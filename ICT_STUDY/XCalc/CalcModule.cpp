//---------------------------------------------------------------------------


#include <vcl.h>
#pragma hdrstop

#include <math.h>

#include "iLogLib.h"

#include "CalcModule.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

String asTypeStr[]
={
	"NUM",
	"OPEN_BRACKET",
	"CLOSE_BRACKET",
	"OP", // ������
	"SIGN", // +- ��ȣǥ��
	"FUNC",
};

static bool bIsAngleRad = false; // Radian ������ ������ ��Ÿ��



void SetAngleType(ANGLE_TYPE type)
{
	bIsAngleRad = (type==AT_RAD);
}

// �Լ� �̸����� �Լ� �Է� ���ڿ� �����ϴ� ���� ������
// ���� �߻��� false�� ����
// �Լ����� sin, cos ���� �ﰢ�� �� �� �ƴ϶� �⺻ ��Ģ ���굵 ���Ե�
bool GetFuncValue(/* IN*/String sFuncName, double dValue1, /*OUT*/double &dResult)
{
	if( bIsAngleRad == false ) // ���� �����̸�.. ���� ������ �ٲ���
	{
		dValue1 = M_PI  / 180 * dValue1;
   }
	//------------------------------------------------------------------------------
	// �Ķ��Ÿ�� 1���� �Լ�
	if( sFuncName == "sin")
	{
		dResult = sin(dValue1);
		return true;
	}
	else if( sFuncName == "cos")
	{
		dResult = cos(dValue1);
		return true;
	}
	else if( sFuncName == "tan")
	{
		dResult = tan(dValue1);
		return true;
	}

	return false;

}




// ����Ʈ�� ����ִ� ������ ����Ѵ�. ( ������ )
void LogSplitList(TList *pList, String sTitle)
{

	LOG_PRINTFW("TEST", L"------------------------- SENTENCE LIST (\"%s\") : count=%d ---------------------------", sTitle=="" ? String("no title") : sTitle , pList->Count);

	for (int i = 0; i < pList->Count; i++)
	{
		LOG_PRINTFW("TEST", L"%d:type=%s: item=\"%s\"", i, asTypeStr[ ((CalcItem*)pList->Items[i])->m_eType ]
			, ((CalcItem*)pList->Items[i])->m_sData );
	}

}



// ���ڿ��� ���뿡 ���� �Լ����� �������� �Ǵ��Ͽ� ����Ʈ�� �߰��� �ְ� ���ڿ��� Clear
bool AddSplitedItem(TList *pList , /*IN.OUT*/String &sItem, bool &bNum, bool &bFunc)
{
	if( pList == NULL)
		return false;
	if( sItem == "")
		return false;

	if( isalpha( sItem[1] ) ) // �Լ�
	{
		pList->Add( new CalcItem(CT_FUNC , sItem ));
		sItem = "";
		bFunc = false;

	}
	else if( isdigit(sItem[1])  || sItem[1]=='.' )  // ����
	{
		pList->Add( new CalcItem(CT_NUM , sItem ));
		sItem = "";
		bNum = false;

	}
	else
		return false;


	return true;

}


