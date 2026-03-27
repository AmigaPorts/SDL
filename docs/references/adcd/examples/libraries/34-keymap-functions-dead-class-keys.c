/* Source: ADCD 2.1
 * Section: 34-keymap-functions-dead-class-keys
 * Library: libraries
 * ADCD reference: libraries/34-keymap-functions-dead-class-keys.md
 */

    KMLowMapType:
        DC.B    KCF_DEAD+KC_VANILLA     ; aA (Key 20)
                    ...                 ; (more...)
        DC.B    KCF_DEAD+KC_VANILLA     ; hH (Key 25)
                    ...                 ; (more...)
    KMLowMap:
        DC.L    key20                   ; a, A, ae, AE
                    ...                 ; (more...)
        DC.L    key25                   ; h, H, dead ^
                    ...                 ; (more...)
    ;------ possible dead keys
    key25:
        DC.B    0,'h',0,'H'             ; h, H
        DC.B    DPF_DEAD,3,DPF_DEAD,3   ; dead ^, dead ^
        DC.B    0,$08,0,$08,0,$88,0,$88 ; control translation
                    ...                 ; (more...)
    ;------ deadable keys (modified by dead keys)
    key20:              ; a, A, ae, AE
        DC.B    DPF_MOD,key20u-key20    ; deadable flag, number of
                                        ; bytes from start of key20
                                        ; descriptor to start of un-
                                        ; shifted data
        DC.B    DPF_MOD,key20s-key20    ; deadable flag, number of
                                        ; bytes from start of key20
                                        ; descriptor to start of shift-
                                        ; ed data
        DC.B    0,$E6,0,$C6             ; null flags followed by rest
        DC.B    0,$01,0,$01,0,$81,0,$81 ; of values (ALT, CTRL...)
    key20u:
        DC.B    'a',$E1,$E0,$E2,$E3,$E4 ; 'a' alone and characters to
                                        ; output when key alone is
                                        ; prefixed by a dead key
        DC.B    $E1,$E1,$E2,$E1,$E1,$E1 ; most recent is '
        DC.B    $E0,$E2,$E0,$E0,$E0,$E0 ; most recent is `
    key20s:
        DC.B    'A',$C1,$C0,$C2,$C3,$C4 ; SHIFTed 'a' and characters to
                                        ; output when SHIFTed key is
                                        ; prefixed by a dead key
        DC.B    $C1,$C1,$C2,$C1,$C1,$C1 ; most recent is '
        DC.B    $C0,$C2,$C0,$C0,$C0,$C0 ; most recent is `
