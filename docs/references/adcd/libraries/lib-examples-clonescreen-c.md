---
title: Lib_examples/clonescreen.c
manual: libraries
chapter: libraries
section: lib-examples-clonescreen-c
functions: [OpenScreenTagList]
libraries: [intuition.library]
---

# Lib_examples/clonescreen.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/* clonescreen.c
** clone an existing public screen.
**
** SAS/C 5.10a
** lc -b1 -cfist -v -y clonescreen
** blink FROM LIB:c.o clonescreen.o TO clonescreen LIB LIB:lc.lib LIB:amiga.lib
*/

#define INTUI_V36_NAMES_ONLY

#include <exec/types.h>
#include <exec/memory.h>
#include <intuition/intuition.h>
#include <intuition/screens.h>

#include <clib/exec_protos.h>
#include <clib/dos_protos.h>
#include <clib/graphics_protos.h>
#include <clib/intuition_protos.h>

#include <string.h>

#ifdef LATTICE
int CXBRK(void)    { return(0); }  /* Disable Lattice CTRL/C handling */
int chkabort(void) { return(0); }  /* really */
#endif

VOID cloneScreen( UBYTE * );

struct Library *IntuitionBase;
struct GfxBase *GfxBase;

/*
** Open all libraries for the cloneScreen() subroutine.
*/
VOID main(int argc, char **argv)
{
UBYTE *pub_screen_name = "Workbench";

IntuitionBase = OpenLibrary("intuition.library",0);
if (IntuitionBase != NULL)
```c
    {
    /* Require version 37 of Intuition. */
    if (IntuitionBase->lib_Version >= 37)
        {
        /* Note the two methods of getting the library version
        ** that you really want.
        */
        GfxBase = (struct GfxBase *)OpenLibrary("graphics.library",37);
        if (GfxBase != NULL)
            {
            cloneScreen(pub_screen_name);

            CloseLibrary((struct Library *)GfxBase);
            }
        }
    CloseLibrary(IntuitionBase);
    }
```
}

/* Clone a public screen whose name is passed to the routine.
**    Width, Height, Depth, Pens, Font and DisplayID attributes are
** all copied from the screen.
**    Overscan is assumed to be OSCAN_TEXT, as there is no easy way to
** find the overscan type of an existing screen.
**    AutoScroll is turned on, as it does not hurt.  Screens that are
** smaller than the display clip will not scroll.
*/

VOID cloneScreen(UBYTE *pub_screen_name)
{
struct Screen *my_screen;
ULONG  screen_modeID;
UBYTE *pub_scr_font_name;
UBYTE *font_name;
ULONG  font_name_size;
struct TextAttr pub_screen_font;
struct TextFont *opened_font;

struct Screen   *pub_screen = NULL;
struct DrawInfo *screen_drawinfo = NULL;

/* name is a (UBYTE *) pointer to the name of the public screen to clone */
pub_screen = LockPubScreen(pub_screen_name);
if (pub_screen != NULL)

```c
    {
    /* Get the DrawInfo structure from the locked screen
    ** This returns pen, depth and font info.
    */
    screen_drawinfo = GetScreenDrawInfo(pub_screen);
    if (screen_drawinfo != NULL)
        {
        screen_modeID = GetVPModeID(&(pub_screen->ViewPort));
        if( screen_modeID != INVALID_ID )
            {
            /* Get a copy of the font
            ** The name of the font must be copied as the public screen may
            ** go away at any time after we unlock it.
            ** Allocate enough memory to copy the font name, create a
            ** TextAttr that matches the font, and open the font.
            */
            pub_scr_font_name = screen_drawinfo->dri_Font->tf_Message.mn_Node.ln_Name;
            font_name_size = 1 + strlen(pub_scr_font_name);
            font_name = AllocMem(font_name_size, MEMF_CLEAR);
            if (font_name != NULL)
                {
                strcpy(font_name, pub_scr_font_name);
                pub_screen_font.ta_Name  = font_name;
                pub_screen_font.ta_YSize = screen_drawinfo->dri_Font->tf_YSize;
                pub_screen_font.ta_Style = screen_drawinfo->dri_Font->tf_Style;
                pub_screen_font.ta_Flags = screen_drawinfo->dri_Font->tf_Flags;

                opened_font = OpenFont(&pub_screen_font);
                if (opened_font != NULL)
                    {
                    /* screen_modeID may now be used in a call to
                    ** OpenScreenTagList() with the tag SA_DisplayID.
                    */
                    my_screen = OpenScreenTags(NULL,
                        SA_Width,      pub_screen->Width,
                        SA_Height,     pub_screen->Height,
                        SA_Depth,      screen_drawinfo->dri_Depth,
                        SA_Overscan,   OSCAN_TEXT,
                        SA_AutoScroll, TRUE,
                        SA_Pens,       (ULONG)(screen_drawinfo->dri_Pens),
                        SA_Font,       (ULONG)&pub_screen_font,
                        SA_DisplayID,  screen_modeID,
                        SA_Title,      "Cloned Screen",
                        TAG_END);
                    if (my_screen != NULL)
                        {
                        /* Free the drawinfo and public screen as we don't
                        ** need them any more.  We now have our own screen.
                        */
                        FreeScreenDrawInfo(pub_screen,screen_drawinfo);
                        screen_drawinfo = NULL;
                        UnlockPubScreen(pub_screen_name,pub_screen);
                        pub_screen = NULL;

                        Delay(300);   /* should be rest_of_program */

                        CloseScreen(my_screen);
                        }
                    CloseFont(opened_font);
                    }
                FreeMem(font_name, font_name_size);
                }
            }
        }
    }
```
/* These are freed in the main loop if OpenScreenTagList() does
** not fail.  If something goes wrong, free them here.
*/
if (screen_drawinfo != NULL )
```c
    FreeScreenDrawInfo(pub_screen,screen_drawinfo);
```
if (pub_screen != NULL )
```c
    UnlockPubScreen(pub_screen_name,pub_screen);
```
}

---

## See Also

- [OpenScreenTagList — intuition.library](../autodocs/intuition.library.md#openscreentaglist)
