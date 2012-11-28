CC	= g++
CFLAGS	= -Wall -g `sdl-config --cflags --libs`
OBJS	= main.o animation.o npc.o player.o events.o 

all:	sdlgame
sdlgame:	${OBJS}
		${CC} ${CFLAGS} -o $@ $?

main.o:		animation.c player.c events.c npc.c animation.h player.h events.h npc.h	
animation.o:	animation.c animation.h player.c player.h events.c events.h
npc.o:		npc.c npc.h
player.o:	player.c player.h
events.o:	events.c events.h player.c player.h animation.c animation.h
