#ifndef STRUCT_H
#define STRUCT_H

#include "../raylib/raylib.h"

extern const int WIDTH;
extern const int HEIGHT;
extern Music music;


struct ProgBar {
    int barX;
    int barY;
    float progress;
    ProgBar() : barX(WIDTH - 50), barY(20), progress(0.0f) {}
};

struct VolBar {
    int barX;
    int barY;
    float volume;
    int vol;
    VolBar() : barX(20), barY(100), volume(0.5f), vol((int)(volume * 100)) {}
};


struct RemTime {
	float fullTime;
	float timePlayed;
    float remTime;
	int remHr;
	int remMin;
	int remSec;
	float progress;
};


struct BoolState {
	bool musicLoaded;
	bool isPaused;

    BoolState() : musicLoaded(false), isPaused(false) {}
};


#endif
