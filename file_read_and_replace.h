//---------------------------------------------------------------------------

#ifndef file_read_and_replaceH
#define file_read_and_replaceH
//---------------------------------------------------------------------------
#include <string>
#include <boost/algorithm/string.hpp>

class FileTool
{
public:
	static void FileReadAndReplace(const std::string& filePath,std::string& fileContent);
};

#endif
