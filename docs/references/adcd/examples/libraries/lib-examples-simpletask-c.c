/* Source: ADCD 2.1
 * Section: lib-examples-simpletask-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-simpletask-c.md
 */

    sharedvar = 0L;

    task = CreateTask(simpletaskname,0,simpletask,STACK_SIZE);
    if(!task)  cleanexit("Can't create task",RETURN_FAIL);

    printf("This program initialized a variable to zero, then started a\n");
    printf("separate task which is incrementing that variable right now,\n");
    printf("while this program waits for you to press RETURN.\n");
    printf("Press RETURN now: ");
    getchar();

    printf("The shared variable now equals %ld\n",sharedvar);

    /* We can simply remove the task we added because our simpletask does not make */
    /* any system calls which could cause it to be awakened or signalled later.    */
    Forbid();
    DeleteTask(task);
    Permit();
    cleanexit("",RETURN_OK);
