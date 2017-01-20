
#include <SDL.h>
#include "AwcVector2D.h"
#include "ASurface.h"

#define FRAMES_PER_SECOND 60
#define MS_PER_FRAME 17
//#define MS_PER_FRAME 1000/FRAMES_PER_SECOND

extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;
extern int PPM;
extern Vector2D camPos;

extern ASurface surface;

extern enum Gamestates;
extern int Gamestate;
extern int nextGamestate;
