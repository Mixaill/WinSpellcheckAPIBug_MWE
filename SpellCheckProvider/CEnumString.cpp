#include <Shlwapi.h>

#include "CEnumString.h"

HRESULT EnumString::RuntimeClassInitialize(std::vector<std::wstring>& values)
{
    _values = values;
    return S_OK;
}

STDMETHODIMP EnumString::Next(ULONG celt, LPOLESTR * rgelt, ULONG * pceltFetched)
{
    if (rgelt == nullptr) {
        return E_INVALIDARG;
    }

    if (_values.empty()) {
        return S_FALSE;
    }

    ULONG done = 0;
    while (done < celt && _index < _values.size()) {
        SHStrDupW(_values[_index].c_str(), &rgelt[done]);

        _index++;
        done++;
    }

    if (pceltFetched != nullptr) {
        *pceltFetched = done;
    }

    return done == celt ? S_OK : S_FALSE;
}

STDMETHODIMP EnumString::Skip(ULONG celt)
{
    _index = _index + celt;
    if (_index >= _values.size())
    {
        return S_FALSE;
    }

    return S_OK;
}

STDMETHODIMP EnumString::Reset(void)
{
    _index = 0;
    return S_OK;
}

STDMETHODIMP EnumString::Clone(IEnumString** ppenum)
{
    *ppenum = nullptr;

    ComPtr<EnumString> clone;

    HRESULT hr = MakeAndInitialize<EnumString>(&clone, _values);
    if (!SUCCEEDED(hr)) {
        return hr;
    }

    *ppenum = clone.Detach();

    hr = clone->Skip(_index);
    if (!SUCCEEDED(hr)) {
        return hr;
    }

    return S_OK;
}
