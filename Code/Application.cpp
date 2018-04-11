#include "Application.h"
#include "ModuleWindow.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleIntroNeoGeo.h"
#include "ModuleSceneLevel1.h"
#include "ModulePlayer.h"
#include "ModuleFadeToBlack.h"
#include "ModuleAudio.h"
#include "ModuleSceneLevel2.h"
#include "ModuleBonus.h"
#include "ModuleParticles.h"
#include "ModuleStartMenu.h"
#include "ModulePlayer2.h"
#include "ModuleCollision.h"

Application::Application()
{
	modules[0] = window = new ModuleWindow();
	modules[1] = render = new ModuleRender();
	modules[2] = input = new ModuleInput();
	modules[3] = textures = new ModuleTextures();
	modules[4] = level1 = new ModuleSceneLevel1();
	modules[5] = NeoGeo = new ModuleIntroNeoGeo();
	modules[6] = level2 = new ModuleSceneLevel2();
	modules[7] = start_menu = new ModuleStartMenu();
	modules[8] = particles = new ModuleParticles();
	modules[9] = audio = new ModuleAudio();
	modules[10] = player = new ModulePlayer();
	modules[11] = player2 = new ModulePlayer2();
	modules[12] = bonus = new ModuleBonus();
	modules[13] = fade =  new ModuleFadeToBlack();
	modules[14] = collision = new ModuleCollision();
}	

Application::~Application()
{
	for(int i = NUM_MODULES - 1; i >= 0; --i)
		delete modules[i];
}

bool Application::Init()
{
	bool ret = true;

	// Player will be enabled on the first update of a new scene
	player->Disable();
	player2->Disable();
	// Disable the map that you do not start with
	level1->Disable();
	level2->Disable();
	bonus->Disable();
	start_menu->Disable();
	

	for(int i = 0; i < NUM_MODULES && ret == true; ++i)
		ret = modules[i]->Init();

	for(int i = 0; i < NUM_MODULES && ret == true; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->Start() : true;

	return ret;
}

update_status Application::Update()
{
	update_status ret = UPDATE_CONTINUE;

	for(int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->PreUpdate() : UPDATE_CONTINUE;

	for(int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->Update() : UPDATE_CONTINUE;

	for(int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->PostUpdate() : UPDATE_CONTINUE;

	return ret;
}

bool Application::CleanUp()
{
	bool ret = true;

	for(int i = NUM_MODULES - 1; i >= 0 && ret == true; --i)
		ret = modules[i]->CleanUp();

	return ret;
}