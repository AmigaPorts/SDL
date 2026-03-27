# layers.library — Autodoc Reference

*Filtered to AmigaOS V39 and below.*

**Functions:** 31
**Obsolete:** 3

## Function Index

- **AllocClipRect** — Build a ClipRect.
- **BeginUpdate** — Prepare to repair damaged layer.
- **BehindLayer** — Put layer behind other layers.
- **CreateBehindHookLayer** (V36) — Create a layer behind all existing layers
- **CreateBehindLayer** — Create a new layer behind all existing layers.
- **CreateUpfrontHookLayer** (V36) — Create a layer on top of existing layers
- **CreateUpfrontLayer** — Create a new layer on top of existing layers.
- **DeleteLayer** — Delete layer from layer list.
- **DisposeLayerInfo** — Return all memory for LayerInfo to memory pool.
- **DoHookClipRects** (V39) — Do the given hook for each of the ClipRects.
- **EndUpdate** — Remove damage list and restore state of layer to normal.
- **FreeClipRect** — Release a ClipRect built by AllocClipRect().
- **InstallClipRegion** — Install clip region in layer.
- **InstallLayerHook** (V36) — Safely install a new layer backfill hook.
- **InstallLayerInfoHook** (V39) — Install a backfill hook for non-layer.
- **LockLayer** — Lock layer to make changes to ClipRects.
- **LockLayerInfo** — Lock the Layer_Info structure.
- **LockLayers** — Lock all layers from graphics output.
- **MoveLayer** — Move layer to new position in BitMap.
- **MoveLayerInFrontOf** — Put layer in front of another layer.
- **MoveSizeLayer** (V36) — Position/size layer.
- **NewLayerInfo** — Allocate and Initialize full Layer_Info structure.
- **ScrollLayer** — Scroll around in a SuperBitMap, translate coordinates
- **SizeLayer** — Change the size of this layer.
- **SortLayerCR** (V39) — Sort the layer's cliprects for scroll raster.
- **SwapBitsRastPortClipRect** — Swap bits between common bitmap
- **UnlockLayer** — Unlock layer and allow graphics routines to use it.
- **UnlockLayerInfo** — Unlock the Layer_Info structure.
- **UnlockLayers** — Unlock all layers from graphics output.
- **UpfrontLayer** — Put layer in front of all other layers.
- **WhichLayer** — Which layer is this point in?

## Functions

### layers.library/AllocClipRect

**Build a ClipRect.**

**Synopsis:**
```c
cliprect = AllocClipRect( li )

struct ClipRect *AllocClipRect( struct Layer_Info * );
```

**Description:**
This function allocates a new ClipRect from a Layer_Info
structure and returns a pointer to the ClipRect. The
ClipRect is initialized up to the cliprect bounds.

This cliprect belongs to the given Layer_Info structure
and must be released before the LayerInfo gets released.

Note: this function used to be private, since you should never
play with layer cliprects yourself and never attach this cliprect
to a layer yourself. Now it is public, with the only purpose of
being of support in generating alpha cliprects to be used with
ChangeLayerAlpha(), LAYA_AlphaClips or "alpha hooks" for custom
layer transparency.

**Inputs:**
li - pointer to a LayerInfo to allocate the ClipRect from.

**Result:**
cliprect - a pointer to a ClipRect structure or NULL
           in case the system runs out of memory

**Bugs:**


**See also:** FreeClipRect, ChangeLayerAlpha, graphics/clip.h

---

### layers.library/BeginUpdate

**Prepare to repair damaged layer.**

**Synopsis:**
```c
result = BeginUpdate( l )

LONG BeginUpdate( struct Layer * );
```

**Description:**
Convert damage list to ClipRect list and swap in for the
programmer to redraw through. The idea is to only render in the
"damaged" areas, saving time over redrawing all of the layer.
The layer is locked against changes made by the layer library.

**Inputs:**
l - pointer to a layer

**Result:**
result - TRUE if damage list converted to ClipRect list successfully
         FALSE if list conversion aborted (probably out of memory)

**Bugs:**
If BeginUpdate() returns FALSE, programmer must abort the attempt to
refresh this layer and instead call EndUpdate( l, FALSE ) to restore
original ClipRects and damage list.

**See also:** EndUpdate, graphics/layers.h, graphics/clip.h

---

### layers.library/BehindLayer

**Put layer behind other layers.**

**Synopsis:**
```c
result = BehindLayer( dummy, l )

LONG BehindLayer( LONG, struct Layer * );
```

**Description:**
Move this layer to the most behind position swapping bits
in and out of the display with other layers.
If other layers are REFRESH then collect their damage lists and
set the LAYERREFRESH bit in the Flags fields of those layers that
may be revealed.  If this layer is a backdrop layer then
put this layer behind all other backdrop layers.
If this layer is NOT a backdrop layer then put in front of the
top backdrop layer and behind all other layers.
If this layer is a staytop layer then put in front of the top
non-staytop layer and behind all other staytop layers.

Note: this operation may generate refresh events in other layers
   associated with this layer's Layer_Info structure.

**Inputs:**
dummy - unused
l - pointer to a layer

**Result:**
result - TRUE if operation successful
         FALSE if operation unsuccessful (probably out of memory)

**Bugs:**


**See also:** graphics/layers.h, graphics/clip.h

---

### layers.library/CreateBehindHookLayer (V36)

**Create a layer behind all existing layers
                         using supplied callback BackFill hook.**

