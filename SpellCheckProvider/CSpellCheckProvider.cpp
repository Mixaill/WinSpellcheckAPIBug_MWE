#include <shlwapi.h>

#include "CEnumSpellingError.h"
#include "CEnumString.h"
#include "CSpellCheckProvider.h"
#include "COptionDescription.h"

#include "StringHelper.h"

SpellCheckProvider::~SpellCheckProvider()
{
    if (_languageTag != nullptr) {
        CoTaskMemFree(_languageTag);
    }
}

HRESULT SpellCheckProvider::RuntimeClassInitialize(PCWSTR languageTag)
{
    if (languageTag == nullptr) {
        return E_POINTER;
    }

    return SHStrDupW(languageTag, &_languageTag);
}

IFACEMETHODIMP SpellCheckProvider::get_LanguageTag(_Out_ PWSTR* value)
{
   return SHStrDupW(_languageTag, value);
};

IFACEMETHODIMP SpellCheckProvider::get_Id(_Out_ PWSTR* value)
{
    return SHStrDupW(SPELLCHECK_PROVIDER_ID, value);
}

IFACEMETHODIMP SpellCheckProvider::get_LocalizedName(_Out_ PWSTR* value)
{
    return SHStrDupW(SPELLCHECK_PROVIDER_DESCRIPTION, value);
}

IFACEMETHODIMP SpellCheckProvider::get_OptionIds(_COM_Outptr_ IEnumString** value)
{
    *value = nullptr;

    std::vector<std::wstring> ids{ std::wstring(SPELLCHECK_PROVIDER_ID) + L":option_id" };

    ComPtr<IEnumString> enumString;
    const HRESULT hr = MakeAndInitialize<EnumString>(
        &enumString,
        ids);

    if (SUCCEEDED(hr)) {
        *value = enumString.Detach();
        return S_OK;
    }
    else {
        return hr;
    }
}

IFACEMETHODIMP SpellCheckProvider::Check(_In_ PCWSTR text, _COM_Outptr_ IEnumSpellingError** value)
{
    *value = nullptr;

    ComPtr<EnumSpellingError> enumSpellingError;
    HRESULT hr = MakeAndInitialize<EnumSpellingError>(&enumSpellingError, text, this);
    if (SUCCEEDED(hr)) {
        *value = enumSpellingError.Detach();
        return S_OK;
    }
    else {
        return hr;
    }
}

IFACEMETHODIMP SpellCheckProvider::Suggest(_In_ PCWSTR word, _COM_Outptr_ IEnumString** value)
{
    *value = nullptr;

    if (word == nullptr) {
        return E_POINTER;
    }

    if (word[0] == L'\0')  {
        return E_INVALIDARG;
    }

    return E_NOTIMPL;
}

IFACEMETHODIMP SpellCheckProvider::GetOptionValue(_In_ PCWSTR optionId, _Out_ BYTE* value)
{
    if (optionId == nullptr) {
        return E_POINTER;
    }

    std::vector<std::wstring> tokens = StringHelper::split(optionId, L':', false);

    if (tokens[0] != SPELLCHECK_PROVIDER_ID) {
        return E_INVALIDARG;
    }

    if (tokens.size() < 2 || tokens.size() >3) {
        return E_INVALIDARG;
    }

    *value = 0;

    return S_OK;
}

IFACEMETHODIMP SpellCheckProvider::SetOptionValue(_In_ PCWSTR optionId, _In_ BYTE value)
{

    if (optionId == nullptr) {
        return E_POINTER;
    }

    std::vector<std::wstring> tokens = StringHelper::split(optionId, L':', false);

    if (tokens[0] != SPELLCHECK_PROVIDER_ID) {
        return E_INVALIDARG;
    }

    if (tokens.size() < 2 || tokens.size() > 3) {
        return E_INVALIDARG;
    }

    return S_OK;
}

IFACEMETHODIMP SpellCheckProvider::InitializeWordlist(_In_ WORDLIST_TYPE wordlistType, _In_ IEnumString* words)
{
    return S_OK;
}

IFACEMETHODIMP SpellCheckProvider::GetOptionDescription(_In_ PCWSTR optionId, _COM_Outptr_ IOptionDescription** value)
{
    if (optionId == nullptr) {
        return E_POINTER;
    }


    *value = nullptr;
    ComPtr<OptionDescription> optionDescription;
    const auto hr = MakeAndInitialize<OptionDescription>(&optionDescription, optionId);

    if (SUCCEEDED(hr)) {
        *value = optionDescription.Detach();
        return S_OK;
    } else
    {
        return hr;
    }
}
