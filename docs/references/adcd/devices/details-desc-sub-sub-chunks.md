---
title: Details /  DESC sub-sub-chunks
manual: devices
chapter: devices
section: details-desc-sub-sub-chunks
functions: []
libraries: []
---

# Details /  DESC sub-sub-chunks

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME - size 18


```c
    BYTE    Name[18];       ; a name for the object.

    Used for camera tracking, specifying story paths, etc.
```
SHAP - size 4


```c
    WORD    Shape;          ; number indicating object type
    WORD    Lamp;           ; number indicating lamp type

    Lamp numbers are composed of several bit fields:

            Bits 0-1:
        0 - not a lamp
        1 - like sunlight
        2 - like a lamp - intensity falls off with distance.
        3 - unused/reserved

            Bits 2:
                    0 - non-shadow-casting light
                    4 - shadow-casting light

            Bits 3-4:
        0  - Spherical light source
        8  - Cylindrical light source.
        16 - Conical light source.
        24 - unused/reserved

    Shape numbers are:

        0 - Sphere
        1 - Stencil         ; not supported by Imagine
        2 - Axis            ; custom objects with points/triangles
        3 - Facets          ; illegal - for internal use only
        4 - Surface         ; not supported by Imagine
        5 - Ground

    Spheres have thier radius set by the X size parameter.
    Stencils and surfaces are plane-parallelograms, with one
    point at the object's position vector; one side lying along
    the object's X axis with a length set by the X size; and
    another side starting from the position vector and going
    "Y size" units in the Y direction and "Z size" units in
    the X direction.  A ground object is an infinte plane
    perpendicular to the world Z axis.  Its Z coordinate sets
    its height, and the X and Y coordinates are only relevant
    to the position of the "hot point" used in selecting the
    object in the editor.  Custom objects have points, edges
    and triangles associated with them.  The size fields are
    relevant only for drawing the object axes in the editor.
    Shape number 3 is used internally for triangles of custom
    objects, and should never appear in a data file.
```
POSI - size 12


```c
    VECTOR  Position;       ; the object's position.

    Legal coordinates are in the range -32768 to 32767 and 65535/65536.
    Currently, the ray-tracer only sees objects in the -1024 to 1024
    range.  Light sources, and the camera may be placed outside that
    range, however.
```
AXIS - size 36


```c
    VECTOR  XAxis;
    VECTOR  YAxis;
    VECTOR  ZAxis;

    These are direction vectors for the object coordinate system.
    They must be "orthogonal unit vectors" - i.e. the sum of the
    squares of the vevtor components must equal one (or close to it),
    and the vectors must be perpendicular.
```
SIZE - size 12


```c
    VECTOR  Size;

    See SHAP chunk above.  The sizes are used in a variety of ways
    depending on the object shape.  For custom objects, they are
    the lengths of the coordinate axes drawn in the editor.  If the
    object has its "Quickdraw" flag set, the axes lengths are also
    used to set the size of a rectangular solid that is drawn rather
    than drawing all the points and edges.
```
PNTS - size 2 + 12 * point count


```c
    UWORD   PCount;         ; point count
    VECTOR  Points[];       ; points

    This chunk has all the points for custom objects.  The are
    refered to by thier position in the array.
```
EDGE - size 4 + 4 * edge cout


```c
    UWORD   ECount;         ; edge count
    UWORD   Edges[][2];     ; edges

    This chunk contins the edge list for custom objects.
    The Edges[][2] array is pairs of point numbers that
    are connected by the edges.  Edges are refered to by thier
    position in the Edges[] array.
```
FACE - size 2 + 6 * face count


```c
    UWORD   TCount;         ; face count
    UWORD   Connects[][3];  ; faces

    This chunk contains the triangle (face) list for custom objects.
    The Connects[][3] array is triples of edge numbers that are
    connected by triangles.
```
PTHD - size 2 + 6 * axis count - Imagine only


```c
    UWORD   ACount;         ; axis count
    TFORM   PData[][3];     ; axis data

    This chunk contains the axis data for Imagine "path" objects.
    The PData array contains a TFORM structure for each point along
    the path.  The "Y size" item for the last point on the path tells
    whether the path is closed or not.  Zero means closed, non-zero
    means open.  Otherwise the Y size field is the distance along
    the path to the next path point/axis.
```
COLR - size 4
REFL - size 4
TRAN - size 4
SPC1 - size 4 - Imagine only


