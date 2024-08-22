#include "../include/raylib/raylib.h"
#include "../include/headers/keys.h"



void input_keys(BoolState &state, VolBar &vbar, RemTime &rt){

    // space key for pausing the audio
    if(IsKeyPressed(KEY_SPACE) && state.musicLoaded){
        if(IsMusicStreamPlaying(music)){
            PauseMusicStream(music);
            state.isPaused = true;
        }
        else {
            ResumeMusicStream(music);
            state.isPaused = false;
        }
    }

    // increasing volume
    if(IsKeyPressed(KEY_UP) && state.musicLoaded){
        vbar.volume += 0.1f;
        if(vbar.volume > 1.0f) vbar.volume = 1.0f;
        SetMusicVolume(music, vbar.volume);
        vbar.vol = (int)(vbar.volume * 100);
    }

    // decreasing volume
    if(IsKeyPressed(KEY_DOWN) && state.musicLoaded){
        vbar.volume -= 0.1f;
        if(vbar.volume < 0.0f) vbar.volume = 0.0f;
        SetMusicVolume(music, vbar.volume);
        vbar.vol = (int)(vbar.volume * 100);
    }


    // speeding the audio by 10 seconds
    if(IsKeyPressed(KEY_RIGHT) && state.musicLoaded){
        rt.timePlayed += 10.0f;
        if(rt.timePlayed > rt.fullTime) rt.timePlayed = rt.fullTime;
        SeekMusicStream(music, rt.timePlayed);
    }


    //rewinding the audio by 10 seconds
    if(IsKeyPressed(KEY_LEFT) && state.musicLoaded){
        rt.timePlayed -= 10.0f;
        if(rt.timePlayed < 0.0f) rt.timePlayed = 0.0f;
        SeekMusicStream(music, rt.timePlayed);
    }

}