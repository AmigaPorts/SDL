# 14 Workbench and Icon Library / The Info File


The iconic representation of Amiga filing system objects is implemented
through .info files.  In general, for each file, disk or directory that is
visible in the Workbench environment, there is an associated .info file
which contains the icon imagery and other information needed by Workbench.

Icons are associated with a particular file or directory by name.  For
example, the icon for a file named myapp would be stored in a .info file
named myapp.info in the same directory.

To make your application program accessible (and visible) in the
Workbench environment, you need only supply a .info file with
the appropriate name and type.  The are four main types of icons
(and .info files) used to represent Amiga filing system
objects (Table (14-1).




```c
           Table 14-1: Basic Workbench Icon Types


    Workbench          Filing                   Result When
    Icon Type       System Object            Icon Is Activated
    ---------       -------------            -----------------
    Disk       The root level directory    Window opens showing files
                                           and subdirectories

    Drawer     A subdirectory              Window opens showing files
                                           and subdirectories

    Tool       An executable file          Application runs
               (i.e., an application)

    Project    A data file                 Typically, the application
                                           that created the data file
                                           runs and the data file is
                                           automatically loaded into it.


     [Figure 14-1: Basic Workbench Icon Types](../Libraries_Manual_guide/node05E1.html) 
```
Icons can be created with the IconEdit program (in the Tools directory of
the Extras disk), or by copying an existing .info file of the correct
type.  Icons can also be created under program control with
[PutDiskObject()](../Libraries_Manual_guide/node0243.html#line4).  See the discussion of the [icon library functions](../Libraries_Manual_guide/node0243.html) below
for more on this.

For an executable file the icon type must be set to tool.  For a data file
the icon type must be set to project. Create icons for your application
disk and directories too.  For a directory, the icon is stored in a .info
file at the same level where the directory name appears (not in the
directory itself).  The icon type should be set to drawer.  The icon for a
disk should always be stored in a file named disk.info at the root level
directory of the disk.  The icon type should be set to disk.  (The icon
type can be set and the icon imagery edited with the IconEdit program.)

