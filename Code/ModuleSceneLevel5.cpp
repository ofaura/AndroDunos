#include "Globals.h"
#include "Application.h"
#include "ModuleSceneLevel5.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleBonus.h"
#include "ModuleAudio.h"
#include "ModuleCollision.h"
#include "ModuleEnemies.h"
#include "ModuleParticles.h"
#include "ModuleUserInterface.h"
#include "ModuleShield.h"

ModuleSceneLevel5::ModuleSceneLevel5()
{
	// Background 
	background.x = 10;
	background.y = 0;
	background.w = 3970;
	background.h = 199;

	ground.x = 0;
	ground.y = 0;
	ground.w = 9305;
	ground.h = 563;
}

ModuleSceneLevel5::~ModuleSceneLevel5()
{}

// Load assets
bool ModuleSceneLevel5::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	//Textures are loaded
	background_texture = App->textures->Load("Assets/Sprites/lvl5/background5.png");

	//Audios are loaded
	small_enemy_death = App->audio->LoadFx("Assets/Audio/Sound FX/enemy_small_explosion.wav");

	if (IsEnabled()) {
		if (App->player->IsEnabled() == false) {
			App->player->Enable();
		}
	}
	if (IsEnabled() == false) {
		if (App->player->IsEnabled() == true) {
			App->player->Disable();
		}
	}

	App->user_interface->Enable();

	// Reseting the camera to the start of the level
	App->render->camera.x = App->render->camera.y = 0;
	App->render->camera.w = SCREEN_WIDTH;
	App->render->camera.h = SCREEN_HEIGHT;

	//Enemies ---
	App->enemies->Enable();

	App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_POWERUP, 300, (SCREEN_HEIGHT / 2) - 20);

	App->enemies->AddEnemy(ENEMY_TYPES::FIRST_ENEMY, 200, 60);
	App->enemies->AddEnemy(ENEMY_TYPES::FIRST_ENEMY, 215, 60);
	App->enemies->AddEnemy(ENEMY_TYPES::FIRST_ENEMY, 230, 60);
	App->enemies->AddEnemy(ENEMY_TYPES::FIRST_ENEMY, 245, 60);

	// Colliders ----
	App->collision->Enable();

	//Audio ---
	App->audio->PlayMusic("Assets/Audio/Music/level5.ogg", 1.0f);

	return ret;
}

// Update: draw background
update_status ModuleSceneLevel5::Update()
{
<<<<<<< HEAD
	
=======
>>>>>>> 2bb85505c93c8286273ff1e3e264233abb329404
	if (App->render->camera.x >= 0 && App->render->camera.x <= 8800 * SCREEN_SIZE)
	{

		App->render->camera.x += 1 * SCREEN_SIZE;

		App->player->position.x += 1;

		App->player2->position.x += 1;
	}

<<<<<<< HEAD
	App->render->Blit(background_texture, (background_pos_x) / 3.5, background_pos_y, &background, 1.0f, true);
=======
	App->render->Blit(background_texture, (background_pos_x) / 3.5, background_pos_y, &background, 0.5f, true);
>>>>>>> 2bb85505c93c8286273ff1e3e264233abb329404

	return UPDATE_CONTINUE;
}

// Load assets
bool ModuleSceneLevel5::CleanUp()
{
	// Remove all memory leaks
	LOG("Unloading textures");
	App->audio->UnLoadFx(small_enemy_death);
	App->textures->Unload(background_texture);

	App->collision->CleanUp();

	App->user_interface->Disable();
	App->enemies->Disable();
	App->collision->Disable();
	App->player->Disable();
	App->shield->Disable();

	if (App->player2->IsEnabled() == true)
		App->player2->Disable();

	return true;
}