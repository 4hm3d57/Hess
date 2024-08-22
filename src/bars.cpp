#include "../include/headers/bars.h"

void DrawProgressBar(ProgBar &bar, RemTime &rt) {
    int musicProg = (int)(bar.barX * rt.progress);  
    DrawRectangle(20, 530, bar.barX, bar.barY, DARKGRAY);  
    DrawRectangle(20, 530, musicProg, bar.barY, RED);
    DrawText(TextFormat("Time: %02d:%02d:%02d", rt.remHr, rt.remMin, rt.remSec), 20, 530, 20, BLACK);  
}

void DrawVolumeBar(VolBar &vbar) {
    int volProg = (int)(vbar.barY * vbar.volume);  
    DrawRectangle(10, 350 - vbar.barY, vbar.barX, vbar.barY, DARKGRAY);  
    DrawRectangle(10, 350 - volProg, vbar.barX, volProg, RED);;
    DrawText(TextFormat("%d%%", vbar.vol), 10, 350, 15, BLACK);
}


void CheckIfMusicIsLoaded(BoolState &state, RemTime &rt){
    if(state.musicLoaded) {
        rt.timePlayed = GetMusicTimePlayed(music);
        rt.fullTime = GetMusicTimeLength(music);
        rt.remTime = rt.fullTime - rt.timePlayed;
        rt.remHr = (int)rt.remTime / 3600;
        rt.remMin = (int)(rt.remTime / 60) % 60;
        rt.remSec = (int)rt.remTime % 60;
        rt.progress = rt.timePlayed / rt.fullTime;
    }
}

void render_bar(ProgBar &bar, VolBar &vbar, RemTime &rt, BoolState &state) {
    if (state.musicLoaded) {
        if (!state.isPaused) {
            DrawText("Playing", (WIDTH / 2) - (MeasureText("Playing", 20) / 2), HEIGHT / 2, 20, BLACK);
        } else {
            DrawText("Paused", (WIDTH / 2) - (MeasureText("Paused", 20) / 2), HEIGHT / 2, 20, BLACK);
        }
        DrawProgressBar(bar, rt);
        DrawVolumeBar(vbar);
    } else {
        DrawText("Drag and drop files", (WIDTH / 2) - (MeasureText("Drag and drop files", 20) / 2), HEIGHT / 2, 20, BLACK);
    }
}



