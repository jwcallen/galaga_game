#include"npc.h"
void person_setup(animal* x)
{	
	x->fps = 200;
	x->cur_frame = 0;
	x->inc_frame = 1;	
	x->tim_frame = 0;
	strcpy(x->image, "person.png");
	x->left[0] = 64;
	x->left[1] = 224;
	x->left[2] = 64;
	x->right[0] = 352;
	x->right[1] = 288;
	x->right[2] = 352;
	x->up[0] = 32;
	x->up[1] = 96;
	x->up[2] = 128;
	x->down[0] = 0;
	x->down[1] = 160;
	x->down[2] = 192;
	x->move.sps = 20;
	x->move.tim_step = 0;
	x->move.inc_step = 1;
	x->move.moving = false;
	x->intel.config[0]=128;
	x->intel.stage = 0;
	x->intel.script = square;

}	
void npc_move(animal* x)
{	
	if (x->move.moving) return;
	if (x->intel.script == square)
		square_script(x);
}

void square_script(animal* x){
	if (x->intel.stage == 0)
	x->move.direction = SDLK_RIGHT;
	else if (x->intel.stage == 1)
	x->move.direction = SDLK_DOWN;
	else if (x->intel.stage == 2)
	x->move.direction = SDLK_LEFT;
	else if (x->intel.stage == 3)
	x->move.direction = SDLK_UP;

	x->move.moving = true;
	x->move.sign = get_sign(x->move.direction);
	x->move.distance = x->intel.config[0]; 
	x->intel.stage<3 ? x->intel.stage++ : x->intel.stage=0;
}
