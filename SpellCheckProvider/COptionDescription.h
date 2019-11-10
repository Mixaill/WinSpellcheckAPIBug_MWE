#pragma once

#include <string>

#include <windows.h>
#include <wrl.h>

#include "SpellCheckProviderLib_h.h"

using namespace Microsoft::WRL;

class OptionDescription : public RuntimeClass<RuntimeClassFlags<ClassicCom>, IOptionDescription>
{
public:
    OptionDescription() = default;
    ~OptionDescription();

    HRESULT RuntimeClassInitialize(_In_ PCWSTR optionId);

    STDMETHODIMP get_Id(_Out_ PWSTR* value);
    STDMETHODIMP get_Heading(_Out_ PWSTR* value);
    STDMETHODIMP get_Description(_Out_ PWSTR* value);
    STDMETHODIMP get_Labels(_COM_Outptr_ IEnumString** value);

private:
    PWSTR _optionId = nullptr;
    std::wstring lang_tag;
    std::wstring option_id;
};
