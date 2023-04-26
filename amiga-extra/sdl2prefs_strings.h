#ifndef SDL2PREFS_STRINGS_H
#define SDL2PREFS_STRINGS_H


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

#define MSG_APPLICATION_NAME 0
#define MSG_OK 1
#define MSG_RENDERER_OPTIONS_GROUP 10
#define MSG_DRIVER_GAD 11
#define MSG_DRIVER_DEFAULT 12
#define MSG_DRIVER_COMPOSITING 13
#define MSG_DRIVER_OPENGL 14
#define MSG_DRIVER_OPENGLES2 15
#define MSG_DRIVER_SOFTWARE 16
#define MSG_VERTICAL_SYNC_GAD 17
#define MSG_VERTICAL_SYNC_DEFAULT 18
#define MSG_VERTICAL_SYNC_ENABLED 19
#define MSG_VERTICAL_SYNC_DISABLED 20
#define MSG_BATCHING_MODE_GAD 21
#define MSG_BATCHING_MODE_DEFAULT 22
#define MSG_BATCHING_MODE_ENABLED 23
#define MSG_BATCHING_MODE_DISABLED 24
#define MSG_SCALE_QUALITY_GAD 25
#define MSG_SCALE_QUALITY_DEFAULT 26
#define MSG_SCALE_QUALITY_NEAREST 27
#define MSG_SCALE_QUALITY_LINEAR 28
#define MSG_LOGICAL_SIZE_MODE_GAD 29
#define MSG_LOGICAL_SIZE_MODE_DEFAULT 30
#define MSG_LOGICAL_SIZE_MODE_LETTERBOX_OR_SIDEBARS 31
#define MSG_LOGICAL_SIZE_MODE_OVERSCAN 32
#define MSG_VIDEO_OPTIONS_GROUP 33
#define MSG_SCREEN_SAVER_GAD 34
#define MSG_SCREEN_SAVER_DEFAULT 35
#define MSG_SCREEN_SAVER_ENABLED 36
#define MSG_SCREEN_SAVER_DISABLED 37
#define MSG_SETTINGS_GROUP 38
#define MSG_SAVE_GAD 39
#define MSG_RESET_GAD 40
#define MSG_CANCEL_GAD 41
#define MSG_MAIN_MENU 100
#define MSG_MAIN_ICONIFY 101
#define MSG_MAIN_ABOUT 102
#define MSG_MAIN_QUIT 103
#define MSG_ABOUT_WINDOW 150
#define MSG_ABOUT_AUTHOR 151
#define MSG_ABOUT_TRANSLATOR 152
#define MSG_DRIVER_HELP 200
#define MSG_VERTICAL_SYNC_HELP 201
#define MSG_BATCHING_MODE_HELP 202
#define MSG_SCALE_QUALITY_HELP 203
#define MSG_LOGICAL_SIZE_MODE_HELP 204
#define MSG_SCREEN_SAVER_HELP 205
#define MSG_SAVE_HELP 206
#define MSG_RESET_HELP 207
#define MSG_CANCEL_HELP 208

#endif /* CATCOMP_NUMBERS */


/****************************************************************************/


#ifdef CATCOMP_STRINGS

