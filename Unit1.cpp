//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;

bool langEvent=true, onlangEvent=false;
int gravity;
int level;
int lang = 0;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{


	for (int i = 1; i <10; i++) {
		Memo1->Lines->Add(IntToStr(i));
	}

	PanelOutput->Visible=false;
	DialogShadow->Visible=false;
    CButton->Visible=false;
    CppButton->Visible=false;
    PythonButton->Visible=false;
    Timer1->Enabled=false;

}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

















void __fastcall TForm1::CompileButtonClick(TObject *Sender)
{

//    if(Pos("scanf", CodeEditor->Lines->Text)){
//    	PanelInput->Visible=true;
//		DialogShadow->Visible=true;
//    }
//    else{
    if(lang==0){
    	CodeEditor->Lines->SaveToFile("code_c.c", TEncoding::UTF8);        //�Է��� �ڵ带 ����
		system("mode con:cols=15 lines=1 && gcc -O3 -std=c99 -Wall -Wextra -o first.exe code_c.c & cmd /c first.exe > output_c.txt");         //gcc�� �̿��� �������� �����
        OutputLoad->Lines->LoadFromFile("output_c.txt");
		PanelOutput->Visible=true;
		DialogShadow->Visible=true;
        Text2->Text=OutputLoad->Text;


    }
    else if(lang==1){
    	CodeEditor->Lines->SaveToFile("code_cpp.cpp", TEncoding::UTF8);        //�Է��� �ڵ带 ����
		system("mode con:cols=15 lines=1 && g++ -O3 -Wextra -o Cpp_Language.exe code_cpp.cpp & cmd /c Cpp_Language.exe > output_cpp.txt");         //gcc�� �̿��� �������� �����
        OutputLoad->Lines->LoadFromFile("output_cpp.txt");
		PanelOutput->Visible=true;
		DialogShadow->Visible=true;
        Text2->Text=OutputLoad->Text;
    }
    else if(lang==2){
    	CodeEditor->Lines->SaveToFile("code_py.py", TEncoding::UTF8);        //�Է��� �ڵ带 ����
		system("mode con:cols=15 lines=1 && python code_py.py 1> output_py.txt 2>error_py.txt");        //<input.txt
        GetErrorMsg->Lines->LoadFromFile("error_py.txt");
		if(GetErrorMsg->Text.Length()>0)
		{
			ShowMessage(GetErrorMsg->Text);
		}
		else
		{
			OutputLoad->Lines->LoadFromFile("output_py.txt");
		}
		PanelOutput->Visible=true;
		DialogShadow->Visible=true;
        Text2->Text=OutputLoad->Text;
    }

    	
//    }

}
//---------------------------------------------------------------------------







void __fastcall TForm1::RunDialogNoButtonClick(TObject *Sender)
{
	PanelOutput->Visible=false;
	DialogShadow->Visible=false;
    OutputLoad->Lines->Clear();
}
//---------------------------------------------------------------------------



void __fastcall TForm1::LangButtonClick(TObject *Sender)
{

    if(!onlangEvent){
        CButton->Visible=true;
    	CppButton->Visible=true;
    	PythonButton->Visible=true;
    	onlangEvent=true;
    	gravity = 400;
		level = 0;
    	Timer1->Enabled=true;
    }



}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{


    if(langEvent){
    	CButton->Position->X += (1+(gravity/100));
    	CppButton->Position->X += (4+(gravity/100));
    	PythonButton->Position->X += (7+(gravity/100));
    }
    else
    {
        CButton->Position->X -= (1+(gravity/100));
    	CppButton->Position->X -= (4+(gravity/100));
    	PythonButton->Position->X -= (7+(gravity/100));
    }

    if(level++>30){
    	langEvent=!langEvent;
        onlangEvent=false;
    	Timer1->Enabled=false;

    }
    //if(level>10) gravity-=1;
    if(level>20) gravity-=2;
    if(level>25) gravity-=4;
    if(level>35) gravity-=6;
    if(level>40) gravity-=8;
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
    CodeEditor->Lines->SaveToFile("code.c");
    system("gcc -O3 -std=c99 -Wall -Wextra -o c.exe code.c");
    system("cmd /c c.exe > output.txt");
    PanelOutput->Visible=true;
    DialogShadow->Visible=true;
    Text2->Text="���� ���:\n\n*****\n****\n***\n**\n*\n\n\n\n����Ϸ��� �ƹ� Ű�� ��������...";
}
//---------------------------------------------------------------------------





void __fastcall TForm1::CButtonClick(TObject *Sender)
{
    lang = 0;
    CodeEditor->Lines->Text="#include <stdio.h>\n\nint main()\n{\n\n\n\n\n}";
    if(!onlangEvent){
    	onlangEvent=true;
    	gravity = 400;
		level = 0;
    	Timer1->Enabled=true;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CppButtonClick(TObject *Sender)
{
    lang = 1;
	CodeEditor->Lines->Text="#include <iostream>\nusing namespace std;\n\nint main()\n{\n\n\n\n    return 0;\n}";
    if(!onlangEvent){
    	onlangEvent=true;
    	gravity = 400;
		level = 0;
    	Timer1->Enabled=true;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PythonButtonClick(TObject *Sender)
{
    lang = 2;
    CodeEditor->Lines->Text="print(\"Hello World\")";
    if(!onlangEvent){
    	onlangEvent=true;
    	gravity = 400;
		level = 0;
    	Timer1->Enabled=true;
    }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

void __fastcall TForm1::CodeEditorKeyUp(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
          TShiftState Shift)
{
	if(Key==9)   //�� Ű�� ������ ��
	{
		int tab = CodeEditor->PosToTextPos(CodeEditor->CaretPosition)+4;       //Ŀ�� ��ġ �� ����
		CodeEditor->Text = CodeEditor->Text.Insert("    ",CodeEditor->PosToTextPos(CodeEditor->CaretPosition)+1); //4ĭ ���� -> ��, tab ���
		CodeEditor->CaretPosition = CodeEditor->TextPosToPos(tab);             //Ŀ���� ���� ��ġ�� �α�
	}
}
//---------------------------------------------------------------------------

