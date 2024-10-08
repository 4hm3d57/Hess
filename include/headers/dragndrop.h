#ifndef DRAG_DROP_H
#define DRAG_DROP_H


#include "../raylib/raylib.h"
#include "globals.h"
#include <string>
#include <cstring>


void drag_drop(const char* filePath, char* fileName, Music& music, BoolState &state, VolBar &vbar);
// print the audio file name
void PrintFilePath(const char* filePath, char* fileName);


#endif
