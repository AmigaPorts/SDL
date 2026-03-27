/* Source: ADCD 2.1
 * Section: 1-introduction-to-libraries-general-amiga-development
 * Library: libraries
 * ADCD reference: libraries/1-introduction-to-libraries-general-amiga-development.md
 */

    for.  This applies to memory, windows, screens, file handles,
    libraries, devices, ports, etc.  Where an error value or return is
    possible, ensure that there is a reasonable failure path.  Many
    poorly written programs will appear to be reliable, until some [error](../Libraries_Manual_guide/node0536.html)
    condition (such as memory full or a disk problem) causes the program
    to continue with an invalid or null pointer, or branch to untested
    error handling code.
