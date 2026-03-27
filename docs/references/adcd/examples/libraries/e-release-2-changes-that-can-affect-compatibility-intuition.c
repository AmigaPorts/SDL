/* Source: ADCD 2.1
 * Section: e-release-2-changes-that-can-affect-compatibility-intuition
 * Library: libraries
 * ADCD reference: libraries/e-release-2-changes-that-can-affect-compatibility-intuition.md
 */

    screen is a mode only available after 1.3.  It will try to return the
    most sensible mode that old [OpenScreen()](../Libraries_Manual_guide/node00DF.html#line6) can open.  This was
    necessary to prevent problems in applications that cloned the
    Workbench screen. To properly handle new modes, see [LockPubScreen()](../Libraries_Manual_guide/node00E6.html#line34),
    [GetVPModeID()](../Libraries_Manual_guide/node033C.html#line19), and the [SA_DisplayID](../Libraries_Manual_guide/node00E5.html#line74) tag for [OpenScreenTags()](../Libraries_Manual_guide/node00DF.html#line6).
