#ifndef AUDIO_H
#define AUDIO_H

#include <vector>
#include <string>

#include <AL/al.h>

class Audio {
public:
    Audio(const char *file_name);
    ~Audio();

    bool loaded_succesfully();
    void play();

private:
    std::string file_name{};

    bool loaded = false;
    std::vector<short> data{};
    int sample_rate{};
    int channels{};

    ALenum format{};
    ALuint buffer{};
    ALuint source{};

    void load_ogg();
};

#endif
