# graphics.library — Autodoc Reference

*Filtered to AmigaOS V39 and below.*

**Functions:** 166

## Function Index

- **AddAnimOb** — Add an AnimOb to the linked list of AnimObs.
- **AddBob** — Adds a Bob to current gel list.
- **AddFont** — add a font to the system list
- **AddVSprite** — Add a VSprite to the current gel list.
- **AllocBitMap** (V39) — Allocate a bitmap and attach bitplanes to it.
- **AllocBitMapTagList** — Allocate a bitmap using a tag list (V53.7)
- **AllocDBufInfo** (V39) — Allocate structure for multi-buffered animation
- **AllocRaster** — Allocate space for a bitplane.
- **AllocSpriteDataA** (V39) — allocate sprite data
- **AndRectRegion** — Perform 2d AND operation of rectangle
- **AndRegionRegion** — Perform 2d AND operation of one region
- **Animate** — Processes every AnimOb in the current animation list.
- **AreaCircle** — add a circle to areainfo list for areafill.
- **AreaDraw** — Add a point to a list of end points for areafill.
- **AreaEllipse** — add a ellipse to areainfo list for areafill.
- **AreaEnd** — Process table of vectors and ellipses
- **AreaMove** — Define a new starting point for a new
- **AskFont** — get the text attributes of the current font
- **AskSoftStyle** — Get the soft style bits of the current font.
- **AttachPalExtra** (V39) — Allocate and attach a palette sharing structure to a
- **AttemptLockLayerRom** — Attempt to Lock Layer structure
- **BestModeIDA** (V39) — calculate the best ModeID with given parameters
- **BitMapScale** (V36) — Perform raster scaling on a bit map.
- **BltBitMap** — Move a rectangular region of bits in a BitMap.
- **BltBitMapRastPort** — Blit from source bitmap to destination rastport.
- **BltClear** — 
- **BltMaskBitMapRastPort** — blit from source bitmap to destination
- **BltPattern** — Using standard drawing rules for areafill,
- **BltTemplate** — Cookie cut a shape in a rectangle to the RastPort.
- **CalcIVG** (V39) — Calculate the number of blank lines above a ViewPort
- **CBump** — increment user copper list pointer
- **CEND** — Terminate user copper list.
- **ChangeExtSpriteA** (V39) — Change the sprite image pointer. (V39)
- **ChangeSprite** — Change the sprite image pointer.
- **ChangeVPBitMap** (V39) — change display memory address for multi-buffered
- **CINIT** — Initialize user copperlist to accept intermediate
- **ClearEOL** — Clear from current position to end of line.
- **ClearRectRegion** — Perform 2d CLEAR operation of rectangle
- **ClearRegion** — Remove all rectangles from region.
- **ClearScreen** — Clear from current position to end of RastPort.
- **ClipBlit** — Calls BltBitMap() after accounting for windows
- **CloseFont** — Release a pointer to a system font.
- **CloseMonitor** (V36) — close a MonitorSpec
- **CMOVE** — append copper move instruction to user copper list.
- **CoerceMode** (V39) — calculate ViewPort mode coercion
- **CopySBitMap** — Syncronize Layer window with contents of
- **CWAIT** — Append copper wait instruction to user copper list.
- **DisownBlitter** — return blitter to free state.
- **DisposeRegion** — Return all space for this region to free
- **DoCollision** — Test every gel in gel list for collisions.
- **Draw** — Draw a line between the current pen position
- **DrawEllipse** — Draw an ellipse centered at cx,cy with vertical
- **DrawGList** — Process the gel list, queueing VSprites, drawing Bobs.
- **EraseRect** (V36) — Fill a defined rectangular area using the current
- **ExtendFont** (V36) — ensure tf_Extension has been built for a font
- **FindColor** (V39) — Find the closest matching color in a colormap.
- **FindDisplayInfo** (V36) — search for a record identified by
- **Flood** — Flood rastport like areafill.
- **FontExtent** (V36) — get the font attributes of the current font
- **FreeBitMap** (V39) — free a bitmap created by AllocBitMap
- **FreeColorMap** — Free the ColorMap structure and return memory
- **FreeCopList** — deallocate intermediate copper list
- **FreeCprList** — deallocate hardware copper list
- **FreeDBufInfo** (V39) — free information for multi-buffered animation
- **FreeGBuffers** — Deallocate memory obtained by GetGBufers.
- **FreeRaster** — Release an allocated area
- **FreeSprite** — Return sprite for use by others and virtual
- **FreeSpriteData** (V39) — free sprite data
- **FreeVPortCopLists** — deallocate all intermediate copper lists and
- **GetAPen** (V39) — Get the A Pen value for a RastPort (V39).
- **GetBitMapAttr** (V39) — Returns information about a bitmap
- **GetBPen** (V39) — Get the B Pen value for a RastPort (V39).
- **GetColorMap** — allocate and initialize Colormap
- **GetDisplayInfoData** (V36) — Query DisplayInfo Record parameters
- **GetDrMd** (V39) — Get the draw mode value for a RastPort (V39).
- **GetExtSpriteA** (V39) — Attempt to get a sprite for the extended sprite
- **GetGBuffers** — Attempt to allocate ALL buffers of an entire AnimOb.
- **GetOutlinePen** (V39) — Get the Outline-Pen value for a RastPort (V39).
- **GetRGB32** (V39) — Get a series of color registers for this Viewport.
- **GetRGB4** — Inquire value of entry in ColorMap.
- **GetRPAttrsA** — examine rastport settings via a tag list
- **GetSprite** — Attempt to get a sprite for the simple sprite manager.
- **GetVPModeID** (V36) — get the 32 bit DisplayID from a ViewPort.
- **GfxAssociate** (V36) — associate a graphics extended node
- **GfxFree** (V36) — free a graphics extended data structure
- **GfxLookUp** (V36) — find a graphics extended node associated with a
- **GfxNew** (V36) — allocate a graphics extended data structure
- **InitArea** — Initialize vector collection matrix
- **InitBitMap** — Initialize bit map structure with input values.
- **InitGels** — initialize a gel list; must be called before using gels.
- **InitGMasks** — Initialize all of the masks of an AnimOb.
- **InitMasks** — Initialize the BorderLine and CollMask masks
- **InitRastPort** — Initialize raster port structure
- **InitTmpRas** — Initialize area of local memory for usage by
- **InitView** — 
- **InitVPort** — 
- **LoadRGB32** (V39) — Set a series of color registers for this Viewport.
- **LoadRGB4** — Load RGB color values from table.
- **LoadView** — Use a (possibly freshly created) coprocessor instruction
- **LockLayerRom** — Lock Layer structure by ROM(gfx lib) code.
- **MakeVPort** — generate display copper list for a viewport.
- **ModeNotAvailable** (V36) — check if a DisplayID is not available.
- **Move** — Move graphics pen position.
- **MoveSprite** — Move sprite to a point relative to top of viewport.
- **MrgCop** — Merge together coprocessor instructions.
- **NewRegion** — Get an empty region.
- **NextDisplayInfo** (V36) — iterate current displayinfo identifiers
- **ObtainBestPenA** (V39) — - Search for the closest color match, or allocate a
- **ObtainPen** (V39) — Obtain a free palette entry
- **OpenFont** — Get a pointer to a system font.
- **OpenMonitor** (V36) — open a named MonitorSpec
- **OrRectRegion** — Perform 2d OR operation of rectangle
- **OrRegionRegion** — Perform 2d OR operation of one region
- **OwnBlitter** — get the blitter for private usage
- **PolyDraw** — Draw lines from table of (x,y) values.
- **QBlit** — Queue up a request for blitter usage
- **QBSBlit** — Synchronize the blitter request with the video beam.
- **ReadPixel** — Read the pen number value of the pixel at a specified
- **ReadPixelArray8** (V36) — Read the pen number value of a rectangular array
- **ReadPixelLine8** (V36) — Read the pen number value of a horizontal line of
- **RectFill** — Fill a rectangular region in a RastPort.
- **ReleasePen** (V39) — Release an allocated palette entry
- **RemBob** — Macro to remove a Bob from the gel list.
- **RemFont** — Remove a font from the system list.
- **RemIBob** — Immediately remove a Bob from the gel list
- **RemVSprite** — Remove a VSprite from the current gel list.
- **ScalerDiv** (V36) — Get the scaling result that BitMapScale would.
- **ScrollRaster** — Push bits in rectangle in raster around by
- **ScrollRasterBF** (V39) — Push bits in rectangle in raster around by dx, dy
- **ScrollVPort** — Reinterpret RasInfo information in ViewPort to reflect
- **SetABPenDrMd** (V39) — Set pen colors and draw mode for a RastPort.
- **SetAPen** — Set the primary pen for a RastPort.
- **SetBPen** — Set secondary pen for a RastPort
- **SetChipRev** (V39) — turns on the features of a Chip Set
- **SetCollision** — Set a pointer to a user collision routine.
- **SetDrMd** — Set drawing mode for a RastPort
- **SetFont** — Set the text font and attributes in a RastPort.
- **SetMaxPen** (V39) — set maximum pen value for a rastport (V39).
- **SetOPen** — Change the Area OutLine pen and turn on Outline
- **SetOutlinePen** (V39) — Set the Outline Pen value for a RastPort (V39).
- **SetRast** — 
- **SetRGB32** (V39) — Set one color register for this Viewport.
- **SetRGB32CM** (V39) — Set one color register for this ColorMap.
- **SetRGB4** — Set one color register for this viewport.
- **SetRGB4CM** — Set one color register for this ColorMap.
- **SetRPAttrsA** — modify rastport settings via a tag list
- **SetSoftStyle** — Set the soft style of the current font.
- **SetWriteMask** (V39) — Set the pixel write mask value for a RastPort (V39).
- **SortGList** — Sort the current gel list, ordering its y,x coordinates.
- **StripFont** (V36) — remove the tf_Extension from a font
- **SyncSBitMap** — Syncronize Super BitMap with whatever is
- **Text** — Write text characters (no formatting).
- **TextExtent** (V36) — Determine raster extent of text data.
- **TextFit** (V36) — 
- **TextLength** — Determine raster length of text data.
- **UnlockLayerRom** — Unlock Layer structure by ROM(gfx lib) code.
- **VBeamPos** — Get vertical beam position at this instant.
- **VideoControl** (V36) — Modify the operation of a ViewPort's ColorMap
- **WaitBlit** — Wait for the blitter to be finished before proceeding
- **WaitBOVP** — Wait till vertical beam reached bottom of
- **WaitTOF** — Wait for the top of the next video frame.
- **WritePixel** — Change the pen num of one specific pixel in a
- **WritePixelArray8** (V36) — write the pen number value of a rectangular array
- **WritePixelLine8** (V36) — write the pen number value of a horizontal line
- **XorRectRegion** — Perform 2d XOR operation of rectangle
- **XorRegionRegion** — Perform 2d XOR operation of one region

## Functions

### graphics.library/AddAnimOb

**Add an AnimOb to the linked list of AnimObs.**

**Synopsis:**
```c
AddAnimOb(anOb, anKey, rp)

VOID AddAnimOb(struct AnimOb *,struct AnimOb **, struct RastPort *);
```

**Description:**
Links this AnimOb into the current list pointed to by animKey.
Initializes all the Timers of the AnimOb's components.
Calls AddBob with each component's Bob.
rp->GelsInfo must point to an initialized GelsInfo structure.

**Inputs:**
anOb  = pointer to the AnimOb structure to be added to the list
anKey = address of a pointer to the first AnimOb in the list
        (anKey = NULL if there are no AnimObs in the list so far)
rp    = pointer to a valid RastPort

**Result:**


**Bugs:**


**See also:** Animate() graphics/rastport.h graphics/gels.h

---

### graphics.library/AddBob

**Adds a Bob to current gel list.**

**Synopsis:**
```c
AddBob(Bob, rp)

VOID AddBob(struct Bob *, struct RastPort *);
```

**Description:**
Sets up the system Bob flags, then links this gel into the list
via AddVSprite.

**Inputs:**
Bob = pointer to the Bob structure to be added to the gel list
rp  = pointer to a RastPort structure

**Result:**


**Bugs:**


**See also:** InitGels()  AddVSprite()  graphics/gels.h  graphics/rastport.h

---

### graphics.library/AddFont

**add a font to the system list**

**Synopsis:**
```c
AddFont(textFont)

VOID AddFont(struct TextFont *);
```

**Description:**
This function adds the text font to the system, making it
available for use by any application.  The font added must be
in public memory, and remain until successfully removed.

**Inputs:**
textFont - a TextFont structure in public ram.

**Result:**


**Notes:**
This function will set the tf_Accessors to 0.

**Bugs:**


**See also:** SetFont() RemFont() graphics/text.h

---

### graphics.library/AddVSprite

**Add a VSprite to the current gel list.**

**Synopsis:**
```c
AddVSprite(vs, rp)

VOID AddVSprite(struct VSprite *, struct RastPort *);
```

**Description:**
Sets up the system VSprite flags
Links this VSprite into the current gel list using its Y,X

**Inputs:**
vs = pointer to the VSprite structure to be added to the gel list
rp = pointer to a RastPort structure

**Result:**


**Bugs:**


**See also:** InitGels()  graphics/rastport.h  graphics/gels.h

---

### graphics.library/AllocBitMap (V39)

**Allocate a bitmap and attach bitplanes to it.**

**Synopsis:**
```c
struct BitMap *bm = AllocBitMap(uint32 sizex, uint32 sizey,
    uint32 depth, uint32 flags, struct BitMap *friendBitmap);
```

**Description:**
Allocates and initializes a BitMap structure plus underlying
storage in whatever format is required.

**Inputs:**
sizex - the width (in pixels) desired for the bitmap data.

sizey - the height (in pixels) desired.

depth - the number of bitplanes deep for the allocation.
        Pixels with AT LEAST this many bits will be allocated.

flags - BMF_CLEAR to specify that the allocated raster should be
            filled with color 0.

            Planar YUV formats (YUV410P and YUV420P) are cleared by
            filling the Y plane with 0 and the U and V planes
            with 128.

        BMF_DISPLAYABLE to specify that this bitmap data should
            be allocated in such a manner that it can be displayed.
            Displayable data has more severe alignment restrictions
            than non-displayable data in some systems.

        BMF_INTERLEAVED tells graphics that you would like your
            bitmap to be allocated with one large chunk of display
            memory for all bitplanes. This minimizes color flashing
            on deep displays. If there is not enough contiguous RAM
            for an interleaved bitmap, graphics.library will fall
            back to a non-interleaved one.

        BMF_MINPLANES causes graphics to only allocate enough space
            in the bitmap structure for "depth" plane pointers.
            This is for system use and should not be used by
            applications use as it is inefficient and may waste
            memory.

        BMF_HIJACKED
        BMF_RTGTAGS
        BMF_RTGCHECK
        BMF_FRIENDISTAG
        BMF_INVALID are used together (BMF_CHECKMASK) to indicate
            that the friendBitMap pointer is actually a
            struct TagList array. See the AllocBitMapTagList()
            autodoc for full descriptions of all the available
            tags. (V45)

        BMF_LOCKED locks the bitmap in video memory and it
            cannot be moved. This is for system use only. (V51)

friendBitmap - pointer to another bitmap or NULL. If this pointer
        is passed, then the bitmap data will be allocated in
        the most efficient form for blitting to friendBitmap.

        If flags is set to BMF_CHECKMASK then this pointer is
        a struct TagItem array pointer. See the
        AllocBitMapTagList() autodoc for tag descriptions.

**Result:**
bm - Pointer to newly allocated bitmap or NULL for failure.

**Notes:**
When allocating using a friend bitmap, it is not safe to assume
anything about the structure of the bitmap data if that friend
BitMap might not be a standard Amiga bitmap. For instance, if
the Workbench is running on a non-Amiga display device like a
graphics card then its Screen->RastPort->BitMap won't be in
standard Amiga format.

Good arguments to pass for the friend bitmap are your window's
RPort->BitMap and your screen's RastPort->BitMap.

Do NOT pass &(screenptr->BitMap)!

BitMaps not allocated with BMF_DISPLAYABLE may not be used as
Intuition Custom BitMaps or as RasInfo->BitMaps. They may be blitted
to a BMF_DISPLAYABLE BitMap, using one of the BltBitMap() family of
functions.

**See also:** AllocBitMapTagList(), FreeBitMap()

---

### graphics.library/AllocBitMapTagList

**Allocate a bitmap using a tag list (V53.7)**

**Synopsis:**
```c
struct BitMap *bm = AllocBitMapTagList(uint32 sizex, uint32 sizey,
    uint32 depth, CONST struct TagItem * tags);

struct BitMap *bm = AllocBitMapTags(uint32 sizex, uint32 sizey,
    uint32 depth, ...);
```

**Description:**
Allocates and initializes a BitMap structure plus underlying
storage in whatever format is required.

**Inputs:**
BMATags_Friend (struct BitMap *) -- Specifies a friend bitmap.
    Defaults to no friend bitmap.

BMATags_PixelFormat (uint32) -- Color format of the bitmap data.
    Choose one of the enum enPixelFormat values in <graphics/gfx.h>.
    It is usually best to use a friend bitmap and let the system
    determine the optimal format to use.

BMATags_Depth (uint32) -- Specifies the bitmap depth and overrides
    the depth parameter. Defaults to the depth parameter.

BMATags_Clear (BOOL) -- Clear the bitmap by filling it will color
    zero. Equivalent to the BMF_CLEAR flag. Defaults to no clearing.

    Planar YUV formats (YUV410P and YUV420P) are cleared by
    filling the Y plane with 0 and the U and V planes with 128.

BMATags_Displayable (BOOL) -- Specifies whether this bitmap will
    be displayed or not. Equivalent to the BMF_DISPLAYABLE flag.
    Defaults to FALSE.

BMATags_NoMemory (BOOL) -- Just allocate the bitmap structure
    and do not allocate any storage. Defaults to FALSE.

BMATags_NoSprite (BOOL) -- Do not allow generation of sprites.
    Default is FALSE.

BMATags_ModeWidth (uint32) -- Width of the display mode
    (BMATags_DisplayID) in pixels. Default is the sizex parameter.

BMATags_ModeHeight (uint32) -- Height of the display mode
    (BMATags_DisplayID) in pixels. Default is the sizey parameter.

BMATags_Alignment (uint32) -- Specifies additional alignment
    restriction (power of two) for the bitmap rows. If this
    tag is set then bitplane rows are aligned to this boundary.
    Default to the native alignment restriction for the
    video memory in use.

BMATags_ConstantBytesPerRow (BOOL) -- Set to TRUE along with the
    BMATags_Alignment tag to enforce alignment for displayable
    screens. Defaults to FALSE.

BMATags_UserPrivate (BOOL) -- Set to TRUE if this is a user
    private bitmap which will never be in video memory.
    LockBitMapTagList() should not be used because this
    bitmap never moves in and out of video memory.
    Defaults to FALSE.

BMATags_DisplayID (uint32) -- A valid display ID from the
    monitor database which will be used to extract the board,
    width, height and format for the bitmap. Defaults to
    using sizex, sizey and friend bitmap (if available).

BMATags_BitmapInvisible (BOOL) -- If set to TRUE then the bitmap
    is not allocated on the graphics board directly. The bitmap
    may remain in an off-hardware location if the screen is
    invisible. This is intentially identical to the SA_Behind tag.
    Defaults to FALSE.

BMATags_BitmapColors (struct ColorSpec *) -- Specifies an array
    of struct ColorSpec entries terminated by ColorIndex = -1.
    Specifies the initial screen palette colors. This is
    intentially identical to the SA_Colors tag.

BMATags_BitmapColors32 (uint32 *) -- Specifies a set of
    initial palette colors. ti_Data is a pointer to a table to
    be passed to the LoadRGB32() function. Any color set here
    has precedence over the same register set by
    BMATags_BitmapColors. This is intentionally identical to
    the SA_Colors32 tag.

**Result:**
bm - Pointer to newly allocated bitmap or NULL for failure.

**See also:** AllocBitMap(), FreeBitMap(), graphics/gfx.h

---

### graphics.library/AllocDBufInfo (V39)

**Allocate structure for multi-buffered animation**

**Synopsis:**
```c
AllocDBufInfo(vp)

   struct DBufInfo * AllocDBufInfo(struct ViewPort *)
```

**Description:**
Allocates a structure which is used by the ChangeVPBitMap()
routine.

**Inputs:**
vp  =  A pointer to a ViewPort structure.

**Notes:**
Returns 0 if there is no memory available or if the display mode
of the viewport does not support double-buffering.

The only fields of the DBufInfo structure which can be used by
application programs are the dbi_SafeMessage, dbi_DispMessage,
dbi_UserData1 and dbi_UserData2 fields.

dbi_SafeMessage and dbi_DispMessage are standard exec message
structures which may be used for synchronizing your animation
with the screen update.

dbi_SafeMessage is a message which is replied to when it is safe
to write to the old BitMap (the one which was installed when you
called ChangeVPBitMap).

dbi_DispMessage is replied to when it is safe to call
ChangeVPBitMap again and be certain that the new frame has been
seen at least once.

The dbi_UserData1 and dbi_UserData2 fields, which are stored after
each message, are for your application to stuff any data into that
it may need to examine when looking at the reply coming into the
ReplyPort for either of the embedded Message structures.

DBufInfo structures MUST be allocated with this function.
The size of the structure will grow in future releases.

The following fragment shows proper double buffering
synchronization:

int SafeToChange=TRUE, SafeToWrite=TRUE, CurBuffer=1;
struct MsgPort *ports[2]; // reply ports for DispMessage
                      // and SafeMessage
struct BitMap *BmPtrs[2];
struct DBufInfo *myDBI;

... allocate bitmap pointers, DBufInfo, set up viewports, etc.

myDBI->dbi_SafeMessage.mn_ReplyPort=ports[0];
myDBI->dbi_DispMessage.mn_ReplyPort=ports[1];
while (! done)
{
    if (! SafeToWrite)
    while(! GetMsg(ports[0])) Wait(1l<<(ports[0]->mp_SigBit));
    SafeToWrite=TRUE;

    ... render to bitmap # CurBuffer.

    if (! SafeToChange)
    while(! GetMsg(ports[1])) Wait(1l<<(ports[1]->mp_SigBit));
    SafeToChange=TRUE;
    WaitBlit();         // be sure rendering has finished
    ChangeVPBitMap(vp,BmPtrs[CurBuffer],myDBI);
    SafeToChange=FALSE;
    SafeToWrite=FALSE;
    CurBuffer ^=1;  // toggle current buffer
}
if (! SafeToChange) // cleanup pending messages
while(! GetMsg(ports[1])) Wait(1l<<(ports[1]->mp_SigBit));
if (! SafeToWrite)  // cleanup
while(! GetMsg(ports[0])) Wait(1l<<(ports[0]->mp_SigBit));

