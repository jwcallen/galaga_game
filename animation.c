//Animation functions
#include"animation.h"
#include"events.h"
#include"player.h"

void animate(animal* x)
{
	if (!x->move.moving) {x->cur_frame = 0; return;}

	if (x->tim_frame + x->fps > SDL_GetTicks()) return;
	
	x->tim_frame = SDL_GetTicks();
	if (x->cur_frame == 2) x->cur_frame = 1; else x->cur_frame += x->inc_frame;
}

void move(animal* x)
{
	if (!x->move.moving || x->move.tim_step + x->move.sps > SDL_GetTicks()) return;
	if(x->move.sign)
		x->move.position[get_axis(x->move.direction)] -= x->move.inc_step;
	else
		x->move.position[get_axis(x->move.direction)] += x->move.inc_step;
	x->move.distance--;
	x->move.tim_step = SDL_GetTicks();
	if(x->move.distance == 0) x->move.moving = false;
}

SDLKey redirect_key(SDLKey key)
{
	switch(key)
	{
		case SDLK_k:
			return SDLK_UP;
		break;
		case SDLK_j:
			return SDLK_DOWN;
		break;
		case SDLK_h:
			return SDLK_LEFT;
		break;
		case SDLK_l:
			return SDLK_LEFT;
		break;
		default:
			return key;
		break;
	}
}

int get_sign(SDLKey key)
{
	switch(key)
	{
		case SDLK_RIGHT:
		case SDLK_DOWN:
			return 0;
		break;
		case SDLK_LEFT:
		case SDLK_UP:
			return 1;
		break;
	}
}	
int get_axis(SDLKey key)
{
	switch(key)
	{
		case SDLK_UP:
		case SDLK_DOWN:
			return 1;
		break;
		case SDLK_LEFT:
		case SDLK_RIGHT:
			return 0;
		break;
	}
}
