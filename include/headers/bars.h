#ifndef BARS_H
#define BARS_H


#include "../raylib/raylib.h"
#include "globals.h"


// progress bar
void DrawProgressBar(ProgBar &bar, RemTime &rt);
// volume bar
void DrawVolumeBar(VolBar &vbar);
// draw progress and volume bar
void render_bar(ProgBar &bar, VolBar &vbar, RemTime &rt, BoolState &state);
// check if the music is loaded
void CheckIfMusicIsLoaded(BoolState &state, RemTime &rt);



#endif
