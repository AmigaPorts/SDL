# Chocolate Doom for AmigaOS 3.x -- Cross-compilation via bebbo-gcc
#
# Links against: libSDL2.a (from this project), libamiport.a (POSIX shims)
#
# Usage:
#   make doom          # Build chocolate-doom binary
#   make doom-docker   # Build inside Docker (default)

DOCKER_IMAGE = amigadev/crosstools:m68k-amigaos
CC = m68k-amigaos-gcc
AR = m68k-amigaos-ar

# Paths (relative to this Makefile)
SDL2_DIR   = ../..
DOOM_SRC   = $(HOME)/Developer/chocolate-doom
AMIPORT    = $(HOME)/Developer/amiport

CFLAGS = -std=gnu99 -O0 -m68030 -noixemul \
         -Wall -Wno-unused-parameter -Wno-sign-compare -Wno-missing-field-initializers \
         -I$(DOOM_SRC)/src \
         -I$(DOOM_SRC)/opl \
         -I$(DOOM_SRC)/pcsound \
         -I$(DOOM_SRC)/textscreen \
         -Iconfig \
         -I$(SDL2_DIR)/include \
         -I$(SDL2_DIR)/lib/SDL2_mixer/include \
         -I$(AMIPORT)/lib/posix-shim/include \
         -DDISABLE_SDL2NET=1 \
         -D__AMIGAOS3__

LDFLAGS = -noixemul -m68030 \
          -L$(SDL2_DIR)/lib/SDL2_mixer -lSDL2_mixer \
          -L$(SDL2_DIR) -lSDL2 \
          -L$(AMIPORT)/lib/posix-shim -lamiport \
          -ldebug -lamiga -lm -lstubs

# --- Doom engine (src/doom/) ---
DOOM_ENGINE = \
	$(DOOM_SRC)/src/doom/am_map.c \
	$(DOOM_SRC)/src/doom/deh_ammo.c \
	$(DOOM_SRC)/src/doom/deh_bexstr.c \
	$(DOOM_SRC)/src/doom/deh_cheat.c \
	$(DOOM_SRC)/src/doom/deh_doom.c \
	$(DOOM_SRC)/src/doom/deh_frame.c \
	$(DOOM_SRC)/src/doom/deh_misc.c \
	$(DOOM_SRC)/src/doom/deh_ptr.c \
	$(DOOM_SRC)/src/doom/deh_sound.c \
	$(DOOM_SRC)/src/doom/deh_thing.c \
	$(DOOM_SRC)/src/doom/deh_weapon.c \
	$(DOOM_SRC)/src/doom/d_items.c \
	$(DOOM_SRC)/src/doom/d_main.c \
	$(DOOM_SRC)/src/doom/d_net.c \
	$(DOOM_SRC)/src/doom/doomdef.c \
	$(DOOM_SRC)/src/doom/doomstat.c \
	$(DOOM_SRC)/src/doom/dstrings.c \
	$(DOOM_SRC)/src/doom/f_finale.c \
	$(DOOM_SRC)/src/doom/f_wipe.c \
	$(DOOM_SRC)/src/doom/g_game.c \
	$(DOOM_SRC)/src/doom/hu_lib.c \
	$(DOOM_SRC)/src/doom/hu_stuff.c \
	$(DOOM_SRC)/src/doom/info.c \
	$(DOOM_SRC)/src/doom/m_menu.c \
	$(DOOM_SRC)/src/doom/m_random.c \
	$(DOOM_SRC)/src/doom/p_ceilng.c \
	$(DOOM_SRC)/src/doom/p_doors.c \
	$(DOOM_SRC)/src/doom/p_enemy.c \
	$(DOOM_SRC)/src/doom/p_floor.c \
	$(DOOM_SRC)/src/doom/p_inter.c \
	$(DOOM_SRC)/src/doom/p_lights.c \
	$(DOOM_SRC)/src/doom/p_map.c \
	$(DOOM_SRC)/src/doom/p_maputl.c \
	$(DOOM_SRC)/src/doom/p_mobj.c \
	$(DOOM_SRC)/src/doom/p_plats.c \
	$(DOOM_SRC)/src/doom/p_pspr.c \
	$(DOOM_SRC)/src/doom/p_saveg.c \
	$(DOOM_SRC)/src/doom/p_setup.c \
	$(DOOM_SRC)/src/doom/p_sight.c \
	$(DOOM_SRC)/src/doom/p_spec.c \
	$(DOOM_SRC)/src/doom/p_switch.c \
	$(DOOM_SRC)/src/doom/p_telept.c \
	$(DOOM_SRC)/src/doom/p_tick.c \
	$(DOOM_SRC)/src/doom/p_user.c \
	$(DOOM_SRC)/src/doom/r_bsp.c \
	$(DOOM_SRC)/src/doom/r_data.c \
	$(DOOM_SRC)/src/doom/r_draw.c \
	$(DOOM_SRC)/src/doom/r_main.c \
	$(DOOM_SRC)/src/doom/r_plane.c \
	$(DOOM_SRC)/src/doom/r_segs.c \
	$(DOOM_SRC)/src/doom/r_sky.c \
	$(DOOM_SRC)/src/doom/r_things.c \
	$(DOOM_SRC)/src/doom/s_sound.c \
	$(DOOM_SRC)/src/doom/sounds.c \
	$(DOOM_SRC)/src/doom/statdump.c \
	$(DOOM_SRC)/src/doom/st_lib.c \
	$(DOOM_SRC)/src/doom/st_stuff.c \
	$(DOOM_SRC)/src/doom/wi_stuff.c \
	$(DOOM_SRC)/src/doom/doom_icon.c

