---
title: graphics.library (basename: _GfxBase)
manual: amiga-mail
chapter: amiga-mail
section: graphics-library-basename-gfxbase
functions: []
libraries: []
---

# graphics.library (basename: _GfxBase)

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

BitMapScale(bitScaleArgs)(a0)           - Perform raster scaling on a bit
```c
                                          map. (V36)
```
CloseMonitor(monitorSpec)(a0)           - Close a MonitorSpec (V36)
EraseRect(rp,xMin,yMin,xMax,yMax)(a1,d0/d1/d2/d3)
```c
                                        - Fill a defined rectangular area
                                          using the current BackFill hook.
                                          (V36)
```
ExtendFont(font,fontTags)(a0/a1)        - Ensure tf_Extension has been
```c
                                          built for a font (V36)
```
FindDisplayInfo(displayID)(d0)          - Search for a record identified
```c
                                          by a specific key (V36)
```
FontExtent(font,fontExtent)(a0/a1)      - Get the font attributes of the
```c
                                          current font (V36)
```
GetDisplayInfoData(handle,buf,size,tagID,displayID)(a0/a1,d0/d1/d2)
```c
                                        - Query DisplayInfo Record
                                          parameters (V36)
```
GetVPModeID(vp)(a0)                     - Get the 32 bit DisplayID from a
```c
                                          ViewPort. (V36)
```
GfxAssociate(associateNode,gfxNodePtr)(a0/a1)
                                        - Associate a graphics extended
                                          node with a given pointer
GfxFree(gfxNodePtr)(a0)                 - Free a graphics extended data
```c
                                          structure (V36)
```
GfxLookUp(associateNode)(a0)            - Find a graphics extended node
```c
                                          associated with a given pointer
                                          (V36)
```
GfxNew(gfxNodeType)(d0)                 - Allocate a graphics extended
```c
                                          data structure (V36)
```
ModeNotAvailable(modeID)(d0)            - Check to see if a DisplayID
```c
                                          isn't available. (V36)
```
NextDisplayInfo(displayID)(d0)          - Iterate current displayinfo
```c
                                          identifiers (V36)
```
OpenMonitor(monitorName,displayID)(a1,d0)
```c
                                        - Open a named MonitorSpec (V36)
```
ReadPixelArray8(rp,xstart,ystart,xstop,ystop,array,temprp)
```c
                                         (a0,d0/d1/d2/d3/a2,a1)
                                        - Read the pen number value of a
                                          rectangular array
```
ReadPixelLine8(rp,xstart,ystart,width,array,tempRP)(a0,d0/d1/d2/a2,a1)
                                        - Read the pen number value of a
                                          horizontal line
ScalerDiv(factor,numerator,denominator)(d0/d1/d2)
```c
                                        - Get the scaling result that
                                          BitMapScale would. (V36)
```
StripFont(font)(a0)                     - Remove the tf_Extension from a
```c
                                          font (V36)
```
TextExtent(rp,string,count,textExtent)(a1,a0,d0/a2)
```c
                                        - Determine raster extent of text
                                          data. (V36)
```
TextFit(rp,string,strLen,textExtent,constrainingExtent,strDirection,
```c
       constrainingBitWidth,constrainingBitHeight)(a1,a0,d0/a2/a3,d1/d2/d3)
                                        - Count characters that will fit
                                          in a given extent (V36)
```
VideoControl(colorMap,tagarray)(a0/a1)  - Modify the operation of a
```c
                                          ViewPort's ColorMap (V36)
```
WeighTAMatch(reqTextAttr,targetTextAttr,targetTags)(a0/a1/a2)
```c
                                        - Get a measure of how well two
                                          fonts match. (V36)
```
WritePixelArray8(rp,xstart,ystart,xstop,ystop,array,temprp)
```c
                (a0,d0/d1/d2/d3/a2,a1)
                                        - Write the pen number value of a
                                          rectangular array
```
WritePixelLine8(rp,xstart,ystart,width,array,tempRP)(a0,d0/d1/d2/a2,a1)

                                        - Write the pen number value of a
                                          horizontal line
