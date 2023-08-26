//---------------------------------------------------------------------------

#ifndef main_formH
#define main_formH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.CheckLst.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TButton *ButtonExecute;
	TOpenDialog *_OpenFileDialog;
	TMainMenu *_MainMenu;
	TMenuItem *_MenuFile;
	TMenuItem *_MenuItemSelectFiles;
	TMenuItem *_MenuItemSelectDirectory;
	TCheckListBox *_CheckListBoxSelectedFiles;
	void __fastcall ButtonExecuteClick(TObject *Sender);
	void __fastcall _MenuItemSelectDirectoryClick(TObject *Sender);
	void __fastcall _MenuItemSelectFilesClick(TObject *Sender);
private:	// User declarations
	void __fastcall _FindFilesTask(const UnicodeString& uniSDir);
public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
