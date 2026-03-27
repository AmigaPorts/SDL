/* Source: ADCD 2.1
 * Section: include-graphics-clip-h
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/include-graphics-clip-h.md
 */

    struct  ClipRect *Next;	    /* roms used to find next ClipRect */
    struct  ClipRect *prev;	    /* Temp use in layers (private) */
    struct  Layer   *lobs;	    /* Private use for layers */
    struct  BitMap  *BitMap;	    /* Bitmap for layers private use */
    struct  Rectangle	bounds;     /* bounds of cliprect */
    void    *_p1;		    /* Layers private use!!! */
    void    *_p2;		    /* Layers private use!!! */
    LONG    reserved;		    /* system use (Layers private) */
