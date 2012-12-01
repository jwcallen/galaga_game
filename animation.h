#ifndef ANIMATION_H_
#define ANIMATION_H_
#include<SDL.h>


enum cardinal {north, south, east, west};
enum move_script {circle, square, standing};

typedef struct
{
	/*
	/ sps, the ms in between each frame, must be greater than 1000/fps
	/ tim_step, the last saved SDL_GetTicks() to be referenced with sps
	/ inc_step, the pixel length of each step
	/ direction, the direction of the movement
	/ moving, boolean value defining the moving condition
	*/
	int sps, tim_step, inc_step, distance, sign;
	bool moving;
	SDLKey direction;
	int position[2];
} movabal;

typedef struct{
	move_script script;
	unsigned int stage;
	unsigned int config[8];
} ai;

typedef struct{
	//interaction
} interactor;

typedef struct{
	//item info
} informatel;

typedef struct
{
	/*
	/fps, the ms in between each frame
	/frames,
	/cur_frame, the frame number of the frame to display
	/inc_frame, the increment to be used on cur_frame
	/tim_frame, the last saved SDL_GetTicks() to be referenced with fps
	/image[], the character array holding the image source of the sprite
	/
	/up[],
	/down[],
	/right[],
	/left[], the pixel indexes in order of animation within the sprite
	*/
	int fps, frames, cur_frame, inc_frame, tim_frame;
	char image[20];
	int left[3], right[3], up[3], down[3];
	movabal move;
	ai intel;	
	
} animal;

void animate(animal*);
void move(animal*);
SDLKey redirect_key(SDLKey);
int get_axis(SDLKey);
int get_sign(SDLKey);
#endif	