**Synopsis:**
```c
result = CreateBehindHookLayer( li,bm,x0,y0,x1,y1,flags,hook[,bm2] )

struct Layer *CreateBehindHookLayer( struct Layer_Info *,
    struct BitMap *, LONG, LONG, LONG, LONG, LONG,
    struct Hook *, ... );
```

**Description:**
Create a new layer of position and size (x0,y0)-(x1,y1)
Make this layer of type found in flags.
Install Layer->BackFill callback Hook.
If SuperBitMap, use bm2 as pointer to real SuperBitMap,
and copy contents of SuperBitMap into display layer.
If this layer is a backdrop layer then place it behind all
other layers including other backdrop layers. If this is
not a backdrop layer then place it behind all non-backdrop
layers. If this is a staytop layer then place it behind
all other staytop layers, but not behind any other layer.

Note: when using a SuperBitMap, you should also set LAYERSUPER flag.

**Inputs:**
li - pointer to Layer_Info structure
bm - pointer to common BitMap used by all layers
x0,y0 - upper left hand corner of layer
x1,y1 - lower right hand corner of layer
flags - various types of layers supported as bit sets
        (for bit definitions, see graphics/layers.h)
hook -  Layer->BackFill callback Hook (see InstallLayerHook())

        If hook is LAYERS_BACKFILL, the default backfill is
        used for the layer (same as pre-2.0).

        As of V39:
        If hook is LAYERS_NOBACKFILL, the layer will not be
        backfilled (NO-OP).

bm2 - pointer to optional SuperBitMap

**Result:**
result - pointer to Layer structure if successful
         NULL if not successful

**Bugs:**


**See also:** InstallLayerHook, DeleteLayer, graphics/layers.h, graphics/clip.h,
graphics/gfx.h, utility/hooks.h

---

### layers.library/CreateBehindLayer

**Create a new layer behind all existing layers.**

**Synopsis:**
```c
result = CreateBehindLayer( li,bm,x0,y0,x1,y1,flags[,bm2] )

struct Layer *CreateBehindLayer( struct Layer_Info *, struct BitMap *,
    LONG, LONG, LONG, LONG, LONG, ... );
```

**Description:**
Create a new Layer of position and size (x0,y0)-(x1,y1)
Make this layer of type found in flags.
If SuperBitMap, use bm2 as pointer to real SuperBitMap,
and copy contents of SuperBitMap into display layer.
If this layer is a backdrop layer then place it behind all
other layers including other backdrop layers. If this is
not a backdrop layer then place it behind all nonbackdrop
layers. If this is a staytop layer then place it behind
all other staytop layers, but not behind any other layer.

Note: when using a SuperBitMap, you should also set LAYERSUPER flag.

**Inputs:**
li - pointer to Layer_Info structure
bm - pointer to common BitMap used by all layers
x0,y0 - upper left hand corner of layer
x1,y1 - lower right hand corner of layer
flags - various types of layers supported as bit sets
        (for bit definitions, see graphics/layers.h)
bm2 - pointer to optional SuperBitMap

**Result:**
result - pointer to Layer structure if successful
         NULL if not successful

**Bugs:**


**See also:** DeleteLayer, graphics/layers.h, graphics/clip.h, graphics/gfx.h

---

### layers.library/CreateUpfrontHookLayer (V36)

**Create a layer on top of existing layers
                          using supplied callback BackFill hook.**

**Synopsis:**
```c
result = CreateUpfrontHookLayer( li,bm,x0,y0,x1,y1,flags,hook[,bm2] )

struct Layer *CreateUpfrontHookLayer( struct Layer_Info *,
    struct BitMap *, LONG, LONG, LONG, LONG, LONG,
    struct Hook *, ... );
```

**Description:**
Create a new Layer of position and size (x0,y0)-(x1,y1)
and place it on top of all other layers of the same type
(backdrop, normal or staytop).
Make this layer of type found in flags.
Install Layer->BackFill callback hook.
If SuperBitMap, use bm2 as pointer to real SuperBitMap,
and copy contents of SuperBitMap into display layer.

Note: when using a SuperBitMap, you should also set LAYERSUPER flag.

**Inputs:**
li - pointer to Layer_Info structure
bm - pointer to common BitMap used by all layers
x0,y0 - upper left hand corner of layer
x1,y1 - lower right hand corner of layer
flags - various types of layers supported as bit sets
hook -  Layer->BackFill callback Hook (see InstallLayerHook())

        If hook is LAYERS_BACKFILL, the default backfill is
        used for the layer (same as pre-2.0).

        As of V39:
        If hook is LAYERS_NOBACKFILL, the layer will not be
        backfilled (NO-OP).

bm2 - pointer to optional SuperBitMap

**Result:**
result - pointer to Layer structure if successful
         NULL if not successful

**Bugs:**


**See also:** InstallLayerHook, DeleteLayer, graphics/layers.h, graphics/clip.h,
graphics/gfx.h, utility/hooks.h

---

### layers.library/CreateUpfrontLayer

**Create a new layer on top of existing layers.**

**Synopsis:**
```c
result = CreateUpfrontLayer( li,bm,x0,y0,x1,y1,flags[,bm2] )

struct Layer *CreateUpfrontLayer( struct Layer_Info *,struct BitMap *,
    LONG, LONG, LONG, LONG, LONG, ... );
```

