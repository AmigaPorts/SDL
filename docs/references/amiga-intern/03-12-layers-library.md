# The Layers Library

*From "Amiga Intern" (1992) by Kuhnert, Maelger, Schemmel. Abacus.*

### 3.1.12 The Layers Library

The "layers.library" is responsible for the complex Clipping and Refresh of overlapping software levels. The base address of the function is expected in A6.

Functions of the Layers Library 

BeginUpdate 

BehindLayer 

CreateBehindHookLayer 

CreateBehindLayer 

CreateUpfrontHookLayer 

CreateUpfrontLayer 

DeleteLayer 

DisposeLayerlnfo 

EndUpdate 

InstallClipRegion 

InstallLayerHook 

LockLayer 

LockLayerlnfo 

LockLayers 

MoveLayer 

MoveLayerlnFrontOf 

MoveSizeLayer 

NewLayerlnfo 

ScrollLayer 

SizeLayer 

SwapBitsRastPortClipRect 

UnlockLayer 

UnlockLayerlnfo 

UnlockLayers 

UpfrontLayer 

Description of the routines 

IBeginUpdate Begin layer update | 

Call: result =  BeginUpdate (  1 ) 

dO -78 (A6) aO

LONG result 

STRUCT Layer *1 

Function: Converts the DamageList to a  ClipRectList and adds it to 

the layer.

Parameters: 1  Layer 

Result : 0  Error (EndUpdate(l,0) call) 

| BehindLayer Put layer in the background | 

Call: result =  BehindLayer (   1 ) 

dO -54 (A6) al

LONG result 

STRUCT Layer *1 

Function: Moves the given layer behind all other layers. 

Parameters: 1  Layer 

Result: 0  Error 

ICreateBehindHookLayer Create layer with backfill hookl 

Cflll." result »  CreateBeMndHookLayer(ll,lm,xO,yO,xl,yl, flags, hook, fcm2) 

do -192 (A6) aO al dO dl d2 d3 d4 a3 a2

STRUCT Layer 'Result: STRUCT Layer_Info *11 

STRUCT BitMap *hm,*bm2 

LONG xO, yO, xl, yl, flags 

STRUCT Hook *hook 

## 3.1 The Libraries and their Functions

Function: Creates a  new layer in the background and installs a 

backfill hook.

Parameters: 

H 

Layerlnfo 

bm

Screen bit-map 

xO,yO

Upper left corner 

xl.yl

Lower right corner 

flags

Layer type 

hook

BackFill hook 

bm2

SuperBitMap or 0 

Result: 

Layer or 

ICreateBehindLayer Create layer in background! 

Call: result =  CreateBehindLayer (Ii,bm,x0,y0,xl,yl, flags, bm2) 

dO -42 (A6) aO al dO dl d2 d3 d4 a2

STRUCT Layer *result 

STRUCT Layer_Info *li 

STRUCT BitMap *bm,*bm2 

LONG xO,yO,xl,yl, flags 

Function: Creates a  new layer behind all other layers. 

Parameters: H  Layerlnfo 

bm Screen bit-map xO.yO Upper left corner xl.yl Lower right corner flags Layer type bm2 SuperBitMap or 0

Result: Layer or 0 

ICreateUpfrontHookLayer Create foreground layer with hook| 

KsCLlll result =  CreateUpfrontHookLayer(li,bm,xO,yO,xl,yl, flags, hook, bm2) 

dO -186 (A6) aO al do dl d2 63 d4 a3 a2

STRUCT Layer "result 

STRUCT Layer_Info *li 

STRUCT BitMap *ta,*bm2 

LONG xO,yO,xl,yl, flags 

STRUCT Hook *hook 

Function: Creates a  new layer in the foreground and installs a  backfill 

hook.

Parameters: H 

Layerlnfo 

bm

Screen bit-map 

xO,yO

Upper left corner 

xl,yl

Lower right corner 

flags

Layer type 

hook

BackFill hook 

bm2

SuperBitMap or 0 

Result: Layer or 

ICreateUpfrontLayer Create a  foreground layer | 

Call: result =  CreateUpfrontLayer(li,bm,xO,yO,xl,yl, flags, bm2) 

dO -36 (A6) aO al dO dl d2 d3 d4 a2

STRUCT Layer *result 

STRUCT Layer_Info *li 

STRUCT BitMap *bm, *bm2 

LONG xO,yO,xl,yl, flags 

Function: Creates a  new layer in the foreground. 

Parameters: li Layerlnfo 

bm Screen bit-map xO,yO Upper left corner xl.yl Lower right corner flags Layer type bm2 SuperBitMap or 0

Result: Layer or 0 

IDeleteLayer Free a  layer | 

Call: result =  DeleteLayer( 1   ) 

dO -90 (A6) al

LONG result 

STRUCT Layer *1 

Function: Frees the given layer and its memory blocks. 

Parameters: 1  Layer 

Result: 0  Error 

|DisposeLayerInfo Free the Layerlnfo! 

Call: DisposeLayerInfo( li ) 

-150 (A6) a0 

STRUCT Layer_Info *li 

Function: Free Layerlnfo and its memory. 

Parameters: li Layerlnfo 

|EndUpdate End update and normalize clipping | 

Call: Endupdate( 1, flag ) 

