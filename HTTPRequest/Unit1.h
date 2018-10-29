//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.ListBox.hpp>
#include <FMX.Types.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.StdCtrls.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <System.Net.HttpClient.hpp>
#include <System.Net.HttpClientComponent.hpp>
#include <System.Net.URLClient.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TComboBox *ComboBox1;
	TListBoxItem *ListBoxItem1;
	TEdit *SendEdt;
	TButton *SendBtn;
	TEdit *IPEdt;
	TEdit *PortEdt;
	TButton *ConnectBtn;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TIdTCPClient *IdTCPClient1;
	TTimer *Timer1;
	TListBoxItem *ListBoxItem2;
	TListBoxItem *ListBoxItem3;
	TListBoxItem *ListBoxItem4;
	TListBoxItem *ListBoxItem5;
	TNetHTTPRequest *NetHTTPRequest1;
	TNetHTTPClient *NetHTTPClient1;
	void __fastcall SendBtnClick(TObject *Sender);
	void __fastcall ConnectBtnClick(TObject *Sender);
	void __fastcall IdTCPClient1Connected(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
