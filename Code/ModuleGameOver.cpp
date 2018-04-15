#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleGameOver.h"
#include "ModuleFadeToBlack.h"
#include "ModuleStartMenu.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"

ModuleGameOver::ModuleGameOver()
{

	_background.x = 75;
	_background.y = 90;
	_background.w = SCREEN_WIDTH;
	_background.h = SCREEN_HEIGHT;

}

ModuleGameOver::~ModuleGameOver()
{}

// Load assets
bool ModuleGameOver::Start()
{
	LOG("Loading textures");
	App->audio->PlayMusic("Assets/Audio/gameOver.ogg", 1.0f);
	background = App->textures->Load("Assets/Sprites/GameOver/game_over.png");
	return true;
}

// UnLoad assets
bool ModuleGameOver::CleanUp()
{
	LOG("Unloading Neo Geo logo scene");
	App->textures->Unload(background);
	return true;
}

// Update: draw background
update_status ModuleGameOver::Update()
{
	// Draw everything --------------------------------------
	App->render->Blit(background, -14, 0, &_background, 0.75f); 

	if (App->input->keyboard[SDL_SCANCODE_RETURN] == 1)
	{
		App->fade->FadeToBlack(App->game_over, App->start_menu, 1.0f);
	}

	return UPDATE_CONTINUE;
}