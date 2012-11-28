#include"animation.h"

typedef struct 
{
	int enable;
	int id;
	int type;
	animal* anim;
}object;

typedef struct 
{
	int enable;
	int id;
	int type;
	animal* anim;
	movabal* move;
	//npc specific struct
}npc;
