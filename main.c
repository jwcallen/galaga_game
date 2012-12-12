#include"animation.h"
#include"player.h"
#include"events.h"
#include"SDL.h"
#include"npc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SCREEN_WIDTH		640
#define SCREEN_HEIGHT		480
#define SPRITE_SIZE		32
#define MOVE_SPEED		2
#define FPS			60	
#define CAP			1

void data_setup();
void window_setup();
void demo_setup();

int colorkey, endtime, start_time;
SDL_Surface *screen, *temp, *sprite, *grass;
SDL_Rect rcSrc_Grass, rcGrass;
SDL_Rect rcSrc_Sprite, rcSprite;
animal demo[2];

void window_setup()
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_WM_SetCaption("gnubugs", "gnubugs");
	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
	SDL_EnableKeyRepeat(1, 1);
}

void data_setup()
{
	events_setup();
	player_setup(&(demo[0]));
	person_setup(&(demo[1]));
	demo_setup();
}

void demo_setup()
{
	temp   = SDL_LoadBMP("sprite2.bmp");
	sprite = SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);

	colorkey = SDL_MapRGB(screen->format, 255, 0, 255);
	SDL_SetColorKey(sprite, SDL_SRCCOLORKEY | SDL_RLEACCEL, colorkey);

	temp  = SDL_LoadBMP("grass.bmp");
	grass = SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);

	rcSprite.x = 64;
	rcSprite.y = 64;

	rcSrc_Sprite.x = 0;
	rcSrc_Sprite.y = 0;
	rcSrc_Sprite.w = SPRITE_SIZE;
	rcSrc_Sprite.h = SPRITE_SIZE;

	rcSrc_Grass.x = 0;
	rcSrc_Grass.y = 0;
	rcSrc_Grass.w = SPRITE_SIZE;
	rcSrc_Grass.h = SPRITE_SIZE;
}

int main()
{
	window_setup();
	data_setup();
	SDL_Event event;	
	while(1)
	{
	start_time = SDL_GetTicks();

	if (SDL_PollEvent(&event))
	{
		handle_event(&event);
	}
	
	//Set up screen and background display
	for (int x = 0; x < SCREEN_WIDTH / SPRITE_SIZE; x++) 
	{
		for (int y = 0; y < SCREEN_HEIGHT / SPRITE_SIZE; y++)
		{
			rcGrass.x = x * SPRITE_SIZE;
			rcGrass.y = y * SPRITE_SIZE;
			SDL_BlitSurface(grass, &rcSrc_Grass, screen, &rcGrass);
		}
	}
	
	//Handle character movement
	int i = 0;
	for (i = 0; i<2; i++){
		npc_move(&demo[i]);
		animate(&demo[i]);
		move(&demo[i]);

		rcSprite.x = demo[i].move.position[0];
		rcSprite.y = demo[i].move.position[1];
		switch(demo[i].move.direction)
		{
			case SDLK_UP:
				rcSrc_Sprite.y = demo[i].up[demo[i].cur_frame];
			break;
			case SDLK_DOWN:
				rcSrc_Sprite.y = demo[i].down[demo[i].cur_frame];
			break;
			case SDLK_LEFT:
				rcSrc_Sprite.y = demo[i].left[demo[i].cur_frame];
			break;
			case SDLK_RIGHT:
				rcSrc_Sprite.y = demo[i].right[demo[i].cur_frame];
			break;
		}
		SDL_BlitSurface(sprite, &rcSrc_Sprite, screen, &rcSprite);
	}/*
	animate(&demo1);
	animate(&demo2);
	
	move(&demo1);
	move(&demo2);

	rcSprite.x = demo1.move.position[0];
	rcSprite.y = demo1.move.position[1];
		switch(demo1.move.direction)
		{
			case SDLK_UP:
				rcSrc_Sprite.y = demo1.up[demo1.cur_frame];
			break;
			case SDLK_DOWN:
				rcSrc_Sprite.y = demo1.down[demo1.cur_frame];
			break;
			case SDLK_LEFT:
				rcSrc_Sprite.y = demo1.left[demo1.cur_frame];
			break;
			case SDLK_RIGHT:
				rcSrc_Sprite.y = demo1.right[demo1.cur_frame];
			break;
		}
*/
	SDL_UpdateRect(screen, 0, 0, 0, 0);
	endtime = SDL_GetTicks()-start_time;
	if (1000/FPS > endtime) SDL_Delay((1000/FPS)-endtime);
	}
}
