#pragma once

#include <SDL2/SDL_mixer.h>

#define FPS 60
#define SCREEN_WIDTH 64*3*7
#define SCREEN_HEIGHT 64*3*5

#define MapSize 64*3
#define HalfSize 32*3
#define BoosterSize 32
#define BoosterTime 300

#define GreyTeam 6

#define TroopsMax 1000
#define BoostersMax 5
#define StatesMax 35
#define MaxInState 50
#define ABS(a) a>0 ? a : -a
#define MAX(a,b) a > b ? a : b
#define MIN(a, b) a < b ? a : b



SDL_Window *sdlWindow ;
SDL_Renderer *sdlRenderer;
//Mix_Music* music; // ???

int id;
int totalStates;

struct Booster {
	int mode;
	int xPos;
	int yPos;
	int teamOnIt[6];
	int timeLimit;
};
struct OnlineBooster {
	int mode;
	int timer;
};
struct Troop {
	int team;
	struct State *attackTo;
	float xPos;
	float yPos;
	float Vx;
	float Vy;
	int xEnd;
	int yEnd;
	int boostedMode;
};

struct State {
	int team;
	int shape;
	int troops;
	int xArea;
	int yArea;
	int selected;
	int attackCount;
	struct State *attackTo;
	int boostedMode;
};
struct Player {
	int id;
	int rank;
	int playtime;
	char input[15];
};