-84 (A6) aO dO 

STRUCT Layer *1 

UWORD flag 

Function: Return normal ClipRects to the layer. 

Parameters: 1  Layer 

flag TRUE: Update completely ended. llnstallClipRegion Install clipping |

Call: oldclipregion =  InstallClipRegion ( 1, region ) 

dO -174 (A6) aO al

STRUCT Region *oldclipregion, *region 

STRUCT Layer *1 

Function: Installs a  new clipping region in layer. 

Parameters: 1  Layer 

region New ClipRegion
Result: Previous ClipRegion or 0 

InstallLayerHook Install backfill hookj 

Call: oldhook =  InstallLayerHook ( layer, hook ) 

dO -198 (A6) aO al

STRUCT Hook *oldhook,*hook 

STRUCT Layer * layer 

Function: Installs a  new backfill hook in a  layer. 

Parameters: layer Layer 

hook New backfill hook

Result: Previous backfill hook 

ILockLayer Lock layer | 

Call: LockLayer( 1   ) 

-96 (A6) al 

STRUCT Layer *1 

Function: Lock a  layer from other programs. 

Parameters: 1  Layer 

ILockLayerlnfo Lock Layerliifol 

Call: LockLayerlnf o (   li ) 

-120 (A6) aO 

STRUCT Layerlnfo *li 

Function: Lock Layerlnfo from other programs. 

Parameters: i  Layerlnfo 

ILockLayers Lock all layers of a  Layerlnfol 

Call: LockLayers (   li ) 

-108 (A6) aO 

STRUCT Layerlnfo *li 

Function: Locks an entire layer system from other programs. 

Parameters: H  Layerlnfo 

IMoveLayer Move a  layer | 

Call: result =  MoveLayer( 1, dx, dy ) 

dO -60 (A6) al dO dl

LONG result, dx,dy 

STRUCT Layer *1 

Function: Move a  layer relative to its current position. 

Parameters: 1  Layer 

dx Relative X  position dy Relative Y  position

Result: 0  Error 

IMoveLayerlnFrontOf Move layer in front of another layer | 

Call: result =   MoveLayerlnFrontOf (  layertomove, targetlayer ) 

dO -168 (A6) aO al

LONG result 

STRUCT Layer * layertomove, 'targetlayer 

Function: Moves one layer in front of another. 

Parameters: layertomove 

Layer to move in front of targetlayer. 

targetlayer Layer that layertomove will overlay.

Result: 0  Error 

IMoveSizeLayer Change layer size and position! 

Call: result =  MoveSizeLayer (  layer, dx, dy, dw, dh ) 

dO -180 (A6) aO dO dl d2 d3

LONG result, dx,dy,dw, dh 

STRUCT Layer * layer 

Function: Move upper left and lower right corners. 

Parameters: layer Layer 

dx.dy Relative position dw,dy Relative size

Result: 0  Error 

INewLayerlnfo 

Call: result =  NewLayerlnf o  ( ) 

dO -144 (A6)

STRUCT Layerlnfo *result 

Function: Creates a  new Layerlnfo structure. 

Result: Layerlnfo or 0 

IScrollLaver 

Get Layerlnfo | 

Scroll layer contents] 

Call: ScrollLayer (   1, dx, dy ) 

-72 (A6) al dO dl 

STRUCT Layer *1 

LONG dx,dy 

Function: Scrolls the contents of a  layer. 

Parameters: 1  Layer 

dx Delta value X dy Delta value Y

ISizeLayer 

Change layer size 

Call: result =  SizeLayer( 1, dx, dy ) 

dO -66 (A6) al dO dl

LONG result , dx, dy 

STRUCT Layer *1 

Function: Changes the size of a  layer relative to its current size. 

Parameters: 1  Layer 

dx,dy Relative size change

Result: 0  Error 

SwapBitsRastPortClipKect 

Switch contents of a  bit-map and ClipRect 

Call: SwapBitsRastPortClipRect (   rp, cr ) 

-126 (A6) aO al 

STRUCT RastPort *rp 

STRUCT ClipRect *cr 

Function: Switches the contents of a  ClipRect with the regions of a 

bit-map.

Parameters: rp RastPort 

cr ClipRect lUnlockLayer Undo a  LockLayerQ caii]

Call: UnlockLayer( 1   ) 

-102 (A6) aO 

STRUCT Layer *1 

Function: Frees the layer for other programs to use again. 

Parameters: 1  Layer 

lUnlockLayerlnfo Undo LockLayerlnfoQ caTT]

Call: UnlockLayerlnf o (   li ) 

-138 (A6) aO 

STRUCT Layer Info *li 

Function: Frees the Layerlnfo structure for other programs. 

Parameters: K  Layerlnfo 

|UnlockLayers Undo LockLayersQ cali| 

Call: UnlockLayers (   li ) 

-114 (A6) aO 

STRUCT Layerlnfo *li 

Function: Frees the entire layer system in the given Layerlnfo list. 

Parameters: b  Layerlnfo 

[UpfrontLayer Move a  layer to the frontl 

Call: result =  UpfrontLayer (   1 ) 

dO -48 (A6) al

LONG result 

STRUCT Layer *1 

Function: Moves a  layer in front of all other layers. 

Parameters: 1  Layer 

Result: 0  Error 

