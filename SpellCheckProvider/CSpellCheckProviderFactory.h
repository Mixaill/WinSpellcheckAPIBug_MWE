#pragma once

#include <windows.h>
#include <wrl.h>

#include "SpellCheckProviderLib_h.h"

using namespace Microsoft::WRL;

class SpellCheckProviderFactory : public RuntimeClass<RuntimeClassFlags<ClassicCom>, ISpellCheckProviderFactory>
{
public:
    SpellCheckProviderFactory() = default;
    ~SpellCheckProviderFactory() = default;

    STDMETHODIMP get_SupportedLanguages(_COM_Outptr_ IEnumString** value);
    STDMETHODIMP IsSupported(_In_ PCWSTR languageTag, _Out_ BOOL* value);
    STDMETHODIMP CreateSpellCheckProvider(_In_ PCWSTR languageTag, _COM_Outptr_ ISpellCheckProvider** value);

private:

#ifdef ENABLE_LOGGING
    IP7_Trace* _trace_channel = nullptr;
#endif

};

CoCreatableClass(SpellCheckProviderFactory);
