/* Source: ADCD 2.1
 * Section: devices-dev-examples-console-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-console-c.md
 */

    {
    10, 10,                           /* starting position (left,top) */
    620,180,                          /* width, height */
    -1,-1,                            /* detailpen, blockpen */
    CLOSEWINDOW,                      /* flags for idcmp */
    WINDOWDEPTH|WINDOWSIZING|
    WINDOWDRAG|WINDOWCLOSE|
    SMART_REFRESH|ACTIVATE,           /* window flags */
    NULL,                             /* no user gadgets */
    NULL,                             /* no user checkmark */
    "Console Test",                   /* title */
    NULL,                             /* pointer to window screen */
    NULL,                             /* pointer to super bitmap */
    100,45,                           /* min width, height */
    640,200,                          /* max width, height */
    WBENCHSCREEN                      /* open on workbench screen */
    };
