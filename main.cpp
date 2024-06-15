#include "include/raylib/raylib.h"
#include <cstring>

#define WIDTH 800
#define HEIGHT 600

const char* PataFileName(const char* filePath) {
	const char* fileName = strrchr(filePath, '/');
	if (fileName) {
		return fileName + 1; // Skip the '/'
	}
	fileName = strrchr(filePath, '\\');
	if (fileName) {
		return fileName + 1; // Skip the '\'
	}
	return filePath; // No path separators found, return the whole path
}

void progressBar(int barX, int barY, float progress, int remHr, int remMin, int remSec);
void volumeBar(int barX, int barY, float volume, int vol);

int main() {
	InitWindow(WIDTH, HEIGHT, "test");
	SetTargetFPS(60);
	InitAudioDevice();

	const char* filePath = nullptr;
	char fileName[512] = {0};
	Music music;
	bool musicLoaded = false;
	bool isPause = false;
	float volume = 0.5f;
	
	while (!WindowShouldClose()) {
		if (musicLoaded) {
			UpdateMusicStream(music);
		}
		
		// Drag and drop file to be played
		if (IsFileDropped()) {
			FilePathList droppedFiles = LoadDroppedFiles();
			if (droppedFiles.count > 0) {
				filePath = droppedFiles.paths[0];
				strncpy(fileName, PataFileName(filePath), sizeof(fileName) - 1);
				fileName[sizeof(fileName) - 1] = '\0';
				if (musicLoaded) {
					StopMusicStream(music);
					UnloadMusicStream(music);
				}
				music = LoadMusicStream(filePath);
				if(IsMusicReady(music)){
					PlayMusicStream(music);
					SetMusicVolume(music, volume);
					musicLoaded = true;
				} else {
					TraceLog(LOG_WARNING, "Music file could not be loaded");
					musicLoaded = false;
				}
				
			}
			UnloadDroppedFiles(droppedFiles);
		}
		
		float timePlayed = 0.0f;
		float fullTime = 0.0f;
		float remTime = 0.0f;
		int remHr = 0.0f;
		int remMin = 0.0f;
		int remSec = 0.0f;
		float progress = 0.0f;
		
		if (musicLoaded) {
			timePlayed = GetMusicTimePlayed(music);
			fullTime = GetMusicTimeLength(music);
			remTime = fullTime - timePlayed;
			remHr = (int)remTime / 3600;
			remMin = (int)(remTime / 60) % 60;
			remSec = (int)remTime % 60;
			progress = timePlayed / fullTime;
		}
		
		// Progress bar variables
		int barX = WIDTH - 50;
		int barY = 20;
		
		// Volume bar variables
		int volBarX = 20;
		int volBarY = 100;
		int vol = volume * 100;
		
		if (IsKeyPressed(KEY_SPACE) && musicLoaded) {
			if (IsMusicStreamPlaying(music)) {
				PauseMusicStream(music);
				isPause = true;
			} else {
				ResumeMusicStream(music);
				isPause = false;
			}
		}
		
		if (IsKeyPressed(KEY_UP) && musicLoaded) {
			volume += 0.1f;
			if (volume > 1.0f) volume = 1.0f;
			SetMusicVolume(music, volume);
		}
		
		if (IsKeyPressed(KEY_DOWN) && musicLoaded) {
			volume -= 0.1f;
			if (volume < 0.0f) volume = 0.0f;
			SetMusicVolume(music, volume);
		}
		
		BeginDrawing();
		ClearBackground(GRAY);
		
		if (filePath) {
			DrawText(TextFormat("File: %s", fileName), 10, 10, 20, BLACK);
		} else {
			DrawText("No file loaded.", 10, 10, 20, BLACK);
		}
		
		if (musicLoaded) {
			if (!isPause) {
				DrawText("Playing", (WIDTH / 2) - (MeasureText("Playing", 20) / 2), HEIGHT / 2, 20, BLACK);
			} else {
				DrawText("Paused", (WIDTH / 2) - (MeasureText("Paused", 20) / 2), HEIGHT / 2, 20, BLACK);
			}
			
			progressBar(barX, barY, progress, remHr, remMin, remSec);
			volumeBar(volBarX, volBarY, volume, vol);
		} else {
			DrawText("Drag and drop file", (WIDTH / 2) - (MeasureText("Drag and drop file", 20) / 2), HEIGHT / 2, 20, BLACK);
		}
		
		EndDrawing();
	}
	
	if (musicLoaded) {
		StopMusicStream(music);
		UnloadMusicStream(music);
	}
	
	CloseAudioDevice();
	CloseWindow();
	return 0;
}

void progressBar(int barX, int barY, float progress, int remHr, int remMin, int remSec) {
	int musicProg = (int)(barX * progress);
	DrawRectangle(10, 550, barX, barY, DARKGRAY);
	DrawRectangle(10, 550, musicProg, barY, RED);
	DrawText(TextFormat("Time: %02d:%02d:%02d", remHr, remMin, remSec), 10, 550, 20, BLACK);
}

void volumeBar(int barX, int barY, float volume, int vol) {
	int volProg = (int)(barY * volume);
	DrawRectangle(10, 350 - barY, barX, barY, DARKGRAY);
	DrawRectangle(10, 350 - volProg, barX, volProg, RED);
	DrawText(TextFormat("%d", vol), 10, 350, 15, BLACK);
}
