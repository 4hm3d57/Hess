#include "../include/headers/buttons.h"
#include <cmath>

Button::Button(int x, int y, int width, int height, const char* iconPath) {
    bounds = { (float)x, (float)y, (float)width, (float)height };
    icon = LoadTexture(iconPath);
    isPressed = false;
}

Button::~Button() {
    UnloadTexture(icon);
}

Button *rewindButton;
Button *playButton;
Button *forwardButton;

void Button::Draw() {
    float scaleX = bounds.width / icon.width;
    float scaleY = bounds.height / icon.height;
    
    float scalingFactor = 1.0f;
    scaleX *= scalingFactor;
    scaleY *= scalingFactor;

    DrawTextureEx(icon, {bounds.x, bounds.y}, 0.0f, fmin(scaleX, scaleY), WHITE);
}

bool Button::IsClicked() {
    if (CheckCollisionPointRec(GetMousePosition(), bounds) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        isPressed = true;
        return true;
    }
    isPressed = false;
    return false;
}

void draw_buttons(){
    rewindButton->Draw();
    playButton->Draw();
    forwardButton->Draw();
}


void init_button(){
    rewindButton = new Button(300, 560, 30, 30, "assets/textures/rewind.png");
    playButton = new Button(400, 560, 30, 30, "assets/textures/play.png");
    forwardButton = new Button(500, 560, 30, 30, "assets/textures/forward.png");
}


void CheckPressedBtn(BoolState &state, RemTime &rt){
    if(rewindButton->IsClicked()){
        if (state.musicLoaded){
            rt.timePlayed -= 10.0f;
            if (rt.timePlayed < 0.0f) rt.timePlayed = 0.0f;
            SeekMusicStream(music, rt.timePlayed);
        }
    }
    if(playButton->IsClicked()){
        if (state.musicLoaded) {
            if (IsMusicStreamPlaying(music)) {
                PauseMusicStream(music);
                state.isPaused = true;
            } else {
                ResumeMusicStream(music);
                state.isPaused = false;
            }
        }   
    }
    if(forwardButton->IsClicked()){
        if (state.musicLoaded) {
            rt.timePlayed += 10.0f;
            if (rt.timePlayed > rt.fullTime) rt.timePlayed = rt.fullTime;
            SeekMusicStream(music, rt.timePlayed);
        }
    }
}


void cleanup_buttons() {
    delete rewindButton;
    delete playButton;
    delete forwardButton;
}