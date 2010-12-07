//---------------------------------------------------------------------------

#ifndef FHelpH
#define FHelpH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TF_Help : public TForm
{
__published:	// IDE-managed Components
	TRichEdit *RichEdit1;
private:	// User declarations
public:		// User declarations
	__fastcall TF_Help(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TF_Help *F_Help;
//---------------------------------------------------------------------------
#endif
