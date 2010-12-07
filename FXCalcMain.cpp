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







void __fastcall TF_XCalcMain::ToolButton1Click(TObject *Sender)
{
	F_Help->Show();
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
	SB_Msg->Panels->Items[0]->Text =  "������";
	if( Key == '\r')
	{
		ClearEqualLine();

		Key = 0;

		int iErrIdx =-1;

		m_pList->Clear();

		try{

			if( SplitSentence(M_Sentence->Text , m_pList , iErrIdx) == false )
			{
				String s;
				s.sprintf(L"%d��° ���ں��� ���� ����(Syntax Error)",iErrIdx+1 );
				SB_Msg->Panels->Items[0]->Text =  s;
				return;
			}

			LogSplitList(m_pList);

			double result;
			if( Calc(m_pList , result ) == false )
			{
				String s;
				s.sprintf(L"%d��° ���ں��� ������", iErrIdx+1);
				SB_Msg->Panels->Items[0]->Text =  s;
				return;

			}


			M_Sentence->Lines->Add("="+NumberToStr(result, 10));
		}
		catch(Exception &e)
		{

			SB_Msg->Panels->Items[0]->Text =  e.Message;
		}

		SB_Msg->Panels->Items[0]->Text = "���Ϸ�";
	}

}
//---------------------------------------------------------------------------

// Memo ���ڿ��� ã�Ƽ� "="��ȣ�� �� �ִ� ���ڿ��� �����Ѵ�.
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
void __fastcall TF_XCalcMain::RG_AngleClick(TObject *Sender)
{

	SetAngleType((ANGLE_TYPE)RG_Angle->ItemIndex);
}
//---------------------------------------------------------------------------

