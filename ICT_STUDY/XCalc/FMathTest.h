//---------------------------------------------------------------------------

#ifndef FMathTestH
#define FMathTestH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TF_MathTest : public TForm
{
__published:	// IDE-managed Components
   TMemo *Memo1;
   TGroupBox *GroupBox1;
   TEdit *E_X;
   TEdit *E_Y;
   TEdit *E_Th;
   TLabel *Label5;
   TLabel *Label6;
   TLabel *Label7;
   TButton *Button3;
   TEdit *E_Cx;
   TEdit *E_Cy;
   TLabel *Label1;
   TLabel *Label2;
   TGroupBox *GroupBox2;
   TLabel *Label3;
   TLabel *Label4;
   TLabel *Label9;
   TLabel *Label10;
   TEdit *E_X2;
   TEdit *E_Y2;
   TButton *B_2PCalc;
   TEdit *E_X1;
   TEdit *E_Y1;
   TButton *B_Clear;
	TButton *B_Close;
   void __fastcall Button3Click(TObject *Sender);
   void __fastcall B_ClearClick(TObject *Sender);
   void __fastcall B_2PCalcClick(TObject *Sender);
	void __fastcall B_CloseClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
   __fastcall TF_MathTest(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TF_MathTest *F_MathTest;
//---------------------------------------------------------------------------
#endif
