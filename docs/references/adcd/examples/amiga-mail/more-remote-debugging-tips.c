/* Source: ADCD 2.1
 * Section: more-remote-debugging-tips
 * Library: amiga-mail
 * ADCD reference: amiga-mail/more-remote-debugging-tips.md
 */

    /**********    debug macros     ***********/
    #define MYDEBUG  1
    void kprintf(UBYTE *fmt,...);
    void dprintf(UBYTE *fmt,...);
    #define DEBTIME 0
    #define bug printf
    #if MYDEBUG
    #define D(x) (x); if(DEBTIME>0) Delay(DEBTIME);
    #else
    #define D(x) ;
    #endif /* MYDEBUG */
    /********** end of debug macros **********/
