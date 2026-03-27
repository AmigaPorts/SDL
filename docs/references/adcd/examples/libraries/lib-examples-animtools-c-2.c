/* Source: ADCD 2.1
 * Section: lib-examples-animtools-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-animtools-c.md
 */

        {
        if (NULL != (vsprite->BorderLine = (WORD *)AllocMem(line_size, MEMF_CHIP)))
            {
            if (NULL != (vsprite->CollMask = (WORD *)AllocMem(plane_size, MEMF_CHIP)))
                {
                vsprite->Y          = nVSprite->nvs_Y;
                vsprite->X          = nVSprite->nvs_X;
                vsprite->Flags      = nVSprite->nvs_Flags;
                vsprite->Width      = nVSprite->nvs_WordWidth;
                vsprite->Depth      = nVSprite->nvs_ImageDepth;
                vsprite->Height     = nVSprite->nvs_LineHeight;
                vsprite->MeMask     = nVSprite->nvs_MeMask;
                vsprite->HitMask    = nVSprite->nvs_HitMask;
                vsprite->ImageData  = nVSprite->nvs_Image;
                vsprite->SprColors  = nVSprite->nvs_ColorSet;
                vsprite->PlanePick  = vsprite->PlaneOnOff = 0x00;
                InitMasks(vsprite);
                return(vsprite);
                }
            FreeMem(vsprite->BorderLine, line_size);
            }
        FreeMem(vsprite, (LONG)sizeof(*vsprite));
        }
