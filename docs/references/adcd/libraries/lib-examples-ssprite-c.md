---
title: lib_examples/ssprite.c
manual: libraries
chapter: libraries
section: lib-examples-ssprite-c
functions: [WaitTOF]
libraries: [graphics.library]
---

# lib_examples/ssprite.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/* The following example demonstrates how to set up, move and free a
** Simple Sprite.  The animtools.h file included is listed at the end of
** the chapter.
**
** ssprite.c - Simple Sprite example
**
** SAS/C V5.10a
** lc -b1 -cfist -v -y ssprite.c
** blink FROM LIB:c.o ssprite.o LIB LIB:lc.lib LIB:amiga.lib TO ssprite
*/
#include <exec/types.h>
#include <graphics/gfx.h>
#include <graphics/gfxbase.h>
#include <graphics/gfxmacros.h>
#include <graphics/sprite.h>
#include <intuition/intuitionbase.h>
#include <intuition/screens.h>
#include <hardware/custom.h>
#include <hardware/dmabits.h>
#include <libraries/dos.h>

#include <clib/graphics_protos.h>
#include <clib/exec_protos.h>
#include <clib/intuition_protos.h>
#include <clib/alib_stdio_protos.h>

#include <stdlib.h>

struct GfxBase *GfxBase = NULL;
struct IntuitionBase *IntuitionBase = NULL;
extern struct Custom far custom ;

/* real boring sprite data */
UWORD chip sprite_data[ ] = {

```c
    0, 0,           /* position control           */
    0xffff, 0x0000, /* image data line 1, color 1 */
    0xffff, 0x0000, /* image data line 2, color 1 */
    0x0000, 0xffff, /* image data line 3, color 2 */
    0x0000, 0xffff, /* image data line 4, color 2 */
    0x0000, 0x0000, /* image data line 5, transparent */
    0x0000, 0xffff, /* image data line 6, color 2 */
    0x0000, 0xffff, /* image data line 7, color 2 */
    0xffff, 0xffff, /* image data line 8, color 3 */
    0xffff, 0xffff, /* image data line 9, color 3 */
    0, 0            /* reserved, must init to 0 0 */
    };
```
VOID main(int argc, char **argv)
{
struct SimpleSprite    sprite = {0};
struct ViewPort        *viewport;

WORD sprite_num;
SHORT delta_move, ktr1, ktr2, color_reg;
struct Screen *screen;
int return_code;

return_code = RETURN_OK;

if (NULL == (GfxBase = (struct GfxBase *) OpenLibrary("graphics.library",37L)))
```c
    return_code = RETURN_FAIL;
```
else
```c
    {
    if (NULL == (IntuitionBase = (struct IntuitionBase *)OpenLibrary("intuition.library",37L)))
        return_code = RETURN_FAIL;
    else
        {
        /* opened library, need a viewport to render a sprite over. */
        if (NULL == (screen = OpenScreenTagList(NULL, NULL)))
            return_code = RETURN_FAIL;
        else
            {
            viewport = &screen->ViewPort;
            if (-1 == (sprite_num = GetSprite(&sprite, 2)))
                return_code = RETURN_WARN;
            else
                {
                /* Calculate the correct base color register number, */
                /* set up the color registers.                       */
                color_reg = 16 + ((sprite_num & 0x06) << 1);
                printf("color_reg=%d\n", color_reg);
                SetRGB4(viewport, color_reg + 1, 12,  3,  8);
                SetRGB4(viewport, color_reg + 2, 13, 13, 13);
                SetRGB4(viewport, color_reg + 3,  4,  4, 15);

                sprite.x = 0;       /* initialize position and size info    */
                sprite.y = 0;       /* to match that shown in sprite_data   */
                sprite.height = 9;  /* so system knows layout of data later */

                /* install sprite data and move sprite to start position. */
                ChangeSprite(NULL, &sprite, (APTR)sprite_data);
                MoveSprite(NULL, &sprite, 30, 0);

                /* move the sprite back and forth. */
                for ( ktr1 = 0, delta_move = 1;
                      ktr1 < 6; ktr1++, delta_move = -delta_move)
                    {
                    for ( ktr2 = 0; ktr2 < 100; ktr2++)
                        {
                        MoveSprite( NULL, &sprite, (LONG)(sprite.x + delta_move),
                                    (LONG)(sprite.y + delta_move) );
                        WaitTOF(); /* one move per video frame */

                        /* Show the effect of turning off sprite DMA. */
                        if (ktr2 == 40) OFF_SPRITE ;
                        if (ktr2 == 60) ON_SPRITE ;
                        }
                    }
                /* NOTE:  if you turn off the sprite at the wrong time (when it
                ** is being displayed), the sprite will appear as a vertical bar
                ** on the screen.  To really get rid of the sprite, you must
                ** OFF_SPRITE while it is not displayed.  This is hard in a
                ** multi-tasking system (the solution is not addressed in
                ** this program).
                */
                ON_SPRITE ; /* just to be sure */
                FreeSprite((WORD)sprite_num);
                }
            (VOID) CloseScreen(screen);
            }
        CloseLibrary((struct Library *)IntuitionBase);
        }
    CloseLibrary((struct Library *)GfxBase);
    }
```
exit(return_code);
}

---

## See Also

- [WaitTOF — graphics.library](../autodocs/graphics.library.md#waittof)
