# II-49: Directory Scanning


by Ewout Walraven


Prior to release 2.0, examining the contents of directories using
dos.library required the use of two functions: Examine() and ExNext().
Although these routines perform the task for which they were intended,
they have limitations.  One is that these functions require stepping
through a directory one entry at a time.  For most applications that need
to do directory scanning, it would more efficient to scan a directory in
one pass rather than many.  This would significantly reduce the time spent
scanning. Also, these functions don't know anything about the AmigaDOS
wildcards, so any wildcard processing must be done by the application, not
by the OS.

 [Atomic Directory Scanning](../AmigaMail_Vol2_guide/node006E.html) 
 [MultiDirectory Assigns](../AmigaMail_Vol2_guide/node006F.html) 
 [Filename Matching](../AmigaMail_Vol2_guide/node0070.html) 

