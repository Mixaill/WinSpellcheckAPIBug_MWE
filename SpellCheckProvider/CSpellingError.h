#pragma once

#include <windows.h>
#include <wrl.h>

#include "SpellCheckProviderLib_h.h"

using namespace Microsoft::WRL;

class SpellingError : public RuntimeClass<RuntimeClassFlags<ClassicCom>, ISpellingError>
{
public:
    SpellingError() = default;
    ~SpellingError();

    HRESULT RuntimeClassInitialize(_In_ ULONG startIndex, _In_ ULONG errorLength, _In_ CORRECTIVE_ACTION correctiveAction, _In_ PCWSTR replacement);

    STDMETHODIMP get_StartIndex(_Out_ ULONG* value);
    STDMETHODIMP get_Length(_Out_ ULONG* value);
    STDMETHODIMP get_CorrectiveAction(_Out_ CORRECTIVE_ACTION* value);
    STDMETHODIMP get_Replacement(_Out_ PWSTR* value);

private:

    ULONG _startIndex = 0;
    ULONG _errorLength = 0;
    CORRECTIVE_ACTION _correctiveAction = CORRECTIVE_ACTION_NONE;
    PWSTR _replacement = nullptr;
};
