#include "../include/headers/dragndrop.h"
#include "../include/headers/bars.h"
#include "../include/headers/struct.h"
#include "../include/headers/keys.h"

const int WIDTH = 800;
const int HEIGHT = 600;
Music music;

ProgBar bar;
VolBar vbar;
RemTime rt;
BoolState state;


int main() {

	InitWindow(WIDTH, HEIGHT, "Hess");
	SetTargetFPS(60);
	InitAudioDevice();
	
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
		EndDrawing();


	}

	
	if (state.musicLoaded) {
	 	StopMusicStream(music);       
     	UnloadMusicStream(music);    
	}
	
	CloseAudioDevice();
	CloseWindow();
	
	return 0;
}
