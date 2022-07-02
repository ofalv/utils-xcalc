//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "XMathUtil.h"
#include "FMathTest.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TF_MathTest *F_MathTest;
//---------------------------------------------------------------------------
__fastcall TF_MathTest::TF_MathTest(TComponent* Owner)
   : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TF_MathTest::Button3Click(TObject *Sender)
{
   double x, y;

   double cx = E_Cx->Text.ToDouble();
   double cy = E_Cy->Text.ToDouble();

   double sx = E_X->Text.ToDouble();
   double sy = E_Y->Text.ToDouble();
   double th = E_Th->Text.ToDouble();

   x = sx;
   y = sy;

   CalcRotation(cx, cy, x, y, th);


   AnsiString s;

	s.sprintf("Center (%.6lf, %.6lf)중심으로 (%.6lf,%.6lf)를 %.6lf(도) 만큼 회전"
		, cx, cy, sx, sy, th);
	Memo1->Lines->Add(s);
	s.sprintf("결과좌표 : ( %.6lf, %.6lf )", x, y);
	Memo1->Lines->Add(s);
}
//---------------------------------------------------------------------------
void __fastcall TF_MathTest::B_ClearClick(TObject *Sender)
{
   Memo1->Lines->Clear();   
}
//---------------------------------------------------------------------------

void __fastcall TF_MathTest::B_2PCalcClick(TObject *Sender)
{
   double x1 = E_X1->Text.ToDouble();
   double y1 = E_Y1->Text.ToDouble();
   double x2 = E_X2->Text.ToDouble();
   double y2 = E_Y2->Text.ToDouble();

   AnsiString s;

   double th = CalcAngle(x1, y1, x2, y2 );

   Memo1->Lines->Add("");
	s.sprintf("두점  (%.6lf, %.6lf) , (%.6lf, %.6lf) 사이의 각도는 %.6lf (도) 입니다."
		, x1, y1, x2, y2, th);

   Memo1->Lines->Add(s);

}
//---------------------------------------------------------------------------


void __fastcall TF_MathTest::B_CloseClick(TObject *Sender)
{
	Close();	
}
//---------------------------------------------------------------------------

