#ifndef BARS_H
#define BARS_H


#include "../raylib/raylib.h"
#include "struct.h"


// progress bar
void DrawProgressBar(ProgBar &bar, RemTime &rt);

// volume bar
void DrawVolumeBar(VolBar &vbar);

// render progress bar
void render_bar(ProgBar &bar, VolBar &vbar, RemTime &rt, BoolState &state);


// check if the music is loaded
void CheckIfMusicIsLoaded(BoolState &state, RemTime &rt);



#endif
