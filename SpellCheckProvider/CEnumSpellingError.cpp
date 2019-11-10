#include <Shlwapi.h>

#include "CEnumSpellingError.h"
#include "CSpellCheckProvider.h"

STDMETHODIMP EnumSpellingError::Next(_COM_Outptr_ ISpellingError** value)
{
    *value = nullptr;
    return E_NOTIMPL;
}

HRESULT EnumSpellingError::RuntimeClassInitialize(_In_ PCWSTR text, _In_ SpellCheckProvider* spellcheckProvider)
{
    HRESULT hr = SHStrDupW(text, &_text);
    if (SUCCEEDED(hr))
    {
        _currentTextPosition = _text;

        _spellcheckProvider = spellcheckProvider;
        if (_spellcheckProvider != nullptr) {
            _spellcheckProvider->AddRef();
        }
    }

    return hr;
}

EnumSpellingError::~EnumSpellingError()
{
    if (_spellcheckProvider != nullptr) {
        _spellcheckProvider->Release();
    }

    CoTaskMemFree(_text);
}
