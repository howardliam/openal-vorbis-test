#include "audio.h"

#define STB_VORBIS_HEADER_ONLY
#include "stb_vorbis.c"

Audio::Audio(const char *file_name) : file_name{file_name} {
    load_ogg();

    ALenum format;
    if (channels == 1) {
        format = AL_FORMAT_MONO16;
    } else if (channels == 2) {
        format = AL_FORMAT_STEREO16;
    }

    alGenBuffers(1, &buffer);
    alBufferData(buffer, format, data.data(), data.size() * sizeof(short), sample_rate);

    alGenSources(1, &source);
    alSourcei(source, AL_BUFFER, buffer);
}

Audio::~Audio() {
    alDeleteSources(1, &source);
    alDeleteBuffers(1, &buffer);
}

bool Audio::loaded_succesfully() {
    return loaded;
}

void Audio::play() {
    alSourcePlay(source);

    ALint state;
    do {
        alGetSourcei(source, AL_SOURCE_STATE, &state);
    } while (state == AL_PLAYING);
}

void Audio::load_ogg() {
    stb_vorbis *vorbis = stb_vorbis_open_filename(file_name.c_str(), nullptr, nullptr);
    if (vorbis == nullptr) {
        stb_vorbis_close(vorbis);
        return;
    }

    stb_vorbis_info info = stb_vorbis_get_info(vorbis);
    sample_rate = info.sample_rate;
    channels = info.channels;

    int sample_count = stb_vorbis_stream_length_in_samples(vorbis) * channels;
    std::vector<short> output(sample_count);
    int samples_decoded = stb_vorbis_get_samples_short_interleaved(vorbis, channels, output.data(), sample_count);

    stb_vorbis_close(vorbis);

    output.resize(samples_decoded * info.channels);

    data = output;
    loaded = true;
}
