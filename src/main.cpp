#include <cstdlib>
#include <iostream>
#include <fstream>

#include "audiomanager.h"
#include "audio.h"

bool file_exists(const char *file_name) {
    std::ifstream file(file_name);
    return file.good();
}

int main(int argc, char **argv) {
    if (argc == 1) {
        std::cout << "Ogg Vorbis file not provided.\n";
        std::cout << "Usage: " << argv[0] << " FILE\n";
        return EXIT_FAILURE;
    }

    AudioManager audio_manager;
    auto file_name = argv[1];

    if (!file_exists(file_name)) {
        std::cout << "File does not exist.\n";
        return EXIT_FAILURE;
    }

    Audio track{file_name};

    if (!track.loaded_succesfully()) {
        std::cout << "Track loaded succesfully\n";
        return EXIT_FAILURE;
    }

    track.play();

    return EXIT_SUCCESS;
}
