# 18 / What is a Library? / Using a Library to Reference Data


Most libraries (such as Intuition, graphics and Exec) have other data that
follows the [Library](../Libraries_Manual_guide/node0292.html) data structure in memory.  Although it is not normally
necessary, a program can use the library base pointer to access the
Library structure and any custom library data.

In general, the system's library base data is read-only, and should be
directly accessed as little as possible, primarily because the format of
the data may change in future revisions of the library.  If the library
provides functions to allow access to library data, use those instead.

