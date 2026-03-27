/* Source: ADCD 2.1
 * Section: exec-library-obtainsemaphoreshared
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/exec-library-obtainsemaphoreshared.md
 */

            ObtainSemaphoreShared(ss);
            /* read data */
            ReleaseSemaohore(ss);

            ObtainSemaphore(ss);
            /* modify data */
            ReleaseSemaohore(ss);
