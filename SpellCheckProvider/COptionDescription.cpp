#include <vector>
#include <string>

#include <Shlwapi.h>

#include "CEnumString.h"
#include "COptionDescription.h"
#include "CSpellCheckProvider.h"

#include "StringHelper.h"


HRESULT OptionDescription::RuntimeClassInitialize(_In_ PCWSTR optionId)
{
    if (optionId == nullptr) {
        return E_POINTER;
    }

    const auto hr = SHStrDupW(optionId, &_optionId);
    if (hr != S_OK) {
        return hr;
    }

    std::vector<std::wstring> tokens = StringHelper::split(_optionId, L':', false);

    //check if it our setting
    if (tokens[0] != SPELLCHECK_PROVIDER_ID) {
        return E_INVALIDARG;
    }

    if (tokens.size() == 2) {
        lang_tag.clear();
        option_id = tokens[1];
    }
    else if (tokens.size() == 3) {
        lang_tag = tokens[1];
        option_id = tokens[2];
    } 
    else {
        return E_INVALIDARG;
    }

    return S_OK;
}

OptionDescription::~OptionDescription()
{
    if (_optionId != nullptr) {
        CoTaskMemFree(_optionId);
    }
}

STDMETHODIMP OptionDescription::get_Id(_Out_ PWSTR* value)
{
    *value = nullptr;
    return SHStrDupW(_optionId, value);
}

IFACEMETHODIMP OptionDescription::get_Heading(_Out_ PWSTR* value)
{
    *value = nullptr;
    return SHStrDupW((option_id+L"/heading").c_str(), value);
}

IFACEMETHODIMP OptionDescription::get_Description(_Out_ PWSTR* value)
{
    *value = nullptr;
    return SHStrDupW((option_id + L"/description").c_str(), value);
}

IFACEMETHODIMP OptionDescription::get_Labels(_COM_Outptr_ IEnumString** value)
{
    *value = nullptr;

    std::vector<std::wstring>  labels{ option_id + L"/label_1", option_id + L"/label_2" };
    ComPtr<IEnumString> enumString;
    const HRESULT hr = MakeAndInitialize<EnumString>(
        &enumString,
        labels);

    if (SUCCEEDED(hr)) {
        *value = enumString.Detach();
        return S_OK;
    }
    else {
        return hr;
    }
}



