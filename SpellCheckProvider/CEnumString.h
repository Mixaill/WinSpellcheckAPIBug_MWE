#pragma once

#include <vector>
#include <string>

#include <windows.h>
#include <wrl.h>

#include "SpellCheckProviderLib_h.h"

using namespace Microsoft::WRL;

class EnumString : public RuntimeClass<RuntimeClassFlags<ClassicCom>, IEnumString>
{
public:
    EnumString() = default;
    ~EnumString() = default;

    HRESULT RuntimeClassInitialize(std::vector<std::wstring>& values);

    STDMETHODIMP Next(ULONG celt, _Out_writes_to_(celt, *pceltFetched) LPOLESTR *rgelt, _Out_opt_  ULONG *pceltFetched) override;

    STDMETHODIMP Skip(ULONG celt) override;

    STDMETHODIMP Reset(void) override;

    STDMETHODIMP Clone(__RPC__deref_out_opt IEnumString **ppenum) override;

private:

    std::vector<std::wstring> _values;

    ULONG _index = 0;

};