**Description:**
Create a new Layer of position and size (x0,y0)-(x1,y1)
and place it on top of all other layers of the same type
(backdrop, normal or staytop).
Make this layer of type found in flags.
If SuperBitMap, use bm2 as pointer to real SuperBitMap,
and copy contents of SuperBitMap into display layer.

Note: when using a SuperBitMap, you should also set LAYERSUPER flag.

**Inputs:**
li - pointer to Layer_Info structure
bm - pointer to common BitMap used by all layers
x0,y0 - upper left hand corner of layer
x1,y1 - lower right hand corner of layer
flags - various types of layers supported as bit sets
bm2 - pointer to optional SuperBitMap

**Result:**
result - pointer to Layer structure if successful
         NULL if not successful

**Bugs:**


**See also:** DeleteLayer, graphics/layers.h, graphics/clip.h, graphics/gfx.h

---

### layers.library/DeleteLayer

**Delete layer from layer list.**

**Synopsis:**
```c
result = DeleteLayer( dummy, l )

LONG DeleteLayer( LONG, struct Layer * );
```

**Description:**
Remove this layer from the list of layers.  Release memory
associated with it.  Restore other layers that may have been
obscured by it.  Trigger refresh in those that may need it.
If this is a SuperBitMap layer make sure SuperBitMap is current.
The SuperBitMap is not removed from the system but is available
for program use even though the rest of the layer information has
been deallocated.

**Inputs:**
dummy - unused
l - pointer to a layer

**Result:**
result - TRUE if layer successfully deleted from the system
         FALSE if layer not deleted (probably out of memory)

**Bugs:**


**See also:** graphics/layers.h, graphics/clip.h

---

### layers.library/DisposeLayerInfo

**Return all memory for LayerInfo to memory pool.**

**Synopsis:**
```c
DisposeLayerInfo( li )

VOID DisposeLayerInfo( struct Layer_Info * );
```

**Description:**
Return LayerInfo and any other memory attached to this LayerInfo
to memory allocator.

Note: if you wish to delete the layers associated with this Layer_Info
      structure, remember to call DeleteLayer() for each of the layers
      before calling DisposeLayerInfo().

**Inputs:**
li - pointer to Layer_Info structure

**Example:**
```c
-- delete the layers associated with this Layer_Info structure --

DeleteLayer(0,simple_layer);
DeleteLayer(0,smart_layer);

-- see docs on DeleteLayer about deleting SuperBitMap layers --

my_super_bitmap_ptr = super_layer->SuperBitMap;
DeleteLayer(0,super_layer);

-- now dispose of the Layer_Info structure itself --

DisposeLayerInfo(li);
```

**Bugs:**


**See also:** DeleteLayer, graphics/layers.h

---

### layers.library/DoHookClipRects (V39)

**Do the given hook for each of the ClipRects.**

**Synopsis:**
```c
DoHookClipRects( hook, rport, rect )

VOID DoHookClipRects( CONST struct Hook *, struct RastPort *,
                      CONST struct Rectangle * );
```

**Description:**
This function will call the given hook for each cliprect in the
layer that can be rendered into.  This is how the backfill hook
in Layers is implemented.  This means that hidden simple refresh
cliprects will be ignored.  It will call the SuperBitMap cliprects,
smart refresh off-screen cliprects, and all on screen cliprects.
If the 'rect' parameter is not NULL, the cliprects are bounded to
the rectangle given.

**Inputs:**
hook - pointer to layer callback hook which will be called, with
       object == pointer to the RastPort the hook shall render to
       and message == pointer to a BackFillMessage structure.

       The BackFillMessage structure is defined as

       struct BackFillMessage
       {
           struct Layer     *Layer;    /* RastPort's layer */
           struct Rectangle  Bounds;   /* Rectangle to fill */
           LONG              OffsetX;  /* Pattern X offset */
           LONG              OffsetY;  /* Pattern Y offset */
       };

       This hook should fill the rectangle in the RastPort defined by
       the message's Bounds with the backfill pattern appropriate for
       the message's OffsetX and OffsetY.

       If hook is LAYERS_BACKFILL, the default backfill is used
       for the layer.

       If hook is LAYERS_NOBACKFILL, the layer will not be
       backfilled (NO-OP).

rport - a pointer to the RastPort that is to be operated on.
        This function will lock the layer if the RastPort is
        layered.
        If 'rport' is not layered your hook will be called with
        the rectangle as passed, the RastPort, and a NULL layer.

rect - the bounding rectangle that should be used on the layer.
       This rectangle "clips" the cliprects to the bounds given.
       If this is NULL, no bounding will take place.
       *MUST* not be NULL if the RastPort is not layered!

**Notes:**
The RastPort you are passed back is the same one passed to the
function.  You should *not* use "layered" rendering functions
on this RastPort.  Generally, you will wish to do BitMap operations
such as BltBitMap().  The callback is a raw, low-level rendering
callback.  If you need to call a rendering operation with a
RastPort, make sure you use a copy of the RastPort and NULL its
Layer pointer.

**See also:** graphics/clip.h utility/hooks.h

---

### layers.library/EndUpdate

**Remove damage list and restore state of layer to normal.**

**Synopsis:**
```c
EndUpdate( l, flag )

VOID EndUpdate( struct Layer *, UWORD );
```

**Description:**
After the programmer has redrawn his picture he calls this
routine to restore the ClipRects to point to his standard
layer tiling. The layer is then unlocked for access by the
layer library.

Note: use flag = FALSE if you are only making a partial update.
You may use the other region functions (graphics functions such as
OrRectRegion(), AndRectRegion(), and XorRectRegion()) to clip adjust
the DamageList to reflect a partial update.

