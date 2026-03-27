/* Source: ADCD 2.1
 * Section: layers-library-endupdate
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/layers-library-endupdate.md
 */

    -- begin update for first part of two-part refresh --
    BeginUpdate(my_layer);

    -- do some refresh, but not all --
    my_partial_refresh_routine(my_layer);

    -- end update, false (not completely done refreshing yet) --
    EndUpdate(my_layer, FALSE);

    -- begin update for last part of refresh --
    BeginUpdate(my_layer);

    -- do rest of refresh --
    my_complete_refresh_routine(my_layer);

    -- end update, true (completely done refreshing now) --
    EndUpdate(my_layer, TRUE);
