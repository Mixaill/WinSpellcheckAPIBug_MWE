#pragma once

#include <windows.h>
#include <wrl.h>

#include "SpellCheckProviderLib_h.h"

using namespace Microsoft::WRL;

class EnumSpellingError : public RuntimeClass<RuntimeClassFlags<ClassicCom>, IEnumSpellingError>
{
public:
    EnumSpellingError() = default;
    ~EnumSpellingError();

    HRESULT RuntimeClassInitialize(_In_ PCWSTR text, _In_ SpellCheckProvider* spellcheckProvider);

    STDMETHODIMP Next(_COM_Outptr_ ISpellingError** value);

private:
    SpellCheckProvider* _spellcheckProvider = nullptr;
    PWSTR _text = nullptr;
    PWSTR _currentTextPosition = nullptr;
};