#define MSG_APPLICATION_NAME_STR "SDL2 Prefs"
#define MSG_OK_STR "_OK"
#define MSG_RENDERER_OPTIONS_GROUP_STR "2D Renderer Options"
#define MSG_DRIVER_GAD_STR "_Driver"
#define MSG_DRIVER_DEFAULT_STR "default"
#define MSG_DRIVER_COMPOSITING_STR "compositing"
#define MSG_DRIVER_OPENGL_STR "opengl"
#define MSG_DRIVER_OPENGLES2_STR "opengles2"
#define MSG_DRIVER_SOFTWARE_STR "software"
#define MSG_VERTICAL_SYNC_GAD_STR "_Vertical Sync"
#define MSG_VERTICAL_SYNC_DEFAULT_STR "default"
#define MSG_VERTICAL_SYNC_ENABLED_STR "enabled"
#define MSG_VERTICAL_SYNC_DISABLED_STR "disabled"
#define MSG_BATCHING_MODE_GAD_STR "_Batching Mode"
#define MSG_BATCHING_MODE_DEFAULT_STR "default"
#define MSG_BATCHING_MODE_ENABLED_STR "enabled"
#define MSG_BATCHING_MODE_DISABLED_STR "disabled"
#define MSG_SCALE_QUALITY_GAD_STR "Scale _Quality"
#define MSG_SCALE_QUALITY_DEFAULT_STR "default"
#define MSG_SCALE_QUALITY_NEAREST_STR "nearest"
#define MSG_SCALE_QUALITY_LINEAR_STR "linear"
#define MSG_LOGICAL_SIZE_MODE_GAD_STR "_Logical Size Mode"
#define MSG_LOGICAL_SIZE_MODE_DEFAULT_STR "default"
#define MSG_LOGICAL_SIZE_MODE_LETTERBOX_OR_SIDEBARS_STR "letterbox / sidebars"
#define MSG_LOGICAL_SIZE_MODE_OVERSCAN_STR "overscan"
#define MSG_VIDEO_OPTIONS_GROUP_STR "Video Options"
#define MSG_SCREEN_SAVER_GAD_STR "_Allow Screen Saver"
#define MSG_SCREEN_SAVER_DEFAULT_STR "default"
#define MSG_SCREEN_SAVER_ENABLED_STR "enabled"
#define MSG_SCREEN_SAVER_DISABLED_STR "disabled"
#define MSG_SETTINGS_GROUP_STR "Settings"
#define MSG_SAVE_GAD_STR "_Save"
#define MSG_RESET_GAD_STR "_Reset"
#define MSG_CANCEL_GAD_STR "_Cancel"
#define MSG_MAIN_MENU_STR "Main"
#define MSG_MAIN_ICONIFY_STR "I\0Iconify"
#define MSG_MAIN_ABOUT_STR "?\0About..."
#define MSG_MAIN_QUIT_STR "Q\0Quit"
#define MSG_ABOUT_WINDOW_STR "About SDL2 Prefs"
#define MSG_ABOUT_AUTHOR_STR "Written by Juha Niemimaki"
#define MSG_ABOUT_TRANSLATOR_STR "(using built-in strings)"
#define MSG_DRIVER_HELP_STR "Select driver implementation:\n \033bcompositing \033ndoesn't support some blend modes\n \033bopengl \033n(MiniGL) doesn't support render targets and some blend modes\n \033bopengles2 \033nsupports most features\n \033bsoftware \033nsupports most features but is not accelerated"
#define MSG_VERTICAL_SYNC_HELP_STR "Synchronize display update to monitor refresh rate"
#define MSG_BATCHING_MODE_HELP_STR "Batching may improve drawing speed if application does many operations per frame and SDL2 is able to combine those"
#define MSG_SCALE_QUALITY_HELP_STR "Nearest pixel sampling or linear filtering"
#define MSG_LOGICAL_SIZE_MODE_HELP_STR "Scaling policy for SDL_RenderSetLogicalSize"
#define MSG_SCREEN_SAVER_HELP_STR "Allow screen saver (disabled by default)"
#define MSG_SAVE_HELP_STR "Store settings to ENVARC: and exit"
#define MSG_RESET_HELP_STR "Reset GUI to default values"
#define MSG_CANCEL_HELP_STR "Exit program"

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
    {MSG_APPLICATION_NAME,(CONST_STRPTR)MSG_APPLICATION_NAME_STR},
    {MSG_OK,(CONST_STRPTR)MSG_OK_STR},
    {MSG_RENDERER_OPTIONS_GROUP,(CONST_STRPTR)MSG_RENDERER_OPTIONS_GROUP_STR},
    {MSG_DRIVER_GAD,(CONST_STRPTR)MSG_DRIVER_GAD_STR},
    {MSG_DRIVER_DEFAULT,(CONST_STRPTR)MSG_DRIVER_DEFAULT_STR},
    {MSG_DRIVER_COMPOSITING,(CONST_STRPTR)MSG_DRIVER_COMPOSITING_STR},
    {MSG_DRIVER_OPENGL,(CONST_STRPTR)MSG_DRIVER_OPENGL_STR},
    {MSG_DRIVER_OPENGLES2,(CONST_STRPTR)MSG_DRIVER_OPENGLES2_STR},
    {MSG_DRIVER_SOFTWARE,(CONST_STRPTR)MSG_DRIVER_SOFTWARE_STR},
    {MSG_VERTICAL_SYNC_GAD,(CONST_STRPTR)MSG_VERTICAL_SYNC_GAD_STR},
    {MSG_VERTICAL_SYNC_DEFAULT,(CONST_STRPTR)MSG_VERTICAL_SYNC_DEFAULT_STR},
    {MSG_VERTICAL_SYNC_ENABLED,(CONST_STRPTR)MSG_VERTICAL_SYNC_ENABLED_STR},
    {MSG_VERTICAL_SYNC_DISABLED,(CONST_STRPTR)MSG_VERTICAL_SYNC_DISABLED_STR},
    {MSG_BATCHING_MODE_GAD,(CONST_STRPTR)MSG_BATCHING_MODE_GAD_STR},
    {MSG_BATCHING_MODE_DEFAULT,(CONST_STRPTR)MSG_BATCHING_MODE_DEFAULT_STR},
    {MSG_BATCHING_MODE_ENABLED,(CONST_STRPTR)MSG_BATCHING_MODE_ENABLED_STR},
    {MSG_BATCHING_MODE_DISABLED,(CONST_STRPTR)MSG_BATCHING_MODE_DISABLED_STR},
    {MSG_SCALE_QUALITY_GAD,(CONST_STRPTR)MSG_SCALE_QUALITY_GAD_STR},
    {MSG_SCALE_QUALITY_DEFAULT,(CONST_STRPTR)MSG_SCALE_QUALITY_DEFAULT_STR},
    {MSG_SCALE_QUALITY_NEAREST,(CONST_STRPTR)MSG_SCALE_QUALITY_NEAREST_STR},
    {MSG_SCALE_QUALITY_LINEAR,(CONST_STRPTR)MSG_SCALE_QUALITY_LINEAR_STR},
    {MSG_LOGICAL_SIZE_MODE_GAD,(CONST_STRPTR)MSG_LOGICAL_SIZE_MODE_GAD_STR},
    {MSG_LOGICAL_SIZE_MODE_DEFAULT,(CONST_STRPTR)MSG_LOGICAL_SIZE_MODE_DEFAULT_STR},
    {MSG_LOGICAL_SIZE_MODE_LETTERBOX_OR_SIDEBARS,(CONST_STRPTR)MSG_LOGICAL_SIZE_MODE_LETTERBOX_OR_SIDEBARS_STR},
    {MSG_LOGICAL_SIZE_MODE_OVERSCAN,(CONST_STRPTR)MSG_LOGICAL_SIZE_MODE_OVERSCAN_STR},
    {MSG_VIDEO_OPTIONS_GROUP,(CONST_STRPTR)MSG_VIDEO_OPTIONS_GROUP_STR},
    {MSG_SCREEN_SAVER_GAD,(CONST_STRPTR)MSG_SCREEN_SAVER_GAD_STR},
    {MSG_SCREEN_SAVER_DEFAULT,(CONST_STRPTR)MSG_SCREEN_SAVER_DEFAULT_STR},
    {MSG_SCREEN_SAVER_ENABLED,(CONST_STRPTR)MSG_SCREEN_SAVER_ENABLED_STR},
    {MSG_SCREEN_SAVER_DISABLED,(CONST_STRPTR)MSG_SCREEN_SAVER_DISABLED_STR},
    {MSG_SETTINGS_GROUP,(CONST_STRPTR)MSG_SETTINGS_GROUP_STR},
    {MSG_SAVE_GAD,(CONST_STRPTR)MSG_SAVE_GAD_STR},
    {MSG_RESET_GAD,(CONST_STRPTR)MSG_RESET_GAD_STR},
    {MSG_CANCEL_GAD,(CONST_STRPTR)MSG_CANCEL_GAD_STR},
    {MSG_MAIN_MENU,(CONST_STRPTR)MSG_MAIN_MENU_STR},
    {MSG_MAIN_ICONIFY,(CONST_STRPTR)MSG_MAIN_ICONIFY_STR},
    {MSG_MAIN_ABOUT,(CONST_STRPTR)MSG_MAIN_ABOUT_STR},
    {MSG_MAIN_QUIT,(CONST_STRPTR)MSG_MAIN_QUIT_STR},
    {MSG_ABOUT_WINDOW,(CONST_STRPTR)MSG_ABOUT_WINDOW_STR},
    {MSG_ABOUT_AUTHOR,(CONST_STRPTR)MSG_ABOUT_AUTHOR_STR},
    {MSG_ABOUT_TRANSLATOR,(CONST_STRPTR)MSG_ABOUT_TRANSLATOR_STR},
    {MSG_DRIVER_HELP,(CONST_STRPTR)MSG_DRIVER_HELP_STR},
    {MSG_VERTICAL_SYNC_HELP,(CONST_STRPTR)MSG_VERTICAL_SYNC_HELP_STR},
    {MSG_BATCHING_MODE_HELP,(CONST_STRPTR)MSG_BATCHING_MODE_HELP_STR},
    {MSG_SCALE_QUALITY_HELP,(CONST_STRPTR)MSG_SCALE_QUALITY_HELP_STR},
    {MSG_LOGICAL_SIZE_MODE_HELP,(CONST_STRPTR)MSG_LOGICAL_SIZE_MODE_HELP_STR},
    {MSG_SCREEN_SAVER_HELP,(CONST_STRPTR)MSG_SCREEN_SAVER_HELP_STR},
    {MSG_SAVE_HELP,(CONST_STRPTR)MSG_SAVE_HELP_STR},
    {MSG_RESET_HELP,(CONST_STRPTR)MSG_RESET_HELP_STR},
    {MSG_CANCEL_HELP,(CONST_STRPTR)MSG_CANCEL_HELP_STR},
};