// sSentence ���� �Է� ���� ������ ������ ����, ������, ��ȣ ������ �߶�
// CalcItem ��ü�� �����ؼ� ����Ʈ�� �߰��� �ִ� �Լ�
// ��ȯ�� ������ ���� ��� iErrIdx�� ������ �߻��� ������ ��ġ�� ����
bool SplitSentence(String sSentence , TList *pList, /*OUT*/int &iErrIdx)
{
	if( pList == NULL)
		return false;

	int len = sSentence.Length();

	String &s = sSentence;

	bool bNum = false;
	bool bFunc = false;
	int iDepth = 0;
	int iPointCount = 0; // �Ҽ��� ����

	String sBuf;

	for (int i = 1; i <= len; i++)
	{

		if( isdigit(s[i]) || s[i] == '.')
		{
			if( bNum == false )
			{
				//  ���� ���ڰ� ������ ���� ó��
				if( pList->Count>0 && ((CalcItem*)pList->Items[pList->Count-1])->m_eType == CT_NUM )
				{
					iErrIdx = i-1;
					return false;

				}

				// ���� ����
				bNum=true;
				iPointCount = 0;
			}

			if( s[i] == '.' )
			{
				if( iPointCount > 0) // error
				{
					iErrIdx = i-1;
					return false;
				}

				iPointCount ++;
			}


			sBuf += s[i];


		}
		else if( s[i] == '(')
		{
			AddSplitedItem(pList, sBuf, bNum, bFunc );

			iDepth ++;
			pList->Add(new CalcItem(CT_OPEN_BRACKET, s[i]));

		}
		else if( s[i] == ')')
		{
			AddSplitedItem(pList, sBuf, bNum, bFunc );

			iDepth --;
			pList->Add(new CalcItem(CT_CLOSE_BRACKET, s[i]));

			if( iDepth < 0) // error
			{
				iErrIdx = i-1;
				return false;
         }

		}
		else if( s[i] == '+' || s[i] == '-' )
		{
			AddSplitedItem(pList, sBuf, bNum, bFunc );

			// ù��° +-�� ���ų� , ��ȣ ���� ó�� ���� +- ��ȣ�� ��ȣ ǥ���̴�.
			if( pList->Count == 0 || ((CalcItem*)pList->Items[pList->Count-1])->m_eType == CT_OPEN_BRACKET )
			{
				pList->Add(new CalcItem(CT_SIGN, s[i]));
			}
			else  // �������� ���� ���� ������
			{
				pList->Add(new CalcItem(CT_OP, s[i]));
			}

		}
		else if(s[i] == '*' || s[i] == '/' || s[i] == '^')
		{
			AddSplitedItem(pList, sBuf, bNum, bFunc );

			pList->Add(new CalcItem(CT_OP, s[i]));

		}
		else if( s[i] == ' ' || s[i] == '\r' || s[i] == '\n')
		{
			AddSplitedItem(pList, sBuf, bNum, bFunc );
			continue;
		}
		else if(isalpha(s[i] ) )
		{
			if( bFunc == false )
			{
				AddSplitedItem(pList, sBuf, bNum, bFunc );
				bFunc = true;
			}

			sBuf += s[i];
		}
		else // �̿��� ���� ����
		{
			iErrIdx = i-1;
			return false;
      }
	}

	// �������� �� �ִ� ������ �߰�
   AddSplitedItem(pList, sBuf, bNum, bFunc );


	if( iDepth > 0) // ��ȣ�� �ȸ���
	{
		return false;
	}

	return true;
}




