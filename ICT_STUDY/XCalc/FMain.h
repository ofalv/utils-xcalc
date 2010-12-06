//---------------------------------------------------------------------------

#ifndef FMainH
#define FMainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <ImgList.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TMemo *M_Sentence;
	TToolBar *ToolBar1;
	TToolButton *ToolButton1;
	TImageList *ImageList1;
	TRadioGroup *RG_Angle;
	TStatusBar *SB_Msg;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormHide(TObject *Sender);
	void __fastcall ToolButton1Click(TObject *Sender);
	void __fastcall ToolButton2Click(TObject *Sender);
	void __fastcall ToolButton3Click(TObject *Sender);
	void __fastcall M_SentenceKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall RG_AngleClick(TObject *Sender);
private:	// User declarations
	TList *m_pList;
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
	void __fastcall ClearEqualLine(void);

};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