# --- Shared platform layer (src/) ---
DOOM_SHARED = \
	$(DOOM_SRC)/src/i_main.c \
	$(DOOM_SRC)/src/i_system.c \
	$(DOOM_SRC)/src/m_argv.c \
	$(DOOM_SRC)/src/m_misc.c \
	$(DOOM_SRC)/src/aes_prng.c \
	$(DOOM_SRC)/src/d_event.c \
	$(DOOM_SRC)/src/d_iwad.c \
	$(DOOM_SRC)/src/d_loop.c \
	$(DOOM_SRC)/src/d_mode.c \
	$(DOOM_SRC)/src/deh_str.c \
	$(DOOM_SRC)/src/gusconf.c \
	$(DOOM_SRC)/src/i_cdmus.c \
	$(DOOM_SRC)/src/i_endoom.c \
	$(DOOM_SRC)/src/i_flmusic.c \
	$(DOOM_SRC)/src/i_glob.c \
	$(DOOM_SRC)/src/i_input.c \
	$(DOOM_SRC)/src/i_joystick.c \
	$(DOOM_SRC)/src/i_musicpack.c \
	$(DOOM_SRC)/src/i_oplmusic.c \
	$(DOOM_SRC)/src/i_pcsound.c \
	$(DOOM_SRC)/src/i_sdlmusic.c \
	$(DOOM_SRC)/src/i_sdlsound.c \
	$(DOOM_SRC)/src/i_sound.c \
	$(DOOM_SRC)/src/i_timer.c \
	$(DOOM_SRC)/src/i_video.c \
	$(DOOM_SRC)/src/i_videohr.c \
	$(DOOM_SRC)/src/i_winmusic.c \
	$(DOOM_SRC)/src/midifallback.c \
	$(DOOM_SRC)/src/midifile.c \
	$(DOOM_SRC)/src/mus2mid.c \
	$(DOOM_SRC)/src/m_bbox.c \
	$(DOOM_SRC)/src/m_cheat.c \
	$(DOOM_SRC)/src/m_config.c \
	$(DOOM_SRC)/src/m_controls.c \
	$(DOOM_SRC)/src/m_fixed.c \
	$(DOOM_SRC)/src/net_client.c \
	$(DOOM_SRC)/src/net_common.c \
	$(DOOM_SRC)/src/net_dedicated.c \
	$(DOOM_SRC)/src/net_gui.c \
	$(DOOM_SRC)/src/net_io.c \
	$(DOOM_SRC)/src/net_loop.c \
	$(DOOM_SRC)/src/net_packet.c \
	$(DOOM_SRC)/src/net_petname.c \
	$(DOOM_SRC)/src/net_query.c \
	$(DOOM_SRC)/src/net_sdl.c \
	$(DOOM_SRC)/src/net_server.c \
	$(DOOM_SRC)/src/net_structrw.c \
	$(DOOM_SRC)/src/p_rejectpad.c \
	$(DOOM_SRC)/src/sha1.c \
	$(DOOM_SRC)/src/memio.c \
	$(DOOM_SRC)/src/tables.c \
	$(DOOM_SRC)/src/v_diskicon.c \
	$(DOOM_SRC)/src/v_video.c \
	$(DOOM_SRC)/src/w_checksum.c \
	$(DOOM_SRC)/src/w_main.c \
	$(DOOM_SRC)/src/w_wad.c \
	$(DOOM_SRC)/src/w_file.c \
	$(DOOM_SRC)/src/w_file_stdc.c \
	$(DOOM_SRC)/src/w_merge.c \
	$(DOOM_SRC)/src/z_zone.c

