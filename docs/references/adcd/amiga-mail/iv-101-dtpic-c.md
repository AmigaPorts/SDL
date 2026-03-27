---
title: IV-101/dtpic.c
manual: amiga-mail
chapter: amiga-mail
section: iv-101-dtpic-c
functions: [GetAttr]
libraries: [intuition.library]
---

# IV-101/dtpic.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

; /* Compiled with SAS/C 6.56.  Run from CLI only.
sc DATA=NEAR NMINC STRMERGE NOSTKCHK IGNORE=73 dtpic.c
slink from lib:c.o dtpic.o TO dtpic LIBRARY lib:sc.lib lib:amiga.lib
quit ; */

#include <exec/types.h>
#include <datatypes/datatypes.h>      /* Datatypes definitions we need */
#include <datatypes/pictureclass.h>
#include <stdio.h>

#include <clib/exec_protos.h>         /* Prototypes for system functions */
#include <clib/intuition_protos.h>
#include <clib/alib_protos.h>
#include <clib/datatypes_protos.h>
#include <clib/graphics_protos.h>

#ifdef LATTICE
int CXBRK(void)    { return(0); }     /* Disable SAS/C CTRL-C handling */
int chkabort(void) { return(0); }
#endif

struct Library *IntuitionBase=NULL;   /* System library bases */
struct Library *GfxBase=NULL;
struct Library *DataTypesBase=NULL;

VOID main(int argc, char **argv)
{
APTR dtobject=NULL;                   /* Pointer to a datatypes object       */
ULONG res;                            /* Variable for function return values */
struct dtFrameBox mydtFrameBox;       /* Use this with DTM_FRAMEBOX method   */
struct FrameInfo myFrameInfo;         /* For info returned from DTM_FRAMEBOX */
struct gpLayout mygpLayout;           /* Use this with DTM_PROCLAYOUT method */

ULONG modeID = INVALID_ID;            /* Variables for storing the display */
struct Screen *myScreen=NULL;         /* environment information obtained  */
struct BitMap *bm = NULL;             /* the datatype object.              */
ULONG *cregs = NULL;
ULONG i,r,g,b,numcolors;

if (IntuitionBase=OpenLibrary("intuition.library",39L))
  {
  if (GfxBase=OpenLibrary("graphics.library",39L))
```c
    {
    if(DataTypesBase=OpenLibrary("datatypes.library",0L))
        {
        if(argc > 1 ) /* CLI only, at least one argument please.  */
            {
            /* Attempt to create a picture object in memory from the file    */
            /* name given by the user in the command line.  If we wanted to  */
            /* show the picture in a screen set up ahead of time, we could   */
            /* set PDTA_Remap to TRUE and provide a pointer to the screen    */
            /* with the PDTA_Screen tag (datatypes.library handles the rest).*/
            /* However in this case we want to first find out the attributes */
            /* of the picture object and set up a matching screen and do the */
            /* remapping later.  Therefore PDTA_Remap is set to false.       */
            /* The group ID tag ensures that we get only a picture file type.*/
            if (dtobject = NewDTObject(argv[1], PDTA_Remap,  FALSE,
                                                DTA_GroupID, GID_PICTURE,
                                                TAG_END) )
                {
                /* Here we want to find the display environment required by  */
                /* this picture.  To do that, perform the DTM_FRAMEBOX method */
                /* on the object.  The datatypes library fills in the struct */
                /* FrameBox you give it with the info on the display needed.  */
                mydtFrameBox.MethodID         = DTM_FRAMEBOX;
                mydtFrameBox.dtf_GInfo        = NULL;
                mydtFrameBox.dtf_ContentsInfo = NULL;
                mydtFrameBox.dtf_FrameInfo    = &myFrameInfo;
                mydtFrameBox.dtf_SizeFrameInfo= sizeof (struct FrameInfo);
                mydtFrameBox.dtf_FrameFlags   = 0L;

                /* The return value from DTM_FRAMEBOX is currently undefined */
                res = DoMethodA(dtobject, &mydtFrameBox);

                /* OK, now do the layout (remap) of the object on our process */
                mygpLayout.MethodID   = DTM_PROCLAYOUT;
                mygpLayout.gpl_GInfo  = NULL;
                mygpLayout.gpl_Initial= 1L;

                /* The return value of DTM_PROCLAYOUT is non-zero for success */
                if( res = DoMethodA(dtobject, &mygpLayout) )
                   {
                   /* Get the attributes of this picture object.  You could  */
                   /* use a series of GetAttr() function calls here instead.  */
                   res = GetDTAttrs(dtobject, PDTA_ModeID, &modeID,
                                              PDTA_CRegs, &cregs,
                                              PDTA_BitMap, &bm,
                                              TAG_END);

                   /* Did we get all threee attributes? */
                   if( (modeID!=INVALID_ID) && (cregs) && (bm) )
                       {
                       /* Open a screen that matches the picture object */
                       if( myScreen = OpenScreenTags( NULL,
                           SA_Width,     myFrameInfo.fri_Dimensions.Width,
                           SA_Height,    myFrameInfo.fri_Dimensions.Height,
                           SA_Depth,     myFrameInfo.fri_Dimensions.Depth,
                           SA_DisplayID, modeID,
                           SA_BitMap,    bm,
                           TAG_END) )
                           {
                           /* Now fill in the color registers for this screen */
                           numcolors = 2<<(myFrameInfo.fri_Dimensions.Depth-1);
                           for( i=0; i < numcolors; i++ )
                              {
                              r = cregs[i * 3 + 0];
                              g = cregs[i * 3 + 1];
                              b = cregs[i * 3 + 2];
                              SetRGB32(&myScreen->ViewPort, i, r, g, b);
                              }

                           printf("Ctrl-C in this window to quit\n");
                           /* Wait for the user to have a look...  */
                           Wait(SIGBREAKF_CTRL_C);

                           CloseScreen(myScreen);
                           }
                       else printf("Couldn't open required screen\n");
                       }
                   else printf("Couldn't get picture attributes\n");

                  DisposeDTObject(dtobject);
                  }
               else printf("Couldn't perform PROC_LAYOUT\n");
               }
            else printf("Couldn't create new object or not a picture file\n");
            }
        else printf("Give a file name too.\n");

        CloseLibrary(DataTypesBase);
        }
    else printf("Can't open datatypes library\n");

    CloseLibrary(GfxBase);
    }
```
  else printf("Can't open V39 graphics\n");

  CloseLibrary(IntuitionBase);
  }
else printf("Can't open V39 Intuition\n");
}

---

## See Also

- [GetAttr — intuition.library](../autodocs/intuition.library.md#getattr)
