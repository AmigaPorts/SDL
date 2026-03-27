/* Source: ADCD 2.1
 * Section: amiga-lib-argarrayinit
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/amiga-lib-argarrayinit.md
 */

    Use of these routines facilitates the use of ToolTypes or command-
    line arguments to control end-user parameters in Commodities
    applications. For example, a filter used to trap a keystroke for
    popping up a window might be created by something like this:

            char   *ttypes  = ArgArrayInit(argc, argv);
            CxObj   *filter = UserFilter(ttypes, "POPWINDOW", "alt f1");

           ... with ...

           CxObj *UserFilter(char **tt, char *action_name,
                              char *default_descr)
            {
            char *desc;

                desc = FindToolType(tt,action_name);

                return(CxFilter((ULONG)(desc? desc: default_descr)));
            }

    In this way the user can assign "alt f2" to the action by
    entering a tooltype in the program's icon of the form:

            POPWINDOW=alt f2

    or by starting the program from the CLI like so:

            myprogram "POPWINDOW=alt f2"
