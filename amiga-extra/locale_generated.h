#ifndef LOCALE_GENERATED_H
#define LOCALE_GENERATED_H


/****************************************************************************/


/* This file was created automatically by CatComp.
 * Do NOT edit by hand!
 */


#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifdef CATCOMP_CODE
#ifndef CATCOMP_BLOCK
#define CATCOMP_ARRAY
#endif
#endif

#ifdef CATCOMP_ARRAY
#ifndef CATCOMP_NUMBERS
#define CATCOMP_NUMBERS
#endif
#ifndef CATCOMP_STRINGS
#define CATCOMP_STRINGS
#endif
#endif

#ifdef CATCOMP_BLOCK
#ifndef CATCOMP_STRINGS
#define CATCOMP_STRINGS
#endif
#endif


/****************************************************************************/


#ifdef CATCOMP_NUMBERS

#define MSG_SDL3_ICONIFY 0
#define MSG_SDL3_ABOUT 1
#define MSG_SDL3_QUIT 2
#define MSG_SDL3_ABOUT_REQ 3
#define MSG_SDL3_OK 4
#define MSG_SDL3_APPLICATION 5
#define MSG_SDL3_LIBRARY_VERSION 6

#endif /* CATCOMP_NUMBERS */


/****************************************************************************/


#ifdef CATCOMP_STRINGS

#define MSG_SDL3_ICONIFY_STR "I|Iconify"
#define MSG_SDL3_ABOUT_STR "A|About..."
#define MSG_SDL3_QUIT_STR "Q|Quit"
#define MSG_SDL3_ABOUT_REQ_STR "About SDL3"
#define MSG_SDL3_OK_STR "_Ok"
#define MSG_SDL3_APPLICATION_STR "SDL3 application"
#define MSG_SDL3_LIBRARY_VERSION_STR "SDL library version"

#endif /* CATCOMP_STRINGS */


/****************************************************************************/


#ifdef CATCOMP_ARRAY

struct CatCompArrayType
{
    LONG         cca_ID;
    CONST_STRPTR cca_Str;
};

STATIC CONST struct CatCompArrayType CatCompArray[] =
{
    {MSG_SDL3_ICONIFY,(CONST_STRPTR)MSG_SDL3_ICONIFY_STR},
    {MSG_SDL3_ABOUT,(CONST_STRPTR)MSG_SDL3_ABOUT_STR},
    {MSG_SDL3_QUIT,(CONST_STRPTR)MSG_SDL3_QUIT_STR},
    {MSG_SDL3_ABOUT_REQ,(CONST_STRPTR)MSG_SDL3_ABOUT_REQ_STR},
    {MSG_SDL3_OK,(CONST_STRPTR)MSG_SDL3_OK_STR},
    {MSG_SDL3_APPLICATION,(CONST_STRPTR)MSG_SDL3_APPLICATION_STR},
    {MSG_SDL3_LIBRARY_VERSION,(CONST_STRPTR)MSG_SDL3_LIBRARY_VERSION_STR},
};

#endif /* CATCOMP_ARRAY */


/****************************************************************************/


#ifdef CATCOMP_BLOCK

STATIC CONST UBYTE CatCompBlock[] =
{
    "\x00\x00\x00\x00\x00\x0A"
    MSG_SDL3_ICONIFY_STR "\x00"
    "\x00\x00\x00\x01\x00\x0C"
    MSG_SDL3_ABOUT_STR "\x00\x00"
    "\x00\x00\x00\x02\x00\x08"
    MSG_SDL3_QUIT_STR "\x00\x00"
    "\x00\x00\x00\x03\x00\x0C"
    MSG_SDL3_ABOUT_REQ_STR "\x00\x00"
    "\x00\x00\x00\x04\x00\x04"
    MSG_SDL3_OK_STR "\x00"
    "\x00\x00\x00\x05\x00\x12"
    MSG_SDL3_APPLICATION_STR "\x00\x00"
    "\x00\x00\x00\x06\x00\x14"
    MSG_SDL3_LIBRARY_VERSION_STR "\x00"
};

#endif /* CATCOMP_BLOCK */


/****************************************************************************/


#ifndef PROTO_LOCALE_H
 #ifndef __NOLIBBASE__
  #define _NLB_DEFINED_
  #define __NOLIBBASE__
 #endif
 #ifndef __NOGLOBALIFACE__
  #define _NGI_DEFINED_
  #define __NOGLOBALIFACE__
 #endif
 #include <proto/locale.h>
 #ifdef _NLB_DEFINED_
  #undef __NOLIBBASE__
  #undef _NLB_DEFINED_
 #endif
 #ifdef _NGI_DEFINED_
  #undef __NOGLOBALIFACE__
  #undef _NGI_DEFINED_
 #endif
#endif

struct LocaleInfo
{
#ifndef __amigaos4__
    struct Library     *li_LocaleBase;
#else
    struct LocaleIFace *li_ILocale;
#endif
    struct Catalog     *li_Catalog;
};


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

CONST_STRPTR GetStringGenerated(struct LocaleInfo *li, LONG stringNum);

#ifdef __cplusplus
}
#endif /* __cplusplus */


#ifdef CATCOMP_CODE

CONST_STRPTR GetStringGenerated(struct LocaleInfo *li, LONG stringNum)
{
#ifndef __amigaos4__
    struct Library     *LocaleBase = li->li_LocaleBase;
#else
    struct LocaleIFace *ILocale    = li->li_ILocale;
#endif
    LONG         *l;
    UWORD        *w;
    CONST_STRPTR  builtIn = NULL;

    l = (LONG *)CatCompBlock;

    while (*l != stringNum && l < (LONG *)(&CatCompBlock[sizeof(CatCompBlock)]))
    {
        w = (UWORD *)((ULONG)l + 4);
        l = (LONG *)((ULONG)l + (ULONG)*w + 6);
    }
    if (*l == stringNum)
    {
        builtIn = (CONST_STRPTR)((ULONG)l + 6);
    }

#ifndef __amigaos4__
    if (LocaleBase)
    {
        return GetCatalogStr(li->li_Catalog, stringNum, builtIn);
    }
#else
    if (ILocale)
    {
#ifdef __USE_INLINE__
        return GetCatalogStr(li->li_Catalog, stringNum, builtIn);
#else
        return ILocale->GetCatalogStr(li->li_Catalog, stringNum, builtIn);
#endif
    }
#endif
    return builtIn;
}


#endif /* CATCOMP_CODE */


/****************************************************************************/


#endif /* LOCALE_GENERATED_H */
