//---------------------------------------------------------------------------

#pragma hdrstop

#include "file_read_and_replace.h"
#include <windows.h>
#include <boost/regex.hpp>
#include <fstream>
#include <sstream>
//---------------------------------------------------------------------------
void FileTool::FileReadAndReplace(const std::string& filePath,
                                  std::string& fileContent) {
  std::ifstream ifile(filePath);
  std::ostringstream buf;
  char ch = 0x0;

  while (buf && ifile.get(ch))
    buf.put(ch);

  ifile.close();
  fileContent = buf.str();

  boost::regex rgx("onerror");
  fileContent = boost::regex_replace(fileContent, rgx, "on_error_function");

  //OutputDebugStringA(fileContent.c_str());

  std::ofstream ofile(filePath);
  ofile << fileContent;
  ofile.close();
}
#pragma package(smart_init)

