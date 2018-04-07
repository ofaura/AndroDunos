#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleParticles.h"


ModulePlayer::ModulePlayer()
{
	position.x = 0;
	position.y = SCREEN_HEIGHT / 2;

	current_animation = NULL;

	idle.PushBack({ 94, 107, 27, 17 });


	up.PushBack({ 94, 107, 27, 17 });
	up.PushBack({ 94, 86, 27, 15 });
	up.PushBack({ 94, 66, 27, 15 });
	up.loop = false;
	up.speed = 0.1f;

	down.PushBack({ 94, 107, 27, 17 });
	down.PushBack({ 94, 130, 27, 16 });
	down.PushBack({ 94, 152, 27, 17 });
	down.loop = false;
	down.speed = 0.1f;

}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player textures");
	graphics = App->textures->Load("Assets/Sprites/player/ships.png"); // arcade version
	return true;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	int speed = 2;

	if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
	{
		position.x -= speed + 1;
	}

	if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
	{
		position.x += speed;
	}

	if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
	{
		position.y += speed;
		if (current_animation != &down)
		{
			down.Reset();
			current_animation = &down;
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT)
	{
		position.y -= speed;
		if (current_animation != &up)
		{
			up.Reset();
			current_animation = &up;
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
	{
		App->particles->AddParticle(App->particles->laser, position.x + 25, position.y + 3);
		App->particles->AddParticle(App->particles->laser, position.x + 25, position.y + 8);
	}

	if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_IDLE
		&& App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_IDLE)
		current_animation = &idle;

	if (position.x <= 0) position.x = 0;
	else if (position.x >= SCREEN_WIDTH - 27) position.x = SCREEN_WIDTH - 27;
	if (position.y <= 0) position.y = 0;
	else if (position.y >= SCREEN_HEIGHT - 17) position.y = SCREEN_HEIGHT - 17;

	// Draw everything --------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();

	App->render->Blit(graphics, position.x, position.y, &r, 1);
	
	return UPDATE_CONTINUE;
}
bool ModulePlayer::CleanUp()
{
	// TODO 5: Remove all memory leaks
	LOG("Unloading ship");
	App->textures->Unload(graphics);

	return true;
}