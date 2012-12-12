//event handler
#include"events.h"
#include"player.h"
#include"animation.h"

Uint8 *keystate;

void events_setup()
{
	keystate = SDL_GetKeyState(NULL);
}

//Function handles event passed to it
//Determines cause of event and acts accordingly
void handle_event(SDL_Event* event)
{
	switch(event->type)
	{
		case SDL_KEYDOWN:
			switch(event->key.keysym.sym)
			{
				case SDLK_ESCAPE:
				case SDLK_q:
					game_quit();
				break;
				case SDLK_DOWN:
				case SDLK_UP:
				case SDLK_LEFT:
				case SDLK_RIGHT:
				case SDLK_l:
				case SDLK_h:
				case SDLK_j:
				case SDLK_k:
					player_move(redirect_key(event->key.keysym.sym));
				break;
			}
		break;
		case SDL_KEYUP:
		break;
		case SDL_MOUSEBUTTONDOWN:
		break;
		case SDL_MOUSEBUTTONUP:
		break;
		case SDL_JOYAXISMOTION:
		break;
		case SDL_JOYBALLMOTION:
		break;
		case SDL_JOYHATMOTION:
		break;
		case SDL_JOYBUTTONDOWN:
		break;
		case SDL_JOYBUTTONUP:
		break;
		case SDL_VIDEORESIZE:
		break;
		case SDL_VIDEOEXPOSE:
		break;
		case SDL_QUIT:
			game_quit();
		break;
		case SDL_USEREVENT:
		break;
		case SDL_SYSWMEVENT:
		break;
	}
}

//Arguments: SDLKey
//Returns: State of the key: true or false
bool key_pressed(SDLKey x)
{
	return (bool)keystate[x];
}

//Function to handle quitting of the game
void game_quit()
{

	/* clean up */
	SDL_Quit();

}