**Inputs:**
l - pointer to a layer
flag - use TRUE if update was completed. The damage list is cleared.
       use FALSE if update not complete. The damage list is retained.

**Example:**
```c
-- begin update for first part of two-part refresh --
BeginUpdate(my_layer);

-- do some refresh, but not all --
my_partial_refresh_routine(my_layer);

-- end update, false (not completely done refreshing yet) --
EndUpdate(my_layer, FALSE);

-- begin update for last part of refresh --
BeginUpdate(my_layer);

-- do rest of refresh --
my_complete_refresh_routine(my_layer);

-- end update, true (completely done refreshing now) --
EndUpdate(my_layer, TRUE);
```

**Bugs:**
In V40 or below, EndUpdate() could have failed to re-install
the user clip region in low-memory situations. This has been
fixed for V45. V45 may leave the layer cliprects in sub-
optimal, but valid state if it runs low on memory.

**See also:** BeginUpdate, graphics/layers.h, graphics/clip.h

---

### layers.library/FreeClipRect

**Release a ClipRect built by AllocClipRect().**

**Synopsis:**
```c
FreeClipRect( li, cliprect )

VOID FreeClipRect( struct Layer_Info *, struct ClipRect * );
```

**Description:**
Disposes a ClipRect that is no longer required by the caller.
The ClipRect is either released immediately into the free memory
pool, or recycled by layers as soon as clipping operations are
performed in the same LayerInfo.

This function also releases the BitMap linked to by the ClipRect.
In case you disposed this BitMap already, make sure that you
NULL cliprect->BitMap before calling this function.

Note: this function used to be private, since you should never
play with layer cliprects yourself and never attach this cliprect
to a layer yourself. Now it is public, with the only purpose of
being of support in generating alpha cliprects to be used with
ChangeLayerAlpha(), LAYA_AlphaClips or "alpha hooks" for custom
layer transparency.

**Inputs:**
li - pointer to the LayerInfo the ClipRect has been allocated
     from by means of AllocClipRect()

**Result:**


**Bugs:**


**See also:** AllocClipRect, ChangeLayerAlpha, graphics/clip.h

---

### layers.library/InstallClipRegion

**Install clip region in layer.**

**Synopsis:**
```c
oldclipregion = InstallClipRegion( l,  region )

struct Region *InstallClipRegion( struct Layer *,
                                  CONST struct Region * );
```

**Description:**
Installs a transparent clip region in the layer. All
subsequent graphics calls will be clipped to this region.
You MUST remember to call InstallClipRegion(l,NULL) before
calling DeleteLayer(l) or the Intuition function CloseWindow()
if you have installed a non-NULL ClipRegion in l.

**Inputs:**
l - pointer to a layer
region - pointer to a region

**Result:**
oldclipregion - the pointer to the previous ClipRegion that was
    installed. Returns NULL if no previous ClipRegion installed.
    Returns "region" in case it could not install the user clip
    region, for example because it ran out of memory.

**Notes:**
In V44 and before, if the system ran out of memory during this
function, it would not install the user cliprects, but would also
sweep away the previously installed cliprects, hence would leave
the layer completely unclipped. This has been fixed in V45.
Note that you should therefore check the result code against
your clip region. In case they are equal, the clip region
could not be installed.
Removing a clip region (i.e. installing NULL) will always work.

**Bugs:**
If you try to remove a user clip region while the layer is
updating, i.e. BeginUpdate() has been called, then this
function may erroneously insert cliprects that are not
part of the damage list into the layer if layers runs low
on memory. Note that calling InstallClipRegion() under
this condition is discouraged.
If this function runs low on memory for removing a clip
region otherwise, the resulting layer will be still in valid
state, but the cliprect layout may be sub-optimal. This gets
fixed on the next layer resize or depth-arrange operation.

**See also:** BeginUpdate, EndUpdate,
graphics/layers.h, graphics/clip.h, graphics/regions.h

---

### layers.library/InstallLayerHook (V36)

**Safely install a new layer backfill hook.**

**Synopsis:**
```c
oldhook = InstallLayerHook( layer, hook )

struct Hook *InstallLayerHook( struct Layer *, struct Hook * );
```

**Description:**
Installs a new layer backfill hook, waiting until it is safe to do
so. Locks the layer while substituting the new hook and removing the
old one. If a new hook is not provided, will install the default layer
backfill hook.

**Inputs:**
layer - pointer to the layer in which to install the backfill hook.
hook - pointer to layer callback hook which will be called, with
       object == pointer to the RastPort the hook shall render to
       and message == pointer to a BackFillMessage structure.

       The BackFillMessage structure is defined as

       struct BackFillMessage
       {
           struct Layer     *Layer;    /* This layer */
           struct Rectangle  Bounds;   /* Rectangle to fill */
           LONG              OffsetX;  /* Pattern X offset */
           LONG              OffsetY;  /* Pattern Y offset */
       };

       This hook should fill the rectangle in the RastPort defined by
       the message's Bounds with the backfill pattern appropriate for
       the message's OffsetX and OffsetY.

       If hook is LAYERS_BACKFILL, the default backfill is used
       for the layer (same as pre-2.0).

       As of V39:
       If hook is LAYERS_NOBACKFILL, the layer will not be
       backfilled (NO-OP).

