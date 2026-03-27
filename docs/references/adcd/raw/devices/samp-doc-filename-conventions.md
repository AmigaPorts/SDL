# SAMP.doc / Filename Conventions


For when it becomes necessary to split a SAMP file between floppies using
the Continuation feature, the filenames should be related. The method is
the following:

The "root" file has the name that the user chose to save under. Subsequent
files have an ascii number appended to the name to indicate what sublevel
the file is in. In this way, a program can reload the files in the proper
order.

For example, if a user saved a file called "Gurgle", the first
continuation file should be named "Gurgle1", etc.

