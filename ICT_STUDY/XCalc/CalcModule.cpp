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
	"OP", // 연산자
	"SIGN", // +- 부호표시
	"FUNC",
};

static bool bIsAngleRad = false; // Radian 각도를 쓰는지 나타냄



void SetAngleType(ANGLE_TYPE type)
{
	bIsAngleRad = (type==AT_RAD);
}

// 함수 이름으로 함수 입력 인자에 대응하는 값을 리턴함
// 에러 발생시 false를 리턴
// 함수에는 sin, cos 등의 삼각함 수 뿐 아니라 기본 사칙 연산도 포함됨
bool GetFuncValue(/* IN*/String sFuncName, double dValue1, /*OUT*/double &dResult)
{
	if( bIsAngleRad == false ) // 각도 단위이면.. 라디안 단위로 바꿔줌
	{
		dValue1 = M_PI  / 180 * dValue1;
   }
	//------------------------------------------------------------------------------
	// 파라메타가 1개인 함수
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




// 리스트에 담겨있는 내용을 출력한다. ( 디버깅용 )
void LogSplitList(TList *pList, String sTitle)
{

	LOG_PRINTFW("TEST", L"------------------------- SENTENCE LIST (\"%s\") : count=%d ---------------------------", sTitle=="" ? String("no title") : sTitle , pList->Count);

	for (int i = 0; i < pList->Count; i++)
	{
		LOG_PRINTFW("TEST", L"%d:type=%s: item=\"%s\"", i, asTypeStr[ ((CalcItem*)pList->Items[i])->m_eType ]
			, ((CalcItem*)pList->Items[i])->m_sData );
	}

}



// 문자열의 내용에 따라 함수인지 숫자인지 판단하여 리스트에 추가해 주고 문자열은 Clear
bool AddSplitedItem(TList *pList , /*IN.OUT*/String &sItem, bool &bNum, bool &bFunc)
{
	if( pList == NULL)
		return false;
	if( sItem == "")
		return false;

	if( isalpha( sItem[1] ) ) // 함수
	{
		pList->Add( new CalcItem(CT_FUNC , sItem ));
		sItem = "";
		bFunc = false;

	}
	else if( isdigit(sItem[1])  || sItem[1]=='.' )  // 숫자
	{
		pList->Add( new CalcItem(CT_NUM , sItem ));
		sItem = "";
		bNum = false;

	}
	else
		return false;


	return true;

}


// sSentence 에서 입력 받은 수식을 각각의 숫자, 연산자, 괄호 등으로 잘라서
// CalcItem 객체를 생성해서 리스트에 추가해 주는 함수
// 변환에 문제가 있을 경우 iErrIdx에 에러가 발생한 문자의 위치를 리턴
bool SplitSentence(String sSentence , TList *pList, /*OUT*/int &iErrIdx)
{
	if( pList == NULL)
		return false;

	int len = sSentence.Length();

	String &s = sSentence;

	bool bNum = false;
	bool bFunc = false;
	int iDepth = 0;
	int iPointCount = 0; // 소숫점 개수

	String sBuf;

	for (int i = 1; i <= len; i++)
	{

		if( isdigit(s[i]) || s[i] == '.')
		{
			if( bNum == false )
			{
				//  연속 숫자가 나오면 에러 처리
				if( pList->Count>0 && ((CalcItem*)pList->Items[pList->Count-1])->m_eType == CT_NUM )
				{
					iErrIdx = i-1;
					return false;

				}

				// 숫자 시작
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

			// 첫번째 +-가 오거나 , 괄호 열고 처음 오는 +- 기호는 부호 표시이다.
			if( pList->Count == 0 || ((CalcItem*)pList->Items[pList->Count-1])->m_eType == CT_OPEN_BRACKET )
			{
				pList->Add(new CalcItem(CT_SIGN, s[i]));
			}
			else  // 나머지는 덧셈 뺄셈 연산자
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
		else // 이외의 문자 에러
		{
			iErrIdx = i-1;
			return false;
      }
	}

	// 마지막에 남 있던 데이터 추가
   AddSplitedItem(pList, sBuf, bNum, bFunc );


	if( iDepth > 0) // 괄호가 안맞음
	{
		return false;
	}

	return true;
}




// 수식을 분석해서 계산하는 함수  - 재귀호출을 사용하지 않음.
bool Calc(TList *pList , double &dResult)
{

	if( pList == NULL)
		return false;

	int iIdx = 0;

	CalcItem *crnt, *pre, *next;
	CT_TYPE type;
	String data;
	// 피연산자 값 저장
	double v1, v2;

	while(true)
	{

		// 계산 처리후 iIdx가 마지막 숫자에 가 있을 경우 처리
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
			pList->Delete(iIdx); // 하나 삭제

			//다음엔 숫자가 오는것으로 가정하고  - 부호 붙임
			if(data =="-")
			{
				// 다음에 오는 숫자에 - 부호 붙임
				crnt = (CalcItem*)pList->Items[iIdx];
				crnt->m_sData = "-" + crnt->m_sData;
			}

			continue;
		}
		else if(type == CT_NUM)
		{
			// 괄호 벗기기 또는 함수 계산 기능 처리
			if(iIdx>0 &&  pList->Count > iIdx+1)
			{
				pre = (CalcItem*)pList->Items[iIdx-1];
				next = (CalcItem*)pList->Items[iIdx+1];
				if( pre->m_eType==CT_OPEN_BRACKET && next->m_eType==CT_CLOSE_BRACKET)
				{

					// 괄호 벗기기
					delete pre;
					delete next;
					pList->Delete(iIdx+1);
					pList->Delete(iIdx-1);
					iIdx--;

					//함수 처리
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
								LOG_PRINTFW("CALC", L"함수 계산 처리 오류 : %s(%lf)", sFunc, value);
								//함수 오류
								return false;
							}

							// 함수 이름 지우고 결과 입력
							delete pre;
							pList->Delete(iIdx-1);
							crnt->m_sData = FloatToStr(result);
							LogSplitList(pList, "함수계산후");

							LOG_PRINTFW("CALC", L"함수 처리 결과 : %s(%lf) = %lf", sFunc, value, result);
							iIdx--;
							continue ;
						}
					}

					continue;
				}


			}

			// 마지막 숫자 위치에 Index가 왔을때 처리
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

			// 연산자 다음에 숫자가 나오지 않으면 Calc 함수 호출(?)
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

				// 계산 끝난 데이터 삭제
				delete next;
				delete crnt;
				pList->Delete(iIdx+1);
				pList->Delete(iIdx);
				iIdx-=2;

				LogSplitList(pList, "곱셈나눗셈 연산후");

				continue;
			}
			else
			{

				// + 나 - 연산자이고 다음에 우선순위가 높은 연산자가 나올때 건너뜀
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

				// 계산 끝난 데이터 삭제
				delete next;
				delete crnt;
				pList->Delete(iIdx+1);
				pList->Delete(iIdx);
				iIdx-=2;

				LogSplitList(pList, "덧셈 뺄셈 연산후");

				continue;

			}

		}
		else // 숫자나 연산자가 아닐경우 다음으로 넘어감
		{
			// pi상수 처리
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



// iNum 숫자를 문자열로 바꿔준다
// prec 옵션에 따라서 소숫점 자리수를 맞춰준다.
// 소숫점 아래에 따라오는 "0" 문자는 제거한다.
String NumberToStr(double dNum , int prec)
{
	String sFormat;
	sFormat.sprintf(L"%%.%dlf", prec);

	String sStr;
	sStr.sprintf(sFormat.c_str(), dNum);

	// 뒷쪽에 따라오는 0 제거하기
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







