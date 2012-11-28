#include"player.h"
animal* playermove;
void player_setup(animal* x)
{	
	playermove = x;
	playermove->fps = 200;
	playermove->cur_frame = 0;
	playermove->inc_frame = 1;	
	playermove->tim_frame = 0;
	strcpy(playermove->image, "player.png");
	playermove->left[0] = 64;
	playermove->left[1] = 224;
	playermove->left[2] = 64;
	playermove->right[0] = 352;
	playermove->right[1] = 288;
	playermove->right[2] = 352;
	playermove->up[0] = 32;
	playermove->up[1] = 96;
	playermove->up[2] = 128;
	playermove->down[0] = 0;
	playermove->down[1] = 160;
	playermove->down[2] = 192;
	playermove->move.sps = 20;
	playermove->move.tim_step = 0;
	playermove->move.inc_step = 1;
	playermove->move.moving = false;
}	
void player_move(SDLKey key)
{	
	if (playermove->move.moving) return;
	playermove->move.direction = key;
	playermove->move.moving = true;
	playermove->move.sign = get_sign(key);
	playermove->move.distance = 16; 
}
	
