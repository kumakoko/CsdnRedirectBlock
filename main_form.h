//---------------------------------------------------------------------------

#ifndef main_formH
#define main_formH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.StdCtrls.hpp>
#include <string>
//---------------------------------------------------------------------------
class TMainForm : public TForm {
 __published:  // IDE-managed Components
  TButton* ButtonExecute;
  TOpenDialog* _OpenFileDialog;
  TButton* ButtonSelectFile;
  TEdit* EditSelectedFilePath;
  void __fastcall ButtonExecuteClick(TObject* Sender);
  void __fastcall ButtonSelectFileClick(TObject* Sender);

 private:  // User declarations
  AnsiString _SelectedFilePath;

 public:  // User declarations
  __fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm* MainForm;
//---------------------------------------------------------------------------
#endif

