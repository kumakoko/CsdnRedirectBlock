//---------------------------------------------------------------------------

#ifndef file_read_and_replaceH
#define file_read_and_replaceH
//---------------------------------------------------------------------------
#include <boost/algorithm/string.hpp>
#include <string>

class FileTool {
 public:
  static void FileReadAndReplace(const std::string& filePath,
                                 std::string& fileContent);
};

#endif

