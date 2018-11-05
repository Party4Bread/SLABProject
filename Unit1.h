//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.ListBox.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Memo.hpp>
#include <FMX.ScrollBox.hpp>
#include <FMX.Edit.hpp>
#include <FMX.Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TLabel *Label1;
	TIdTCPClient *client;
	TButton *CompileButton;
	TLabel *Label2;
	TMemo *Memo1;
	TMemo *CodeEditor;
	TButton *UploadButton;
	TStyleBook *StyleBook1;
	TText *Text1;
	TButton *RunDialogYesButton;
	TButton *RunDialogNoButton;
	TRectangle *Rectangle1;
	TRectangle *DialogShadow;
	TRectangle *Rectangle3;
	TText *Text2;
	TButton *LangButton;
	TButton *CButton;
	TTimer *Timer1;
	TButton *CppButton;
	TButton *PythonButton;
	TButton *NextButton;
	TRectangle *Rectangle4;
	TText *Text3;
	TButton *InputCloseBtn;
	TButton *InputNextBtn;
	TPanel *PanelInput;
	TPanel *PanelOutput;
	TMemo *Memo3;
	TMemo *OutputLoad;
	TMemo *GetErrorMsg;
	void __fastcall CompileButtonClick(TObject *Sender);
	void __fastcall RunDialogNoButtonClick(TObject *Sender);
	void __fastcall LangButtonClick(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall InputCloseBtnClick(TObject *Sender);
	void __fastcall InputNextBtnClick(TObject *Sender);
	void __fastcall CButtonClick(TObject *Sender);
	void __fastcall CppButtonClick(TObject *Sender);
	void __fastcall PythonButtonClick(TObject *Sender);
	void __fastcall CodeEditorKeyUp(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
          TShiftState Shift);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
