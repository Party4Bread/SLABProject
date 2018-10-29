//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;

bool langEvent=true, onlangEvent;
int gravity;
int level;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{


	for (int i = 1; i <10; i++) {
		Memo1->Lines->Add(IntToStr(i));
	}

	PanelOutput->Visible=false;
	DialogShadow->Visible=false;
    Button3->Visible=false;
    Button4->Visible=false;
    Button5->Visible=false;
    Timer1->Enabled=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	//client->Connect();//
}
//---------------------------------------------------------------------------

















void __fastcall TForm1::CompileButtonClick(TObject *Sender)
{

    if(Pos("scanf", Memo2->Lines->Text)){
    	PanelInput->Visible=true;
		DialogShadow->Visible=true;
    }
    else{
    	Memo2->Lines->SaveToFile("code.c");
		system("gcc -O3 -std=c99 -Wall -Wextra -o c.exe code.c");
    	system("cmd /c c.exe > output.txt");
		PanelOutput->Visible=true;
		DialogShadow->Visible=true;
    	Text2->Text="실행 결과:\n\n*****\n****\n***\n**\n*\n\n\n\n계속하려면 아무 키나 누르세요...";
    }

}
//---------------------------------------------------------------------------







void __fastcall TForm1::RunDialogNoButtonClick(TObject *Sender)
{
	PanelOutput->Visible=false;
	DialogShadow->Visible=false;
}
//---------------------------------------------------------------------------



void __fastcall TForm1::LangButtonClick(TObject *Sender)
{

    Button3->Visible=true;
    Button4->Visible=true;
    Button5->Visible=true;
    gravity = 400;
	level = 0;

    Timer1->Enabled=true;


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{


    if(langEvent){
    	Button3->Position->X += (+(gravity/100));
    	Button4->Position->X += (3+(gravity/100));
    	Button5->Position->X += (6+(gravity/100));
    }
    else
    {
        Button3->Position->X -= ((gravity/100));
    	Button4->Position->X -= (3+(gravity/100));
    	Button5->Position->X -= (6+(gravity/100));
    }

    if(level++>30){
    	langEvent=!langEvent;
    	Timer1->Enabled=false;

    }
    if(level>10) gravity-=1;
    if(level>20) gravity-=4;
    if(level>25) gravity-=8;
//    if(level>35) gravity-=4;
//    if(level>40) gravity-=4;
//    if(level>45) gravity-=16;

}
//---------------------------------------------------------------------------




void __fastcall TForm1::InputCloseBtnClick(TObject *Sender)
{
    PanelInput->Visible=false;
    DialogShadow->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::InputNextBtnClick(TObject *Sender)
{
    PanelInput->Visible=false;
    DialogShadow->Visible=false;
    Memo2->Lines->SaveToFile("code.c");
    system("gcc -O3 -std=c99 -Wall -Wextra -o c.exe code.c");
    system("cmd /c c.exe > output.txt");
    PanelOutput->Visible=true;
    DialogShadow->Visible=true;
    Text2->Text="실행 결과:\n\n*****\n****\n***\n**\n*\n\n\n\n계속하려면 아무 키나 누르세요...";
}
//---------------------------------------------------------------------------



