#include <codecvt>
#include <string>
#include <sstream>
#include <algorithm>

#include "StringHelper.h"

std::string StringHelper::wstring_to_utf8(const std::wstring& str)
{
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    return converter.to_bytes(str);
}

std::wstring StringHelper::utf8_to_wstring(const std::string& str)
{
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    return converter.from_bytes(str);
}

template<typename Out>
void StringHelper::split(const std::wstring &s, wchar_t delim, Out result)
{
    std::wstringstream ss;
    ss.str(s);
    std::wstring item;
    while (std::getline(ss, item, delim))
    {
        *(result++) = item;
    }
}

std::vector<std::wstring> StringHelper::split(const std::wstring &s, wchar_t delim, bool lowercase)
{
    std::vector<std::wstring> elems;
    split(s, delim, std::back_inserter(elems));

    if (lowercase)
    {
        for (auto& elem : elems)
        {
            std::transform(elem.begin(), elem.end(), elem.begin(), towlower);
        }
    }
    return elems;
}

std::wstring StringHelper::create_wstring_from_pointers(const wchar_t* begin, const wchar_t* end)
{
    if (end < begin)
    {
        return L"";
    }

    const size_t word_size = end - begin;
    wchar_t* word = new wchar_t[word_size + 1]{ 0 };
    memcpy(word, begin, word_size * sizeof(wchar_t));
    std::wstring word_w(word);
    return word_w;
}

bool StringHelper::is_delimeter(const wchar_t c)
{
    return (
        //punctuation
        (c == L',') ||
        (c == L'.') ||
        (c == L'!') ||
        (c == L'?') ||
        (c == L':') ||
        (c == L';') ||
    //  (c == L'…') ||

        //brackets
        (c == L'(') ||
        (c == L')') ||
        (c == L'{') ||
        (c == L'}') ||
        (c == L'[') ||
        (c == L']') ||
        (c == L'<') ||
        (c == L'>') ||

        //quotes
    //  (c == L'«') ||
    //  (c == L'»') ||
    //  (c == L'“') ||
    //  (c == L'”') ||
        (c == L'"') ||

        //slashes
        (c == L'/') ||
    //  (c == L'⁄') ||

        //whitespaces
        (c == L'\u00A0') || //No-Break Space
        (c == L' ')      ||
        (c == L'\t')     ||

        //lineending
        (c == L'\n')
    );
}

const wchar_t* StringHelper::find_first_non_delimeter(const wchar_t* text)
{
    const wchar_t* p;
    for (p = text; *p != L'\0'; ++p)
    {
        if (!is_delimeter(*p))
        {
            break;
        }
    }

    return p;
}

const wchar_t* StringHelper::find_first_delimeter(const wchar_t* text)
{
    const wchar_t* p;
    for (p = text; *p != L'\0'; ++p)
    {
        if (is_delimeter(*p))
        {
            break;
        }
    }

    return p;
}

std::vector<uint32_t> StringHelper::wstring_to_utf32(const std::wstring& string)
{
    const wchar_t* src = string.c_str();
    std::vector<uint32_t> dest;

    do {
#ifdef _WIN32
        if ((*src & 0xD800) == 0xD800)
            dest.push_back(((*src++ & 0x07ff) << 10) + (*src & 0x7ff) + 0x10000);
        else
#endif
            dest.push_back(*src);
    } while (*src++);

    return dest;
}

std::wstring StringHelper::utf32_to_wstring(const std::vector<uint32_t>& string)
{
    std::vector<uint16_t> newstring;

    for (const uint32_t& character : string)
    {
        if (character < 0x10000)
        {
            newstring.push_back(static_cast<uint16_t>(character));
        }
        else
        {
            const uint32_t t = character - 0x10000;
            newstring.push_back(static_cast<uint16_t>(t / 0x400 + 0xDC00));
            newstring.push_back(static_cast<uint16_t>(t % 0x400 + 0xD800));
        }
    }

    return std::wstring(newstring.begin(), newstring.end());
}

uint32_t* StringHelper::utf32vector_to_utf32array(const std::vector<uint32_t>& vec)
{
    if (vec.empty())
        return nullptr;

    uint32_t* res = new uint32_t[vec.size()];
    for (size_t i = 0; i < vec.size(); i++)
    {
        res[i] = vec[i];
    }
    return res;
}

std::wstring StringHelper::replace_all(std::wstring str, const std::wstring& from, const std::wstring& to)
{
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != std::wstring::npos)
    {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
    return str;
}
