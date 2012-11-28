#include"SDL.h"
#ifndef EVENTS_H_
#define EVENTS_H_
void handle_event(SDL_Event*);
void game_quit();
bool key_pressed(SDLKey);
void events_setup();
#endif
