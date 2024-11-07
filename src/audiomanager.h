#ifndef AUDIOMANANAGER_H
#define AUDIOMANANAGER_H

#include <AL/alc.h>

class AudioManager {
public:
    AudioManager();
    ~AudioManager();

private:
    ALCdevice *device;
    ALCcontext *context;
};

#endif
