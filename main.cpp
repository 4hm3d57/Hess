#include "include/raylib/raylib.h"
#include <iostream>

#define WIDTH 800
#define HEIGHT 600

int main() {

	InitWindow(WIDTH, HEIGHT, "music player");
	InitAudioDevice();
	const char* filePath = "test.mp3";
	Music music = LoadMusicStream(filePath);
	PlayMusicStream(music);

	float volume = 0.5f;

	SetMusicVolume(music, volume);

	bool isPaused = false;


	while(!WindowShouldClose()){
		UpdateMusicStream(music);

		if(IsKeyPressed(KEY_SPACE)){
			if(IsMusicStreamPlaying(music)){
				PauseMusicStream(music);
				isPaused = true;
			}
			else {
				ResumeMusicStream(music);
				isPaused = false;
			}
		}

		if(IsKeyPressed(KEY_UP)){
			volume += 0.1f;
			if(volume > 1.0f) volume = 1.0f;
			SetMusicVolume(music, volume);
		}

		if(IsKeyPressed(KEY_DOWN)){ 
			volume -= 0.1f;
			if(volume < 0.0f) volume = 0.0f;
			SetMusicVolume(music, volume);
			
		}

		// progress bar variables
		float timePlayed = GetMusicTimePlayed(music);
		float full_time = GetMusicTimeLength(music);
		float progress = timePlayed / full_time;
		float remTime = (full_time - timePlayed) / 60;   // minutes
		int barX = WIDTH - 50;
		int barY = 20;


		// volume variables
		int volX = 10;
		int volY = 350;
		int volBarX = 20;
		int volBarY = 100;
		int volHeight = (int)(volBarY * volume);
		
		
		BeginDrawing();
		
		ClearBackground(GRAY);
		
		// progress bar
		DrawText(TextFormat("File: %s", filePath), 10, 10, 20, BLACK);
		DrawRectangle(10, 550, barX, barY, DARKGRAY);
		DrawRectangle(10, 550, (int)(barX * progress), barY, RED);
		DrawText(TextFormat("Time: %.2f", remTime), 10, 550, 20, BLACK);
		
		// voluem bar
		// DrawRectangle(volBarX, volBarY - volBarMaxHeight, volX, volBarMaxHeight, DARKGRAY);
		// DrawRectangle(volBarX, volBarY - volHeight, volX, volHeight, RED);

		DrawRectangle(volX, volY - volBarY, volBarX, volBarY, DARKGRAY);
		DrawRectangle(volX, volY - volHeight, volBarX, volHeight, RED);
		
		if(isPaused){
			DrawText(TextFormat("Paused"), WIDTH /2 - MeasureText("Paused", 20), HEIGHT / 2, 20, BLACK);
		} else {
			DrawText(TextFormat("Playing"), WIDTH /2 - MeasureText("Playing", 20), HEIGHT / 2, 20, BLACK);
		}
		
		EndDrawing();
	}

	UnloadMusicStream(music);
	CloseAudioDevice();
	CloseWindow();
	return 0;
	
}