**Result:**
oldhook - pointer to the layer backfill hook that was previously
          active.  Returns NULL (i.e. LAYERS_BACKFILL) if it was
          the default hook.
          In V39, it could return 1 (i.e. LAYERS_NOBACKFILL) if
          there was no hook.

**Example:**
```c
The following hook is a very simple example that does rather little
but gives the basis idea of what is going on.

*
* This is the code called by the layer hook...
* Note that some other setup is required for this to work, including
* the definition of the PrivateData structure (pd_...) and the
* definition of the BitMapPattern structure (bmp_...)
*
CoolHook:       xdef    CoolHook
                movem.l d2-d7/a3-a6,-(sp) ; Save these...
                move.l  h_SubEntry(a0),a4 ; (my private data #1 here)
                move.l  h_Data(a0),a5     ; Put data into address reg
*
* Now, we do the rendering...
* Note that the layer may not be important...  But it is here...
*
                move.l  (a1)+,a0          ; Get the layer...
*
* a1 now points at the rectangle...
*
                move.l  pd_GfxBase(a4),a6 ; Point at GfxBase
                move.l  bmp_Pattern(a5),d0; Get PatternBitMap
                beq     SimpleCase        ; None?  Simple (0) case
*
* Now do the complex case of a pattern...
*
                move.l  a1,a3             ; Pointer to rectangle
                addq.l  #8,a1             ; Get past rectangle
                move.l  (a1)+,d2          ; X Offset (For pattern)
                move.l  (a1)+,d3          ; Y Offset
        ;
        ; Whatever complex blitting you would do in the complex case
        ; goes here
        ;
*
* No bitmap, so just do the simple (0) minterm case...
*
SimpleCase:     moveq.l #0,d2             ; Clear d2
                move.w  ra_MinX(a1),d2    ; Get X pos
*
                moveq.l #0,d3
                move.w  ra_MinY(a1),d3    ; Get Y pos
*
                moveq.l #0,d4
                move.w  ra_MaxX(a1),d4
                sub.l   d2,d4
                addq.l  #1,d4             ; Get X size
*
                moveq.l #0,d5
                move.w  ra_MaxY(a1),d5
                sub.l   d3,d5
                addq.l  #1,d5             ; Get Y size
*
                move.l  d2,d0             ; X Source
                move.l  d3,d1             ; Y Source
                moveq.l #0,d6             ; NULL minterm
                moveq.l #-1,d7            ; FF mask
*
                move.l  rp_BitMap(a2),a1  ; Get bitmap
                move.l  a1,a0
                CALLSYS BltBitMap         ; Do the backfill-0
*
HookDone:       movem.l (sp)+,d2-d7/a3-a6 ; Restore
                rts
```

**Notes:**
You should *not* use "layered" rendering functions on the RastPort you
are passed back.  Generally, you will wish to do BitMap operations
such as BltBitMap().  The callback is a raw, low-level rendering
callback.  If you need to call a rendering operation with a RastPort,
make sure you use a copy of the RastPort and NULL its Layer pointer.

**Bugs:**


**See also:** graphics/clip.h utility/hooks.h

---

### layers.library/InstallLayerInfoHook (V39)

**Install a backfill hook for non-layer.**

**Synopsis:**
```c
oldhook = InstallLayerInfoHook( li, hook )

struct Hook *InstallLayerInfoHook( struct Layer_Info *,
                                   CONST struct Hook * );
```

**Description:**
This function will install a backfill hook for the Layer_Info
structure passed.  This backfill hook will be used to clear the
background area where no layer exists.  The hook function is
passed the RastPort and the bounds just like the layer backfill
hook.  Note that this hook could be called for any layer.

**Inputs:**
li - pointer to the LayerInfo in which to install the backfill hook.

hook - pointer to layer callback hook which will be called, with
       object == pointer to the RastPort the hook shall render to
       and message == pointer to a BackFillMessage structure.

       The BackFillMessage structure is defined as

       struct BackFillMessage
       {
           struct Layer     *Layer;    /* Undefined, ignore this */
           struct Rectangle  Bounds;   /* Rectangle to fill */
           LONG              OffsetX;  /* Undefined, ignore this */
           LONG              OffsetY;  /* Undefined, ignore this */
       };

       This hook should fill the rectangle in the RastPort defined by
       the message's Bounds with the backfill pattern appropriate for
       the given rectangle's coordinates.
       The message's Layer and OffsetX/Y fields have no meaning for
       a LayerInfo backfill hook.

       If hook is LAYERS_BACKFILL, the default backfill is used
       (same as pre-2.0).

       If hook is LAYERS_NOBACKFILL, there will be no backfill
       (NO-OP).

**Result:**
oldhook - Returns the backfill hook that was in the LayerInfo.
          Returns LAYERS_BACKFILL if the default was installed.
          Returns LAYERS_NOBACKFILL if there was a NO-OP hook.
          Returns -1 if there was some failure.

**Example:**
```c
See the example in InstallLayerHook().  Note that both the Layer
pointer and the OffsetX/Y values are not available in the
LayerInfo backfill hook.
```

**Notes:**
When the hook is first installed, it is *NOT* called.  It is up
to the application to know if it is safe to fill in the area.
Since the hook will be called when a layer is deleted, the easiest
way to have layers call this hook is to create and delete a backdrop
layer that is the size of the area.

Also, note that currently the first long word of the hook message
contains an undefined value. This value may look like a layer
pointer. It is *not* a layer pointer.

