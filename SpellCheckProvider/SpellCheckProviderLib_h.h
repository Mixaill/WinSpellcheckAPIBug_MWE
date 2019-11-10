

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 06:14:07 2038
 */
/* Compiler settings for SpellCheckProviderLib.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.01.0622 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */


#ifndef __SpellCheckProviderLib_h_h__
#define __SpellCheckProviderLib_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __SpellCheckProvider_FWD_DEFINED__
#define __SpellCheckProvider_FWD_DEFINED__

#ifdef __cplusplus
typedef class SpellCheckProvider SpellCheckProvider;
#else
typedef struct SpellCheckProvider SpellCheckProvider;
#endif /* __cplusplus */

#endif 	/* __SpellCheckProvider_FWD_DEFINED__ */


#ifndef __SpellCheckProviderFactory_FWD_DEFINED__
#define __SpellCheckProviderFactory_FWD_DEFINED__

#ifdef __cplusplus
typedef class SpellCheckProviderFactory SpellCheckProviderFactory;
#else
typedef struct SpellCheckProviderFactory SpellCheckProviderFactory;
#endif /* __cplusplus */

#endif 	/* __SpellCheckProviderFactory_FWD_DEFINED__ */


#ifndef __EnumString_FWD_DEFINED__
#define __EnumString_FWD_DEFINED__

#ifdef __cplusplus
typedef class EnumString EnumString;
#else
typedef struct EnumString EnumString;
#endif /* __cplusplus */

#endif 	/* __EnumString_FWD_DEFINED__ */


#ifndef __OptionDescription_FWD_DEFINED__
#define __OptionDescription_FWD_DEFINED__

#ifdef __cplusplus
typedef class OptionDescription OptionDescription;
#else
typedef struct OptionDescription OptionDescription;
#endif /* __cplusplus */

#endif 	/* __OptionDescription_FWD_DEFINED__ */


#ifndef __EnumSpellingError_FWD_DEFINED__
#define __EnumSpellingError_FWD_DEFINED__

#ifdef __cplusplus
typedef class EnumSpellingError EnumSpellingError;
#else
typedef struct EnumSpellingError EnumSpellingError;
#endif /* __cplusplus */

#endif 	/* __EnumSpellingError_FWD_DEFINED__ */


#ifndef __SpellingError_FWD_DEFINED__
#define __SpellingError_FWD_DEFINED__

#ifdef __cplusplus
typedef class SpellingError SpellingError;
#else
typedef struct SpellingError SpellingError;
#endif /* __cplusplus */

#endif 	/* __SpellingError_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "spellcheckprovider.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __SpellCheckProviderLib_LIBRARY_DEFINED__
#define __SpellCheckProviderLib_LIBRARY_DEFINED__

/* library SpellCheckProviderLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_SpellCheckProviderLib;

EXTERN_C const CLSID CLSID_SpellCheckProvider;

#ifdef __cplusplus

class DECLSPEC_UUID("29E2FCDB-8C6F-4A15-AE9A-25B5DA1FE44B")
SpellCheckProvider;
#endif

EXTERN_C const CLSID CLSID_SpellCheckProviderFactory;

#ifdef __cplusplus

class DECLSPEC_UUID("718D12CB-2C66-42C4-A058-49559D0B6C7E")
SpellCheckProviderFactory;
#endif

EXTERN_C const CLSID CLSID_EnumString;

#ifdef __cplusplus

class DECLSPEC_UUID("5423BF7C-3421-4844-B6CF-50AAF1184D62")
EnumString;
#endif

EXTERN_C const CLSID CLSID_OptionDescription;

#ifdef __cplusplus

class DECLSPEC_UUID("50E1285E-0BFB-4F6C-AC09-C61F8792DD51")
OptionDescription;
#endif

EXTERN_C const CLSID CLSID_EnumSpellingError;

#ifdef __cplusplus

class DECLSPEC_UUID("445010EB-3595-4EDE-B6C6-4A56DA2E20A0")
EnumSpellingError;
#endif

EXTERN_C const CLSID CLSID_SpellingError;

#ifdef __cplusplus

class DECLSPEC_UUID("79EA9F21-5E97-4C8B-B503-9125F8D1D57A")
SpellingError;
#endif
#endif /* __SpellCheckProviderLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


