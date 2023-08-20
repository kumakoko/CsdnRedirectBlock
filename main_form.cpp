//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main_form.h"
#include "file_read_and_replace.h"
#include <string>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
	_OpenFileDialog->Filter = "Html files (*.htm)|*.htm|Html files (*.html)|*.html";
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ButtonExecuteClick(TObject *Sender)
{
    /*
	std::string filePath = "d:/test.html";
	std::string fileContent;
	FileTool::FileReadAndReplace(filePath,fileContent);
	*/
	if (_OpenFileDialog->Execute())
	{
        std::string fileContent;
		AnsiString fileName = _OpenFileDialog->FileName;

		if (FileExists(fileName))
		{
			std::string fn = fileName.c_str();
			FileTool::FileReadAndReplace(fn,fileContent);
            Application->MessageBox(L"OK",L"Message");
		}
	}
}
//---------------------------------------------------------------------------