# --- DeHackEd support ---
DOOM_DEH = \
	$(DOOM_SRC)/src/deh_io.c \
	$(DOOM_SRC)/src/deh_main.c \
	$(DOOM_SRC)/src/deh_mapping.c \
	$(DOOM_SRC)/src/deh_text.c

# --- Internal libraries ---
# OPL (Yamaha OPL2/OPL3 emulator for music)
DOOM_OPL = \
	$(DOOM_SRC)/opl/opl.c \
	$(DOOM_SRC)/opl/opl3.c \
	$(DOOM_SRC)/opl/opl_queue.c \
	$(DOOM_SRC)/opl/opl_sdl.c \
	$(DOOM_SRC)/opl/opl_timer.c

# PC Speaker emulation
DOOM_PCSOUND = \
	$(DOOM_SRC)/pcsound/pcsound.c \
	$(DOOM_SRC)/pcsound/pcsound_sdl.c

# Text-mode screen (for setup, not needed for game but linked)
DOOM_TEXTSCREEN = \
	$(DOOM_SRC)/textscreen/txt_button.c \
	$(DOOM_SRC)/textscreen/txt_checkbox.c \
	$(DOOM_SRC)/textscreen/txt_conditional.c \
	$(DOOM_SRC)/textscreen/txt_desktop.c \
	$(DOOM_SRC)/textscreen/txt_dropdown.c \
	$(DOOM_SRC)/textscreen/txt_fileselect.c \
	$(DOOM_SRC)/textscreen/txt_gui.c \
	$(DOOM_SRC)/textscreen/txt_inputbox.c \
	$(DOOM_SRC)/textscreen/txt_io.c \
	$(DOOM_SRC)/textscreen/txt_label.c \
	$(DOOM_SRC)/textscreen/txt_radiobutton.c \
	$(DOOM_SRC)/textscreen/txt_scrollpane.c \
	$(DOOM_SRC)/textscreen/txt_sdl.c \
	$(DOOM_SRC)/textscreen/txt_separator.c \
	$(DOOM_SRC)/textscreen/txt_spinctrl.c \
	$(DOOM_SRC)/textscreen/txt_strut.c \
	$(DOOM_SRC)/textscreen/txt_table.c \
	$(DOOM_SRC)/textscreen/txt_utf8.c \
	$(DOOM_SRC)/textscreen/txt_widget.c \
	$(DOOM_SRC)/textscreen/txt_window.c \
	$(DOOM_SRC)/textscreen/txt_window_action.c

# --- AmigaOS shims (missing libc functions) ---
DOOM_SHIMS = amiga_shims.c

ALL_SRCS = $(DOOM_ENGINE) $(DOOM_SHARED) $(DOOM_DEH) $(DOOM_OPL) $(DOOM_PCSOUND) $(DOOM_TEXTSCREEN) $(DOOM_SHIMS)
ALL_OBJS = $(patsubst %.c,%.o,$(ALL_SRCS))

TARGET = chocolate-doom

.PHONY: doom doom-docker clean

doom-docker:
	docker run --rm \
		-v "$(PWD)/../..:/work" \
		-v "$(DOOM_SRC):/doom-src" \
		-v "$(AMIPORT):/amiport" \
		-w /work/ports/chocolate-doom \
		-e HOME=/work \
		$(DOCKER_IMAGE) \
		make -f Makefile doom \
			DOOM_SRC=/doom-src \
			SDL2_DIR=/work \
			AMIPORT=/amiport

doom: $(TARGET)
	@echo "Built $(TARGET) ($$(wc -c < $(TARGET)) bytes)"

$(TARGET): $(ALL_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET)
	find $(DOOM_SRC) -name '*.o' -delete
