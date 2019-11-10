#include <shlwapi.h>

#include "CSpellingError.h"

SpellingError::~SpellingError()
{
    if (_replacement != nullptr) {
        CoTaskMemFree(_replacement);
    }
}

STDMETHODIMP SpellingError::get_StartIndex(_Out_ ULONG* value)
{
    *value = _startIndex;
    return S_OK;
}

STDMETHODIMP SpellingError::get_Length(_Out_ ULONG* value)
{
    *value = _errorLength;
    return S_OK;
}

STDMETHODIMP SpellingError::get_CorrectiveAction(_Out_ CORRECTIVE_ACTION* value)
{
    *value = _correctiveAction;
    return S_OK;
}

STDMETHODIMP SpellingError::get_Replacement(_Out_ PWSTR* value)
{
    return SHStrDupW(_replacement, value);
}

HRESULT SpellingError::RuntimeClassInitialize(_In_ ULONG startIndex, _In_ ULONG errorLength, _In_ CORRECTIVE_ACTION correctiveAction, _In_ PCWSTR replacement)
{
    _startIndex = startIndex;
    _errorLength = errorLength;
    _correctiveAction = correctiveAction;

    return SHStrDupW(replacement, &_replacement);
}
