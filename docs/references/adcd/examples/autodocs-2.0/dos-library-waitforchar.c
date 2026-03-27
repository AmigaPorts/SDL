/* Source: ADCD 2.1
 * Section: dos-library-waitforchar
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/dos-library-waitforchar.md
 */

    If a character is available to be read from 'file' within a the
    time (in microseconds) indicated by 'timeout', WaitForChar()
    returns -1 (TRUE). If a character is available, you can use [Read()](../Includes_and_Autodocs_2._guide/node02E0.html)
    to read it.  Note that WaitForChar() is only valid when the I/O
    stream is connected to a virtual terminal device. If a character is
    not available within 'timeout', a 0 (FALSE) is returned.
