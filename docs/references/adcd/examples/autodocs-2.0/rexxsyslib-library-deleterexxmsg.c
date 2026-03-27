/* Source: ADCD 2.1
 * Section: rexxsyslib-library-deleterexxmsg
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/rexxsyslib-library-deleterexxmsg.md
 */

    if (rmsg=CreateRexxMsg(myport,"myapp","MYAPP_PORT"))
    {
            /* Do my think with rmsg */
            ClearRexxMsg(rmsg,16);  /* We may not want to clear all 16 */
            DeleteRexxMsg(rmsg);
    }
