# 10 / Printer Device Access / Opening Prt:


When using the printer device as PRT:, you can open it just as though it
were a normal AmigaDOS output file.


```c
    struct FileHandle *file;

    file = Open( "PRT:", MODE_NEWFILE ); /* Open PRT: */
    if (file == 0)                       /* if the open was unsuccessful */
        exit(PRINTER_WONT_OPEN);
```