You should *not* use "layered" rendering functions on the RastPort you
are passed back.  Generally, you will wish to do BitMap operations
such as BltBitMap().  The callback is a raw, low-level rendering
callback.  If you need to call a rendering operation with a RastPort,
make sure you use a copy of the RastPort and NULL its Layer pointer.

**See also:** InstallLayerHook

---

### layers.library/LockLayer

**Lock layer to make changes to ClipRects.**

**Synopsis:**
```c
LockLayer( dummy, l )

VOID LockLayer( LONG, struct Layer * );
```

**Description:**
Make this layer unavailable for other tasks to use.
If another task is already using this layer then wait for
it to complete and then reserve the layer for your own use.
(This function does the same as graphics.library/LockLayerRom().)

Note: if you wish to lock MORE THAN ONE layer at a time, you
must call LockLayerInfo() before locking those layers and
then call UnlockLayerInfo() when you have finished. This
is to prevent system "deadlocks".

Further Note: while you hold the lock on a layer, Intuition will block
on operations such as sizing, dragging and depth arranging windows and
displaying menus in this layer's screen. It is recommended that
YOU do not make Intuition function calls while the layer is locked.

**Inputs:**
dummy - unused
l - pointer to a layer

**Bugs:**


**See also:** UnlockLayer, LockLayerInfo, UnlockLayerInfo,
graphics.library/LockLayerRom, graphics/layers.h, graphics/clip.h

---

### layers.library/LockLayerInfo

**Lock the Layer_Info structure.**

**Synopsis:**
```c
LockLayerInfo( li )

VOID LockLayerInfo( struct Layer_Info * );
```

**Description:**
Before doing an operation that requires the Layer_Info
structure, make sure that no other task is also using the
Layer_Info structure.  LockLayerInfo() returns when the
LayerInfo belongs to the calling task.  There should be
a matching UnlockLayerInfo() for every LockLayerInfo().

Note: Most layer routines presently LockLayerInfo() when they
start up and UnlockLayerInfo() as they exit.  Programmers
will need to use these Lock/Unlock routines if they wish
to do something with the Layer structure that is not
supported by the layers.library.

**Inputs:**
li - pointer to Layer_Info structure

**Bugs:**


**See also:** UnlockLayerInfo, graphics/layers.h

---

### layers.library/LockLayers

**Lock all layers from graphics output.**

**Synopsis:**
```c
LockLayers( li )

VOID LockLayers( struct Layer_Info * );
```

**Description:**
First calls LockLayerInfo().
Make all layers in this layer list locked.

**Inputs:**
li - pointer to Layer_Info structure

**Bugs:**
V44 and below might have failed on a low-memory situation.
In this case, layer cliprects, especially user cliprects
might have been un-installed and incorrect. This has been
fixed in V45.
As a side effect, LockLayers() removes all user- and
damage-list constraints of the layer such that it will
become draw-able in its full rectangle. Whether this side
effect is desirable or not is arguable, but we leave it
like this for now for backwards compatibility. The cliprect
layout LockLayers() results in is sub-optimal, but correct.
UnlockLayers() restores the original cliprect layout.

**See also:** UnlockLayer, LockLayerInfo, graphics/layers.h

---

### layers.library/MoveLayer

**Move layer to new position in BitMap.**

**Synopsis:**
```c
result = MoveLayer( dummy, l, dx, dy )

LONG MoveLayer( LONG, struct Layer *, LONG, LONG );
```

**Description:**
Move this layer to new position in shared BitMap.
If any refresh layers become revealed, collect damage and
set REFRESH bit in layer Flags.

**Inputs:**
dummy - unused
l - pointer to a layer
dx - delta to add to current x position
dy - delta to add to current y position

**Result:**
result - TRUE if operation successful
         FALSE if failed (out of memory)

**Bugs:**
May not handle (dx,dy) which attempts to move the layer outside the
layer's RastPort->BitMap bounds. However, starting with V45, you can
use SetLayerInfoBounds() to enable layers to cross the bitmap bounds.

**See also:** graphics/layers.h, graphics/clip.h

---

### layers.library/MoveLayerInFrontOf

**Put layer in front of another layer.**

**Synopsis:**
```c
result = MoveLayerInFrontOf( layertomove, targetlayer )

LONG MoveLayerInFrontOf( struct Layer *, struct Layer * );
```

**Description:**
Move this layer in front of target layer, swapping bits
in and out of the display with other layers.
If this is a refresh layer then collect damage list and
set the LAYERREFRESH bit in layer->Flags if redraw required.

Note: this operation may generate refresh events in other layers
      associated with this layer's Layer_Info structure.

**Inputs:**
layertomove - pointer to layer which should be moved
targetlayer - pointer to target layer in front of which to move layer

**Result:**
result - TRUE if operation successful
         FALSE if operation unsuccessful (probably out of memory)

**Bugs:**


**See also:** graphics/layers.h

---

### layers.library/MoveSizeLayer (V36)

**Position/size layer.**

**Synopsis:**
```c
result = MoveSizeLayer( layer, dx, dy, dw, dh )

LONG MoveSizeLayer( struct Layer *, LONG, LONG, LONG, LONG );
```

**Description:**
Change upper left and lower right position of layer.

**Inputs:**
l - pointer to a layer
dx,dy - change upper left corner by (dx,dy)
dw,dh - change size by (dw,dh)

**Result:**
result - TRUE if operation successful
         FALSE if failed (due to out of memory)
         FALSE if failed (due to illegal layer bounds)

**Bugs:**