#endif /* CATCOMP_ARRAY */


/****************************************************************************/


#ifdef CATCOMP_BLOCK

STATIC CONST UBYTE CatCompBlock[] =
{
    "\x00\x00\x00\x00\x00\x0C"
    MSG_APPLICATION_NAME_STR "\x00\x00"
    "\x00\x00\x00\x01\x00\x04"
    MSG_OK_STR "\x00"
    "\x00\x00\x00\x0A\x00\x14"
    MSG_RENDERER_OPTIONS_GROUP_STR "\x00"
    "\x00\x00\x00\x0B\x00\x08"
    MSG_DRIVER_GAD_STR "\x00"
    "\x00\x00\x00\x0C\x00\x08"
    MSG_DRIVER_DEFAULT_STR "\x00"
    "\x00\x00\x00\x0D\x00\x0C"
    MSG_DRIVER_COMPOSITING_STR "\x00"
    "\x00\x00\x00\x0E\x00\x08"
    MSG_DRIVER_OPENGL_STR "\x00\x00"
    "\x00\x00\x00\x0F\x00\x0A"
    MSG_DRIVER_OPENGLES2_STR "\x00"
    "\x00\x00\x00\x10\x00\x0A"
    MSG_DRIVER_SOFTWARE_STR "\x00\x00"
    "\x00\x00\x00\x11\x00\x10"
    MSG_VERTICAL_SYNC_GAD_STR "\x00\x00"
    "\x00\x00\x00\x12\x00\x08"
    MSG_VERTICAL_SYNC_DEFAULT_STR "\x00"
    "\x00\x00\x00\x13\x00\x08"
    MSG_VERTICAL_SYNC_ENABLED_STR "\x00"
    "\x00\x00\x00\x14\x00\x0A"
    MSG_VERTICAL_SYNC_DISABLED_STR "\x00\x00"
    "\x00\x00\x00\x15\x00\x10"
    MSG_BATCHING_MODE_GAD_STR "\x00\x00"
    "\x00\x00\x00\x16\x00\x08"
    MSG_BATCHING_MODE_DEFAULT_STR "\x00"
    "\x00\x00\x00\x17\x00\x08"
    MSG_BATCHING_MODE_ENABLED_STR "\x00"
    "\x00\x00\x00\x18\x00\x0A"
    MSG_BATCHING_MODE_DISABLED_STR "\x00\x00"
    "\x00\x00\x00\x19\x00\x10"
    MSG_SCALE_QUALITY_GAD_STR "\x00\x00"
    "\x00\x00\x00\x1A\x00\x08"
    MSG_SCALE_QUALITY_DEFAULT_STR "\x00"
    "\x00\x00\x00\x1B\x00\x08"
    MSG_SCALE_QUALITY_NEAREST_STR "\x00"
    "\x00\x00\x00\x1C\x00\x08"
    MSG_SCALE_QUALITY_LINEAR_STR "\x00\x00"
    "\x00\x00\x00\x1D\x00\x14"
    MSG_LOGICAL_SIZE_MODE_GAD_STR "\x00\x00"
    "\x00\x00\x00\x1E\x00\x08"
    MSG_LOGICAL_SIZE_MODE_DEFAULT_STR "\x00"
    "\x00\x00\x00\x1F\x00\x16"
    MSG_LOGICAL_SIZE_MODE_LETTERBOX_OR_SIDEBARS_STR "\x00\x00"
    "\x00\x00\x00\x20\x00\x0A"
    MSG_LOGICAL_SIZE_MODE_OVERSCAN_STR "\x00\x00"
    "\x00\x00\x00\x21\x00\x0E"
    MSG_VIDEO_OPTIONS_GROUP_STR "\x00"
    "\x00\x00\x00\x22\x00\x14"
    MSG_SCREEN_SAVER_GAD_STR "\x00"
    "\x00\x00\x00\x23\x00\x08"
    MSG_SCREEN_SAVER_DEFAULT_STR "\x00"
    "\x00\x00\x00\x24\x00\x08"
    MSG_SCREEN_SAVER_ENABLED_STR "\x00"
    "\x00\x00\x00\x25\x00\x0A"
    MSG_SCREEN_SAVER_DISABLED_STR "\x00\x00"
    "\x00\x00\x00\x26\x00\x0A"
    MSG_SETTINGS_GROUP_STR "\x00\x00"
    "\x00\x00\x00\x27\x00\x06"
    MSG_SAVE_GAD_STR "\x00"
    "\x00\x00\x00\x28\x00\x08"
    MSG_RESET_GAD_STR "\x00\x00"
    "\x00\x00\x00\x29\x00\x08"
    MSG_CANCEL_GAD_STR "\x00"
    "\x00\x00\x00\x64\x00\x06"
    MSG_MAIN_MENU_STR "\x00\x00"
    "\x00\x00\x00\x65\x00\x0A"
    MSG_MAIN_ICONIFY_STR "\x00"
    "\x00\x00\x00\x66\x00\x0C"
    MSG_MAIN_ABOUT_STR "\x00\x00"
    "\x00\x00\x00\x67\x00\x08"
    MSG_MAIN_QUIT_STR "\x00\x00"
    "\x00\x00\x00\x96\x00\x12"
    MSG_ABOUT_WINDOW_STR "\x00\x00"
    "\x00\x00\x00\x97\x00\x1A"
    MSG_ABOUT_AUTHOR_STR "\x00"
    "\x00\x00\x00\x98\x00\x1A"
    MSG_ABOUT_TRANSLATOR_STR "\x00\x00"
    "\x00\x00\x00\xC8\x00\xFC"
    MSG_DRIVER_HELP_STR "\x00\x00"
    "\x00\x00\x00\xC9\x00\x34"
    MSG_VERTICAL_SYNC_HELP_STR "\x00\x00"
    "\x00\x00\x00\xCA\x00\x74"
    MSG_BATCHING_MODE_HELP_STR "\x00\x00"
    "\x00\x00\x00\xCB\x00\x2C"
    MSG_SCALE_QUALITY_HELP_STR "\x00\x00"
    "\x00\x00\x00\xCC\x00\x2C"
    MSG_LOGICAL_SIZE_MODE_HELP_STR "\x00"
    "\x00\x00\x00\xCD\x00\x2A"
    MSG_SCREEN_SAVER_HELP_STR "\x00\x00"
    "\x00\x00\x00\xCE\x00\x24"
    MSG_SAVE_HELP_STR "\x00\x00"
    "\x00\x00\x00\xCF\x00\x1C"
    MSG_RESET_HELP_STR "\x00"
    "\x00\x00\x00\xD0\x00\x0E"
    MSG_CANCEL_HELP_STR "\x00\x00"
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


#endif /* SDL2PREFS_STRINGS_H */
