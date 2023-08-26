//---------------------------------------------------------------------------

#ifndef read_file_path_dialogH
#define read_file_path_dialogH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TReadFilePathDialog : public TForm
{
__published:	// IDE-managed Components
	TProgressBar *_ProgressBarReadFilePath;
private:	// User declarations
public:		// User declarations
	__fastcall TReadFilePathDialog(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TReadFilePathDialog *ReadFilePathDialog;
//---------------------------------------------------------------------------
#endif
