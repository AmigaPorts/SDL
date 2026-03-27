/* Source: ADCD 2.1
 * Section: graphics-library-initarea
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/graphics-library-initarea.md
 */

    This function provides initialization for the vector collection
    matrix such that it has a size of (max vectors ).  The size of the
    region pointed to by buffer (short pointer) should be five (5) times as
    large as maxvectors. This size is in bytes.  Areafills done by using
    [AreaMove](../Includes_and_Autodocs_2._guide/node041A.html), [AreaDraw](../Includes_and_Autodocs_2._guide/node0417.html), and [AreaEnd](../Includes_and_Autodocs_2._guide/node0419.html) must have enough space allocated in
    this table to store all the points of the largest fill. [AreaEllipse](../Includes_and_Autodocs_2._guide/node0418.html)
    takes up two vectors for every call. If AreaMove/Draw/Ellipse detect
    too many vectors going into the buffer they will return -1.
