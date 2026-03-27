/* Source: ADCD 2.1
 * Section: 25-making-a-signalsemaphore-available-to-the-public
 * Library: libraries
 * ADCD reference: libraries/25-making-a-signalsemaphore-available-to-the-public.md
 */

       /* Allocate memory for the structure */
       if (sema=(struct SignalSemaphore *)
           AllocMem(sizeof(struct SignalSemaphore),MEMF_PUBLIC|MEMF_CLEAR))
       {
           sema->ss_Link.ln_Pri=0;         /* Set the priority to zero */
           sema->ss_Link.ln_Name=name;
           /* Note that the string 'name' is not copied. If that is    */
           /* needed, allocate memory for it and copy the string. And  */
           /* add the semaphore the the system list                    */
           AddSemaphore(semaphore);
       }
