//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main_form.h"
#include <exception>
#include <string>
#include "file_read_and_replace.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm* MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner) : TForm(Owner) {
  _OpenFileDialog->Filter =
      "Html files (*.htm)|*.htm|Html files (*.html)|*.html";
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ButtonExecuteClick(TObject* Sender) {
    if (FileExists(_SelectedFilePath)) {
      std::string fn = _SelectedFilePath.c_str();
      std::string fileContent;
      FileTool::FileReadAndReplace(fn, fileContent);
      Application->MessageBox(L"OK", L"Message");
    }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ButtonSelectFileClick(TObject* Sender) {
  if (_OpenFileDialog->Execute()) {
    _SelectedFilePath = _OpenFileDialog->FileName;
    EditSelectedFilePath->Text = _SelectedFilePath;
  }
}
//---------------------------------------------------------------------------

