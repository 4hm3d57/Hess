#include "../include/headers/dragndrop.h"
#include "../include/headers/bars.h"
#include "../include/headers/globals.h"
#include "../include/headers/keys.h"
#include "../include/headers/buttons.h"


const int WIDTH = 800;
const int HEIGHT = 600;
Music music;


ProgBar bar;
VolBar vbar;
RemTime rt;
BoolState state;


int main() {

	InitWindow(WIDTH, HEIGHT, "Hess");
	InitAudioDevice();
    init_button();
    
    SetTargetFPS(60);
	
	const char* filePath = nullptr;
	char fileName[512] = {0};  
	
	
	while (!WindowShouldClose()) {
		if (state.musicLoaded) {
			UpdateMusicStream(music);  
		}
		
		// Drag and drop the music files
		drag_drop(filePath, fileName, music, state, vbar);
        // check if music is loaded
        CheckIfMusicIsLoaded(state, rt);
        // keys set for use
		input_keys(state, vbar, rt);

		BeginDrawing();
		ClearBackground(GRAY);
        // this function prints the name of the audio file
        PrintFilePath(filePath, fileName);
		// Draw the progress bars
		render_bar(bar, vbar, rt, state);
		// draw buttons
        draw_buttons();
        CheckPressedBtn(state, rt);
		EndDrawing();
	}

    
	
	if (state.musicLoaded) {
	 	StopMusicStream(music);       
     	UnloadMusicStream(music);    
	}
	
    cleanup_buttons();

	CloseAudioDevice();
	CloseWindow();
	
	return 0;
}
