#ifndef DRAG_DROP_H
#define DRAG_DROP_H


#include "../raylib/raylib.h"
#include "struct.h"
#include <string>
#include <cstring>


void drag_drop(const char* filePath, char* fileName, Music& music, BoolState &state, VolBar &vbar);
void PrintFilePath(const char* filePath, char* fileName);


#endif