**Bugs:**


**See also:** FreeDBufInfo() ChangeVPBitMap()

---

### graphics.library/AllocRaster

**Allocate space for a bitplane.**

**Synopsis:**
```c
PLANEPTR planeptr = AllocRaster(uint16 width, uint16 height);
```

**Description:**
This function calls the memory allocation routines
to allocate memory space for a bitplane "width" bits
wide and "height" bits high.

**Inputs:**
width   - number of columns in bitplane
height  - number of rows in bitplane

**Result:**
planeptr - pointer to first word in bitplane, or NULL if
it was not possible to allocate the desired
amount of memory.

**Notes:**
In order to assure proper alignment of display memory, the
AllocBitMap() function should be used instead of AllocRaster
when you wish to allocate display memory (rasters which are
attached to a ViewPort or Screen).

**Bugs:**


**See also:** FreeRaster() graphics/gfx.h

---

### graphics.library/AllocSpriteDataA (V39)

**allocate sprite data
             and convert from a bitmap.AllocSpriteData -- varargs stub for AllocSpriteData().**

**Synopsis:**
```c
SpritePtr | 0 = AllocSpriteDataA(bitmap, taglist)

struct ExtSprite *AllocSpriteDataA( CONST struct BitMap *,
                             CONST struct TagItem * );

extsprite = AllocSpriteData(bitmap, tag1, ...);
```

**Description:**
Allocate memory to hold a sprite image, and convert the passed-in
bitmap data to the appropriate format. The tags allow specification
of width, scaling, and other options.

**Inputs:**
bitmap - ptr to a bitmap. This bitmap provides the source data
  for the sprite image.

tags -	SPRITEA_Width specifies how many pixels wide you desire
	the sprite to be. Specifying a width wider than the hardware
	can handle will cause the function to return failure. If the
	bitmap passed in is narrower than the width asked for, then
	it will be padded on the right with transparent pixels.
	Defaults to 16.

	SPRITEA_XReplication controls the horizontal pixel
	replication factor
	used when converting the bitmap data. Valid values are:
		0 - perform a 1 to 1 conversion
		1 - each pixel from the source is replicated twice
		    in the output.
		2 - each pixel is replicated 4 times.
	       -1 - skip every other pixel in the source bitmap
	       -2 - only include every fourth pixel from the source.

	This tag is useful for converting data from one resolution
	to another. For instance, hi-res bitmap data can be correctly
	converted for a lo-res sprite by using an
	x replication factor of -1. Defaults to 0.

	SPRITEA_YReplication controls the vertical pixel replication
	factor in the same manner as SPRITEA_XReplication controls
	the horizontal.

	SPRITEA_OutputHeight specifies how tall the resulting sprite
	should be. Defaults to the bitmap height. The bitmap MUST be
	at least as tall as the output height.

	SPRITEA_Attached tells the function that you wish to convert
	the data for the second sprite in an attached sprite pair.
	This will cause AllocSpriteData() to take its data from the
	3rd and 4th bitplanes of the passed in bitmap.


Bitplane data is not required to be in chip ram for this function.

**Result:**
SpritePtr = a pointer to a ExtSprite structure, or 0 if there is
a failure. You should pass this pointer to FreeSpriteData() when
finished with the sprite.

**Bugs:**
Under V39, the appropriate attach bits would not be set in the sprite
data.
The work-around is to set the bits manually. Bit 7 of the second
word should be set. On a 32 bit sprite, bit 7 of the 3rd word should
also be set. For a 64 bit sprite, bit 7 of the 5th word should also
be set. This should NOT be done under V40, as the bug is fixed.

**See also:** FreeSpriteData() FreeSprite() ChangeSprite() MoveSprite()
GetExtSpriteA() AllocBitMap() graphics/sprite.h

---

### graphics.library/AndRectRegion

**Perform 2d AND operation of rectangle
                 with region, leaving result in region.**

**Synopsis:**
```c
AndRectRegion(region, rectangle)

VOID AndRectRegion( struct Region *, CONST struct Rectangle * );
```

**Description:**
Clip away any portion of the region that exists outside
of the rectangle. Leave the result in region.

**Inputs:**
region - pointer to Region structure
rectangle - pointer to Rectangle structure

**Notes:**
Unlike the other rect-region primitives, AndRectRegion() cannot
fail.

**Bugs:**


**See also:** AndRegionRegion() OrRectRegion() graphics/regions.h

---

### graphics.library/AndRegionRegion

**Perform 2d AND operation of one region
                with second region, leaving result in second region.**

**Synopsis:**
```c
status = AndRegionRegion(region1, region2)

BOOL AndregionRegion(CONST struct Region *, struct Region * );
```

**Description:**
Remove any portion of region2 that is not in region1.

**Inputs:**
region1 - pointer to Region structure
region2 - pointer to Region structure to use and for result

**Result:**
status - return TRUE if successful operation
         return FALSE if ran out of memory

**Bugs:**


**See also:** OrRegionRegion() AndRectRegion() graphics/regions.h

---

### graphics.library/Animate

**Processes every AnimOb in the current animation list.**

**Synopsis:**
```c
Animate(anKey, rp)

VOID Animate(struct AnimOb **, struct RastPort *);
```

**Description:**
For every AnimOb in the list
    - update its location and velocities
    - call the AnimOb's special routine if one is supplied
    - for each component of the AnimOb
        - if this sequence times out, switch to the new one
        - call this component's special routine if one is supplied
        - set the sequence's VSprite's y,x coordinates based
          on whatever these routines cause

**Inputs:**
ankey = address of the variable that points to the head AnimOb
rp    = pointer to the RastPort structure

**Result:**


**Bugs:**


**See also:** AddAnimOb() graphics/gels.h graphics/rastport.h

---

### graphics.library/AreaCircle

**add a circle to areainfo list for areafill.**

**Synopsis:**
```c
error = AreaCircle( rp,  cx,  cy, radius)

LONG AreaCircle(struct RastPort *, WORD, WORD, UWORD);
```

**Description:**
Add circle to the vector buffer. It will be drawn to the rastport
when AreaEnd is executed.

**Inputs:**
rp   - pointer to a RastPort structure

cx, cy   - the coordinates of the center of the desired circle.

radius   - is the radius of the circle to draw around the
           centerpoint.

**Result:**
0 if no error
-1 if no space left in vector list

**Notes:**
This function is actually a macro which calls
AreaEllipse(rp,cx,cy,radius,radius).

**See also:** AreaMove() AreaDraw() AreaCircle() InitArea() AreaEnd()
graphics/rastport.h graphics/gfxmacros.h

---

### graphics.library/AreaDraw

**Add a point to a list of end points for areafill.**

**Synopsis:**
```c
error = AreaDraw( rp,  x,     y)

LONG AreaDraw( struct RastPort *, WORD, WORD);
```

**Description:**
Add point to the vector buffer.

**Inputs:**
rp  - points to a RastPort structure.
x,y - are coordinates of a point in the raster.

**Result:**
error   - zero for success, else -1 if no there was no space
          left in the vector list.

**Bugs:**


**See also:** AreaMove() InitArea() AreaEnd() graphics/rastport.h

---

### graphics.library/AreaEllipse

**add a ellipse to areainfo list for areafill.**

**Synopsis:**
```c
error = AreaEllipse( rp, cx,   cy,   a,    b    )

LONG AreaEllipse( struct RastPort *, WORD, WORD, WORD, WORD)
```

**Description:**
Add an ellipse to the vector buffer. It will be draw when AreaEnd()
is called.

**Inputs:**
rp - pointer to a RastPort structure
cx - x coordinate of the centerpoint relative to the rastport.
cy - y coordinate of the centerpoint relative to the rastport.
a  - the horizontal radius of the ellipse (note: a must be > 0)
b  - the vertical radius of the ellipse (note: b must be > 0)

**Result:**
error - zero for success, or -1 if there is no space left in the
        vector list

**See also:** AreaMove() AreaDraw() AreaCircle() InitArea() AreaEnd()
graphics/rastport.h

---

### graphics.library/AreaEnd

**Process table of vectors and ellipses
           and produce areafill.**

**Synopsis:**
```c
error = AreaEnd(rp)

LONG AreaEnd( struct RastPort * );
```

**Description:**
Trigger the filling operation.
Process the vector buffer and generate required
fill into the raster planes. After the fill is complete, reinitialize
for the next AreaMove or AreaEllipse. Use the raster set up by
InitTmpRas when generating an areafill mask.

**Inputs:**
rp - pointer to a RastPort structure which specifies where the filled
     regions will be rendered to.

**Result:**
error - zero for success, or -1 if an error occurred anywhere.

**Bugs:**


**See also:** InitArea() AreaMove() AreaDraw() AreaEllipse() InitTmpRas()
graphics/rastport.h

---

### graphics.library/AreaMove

**Define a new starting point for a new
            shape in the vector list.**

**Synopsis:**
```c
error =  AreaMove( rp,   x,     y)

LONG AreaMove( struct RastPort *, WORD, WORD );
```

**Description:**
Close  the last polygon and start another polygon
at  (x,y). Add the necessary  points  to  vector
buffer. Closing a polygon may result in the generation
of another AreaDraw() to close previous polygon.
Remember to have an initialized AreaInfo structure attached
to the RastPort.

**Inputs:**
rp  - points to a RastPort structure
x,y - positions in the raster

**Result:**
error - zero for success, or -1 if there is no space left in the
vector list

**Bugs:**


**See also:** InitArea() AreaDraw() AreaEllipse() AreaEnd() graphics/rastport.h

---

### graphics.library/AskFont

**get the text attributes of the current font**

**Synopsis:**
```c
AskFont(rp, textAttr)

VOID AskFont(struct RastPort *, struct TextAttr *);
```

**Description:**
This function fills the text attributes structure with the
attributes of the current font in the RastPort.

**Inputs:**
rp       - the RastPort from which the text attributes are
           extracted
textAttr - the TextAttr structure to be filled.  Note that
           there is no support for a struct TTextAttr.

**Result:**
The textAttr structure is filled with the RastPort's text
attributes.

**Bugs:**


**See also:** diskfont.library/ObtainTTextAttr(), graphics/text.h

---

### graphics.library/AskSoftStyle

**Get the soft style bits of the current font.**

**Synopsis:**
```c
enable = AskSoftStyle(rp)

ULONG AskSoftStyle(struct RastPort *);
```

**Description:**
This function returns those style bits of the current font
that are not intrinsic in the font itself, but
algorithmically generated.  These are the bits that are
valid to set in the enable mask for SetSoftStyle().

**Inputs:**
rp - the RastPort from which the font and style are extracted.

**Result:**
enable - those bits in the style algorithmically generated.
         Style bits that are not defined are also set.

**Bugs:**


**See also:** SetSoftStyle() graphics/text.h

---

### graphics.library/AttachPalExtra (V39)

**Allocate and attach a palette sharing structure to a
              colormap.**

**Synopsis:**
```c
status=AttachPalExtra( cm, vp)

LONG AttachPalExtra( Struct ColorMap *, struct ViewPort *);
```

**Description:**
Allocates and attaches a PalExtra structure to a ColorMap.
This is necessary for color palette sharing to work. The
PalExtra structure will be freed by FreeColorMap().
The set of available colors will be determined by the mode
and depth of the viewport.

**Inputs:**
cm  =  A pointer to a color map created by GetColorMap().

vp   = A pointer to the viewport structure associated with
       the ColorMap.

**Result:**
status - 0 if sucessful, else an error number. The only currently
         defined error number is out of memory (1).

**Notes:**
This function is for use with custom ViewPorts and custom ColorMaps,
as Intuition attaches a PalExtra to all of its Screens.
If there is already a PalExtra associated with the ColorMap, then
this function will do nothing.

**Bugs:**


**See also:** GetColorMap() FreeColorMap() ObtainPen() ObtainBestPenA()

---

### graphics.library/AttemptLockLayerRom

**Attempt to Lock Layer structure
                 by ROM(gfx lib) code**

**Synopsis:**
```c
gotit = AttemptLockLayerRom( layer )

BOOL AttempLockLayerRom( struct Layer * );
```

**Description:**
Query the current state of the lock on this Layer. If it is
already locked then return FALSE, could not lock. If the
Layer was not locked then lock it and return TRUE.
This call does not destroy any registers.
This call nests so that callers in this chain will not lock
themselves out.

**Inputs:**
layer - pointer to Layer structure

**Result:**
gotit - TRUE or FALSE depending on whether the Layer was
    successfully locked by the caller.

**See also:** LockLayerRom() UnlockLayerRom()

---

### graphics.library/BestModeIDA (V39)

**calculate the best ModeID with given parameters**

**Synopsis:**
```c
uint32 ID = BestModeIDA(CONST struct TagItem *TagItems);

uint32 ID = BestModeID(Tag Tag1, ...);
```

**Description:**
To determine the best ModeID to fit the parameters set in the
TagList.

**Inputs:**
BIDTAG_DIPFMustHave (uint32) - Mask of DIPF_ flags
(from DisplayInfo->PropertyFlags) that the returned ModeID
must have.
Default - NULL

BIDTAG_DIPFMustNotHave (uint32) - Mask of DIPF_ flags that the
returned ModeID must not have.
Default - SPECIAL_FLAGS

BIDTAG_ViewPort (struct ViewPort *) - ViewPort for which a best-fit
ModeID is sought.
Default - NULL

BIDTAG_NominalWidth (uint16)
BIDTAG_NominalHeight (uint16) - Together make the aspect ratio.
These values override the vp->DWidth and vp->DHeight values
in the given ViewPort.
Default - SourceID NominalDimensionInfo if BIDTAG_SourceID is
passed, or vp->DWidth and vp->DHeight if BIDTAG_ViewPort is
passed, or 640 x 200.

BIDTAG_DesiredWidth (uint16)
BIDTAG_DesiredHeight (uint16) - Used to distinguish between two
mode IDs with identical aspect ratios.
Default - same values as NominalWidth and NominalHeight.

BIDTAG_MinDepth (uint8) - Minimum depth the returned ModeID must support.
Default is vp->RasInfo->BitMap->Depth if BIDTAG_ViewPort is
passed else 1.

BIDTAG_MaxDepth (uint8) - Maximum depth the ModeID must support.
The maximum depth is 24. Default is 24. (V54)

BIDTAG_MonitorID (uint32) - Returned ModeID must use this monitor.
Default - will not restrict the search to any particular
monitor.

BIDTAG_SourceID (uint32) - Use this ModeID instead of a ViewPort.
If specified, the DIPFMustHave mask is made up of the
((DisplayInfo->PropertyFlags of this ID & SPECIAL_FLAGS) |
 DIPFMustHave flags).
Default - VPModeID(vp) if BIDTAG_ViewPort was passed, else the
DIPFMustHave and DIPFMustNotHave masks are left unchanged.

BIDTAG_RedBits (uint8)
BIDTAG_BlueBits (uint8)
BIDTAG_Greenits (uint8) - Minimum bits per gun the resultant
ModeID must support.
Default - 4 bits per gun.

**Result:**
ID - ID of the best mode to use or INVALID_ID if a match could
     not be found.

**Example:**
```c
IFF display program with a HAM image, to be displayed in the same
monitor type as the Workbench ViewPort.

uint32 monitorid = IGraphics->GetVPModeID(WbVP) & MONITOR_ID_MASK;
uint32 ID = IGraphics->BestModeID(
       BIDTAG_NominalWidth, IFFImage->Width,
       BIDTAG_NominalHeight, IFFImage->Height,
       BIDTAG_MinDepth, IFFImage->Depth,
       BIDTAG_DIPFMustHave, DIPF_IS_HAM,
       BIDTAG_MonitorID, monitorid,
       TAG_END);

To make an interlace version of a ViewPort:

uint32 ID = IGraphics->BestModeID(
       BIDTAG_ViewPort, ThisViewPort,
       BIDTAG_MustHave, DIFP_IS_LACE,
       TAG_END);
```

**Notes:**
This function takes into account the Compatability of the Monitor
being matched to and the source ViewPort or ModeID.
Incompatibilitys will cause a result of INVALID_ID.

BIDTAG_NominalWidth, BIDTAG_NominalHeight,
BIDTAG_DesiredWidth and BIDTAG_DesiredHeight must all be non-0.

The comparisons are made against the DimensionInfo->Nominal values
(i.e. this will not return a best fit against overscan dimensions).

The minimum and maximum depth values are not the same as the
bits per pixel or bytes per pixel. See the GetBitMapAttr()
autodoc for more information.

**See also:** <graphics/modeid.h> <graphics/displayinfo.h>

---

### graphics.library/BitMapScale (V36)

**Perform raster scaling on a bit map.**

**Synopsis:**
```c
void BitMapScale(struct BitScaleArgs *bitScaleArgs);
```

**Description:**
Scale a source bit map to a non-overlapping destination
bit map.

**Inputs:**
bitScaleArgs - structure of parameters describing scale:
    bsa_SrcX, bsa_SrcY - origin of the source bits.
    bsa_SrcWidth, bsa_SrcHeight - number of bits to scale from in x
    and y.
    bsa_DestX, bsa_DestY - origin of the destination.
    bsa_DestWidth, bsa_DestHeight - resulting number of bits in x
    and y.  NOTE: these values are set by this function.
    bsa_XSrcFactor:bsa_XDestFactor - equivalent to the ratio
 srcWidth:destWidth, but not necessarily the same
 numbers.  Each must be in the range 1..16383.
    bsa_YSrcFactor:bsa_YDestFactor - equivalent to the ratio
 srcHeight:destHeight, but not necessarily the same
 numbers.  Each must be in the range 1..16383.
    bsa_SrcBitMap - source of the bits to scale.
    bsa_DestBitMap - destination for the bits to scale.  This had
 better be big enough!
    bsa_Flags - future scaling options.  Set it to zero!
    bsa_XDDA, bsa_YDDA - for future use.  Need not be set by user.
    bsa_Reserved1, bsa_Reserved2 - for future use.  Need not be set.

**Result:**
The destWidth, destHeight fields are set by this function as
described above.

**Notes:**
o   This function may use the blitter.
o   Overlapping source and destination bit maps are not
    supported.
o   No check is made to ensure destBitMap is big enough: use
    ScalerDiv to calculate a destination dimension.

**Bugs:**
o   This function does not use the HighRes Agnus 'Big Blit'
    facility. You should not use XSrcFactor == XDestFactor,
    where SrcWidth or DestWidth > 1024.

o   Also, the blitter is used when expanding in the Y direction.
    You should not expand in the Y direction if
    ((DestX & 0xf) + DestWidth) >= 1024 pixels. (Up to 1008 pixels
    is always safe).

**See also:** ScalerDiv()  graphics/scale.h

---

### graphics.library/BltBitMap

**Move a rectangular region of bits in a BitMap.**

**Synopsis:**
```c
planecnt = BltBitMap(SrcBitMap, SrcX, SrcY, DstBitMap,
    DstX, DstY, SizeX, SizeY, Minterm, Mask [, TempA])

ULONG BltBitMap(CONST struct BitMap *, WORD, WORD,
    struct BitMap *, WORD, WORD, WORD, WORD, UBYTE, UBYTE,
    PLANEPTR);
```

**Description:**
Perform non-destructive blits to move a rectangle from one
area in a BitMap to another area, which can be on a different
BitMap.
This blit is assumed to be friendly: no error conditions (e.g.
a rectangle outside the BitMap bounds) are tested or reported.

**Inputs:**
SrcBitMap, DstBitMap - the BitMap(s) containing the
      rectangles
    - the planes copied from the source to the destination are
      only those whose plane numbers are identical and less
      than the minimum Depth of either BitMap and whose Mask
      bit for that plane is non-zero.
    - as a special case, if a plane pointer in the SrcBitMap
      is zero, it acts as a pointer to a plane of all zeros, and
      if the plane pointer is 0xffffffff, it acts as a pointer
      to a plane of all ones.  (Note: new for V36)
    - SrcBitMap and DstBitMap can be identical if they point
      to actual planes.
SrcX, SrcY - the x and y coordinates of the upper left corner
    of the source rectangle.  Valid range is positive
    signed integer such that the raster word's offset
    0..(32767-Size)
DstX, DstY - the x and y coordinates of the upper left
    corner of the destination for the rectangle.  Valid
    range is as for Src.
