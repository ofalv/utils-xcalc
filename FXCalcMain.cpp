//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "iLogLib.h"

#include "FXCalcMain.h"
#include "CalcModule.h"
#include "FHelp.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TF_XCalcMain *F_XCalcMain;
//---------------------------------------------------------------------------
__fastcall TF_XCalcMain::TF_XCalcMain(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TF_XCalcMain::FormCreate(TObject *Sender)
{
	//
	m_pList = new TList();

	SetAngleType(AT_DEG);

}
//---------------------------------------------------------------------------

void __fastcall TF_XCalcMain::FormDestroy(TObject *Sender)
{
	//

	delete m_pList;
}
//---------------------------------------------------------------------------

void __fastcall TF_XCalcMain::FormShow(TObject *Sender)
{

	//

}
//---------------------------------------------------------------------------

void __fastcall TF_XCalcMain::FormHide(TObject *Sender)
{
	//

}
//---------------------------------------------------------------------------








void __fastcall TF_XCalcMain::ToolButton2Click(TObject *Sender)
{
	ShowMessage("Nothing todo ");

}
//---------------------------------------------------------------------------

void __fastcall TF_XCalcMain::ToolButton3Click(TObject *Sender)
{
	ShowMessage("Nothing todo ");

}
//---------------------------------------------------------------------------



void __fastcall TF_XCalcMain::M_SentenceKeyPress(TObject *Sender, wchar_t &Key)
{
	SB_Msg->Panels->Items[0]->Text =  "계산시작";


	if( Key == '\r')
	{
		Key = 0;

		int iErrIdx =-1;

		m_pList->Clear();

		int iCaretLine = M_Sentence->Perform(EM_LINEFROMCHAR, M_Sentence->SelStart, 0);
		String sCalcData = M_Sentence->Lines->Strings[iCaretLine];


		if( sCalcData[sCalcData.Length()] == '=')
		{
			int iLen = sCalcData.Length();
			sCalcData[iLen] = ' ' ;
			M_Sentence->Lines->Strings[iCaretLine] = sCalcData.Trim();
      }

		try{

			if( SplitSentence(sCalcData, m_pList , iErrIdx) == false )
			{
				String s;
				s.sprintf(L"%d번째 문자부터 수식 오류(Syntax Error)",iErrIdx+1 );
				SB_Msg->Panels->Items[0]->Text =  s;
				return;
			}

			LogSplitList(m_pList);

			double result;
			if( Calc(m_pList , result ) == false )
			{

				String s;
				if( g_sErrMsg == "")
				{
					s.sprintf(L"계산실패");
					SB_Msg->Panels->Items[0]->Text =  s;
					M_Sentence->Lines->Add("ERROR");
					Sleep(300);
					M_Sentence->Lines->Strings[M_Sentence->Lines->Count-1] = "";
				}
				else
				{
					SB_Msg->Panels->Items[0]->Text =  g_sErrMsg;

				}


				return;

			}

			M_Sentence->Lines->Strings[iCaretLine] = M_Sentence->Lines->Strings[iCaretLine] + " =" ;

			M_Sentence->Lines->Insert(iCaretLine+1, NumberToStr(result, 10));
		}
		catch(Exception &e)
		{

			SB_Msg->Panels->Items[0]->Text =  e.Message;
		}

		SB_Msg->Panels->Items[0]->Text = "계산완료";
	}

}
//---------------------------------------------------------------------------

// Memo 문자열을 찾아서 "="기호가 들어가 있는 문자열은 제거한다.
void __fastcall TF_XCalcMain::ClearEqualLine(void)
{

	for (int i = 0; i < M_Sentence->Lines->Count; i++)
	{
		if( M_Sentence->Lines->Strings[i][1] == '=' || M_Sentence->Lines->Strings[i].Length()==0)
		{
			M_Sentence->Lines->Delete(i);
			i--;

      }
	}

}

void __fastcall TF_XCalcMain::M_SentenceKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{

	if( Key == VK_F1 )
	{
		F_Help->Show();

	}
}
//---------------------------------------------------------------------------

void __fastcall TF_XCalcMain::Exit1Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TF_XCalcMain::Help1Click(TObject *Sender)
{
	F_Help->Show();
}
//---------------------------------------------------------------------------

void __fastcall TF_XCalcMain::Radian1Click(TObject *Sender)
{

	SetAngleType((ANGLE_TYPE)AT_RAD);
	Degree1->Checked = false;
	Radian1->Checked = true;

}
//---------------------------------------------------------------------------

void __fastcall TF_XCalcMain::Degree1Click(TObject *Sender)
{
	SetAngleType((ANGLE_TYPE)AT_DEG);
	Degree1->Checked = true;
	Radian1->Checked = false;

}
//---------------------------------------------------------------------------


void __fastcall TF_XCalcMain::Clear1Click(TObject *Sender)
{
	M_Sentence->Clear();
}
//---------------------------------------------------------------------------

