

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


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



#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        EXTERN_C __declspec(selectany) const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif // !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, LIBID_SpellCheckProviderLib,0x34AEE1FF,0x3935,0x4C5B,0x8F,0x6E,0x77,0xC9,0x80,0xE4,0x71,0x85);


MIDL_DEFINE_GUID(CLSID, CLSID_SpellCheckProvider,0x29E2FCDB,0x8C6F,0x4A15,0xAE,0x9A,0x25,0xB5,0xDA,0x1F,0xE4,0x4B);


MIDL_DEFINE_GUID(CLSID, CLSID_SpellCheckProviderFactory,0x718D12CB,0x2C66,0x42C4,0xA0,0x58,0x49,0x55,0x9D,0x0B,0x6C,0x7E);


MIDL_DEFINE_GUID(CLSID, CLSID_EnumString,0x5423BF7C,0x3421,0x4844,0xB6,0xCF,0x50,0xAA,0xF1,0x18,0x4D,0x62);


MIDL_DEFINE_GUID(CLSID, CLSID_OptionDescription,0x50E1285E,0x0BFB,0x4F6C,0xAC,0x09,0xC6,0x1F,0x87,0x92,0xDD,0x51);


MIDL_DEFINE_GUID(CLSID, CLSID_EnumSpellingError,0x445010EB,0x3595,0x4EDE,0xB6,0xC6,0x4A,0x56,0xDA,0x2E,0x20,0xA0);


MIDL_DEFINE_GUID(CLSID, CLSID_SpellingError,0x79EA9F21,0x5E97,0x4C8B,0xB5,0x03,0x91,0x25,0xF8,0xD1,0xD5,0x7A);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