```c
    BYTE    pad;            ; pad byte - must be zero
    COLOR   col;            ; RGB color

    These are the main object RGB color, and reflection, transmission
    and specularity coefficients.
```
CLST - size 2 + 3 * count
RLST - size 2 + 3 * count
TLST - size 2 + 3 * count


```c
    UWORD   count;          ; count of colors
    COLOR   colors[];       ; colors

    These are the color, reflection and transmission coefficients
    for each face in custom objects. The count should match the
    face count in the FACE chunk. The ordering corresponds to the
    face order.
```
TPAR - size 64 - not written by Imagine - see TXT1 below

```c
    FRACT   Params[16];     ; texture parameters

    This is the list of parameters for texture modules when
    texture mapping is used.
```
TXT1 - variable size - Imagine only


```c
    This chunk contains texture data when texture mapping is used.

    UWORD   Flags;          ; texture flags:
                            ;    1 - TXTR_CHILDREN - apply to child objs
    TFORM   TForm;          ; local coordinates of texture axes.
    FRACT   Params[16];     ; texture parameters
    UBYTE   PFlags[16];     ; parameter flags (currently unused)
    UBYTE   Length;         ; length of texture file name
    UBYTE   Name[Length];   ; texture file name (not NULL terminated)
    UBYTE   pad;            ; (if necessary to make an even length)
```
BRS1 - variable size - Imagine only (version 1.0)
BRS2 - variable size - Imagine only (version 1.1)


```c
    UWORD   Flags;          ; brush type:
                            ;    0 - Color
                            ;    1 - Reflection
                            ;    2 - Filter
                            ;    3 - Altitude
    UWORD   WFlags;         ; brush wrapping flags:
                            ;    1   WRAP_X        - wrap type
                            ;    2   WRAP_Z        - wrap type
                            ;    4   WRAP_CHILDREN - apply to children
                            ;    8   WRAP_REPEAT   - repeating brush
                            ;    16  WRAP_FLIP     - flip with repeats
    TFORM   TForm;          ; local coordinates of brush axes.
    (UWORD   FullScale;)    ; full scale value
    (UWORD   MaxSeq;)       ; highest number for sequenced brushes
    UBYTE   Length;         ; length of brush file name
    UBYTE   Name[Length];   ; brush file name (not NULL terminated)
    UBYTE   pad;            ; (if necessary to make an even length)

    The FullScale and MaxSeq items are in BRS2 chunks only.
```
SURF - size 5 - not written by Imagine


```c
    BYTE    SProps[5];      ; object properties

    This chunk contains object (surface) properties used by Turbo Silver.

    SProps[0] - PRP_SURFACE ; surface type
                            ;   0 - normal
                            ;   4 - genlock
                            ;   5 - IFF brush
    SProps[1] - PRP_BRUSH   ; brush number (if IFF mapped)
    SProps[2] - PRP_WRAP    ; IFF brush wrapping type
                            ;   0 - no wrapping
                            ;   1 - wrap X
                            ;   2 - wrap Z
                            ;   3 - wrap X and Z
    SProps[3] - PRP_STENCIL ; stencil number for stencil objects
    SProps[4] - PRP_TEXTURE ; texture number if texture mapped
```
MTTR - size 2 - not written by Imagine - see PRP1 chunk.


```c
    UBYTE   Type;           ; refraction type (0-4)
    UBYTE   Index;          ; custom index of refraction

    This chunk contains refraction data for transparent or glossy
    objects.  If the refraction type is 4, the object has a "custom"
    refractive index stored in the Index field.  The Index field is
    100 * (true index of refraction - 1.00) -- so it must be in the
    range of 1.00 to 3.55.  The refraction types 0-3 specify 0) Air
    - 1.00, 1) Water - 1.33, 2) Glass - 1.67 or 3) Crystal 2.00.
```
SPEC - size 2 - not written by Imagine - see SPC1 above.


```c
    UBYTE   Specularity;    ; range of 0-255
    UBYTE   Hardness;       ; specular exponent (0-31)

    This chunk contains specular information.  The Specularity
    field is the amount of specular reflection -- 0 is none,
    255 is fully specular.  The "specular exponent" controls
    the "tightness" of the specular spots.  A value of zero
    gives broad specular spots and a value of 31 gives smaller
    spots.
```
PRP0 - size 6 - not written by Imagine


