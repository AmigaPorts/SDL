/* Source: ADCD 2.1
 * Section: devices-ramdev-device-asm
 * Library: devices
 * ADCD reference: devices/devices-ramdev-device-asm.md
 */

    INITLONG	mdn_execName,myName	; Address of driver name
    INITLONG	mdn_tableSize,12	; # long words in AmigaDOS env.
    INITLONG	mdn_dName,$524d0000	; Store 'RM' in name
    INITLONG	mdn_sizeBlock,SECTOR/4	; # longwords in a block
    INITLONG	mdn_numHeads,1		; RAM disk has only one "head"
    INITLONG	mdn_secsPerBlk,1	; secs/logical block, must = "1"
    INITLONG	mdn_blkTrack,SECTORSPER ; secs/track (must be reasonable)
    INITLONG	mdn_resBlks,1		; reserved blocks, MUST > 0!
    INITLONG	mdn_upperCyl,(RAMSIZE/BYTESPERTRACK)-1 ; upper cylinder
    INITLONG	mdn_numBuffers,1	; # AmigaDOS buffers to start
    DC.W   0
