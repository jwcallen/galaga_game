#include"object.h"

tile[][] map;

enum Graphic
{
	//List of Graphics
}

typedef struct
{
	bool collide, door, hasobject, hasnpc;
	enum Graphic tile;
	object thing;
} tile;
