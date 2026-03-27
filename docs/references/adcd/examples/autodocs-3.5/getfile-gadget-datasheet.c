/* Source: ADCD 2.1
 * Section: getfile-gadget-datasheet
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/getfile-gadget-datasheet.md
 */

       The getfile gadget class is used to get files and drawers from a file
       requester in an easy and consistent way.  It consists of two button
       gadgets, one read-only and one popfile/popdrawer button, that are
       used to select the file(s)/drawer and show the result.

       Advantages that this class provides:

       > Consistent behaviour and look in all applications using this class
         instead of doing their own file and drawer routines.

       > Easy to use.


    METHODS
       OM_NEW -- Passed to superclass, defaults set, then OM_SET. Children
                 created.

       OM_SET -- Passed to superclass, custom tags set.

       OM_GET -- [Custom](../Includes_and_Autodocs_3._guide/node05F6.html#line24) tag returned or passed to superclass.

       OM_UPDATE -- Passed to superclass, options set then rendered.

       OM_DISPOSE -- Children disposed of, then passed to superclass.

       GM_RENDER -- Passed to superclass, then children are rendered.

       GM_HITTEST -- Overrides superclass, returns GMR_GADGETHIT if within
                 the popfile/drawer button.

       GM_HELPTEST -- Overrides superclass, returns GMR_HELPHIT if within
                 the domain of the gadget.

       GM_GOACTIVE -- Passed to superclass, passed to popfile/drawer button.

       GM_HANDLEINPUT -- Overrides superclass, all input processed.

       GM_GOINACTIVE -- Passed to superclass, popfile/drawer button deactivated.

       GM_DOMAIN -- Returns GDOMAIN_MINIMUM and GDOMAIN_MAXIMUM dimensions.

       GM_KEYACTIVE -- Private method for keyboard control.

       GM_KEYINACTIVE -- Private method for keyboard control.

       GFILE_REQUEST -- getfile gadget method for invoking the file requester.

       GFILE_FREELIST -- getfile gadget method for freeing allocated list
                   of files.

    ATTRIBUTES
       Most of these tags operate the same as the ASLFR_#? tags in ASL library.
       See <asl.library/AslRequest> for detailed descriptions.

       GETFILE_TitleText (STRPTR)
          [Requester](../Includes_and_Autodocs_3._guide/node05E0.html#line143) title text.

          Defaults to NULL.

          Applicability is (OM_NEW, OM_SET).

       GETFILE_LeftEdge (WORD)
       GETFILE_TopEdge  (WORD)
          [Requester](../Includes_and_Autodocs_3._guide/node05E0.html#line143) placement coordinates.

          Defaults to leftedge: 30, topedge: 20.

          Applicability is (OM_NEW, OM_SET, OM_GET).

       GETFILE_Width  (WORD)
       GETFILE_Height (WORD)
          [Requester](../Includes_and_Autodocs_3._guide/node05E0.html#line143) dimensions.

          Default height: 200, width: 300.

          Applicability is (OM_NEW, OM_SET, OM_GET).

       GETFILE_File (STRPTR)
          Contents of file gadget.

          Defaults to NULL.

          Applicability is (OM_NEW, OM_SET, OM_GET, OM_NOTIFY).

       GETFILE_Drawer (STRPTR)
          Contents of drawer gadget.

          Defaults to NULL.

          Applicability is (OM_NEW, OM_SET, OM_GET, OM_NOTIFY).

       GETFILE_FullFile (STRPTR)
          Complete qualified file name. Replaces GETFILE_Drawer and GETFILE_File.

          Defaults to NULL.

          Applicability is (OM_NEW, OM_SET, OM_GET, OM_NOTIFY).

       GETFILE_FullFileExpand (BOOL)
          GETFILE_FullFile will give complete file name(s) expanded with
          [NameFromLock()](../Includes_and_Autodocs_3._guide/node0193.html) to remove relative paths.

          Defaults to TRUE.

          Applicability is (OM_NEW, OM_SET).

       GETFILE_Pattern (STRPTR)
          Contents of pattern gadget.

          Defaults to "#?".

          Applicability is (OM_NEW, OM_SET, OM_GET).

       GETFILE_DoSaveMode (BOOL)
          Being used for saving?

          Defaults to FALSE.

          Applicability is (OM_NEW, OM_SET).

       GETFILE_DoMultiSelect (BOOL)
          Do multi-select of files?

          Defaults to FALSE.

          Applicability is (OM_NEW, OM_SET).

       GETFILE_DoPatterns (BOOL)
          Display a Pattern gadget?

          Defaults to FALSE.

          Applicability is (OM_NEW, OM_SET).

       GETFILE_DrawersOnly   (BOOL)
          Don't display files?

          Defaults to FALSE.

          Applicability is (OM_NEW, OM_SET).

       GETFILE_FilterFunc (struct [Hook](../Includes_and_Autodocs_3._guide/node0617.html#line27) *)
          Function to filter files.

          Defaults to none.

          Applicability is (OM_NEW, OM_SET).

       GETFILE_RejectIcons   (BOOL)
          Display .info files?

          Defaults to FALSE.

          Applicability is (OM_NEW, OM_SET).

       GETFILE_RejectPattern   (UBYTE *)
          Don't display files matching pattern.

          Defaults to none.

          Applicability is (OM_NEW, OM_SET).

       GETFILE_AcceptPattern (UBYTE *)
          Accept only files matching pattern.

          Defaults to none.

          Applicability is (OM_NEW, OM_SET).

       GETFILE_FilterDrawers (BOOL)
          Also filter drawers with pattern.

          Defaults to FALSE.

          Applicability is (OM_NEW, OM_SET).

       GETFILE_Filelist (struct [List](../Includes_and_Autodocs_3._guide/node0628.html#line19) *)
          If the GETFILE_DoMultiSelect tags was used, you can get a pointer
          to the list of selected files/drawers using this tag. The ln_Name
          part of each node will contain the filename/drawername for each
          selected file with a fully qualified path, even if you didn't use
          the GETFILE_FullFileExpand.
          In single-selected mode, the list will contain the single selected
          file for notification purposes. Don't forget to free the list using
          the GFILE_FREELIST method! This list is not suitable to be shown
          directly in a listbrowser gadget without conversion as default, use
          GETFILE_LBNodeStruct for that.

          Applicability is (OM_GET, OM_NOTIFY).

       GETFILE_LBNodeStruct (BOOL)
          GETFILE_Filelist will give a list with ListBrowserNodes instead of
          normal struct [Node](../Includes_and_Autodocs_3._guide/node062F.html#line21) node structures. NOTE: This tag requires that
          listbrowser.gadget is installed.

          Defaults to FALSE.

          Applicability is (OM_NEW).

          DO NOT USE THIS TAG YET SINCE SOME INTERNAL ISSUES HAVE NOT BEEN
          SORTED OUT YET!

       GETFILE_ReadOnly (BOOL)
          If TRUE, a read-only recessed button gadget is used to present the
          file/drawer information. If FALSE, an editable string gadget is used.
          The gadget will send the supported attributes in a OM_NOTIFY when a
          this tag is FALSE and the user is finished editing the content of the
          string gadget. The application can be aware of all changes to the
          string gadget by setting ICA_TARGET to TARGET_IDCMP for this
          getfile gadget instance and watching IDCMP_IDCMPUPDATE messages.
          See the provided example program for an example on how this can be
          done.

          Defaults to TRUE.

          Applicability is (OM_NEW).
