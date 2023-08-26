//---------------------------------------------------------------------------

#include <vcl.h>
#include <Vcl.FileCtrl.hpp>
#include <System.Threading.hpp>
#pragma hdrstop

#include "main_form.h"
#include "file_read_and_replace.h"
#include "read_file_path_dialog.h"
#include <string>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm* MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner) : TForm(Owner)
{
    _OpenFileDialog->Filter =
        "Html files (*.htm)|*.htm|Html files (*.html)|*.html";
    _CheckListBoxSelectedFiles->AddItem(L"AAAAA", nullptr);
    _CheckListBoxSelectedFiles->AddItem(L"BBBBB", nullptr);
    _CheckListBoxSelectedFiles->AddItem(L"CCCCC", nullptr);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ButtonExecuteClick(TObject* Sender)
{
    auto Form2 = new TReadFilePathDialog(this); // 创建 Form2
    int r = Form2->ShowModal(); // 显示模态窗口
    if (r == mrOk)
        ShowMessage(L"你点击了 OK 按钮！");
    delete Form2; // 销毁 Form2，释放所有占用的资源
    /*
    if (_OpenFileDialog->Execute()) {
        std::string fileContent;
        AnsiString fileName = _OpenFileDialog->FileName;

        if (FileExists(fileName)) {
            std::string fn = fileName.c_str();
            FileTool::FileReadAndReplace(fn, fileContent);
            Application->MessageBox(L"OK", L"Message");
        }
	}*/
}
//---------------------------------------------------------------------------
// https://blog.csdn.net/weixin_48776540/article/details/125561094
void __fastcall TMainForm::_MenuItemSelectDirectoryClick(TObject* Sender)
{
    /*
	_CheckListBoxSelectedFiles->Clear();
	UnicodeString uniSDir;
	if (SelectDirectory(uniSDir,
			TSelectDirOpts() << sdAllowCreate << sdPerformCreate << sdPrompt,
			0)) //需要Vcl.FileCtrl.hpp文件定义支持
	{
		std::list<std::string> filters = { ".html", ".htm" };
		std::list<std::string> filePathList;
		AnsiString s = uniSDir;
		FileTool::GetFiles(s.c_str(), filters, filePathList);
		for (auto it = filePathList.begin() ; it != filePathList.end(); ++it) {
			UnicodeString ustr = it->c_str();
			_CheckListBoxSelectedFiles->AddItem(ustr, nullptr);
		}
	}
	*/
    _CheckListBoxSelectedFiles->Clear();
    UnicodeString uniSDir;
    if (SelectDirectory(uniSDir,
            TSelectDirOpts() << sdAllowCreate << sdPerformCreate << sdPrompt,
            0)) //需要Vcl.FileCtrl.hpp文件定义支持
    {
        _FindFilesTask(uniSDir);
    }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::_MenuItemSelectFilesClick(TObject* Sender)
{
    if (_OpenFileDialog->Execute()) {
        std::string fileContent;
        AnsiString fileName = _OpenFileDialog->FileName;

        if (FileExists(fileName)) {
            std::string fn = fileName.c_str();
            FileTool::FileReadAndReplace(fn, fileContent);
            Application->MessageBox(L"OK", L"Message");
        }
    }
}
//---------------------------------------------------------------------------
// 使用TTask库进行并行编程
// https://docwiki.embarcadero.com/RADStudio/Alexandria/en/Using_TTask_from_the_Parallel_Programming_Library
void __fastcall TMainForm::_FindFilesTask(const UnicodeString &uniSDir)
{
    auto readFileDlg = new TReadFilePathDialog(this); // 创建 readFileDlg
	readFileDlg->Show(); // 显示模态窗口

    std::list<std::string> filePathList;
    _di_ITask tasks[1];

    tasks[0] = TTask::Create([&]() {
        std::list<std::string> filters = { ".html", ".htm" };

        AnsiString s = uniSDir;
        FileTool::GetFiles(s.c_str(), filters, filePathList);
    });

    tasks[0]->Start();
    TTask::WaitForAll(tasks, sizeof(tasks) / sizeof(tasks[0]) - 1);

    for (auto it = filePathList.begin(); it != filePathList.end(); ++it) {
        UnicodeString ustr = it->c_str();
        _CheckListBoxSelectedFiles->AddItem(ustr, nullptr);
    }

    delete readFileDlg;
}