**See also:** graphics/layers.h, graphics/clip.h

---

### layers.library/NewLayerInfo

**Allocate and Initialize full Layer_Info structure.**

**Synopsis:**
```c
result = NewLayerInfo()

struct Layer_Info *NewLayerInfo( VOID );
```

**Description:**
Allocate memory required for full Layer_Info structure.
Initialize Layer_Info structure in preparation to use
other layer operations on this list of layers.
Make the LayerInfo unlocked (open).

**Inputs:**
None

**Result:**
result - pointer to Layer_Info structure if successful
         NULL if not enough memory

**Bugs:**


**See also:** graphics/layers.h

---

### layers.library/ScrollLayer

**Scroll around in a SuperBitMap, translate coordinates
               in non-SuperBitMap layer.**

**Synopsis:**
```c
ScrollLayer( dummy, l, dx, dy )

VOID ScrollLayer( LONG, struct Layer *, LONG, LONG );
```

**Description:**
For a SuperBitMap Layer:
Update the SuperBitMap from the layer display, then copy bits
between Layer and SuperBitMap to reposition layer over different
portion of SuperBitMap.

For non-SuperBitMap layers, all (x,y) pairs are adjusted by
the scroll (x,y) value in the layer.  To cause (0,0) to actually
be drawn at (3,10) use ScrollLayer(-3,-10). This can be useful
along with InstallClipRegion() to simulate Intuition GZZWindows
without the overhead of an extra layer.

**Inputs:**
dummy - unused
l - pointer to a layer
dx - delta to add to current x scroll value
dy - delta to add to current y scroll value

**Bugs:**
May not handle (dx,dy) which attempts to move the layer outside the
layer's SuperBitMap bounds.

**See also:** graphics/layers.h

---

### layers.library/SizeLayer

**Change the size of this layer.**

**Synopsis:**
```c
result = SizeLayer( dummy, l, dx, dy )

LONG SizeLayer( LONG, struct Layer *, LONG, LONG );
```

**Description:**
Change the size of this layer by (dx,dy). The lower right hand
corner is extended to make room for the larger layer.
If there is a SuperBitMap for this layer then copy pixels into
or out of the layer depending on whether the layer increases or
decreases in size.  Collect damage list for those layers that may
need to be refreshed if damage occurred.

**Inputs:**
dummy - unused
l - pointer to a layer
dx - delta to add to current x size
dy - delta to add to current y size

**Result:**
result - TRUE if operation successful
         FALSE if failed (out of memory)

**Bugs:**


**See also:** graphics/layers.h, graphics/clip.h

---

### layers.library/SortLayerCR (V39)

**Sort the layer's cliprects for scroll raster.**

**Synopsis:**
```c
SortLayerCR(layer, dx, dy)

VOID SortLayerCR(struct Layer *, WORD, WORD);
```

**Description:**
This function will sort the given layer's cliprects such that a
scroll in the direction given will be optimal.

**Inputs:**
layer   - the layer to be sorted
dx      - x scroll offset
dy      - y scroll offset

**Notes:**
This routine is for Layers/Graphics internal use only.
The layer must be locked before calling this routine.

---

### layers.library/SwapBitsRastPortClipRect

**Swap bits between common bitmap
                            and obscured ClipRect.**

**Synopsis:**
```c
SwapBitsRastPortClipRect( rp, cr )

VOID SwapBitsRastPortClipRect( struct RastPort *, struct ClipRect * );
```

**Description:**
Support routine useful for those that need to do some
operations not done by the layer library.  Allows programmer
to swap the contents of a small BitMap with a subsection of
the display. This is accomplished without using extra memory.
The bits in the display RastPort are exchanged with the
bits in the ClipRect's BitMap.

Note: the ClipRect structures which the layer library allocates are
actually a little bigger than those described in the graphics/clip.h
include file.  So be warned that it is not a good idea to have
instances of ClipRects in your code.

**Inputs:**
rp - pointer to RastPort
cr - pointer to ClipRect to swap bits with

**Notes:**
Because the blit operation started by this function is done
asynchronously, it is imperative that a WaitBlit() be performed
before releasing or using the processor to modify any of the
associated structures.

**Bugs:**


**See also:** graphics/clip.h, graphics/rastport.h

---

### layers.library/UnlockLayer

**Unlock layer and allow graphics routines to use it.**

**Synopsis:**
```c
UnlockLayer( l )

VOID UnlockLayer( struct Layer * );
```

**Description:**
When finished changing the ClipRects or whatever you were
doing with this layer you must call UnlockLayer() to allow
other tasks to proceed with graphic output to the layer.

**Inputs:**
l - pointer to a layer

**Bugs:**


**See also:** graphics/layers.h, graphics/clip.h

---

### layers.library/UnlockLayerInfo

**Unlock the Layer_Info structure.**

**Synopsis:**
```c
UnlockLayerInfo( li )

VOID UnlockLayerInfo( struct Layer_Info * );
```

**Description:**
After the operation is complete that required a LockLayerInfo(),
unlock the Layer_Info structure so that other tasks may affect
the layers.

**Inputs:**
li - pointer to the Layer_Info structure

**Bugs:**


**See also:** LockLayerInfo, graphics/layers.h

---

### layers.library/UnlockLayers

**Unlock all layers from graphics output.
                Restart graphics output to layers that have
                been waiting.**

**Synopsis:**
```c
ok = UnlockLayers( li )

BOOL UnlockLayers( struct Layer_Info * );
```

