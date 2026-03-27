/* Source: ADCD 2.1
 * Section: iv-3-screendisplaymodes-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-3-screendisplaymodes-c.md
 */

                            textattr->ta_YSize = defaultfont->tf_YSize;
                            textattr->ta_Style = defaultfont->tf_Style;
                            textattr->ta_Flags = defaultfont->tf_Flags;

                            if (window = OpenAWindow(screen, overscantype)) {
                                vi = GetVisualInfo(screen, TAG_END);
                                if (LayoutMenus(menu, vi, TAG_DONE)) {
                                    if (gadget = CreateContext(&glist)) {
                                        ng->ng_LeftEdge =
