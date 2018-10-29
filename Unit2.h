//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TIntroForm : public TForm
{
__published:	// IDE-managed Components
	TTimer *Timer1;
	void __fastcall Timer1Timer(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TIntroForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TIntroForm *IntroForm;
//---------------------------------------------------------------------------
#endif
