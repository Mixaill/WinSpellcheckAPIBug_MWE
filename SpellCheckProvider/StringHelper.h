#pragma once

#include <string>
#include <vector>

class StringHelper
{
public:
    static std::string wstring_to_utf8(const std::wstring& str);
    static std::wstring utf8_to_wstring(const std::string& str);

    static std::vector<uint32_t> wstring_to_utf32(const std::wstring& string);
    static std::wstring utf32_to_wstring(const std::vector<uint32_t>& string);
    static uint32_t* utf32vector_to_utf32array(const std::vector<uint32_t>& vec);

    template<typename Out>
    static void split(const std::wstring &s, wchar_t delim, Out result);
    static std::vector<std::wstring> split(const std::wstring &s, wchar_t delim, bool lowercase = true);
    static std::wstring create_wstring_from_pointers(const wchar_t* begin, const wchar_t* end);

    static bool is_delimeter(const wchar_t c);
    static const wchar_t* find_first_delimeter(const wchar_t* text);
    static const wchar_t* find_first_non_delimeter(const wchar_t* text);

    static std::wstring replace_all(std::wstring str, const std::wstring& from, const std::wstring& to);
};