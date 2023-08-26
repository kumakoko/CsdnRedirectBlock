//---------------------------------------------------------------------------

#ifndef file_read_and_replaceH
#define file_read_and_replaceH
//---------------------------------------------------------------------------
#include <string>
#include <list>
#include <boost/algorithm/string.hpp>

class FileTool
{
  public:
    static void FileReadAndReplace(
        const std::string &filePath, std::string &fileContent);
    static void GetFiles(const std::string &rootPath,
        const std::list<std::string> &filters,
        std::list<std::string> &filePathList);
  private:
    // �������ļ���׺���ڲ��ڸ������б��б�����
    static bool IsFileExtensionInFilterList(
        const std::string &extension, const std::list<std::string> &filters);
};

#endif
