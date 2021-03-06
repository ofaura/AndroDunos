#ifndef __MODULEINTRONEOGEO_H__
#define __MODULEINTRONEOGEO_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleIntroNeoGeo : public Module
{
public:
	ModuleIntroNeoGeo();
	~ModuleIntroNeoGeo();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	
	SDL_Texture* graphics = nullptr;
	Animation NeoGeo;
	Animation* current_animation = nullptr;

};

#endif // __MODULEINTRONEOGEO_H__