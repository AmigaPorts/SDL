/* amiport: stub sound_device for AmigaOS 3.x (no SDL_mixer yet)
 * Implements all functions from sound/device.h as no-ops.
 * Replace with real implementation once SDL2_mixer is ported. */

void sound_device_open(void) {}
void sound_device_close(void) {}

void sound_device_init_channels(int num_channels, char filenames[][32])
{
    (void)num_channels; (void)filenames;
}

int sound_device_is_channel_playing(int channel)
{
    (void)channel;
    return 0;
}

void sound_device_set_music_volume(int volume_pct)
{
    (void)volume_pct;
}

void sound_device_set_channel_volume(int channel, int volume_pct)
{
    (void)channel; (void)volume_pct;
}

int sound_device_play_music(const char *filename, int volume_pct)
{
    (void)filename; (void)volume_pct;
    return 0;
}

void sound_device_play_file_on_channel(const char *filename, int channel, int volume_pct)
{
    (void)filename; (void)channel; (void)volume_pct;
}

void sound_device_play_channel(int channel, int volume_pct)
{
    (void)channel; (void)volume_pct;
}

void sound_device_play_channel_panned(int channel, int volume_pct, int left_pct, int right_pct)
{
    (void)channel; (void)volume_pct; (void)left_pct; (void)right_pct;
}

void sound_device_stop_music(void) {}

void sound_device_stop_channel(int channel)
{
    (void)channel;
}

void sound_device_use_custom_music_player(int bitdepth, int num_channels, int rate,
                                          const unsigned char *data, int len)
{
    (void)bitdepth; (void)num_channels; (void)rate;
    (void)data; (void)len;
}

void sound_device_write_custom_music_data(const unsigned char *data, int len)
{
    (void)data; (void)len;
}

void sound_device_use_default_music_player(void) {}
