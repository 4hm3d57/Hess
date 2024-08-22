#ifndef BUTTON_H
#define BUTTON_H

#include "globals.h"

void draw_buttons();
void init_button();
void CheckPressedBtn(BoolState &state, RemTime &rt);
void cleanup_buttons();

#endif