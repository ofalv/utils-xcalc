//---------------------------------------------------------------------------

#ifndef FXCalcMainH
#define FXCalcMainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <ImgList.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TF_XCalcMain : public TForm
{
__published:	// IDE-managed Components
	TMemo *M_Sentence;
	TStatusBar *SB_Msg;
	TMainMenu *MainMenu1;
	TMenuItem *Exit1;
	TMenuItem *Help1;
	TMenuItem *AngleType1;
	TMenuItem *Radian1;
	TMenuItem *Degree1;
	TMenuItem *Clear1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormHide(TObject *Sender);
	void __fastcall ToolButton2Click(TObject *Sender);
	void __fastcall ToolButton3Click(TObject *Sender);
	void __fastcall M_SentenceKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall M_SentenceKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall Exit1Click(TObject *Sender);
	void __fastcall Help1Click(TObject *Sender);
	void __fastcall Radian1Click(TObject *Sender);
	void __fastcall Degree1Click(TObject *Sender);
	void __fastcall Clear1Click(TObject *Sender);

private:	// User declarations
	TList *m_pList;
public:		// User declarations
	__fastcall TF_XCalcMain(TComponent* Owner);
	void __fastcall ClearEqualLine(void);

};
//---------------------------------------------------------------------------
extern PACKAGE TF_XCalcMain *F_XCalcMain;
//---------------------------------------------------------------------------
#endif
