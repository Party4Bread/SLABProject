//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SendBtnClick(TObject *Sender)
{
	//String ans = ComboBox1->Items->Text;
	//IdTCPClient1->Socket->Write(SendEdt->Text);

}
//---------------------------------------------------------------------------
void __fastcall TForm1::ConnectBtnClick(TObject *Sender)
{
	/*
	IdTCPClient1->Host = IPEdt->Text;
	IdTCPClient1->Port = StrToInt(PortEdt->Text);
	IdTCPClient1->Connect();


	lParamList: TStringList;
begin
  lParamList := TStringList.Create;
  lParamList.Add('id=1');

	*/

	//ShowMessage(NetHTTPClient1->Post("http://192.168.0.38:3000/anw","http://192.168.0.38:3000/anw?anw=4")->ContentAsString(TEncoding::Default));
	 NetHTTPRequest1->Post("http://192.168.0.38:3000/anw",'?anws=4', NULL, TEncoding::Default);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::IdTCPClient1Connected(TObject *Sender)
{
	ShowMessage("connect");
}
//---------------------------------------------------------------------------

