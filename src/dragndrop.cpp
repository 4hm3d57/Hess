#include "../include/headers/dragndrop.h"
#include <cstring>
#include <iostream>

const char* PataFileName(const char* filePath) {
	const char* fileName = strrchr(filePath, '/');
	if (fileName) {
		return fileName + 1; 
	}
	fileName = strrchr(filePath, '\\');
	if (fileName) {
		return fileName + 1; 
	}
	return filePath; 
}

void drag_drop(const char* filePath, char *fileName, Music& music, BoolState &state, VolBar &vbar) {
	if (IsFileDropped()) {
			FilePathList droppedFiles = LoadDroppedFiles();
			if (droppedFiles.count > 0) {
				filePath = droppedFiles.paths[0];
				const char* baseName = PataFileName(filePath);
				strncpy(fileName, baseName, 511);
				fileName[511] = '\0';

				std::cout << "Dropped file path: " << filePath << std::endl;
				std::cout << "file name: " << fileName << std::endl;

				if (state.musicLoaded) {
					StopMusicStream(music);
					UnloadMusicStream(music);
				}
				music = LoadMusicStream(filePath);
				if(IsMusicReady(music)){
					PlayMusicStream(music);
					SetMusicVolume(music, vbar.volume);
					state.musicLoaded = true;
				} else {
					TraceLog(LOG_WARNING, "Music file could not be loaded");
					state.musicLoaded = false;
				}
				
			}
			UnloadDroppedFiles(droppedFiles);
		}
}

void PrintFilePath(const char* filePath, char* fileName) {
    if (fileName && strlen(fileName) > 0) {
        DrawText(TextFormat("File: %s", fileName), 10, 10, 15, BLACK);
    } else {
        DrawText("No file Loaded", 10, 10, 15, BLACK);
    }
}