// ������ �м��ؼ� ����ϴ� �Լ�  - ���ȣ���� ������� ����.
bool Calc(TList *pList , double &dResult)
{

	if( pList == NULL)
		return false;

	int iIdx = 0;

	CalcItem *crnt, *pre, *next;
	CT_TYPE type;
	String data;
	// �ǿ����� �� ����
	double v1, v2;

	while(true)
	{

		// ��� ó���� iIdx�� ������ ���ڿ� �� ���� ��� ó��
		if( pList->Count>1 && iIdx==pList->Count-1 )
		{
			crnt = (CalcItem*)pList->Items[iIdx];

			if( crnt->m_eType == CT_NUM)
				iIdx--;
      }


		if( iIdx < 0) iIdx = 0;


		if( iIdx >= 0)
		{
			crnt = (CalcItem*)pList->Items[iIdx];
			type = crnt->m_eType;
			data = crnt->m_sData;
		}



		if( pList->Count == 1 && crnt->m_eType==CT_NUM)
		{
			dResult = data.ToDouble();
			return true;
      }



		if( type  == CT_SIGN)
		{

			delete crnt;
			pList->Delete(iIdx); // �ϳ� ����

			//������ ���ڰ� ���°����� �����ϰ�  - ��ȣ ����
			if(data =="-")
			{
				// ������ ���� ���ڿ� - ��ȣ ����
				crnt = (CalcItem*)pList->Items[iIdx];
				crnt->m_sData = "-" + crnt->m_sData;
			}

			continue;
		}
		else if(type == CT_NUM)
		{
			// ��ȣ ����� �Ǵ� �Լ� ��� ��� ó��
			if(iIdx>0 &&  pList->Count > iIdx+1)
			{
				pre = (CalcItem*)pList->Items[iIdx-1];
				next = (CalcItem*)pList->Items[iIdx+1];
				if( pre->m_eType==CT_OPEN_BRACKET && next->m_eType==CT_CLOSE_BRACKET)
				{

					// ��ȣ �����
					delete pre;
					delete next;
					pList->Delete(iIdx+1);
					pList->Delete(iIdx-1);
					iIdx--;

					//�Լ� ó��
					if( iIdx>0 )
					{
						pre = (CalcItem*)pList->Items[iIdx-1];
						crnt = (CalcItem*)pList->Items[iIdx];

						if( pre->m_eType == CT_FUNC)
						{
							double result ;
							double value = crnt->m_sData.ToDouble();
							String sFunc = pre->m_sData;

							if( GetFuncValue(sFunc,  value, result ) == false )
							{
								LOG_PRINTFW("CALC", L"�Լ� ��� ó�� ���� : %s(%lf)", sFunc, value);
								//�Լ� ����
								return false;
							}

							// �Լ� �̸� ����� ��� �Է�
							delete pre;
							pList->Delete(iIdx-1);
							crnt->m_sData = FloatToStr(result);
							LogSplitList(pList, "�Լ������");

							LOG_PRINTFW("CALC", L"�Լ� ó�� ��� : %s(%lf) = %lf", sFunc, value, result);
							iIdx--;
							continue ;
						}
					}

					continue;
				}


			}

			// ������ ���� ��ġ�� Index�� ������ ó��
			if( pList->Count>=3 && pList->Count == iIdx +1 )
			{
				iIdx--;
				continue;
			}


			iIdx ++;
			continue;
		}
		else if( type == CT_OP)
		{


			next = (CalcItem*)pList->Items[iIdx+1];

			// ������ ������ ���ڰ� ������ ������ Calc �Լ� ȣ��(?)
			if( next->m_eType != CT_NUM)
			{
				iIdx ++;
				continue;
			}

			pre = (CalcItem*)pList->Items[iIdx-1];
			next = (CalcItem*)pList->Items[iIdx+1];

			if( data=="*" || data=="/" || data=="^")
			{

				v1 = pre->m_sData.ToDouble();
				v2 = next->m_sData.ToDouble();

				if( data == "*")
					pre->m_sData = FloatToStr( v1 * v2 );
				else if( data == "^")
					pre->m_sData = FloatToStr( pow( v1 , v2) );
				else if( v2 == 0.0 )
					return false;
				else
					pre->m_sData = FloatToStr( v1 / v2 );

				// ��� ���� ������ ����
				delete next;
				delete crnt;
				pList->Delete(iIdx+1);
				pList->Delete(iIdx);
				iIdx-=2;

				LogSplitList(pList, "���������� ������");

				continue;
			}
			else
			{

				// + �� - �������̰� ������ �켱������ ���� �����ڰ� ���ö� �ǳʶ�
				if(pList->Count > iIdx+2 )
				{
					CalcItem * next2 = (CalcItem*)pList->Items[iIdx+2];

					if( next2->m_sData=="*" || next2->m_sData=="/" || next2->m_sData=="^" )
					{
						iIdx += 2;
						continue;
					}

				}

				v1 = pre->m_sData.ToDouble();
				v2 = next->m_sData.ToDouble();

				if( data == "+")
					pre->m_sData = FloatToStr( v1 + v2 );
				else //
					pre->m_sData = FloatToStr( v1 - v2 );

				// ��� ���� ������ ����
				delete next;
				delete crnt;
				pList->Delete(iIdx+1);
				pList->Delete(iIdx);
				iIdx-=2;

				LogSplitList(pList, "���� ���� ������");

				continue;

			}

		}
		else // ���ڳ� �����ڰ� �ƴҰ�� �������� �Ѿ
		{
			// pi��� ó��
			if( crnt->m_sData.UpperCase() == "PI")
			{
				crnt->m_eType = CT_NUM;
				crnt->m_sData = FloatToStr(M_PI);
				continue;
         }

			iIdx++;
			continue;

		}

	}



}



// iNum ���ڸ� ���ڿ��� �ٲ��ش�
// prec �ɼǿ� ���� �Ҽ��� �ڸ����� �����ش�.
// �Ҽ��� �Ʒ��� ������� "0" ���ڴ� �����Ѵ�.
String NumberToStr(double dNum , int prec)
{
	String sFormat;
	sFormat.sprintf(L"%%.%dlf", prec);

	String sStr;
	sStr.sprintf(sFormat.c_str(), dNum);

	// ���ʿ� ������� 0 �����ϱ�
	int count = sStr.Length();
	for (int i = count; i >=1; i--)
	{
		if( sStr[i] == '.' )
		{
			sStr.SetLength(i-1);
			break;
		}
		else if( sStr[i] == '0' )
			sStr.SetLength(i-1);
		else
			break;
	}

	return sStr;
}







