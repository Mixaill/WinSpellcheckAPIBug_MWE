#pragma once

#include <windows.h>
#include <wrl.h>

#include <spellcheckprovider.h>
#include "SpellCheckProviderLib_h.h"

using namespace Microsoft::WRL;

#define SPELLCHECK_PROVIDER_ID L"winspellcheck_test"
#define SPELLCHECK_PROVIDER_DESCRIPTION L"winspellcheck_test__description"

class SpellCheckProvider : public RuntimeClass<RuntimeClassFlags<ClassicCom>, ISpellCheckProvider>
{
public:
    SpellCheckProvider() = default;
    ~SpellCheckProvider();

    HRESULT RuntimeClassInitialize(_In_ PCWSTR languageTag);

    STDMETHODIMP get_LanguageTag(_Out_ PWSTR* value);
    STDMETHODIMP get_Id(_Out_ PWSTR* value);
    STDMETHODIMP get_LocalizedName(_Out_ PWSTR* value);
    STDMETHODIMP Check(_In_ PCWSTR text, _COM_Outptr_ IEnumSpellingError** value);
    STDMETHODIMP Suggest(_In_ PCWSTR word, _COM_Outptr_ IEnumString** value);
    STDMETHODIMP GetOptionValue(_In_ PCWSTR optionId, _Out_ BYTE* value);
    STDMETHODIMP SetOptionValue(_In_ PCWSTR optionId, BYTE value);
    STDMETHODIMP get_OptionIds(_COM_Outptr_ IEnumString** value);

    STDMETHODIMP InitializeWordlist(WORDLIST_TYPE wordlistType, _In_ IEnumString* words);
    STDMETHODIMP GetOptionDescription(_In_ PCWSTR optionId, _COM_Outptr_ IOptionDescription** value);

private:
    PWSTR _languageTag = nullptr;
};
