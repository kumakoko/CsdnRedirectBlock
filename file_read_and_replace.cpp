//---------------------------------------------------------------------------

#pragma hdrstop

#include "file_read_and_replace.h"
#include <boost/regex.hpp>
#include <boost/filesystem.hpp>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <windows.h>

namespace fs = boost::filesystem;

//---------------------------------------------------------------------------
void FileTool::FileReadAndReplace(
    const std::string &filePath, std::string &fileContent)
{
    std::ifstream ifile(filePath);
    std::ostringstream buf;
    char ch = 0x0;

    while (buf && ifile.get(ch))
        buf.put(ch);

    ifile.close();
    fileContent = buf.str();

    boost::regex rgx("onerror");
    fileContent = boost::regex_replace(fileContent, rgx, "on_error_function");

    OutputDebugStringA(fileContent.c_str());

    std::ofstream ofile(filePath);
    ofile << fileContent;
    ofile.close();
}

bool FileTool::IsFileExtensionInFilterList(
    const std::string &extension, const std::list<std::string> &filters)
{
    return std::find(filters.begin(), filters.end(), extension) !=
           filters.end();
}

void FileTool::GetFiles(const std::string &rootPath,
    const std::list<std::string> &filters, std::list<std::string> &filePathList)
{
    if (!fs::exists(rootPath) && !fs::is_directory(rootPath))
        return;

    fs::path inputFilePath(rootPath);
    fs::recursive_directory_iterator it(inputFilePath);
    fs::recursive_directory_iterator endit;

    while (it != endit) {
        if (fs::is_regular_file(*it) &&
            IsFileExtensionInFilterList(
                it->path().extension().string(), filters))
        {
            std::string file_name = it->path().string();
            filePathList.push_back(file_name);
            OutputDebugStringA(file_name.c_str());
        }

        it++;
    }
}
#pragma package(smart_init)

