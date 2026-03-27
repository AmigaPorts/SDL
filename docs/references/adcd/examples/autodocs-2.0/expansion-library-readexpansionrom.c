/* Source: ADCD 2.1
 * Section: expansion-library-readexpansionrom
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/expansion-library-readexpansionrom.md
 */

    configDev = AllocConfigDev();
    if( ! configDev ) panic();

    error = ReadExpansionBoard( board, configDev );
    if( ! error ) {
            configDev->cd_BoardAddr = board;
            ConfigBoard( configDev );
    }
