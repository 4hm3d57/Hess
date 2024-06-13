#include "../include/raylib/raylib.h"
#include <iostream>

#define WIDTH 800
#define HEIGHT 600

int main() {

	InitWindow(WIDTH, HEIGHT, "music player");
	InitAudioDevice();
	const char* filePath = "test.mp3";
	Music music = LoadMusicStream(filePath);
	PlayMusicStream(music);

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


		float timePlayed = GetMusicTimePlayed(music);
		float full_time = GetMusicTimeLength(music);
		float progress = timePlayed / full_time;
		float remTime = (full_time - timePlayed) / 60;   // minutes
		int barX = WIDTH - 50;
		int barY = 20;


		
		
		BeginDrawing();
		
		ClearBackground(GRAY);
		DrawRectangle(10, 550, barX, barY, DARKGRAY);
		DrawRectangle(10, 550, (int)(barX * progress), barY, RED);
		DrawText(TextFormat("Time: %.2f", remTime), 10, 550, 20, BLACK);

		if(isPaused){
			DrawText(TextFormat("Paused"), WIDTH /2 - MeasureText("Paused", 20), HEIGHT / 2, 20, BLACK);
		} else {
			DrawText(TextFormat("Playing"), WIDTH /2 - MeasureText("Playing", 20), HEIGHT / 2, 20, BLACK);
		}
		
		EndDrawing();
	}

	CloseWindow();
	return 0;
	
}


