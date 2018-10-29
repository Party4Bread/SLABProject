//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TIntroForm *IntroForm;
//---------------------------------------------------------------------------
__fastcall TIntroForm::TIntroForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TIntroForm::Timer1Timer(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------
