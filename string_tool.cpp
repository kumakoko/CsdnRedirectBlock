//---------------------------------------------------------------------------

#pragma hdrstop

#include "string_tool.h"
#include <System.Classes.hpp>
#include <windows.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)

namespace xkcb
{
    // http://www.cppfans.com/cbknowledge/skills/strings/charencconv.asp
    void StringTool::ConvertAnsiFileIntoUtf8(
        const System::UnicodeString &fileName)
    {
        TStringList* sl = new TStringList();
        sl->LoadFromFile(fileName, TEncoding::ANSI);
        sl->SaveToFile(fileName, TEncoding::UTF8);
        delete sl;
    }

    void StringTool::ConvertBig5FileIntoGBK(
        const System::UnicodeString &fileName)
    {
        TStringList* sl = new TStringList;
        TEncoding* encBig5 = new TMBCSEncoding(950); // 选取代码页 950
        sl->LoadFromFile(fileName, encBig5); // 读取 BIG5 编码的文件
        TEncoding* encGBK = new TMBCSEncoding(936); // 选取代码页 936
        sl->SaveToFile(fileName, encGBK); // 存为 GBK 编码的文件
        delete sl;
        delete encBig5;
        delete encGBK;
    }

    UnicodeString StringTool::CHT2CHS(
		const UnicodeString &sChs)
    {
        UnicodeString sDst;
        LCID lcidSrc =
            MAKELCID(MAKELANGID(LANG_CHINESE, SUBLANG_CHINESE_SIMPLIFIED),
                SORT_CHINESE_BIG5);
        int iNewLen = LCMapString(lcidSrc, LCMAP_SIMPLIFIED_CHINESE,
            sChs.c_str(), sChs.Length(), NULL, 0);
        if (iNewLen > 0) {
            sDst.SetLength(iNewLen);
            LCMapString(lcidSrc, LCMAP_SIMPLIFIED_CHINESE, sChs.c_str(),
                sChs.Length(), sDst.c_str(), iNewLen);
        }
        return sDst;
    }
    //---------------------------------------------------------------------------
    UnicodeString StringTool::CHS2CHT(
        const UnicodeString &sCht)
    {
        UnicodeString sDst;
        LCID lcidSrc =
            MAKELCID(MAKELANGID(LANG_CHINESE, SUBLANG_CHINESE_SIMPLIFIED),
                SORT_CHINESE_PRC);
        int iNewLen = LCMapString(lcidSrc, LCMAP_TRADITIONAL_CHINESE,
            sCht.c_str(), sCht.Length(), NULL, 0);
        if (iNewLen > 0) {
            sDst.SetLength(iNewLen);
            LCMapString(lcidSrc, LCMAP_TRADITIONAL_CHINESE, sCht.c_str(),
                sCht.Length(), sDst.c_str(), iNewLen);
        }
        return sDst;
    }
    //-----------------------------------------------------
} // namespace xkcb

