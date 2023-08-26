//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "read_file_path_dialog.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TReadFilePathDialog *ReadFilePathDialog;
//---------------------------------------------------------------------------
__fastcall TReadFilePathDialog::TReadFilePathDialog(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