```c
    UBYTE   Props[6];       ; more object properties

    This chunk contains object properties that programs other
    than Turbo Silver might support.

    Props[0] - PRP_BLEND    ; blending factor (0-255)
    Props[1] - PRP_SMOOTH   ; roughness factor
    Props[2] - PRP_SHADE    ; shading on/off flag
    Props[3] - PRP_PHONG    ; phong shading on/off flag
    Props[4] - PRP_GLOSSY   ; glossy on/off flag
    Props[5] - PRP_QUICK    ; Quickdraw on/off flag

    The blending factor controls the amount of dithering used
    on the object - 255 is fully dithered.  The roughness factor
    controls how rough the object should appear - 0 is smooth, 255
    is max roughness.  The shading flag is interpreted differently
    depending on whether the object is a light source or not.  For
    light sources, it sets the light to cast shadows or not.  For
    normal objects, if the flag is set, the object is always
    considered as fully lit - i.e., it's color is read directly
    from the object (or IFF brush), and is not affected by light
    sources.  The phong shading is on by default - a non-zero value
    turns it off.  The glossy flag sets the object to be glossy or
    not.  If the object is glossy, the "transmit" colors and the
    index of refraction control the amount of "sheen".  The glossy
    feature is meant to simulate something like a wax coating
    on the object with the specified index of refraction. The
    trasmission coefficients control how much light from the
    object makes it through the wax coating.
    The Quickdraw flag, if set, tells the editor not to draw
    all the points and edges for the object, but to draw a
    rectanglular solid centered at the object position, and
    with sizes detemined by the axis lengths.
```
PRP1 - size 8 - Imagine only


```c
    UBYTE   IProps[8];       ; more object properties

    This chunk contains object properties that programs other
    than Imagine might support.

    IProps[0] - IPRP_DITHER   ; blending factor (0-255)
    IProps[1] - IPRP_HARD     ; hardness factor (0-255)
    IProps[2] - IPRP_ROUGH    ; roughness factor (0-255)
    IProps[3] - IPRP_SHINY    ; shinyness factor (0-255)
    IProps[4] - IPRP_INDEX    ; index of refraction
    IProps[5] - IPRP_QUICK    ; flag - Quickdraw on/off
    IProps[6] - IPRP_PHONG    ; flag - Phong shading on/off
    IProps[7] - IPRP_GENLOCK  ; flag - Genlock on/off

    The blending factor controls the amount of dithering used
    on the object - 255 is fully dithered.
    The hardness factor controls how tight the specular spot
    should be - 0 is a big soft spot, 255 is a tight hot spot
    The roughness factor controls how rough the object should
    appear - 0 is smooth, 255 is max roughness.
    The shiny factor in interaction with the object's filter
    values controls how shiny the object appears.  Setting it
    to anything but zero forces the object to be non-transparent
    since then the filter values are used in the shiny (reflection)
    calculations.  A value of 255 means maximum shinyness.
```
INTS - size 4 - not written by Imagine


```c
    FRACT   Intensity;      ; light intensity

    This is the intensity field for light source objects.
    an intensity of 255 for a sun-like light fully lights
    object surfaces which are perpendicular to the direction
    to the light source.  For lamp-like light sources, the
    necessary intensity will depend on the distance to the light.
```
INT1 - size 12 - Imagine only


```c
    VECTOR  Intensity;      ; light intensity

    This is like INTS above, but has seperate R, G & B intensities.
```
STRY - size 56 - not written by Imagine


```c
    STORY   story;          ; a story structure for the object.

    The story structure is described above.
```
ANID - size 64 - Imagine only


```c
    LONG    Cellno;         ; cell number
    TFORM   TForm;          ; object position/axes/size in that cell.

    For Imagine's "Cycle" objects, within EACH DESC chunk in the
    file - that is, for each object of the group, there will be
    a series of ANID chunks.  The cell number sequences of each
    part of the must agree with the sequence for the head object,
    and the first cell number must be zero.
```
FORD - size 56 + 12 * PC - Imagine only


```c
    WORD    NumC;           ; number of cross section points
    WORD    NumF;           ; number of slices
    WORD    Flags;          ; orientation flag
    WORD    pad;            ; reserved
    MATRIX  TForm;          ; object rotation/scaling transformation
    VECTOR  Shift;          ; object translation
    VECTOR  Points[PC];     ; "Forms" editor points

    For Imagine's "Forms" objects, the "PNTS" chunk above is not
    written out, but this structure is written instead.  The point
    count is PC = NumC + 4 * NumF.  The object's real points are
    then calculated from these using a proprietary algorithm.
    The tranformation parameters above allow the axes of the
    real object be moved around relative to the "Forms" points.
```
