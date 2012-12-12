#sdlgame

##about
sdlgame is a framework written in sdl capable of supporting 2D graphical games. It provides animation and movement data structures
and separates the concept of frames per a second and animation speed. The framework can easily support a wide range of diverse
range of sprite types and frame counts. However this is also its greatest downfall. In games where sprites differ in visual design,
but not animation and speed, the framework has a lot of overhead.

##demo
The demo demonstrates the power of the framework using art assets ripped from various Pokemon games. It is meant to simply demonstrate
the animation and movement handling on two actors, an npc moving in a circle and a player character.

##controls
movement
	arrowkeys
	
quit
	q

##todo
1. The next feature to implement is a map based movement wrapper so that obstruction detection is possible. This will allow for a great
deal of code cleanup and restructuring.

2. A restructure of the animation and movement system is being considered. A unified actor struct will represent a single npc/player.
This will hinder the support of diverse animation and movement styles, but will allow for greater readability.

3. Quit cleanup is unfinished, so the client crashes on a quit.