**Description:**
Make all layers in this layer list unlocked.
Then calls UnlockLayerInfo().

**Inputs:**
li - pointer to the Layer_Info structure

**Result:**
ok - a boolean TRUE/FALSE condition for backwards
     compatibility. V45 and above will always return TRUE.

**Bugs:**
V44 and below might have failed on a low-memory situation.
In this case, layer cliprects, especially user cliprects
might have been un-installed and incorrect. This has been
fixed in V45.

**See also:** LockLayers, UnlockLayer, graphics/layers.h

---

### layers.library/UpfrontLayer

**Put layer in front of all other layers.**

**Synopsis:**
```c
result = UpfrontLayer( dummy, l )

LONG UpfrontLayer( LONG, struct Layer * );
```

**Description:**
Move this layer to the most upfront position swapping bits
in and out of the display with other layers.
If this is a refresh layer then collect damage list and
set the LAYERREFRESH bit in layer->Flags if redraw required.
By clearing the LAYERBACKDROP bit in the layer's Flags you may
bring a backdrop layer up to the front of all other layers;
otherwise a backdrop layer will only be brought up to front of
all other backdrop layers (if any exist).
Similarly, a non-staytop layer can only be moved to the front
of all other non-staytop layers; to bring it in front of
staytop layers (if any exist), set first the LAYERSTAYTOP bit
in the layer's Flags.

Note: this operation may generate refresh events in other layers
      associated with this layer's Layer_Info structure.

**Inputs:**
dummy - unused
l - pointer to a layer

**Result:**
result - TRUE if operation successful
         FALSE if operation unsuccessful (probably out of memory)

**Bugs:**


**See also:** graphics/layers.h

---

### layers.library/WhichLayer

**Which layer is this point in?**

**Synopsis:**
```c
layer = WhichLayer( li, x, y )

struct Layer *WhichLayer( struct Layer_Info *, WORD, WORD );
```

**Description:**
Starting at the topmost layer check to see if this point (x,y)
occurs in this layer. If it does return the pointer to this
layer. Return NULL if there is no layer at this point.

**Inputs:**
li - pointer to Layer_Info structure
(x,y) - coordinate in the BitMap

**Result:**
layer - pointer to the topmost layer that this point is in
        NULL if this point is not in a layer

**Notes:**
You should at least lock the LayerInfo of the layer or the
result is unpredictable as the layer arrangement may change
while this function is running.

**See also:** graphics/layers.h

---

## Obsolete Functions

*These functions are deprecated and should not be used in new code.*

### layers.library/FattenLayerInfo [OBSOLETE]

**Convert 1.0 LayerInfo to 1.1 LayerInfo.
OBSOLETE OBSOLETE OBSOLETE OBSOLETE OBSOLETE**

**Synopsis:**
```c
OBSOLETE OBSOLETE OBSOLETE OBSOLETE OBSOLETE
FattenLayerInfo( li )

LONG FattenLayerInfo( struct Layer_Info * );
OBSOLETE OBSOLETE OBSOLETE OBSOLETE OBSOLETE
```

**Description:**
As of V45, this function does nothing and returns TRUE. V45 no
longer requires additional information in the LayerInfo, but
nevertheless, this function *MUST NOT* be used for new code.
In case the system (Intuition, namely) must roll its own
LayerInfo, it is mandatory to call ThinLayerInfo() if you are
done with it as it releases some additional internal buffers.
NewLayerInfo() is the approved method for getting this structure.
When a program needs to give up the Layer_Info structure it must
call ThinLayerInfo() before freeing the memory. ThinLayerInfo()
is not necessary if New/DisposeLayerInfo() are used, however.

**Inputs:**
li - pointer to Layer_Info structure

**Bugs:**


**See also:** NewLayerInfo, ThinLayerInfo, DisposeLayerInfo, graphics/layers.h

---

### layers.library/InitLayers [OBSOLETE]

**Initialize Layer_Info structure.
OBSOLETE OBSOLETE OBSOLETE OBSOLETE OBSOLETE**

**Synopsis:**
```c
OBSOLETE OBSOLETE OBSOLETE OBSOLETE OBSOLETE
InitLayers( li )

VOID InitLayers( struct Layer_Info * );
OBSOLETE OBSOLETE OBSOLETE OBSOLETE OBSOLETE
```

**Description:**
Initialize Layer_Info structure in preparation to use
other layer operations on this list of layers.
Make the layers unlocked (open), available to layer operations.

**Inputs:**
li - pointer to Layer_Info structure

**Bugs:**


**See also:** NewLayerInfo, DisposeLayerInfo, graphics/layers.h

---

### layers.library/ThinLayerInfo [OBSOLETE]

**Convert 1.1 LayerInfo to 1.0 LayerInfo.
OBSOLETE OBSOLETE OBSOLETE OBSOLETE OBSOLETE**

**Synopsis:**
```c
OBSOLETE OBSOLETE OBSOLETE OBSOLETE OBSOLETE
ThinLayerInfo( li )

VOID ThinLayerInfo( struct Layer_Info * );
OBSOLETE OBSOLETE OBSOLETE OBSOLETE OBSOLETE
```

**Description:**
In V45, this function only flushes the cliprect scratch list
of the LayerInfo. New software MUST use DisposeLayerInfo()
instead.

**Inputs:**
li - pointer to Layer_Info structure

**Bugs:**


**See also:** DisposeLayerInfo, FattenLayerInfo, graphics/layers.h

---
