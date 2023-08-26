//---------------------------------------------------------------------------

#ifndef string_toolH
#define string_toolH
//---------------------------------------------------------------------------
#include <ustring.h>

namespace xkcb
{
    class StringTool
    {
      public:
        //把 ANSI 本地编码的文件转为 UTF-8 编码的文件
        static void ConvertAnsiFileIntoUtf8(
            const System::UnicodeString &fileName);
        static void ConvertBig5FileIntoGBK(
            const System::UnicodeString &fileName);
        // 繁體转为简体: "漢語" → "汉语"
        static UnicodeString CHT2CHS(const UnicodeString &sChs);
        // 简体轉為繁體: "汉语" → "漢語"
        static UnicodeString CHS2CHT(const UnicodeString &sCht);
    };
} // namespace xkcb

#endif

