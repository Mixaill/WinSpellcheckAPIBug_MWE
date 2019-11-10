#include "CEnumString.h"
#include "CSpellCheckProviderFactory.h"
#include "CSpellCheckProvider.h"

STDMETHODIMP SpellCheckProviderFactory::get_SupportedLanguages(_COM_Outptr_ IEnumString** value)
{
	ComPtr<IEnumString> enumString = nullptr;

    std::vector<std::wstring> languages{ L"be", L"be-BY" };
    const HRESULT hr = MakeAndInitialize<EnumString>(
        &enumString,
        languages);

    if (SUCCEEDED(hr)) {
        *value = enumString.Detach();
        return S_OK;
    }
    else {
        return hr;
    }
}


STDMETHODIMP SpellCheckProviderFactory::IsSupported(_In_ PCWSTR languageTag, _Out_ BOOL* value)
{
    *value = FALSE;

    if (languageTag == nullptr)
    {
        return E_POINTER;
    }

    if (languageTag[0] == L'\0')
    {
        return E_INVALIDARG;
    }

    std::vector<std::wstring> languages{ L"be", L"be-BY" };
    for (auto& language : languages)
    {
        if (language == languageTag)
        {
            *value = TRUE;
            break;
        }
    }

    return S_OK;
}

IFACEMETHODIMP SpellCheckProviderFactory::CreateSpellCheckProvider(_In_ PCWSTR languageTag, _COM_Outptr_ ISpellCheckProvider** value)
{
    *value = nullptr;

    BOOL isSupported = FALSE;

    HRESULT hr = IsSupported(languageTag, &isSupported);
    if (!SUCCEEDED(hr))
    {
        return hr;
    }

    if (isSupported == FALSE)
    {
        return E_INVALIDARG;
    }

    ComPtr<ISpellCheckProvider> spellProvider = nullptr;
    hr = MakeAndInitialize<SpellCheckProvider>(&spellProvider, languageTag);

    if (spellProvider == nullptr)
    {
        return E_POINTER;
    }

    if (!SUCCEEDED(hr))
    {
        return hr;
    }

    *value = spellProvider.Detach();

    return S_OK;
}
