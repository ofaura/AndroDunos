#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleEnemyBoss.h"
#include "ModulePlayer.h"
#include "ModuleFadeToBlack.h"
#include "ModuleStartMenu.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"
#include "ModuleEnemies.h"

ModuleEnemyBoss::ModuleEnemyBoss()
{
	//Meteorite
	upHalf.x = 226;
	upHalf.y = 93;
	upHalf.w = 84;
	upHalf.h = 107;

	downHalf.x = 323;
	downHalf.y = 84;
	downHalf.w = 86;
	downHalf.h = 111;

	//Structure
	core.x = 449;
	core.y = 81;
	core.w = 56;
	core.h = 128;

	lightTube.PushBack({ 87, 106, 45, 26 });
	lightTube.PushBack({ 87, 140, 45, 26 });
	lightTube.PushBack({ 87, 174, 45, 26 });
	lightTube.loop = true;
	lightTube.speed = 0.5f;
	
	//Hatchs
	openingHatchs.PushBack({ 32, 329, 22, 152 });
	openingHatchs.PushBack({ 60, 329, 22, 152 });
	openingHatchs.PushBack({ 88, 329, 22, 152 });
	openingHatchs.PushBack({ 115, 329, 22, 152 });
	openingHatchs.PushBack({ 141, 329, 22, 152 });
	openingHatchs.PushBack({ 1, 329, 22, 152 });
	openingHatchs.loop = false;
	openingHatchs.speed = 0.15f;

	closingHatchs.PushBack({ 1, 329, 22, 152 });
	closingHatchs.PushBack({ 141, 329, 22, 152 });
	closingHatchs.PushBack({ 115, 329, 22, 152 });
	closingHatchs.PushBack({ 88, 329, 22, 152 });
	closingHatchs.PushBack({ 60, 329, 22, 152 });
	closingHatchs.PushBack({ 32, 329, 22, 152 });
	closingHatchs.loop = false;
	closingHatchs.speed = 0.15f;
}

ModuleEnemyBoss::~ModuleEnemyBoss()
{}

// Load assets
bool ModuleEnemyBoss::Start()
{
	LOG("Loading music and textures");

	//Textures are loaded
	graphics = App->textures->Load("Assets/Sprites/Enemies/boss.png");

	//Audios are loaded
	boss_death = App->audio->LoadFx("Assets/Audio/Sound FX/boss_death.wav");

	App->audio->PlayMusic("Assets/Audio/Music/bossIntro.ogg", 0.0f); //Intro music

	currentTime = SDL_GetTicks();
	lastTime = currentTime;

	animationHatchs = &openingHatchs;

	//Initial position
	positionX_uh = 7395;
	positionY_uh = 30;

	return true;
}

// Update: draw background
update_status ModuleEnemyBoss::Update()
{
	currentTime = SDL_GetTicks();

	if (currentTime > lastTime + 9000 && musicPlayed == false)
	{
		App->audio->PlayMusic("Assets/Audio/Music/bossLoop.ogg", 0.0f); //Loop music
		musicPlayed = true;
	}

	if (currentTime > lastTime + 2000 && enemiesAdded == false) {
		App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_MINION, positionX_uh + 30, positionY_uh + 23);
		App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_MINION, positionX_uh + 100, positionY_uh + 23);
		App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_MINION, positionX_uh + 30, positionY_uh + 152);
		App->enemies->AddEnemy(ENEMY_TYPES::ENEMY_MINION, positionX_uh + 100, positionY_uh + 152);		
		enemiesAdded = true;
	}
	else if (currentTime > lastTime + 3000 &&enemiesAdded == true) {
		animationHatchs = &closingHatchs;
	}

	SDL_Rect hatchs = animationHatchs->GetCurrentFrame();

	// Draw everything --------------------------------------
	App->render->Blit(graphics, positionX_uh + 25, positionY_uh + 20, &hatchs, 1.0f, true);
	App->render->Blit(graphics, positionX_uh, positionY_uh, &upHalf, 1.0f, true);
	App->render->Blit(graphics, positionX_uh - 2, positionY_uh + 80, &downHalf, 1.0f, true);

	return UPDATE_CONTINUE;
}

// UnLoad assets
bool ModuleEnemyBoss::CleanUp()
{
	LOG("Unloading Neo Geo logo scene");
	App->audio->UnLoadFx(boss_death);
	App->textures->Unload(graphics);

	return true;
}