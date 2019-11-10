// Copyright (c) Microsoft Corporation. All rights reserved

#include <io.h>
#include <fcntl.h>
#include <iomanip>
#include <iostream>

#include <Windows.h>
#include <wrl/client.h>

#include <spellcheck.h>

using namespace Microsoft::WRL;

ComPtr<ISpellCheckerFactory> CreateSpellCheckerFactory()
{
	ComPtr<ISpellCheckerFactory> factory;
	CoCreateInstance(
		__uuidof(SpellCheckerFactory),
		nullptr,
		CLSCTX_INPROC_SERVER,
		__uuidof(factory),
		reinterpret_cast<void**>(factory.GetAddressOf()));

	return factory;
}

inline HRESULT PrintEnumString(ComPtr<IEnumString>& enumString)
{
	HRESULT hr = S_OK;
	while (S_OK == hr)
	{
		LPOLESTR string = nullptr;
		hr = enumString->Next(1, &string, nullptr);

		if (hr == S_OK){
			std::wcout<< string << std::endl;
		}
		CoTaskMemFree(string);
	}

	return (SUCCEEDED(hr) ? S_OK : hr);
}

void PrintAvailableLanguages(ComPtr<ISpellCheckerFactory>& spellCheckerFactory)
{
	ComPtr<IEnumString> enumLanguages;
	HRESULT hr = spellCheckerFactory->get_SupportedLanguages(enumLanguages.GetAddressOf());

	if (SUCCEEDED(hr))
	{
		std::wcout<<L"Available languages:" << std::endl;
	}

	if (SUCCEEDED(hr)){
		hr = PrintEnumString(enumLanguages);
	}
}

int wmain()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);

	if (!SUCCEEDED(CoInitializeEx(nullptr, COINIT_MULTITHREADED)))
	{
		std::wcout << L"1: Failed to initialize" << std::endl;
		return 1;
	}

	auto spellCheckerFactory = CreateSpellCheckerFactory();
	if (!spellCheckerFactory) {
		std::wcout << L"2: Failed to get spell checker factory" << std::endl;
		return 2;
	}
	
	PrintAvailableLanguages(spellCheckerFactory);
	return 0;
}