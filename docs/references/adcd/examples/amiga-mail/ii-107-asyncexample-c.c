/* Source: ADCD 2.1
 * Section: ii-107-asyncexample-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-107-asyncexample-c.md
 */

    if (in = OpenAsync("x", MODE_READ, 8192))
    {
        if (out = OpenAsync("t:test_sync", MODE_WRITE, 8192))
        {
            while ((num = ReadCharAsync(in)) >= 0)
            {
                WriteCharAsync(out,num);
            }
            CloseAsync(out);
        }
        CloseAsync(in);
    }
