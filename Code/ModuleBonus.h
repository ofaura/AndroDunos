#ifndef __MODULEBONUS_H__
#define __MODULEBONUS_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleBonus : public Module
{
public:
	ModuleBonus();
	~ModuleBonus();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	uint joinedScore; // Score of both player 1 and 2

	int bonus_font = -1;
	int font_score = -1;
	int joined_score = -1;
	char joinedScore_text[10];

	SDL_Texture* graphics = nullptr;
	SDL_Texture* scoreRect = nullptr;
	SDL_Texture* background = nullptr;

	SDL_Rect scorePlayer;
	SDL_Rect bonusBackground;

	Animation bonus;
	Animation* current_animation = nullptr;
};

#endif // __MODULEBONUS_H__