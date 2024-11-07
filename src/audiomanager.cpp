#include "audiomanager.h"

#include <stdexcept>

#include <AL/alc.h>

AudioManager::AudioManager() {
    device = alcOpenDevice(nullptr);
    if (device == nullptr) {
        throw std::runtime_error("Unable to open audio device");
    }

    context = alcCreateContext(device, nullptr);
    if (context == nullptr) {
        throw std::runtime_error("Unable to create audio context");
    }
    alcMakeContextCurrent(context);
}

AudioManager::~AudioManager() {
    alcMakeContextCurrent(nullptr);
    alcDestroyContext(context);
    alcCloseDevice(device);
}