SizeX, SizeY - the size of the rectangle to be moved.  Valid
    range is (X: 1..976; Y: 1..1023 such that final raster
    word's offset is 0..32767)
Minterm - the logic function to apply to the rectangle when
    A is non-zero (i.e. within the rectangle).  B is the
    source rectangle and C, D is the destination for the
    rectangle.
    - $0C0 is a vanilla copy
    - $030 inverts the source before the copy
    - $050 ignores the source and inverts the destination
    - see the hardware reference manual for other combinations
Mask - the write mask to apply to this operation.  Bits set
    indicate the corresponding planes (if not greater than
    the minimum plane count) are to participate in the
    operation.  Typically this is set to 0xff.
TempA - If the copy overlaps exactly to the left or right
    (i.e. the scan line addresses overlap), and TempA is
    non-zero, it points to enough chip accessible memory
    to hold a line of A source for the blit (ie CHIP RAM).
    BltBitMap will allocate (and free) the needed TempA if
    none is provided and one is needed.  Blit overlap is
    determined from the relation of the first non-masked
    planes in the source and destination bit maps.

**Result:**
planecnt - the number of planes actually involved in the blit.

**Notes:**
o   This function may use the blitter.

**See also:** ClipBlit() graphics/gfx.h hardware/blit.h

---

### graphics.library/BltBitMapRastPort

**Blit from source bitmap to destination rastport.**

**Synopsis:**
```c
error=BltBitMapRastPort
      (srcbm, srcx, srcy, destrp, destX, destY, sizeX, sizeY,minterm)

BOOL BltBitMapRastPort(CONST struct BitMap *, WORD, WORD,
                       struct RastPort *, WORD, WORD, WORD, WORD,
                       UBYTE);
```

**Description:**
Blits from source bitmap to position specified in destination
rastport using minterm.

**Inputs:**
srcbm   - a pointer to the source bitmap
srcx    - x offset into source bitmap
srcy    - y offset into source bitmap
destrp  - a pointer to the destination rastport
destX   - x offset into dest rastport
destY   - y offset into dest rastport
sizeX   - width of blit in pixels
sizeY   - height of blit in rows
minterm - minterm to use for this blit

**Result:**
TRUE

**Bugs:**


**See also:** BltMaskBitMapRastPort() graphics/gfx.h graphics/rastport.h

---

### graphics.library/BltClear

**Synopsis:**
```c
BltClear( memBlock, bytecount, flags )

VOID BltClear( PLANEPTR, ULONG, ULONG );
```

**Description:**
For memory that is local and blitter accessible, the most
efficient way to clear a range of memory locations is
to use the system's most efficient data mover, the blitter.
This command accepts the starting location and count and clears
that block to zeros.

**Inputs:**
memBloc - pointer to local memory to be cleared
          memBlock is assumed to be even.
flags   - set bit 0 to force function to wait until
          the blit is done.
          set bit 1 to use row/bytesperrow.

bytecount - if (flags & 2) == 0 then
                        even number of bytes to clear.
                else
                        low 16 bits is taken as number of bytes
                        per row and upper 16 bits taken as
                        number of rows.

This function is somewhat hardware dependent.
In the rows/bytesperrow mode (with the pre-ECS blitter) rows must
be <- 1024. In bytecount mode multiple runs of the blitter may be
used to clear all the memory.

Set bit 2 to use the upper 16 bits of the Flags as the data to fill
memory with instead of 0 (V36).

**Result:**
The block of memory is initialized.

**Bugs:**


---

### graphics.library/BltMaskBitMapRastPort

**blit from source bitmap to destination
                         rastport with masking of source image.**

**Synopsis:**
```c
BltMaskBitMapRastPort
    (srcbm, srcx, srcy, destrp, destX, destY, sizeX, sizeY,
     minterm, bltmask)

VOID BltMaskBitMapRastPort
     (struct BitMap *, WORD, WORD, struct RastPort *, WORD, WORD,
      WORD, WORD, UBYTE, PLANEPTR);
```

**Description:**
Blits from source bitmap to position specified in destination
rastport using bltmask to determine where source overlays
destination, and minterm to determine whether to copy the source
image "as is" or to "invert" the sense of the source image when
copying. In either case, blit only occurs where the mask is non-zero.

**Inputs:**
srcbm   - a pointer to the source bitmap
srcx    - x offset into source bitmap
srcy    - y offset into source bitmap
destrp  - a pointer to the destination rastport
destX   - x offset into dest rastport
destY   - y offset into dest rastport
sizeX   - width of blit in pixels
sizeY   - height of blit in rows
minterm - either (ABC|ABNC|ANBC) if copy source and blit thru mask
          or     (ANBC)          if invert source and blit thru mask
bltmask - pointer to the single bit-plane mask, which must be the
          same size and dimensions as the planes of the
          source bitmap.

**Result:**


**Bugs:**


**See also:** BltBitMapRastPort() graphics/gfx.h graphics/rastport.h

---

### graphics.library/BltPattern

**Using standard drawing rules for areafill,
				 blit through a mask.**

**Synopsis:**
```c
BltPattern(rp, mask, xl, yl, maxx, maxy, bytecnt)

VOID BltPattern(struct RastPort *, CONST PLANEPTR,
         WORD, WORD, WORD, WORD, UWORD);
```

**Description:**
Blit using drawmode,areafill pattern, and mask
at position rectangle (xl,yl) (maxx,maxy).

**Inputs:**
rp    -  points to the destination RastPort for the blit.
mask  -  points to 2 dimensional mask if needed
         if mask == NULL then use a rectangle.
xl,yl -  coordinates of upper left of rectangular region in RastPort
maxx,maxy - points to lower right of rectangular region in RastPort
bytecnt - BytesPerRow for mask

**Result:**


**See also:** AreaEnd()

---

### graphics.library/BltTemplate

**Cookie cut a shape in a rectangle to the RastPort.**

**Synopsis:**
```c
BltTemplate(SrcTemplate, SrcX, SrcMod, rp,
    DstX,  DstY, SizeX, SizeY)

VOID BltTemplate(CONST PLANEPTR, WORD, WORD, struct RastPort *,
     WORD, WORD, WORD, WORD);
```

**Description:**
This function draws the image in the template into the
RastPort in the current color and drawing mode at the
specified position.  The template is assumed not to overlap
the destination.
If the template falls outside the RastPort boundary, it is
truncated to that boundary.

Note: the SrcTemplate pointer should point to the "nearest" word
   (rounded down) of the template mask. Fine alignment of the mask
   is achieved by setting the SrcX bit offseet within the range
   of 0 to 15 decimal.

**Inputs:**
SrcTemplate  - pointer to the first (nearest) word of the
        template mask.
SrcX         - x bit offset into the template mask (range 0..15).
SrcMod       - number of bytes per row in template mask.
rp           - pointer to destination RastPort.
DstX, DstY   - x and y coordinates of the upper left
        corner of the destination for the blit.
SizeX, SizeY - size of the rectangle to be used as the
        template.

**Notes:**
o   This function may use the blitter.

**See also:** BltBitMap()  graphics/rastport.h

---

### graphics.library/CalcIVG (V39)

**Calculate the number of blank lines above a ViewPort**

**Synopsis:**
```c
uint16 count = CalcIVG(struct View *view, struct ViewPort* vp);
```

**Description:**
To calculate the maximum number of blank lines above a viewport
needed to load all the copper instructions, after accounting for
the viewport bandwidth and size.

**Inputs:**
view  - pointer to the View
vp    - pointer to the ViewPort you are interested in.

**Result:**
count - the number of ViewPort resolution scan lines needed to
 execute all the copper instructions for ViewPort,
 or 0 if any error.

**Notes:**
The number of copper instructions comes from the vp->vp_DspIns list.
Although there may be other copper instructions in the final list
(from UCopIns, SprIns and ClrIns) they are currently ignored for
this function. This also means that if the ViewPort has never been
made (for example, the ViewPort of an intuition screen was opened
behind) then vp->vp_DspIns is NULL.

Although CalcIVG() returns the true number of lines needed by the
copper, intuition still maintains an inter-screen gap of 3 non-laced
lines (6 interlaced). Therefore, for intuition screens use:
MAX(CalcIVG(v, vp), (islaced ? 6 : 3))

**See also:** GfxNew() VideoControl() graphics/view.h

---

### graphics.library/CBump

**increment user copper list pointer
         (bump to next position in list).**

**Synopsis:**
```c
CBump( c )

VOID CBump( struct UCopList * );
```

**Description:**
Increment pointer to space for next instruction in user copper list.

**Inputs:**
c - pointer to UCopList structure

**Result:**
User copper list pointer is incremented to next position.
Pointer is repositioned to next user copperlist instruction block
if the current block is full.

    Note: CBump is usually invoked for the programmer as part of the
          macro definitions CWAIT or CMOVE.

**Bugs:**


**See also:** CINIT() CWAIT() CMOVE() CEND() graphics/copper.h

---

### graphics.library/CEND

**Terminate user copper list.**

**Synopsis:**
```c
CEND( c )

 struct UCopList *c;
```

**Description:**
Add instruction to terminate user copper list.

**Inputs:**
c - pointer to UCopList structure

**Result:**
This is actually a macro that calls the macro CWAIT(c,10000,255)
 10000 is a magical number that the graphics.library uses.
 I hope display technology doesn't catch up too fast!

**Bugs:**


**See also:** CINIT() CWAIT() CMOVE() graphics/copper.h

---

### graphics.library/ChangeExtSpriteA (V39)

**Change the sprite image pointer.ChangeExtSprite  -- varargs stub for ChangeExtSpriteA().**

**Synopsis:**
```c
success = ChangeExtSpriteA( vp, oldsprite, newsprite, tags)

LONG ChangeExtSpriteA(struct ViewPort *, struct ExtSprite *,
		struct ExtSprite *, CONST struct TagItem *);

LONG ChangeExtSprite(vp, old_sp, new_sp, tag1, ....);
```

**Description:**
Attempt to change which sprite is displayed for a given
sprite engine.

**Inputs:**
vp - pointer to ViewPort structure that this sprite is
	  relative to,  or 0 if relative only top of View
oldsprite - pointer the old ExtSprite structure
newsprite - pointer to the new ExtSprite structure.

**Result:**
success - 0 if there was an error.

**Bugs:**


**See also:** FreeSprite() ChangeSprite() MoveSprite() AllocSpriteDataA()
graphics/sprite.h

---

### graphics.library/ChangeSprite

**Change the sprite image pointer.**

**Synopsis:**
```c
ChangeSprite( vp, s, newdata)

VOID ChangeSprite(struct ViewPort *, struct SimpleSprite *, APTR )
```

**Description:**
The sprite image is changed to use the data starting at newdata

**Inputs:**
vp - pointer to ViewPort structure that this sprite is
     relative to,  or 0 if relative only top of View
s - pointer to SimpleSprite structure
newdata - pointer to data structure of the following form.
    struct spriteimage
    {
        UWORD posctl[2];       // used by simple sprite machine
        UWORD data[height][2]; // actual sprite image
        UWORD reserved[2];     // initialized to 0x0, 0x0
    };
The programmer must initialize reserved[2].  Spriteimage must be
in CHIP memory. The height subfield of the SimpleSprite structure
must be set to reflect the height of the new spriteimage BEFORE
calling ChangeSprite(). The programmer may allocate two sprites to
handle a single attached sprite.  After GetSprite(), ChangeSprite(),
the programmer can set the SPRITE_ATTACHED bit in posctl[1] of the
odd numbered sprite.
If you need more than 8 sprites, look up VSprites in the
graphics documentation.

**Result:**


**Bugs:**


**See also:** FreeSprite() ChangeSprite() MoveSprite() AddVSprite()
graphics/sprite.h

---

### graphics.library/ChangeVPBitMap (V39)

**change display memory address for multi-buffered
                  animation**

**Synopsis:**
```c
VOID ChangeVPBitMap(struct ViewPort *vp, struct BitMap *bm,
                    struct DBufInfo *db);
```

**Description:**
Changes the area of display memory which will be displayed in a
viewport. This can be used to implement double (or triple)
buffering, a method of achieving smooth animation.

**Inputs:**
vp  -  A pointer to a viewport
bm  -  A pointer to a BitMap structure. This BitMap structure must
       be of the same layout as the one attached to the viewport
       (same depth, alignment, and BytesPerRow).
db  -  A pointer to a DBufInfo.

**Notes:**
This will set the vp->RasInfo->BitMap field to the bm pointer which
is passed.

When using the synchronization features, you MUST carefully insure
that all messages have been replied to before calling FreeDBufInfo or
calling ChangeVPBitMap with the same DBufInfo.

**Bugs:**


**See also:** AllocDBufInfo(), AllocBitMap()

---

### graphics.library/CINIT

**Initialize user copperlist to accept intermediate
         user copper instructions.**

**Synopsis:**
```c
cl = CINIT( ucl , n )

cl = UCopperListInit( ucl , n )

struct CopList *UCopperListInit( struct UCopList *, UWORD );
```

**Description:**
Allocates and/or initialize copperlist structures/buffers
internal to a UCopList structure.

This is a macro that calls UCopListInit. You must pass a
(non-initialized) UCopList to CINIT (CINIT will NOT allocate
a new UCopList if ucl==0 ). If (ucl != 0) it will initialize the
intermediate data buffers internal to a UCopList.

The maximum number of intermediate copper list instructions
that these internal CopList data buffers contain is specified
as the parameter n.

**Inputs:**
ucl - pointer to UCopList structure
n - number of instructions buffer must be able to hold

**Result:**
cl- a pointer to a buffer which will accept n intermediate copper
    instructions.

NOTE: this is NOT a UCopList pointer, rather a pointer to the
      UCopList's->FirstCopList sub-structure.

**Bugs:**
CINIT will not actually allocate a new UCopList if ucl==0.
Instead you must allocate a block MEMF_PUBLIC|MEMF_CLEAR, the
sizeof(struct UCopList) and pass it to this function.

The system's FreeVPortCopLists function will take care of
deallocating it if they are called.

Prior to release V36 the  CINIT macro had { } braces surrounding
the definition, preventing the proper return of the result value.
These braces have been removed for the V36 include definitions.

**See also:** CINIT() CMOVE() CEND() graphics/copper.h

---

### graphics.library/ClearEOL

**Clear from current position to end of line.**

**Synopsis:**
```c
ClearEOL(rp)

VOID ClearEOL(struct RastPort *);
```

**Description:**
Clear a rectangular swath from the current position to the
right edge of the rastPort.  The height of the swath is taken
from that of the current text font, and the vertical
positioning of the swath is adjusted by the text baseline,
such that text output at this position would lie wholly on
this newly cleared area.
Clearing consists of setting the color of the swath to zero,
or, if the DrawMode is 2, to the BgPen.

**Inputs:**
rp - pointer to RastPort structure

**Result:**


**Notes:**
o   This function may use the blitter.

**See also:** Text()  ClearScreen()  SetRast()
graphics/text.h  graphics/rastport.h

---

### graphics.library/ClearRectRegion

**Perform 2d CLEAR operation of rectangle
                with region, leaving result in region.**

**Synopsis:**
```c
status = ClearRectRegion(region,rectangle)

BOOL ClearRectRegion(struct Region *, CONST struct Rectangle * );
```

**Description:**
Clip away any portion of the region that exists inside
of the rectangle. Leave the result in region.

**Inputs:**
region - pointer to Region structure
rectangle - pointer to Rectangle structure

**Result:**
status - return TRUE if successful operation
         return FALSE if ran out of memory

**Bugs:**


**See also:** AndRectRegion() graphics/regions.h

---

### graphics.library/ClearRegion

**Remove all rectangles from region.**

**Synopsis:**
```c
ClearRegion(region)

   VOID ClearRegion( struct Region * );
```

**Description:**
Clip away all rectangles in the region leaving nothing.

**Inputs:**
region - pointer to Region structure

**Bugs:**


**See also:** NewRegion() graphics/regions.h

---

### graphics.library/ClearScreen

**Clear from current position to end of RastPort.**

**Synopsis:**
```c
ClearScreen(rp)

VOID ClearScreen(struct RastPort *);
```

**Description:**
Clear a rectangular swath from the current position to the
right edge of the rastPort with ClearEOL, then clear the rest
of the screen from just beneath the swath to the bottom of
the rastPort.
Clearing consists of setting the color of the swath to zero,
or, if the DrawMode is 2, to the BgPen.

**Inputs:**
rp - pointer to RastPort structure

**Notes:**
o   This function may use the blitter.

**See also:** ClearEOL()  Text()  SetRast()
graphics/text.h  graphics/rastport.h

---

### graphics.library/ClipBlit

**Calls BltBitMap() after accounting for windows**

**Synopsis:**
```c
ClipBlit(Src, SrcX, SrcY, Dest, DestX, DestY, XSize, YSize, Minterm)

VOID ClipBlit
     (struct RastPort *, WORD, WORD, struct RastPort *, WORD, WORD,
      WORD, WORD, UBYTE);
```

**Description:**
Performs the same function as BltBitMap(), except that it
takes into account the Layers and ClipRects of the layer library,
all of which are (and should be) transparent to you.  So, whereas
BltBitMap() requires pointers to BitMaps, ClipBlit requires pointers
to the RastPorts that contain the Bitmaps, Layers, etcetera.

If you are going to blit blocks of data around via the RastPort of
your Intuition Window, you must call this routine (rather than
BltBitMap()).

Either the Src RastPort, the Dest RastPort, both, or neither,
can have Layers. This routine takes care of all cases.

See BltBitMap() for a thorough explanation.

**Inputs:**
Src          - pointer to the RastPort of the source for your blit
SrcX, SrcY   - the topleft offset into Src for your data
Dest         - pointer to the RastPort to receive the blitted data
DestX, DestY - the topleft offset into the destination RastPort
XSize        - the width of the blit (must be ta least 1)
YSize        - the height of the blit (must be at least 1)
Minterm      - the boolean blitter function, where SRCB is
               associated with the Src RastPort and SRCC goes
               to the Dest RastPort

**Result:**


**Bugs:**


**See also:** BltBitMap()

---

### graphics.library/CloseFont

**Release a pointer to a system font.**

**Synopsis:**
```c
CloseFont(font)

VOID CloseFont(struct TextFont *);
```

**Description:**
This function indicates that the font specified is no longer
in use.  It is used to close a font opened by OpenFont, so
that fonts that are no longer in use do not consume system
resources.

**Inputs:**
font - A font pointer as returned by OpenFont() or OpenDiskFont().

**Result:**


**Bugs:**


**See also:** OpenFont() diskfont.library/OpenDiskFont() graphics/text.h

---

### graphics.library/CloseMonitor (V36)

**close a MonitorSpec**

**Synopsis:**
```c
error = CloseMonitor( monitor_spec )

LONG CloseMonitor( struct MonitorSpec * );
```

**Description:**
Relinquish access to a MonitorSpec.

**Inputs:**
monitor_spec - a pointer to a MonitorSpec opened via OpenMonitor(),
or NULL.

**Result:**
error - FALSE if MonitorSpec closed uneventfully.
        TRUE if MonitorSpec could not be closed.

**Bugs:**


**See also:** OpenMonitor()

---

### graphics.library/CMOVE

**append copper move instruction to user copper list.**

**Synopsis:**
```c
CMOVE( c , a , v )

 CMove( c , da , v )
 CBump( c )

 VOID CMove( struct UCopList *, WORD, WORD );
```

**Description:**
Add instruction to move value v to hardware register a.

**Inputs:**
c  - pointer to UCopList structure
 a  - hardware register
 da - hardware register offset
 v  - 16 bit value to be written

**Result:**
This is actually a macro that calls CMove(c,&a,v)
 and then calls CBump(c) to bump the local pointer
 to the next instruction. Watch out for macro side affects.

**Bugs:**


**See also:** CINIT() CWAIT() CEND() graphics/copper.h

---

### graphics.library/CoerceMode (V39)

**calculate ViewPort mode coercion**

**Synopsis:**
```c
uint32 ID = CoerceMode(struct ViewPort *RealViewPort, uint32 MonitorID,
                uint32 Flags);
```

**Description:**
To determine the best mode in the MonitorID to coerce RealViewPort
to, given the restrictions set in Flags.

**Inputs:**
RealViewPort - ViewPort to coerce
MonitorID    - Montor number to coerce to (ie a mode masked with
        MONITOR_ID_MASK).
Flags        - PRESERVE_COLORS - keep the number of bitplanes
        in the ViewPort.
        AVOID_FLICKER - do not coerce to an interlace mode

**Result:**
ID - ID of the best mode to coerce to, or INVALID_ID if could not
     coerce (see NOTES).

**Example:**
```c
uint32 newmode = CoerceMode(vp, VGA_MONITOR_ID, PRESERVE_COLORS);
```

**Notes:**
This function takes into account the compatibility of the Monitor
being coerced to, and the ViewPort that is being coerced.
Incompatibilities will cause a result of INVALID_ID.

**See also:** graphics/coerce.h graphics/displayinfo.h

---

### graphics.library/CopySBitMap

**Syncronize Layer window with contents of
                                        Super BitMap**

**Synopsis:**
```c
CopySBitMap( layer )

VOID CopySBitMap(struct Layer *);
```

**Description:**
This is the inverse of SyncSBitMap.
Copy all bits from SuperBitMap to Layer bounds.
This is used for those functions that do not
want to deal with the ClipRect structures but do want
to be able to work with a SuperBitMap Layer.

**Inputs:**
layer - pointer to a SuperBitMap Layer
    The Layer must already be locked by the caller.

**Bugs:**


**See also:** LockLayerRom() SyncSBitMap()

---

### graphics.library/CWAIT

**Append copper wait instruction to user copper list.**

**Synopsis:**
```c
CWAIT( c , v , h )

 CWait( c , v , h )
 CBump( c )

 VOID CWait( struct UCopList *, WORD, WORD)
```

**Description:**
Add instruction to wait for vertical beam position v and
 horizontal position h to this intermediate copper list.

**Inputs:**
c - pointer to UCopList structure
 v - vertical beam position (relative to top of viewport)
 h - horizontal beam position

**Result:**
this is actually a macro that calls CWait(c,v,h)
 and then calls CBump(c) to bump the local pointer
 to the next instruction.

**Bugs:**
User waiting for horizontal values of greater than 222 decimal
 is illegal.

**See also:** CINIT() CMOVE() CEND() graphics/copper.h

---

### graphics.library/DisownBlitter

**return blitter to free state.**

**Synopsis:**
```c
DisownBlitter()

VOID DisownBlitter( VOID );
```

**Description:**
Free blitter up for use by other blitter users.

**Inputs:**


**Result:**


**See also:** OwnBlitter()

---

### graphics.library/DisposeRegion

**Return all space for this region to free
                 memory pool.**

**Synopsis:**
```c
DisposeRegion(region)

   VOID DisposeRegion( struct Region * );
```

**Description:**
Free all RegionRectangles for this Region then
free the Region itself.

**Inputs:**
region - pointer to Region structure

**Bugs:**


**See also:** NewRegion() graphics/regions.h

---

### graphics.library/DoCollision

**Test every gel in gel list for collisions.**

**Synopsis:**
```c
DoCollision(rp)

VOID DoCollision(struct RastPort *);
```

**Description:**
Tests each gel in gel list for boundary and gel-to-gel collisions.
On detecting one of these collisions, the appropriate collision-
handling routine is called. See the documentation for a thorough
description of which collision routine is called. This routine
expects to find the gel list correctly sorted in Y,X order.
The system routine SortGList performs this function for the user.

**Inputs:**
rp = pointer to a RastPort

**Result:**


**Bugs:**


**See also:** InitGels()  SortGList()  graphics/gels.h  graphics/gels.h

---

### graphics.library/Draw

**Draw a line between the current pen position
                and the new x,y position.**

**Synopsis:**
```c
Draw( rp,   x,     y)

VOID Draw( struct RastPort *, WORD, WORD);
```

**Description:**
Draw a line from the current pen position to (x,y).

**Inputs:**
rp - pointer to the destination RastPort
x,y - coordinates of where in the RastPort to end the line.

**Bugs:**


**See also:** Move() graphics/rastport.h

---

### graphics.library/DrawEllipse

**Draw an ellipse centered at cx,cy with vertical
   and horizontal radii of a,b respectively.**

**Synopsis:**
```c
DrawEllipse( rp, cx, cy, a, b )

VOID DrawEllipse( struct RastPort *, WORD, WORD, WORD, WORD);
```

**Description:**
Creates an elliptical outline within the rectangular region
specified by the parameters, using the current foreground pen color.

**Inputs:**
rp - pointer to the RastPort into which the ellipse will be drawn.
cx - x coordinate of the centerpoint relative to the rastport.
cy - y coordinate of the centerpoint relative to the rastport.
a  - the horizontal radius of the ellipse (note: a must be > 0)
b  - the vertical radius of the ellipse (note: b must be > 0)

**Notes:**
this routine does not clip the ellipse to a non-layered rastport.

**Bugs:**


**See also:** DrawCircle macro
graphics/gfxmacros.h
graphics/rastport.h

---

### graphics.library/DrawGList

**Process the gel list, queueing VSprites, drawing Bobs.**

**Synopsis:**
```c
DrawGList(rp, vp)

VOID DrawGList(struct RastPort *, struct ViewPort *);
```

**Description:**
Performs one pass of the current gel list.
   - If nextLine and lastColor are defined, these are
     initialized for each gel.
   - If it's a VSprite, build it into the copper list.
   - If it's a Bob, draw it into the current raster.
   - Copy the save values into the "old" variables,
     double-buffering if required.

**Inputs:**
rp = pointer to the RastPort where Bobs will be drawn
vp = pointer to the ViewPort for which VSprites will be created

**Result:**


**Bugs:**
MUSTDRAW isn't implemented yet.

**See also:** InitGels()  graphics/gels.h graphics/rastport.h  graphics/view.h

---

### graphics.library/EraseRect (V36)

**Fill a defined rectangular area using the current
             BackFill hook.**

**Synopsis:**
```c
EraseRect( rp, xmin, ymin, xmax, ymax)

VOID EraseRect(struct RastPort *, WORD, WORD, WORD, WORD);
```

**Description:**
Fill the rectangular region specified by the parameters with the
BackFill hook. If non-layered, the rectangular region specified by
the parameters is cleared. If layered the Layer->BackFill Hook is
used.

**Inputs:**
rp   - pointer to a RastPort structure.
xmin - x coordinate of the upper left  corner of the region to fill.
ymin - y coordinate of the upper left  corner of the region to fill.
xmax - x coordinate of the lower right corner of the region to fill.
ymax - y coordinate of the lower right corner of the region to fill.

**Notes:**
The following relation MUST be true:
(xmax >= xmin) and (ymax >= ymin)

**Bugs:**


**See also:** graphics/rastport.h graphics/clip.h

---

### graphics.library/ExtendFont (V36)

**ensure tf_Extension has been built for a font**

**Synopsis:**
```c
success = ExtendFont(font, fontTags)

ULONG ExtendFont(struct TextFont *, CONST struct TagItem *);

success = ExtendFontTags(font, Tag1, ...)  (V39)

ULONG ExtendFontTags(struct TextFont *, ULONG, ...);
```

**Description:**
To extend a TextFont structure.

**Inputs:**
font - The font to extend.
fontTags - An optional taglist.  If NULL, then a default is used.
           Currently, the only tag defined is TA_DeviceDPI.

**Result:**
success - 1 if the TextFont was properly extended, else 0.

**Notes:**
The varargs stub was missing from amiga.lib until V39.
To avoid problems when old software copies the tf_Style
flags from a TextFont to the ta_Style flags of a TextAttr
(not a TTextAttr) structure, ExtendFont() clears the FSF_TAGGED
bit. This does not mean that the TextFont is not tagged, only
a NULL tfe_Tags pointer can indicate that its untagged.

**See also:** graphics/text.h

---

### graphics.library/FindColor (V39)

**Find the closest matching color in a colormap.**

**Synopsis:**
```c
uint16 color = FindColor(struct ColorMap *cm,
                  uint32 R, uint32 G, uint32 B, int32 maxpen);
```

**Inputs:**
cm = colormap
R = red level   (32 bit left justified fraction)
G = green level (32 bit left justified fraction)
B = blue level  (32 bit left justified fraction)
MaxPen = the maximum entry in the color table to search. A value of
 -1 will limit the search to only those pens which could be
 rendered in (for instance, it will not examine the sprite
 colors on a 4 color screen).

**Result:**
The system will attempt to find the color in the passed colormap
which most closely matches the RGB values passed. No new pens will
be allocated, and you should not ReleasePen() the returned pen.
This function is not sensitive to palette sharing issues. Its
intended use is for:

 (a) programs which pop up on public screens when those
     screens are not using palette sharing. You might
     use this function as a fallback when ObtainBestPenA()
     says that there are no sharable pens.

 (b) Internal color matching by an application which is
     either running on a non-public screen, or which
     wants to match colors to an internal color table
     which may not be associated with any displayed screen.

**Notes:**
In order to use the MaxPen=-1 feature, you must have initialized
palette sharing via AttachPalExtra() (all intuition screens do this).
Otherwise, MaxPen=-1 will search all colors in the colormap.

**Bugs:**


**See also:** ObtainBestPenA() GetColorMap() ObtainPen() ReleasePen()

---

### graphics.library/FindDisplayInfo (V36)

**search for a record identified by
            a specific key**

**Synopsis:**
```c
handle = FindDisplayInfo(ID)

DisplayInfoHandle FindDisplayInfo(ULONG);
```

**Description:**
Given a 32-bit Mode Key, return a handle to a valid DisplayInfoRecord
found in the graphics database.  Using this handle, you can obtain
information about this Mode, including its default dimensions,
properties, and whether it is currently available for use.

**Inputs:**
ID     - unsigned long identifier

**Result:**
handle - handle to a displayinfo Record with that key
  or NULL if no match.

**Bugs:**


**See also:** graphics/displayinfo.h

---

### graphics.library/Flood

**Flood rastport like areafill.**

**Synopsis:**
```c
BOOL error = Flood(struct RastPort *rp, uint32 mode, int16 x, int16 y);
```

**Description:**
Search the BitMap starting at (x,y).

Fill all adjacent pixels if they are:
    Mode 0: not the same color as AOLPen
    Mode 1: the same color as the pixel at (x,y)

When actually doing the fill use the modes that apply to
standard areafill routine such as drawmodes and patterns.

**Inputs:**
rp    - pointer to RastPort
(x,y) - coordinate in BitMap to start the flood fill at.
mode  -  0 fill all adjacent pixels searching for border.
  1 fill all adjacent pixels that have same pen number
  as the one at (x,y).

**Notes:**
In order to use Flood() on classic Amiga bitmaps the destination
RastPort must have a valid TmpRas raster whose size is as large as
that of the RastPort.

When using Flood() with retargetable bitmaps the TmpRas (if present)
is ignored and internal buffers are used instead. To test whether a
bitmap is retargetable see GetBitMapAttr()'s BMA_ISRTG attribute.

**See also:** AreaEnd(), InitTmpRas(), GetBitMapAttr(), graphics/rastport.h

---

### graphics.library/FontExtent (V36)

**get the font attributes of the current font**

**Synopsis:**
```c
FontExtent(font, fontExtent)

VOID FontExtent(CONST struct TextFont *, struct TextExtent *);
```

**Description:**
This function fills the text extent structure with a bounding
(i.e. maximum) extent for the characters in the specified font.

**Inputs:**
font       - the TextFont from which the font metrics are extracted.
fontExtent - the TextExtent structure to be filled.

**Result:**
fontExtent is filled.

**Notes:**
The TextFont, not the RastPort, is specified -- unlike
TextExtent(), effect of algorithmic enhancements is not
included, nor does te_Width include any effect of
rp_TxSpacing.  The returned te_Width will be negative only
when FPF_REVPATH is set in the tf_Flags of the font -- the
effect of left-moving characters is ignored for the width of
a normal font, and the effect of right-moving characters is
ignored if a REVPATH font.  These characters will, however,
be reflected in the bounding extent.

**See also:** TextExtent() graphics/text.h

---

### graphics.library/FreeBitMap (V39)

**free a bitmap created by AllocBitMap**

**Synopsis:**
```c
VOID FreeBitMap(struct BitMap *bm);
```

**Description:**
Frees bitmap and all associated underlying data.

**Inputs:**
bm - A pointer to a BitMap structure. Passing a NULL-pointer
     (meaning "do nothing") is OK.

**Notes:**
When using standard Amiga bitmaps, be careful to ensure that any
rendering done to the bitmap has completed (by calling WaitBlit())
before you call this function.

**See also:** AllocBitMap(), AllocBitMapTagList()

---

### graphics.library/FreeColorMap

**Free the ColorMap structure and return memory
         to free memory pool.**

**Synopsis:**
```c
void FreeColorMap(struct ColorMap *colormap);
```

**Description:**
Return the memory to the free memory pool that was allocated
with GetColorMap.

**Inputs:**
colormap - pointer to ColorMap allocated with GetColorMap.
    Passing a NULL pointer (meaning "do nothing") is
    acceptable (V39).

**Result:**
The space is made available for others to use.

**Bugs:**


**See also:** SetRGB4() GetColorMap() graphics/view.h

---

### graphics.library/FreeCopList

**deallocate intermediate copper list**

**Synopsis:**
```c
FreeCopList(coplist)

VOID FreeCopList( struct CopList *);
```

**Description:**
Deallocate all memory associated with this copper list.

**Inputs:**
coplist - pointer to structure CopList

**Result:**
memory returned to memory manager

**Bugs:**


**See also:** graphics/copper.h

---

### graphics.library/FreeCprList

**deallocate hardware copper list**

**Synopsis:**
```c
FreeCprList(cprlist)

VOID FreeCprList(struct cprlist *);
```

**Description:**
return cprlist to free memory pool

**Inputs:**
cprlist - pointer to cprlist structure

**Result:**
memory returned and made available to other tasks

**Bugs:**


**See also:** graphics/copper.h

---

### graphics.library/FreeDBufInfo (V39)

**free information for multi-buffered animation**

**Synopsis:**
```c
FreeDBufInfo(db)

VOID FreeDBufInfo(struct DBufInfo *)
```

**Description:**
Frees a structure obtained from AllocDBufInfo

**Inputs:**
db  =  A pointer to a DBufInfo.

**Notes:**
FreeDBufInfo(NULL) is a no-op.

**Bugs:**


**See also:** AllocDBufInfo() ChangeVPBitMap()

---

### graphics.library/FreeGBuffers

**Deallocate memory obtained by GetGBufers.**

**Synopsis:**
```c
FreeGBuffers(anOb, rp, db)

VOID FreeGBuffers(struct AnimOb *, struct RastPort *, BOOL);
```

**Description:**
For each sequence of each component of the AnimOb,
deallocate memory for:
    SaveBuffer
    BorderLine
    CollMask and ImageShadow (point to same buffer)
    if db is set (user had used double-buffering) deallocate:
        DBufPacket
        BufBuffer

**Inputs:**
anOb = pointer to the AnimOb structure
rp   = pointer to the current RastPort
db   = double-buffer indicator (set TRUE for double-buffering)

**Result:**


**Bugs:**


**See also:** GetGBuffers()  graphics/gels.h  graphics/rastport.h

---

### graphics.library/FreeRaster

**Release an allocated area
          to the system free memory pool.**

**Synopsis:**
```c
FreeRaster( p, width, height )

VOID FreeRaster( PLANEPTR, UWORD, UWORD);
```

**Description:**
Return the memory associated with this PLANEPTR of size
width and height to the MEMF_CHIP memory pool.

**Inputs:**
p  =  a pointer to a memory space  returned  as  a
      result of a call to AllocRaster.

width - the width in bits of the bitplane.
height - number of rows in bitplane.

**Notes:**
Width and height should be the same values with which you
called AllocRaster in the first place.

**Bugs:**


**See also:** AllocRaster() graphics/gfx.h

---

### graphics.library/FreeSprite

**Return sprite for use by others and virtual
       sprite machine.**

**Synopsis:**
```c
FreeSprite( pick )

VOID FreeSprite( WORD );
```

**Description:**
Mark sprite as available for others to use.
These sprite routines are provided to ease sharing of sprite
hardware and to handle simple cases of sprite usage and
movement.  It is assumed the programs that use these routines
do want to be good citizens in their hearts. ie: they will
not FreeSprite unless they actually own the sprite.
The Virtual Sprite machine may ignore the simple sprite machine.

**Inputs:**
pick - number in range of 0-7

**Result:**
sprite made available for subsequent callers of GetSprite
as well as use by Virtual Sprite Machine.

**Bugs:**


**See also:** GetSprite() ChangeSprite() MoveSprite() graphics/sprite.h

---

### graphics.library/FreeSpriteData (V39)

**free sprite data
                  allocated by AllocSpriteData()**

**Synopsis:**
```c
FreeSpriteData(extsp)

VOID FreeSpriteData(struct ExtSprite *);
```

**Description:**


**Inputs:**
extsp - The extended sprite structure to be freed.
        Passing NULL is a NO-OP.

**See also:** FreeSpriteData() FreeSprite() ChangeSprite() MoveSprite()
GetExtSprite() AllocBitMap() graphics/sprite.h

---

### graphics.library/FreeVPortCopLists

**deallocate all intermediate copper lists and
their headers from a viewport**

**Synopsis:**
```c
FreeVPortCopLists(vp)

VOID FreeVPortCopLists(struct ViewPort *);
```

**Description:**
Search display, color, sprite, and user copper
lists and call FreeMem() to deallocate them from memory

**Inputs:**
vp - pointer to ViewPort structure

**Result:**
The memory allocated to the various copper lists will be returned
to the system's free memory pool, and the following fields in
the viewport structure will be set to NULL:

        DspIns, Sprins, ClrIns, UCopIns

**Bugs:**
none known

**See also:** graphics/view.h

---

### graphics.library/GetAPen (V39)

**Get the A Pen value for a RastPort.**

**Synopsis:**
```c
pen = GetAPen  ( rp )

   ULONG GetAPen(struct RastPort *)
```

**Description:**
Return the current value of the A pen for the rastport. This function
should be used instead of peeking the structure directly, because
future graphics devices may store it differently, for instance,
using more bits.

**Inputs:**
rp  -  a pointer to a valid RastPort structure.

**Result:**
pen - the A Pen value of the RastPort.

**Notes:**


**Bugs:**


**See also:** SetAPen() graphics/gfx.h

---

### graphics.library/GetBitMapAttr (V39)

**Returns information about a bitmap**

**Synopsis:**
```c
uint32 value = GetBitMapAttr(CONST struct BitMap *bm,
                             uint32 attrnum);
```

**Description:**
Determines information about a bitmap. This function must be used
instead of reading the bitmap structure fields directly. This will
provide future compatibility.

Some attributes such as the base address of the bitmap data is
only available when the bitmap is locked. See the
LockBitMapTagList() autodoc for dynamic attributes.

**Inputs:**
bm - A pointer to a BitMap structure.

attrnum - A number indicating which attribute of the bitmap
          is returned:

          BMA_HEIGHT returns the height in pixels.

          BMA_WIDTH returns the width in pixels.

              Note this value may not be the same as the original
              value passed in via AllocBitMapTagList() due to
              hardware alignment restrictions.

          BMA_DEPTH returns the depth. This is the number of
              bits which are required to store the information
              for one pixel in the bitmap.

              The bitmap depth is the absolute number of bits
              required and is not be the same as the actual number
              of bits per pixel used to store the bitmap in
              memory. See BMA_BITSPERPIXEL for bits per pixel.

              Note this value may not be the same as the original
              value passed in via AllocBitMapTagList() due to
              hardware alignment restrictions.

          BMA_FLAGS returns a bit field describing attributes
              which the bitmap may have. Currently defined flags
              are: BMF_DISPLAYABLE, BMF_INTERLEAVED and
              BMF_STANDARD.

              The BMF_STANDARD flag will be set if the bitmap is
              a standard Amiga bitmap in Chip RAM. It is possible
              to allocate bitmaps in Fast RAM in which case this
              flag will not be set.

              For RTG bitmaps, this field will always be zero.

          BMA_ISRTG returns TRUE is the bitmap is retargetable
              or FALSE if not. Retargetable bitmaps can be moved
              into and out of graphics board memory. (V54)

          BMA_BYTESPERPIXEL returns the number of bytes per pixel
              used to store the bitmap data. Returns zero if this
              is not an RTG bitmap. (V54)

          BMA_BITSPERPIXEL returns the number of bits per pixel
              used to store the bitmap data. This is not the same
              the same as the depth of the bitmap. Returns zero
              if this is not an RTG bitmap. (V54)

              For example, an PIXF_A8B8G8R8 bitmap has a depth
              of 24 bits but stores 32 bits per pixel due to the
              extra 8 bits for the alpha channel.

          BMA_PIXELFORMAT returns the pixel format of the bitmap
              which is one of the enPixelFormat values. Returns
              PIXF_NONE if this is not an RTG bitmap. (V54)

          BMA_ACTUALWIDTH returns the unaltered original bitmap
              width passed in via AllocVecTagList(). This width
              is never altered or aligned by the system.
              Returns zero if this is not an RTG bitmap. (V54)

**Result:**
value - A uint32 value. The interpretation of the return value
        depends on which of the chosen attrnum above.

**Notes:**
Unknown attributes are reserved for future use and return zero.

BMF_DISPLAYABLE will only be set if the source bitmap meets all of
the required alignment restrictions. A bitmap which does not meet
these restrictions may still be displayable at some loss of
efficiency.

Always use BMA_ISRTG to tell the difference between an RTG bitmap
and a non-RTG bitmap. Not only is the code more explicit, it is
also the fastest and most reliable method.

**See also:** AllocBitMap(), AllocBitMapTagList(), LockBitMapTagList()

---

### graphics.library/GetBPen (V39)

**Get the B Pen value for a RastPort.**

**Synopsis:**
```c
pen = GetBPen  ( rp )

ULONG GetBPen(struct RastPort *)
```

**Description:**
Return the current value of the B pen for the rastport. This function
should be used instead of peeking the structure directly, because
future graphics devices may store it differently, using more bits.

**Inputs:**
rp  =  a pointer to a valid RastPort structure.

**Result:**
pen - the B Pen value of the RastPort.

**Notes:**


**Bugs:**


**See also:** SetBPen() graphics/gfx.h

---

### graphics.library/GetColorMap

**allocate and initialize Colormap**

**Synopsis:**
```c
struct ColorMap *cm = GetColorMap(uint16 entries);
```

**Description:**
Allocates, initializes and returns a pointer to a ColorMap
data structure, later enabling calls to SetRGB4/SetRGB32
and LoadRGB4/LoadRGB32 to load colors for a view port. The
ColorTable pointer in the ColorMap structure points to a
hardware specific colormap data structure. You should not
count on it being anything you can understand. Use
GetRGB4()/GetRGB32() to query it or SetRGB4CM/SetRGB32CM
to set it directly.

**Inputs:**
entries - number of entries for this colormap

**Result:**
The pointer value returned by this routine, if nonzero,
may be stored into the ViewPort.ColorMap pointer.
If a value of 0 is returned, the system was unable
to allocate enough memory space for the required
data structures.

**Bugs:**


**See also:** SetRGB4() FreeColorMap()

---

### graphics.library/GetDisplayInfoData (V36)

**Query DisplayInfo Record parameters**

**Synopsis:**
```c
uint32 result = GetDisplayInfoData(CONST DisplayInfoHandle handle,
           APTR buf, uint32 size, Tag tagID, uint32 displayID);
```

**Description:**
GetDisplayInfoData() fills a buffer with data meaningful to the
DisplayInfoRecord pointed at by your valid handle. The data type
that you are interested in is indicated by a tagID for that chunk.
The types of tagged information that may be available include:

DTAG_DISP: (DisplayInfo)   - properties and availability information.
DTAG_DIMS: (DimensionInfo) - default dimensions and overscan info.
DTAG_MNTR: (MonitorInfo)   - type, position, scanrate, and
                      compatibility.
DTAG_NAME: (NameInfo)      - a user friendly way to refer to this
                      mode.

**Inputs:**
handle    - displayinfo handle (may be NULL)
buf       - pointer to destination buffer
size      - buffer size in bytes
tagID     - data chunk type
displayID - displayinfo identifier, optionally used if handle is NULL

**Result:**
result - if positive, number of bytes actually transferred
  if zero, no information for ID was available

**See also:** FindDisplayInfo(), NextDisplayInfo()
graphics/displayinfo.h

---

### graphics.library/GetDrMd (V39)

**Get the draw mode value for a RastPort.**

**Synopsis:**
```c
mode = GetDrMd  ( rp )

ULONG GetDrMd(struct RastPort *)
```

**Description:**
Return the current value of the draw mode for the rastport. This
function should be used instead of peeking the structure directly,
because future graphics devices may store it differently.

**Inputs:**
rp  =  a pointer to a valid RastPort structure.

**Result:**
mode - the draw mode of the RastPort.

**Notes:**


**Bugs:**


**See also:** SetDrMd() graphics/gfx.h

---

### graphics.library/GetExtSpriteA (V39)

**Attempt to get a sprite for the extended sprite
          manager.GetExtSprite -- varargs stub for GetExtSpriteA.**

**Synopsis:**
```c
Sprite_Number = GetExtSpriteA( sprite, tags )

LONG GetExtSpriteA( struct ExtSprite *, CONST struct TagItem * );

spritenum = GetExtSprite(sprite, tag1, ...);
```

**Description:**
Attempt to allocate one of the eight sprites for private use
with the extended sprite manager.

**Inputs:**
sprite - ptr to programmer's ExtSprite (from AllocSpriteData()).
tags   - a standard tag list:

GSTAG_SPRITE_NUM specifies a specific sprite to get by number.

GSTAG_ATTACHED specifies that you wish to get a sprite pair.
the tag data field points to a ExtSprite structure
for the second sprite. You must free both sprites.

**Result:**
Sprite_number - a sprite number or -1 for an error.

**Notes:**
This call will fail if no sprites could be allocated, or
if you try to allocate a sprite which would require
a mode change when there are other sprites of incompatible
modes in use.

**Bugs:**
GSTAG_ATTACHED does not work in version 39. When running under V39,
you should attach the second sprite with a separate GetExtSprite
call.

**See also:** FreeSprite() ChangeSprite() MoveSprite() GetSprite()
graphics/sprite.h

---

### graphics.library/GetGBuffers

**Attempt to allocate ALL buffers of an entire AnimOb.**

**Synopsis:**
```c
status = GetGBuffers(anOb, rp, db)

BOOL GetGBuffers(struct AnimOb *, struct RastPort *, BOOL);
```

**Description:**
For each sequence of each component of the AnimOb,
allocate memory for:
    SaveBuffer
    BorderLine
    CollMask and ImageShadow (point to same buffer)
    if db is set TRUE (user wants double-buffering) allocate:
        DBufPacket
        BufBuffer

**Inputs:**
anOb - pointer to the AnimOb structure
rp   - pointer to the current RastPort
db   - double-buffer indicator (set TRUE for double-buffering)

**Result:**
status - TRUE if the memory allocations were all successful,
         else FALSE

**Bugs:**
If any of the memory allocations fail it does not free the partial
allocations that did succeed.

**See also:** FreeGBuffers() graphics/gels.h

---

### graphics.library/GetOutlinePen (V39)

**Get the Outline-Pen value for a RastPort.**

**Synopsis:**
```c
pen = GetOutlinePen  ( rp )

ULONG GetOutlinePen(struct RastPort *)
```

**Description:**
Return the current value of the O pen for the rastport. This function
should be used instead of peeking the structure directly, because
future graphics devices may store it differently, for instance,
using more bits.

**Inputs:**
rp  =  a pointer to a valid RastPort structure.

**Result:**
pen - the Outline-Pen value of the RastPort.

**Notes:**


**Bugs:**


**See also:** SetOutlinePen() graphics/gfx.h

---

### graphics.library/GetRGB32 (V39)

**Get a series of color registers for this Viewport.**

**Synopsis:**
```c
GetRGB32( cm,  firstcolor, ncolors, table )

VOID GetRGB32( CONST struct ColorMap *, UWORD, UWORD, ULONG *);
```

**Inputs:**
cm = colormap
firstcolor = the first color register to get
ncolors = the number of color registers to set.
table=a pointer to a series of 32-bit RGB triplets.

**Result:**
The ULONG data pointed to by 'table' will be filled with the 32 bit
fractional RGB values from the colormap.

**Notes:**
'Table' should point to at least ncolors*3 longwords.

**Bugs:**
Prior to V46 this function did ignore the LowColorBits on
non-AGA machines.

**See also:** LoadRGB4() GetColorMap() LoadRGB32() SetRGB32CM() graphics/view.h

---

### graphics.library/GetRGB4

**Inquire value of entry in ColorMap.**

**Synopsis:**
```c
value = GetRGB4( colormap, entry )

LONG GetRGB4(struct ColorMap *, UWORD);
```

**Description:**
Read and format a value from the ColorMap.

**Inputs:**
colormap - pointer to ColorMap structure
entry    - index into colormap

**Result:**
returns -1 if no valid entry
return UWORD RGB value 4 bits per gun right justified

**Notes:**
Intuition's DisplayBeep() changes color 0. Reading Color 0 during a
DisplayBeep() will lead to incorrect results.

**Bugs:**


**See also:** SetRGB4() LoadRGB4() GetColorMap() FreeColorMap() graphics/view.h

---

### graphics.library/GetRPAttrsA

**examine rastport settings via a tag list
GetRPAttrs  -- varargs stub for GetRPAttrsA**

**Synopsis:**
```c
GetRPAttrsA(rp, tags)

uint32 GetRPAttrsA(struct RastPort *, CONST struct TagItem *);

GetRPAttrs(rp, attr1, &result1, ...);
```

**Description:**
Read the settings of a rastport into variables. The
ti_Tag field of the TagItem specifies which attribute
should be read, and the ti_Data field points at the
location where the result should be stored. All current
tags store the return data as LONGs (32 bits).

currently available tags are:

RPTAG_Font        Font for Text()
RPTAG_APen        Primary rendering pen
RPTAG_BPen        Secondary rendering pen
RPTAG_DrMd        Drawing mode (see graphics/rastport.h)
RPTAG_OutlinePen  Area Outline pen
RPTAG_WriteMask   Bit Mask for writing.
RPTAG_MaxPen      Maximum pen to render (see SetMaxPen())
RPTAG_DrawBounds  Determine the area that will be rendered
                  into by rendering commands. Can be used
                  to optimize window refresh. Pass a pointer
                  to a rectangle in the tag data. On return,
                  the rectangle's MinX will be greater than
                  its MaxX if there are no active cliprects.

Tags introduced in V51:

RPTAG_APenColor   Primary rendering color (0xaarrggbb)
RPTAG_BPenColor   Secondary rendering color (0xaarrggbb)
RPTAG_OPenColor   Area outline color (0xaarrggbb)
RPTAG_RemapColorFonts  Make use of ColorTextFont->ColorFontColors
 to render color fonts (boolean).

Tags introduced in V51:
RPTAG_XPos        Get X Position in Rastport.
RPTAG_YPos        Get Y Position in Rastport.

**Inputs:**
rp   - pointer to the RastPort to examine.
tags - a standard tag list specifying the attributes to be read,
       and where to store their values.

**Result:**
Returned the number of handled Tags.

**Bugs:**
Before 54.126 it always returned Zero, now it returns the number
of handled tags.

**See also:** GetAPen() GetBPen() GetDrMd() GetOutLinePen()
GetWriteMask() SetRPAttrsA() graphics/rpattr.h

---

### graphics.library/GetSprite

**Attempt to get a sprite for the simple sprite manager.**

**Synopsis:**
```c
Sprite_Number = GetSprite( sprite, pick )

WORD GetSprite( struct SimpleSprite *, WORD );
```

**Description:**
Attempt to allocate one of the eight sprites for private use
with the simple sprite manager. This must be done before using
further calls to the simple sprite machine. If the programmer
wants to use 15 color sprites, they must allocate both sprites
and set the 'SPRITE_ATTACHED' bit in the odd sprite's posctldata
array.

**Inputs:**
sprite - ptr to programmers SimpleSprite structure.
pick - number in the range of 0-7 or
  -1 if programmer just wants the next one.

**Result:**
If pick is 0-7 attempt to allocate the sprite. If the sprite
is already allocated then return -1.
If pick -1 allocate the next sprite starting search at 0.
If no sprites are available return -1 and fill -1 in num entry
of SimpleSprite structure.
If the sprite is available for allocation, mark it allocated
and fill in the 'num' entry of the SimpleSprite structure.
If successful return the sprite number.

**Bugs:**


**See also:** FreeSprite() ChangeSprite() MoveSprite() GetSprite()
graphics/sprite.h

---

### graphics.library/GetVPModeID (V36)

**get the 32 bit DisplayID from a ViewPort.**

**Synopsis:**
```c
uint32 modeID = GetVPModeID(CONST struct ViewPort *vp);
```

**Description:**
returns the normal display modeID, if one is currently associated
with this ViewPort.

**Inputs:**
vp -- pointer to a ViewPort structure.

**Result:**
modeID -- a 32 bit DisplayInfoRecord identifier associated with
   this ViewPort or INVALID_ID.

**Notes:**
Test the return value of this function against INVALID_ID, not NULL.
(INVALID_ID is defined in graphics/modeid.h).

**Bugs:**


**See also:** graphics/displayinfo.h, ModeNotAvailable()

---

### graphics.library/GfxAssociate (V36)

**associate a graphics extended node
                with a given pointer**

**Synopsis:**
```c
GfxAssociate(pointer, node);

VOID GfxAssociate(CONST APTR, struct ExtendedNode *);
```

**Description:**
Associate a special graphics extended data structure (each of which
begins with an ExtendedNode structure)  with another structure via
the other structure's pointer. Later, when you call GfxLookUp()
with the other structure's pointer you may retrieve a pointer
to this special graphics extended data structure, if it is
available.

**Inputs:**
pointer = a pointer to a data structure.
node = an ExtendedNode structure to associate with the pointer

**Result:**
an association is created between the pointer and the node such
that given the pointer the node can be retrieved via GfxLookUp().

**Bugs:**


**See also:** graphics/gfxnodes.h GfxNew() GfxFree() GfxLookUp()

---

### graphics.library/GfxFree (V36)

**free a graphics extended data structure**

**Synopsis:**
```c
GfxFree( node );

VOID GfxFree(struct ExtendedNode *);
```

**Description:**
Free a special graphics extended data structure (each of which
begins with an ExtendedNode structure).

**Inputs:**
node = pointer to a graphics extended data structure obtained via
       GfxNew().

**Result:**
the node is deallocated from memory. graphics will disassociate
this special graphics extended node from any associated data
structures, if necessary, before freeing it (see GfxAssociate()).

**Bugs:**
an Alert() will be called if you attempt to free any structure
other than a graphics extended data structure obtained via GfxFree().

**See also:** graphics/gfxnodes.h GfxNew() GfxAssociate() GfxLookUp()

---

### graphics.library/GfxLookUp (V36)

**find a graphics extended node associated with a
             given pointer**

**Synopsis:**
```c
result = GfxLookUp( pointer );

APTR GfxLookUp( CONST APTR );
```

**Description:**
Finds a special graphics extended data structure (if any) associated
with the pointer to a data structure (eg: ViewExtra associated with
a View structure).

**Inputs:**
pointer = a pointer to a data structure which may have an
          ExtendedNode associated with it (typically a View ).

**Result:**
result = a pointer to the ExtendedNode that has previously been
         associated with the pointer.

**Bugs:**


**See also:** graphics/gfxnodes.h GfxNew() GfxFree() GfxAssociate()

---

### graphics.library/GfxNew (V36)

**allocate a graphics extended data structure**

**Synopsis:**
```c
struct ExtendedNode *result = GfxNew(uint32 node_type);
```

**Description:**
Allocate a special graphics extended data structure (each of which
begins with an ExtendedNode structure).  The type of structure to
be allocated is specified by the node_type identifier.

**Inputs:**
node_type - which type of graphics extended data structure to
     allocate. (see gfxnodes.h for identifier definitions.)

**Result:**
result - a pointer to the allocated graphics node or NULL if the
  allocation failed.

**Bugs:**


**See also:** graphics/gfxnodes.h GfxFree() GfxAssociate() GfxLookUp()

---

### graphics.library/InitArea

**Initialize vector collection matrix**

**Synopsis:**
```c
InitArea( areainfo, buffer, maxvectors )

VOID InitArea(struct AreaInfo *, APTR, WORD);
```

**Description:**
This function provides initialization for the vector collection
matrix such that it has a size of (max vectors ).  The size of the
region pointed to by buffer (short pointer) should be five (5) times
as large as maxvectors. This size is in bytes.  Areafills done by
using AreaMove, AreaDraw, and AreaEnd must have enough space
allocated in this table to store all the points of the largest fill.
AreaEllipse takes up two vectors for every call. If
AreaMove/Draw/Ellipse detect too many vectors going into the buffer
they will return -1.

**Inputs:**
areainfo   - pointer to AreaInfo structure
buffer     - pointer to chunk of memory to collect vertices
maxvectors - max number of vectors this buffer can hold

**Result:**
Pointers are set up to begin storage of vectors done by
AreaMove, AreaDraw, and AreaEllipse.

**Bugs:**


**See also:** AreaEnd() AreaMove() AreaDraw() AreaEllipse() graphics/rastport.h

---

### graphics.library/InitBitMap

**Initialize bit map structure with input values.**

**Synopsis:**
```c
InitBitMap( bm, depth, width, height )

VOID InitBitMap( struct BitMap *, BYTE, UWORD, UWORD );
```

**Description:**
Initialize various elements in the BitMap structure to
correctly reflect depth, width, and height.
Must be used before use of BitMap in other graphics calls.
The Planes[8] are not initialized and need to be set up
by the caller.  The Planes table was put at the end of the
structure so that it may be truncated to conserve space,
as well as extended. All routines that use BitMap should
only depend on existence of depth number of bitplanes.
The Flags and pad fields are reserved for future use and
should not be used by application programs.

**Inputs:**
bm - pointer to a BitMap structure (gfx.h)
depth - number of bitplanes that this bitmap will have
width - number of bits (columns) wide for this BitMap
height- number of bits (rows) tall for this BitMap

**Bugs:**


**See also:** graphics/gfx.h

---

### graphics.library/InitGels

**initialize a gel list; must be called before using gels.**

**Synopsis:**
```c
InitGels(head, tail, GInfo)

VOID InitGels(struct VSprite *, struct VSprite *, struct GelsInfo *);
```

**Description:**
Assigns the VSprites as the head and tail of the gel list in GfxBase.
Links these two gels together as the keystones of the list.
If the collHandler vector points to some memory array, sets
the BORDERHIT vector to NULL.

**Inputs:**
head  - pointer to the VSprite structure to be used as gel list head
tail  - pointer to the VSprite structure to be used as gel list tail
GInfo - pointer to the GelsInfo structure to be initialized

**Result:**


**Bugs:**


**See also:** graphics/gels.h  graphics/rastport.h

---

### graphics.library/InitGMasks

**Initialize all of the masks of an AnimOb.**

**Synopsis:**
```c
InitGMasks(anOb)

VOID InitGMasks(struct AnimOb *);
```

**Description:**
For every sequence of every component call InitMasks.

**Inputs:**
anOb = pointer to the AnimOb

**Bugs:**


**See also:** InitMasks() graphics/gels.h

---

### graphics.library/InitMasks

**Initialize the BorderLine and CollMask masks
             of a VSprite.**

**Synopsis:**
```c
InitMasks(vs)

VOID InitMasks(struct VSprite *);
```

**Description:**
Creates the appropriate BorderLine and CollMask masks of the VSprite.
Correctly detects if the VSprite is actually a Bob definition,
handles the image data accordingly.

**Inputs:**
vs = pointer to the VSprite structure

**Result:**


**Bugs:**


**See also:** InitGels() graphics/gels.h

---

### graphics.library/InitRastPort

**Initialize raster port structure**

**Synopsis:**
```c
InitRastPort( rp )

VOID InitRastPort(struct RastPort *rp);
```

**Description:**
Initialize a RastPort structure to standard values.

**Inputs:**
rp - pointer to a RastPort structure.

**Result:**
all entries in RastPort get zeroed out,
with the following exceptions:

    Mask, FgPen, AOLPen, and LinePtrn are set to -1.
    The DrawMode is set to JAM2
    The font is set to the standard system font

**Notes:**
The struct Rastport describes a control structure
for a write-able raster. The RastPort structure
describes how a complete single playfield display
will be written into. A RastPort structure is
referenced whenever any drawing or filling
operations are to be performed on a section of
memory.

The section of memory which is being used in this
way may or may not be presently a part of the
current actual onscreen display memory. The name
of the actual memory section which is linked to
the RastPort is referred to here as a "raster" or
as a bitmap.

NOTE: Calling the routine InitRastPort only
establishes various defaults. It does NOT
establish where, in memory, the rasters are
located. To do graphics with this RastPort the user
must set up the BitMap pointer in the RastPort.

**Bugs:**


**See also:** graphics/rastport.h

---

### graphics.library/InitTmpRas

**Initialize area of local memory for usage by
    areafill, floodfill, text.**

**Synopsis:**
```c
struct TmpRas *InitTmpRas(struct TmpRas *tmpras, PLANPTR buffer,
                          int32 size);
```

**Description:**
The area of memory pointed to by buffer is set up to be used
by RastPort routines that may need to get some memory for
intermediate operations in preparation to putting the graphics
into the final BitMap.

Tmpras is used to control the usage of buffer.

**Inputs:**
tmpras - pointer to a TmpRas structure to be linked into
         a RastPort
buffer - pointer to a contiguous piece of chip memory.
size   - size in bytes of buffer

**Result:**
Pointer to the same struct TmpRas passed in.

**Bugs:**
Would be nice if RastPorts could share one TmpRas.

**See also:** AreaEnd() Flood() Text() graphics/rastport.h

---

### graphics.library/InitView

**Synopsis:**
```c
InitView( view )

VOID InitView( struct View * );
```

**Description:**
Initialize View structure to default values.

**Inputs:**
view - pointer to a View structure

**Result:**
View structure set to all 0's. (1.0,1.1.1.2)
Then values are put in DxOffset,DyOffset to properly position
default display about .5 inches from top and left on monitor.
InitView pays no attention to previous contents of view.

**Bugs:**


**See also:** MakeVPort graphics/view.h

---

### graphics.library/InitVPort

**Synopsis:**
```c
InitVPort( vp )

VOID InitViewPort( struct ViewPort * );
```

**Description:**
Initialize ViewPort structure to default values.

**Inputs:**
vp - pointer to a ViewPort structure

**Result:**
ViewPort structure set to all 0's. (1.0,1.1)
New field added SpritePriorities, initialized to 0x24 (1.2)

**Bugs:**


**See also:** MakeVPort() graphics/view.h

---

### graphics.library/LoadRGB32 (V39)

**Set a series of color registers for this Viewport.**

**Synopsis:**
```c
VOID LoadRGB32(struct ViewPort *vp, CONST uint32 *table);
```

**Inputs:**
vp    - viewport
table - a pointer to a series of records which describe which
 colors to modify.

**Result:**
The selected color registers are changed to match your specs.

**Notes:**
Passing a NULL "table" is ignored.
The format of the table passed to this function is a series of
records, each with the following format:

 1 Word with the number of colors to load
 1 Word with the first color to be loaded.
 3 longwords representing a left justified 32 bit rgb triplet.
 The list is terminated by a count value of 0.

   examples:
      uint32 table[] = {1 << 16 + 0, 0xffffffff, 0, 0, 0}
      loads color register 0 with 100% red.

      uint32 table[] = {256 << 16 + 0, r1, g1, b1, r2, g2, b2, .....0}
      can be used to load an entire 256 color palette.

Lower order bits of the palette specification will be discarded,
depending on the color palette resolution of the target graphics
device. Use 0xffffffff for the full value, 0x7fffffff for 50%,
etc. You can find out the palette range for your screen by
querying the graphics data base.

LoadRGB32 is faster than SetRGB32, even for one color.

**Bugs:**


**See also:** LoadRGB4() GetColorMap() GetRGB32() SetRGB32CM() graphics/view.h

---

### graphics.library/LoadRGB4

**Load RGB color values from table.**

**Synopsis:**
```c
VOID LoadRGB4(struct ViewPort *vp, CONST uint16 *colors, uint16 count);
```

**Description:**
load the count words of the colormap from table starting at
entry 0.

**Inputs:**
vp     - pointer to ViewPort, whose colors you wish to change
colors - pointer to table of RGB values set up as an array
  of UWORDS:
  background --  0x0RGB
  color1     --  0x0RGB
  color2     --  0x0RGB
  etc.           uint16 per value.
  The colors are interpreted as 15 = maximum intensity.
                                 0 = minimum intensity.
count  - number of uint16's the table to load into the
  colormap starting at color 0(background) and proceeding
  to the next higher color number

**Result:**
The ViewPort should have a pointer to a valid ColorMap to store
the colors in.

On classic Amigas, updates the hardware copperlist to reflect the
new colors. Updates the intermediate copperlist with the new colors.

**Notes:**
Under V36 and up, it is not safe to call this function
from an interrupt, due to semaphore protection of graphics
copper lists.

**Bugs:**


**See also:** SetRGB4() GetRGB4() GetColorMap() graphics/view.h

---

### graphics.library/LoadView

**Use a (possibly freshly created) coprocessor instruction
     list to create the current display.**

**Synopsis:**
```c
LoadView( View )

VOID LoadView( struct View * );
```

**Description:**
Install a new view to be displayed during the next display
refresh pass.
Coprocessor instruction list has been created by
InitVPort(), MakeVPort(), and MrgCop().

**Inputs:**
View - a pointer to the View structure which contains the
pointer to the constructed coprocessor instructions list, or NULL.

**Result:**
If the View pointer is non-NULL, the new View is displayed,
according to your instructions.  The vertical blank routine
will pick this pointer up and direct the copper to start
displaying this View.

If the View pointer is NULL, no View is displayed.

**Notes:**
Even though a LoadView(NULL) is performed, display DMA will still be
active.  Sprites will continue to be displayed after a LoadView(NULL)
unless an OFF_SPRITE is subsequently performed.

**Bugs:**


**See also:** InitVPort() MakeVPort() MrgCop() intuition/RethinkDisplay()
graphics/view.h

---

### graphics.library/LockLayerRom

**Lock Layer structure by ROM(gfx lib) code.**

**Synopsis:**
```c
LockLayerRom( layer )

VOID LockLayerRom( struct Layer * );
```

**Description:**
Return when the layer is locked and no other task may
alter the ClipRect structure in the Layer structure.
This call does not destroy any registers.
This call nests so that callers in this chain will not lock
themselves out.
Do not have the Layer locked during a call to intuition.
There is a potential deadlock problem here, if intuition
needs to get other locks as well.
Having the layer locked prevents other tasks from using the
layer library functions, most notably intuition itself. So
be brief.
layers.library's LockLayer is identical to LockLayerRom.

**Inputs:**
layer - pointer to Layer structure

**Result:**
The layer is locked and the task can render assuming the
ClipRects will not change out from underneath it until
an UnlockLayerRom is called.

**Notes:**
Since V50, this is a C function, which destroys registers
However, registers are preserved when called from 68k.

**See also:** UnlockLayerRom() layers.library/LockLayer() graphics/clip.h

---

### graphics.library/MakeVPort

**generate display copper list for a viewport.**

**Synopsis:**
```c
uint32 error = MakeVPort(struct View *view, struct ViewPort *viewport);
```

**Description:**
Uses information in the View, ViewPort, ViewPort->RasInfo to
construct and intermediate copper list for this ViewPort.

**Inputs:**
view - pointer to a View structure
viewport - pointer to a ViewPort structure
	 The viewport must have valid pointer to a RasInfo.

**Result:**
constructs intermediate copper list and puts pointers in
viewport.DspIns
If the ColorMap ptr in ViewPort is NULL then it uses colors
from the default color table.
If DUALPF in Modes then there must be a second RasInfo pointed
to by the first RasInfo

From V39, MakeVPort can return a uint32 error value (previous versions
returned VOID), to indicate that either not enough memory could be
allocated for MakeVPort's use, or that the ViewPort mode
and bitplane alignments are incorrect for the bitplane's depth.

You should check for these error values - they are defined in
graphics/view.h.

**Bugs:**
In V37 and earlier, narrow Viewports (whose righthand edge is
less than 3/4 of the way across the display) do not work properly.

**See also:** InitVPort() MrgCop() graphics/view.h intuition.library/MakeScreen()
intuition.library/RemakeDisplay() intuition.library/RethinkDisplay()

---

### graphics.library/ModeNotAvailable (V36)

**check if a DisplayID is not available.**

**Synopsis:**
```c
uint32 error = ModeNotAvailable(uint32 modeID);
```

**Description:**
Returns an error code indicating why this modeID is not available
or NULL if there is no reason known why this mode should not be
there.

**Inputs:**
modeID -- A 32 bit display mode ID.

**Result:**
error -- A general indication of why this modeID is not available
  or NULL if there is no reason why it shouldn't be available.

**Notes:**
Return values from this function are a proper superset of the
DisplayInfo.NotAvailable field (defined in graphics/displayinfo.h).

ModeNotAvailable() will return INVALID_ID when given a non-existant
mode ID.

**Bugs:**


**See also:** graphics/displayinfo.h, GetVPModeID()

---

### graphics.library/Move

**Move graphics pen position.**

**Synopsis:**
```c
Move( rp,   x,    y)

VOID Move( struct RastPort *, WORD, WORD );
```

**Description:**
Move graphics pen position to (x,y) relative to upper left (0,0)
of RastPort. This sets the starting point for subsequent Draw()
and Text() calls.

**Inputs:**
rp - pointer to a RastPort structure
x,y - point in the RastPort

**Result:**


**Bugs:**


**See also:** Draw() graphics/rastport.h

---

### graphics.library/MoveSprite

**Move sprite to a point relative to top of viewport.**

**Synopsis:**
```c
MoveSprite(vp, sprite, x, y)

VOID MoveSprite(struct ViewPort *,struct SimpleSprite *, WORD, WORD);
```

**Description:**
Move sprite image to new place on display.

**Inputs:**
vp - pointer to ViewPort structure
     if vp = 0, sprite is positioned relative to View.
sprite - pointer to SimpleSprite structure
(x,y)  - new position relative to top of viewport or view.

**Result:**
Calculate the hardware information for the sprite and
place it in the posctldata array. During next video display
the sprite will appear in new position.

**Bugs:**
Sprites really appear one pixel to the left of the position you
specify. This bug affects the apparent display position of the
sprite on the screen, but does not affect the numeric position
relative to the viewport or view. This behaviour only applies to
SimpleSprites, not to ExtSprites.

**See also:** FreeSprite()  ChangeSprite()  GetSprite()  graphics/sprite.h

---

### graphics.library/MrgCop

**Merge together coprocessor instructions.**

**Synopsis:**
```c
uint32 error = MrgCop(struct View *view);
```

**Description:**
Merge together the display, color, sprite and user coprocessor
instructions into a single coprocessor instruction stream.  This
essentially creates a per-display-frame program for the coprocessor.
This function MrgCop is used, for example, by the graphics animation
routines which effectively add information into an essentially
static background display.  This changes some of the user
or sprite instructions, but not those which have formed the
basic display in the first place.  When all forms of coprocessor
instructions are merged together, you will have a complete per-
frame instruction list for the coprocessor.

Restrictions:  Each of the coprocessor instruction lists MUST be
internally sorted in min to max Y-X order.  The merge routines
depend on this! Each list must be terminated using CEND(copperlist).

**Inputs:**
view - a pointer to the view structure whose coprocessor
instructions are to be merged.

**Result:**
The view structure will now contain a complete, sorted/merged
list of instructions for the coprocessor, ready to be used by
the display processor.  The display processor is told to use
this new instruction stream through the instruction LoadView().

From V39, MrgCop() can return a uint32 error value (previous versions
returned VOID), to indicate that either there was insufficient memory
to build the system copper lists, or that MrgCop() had no work to do
if, for example, there were no ViewPorts in the list.

You should check for these error values - they are defined in
graphics/view.h.

**Bugs:**


**See also:** InitVPort() MakeVPort() LoadView() graphics/view.h
intuition.library/RethinkDisplay()

---

### graphics.library/NewRegion

**Get an empty region.**

**Synopsis:**
```c
region = NewRegion()

struct Region *NewRegion();
```

**Description:**
Create a Region structure, initialize it to empty, and return
a pointer it.

**Inputs:**
none

**Result:**
region - pointer to initialized region. If it could not allocate
         required memory region = NULL.

**Bugs:**


**See also:** graphics/regions.h

---

### graphics.library/NextDisplayInfo (V36)

**iterate current displayinfo identifiers**

**Synopsis:**
```c
uint32 next_ID = NextDisplayInfo(uint32 last_ID);
```

**Description:**
The basic iteration function with which to find all records in the
graphics database. Using each ID in succession, you can then call
FindDisplayInfo() to obtain the handle associated with each ID.
Each ID is a 32-bit Key which uniquely identifies one record.
The INVALID_ID is special, and indicates the end-of-list.

**Inputs:**
last_ID - previous displayinfo identifier
          or INVALID_ID if beginning iteration.

**Result:**
next_ID - subsequent displayinfo identifier
          or INVALID_ID if no more records.

**Bugs:**


**See also:** FindDisplayInfo(), GetDisplayInfoData()
graphics/displayinfo.h

---

### graphics.library/ObtainBestPenA (V39)

**- Search for the closest color match, or allocate a
            new one.ObtainBestPen  --- varargs stub for ObtainBestPenA**

**Synopsis:**
```c
color | -1 = ObtainBestPenA( cm, R, G, B, taglist)

LONG ObtainBestPenA( struct ColorMap *, ULONG, ULONG,
		ULONG, CONST struct TagItem *);

color = ObtainBestPen(cm, r, g, b, tag1, ...);
```

**Description:**
This function can be used by applications to figure out
what pen to use to represent a given color.

The system will attempt to find the color in your viewport closest
to the specified color. If there is no color within your tolerance,
then a new one will be allocated, if available. If none is available,
then the closest one found will be returned.

**Inputs:**
cm = colormap
R = red level   (32 bit left justified fraction)
G = green level (32 bit left justified fraction)
B = blue level  (32 bit left justified fraction)
taglist = a pointer to a standard tag list specifying the color
   matching settings desired:

OBP_Precision - specifies the desired precision for the
         match. Should be PRECISION_GUI, PRECISION_ICON, or
         PRECISION_IMAGE or PRECISION_EXACT.
         Defaults to PRECISION_IMAGE.

OBP_FailIfBad - specifies that you want ObtainBestPen to return
         a failure value if there is not a color within the
         given tolerance, instead of returning the closest
         color. With OBP_FailIfBad==FALSE, ObtainBestPen will
         only fail if the ViewPort contains no sharable
         colors. Defaults to FALSE.

**Result:**
The correct pen value, or -1 if no sharable palette entries are
available.

**Notes:**
If this call succceeds, then you must call ReleasePen() when you are
done with the color.

The error metric used for ObtainBestPen() is based on the magnitude
squared between the two RGB values, scaled by the percentage of free
entries.

**Bugs:**


**See also:** GetColorMap() ObtainPen() ReleasePen()

---

### graphics.library/ObtainPen (V39)

**Obtain a free palette entry
             for use by your program.**

**Synopsis:**
```c
n = ObtainPen( cm, n, r, g, b, flags)

LONG ObtainPen(struct ColorMap *, LONG, ULONG, ULONG, ULONG, ULONG);
```

**Description:**
Attempt to allocate an entry in the colormap for use by the
application. If successful, you should ReleasePen() this entry
after you have finished with it.

Applications needing exclusive use of a color register (say for
color cycling) will typically call this function with n = -1.
Applications needing only the shared use of a color will typically
use ObtainBestPenA() instead. Other uses of this function are rare.

**Inputs:**
cm    -  A pointer to a color map created by GetColorMap().
n     -  The index of the desired entry, or -1 if any one is
         acceptable.
rgb   -  The RGB values (32 bit left justified fractions) to set the
         new palette entry to.
flags - PENF_EXCLUSIVE - tells the system that you want exclusive
        (non-shared) use of this pen value. Default is shared access.

        PENF_NO_SETCOLOR - tells the system to not change the rgb
        values for the selected pen. Really only makes sense for
        exclusive pens.

**Result:**
n  - The allocated pen. -1 will be returned if there is no pen
     available for you.

**Notes:**
When you allocate a palette entry in non-exclusive mode, you
should not change it (via SetRGB32), because other programs on the
same screen may be using it. With PEN_EXCLUSIVE mode, you can
change the returned entry at will.

To avoid visual artifacts, you should not free up a palette
entry until you are sure that your application is not displaying
any pixels in that color at the time you free it. Otherwise, another
task could allocate and set that color index, thus changing the
colors of your pixels.

Generally, for shared access, you should use ObtainBestPenA()
instead, since it will not allocate a new color if there is one
"close enough" to the one you want already.
If there is no Palextra attached to the colormap, then this
routine will always fail.

**Bugs:**


**See also:** GetColorMap() ReleasePen() AttachPalExtra() ObtainBestPenA()

---

### graphics.library/OpenFont

**Get a pointer to a system font.**

**Synopsis:**
```c
font = OpenFont(textAttr)

    struct TextFont *OpenFont(CONST struct TextAttr *);
```

**Description:**
This function searches the system font space for the graphics
    text font that best matches the attributes specified.  The
    pointer to the font returned can be used in subsequent
    SetFont and CloseFont calls.  It is important to match this
    call with a corresponding CloseFont call for effective
    management of ram fonts.

**Inputs:**
textAttr - a TextAttr or TTextAttr structure that describes the
        text font attributes desired.

**Result:**
font is zero if the desired font cannot be found.  If the named
    font is found, but the size and style specified are not
    available, a font with the nearest attributes is returned.

**Notes:**
Prior to V46 this function used case sensitive font names.
    It is not necessary to call ExtendFont() for the returned
    font, OpenFont() only returns successfully extended fonts.

**Bugs:**
Prior to V39 this function would return a TextFont pointer
    for any font which matched exactly in Y size, regardless of
    differences in DPI, or DotSize.

    	As part of fixing this bug it is REQUIRED that you use pass the
    	same TextAttr (or TTextAttr) to this function that was used when
    	OpenDiskFont() was called.

    	OpenFont(), and OpenDiskFont() use WeighTAMatch() to measure
    	how well two fonts match.  WeightTAMatch() was a public function
    	in graphics.library V36-V37; it is now a system PRIVATE function
    	as of V39.

**See also:** CloseFont()  SetFont()
    	diskfont.library/OpenDiskFont()  graphics/text.h
    	intuition/intuition.h

---

### graphics.library/OpenMonitor (V36)

**open a named MonitorSpec**

**Synopsis:**
```c
mspc = OpenMonitor( monitor_name , display_id)

struct MonitorSpec *OpenMonitor( CONST_STRPTR, ULONG );
```

**Description:**
Locate and open a named MonitorSpec.

**Inputs:**
monitor_name - a pointer to a null terminated string.
display_id - an optional 32 bit monitor/mode identifier

**Result:**
mspc - a pointer to an open MonitorSpec structure.
       NULL if MonitorSpec could not  be opened.

**Notes:**
if monitor_name is non-NULL, the monitor will be opened by name.
if monitor_name is NULL the monitor will be opened by optional ID.
if both monitor_name and display_id are NULL returns default monitor.

**Bugs:**


**See also:** CloseMonitor() graphics/monitor.h

---

### graphics.library/OrRectRegion

**Perform 2d OR operation of rectangle
                with region, leaving result in region.**

**Synopsis:**
```c
status = OrRectRegion(region, rectangle)

BOOL OrRectRegion( struct Region *, CONST struct Rectangle * );
```

**Description:**
If any portion of rectangle is not in the region then add
that portion to the region.

**Inputs:**
region - pointer to Region structure
rectangle - pointer to Rectangle structure

**Result:**
status - return TRUE if successful operation
         return FALSE if ran out of memory

**Bugs:**


**See also:** AndRectRegion() OrRegionRegion() graphics/regions.h

---

### graphics.library/OrRegionRegion

**Perform 2d OR operation of one region
                with second region, leaving result in second region**

**Synopsis:**
```c
status = OrRegionRegion(region1, region2)

BOOL OrRegionRegion( CONST struct Region *, struct Region * );
```

**Description:**
If any portion of region1  is not in the region then add
that portion to the region2

**Inputs:**
region1 - pointer to Region structure
region2 - pointer to Region structure

**Result:**
status - return TRUE if successful operation
         return FALSE if ran out of memory

**Bugs:**


**See also:** OrRectRegion() XorRegionRegion() graphics/regions.h

---

### graphics.library/OwnBlitter

**get the blitter for private usage**

**Synopsis:**
```c
OwnBlitter()

VOID OwnBlitter( VOID );
```

**Description:**
If blitter is available return immediately with the blitter
locked for your exclusive use. If the blitter is not available
put task to sleep. It will be awakened as soon as the blitter
is available. When the task first owns the blitter the blitter
may still be finishing up a blit for the previous owner. You
must do a WaitBlit before actually using the blitter registers.

Calls to OwnBlitter() do not nest. If a task that owns the
blitter calls OwnBlitter() again, a lockup will result.
(Same situation if the task calls a system function
that tries to own the blitter).

**Inputs:**
NONE

**Result:**
NONE

**See also:** DisownBlitter() WaitBlit()

---

### graphics.library/PolyDraw

**Draw lines from table of (x,y) values.**

**Synopsis:**
```c
PolyDraw( rp, count , array )

VOID PolyDraw( struct RastPort *, WORD, CONST WORD * );
```

**Description:**
starting with the first pair in the array, draw connected lines to
it and every successive pair.

**Inputs:**
rp    - pointer to RastPort structure
count - number of (x,y) pairs in the array
array - pointer to first (x,y) pair

**Bugs:**


**See also:** Draw() Move() graphics/rastport.h

---

### graphics.library/QBlit

**Queue up a request for blitter usage**

**Synopsis:**
```c
QBlit( bp )

VOID QBlit( struct bltnode * );
```

**Description:**
Link a request for the use of the blitter to the end of the
current blitter queue.  The pointer bp points to a blit structure
containing, among other things, the link information, and the
address of your routine which is to be called when the blitter
queue finally gets around to this specific request.  When your
routine is called, you are in control of the blitter ... it is
not busy with anyone else's requests.  This means that you can
directly specify the register contents and start the blitter.
See the description of the blit structure and the uses of QBlit
in the section titled Graphics Support in the OS Kernel Manual.
Your code must be written to run either in supervisor or user
mode on the 68000.

**Inputs:**
bp - pointer to a blit structure

**Result:**
Your routine is called when the blitter is ready for you.
In general requests for blitter usage through this channel are
put in front of those who use the blitter via OwnBlitter and
DisownBlitter. However for small blits there is more overhead
using the queuer than Own/Disown Blitter.

**Notes:**
Code which uses QBlit(), or QBSBlit() should make use of
the pointer to a cleanup routine in the bltnode structure.
The cleanup routine may be called on the context of an
interrupt, therefore the routine may set a flag, and signal
a task, but it may not call FreeMem() directly.  Use of
the cleanup routine is the only safe way to signal that
your bltnode has completed.

**Bugs:**
QBlit(), and QBSBlit() have been rewritten for V39 due to
various long standing bugs in earlier versions of this code.

**See also:** QBSBlit() hardware/blit.h

---

### graphics.library/QBSBlit

**Synchronize the blitter request with the video beam.**

**Synopsis:**
```c
QBSBlit( bsp )

VOID QBSBlit( struct bltnode * );
```

**Description:**
Call a user routine for use of the blitter, enqueued separately from
the QBlit queue.  Calls the user routine contained in the blit
structure when the video beam is located at a specified position
onscreen.   Useful when you are trying to blit into a visible part
of the screen and wish to perform the data move while the beam is
not trying to display that same area.  (prevents showing part of
an old display and part of a new display simultaneously).  Blitter
requests on the QBSBlit queue take precedence over those on the
regular blitter queue. The beam position is specified in the blitnode.

**Inputs:**
bsp - pointer to a blit structure.  See description in the
      Graphics Support section of the manual for more info.

**Result:**
User routine is called when the QBSBlit queue reaches this
request AND the video beam is in the specified position.
If there are lots of blits going on and the video beam
has wrapped around back to the top it will call all the
remaining bltnodes as fast as it can to try and catch up.

**Notes:**
QBlit(), and QBSBlit() have been rewritten for V39.  Queued
blits are now handled in FIFO order.  Tasks trying to
OwnBlitter() are now given a fair share of the total
blitter time available.  QBSBlit() is no longer queued
separately from nodes added by QBlit().  This fixes the
ordering dependencies listed under BUGS in prior autodoc
notes.

**Bugs:**


**See also:** QBlit() hardware/blit.h

---

### graphics.library/ReadPixel

**Read the pen number value of the pixel at a specified
             x,y location within a certain RastPort.**

**Synopsis:**
```c
int32 penno = ReadPixel(struct RastPort *rp, int16 x, int16 y);
```

**Description:**
Combine the bits from each of the bit-planes used to describe
a particular RastPort into the pen number selector which that
bit combination normally forms for the system hardware selection
of pixel color.

**Inputs:**
rp    - pointer to a RastPort structure
(x,y) - a point in the RastPort

**Result:**
penno - The pen number of the pixel at (x,y) is returned.
        -1 is returned if the pixel cannot be read for some reason.

**See also:** WritePixel(), ReadPixelColor()

---

### graphics.library/ReadPixelArray8 (V36)

**Read the pen number value of a rectangular array
                   of pixels starting at a specified x,y location and
                   continuing through to another x,y location within
                   a certain RastPort.**

**Synopsis:**
```c
int32 count = ReadPixelArray8(struct RastPort *rp,
                uint16 xstart, uint16 ystart,
                uint16 xstop, uint16 ystop,
                uint8 *array, struct RastPort *temprp);
```

**Description:**
For each pixel in a rectangular region, combine the bits from each
of the bit-planes used to describe a particular RastPort into the pen
number selector which that bit combination normally forms for the
system hardware selection of pixel color.

**Inputs:**
rp              - pointer to a RastPort structure
(xstart,ystart) - starting point in the RastPort
(xstop,ystop)   - stopping point in the RastPort
array           - Pointer to an array of UBYTEs from which to fetch
                  the pixel data. Allocate at least
                  ((((width + 15) >> 4) << 4) * (ystop - ystart + 1))
                  bytes.
temprp          - Temporary rastport (copy of rp with Layer
                  set == NULL, temporary memory allocated for
                  temprp->BitMap with Rows set == 1,
                  temprp->BitMap->BytesPerRow == (((width+15)>>4)<<1)
                  and temporary memory allocated for
                  temprp->BitMap->Planes[])

**Result:**
For each pixel in the array:
  Pen   - (0..255) number at that position is returned
  count - the number of pixels read.

**Notes:**
xstop must be >= xstart
ystop must be >= ystart

**See also:** ReadPixel(), ReadPixelLine8()

---

### graphics.library/ReadPixelLine8 (V36)

**Read the pen number value of a horizontal line of
               pixels starting at a specified x,y location and
                  continuing right for count pixels.**

**Synopsis:**
```c
int32 count = ReadPixelLine8(struct RastPort *rp,
                uint16 xstart, uint16 ystart, uint16 width,
                uint8 *array, struct RastPort *temprp);
```

**Description:**
For each pixel in a rectangular region, combine the bits from each
of the bit-planes used to describe a particular RastPort into the
pen number selector which that bit combination normally forms for
the system hardware selection of pixel color.

**Inputs:**
rp    - Pointer to a RastPort structure.
(x,y) - A point in the RastPort.
width - Count of horizontal pixels to read.
array - Pointer to an array of UBYTEs from which to fetch the pixel
        data. Allocate at least (((width + 15) >> 4) << 4) bytes.
temprp - temporary rastport (copy of rp with Layer set == NULL,
         temporary memory allocated for
         temprp->BitMap with Rows set == 1,
         temprp->BitMap->BytesPerRow == (((width + 15) >> 4) << 1),
         and temporary memory allocated for
         temprp->BitMap->Planes[])

**Result:**
For each pixel in the array:
      Pen   - (0..255) number at that position is returned
  count - the number of pixels read.

**Notes:**
width must be non negative

**See also:** ReadPixel()

---

### graphics.library/RectFill

**Fill a rectangular region in a RastPort.**

**Synopsis:**
```c
void RectFill(struct RastPort *rp, int16 xmin, int16 ymin,
              int16 xmax, int16 ymax);
```

**Description:**
Fills the rectangular region specified by the paramters
with the chosen pen colors, areafill pattern and drawing mode.
If no areafill pattern is specified, fill the rectangular region
with the FgPen color, taking into account the drawing mode.

**Inputs:**
rp - pointer to a RastPort structure
(xmin,ymin) (xmax,ymax) are the coordinates of the upper
left corner and the lower right corner, respectively, of the
rectangle.

**Notes:**
The following relation MUST be true:
(xmax >= xmin) and (ymax >= ymin)

**Bugs:**
Complement mode with FgPen complements all bitplanes.

**See also:** AreaEnd(), RectFillColor(), graphics/rastport.h

---

### graphics.library/ReleasePen (V39)

**Release an allocated palette entry
              to the free pool.**

**Synopsis:**
```c
ReleasePen( cm, n )

VOID ReleasePen( Struct ColorMap *, LONG);
```

**Description:**
Return the palette entry for use by other applications.
If the reference count for this palette entry goes to zero,
then it may be reset to another RGB value.

**Inputs:**
cm  -  A pointer to a color map created by GetColorMap().

n   -  A palette index obtained via any of the palette allocation
       functions. Passing a -1 will result in this call doing
       nothing.

**Notes:**
This function works for both shared and exclusive palette entries.

**Bugs:**


**See also:** GetColorMap() ObtainPen() ObtainBestPenA()

---

### graphics.library/RemBob

**Macro to remove a Bob from the gel list.**

**Synopsis:**
```c
RemBob(bob)

RemBob(struct Bob *);
```

**Description:**
Marks a Bob as no-longer-required.  The gels internal code then
removes the Bob from the list of active gels the next time
DrawGList is executed. This is implemented as a macro.
If the user is double-buffering the Bob, it could take two
calls to DrawGList before the Bob actually disappears from
the RastPort.

**Inputs:**
Bob = pointer to the Bob to be removed

**Result:**


**Bugs:**


**See also:** RemIBob()  DrawGList()  graphics/gels.h  graphics/gfxmacros.h

---

### graphics.library/RemFont

**Remove a font from the system list.**

**Synopsis:**
```c
RemFont(textFont)

VOID RemFont(struct TextFont *);
```

**Description:**
This function removes a font from the system, ensuring that
access to it is restricted to those applications that
currently have an active pointer to it: i.e. no new SetFont
requests to this font are satisfied.

**Inputs:**
textFont - the TextFont structure to remove.

**Result:**


**Bugs:**


**See also:** SetFont() AddFont() graphics/text.h

---

### graphics.library/RemIBob

**Immediately remove a Bob from the gel list
    and the RastPort.**

**Synopsis:**
```c
RemIBob(bob, rp, vp)

VOID RemIBob(struct Bob *, struct RastPort *, struct ViewPort *);
```

**Description:**
Removes a Bob immediately by uncoupling it from the gel list and
erases it from the RastPort.

**Inputs:**
bob = pointer to the Bob to be removed
rp  = pointer to the RastPort if the Bob is to be erased
vp  = pointer to the ViewPort for beam-synchronizing

**Result:**


**Bugs:**


**See also:** InitGels() RemVSprite() graphics/gels.h

---

### graphics.library/RemVSprite

**Remove a VSprite from the current gel list.**

**Synopsis:**
```c
RemVSprite(vs)

VOID RemVSprite(struct VSprite *);
```

**Description:**
Unlinks the VSprite from the current gel list.

**Inputs:**
vs = pointer to the VSprite structure to be removed from the gel list

**Result:**


**Bugs:**


**See also:** InitGels()  RemIBob()  graphics/gels.h

---

### graphics.library/ScalerDiv (V36)

**Get the scaling result that BitMapScale would.**

**Synopsis:**
```c
result = ScalerDiv(factor, numerator, denominator)

UWORD ScalerDiv(UWORD, UWORD, UWORD);
```

**Description:**
Calculate the expression (factor*numerator/denominator) such
that the result is the same as the width of the destination
result of BitMapScale when the factor here is the width of
the source, and the numerator and denominator are the
XDestFactor and XSrcFactor for BitMapScale.

**Inputs:**
factor                 - a number in the range 0..16383
numerator, denominator - numbers in the range 1..16383

**Result:**
this returns factor*numerator/denominator

---

### graphics.library/ScrollRaster

**Push bits in rectangle in raster around by
                dx, dy towards 0, 0 inside rectangle.**

**Synopsis:**
```c
ScrollRaster(rp, dx, dy, xmin, ymin, xmax, ymax)

VOID ScrollRaster
             (struct RastPort *, WORD, WORD, WORD, WORD, WORD, WORD);
```

**Description:**
Move the bits in the raster by (dx,dy) towards (0,0)
The space vacated is RectFilled with BGPen.
Limit the scroll operation to the rectangle defined
by (xmin, ymin)(xmax, ymax). Bits outside will not be
affected. If xmax,ymax is outside the rastport then use
the lower right corner of the rastport.
If you are dealing with a SimpleRefresh layered RastPort you
should check rp->Layer->Flags & LAYERREFRESH to see if
there is any damage in the damage list.  If there is you should
call the appropriate BeginRefresh(Intuition) or BeginUpdate(Layers)
routine sequence.

**Inputs:**
rp         - pointer to a RastPort structure
dx, dy     - integers that may be positive, zero, or negative
xmin, ymin - upper left of bounding rectangle
xmax, ymax - lower right of bounding rectangle

**Example:**
```c
// shift raster up by one row
ScrollRaster(rp, 0, 1, minx, miny, maxx, maxy);

// shift raster down and to the right by 1 pixel
ScrollRaster(rp, -1, -1, minx, miny, maxx, maxy);
```

**Bugs:**
In 1.2/V1.3 if you ScrollRaster a SUPERBITMAP exactly left or
right, and there is no TmpRas attached to the RastPort, the system
will allocate one for you, but will never free it or record its
location. This bug has been fixed for V36.  The workaround for
1.2/1.3 is to attach a valid TmpRas of size at least
MAXBYTESPERROW to the RastPort before the call.

Beginning with V36 ScrollRaster adds the shifted areas into the
damage list for SIMPLE_REFRESH windows. Due to unacceptable
system overhead, the decision was made NOT to propagate this
shifted area damage for SMART_REFRESH windows.

**See also:** ScrollRasterBF() RectFill() intuition.library/ScrollWindowRaster()
graphics/rastport.h

---

### graphics.library/ScrollRasterBF (V39)

**Push bits in rectangle in raster around by dx, dy
                  towards 0, 0 inside rectangle. Newly empty areas
                  will be filled via EraseRect().**

**Synopsis:**
```c
ScrollRasterBF(rp, dx, dy, xmin, ymin, xmax, ymax)

VOID ScrollRasterBF
             (struct RastPort *, WORD, WORD, WORD, WORD, WORD, WORD);
```

**Description:**
Move the bits in the raster by (dx,dy) towards (0, 0)
The space vacated is filled by calling EraseRect().
Limit the scroll operation to the rectangle defined
by (xmin, ymin)(xmax, ymax). Bits outside will not be
affected. If xmax,ymax is outside the rastport then use
the lower right corner of the rastport.
If you are dealing with a SimpleRefresh layered RastPort you
should check rp->Layer->Flags & LAYERREFRESH to see if
there is any damage in the damage list.  If there is you should
call the appropriate BeginRefresh(Intuition) or BeginUpdate(Layers)
routine sequence.

**Inputs:**
rp         - pointer to a RastPort structure
dx, dy     - integers that may be positive, zero, or negative
xmin, ymin - upper left of bounding rectangle
xmax, ymax - lower right of bounding rectangle

**Notes:**
This call is exactly the same as ScrollRaster, except that it calls
EraseRect() instead of RectFill() when clearing the newly exposed
area. This allows use of a custom layer backfill hook.

**Bugs:**


**See also:** ScrollRaster() EraseRect() intuition.library/ScrollWindowRaster()
graphics/rastport.h

---

### graphics.library/ScrollVPort

**Reinterpret RasInfo information in ViewPort to reflect
		the current Offset values.**

**Synopsis:**
```c
ScrollVPort( vp )

VOID ScrollVPort(struct ViewPort *vp);
```

**Description:**
After the programmer has adjusted the Offset values in
the RasInfo structures of ViewPort, change the
copper lists to reflect the Scroll positions.
Changing the BitMap ptr in RasInfo and not changing
the Offsets will effect a double buffering affect.

**Inputs:**
vp - pointer to a ViewPort structure
     that is currently be displayed.

**Result:**
modifies hardware and intermediate copperlists to reflect
new RasInfo

**Bugs:**
pokes not fast enough to avoid some visible hashing of display (V37)
This function was re-written in V39 and is ~10 times faster than
before.

**See also:** MakeVPort() MrgCop() LoadView()  graphics/view.h

---

### graphics.library/SetABPenDrMd (V39)

**Set pen colors and draw mode for a RastPort.**

**Synopsis:**
```c
SetABPenDrMd( rp, apen, bpen, mode )

VOID SetABPenDrMd( struct RastPort *, ULONG, ULONG, ULONG );
```

**Description:**
Set the pen values and drawing mode for lines, fills and text.
Get the bit definitions from rastport.h

**Inputs:**
rp - pointer to RastPort structure.
apen - primary pen value
bpen - secondary pen value
mode - 0-255, some combinations may not make much sense.

**Result:**
The mode set is dependent on the bits selected.
Changes minterms to reflect new drawing mode and colors.
Sets line drawer to restart pattern.

**Notes:**
This call is essentially the same as a sequence of
SetAPen()/SetBPen()/SetDrMD() calls, except that it is
significantly faster. The minterms will only be generated
once, or not at all if nothing changed (warning to illegal
RastPort pokers!).

**Bugs:**


**See also:** SetAPen() SetBPen() SetDrMd() graphics/rastport.h

---

### graphics.library/SetAPen

**Set the primary pen for a RastPort.**

**Synopsis:**
```c
SetAPen( rp, pen )

VOID SetAPen( struct RastPort *, UBYTE );
```

**Description:**
Set the primary drawing pen for lines, fills, and text.

**Inputs:**
rp - pointer to RastPort structure.
pen - (0-255)

**Result:**
Changes the minterms in the RastPort to reflect new primary pen.
Sets line drawer to restart pattern.

**Bugs:**


**See also:** SetBPen() graphics/rastport.h

---

### graphics.library/SetBPen

**Set secondary pen for a RastPort**

**Synopsis:**
```c
SetBPen( rp, pen )

VOID SetBPen( struct RastPort *, UBYTE );
```

**Description:**
Set the secondary drawing pen for lines, fills, and text.

**Inputs:**
rp - pointer to RastPort structure.
pen - (0-255)

**Result:**
Changes the minterms in the RastPort to reflect new secondary pen.
Sets line drawer to restart pattern.

**Bugs:**


**See also:** SetAPen() graphics/rastport.h

---

### graphics.library/SetChipRev (V39)

**turns on the features of a Chip Set**

**Synopsis:**
```c
uint32 chiprevbits = SetChipRev(uint32 ChipRev);
```

**Description:**
Enables the features of the requested Chip Set if available,
and updates the graphics database accordingly.

**Inputs:**
ChipRev - Chip Rev that you would like to be enabled.

**Result:**
chiprevbits - Actual bits set in GfxBase->ChipRevBits0.

**Notes:**
This routine should only be called once. It will be called by the
system in the startup-sequence, but is included in the autodocs for
authors of bootblock-games that wish to take advantage of post-ECS
features.

**See also:** graphics/gfxbase.h

---

### graphics.library/SetCollision

**Set a pointer to a user collision routine.**

**Synopsis:**
```c
SetCollision(num, routine, GInfo)

VOID SetCollision(ULONG, VOID (*)(), struct GelsInfo *);
```

**Description:**
Sets a specified entry (num) in the user's collision vectors table
equal to the address of the specified collision routine.

**Inputs:**
num     = collision vector number
routine = pointer to the user's collision routine.
          See graphics/gels.h for the prototype.
GInfo   = pointer to a GelsInfo structure

**Result:**


**Bugs:**


**See also:** InitGels()  graphics/gels.h  graphics/rastport.h

---

### graphics.library/SetDrMd

**Set drawing mode for a RastPort**

**Synopsis:**
```c
SetDrMd( rp, mode )

VOID SetDrMd( struct RastPort *, UBYTE );
```

**Description:**
Set the drawing mode for lines, fills and text.
Get the bit definitions from rastport.h

**Inputs:**
rp - pointer to RastPort structure.
mode - 0-255, some combinations may not make much sense.

**Result:**
The mode set is dependent on the bits selected.
Changes minterms to reflect new drawing mode.
Sets line drawer to restart pattern.

**Bugs:**


**See also:** SetAPen() SetBPen() graphics/rastport.h

---

### graphics.library/SetFont

**Set the text font and attributes in a RastPort.**

**Synopsis:**
```c
SetFont(rp, font)

VOID SetFont(struct RastPort *, struct TextFont *);
```

**Description:**
This function sets the font in the RastPort to that described
by font, and updates the text attributes to reflect that
change.  This function clears the effect of any previous
soft styles.

**Inputs:**
rp   - the RastPort in which the text attributes are to be changed
font - pointer to a TextFont structure returned from OpenFont()
       or OpenDiskFont()

**Result:**


**Notes:**
This function had previously been documented that it would
accept a null font.  This practice is discouraged.
o   Use of a RastPort with a null font with text routines has
    always been incorrect and risked the guru.
o   Keeping an obsolete font pointer in the RastPort is no more
    dangerous than keeping a zero one there.
o   SetFont(rp, 0) causes spurious low memory accesses under
    some system software releases.

As of V36, the following Amiga font variants are no longer
directly supported:
    fonts with NULL tf_CharSpace and non-NULL tf_CharKern.
    fonts with non-NULL tf_CharSpace and NULL tf_CharKern.
    fonts with NULL tf_CharSpace and NULL tf_CharKern with
    a tf_CharLoc size component greater than tf_XSize.
Attempts to SetFont one of these font variants will
cause the system to try to modify your font to make it
acceptable.

SetFont() returns no result but may fail. It can only fail for
fonts not obtained from OpenFont() or OpenDiskFont(), e.g.
in-code TextFonts. It will not set the font if ExtendFont()
fails (out of memory or obsolete font). In this case it
simply keeps the previous font.

**Bugs:**
Calling SetFont() on in-code TextFonts (ie fonts not
OpenFont()ed) will result in a loss of 24 bytes from
the system as of V36.
This can be resolved by calling StripFont().

**See also:** OpenFont() StripFont()
diskfont.library/OpenDiskFont() graphics/text.h

---

### graphics.library/SetMaxPen (V39)

**set maximum pen value for a rastport.**

**Synopsis:**
```c
SetMaxPen ( rp, maxpen)

VOID SetMaxPen(struct RastPort *, ULONG)
```

**Description:**
This will instruct the graphics library that the owner of the
rastport will not be rendering in any colors whose index is >maxpen.
If there are any speed optimizations which the graphics device can
make based on this fact (for instance, setting the pixel write mask),
they will be done.

**Inputs:**
rp  =  a pointer to a valid RastPort structure.
maxpen =  a longword pen value.

**Result:**
Basically this call sets the rastport mask, if this would improve
speed. On devices where masking would slow things down (like with
chunky pixels), it will be a no-op.

**Notes:**
The maximum pen value passed must take into account not only which
colors you intend to render in the future, but what colors you will
be rendering on top of.
SetMaxPen(rp, 0) doesn't make much sense.

**Bugs:**


**See also:** SetWriteMask()

---

### graphics.library/SetOPen

**Change the Area OutLine pen and turn on Outline
           mode for areafills.**

**Synopsis:**
```c
SetOPen(rp, pen)

VOID SetOPen( struct RastPort *, UBYTE );
```

**Description:**
This is implemented as a c-macro.
Pen is the pen number that will be used to draw a border
around an areafill during AreaEnd().

**Inputs:**
rp = pointer to RastPort structure
pen = number  between 0-255

**Bugs:**


**See also:** AreaEnd() graphics/gfxmacros.h graphics/rastport.h

---

### graphics.library/SetOutlinePen (V39)

**Set the Outline Pen value for a RastPort.**

**Synopsis:**
```c
old_pen=SetOutlinePen  ( rp, pen )

ULONG SetOutlinePen(struct RastPort *,ULONG)
```

**Description:**
Set the current value of the O pen for the rastport and turn on
area outline mode. This function should be used instead of poking
the structure directly, because future graphics devices may store
it differently, for instance, using more bits.

**Inputs:**
rp  -  a pointer to a valid RastPort structure.
pen -  a longword pen number

**Result:**
returns the previous outline pen

**Notes:**


**Bugs:**


**See also:** GetOutlinePen() graphics/gfxmacros.h

---

### graphics.library/SetRast

**Synopsis:**
```c
SetRast( rp, pen )

VOID SetRast( struct RastPort *, UBYTE );
```

**Description:**
Set the entire contents of the specified RastPort to the
specified pen.

**Inputs:**
rp - pointer to RastPort structure
pen - the pen number (0-255) to jam into bitmap

**Result:**
All pixels within the drawing area are set to the
selected pen number.

**Bugs:**


**See also:** RectFill() graphics/rastport.h

---

### graphics.library/SetRGB32 (V39)

**Set one color register for this Viewport.**

**Synopsis:**
```c
SetRGB32( vp, n, r, g, b )

VOID SetRGB32( struct ViewPort *, ULONG, ULONG, ULONG, ULONG );
```

**Inputs:**
vp - viewport
n  - the number of the color register to set.
r  - red level   (32 bit left justified fraction)
g  - green level (32 bit left justified fraction)
b  - blue level  (32 bit left justified fraction)

**Result:**
If there is a ColorMap for this viewport, then the value will
be stored in the ColorMap.
The selected color register is changed to match your specs.
If the color value is unused then nothing will happen.

**Notes:**
Lower order bits of the palette specification will be discarded,
depending on the color palette resolution of the target graphics
device. Use 0xffffffff for the full value, 0x7fffffff for 50%,
etc. You can find out the palette range for your screen by
querying the graphics data base.

**Bugs:**


**See also:** GetColorMap() GetRGB32() SetRGB32CM() LoadRGB32() graphics/view.h

---

### graphics.library/SetRGB32CM (V39)

**Set one color register for this ColorMap.**

**Synopsis:**
```c
SetRGB32CM( cm, n, r, g, b )

VOID SetRGB32CM( struct ColorMap *, UWORD, ULONG, ULONG , ULONG);
```

**Inputs:**
cm - colormap
n  - the number of the color register to set. Must not exceed
     the number of colors allocated for the colormap.
r  - red level (32 bit unsigned left justified fraction)
g  - green level
b  - blue level

**Result:**
Store the (r,g,b) triplet at index n of the ColorMap structure.
This function can be used to set up a ColorMap before before
linking it into a viewport.

**Bugs:**
Prior to V46 the lower nibble of the blue color in the ColorMap
was constructed from the wrong bits of the input ULONG value,
e.g. 0x01234567 -> 0x03 instead of 0x01 (or 0x01010101 returned
by GetRGB32()).

**See also:** GetColorMap() GetRGB32() SetRGB32() SetRGB4CM() graphics/view.h

---

### graphics.library/SetRGB4

**Set one color register for this viewport.**

**Synopsis:**
```c
VOID SetRGB4(struct ViewPort *vp, uint16 n, uint8 r, uint8 g, uint8 b);
```

**Description:**
Change the color look up table so that this viewport displays
the color (r,g,b) for pen number n.

**Inputs:**
vp - pointer to viewport structure
n  - the color number (range from 0 to 31)
r  - red   level (0-15)
g  - green level (0-15)
b  - blue  level (0-15)

**Result:**
If there is a ColorMap for this viewport, then the value will
be stored in the ColorMap.
The selected color register is changed to match your specs.
If the color value is unused then nothing will happen.

**Notes:**
Under V36 and up, it is not safe to call this function
from an interrupt, due to semaphore protection of graphics
copper lists.

**Bugs:**


**See also:** LoadRGB4() GetRGB4() graphics/view.h

---

### graphics.library/SetRGB4CM

**Set one color register for this ColorMap.**

**Synopsis:**
```c
SetRGB4CM( cm,  n,  r,   g,   b )

VOID SetRGB4CM( struct ColorMap *, UWORD, UBYTE, UBYTE, UBYTE );
```

**Inputs:**
cm - colormap
n  - the number of the color register to set. Ranges from 0 to 31
     on current Amiga displays.
r  - red   level (0-15)
g  - green level (0-15)
b  - blue  level (0-15)

**Result:**
Store the (r,g,b) triplet at index n of the ColorMap structure.
This function can be used to set up a ColorMap before before
linking it into a viewport.

**Bugs:**


**See also:** GetColorMap() GetRGB4() SetRGB4() graphics/view.h

---

### graphics.library/SetRPAttrsA

**modify rastport settings via a tag list
SetRPAttrs  -- varargs stub for SetRPAttrsA**

**Synopsis:**
```c
SetRPAttrsA(rp, tags)

uint32 SetRPAttrsA(struct RastPort *, CONST struct TagItem *);

SetRPAttrs(rp, tag1, ...);
```

**Description:**
Modify settings of a rastport, based on the taglist passed.
currently available tags are:

RPTAG_Font        Font for Text()
RPTAG_APen        Primary rendering pen
RPTAG_BPen        Secondary rendering pen
RPTAG_DrMd        Drawing mode (see graphics/rastport.h)
RPTAG_OutlinePen  Area Outline pen
RPTAG_OPen        Area Outline pen (short alias added in V51)
RPTAG_WriteMask   Bit Mask for writing.
RPTAG_MaxPen      Maximum pen to render (see SetMaxPen())

Tags introduced in V51:

RPTAG_APenColor       Primary rendering color (overrides APen)
RPTAG_BPenColor       Secondary rendering color (overrides BPen)
RPTAG_OPenColor       Area outline color (overrides OutlinePen)
RPTAG_OutlinePenColor Alias for RPTAG_OPenColor

The color format used by the three tags above is 0xAARRGGBB.
Please note that these tags won't have any effect when
rp->BitMap does not point to a directmapped bitmap. The alpha
part is currently ignored and should be set to 0xFF.

RPTAG_RemapColorFonts  Tells graphics to use ColorTextFont->
 ColorFontColors to render text. The destination bitmap
 must be directmapped to make this work. This tag is a boolean.

Tags introduced in V54:

**Inputs:**
rp   - pointer to the RastPort to modify.
tags - a standard tag list

**Result:**
Return the number of handled Tags.

**Bugs:**
Before 54.136 this function did not return anything, now it returns
the number of handled tags.

**See also:** SetFont() SetSoftStyle() SetAPen() SetBPen() SetDrMd()
SetOutLinePen() SetWriteMask() SetMaxPen() GetRPAttrsA()
graphics/rpattr.h

---

### graphics.library/SetSoftStyle

**Set the soft style of the current font.**

**Synopsis:**
```c
newStyle = SetSoftStyle(rp, style, enable)

ULONG SetSoftStyle(struct RastPort *, ULONG, ULONG);
```

**Description:**
This function alters the soft style of the current font.  Only
those bits that are also set in enable are affected.  The
resulting style is returned, since some style request changes
will not be honored when the implicit style of the font
precludes changing them.

**Inputs:**
rp     - the RastPort from which the font and style
         are extracted.
style  - the new font style to set, subject to enable.
enable - those bits in style to be changed.  Any set bits here
         that would not be set as a result of AskSoftStyle will
         be ignored, and the newStyle result will not be as
         expected.

**Result:**
newStyle - the resulting style, both as a result of previous
           soft style selection, the effect of this function,
           and the style inherent in the set font.

**Bugs:**


**See also:** AskSoftStyle() graphics/text.h

---

### graphics.library/SetWriteMask (V39)

**Set the pixel write mask value for a RastPort.**

**Synopsis:**
```c
success=SetWriteMask ( rp, msk )

ULONG SetWriteMask(struct RastPort *,ULONG)
```

**Description:**
Set the current value of the bit write mask for the rastport.
bits of the pixel with zeros in their mask will not be modified by
subsequent drawing operations.

**Inputs:**
rp  =  a pointer to a valid RastPort structure.
msk =  a longword mask value.

**Result:**
Graphics devices which do not support per-bit masking will
return 0 (failure).

**Notes:**


**Bugs:**


**See also:** graphics/gfxmacros.h

---

### graphics.library/SortGList

**Sort the current gel list, ordering its y,x coordinates.**

**Synopsis:**
```c
SortGList(rp)

VOID SortGList(struct RastPort *);
```

**Description:**
Sorts the current gel list according to the gels' y,x coordinates.
This sorting is essential before calls to DrawGList or DoCollision.

**Inputs:**
rp = pointer to the RastPort structure containing the GelsInfo

**Result:**


**Bugs:**


**See also:** InitGels()  DoCollision()  DrawGList()  graphics/rastport.h

---

### graphics.library/StripFont (V36)

**remove the tf_Extension from a font**

**Synopsis:**
```c
StripFont(font)

VOID StripFont(struct TextFont *);
```

---

### graphics.library/SyncSBitMap

**Syncronize Super BitMap with whatever is
               in the standard Layer bounds.**

**Synopsis:**
```c
SyncSBitMap( layer )

VOID SyncSBitMap( struct Layer * );
```

**Description:**
Copy all bits from ClipRects in Layer into Super BitMap
BitMap.  This is used for those functions that do not
want to deal with the ClipRect structures but do want
to be able to work with a SuperBitMap Layer.

**Inputs:**
layer - pointer to a Layer that has a SuperBitMap
        The Layer should already be locked by the caller.

**Result:**
After calling this function, the programmer can manipulate
the bits in the superbitmap associated with the layer.
Afterwards, the programmer should call CopySBitMap to
copy the bits back into the onscreen layer.

**Bugs:**


**See also:** CopySBitMap() graphics/clip.h

---

### graphics.library/Text

**Write text characters (no formatting).**

**Synopsis:**
```c
Text(rp, string, length)

VOID Text(struct RastPort *, CONST_STRPTR, UWORD);
```

**Description:**
This graphics function writes printable text characters to the
specified RastPort at the current position.  No control meaning
is applied to any of the characters, thus only text on the
current line is output.

The current position in the RastPort is updated to the next
character position.
If the characters displayed run past the RastPort boundary,
the current position is truncated to the boundary, and
thus does not equal the old position plus the text length.

**Inputs:**
rp     - a pointer to the RastPort which describes where the
         text is to be output
string - the address of string to output
length - the number of characters in the string.
         If zero, there are no characters to be output.

**Notes:**
o   This function may use the blitter.
o   Changing the text direction with RastPort->TxSpacing is
    not supported.

**Bugs:**
For V34 and earlier:
o   The maximum string length (in pixels) is limited to
    (1024 - 16 = 1008) pixels wide.
o   A text string whose last character(s) have a
    tf_CharLoc size component that extends to the right of
    the rightmost of the initial and final CP positions
    will be (inappropriately) clipped.

**See also:** Move()  TextLength()  graphics/text.h  graphics/rastport.h

---

### graphics.library/TextExtent (V36)

**Determine raster extent of text data.**

**Synopsis:**
```c
TextExtent(rp, string, count, textExtent)

VOID TextExtent(struct RastPort *, CONST_STRPTR, UWORD,
     struct TextExtent *);
```

**Description:**
This function determines a more complete metric of the space
that a text string would render into than the TextLength()
function.

**Inputs:**
rp     - a pointer to the RastPort which describes where the
  text attributes reside.
string - the address of the string to determine the length of.
count  - the number of characters in the string.
         If zero, there are no characters in the string.
textExtent - a structure to hold the result.

**Result:**
textExtent is filled in as follows:
    te_Width  - same as TextLength() result: the rp_cp_x
         advance that rendering this text would cause.
    te_Height - same as tf_YSize.  The height of the
         font.
    te_Extent.MinX - the offset to the left side of the
         rectangle this would render into.  Often zero.
    te_Extent.MinY - same as -tf_Baseline.  The offset
         from the baseline to the top of the rectangle
         this would render into.
    te_Extent.MaxX - the offset of the left side of the
         rectangle this would render into.  Often the
         same as te_Width-1.
    te_Extent.MaxY - same as tf_YSize-tf_Baseline-1.
         The offset from the baseline to the bottom of
         the rectangle this would render into.

**Bugs:**
See also BUGS section of TextLength() autodoc.

**See also:** TextLength()  Text()  TextFit()
graphics/text.h  graphics/rastport.h

---

### graphics.library/TextFit (V36)

**Synopsis:**
```c
chars = TextFit(rastport, string, strLen, textExtent,
             constrainingExtent, strDirection,
             constrainingBitWidth, constrainingBitHeight)

   UWORD TextFit(struct RastPort *, CONST_STRPTR, UWORD,
       struct TextExtent *, CONST struct TextExtent *,
       WORD, UWORD, UWORD);
```

**Description:**
This function determines how many of the characters of the
   provided string will fit into the space described by the
   constraining parameters.  It also returns the extent of
   that number of characters.

**Inputs:**
rp     - a pointer to the RastPort which describes where the
     text attributes reside.
   string - the address of string to determine the constraint of
   strLen - The number of characters in the string.
     If zero, there are no characters in the string.
   textExtent - a structure to hold the extent result.
   constrainingExtent - the extent that the text must fit in.
     This can be NULL, indicating only the constrainingBit
     dimensions will describe the constraint.
   strDirection - the offset to add to the string pointer to
     get to the next character in the string.  Usually 1.
     Set to -1 and the string to the end of the string to
     perform a TextFit() anchored at the end.  No other value
     is valid.
   constrainingBitWidth - an alternative way to specify the
     rendering box constraint width that is independent of
     the rendering origin.  Range 0..32767.
   constrainingBitHeight - an alternative way to specify the
     rendering box constraint height that is independent of
     the rendering origin.  Range 0..32767.

**Result:**
chars - the number of characters from the origin of the
 given string that will fit in both the constraining
 extent (which specifies a CP bound and a rendering
 box relative to the origin) and in the rendering width
 and height specified.

**Notes:**
The result is zero chars and an empty textExtent when the fit
   cannot be performed.  This occurs not only when no text will
   fit in the provided constraints, but also when:
   -   the RastPort rp's rp_TxSpacing sign and magnitude is so
great it reverses the path of the text.
   -   the constrainingExtent does not include x = 0.

**Bugs:**
Under V37, TextFit() would return one too few characters if the
   font was proportional. This can be worked around by passing
   (constrainingBitWidth + 1) for proportional fonts. This is fixed
   for V39.

**See also:** TextExtent()  TextLength()  Text()
   graphics/text.h  graphics/rastport.h

---

### graphics.library/TextLength

**Determine raster length of text data.**

**Synopsis:**
```c
length = TextLength(rp, string, count)

WORD TextLength(struct RastPort *, CONST_STRPTR, UWORD);
```

**Description:**
This graphics function determines the length that text data
would occupy if output to the specified RastPort with the
current attributes.  The length is specified as the number of
raster dots: to determine what the current position would be
after a Text() using this string, add the length to cp_x
(cp_y is unchanged by Text()).  Use the newer TextExtent() to
get more information.

**Inputs:**
rp     - a pointer to the RastPort which describes where the
  text attributes reside.
string - the address of string to determine the length of
count  - the string length.  If zero, there are no characters
  in the string.

**Result:**
length - the number of pixels in x this text would occupy, not
  including any negative kerning that may take place at
  the beginning of the text string, nor taking into
  account the effects of any clipping that may take
  place.

**Notes:**
Prior to V36, the result length occupied only the low word of
d0 and was not sign extended into the high word.

**Bugs:**
A length that would overflow single word arithmetic is not
calculated correctly. This has been fixed in v51.21, length will
be zero in this case. If you need determine the length of long
strings, the following code can be used:

LONG TextLength32(struct RastPort *rp, STRPTR string, ULONG count)
{
    struct TextExtent te;
    LONG   result = 0;
    ULONG  chars;

    while (count > 0) {
	chars = TextFit(rp, string, MIN(count,65535), &te,
			NULL, 1, 32767, 32767);

	if (!chars) break; // paranoia!

	string += chars;
	count  -= chars;
	result += te.te_Width;
    }

    return result;
}

Please note that this code requires graphics 51.21 or better to work.

**See also:** TextExtent()  Text()  TextFit()
graphics/text.h  graphics/rastport.h

---

### graphics.library/UnlockLayerRom

**Unlock Layer structure by ROM(gfx lib) code.**

**Synopsis:**
```c
UnlockLayerRom( layer )

VOID UnlockLayerRom( struct Layer * );
```

**Description:**
Release the lock on this layer. If the same task has called
LockLayerRom more than once than the same number of calls to
UnlockLayerRom must happen before the layer is actually freed
so that other tasks may use it.
This call does destroy scratch registers.
This call is identical to UnlockLayer (layers.library).

**Inputs:**
layer - pointer to Layer structure

**Bugs:**


**See also:** LockLayerRom() layers.library/UnlockLayer() graphics/clip.h

---

### graphics.library/VBeamPos

**Get vertical beam position at this instant.**

**Synopsis:**
```c
pos = VBeamPos()

LONG VBeamPos( VOID );
```

**Description:**
Get the vertical beam position from the hardware.

**Inputs:**
none

**Result:**
interrogates hardware for beam position and returns value.
valid results in are the range of 0-511.
Because of multitasking, the actual value returned may have
no use. If you are the highest priority task then the value
returned should be close, within 1 line.

**Bugs:**


---

### graphics.library/VideoControl (V36)

**Modify the operation of a ViewPort's ColorMap**

**Synopsis:**
```c
uint32 error = VideoControl(struct ColorMap *cm, struct TagItem *tags);

uint32 error = VideoControlTags(struct ColorMap *cm, Tag tag1, ...);
```

**Description:**
Process the commands in the VideoControl command TagItem buffer
using cm as the target, with respect to its "attached" ViewPort.

viewport commands:

VTAG_ATTACH_CM     [_SET        | _GET] -- set/get attached viewport
VTAG_VIEWPORTEXTRA [_SET        | _GET] -- set/get attached vp_extra
VTAG_NORMAL_DISP   [_SET        | _GET] -- set/get DisplayInfoHandle
                                    (natural mode)
VTAG_COERCE_DISP   [_SET        | _GET] -- set/get DisplayInfoHandle
                                    (coerced mode)
VTAG_PF1_BASE      [_SET        | _GET] -- set/get color base for
                                    first playfield. (V39)
VTAG_PF2_BASE      [_SET        | _GET] -- set/get color base for
                                    second playfield. (V39)
VTAG_SPODD_BASE    [_SET        | _GET] -- set/get color base for odd
                                    sprites. (V39)
VTAG_SPEVEN_BASE   [_SET        | _GET] -- set/get color base for
                                    even sprites. (V39)
VTAG_BORDERSPRITE  [_SET        | _GET] -- on/off/inquire sprites in
                                    borders. (V39)
VTAG_SPRITERESN    [_SET        | _GET] -- set/get sprite resolution
       (legal values are SPRITERESN_ECS/_140NS/_70NS/_35NS.
        see graphics/view.h) (V39)
VTAG_PF1_TO_SPRITEPRI [_SET     | _GET] -- set/get playfield1
                                    priority with respect to
                                    sprites (V39)
VTAG_PF2_TO_SPRITEPRI [_SET     | _GET] -- set/get playfield2
                                    priority with respect to
                                    sprites (V39)
(These two require that the ColorMap is attached to a ViewPort to be
 effective).

genlock commands:

VTAG_BORDERBLANK   [_SET | _CLR | _GET] -- on/off/inquire blanking
VTAG_BORDERNOTRANS [_SET | _CLR | _GET] -- on/off/inquire
                                    notransparency
VTAG_CHROMAKEY     [_SET | _CLR | _GET] -- on/off/inquire chroma mode
VTAG_BITPLANEKEY   [_SET | _CLR | _GET] -- on/off/inquire bitplane
                                    mode
VTAG_CHROMA_PEN    [_SET | _CLR | _GET] -- set/clr/get chromakey
                                    pen #
VTAG_CHROMA_PLANE  [_SET |      | _GET] -- set/get bitplanekey
                                    plane #

control commands:

VTAG_IMMEDIATE - normally, VideoControl changes do not occur until
          the next MakeVPort. Using this tag, some changes
          can be made to happen immediately. The tag data is
          a pointer to a longword flag variable which will be
          cleared if all changes happened immediately. See
          the example. (V39)

VTAG_FULLPALETTE   [_SET | _CLR | _GET] -- enable/disable loading of
                                    all colors in the copper
                                    list.
 Normally, graphics will only load the color which are
 necessary for the viewport, based upon the screen depth and
 mode. In order to use the color palette banking features,
 you may need to use this tag to tell graphics to load ALL
 colors, regardless of screen depth. (V39)

VC_IntermediateCLUpdate
VC_IntermediateCLUpdate_Query
    When set, graphics will update the intermediate copper
    lists on colour changes. When FALSE, graphics won't update
    the intermediate copperlists, so ScrollVPort(),
    ChangeVPBitMap() and colour loading functions will be
    faster. This value is TRUE by default. (V40)

VC_NoColorPaletteLoad
VC_NoColorPaletteLoad_Query
    When set, only colour 0 will be loaded for this ViewPort,
    hence the inter-ViewPort gap will be smaller. The colours
    for this ViewPort are inherited from the next higher
    ViewPort. The results are undefined if this is the first
    or only ViewPort in the display, and undefined when used
    in conjunction with VTAG_FULLPALETTE (!?!).
    This value is FALSE by default. (V40)

VC_DUALPF_Disable
VC_DUALPF_Disable_Query
    When set, disables the setting of the dual-playfield
    bit in bplcon0. When used with a dual-playfield mode
    screen, this allows using separate scroll and bitmaps
    for the odd and even bitplanes, without going through
    the normal dual-playfield priority and palette selection.
    With appropriate palette setup, this can be used for
    transparency effects, etc.

VC_DPMSLevel
    Sets the VESA Display Power Management Signaling (DPMS)
    power saving level for the associated viewport.
    See enDPMSLevel in <graphics/videocontrol.h> for values.
    Defaults to DPMSLEVEL_ON. (V54)

    Note DPMS works only with graphics boards and is implemented
    by each graphics driver.

copper commands

VTAG_USERCLIP      [_SET | _CLR | _GET] -- on/off/inquire clipping of
                                    UserCopperList at bottom
                                    edge of ColorMap->cm_vp
                                    (defaults to off)

buffer commands:

VTAG_NEXTBUF_CM                         -- link to more VTAG commands
VTAG_END_CM                             -- terminate command buffer

batch mode commands:

(if you want your videocontrol taglist to be processed in "batch"
 mode, that is, at the next MakeVPort() for the ColorMap->cm_vp;
 you may install a static list of videocontrol TagItems into the
 ColorMap with the BATCH_ITEMS_SET command; and then enable/disable
 batch mode processing of those items via the BATCH_CM control
 command)

VTAG_BATCH_CM      [_SET | _CLR | _GET] -- on/off/inquire batch mode
VTAG_BATCH_ITEMS   [_SET | _ADD | _GET] -- set/add/get batched
                                    TagLists

private commands (used internally by intuition -- do not call):

VTAG_VPMODEID      [_SET | _CLR | _GET] -- force GetVPModeID() return

**Inputs:**
cm   = pointer to struct ColorMap obtained via GetColorMap().
tags = pointer to a table of videocontrol tagitems.

**Result:**
error = NULL if no error occurred in the control operation.
(non-NULL if bad colormap pointer, no tagitems or bad tag)

The operating characteristics of the ColorMap and its attached
ViewPort are modified. The result will be incorporated into the
ViewPort when its copper lists are reassembled via MakeVPort().

Note that you must NOT change colors in the viewport (via SetRGB4(),
LoadRGB4(), SetRGB4(), etc.) after changing any of the color palette
offsets (VTAG_PF1_BASE, etc), without first remaking the ViewPort.

**Example:**
```c
struct TagItem VCTags[] =
{
    { VC_NoColorPaletteLoad_Query, NULL },
    { TAG_DONE,                    0    }
};
ULONG query;

VCTags[0].ti_Data = (ULONG)&query;
if (VideoControl(cm, VCTags) == NULL)
{
    printf("Palette loading is %s\n", (query ? "off" : "on"));
}
```

**Notes:**
Sprite resolutions is controlled by two sets of tags, SPRITERESN
and DEFSPRITERESN. If you don't set the sprite resolution, it will
follow the intuition-controlled "default" sprite resolution. Setting
the sprite resolution to one of the SPRITERESN_ values will allow the
application to override intuition's control of it.

This function will modify the contents of the TagList you pass to it
by changing _GET tags to the corresponding _SET or _CLR tag. The
exceptions to this rule are documented as such above (such as
VTAG_IMMEDIATE).

The new tags added for V40 have the prefix VC_ instead of VTAG_.
These tags work in the same manner as all other tags in the system,
and will not be modified by VideoControl().

**Bugs:**


**See also:** graphics/videocontrol.h, GetColorMap(), FreeColorMap()

---

### graphics.library/WaitBlit

**Wait for the blitter to be finished before proceeding
            with anything else.**

**Synopsis:**
```c
WaitBlit()

VOID WaitBlit( VOID );
```

**Description:**
WaitBlit returns when the blitter is idle. This function should
normally only be used when dealing with the blitter in a
synchronous manner, such as when using OwnBlitter and DisownBlitter.
WaitBlit does not wait for all blits queued up using QBlit or
QBSBlit. You should call WaitBlit if you are just about to modify or
free some memory that the blitter may be using.

**Inputs:**
none

**Result:**
Your program waits until the blitter is finished.

**Bugs:**
When examining bits with the CPU right after a blit, or when freeing
temporary memory used by the blitter, a WaitBlit() may be required.

Note that many graphics calls fire up the blitter, and let it run.
The CPU does not need to wait for the blitter to finish before
returning.

Because of a bug in Agnus (prior to all revisions of fat Agnus)
this code may return too soon when the blitter has, in fact, not
started the blit yet, even though BltSize has been written.

This most often occurs in a heavily loaded system with extended
memory, HIRES, and 4 bitplanes.

WaitBlit currently tries to avoid this Agnus problem by testing
the BUSY bit multiple times to make sure the blitter has started.
If the blitter is BUSY at first check, this function busy waits.

This initial hardware bug was fixed as of the first "Fat Agnus" chip,
as used in all A500 and A2000 computers.

Because of a different bug in Agnus (currently all revisions thru
ECS) this code may return too soon when the blitter has, in fact,
not stopped the blit yet, even though blitter busy has been cleared.

This most often occurs in a heavily loaded system with extended
memory, in PRODUCTIVITY mode, and 2 bitplanes.

WaitBlit currently tries to avoid this Agnus problem by testing
the BUSY bit multiple times to make sure the blitter has really
written its final word of destination data.

**See also:** OwnBlitter() DisownBlitter() hardware/blit.h

---

### graphics.library/WaitBOVP

**Wait till vertical beam reached bottom of
     this viewport.**

**Synopsis:**
```c
WaitBOVP( vp )

VOID WaitBOVP( struct ViewPort * );
```

**Description:**
Returns when the vertical beam has reached the bottom of this
viewport.

**Inputs:**
vp - pointer to ViewPort structure

**Result:**
This function will return sometime after the beam gets beyond
the bottom of the viewport.  Depending on the multitasking load
of the system, the actual beam position may be different than
what would be expected in a lightly loaded system.

**Bugs:**
Horrors! This function currently busy waits waiting for the
beam to get to the right place.  It should use the copper
interrupt to trigger and send signals like WaitTOF does.

**See also:** WaitTOF() VBeamPos()

---

### graphics.library/WaitTOF

**Wait for the top of the next video frame.**

**Synopsis:**
```c
WaitTOF()

VOID WaitTOF( VOID );
```

**Description:**
Wait  for vertical blank to occur and all vertical blank
interrupt routines to complete before returning to caller.

**Inputs:**
none

**Result:**
Places this task on the TOF wait queue. When the vertical blank
interrupt comes around, the interrupt service routine will fire off
signals to all the tasks doing WaitTOF. The highest priority task
ready will get to run then.

**Bugs:**


**See also:** exec.library/Wait() exec.library/Signal()

---

### graphics.library/WritePixel

**Change the pen num of one specific pixel in a
              specified RastPort.**

**Synopsis:**
```c
int32 error = WritePixel(struct RastPort *rp, int16 x, int16 y);
```

**Description:**
Changes the pen number of the selected pixel in the specified
RastPort to that currently specified by Pen A, the primary
drawing pen. Obeys minterms in RastPort.

**Inputs:**
rp    - a pointer to the RastPort structure
(x,y) - point within the RastPort at which the selected
        pixel is located.

**Result:**
error = 0 if pixel succesfully changed
      = -1 if (x,y) is outside the RastPort

**See also:** ReadPixel(), WritePixelColor()

---

### graphics.library/WritePixelArray8 (V36)

**write the pen number value of a rectangular array
                    of pixels starting at a specified x,y location
                    and continuing through to another x,y location
                    within a certain RastPort.**

**Synopsis:**
```c
int32 count = WritePixelArray8(struct RastPort *rp,
                uint16 xstart, uint16 ystart,
                uint16 xstop, uint16 ystop,
                uint8 *array, struct RastPort *temprp);
```

**Description:**
For each pixel in a rectangular region, decode the pen number
selector from a linear array of pen numbers into the bit-planes
used to describe a particular rastport.

**Inputs:**
rp              - pointer to a RastPort structure
(xstart,ystart) - starting point in the RastPort
(xstop,ystop)   - stopping point in the RastPort
array           - pointer to an array of UBYTEs
                  from which to fetch the pixel data.
                  Allocate at least
                  ((((width + 15) >> 4) << 4) * (ystop - ystart + 1))
                  bytes.
temprp          - temporary rastport (copy of rp with Layer set to
                  NULL, temporary memory allocated for temprp->BitMap
                  with Rows set to 1, temprp->BitMap->BytesPerRow
                  set to (((width + 15) >> 4) << 1), and temporary
                  memory allocated for temprp->BitMap->Planes[])

**Result:**
count will be set to the number of pixels plotted.

**Notes:**
xstop must be >= xstart
ystop must be >= ystart

**See also:** WritePixel()  graphics/rastport.h

---

### graphics.library/WritePixelLine8 (V36)

**write the pen number value of a horizontal line
                   of pixels starting at a specified x,y location
                   and continuing right for count pixels.**

**Synopsis:**
```c
int32 count = WritePixelLine8(struct RastPort *rp,
                uint16 xstart, uint16 ystart, uint16 width,
                uint8 *array, struct RastPort *temprp);
```

**Description:**
For each pixel in a horizontal region, decode the pen number
selector from a linear array of pen numbers into the bit-planes
used to describe a particular rastport.

**Inputs:**
rp     - pointer to a RastPort structure
(x,y)  - a point in the RastPort
width  - count of horizontal pixels to write
array  - pointer to an array of UBYTEs from which to fetch the pixel
         data. Allocate at least (((width + 15) >> 4) << 4) bytes.
temprp - temporary rastport (copy of rp with Layer set == NULL,
         temporary memory allocated for
         temprp->BitMap with Rows set == 1,
         temprp->BitMap->BytesPerRow == (((width + 15) >> 4) << 1),
         and temporary memory allocated for
         temprp->BitMap->Planes[])

**Result:**
Count will be set to the number of pixels plotted

**Notes:**
width must be non negative

**See also:** WritePixel()  graphics/rastport.h

---

### graphics.library/XorRectRegion

**Perform 2d XOR operation of rectangle
                with region, leaving result in region**

**Synopsis:**
```c
status = XorRectRegion(region, rectangle)

BOOL XorRectRegion( struct Region *, CONST struct Rectangle * );
```

**Description:**
Add portions of rectangle to region if they are not in
the region.
Remove portions of rectangle from region if they are
in the region.

**Inputs:**
region - pointer to Region structure
rectangle - pointer to Rectangle structure

**Result:**
status - return TRUE if successful operation
         return FALSE if ran out of memory

**Bugs:**


**See also:** OrRegionRegion() AndRegionRegion() graphics/regions.h

---

### graphics.library/XorRegionRegion

**Perform 2d XOR operation of one region
                with second region, leaving result in second region**

**Synopsis:**
```c
status = XorRegionRegion(region1, region2)

BOOL XorRegionRegion( CONST struct Region *, struct Region * );
```

**Description:**
Join the regions together. If any part of region1 overlaps
region2 then remove that from the new region.

**Inputs:**
region1      = pointer to Region structure
region2      = pointer to Region structure

**Result:**
status - return TRUE if successful operation
         return FALSE if ran out of memory

**Bugs:**


**See also:** XorRectRegion() OrRegionRegion() graphics/regions.h

---
