#include "Application.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"

ModuleCollision::ModuleCollision()
{
	matrix[COLLIDER_WALL][COLLIDER_WALL] = false;
	matrix[COLLIDER_WALL][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_WALL][COLLIDER_PLAYER_2] = true;
	matrix[COLLIDER_WALL][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_WALL][COLLIDER_PLAYER_SHOT] = true;
	matrix[COLLIDER_WALL][COLLIDER_PLAYER_SHOT_ALT] = true;
	matrix[COLLIDER_WALL][COLLIDER_PLAYER2_SHOT] = true;
	matrix[COLLIDER_WALL][COLLIDER_PLAYER2_SHOT_ALT] = true;
	matrix[COLLIDER_WALL][COLLIDER_ENEMY_SHOT] = true;
	matrix[COLLIDER_WALL][COLLIDER_POWER_UP] = true;
	matrix[COLLIDER_WALL][COLLIDER_SHIELD_1] = false;
	matrix[COLLIDER_WALL][COLLIDER_SHIELD_2] = false;
	matrix[COLLIDER_WALL][COLLIDER_NONE] = false;
	matrix[COLLIDER_WALL][COLLIDER_NONE_PLAYER_2] = false;
	matrix[COLLIDER_WALL][COLLIDER_ULTIMATES] = true;
	matrix[COLLIDER_WALL][COLLIDER_ULTIMATES_P2] = true;

	matrix[COLLIDER_PLAYER][COLLIDER_WALL] = true;
	matrix[COLLIDER_PLAYER][COLLIDER_PLAYER] = false;
	matrix[COLLIDER_PLAYER][COLLIDER_PLAYER_2] = true;
	matrix[COLLIDER_PLAYER][COLLIDER_ENEMY] = true;
	matrix[COLLIDER_PLAYER][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_PLAYER][COLLIDER_PLAYER_SHOT_ALT] = false;
	matrix[COLLIDER_PLAYER][COLLIDER_PLAYER2_SHOT] = false;
	matrix[COLLIDER_PLAYER][COLLIDER_PLAYER2_SHOT_ALT] = false;
	matrix[COLLIDER_PLAYER][COLLIDER_ENEMY_SHOT] = true;
	matrix[COLLIDER_PLAYER][COLLIDER_POWER_UP] = true;
	matrix[COLLIDER_PLAYER][COLLIDER_SHIELD_1] = false;
	matrix[COLLIDER_PLAYER][COLLIDER_SHIELD_2] = false;
	matrix[COLLIDER_PLAYER][COLLIDER_NONE] = false;
	matrix[COLLIDER_PLAYER][COLLIDER_NONE_PLAYER_2] = false;
	matrix[COLLIDER_PLAYER][COLLIDER_ULTIMATES] = false;
	matrix[COLLIDER_PLAYER][COLLIDER_ULTIMATES_P2] = false;

	matrix[COLLIDER_PLAYER_2][COLLIDER_WALL] = true;
	matrix[COLLIDER_PLAYER_2][COLLIDER_PLAYER] = false;
	matrix[COLLIDER_PLAYER_2][COLLIDER_PLAYER_2] = true;
	matrix[COLLIDER_PLAYER_2][COLLIDER_ENEMY] = true;
	matrix[COLLIDER_PLAYER_2][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_PLAYER_2][COLLIDER_PLAYER_SHOT_ALT] = false;
	matrix[COLLIDER_PLAYER_2][COLLIDER_PLAYER2_SHOT] = false;
	matrix[COLLIDER_PLAYER_2][COLLIDER_PLAYER2_SHOT_ALT] = false;
	matrix[COLLIDER_PLAYER_2][COLLIDER_ENEMY_SHOT] = true;
	matrix[COLLIDER_PLAYER_2][COLLIDER_POWER_UP] = true;
	matrix[COLLIDER_PLAYER_2][COLLIDER_SHIELD_1] = false;
	matrix[COLLIDER_PLAYER_2][COLLIDER_SHIELD_2] = false; 
	matrix[COLLIDER_PLAYER_2][COLLIDER_NONE] = false;
	matrix[COLLIDER_PLAYER_2][COLLIDER_NONE_PLAYER_2] = false;
	matrix[COLLIDER_PLAYER_2][COLLIDER_ULTIMATES] = false;
	matrix[COLLIDER_PLAYER_2][COLLIDER_ULTIMATES_P2] = false;

	matrix[COLLIDER_ENEMY][COLLIDER_WALL] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_ENEMY][COLLIDER_PLAYER_2] = true;
	matrix[COLLIDER_ENEMY][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_PLAYER_SHOT] = true;
	matrix[COLLIDER_ENEMY][COLLIDER_PLAYER_SHOT_ALT] = true;
	matrix[COLLIDER_ENEMY][COLLIDER_PLAYER2_SHOT] = true;
	matrix[COLLIDER_ENEMY][COLLIDER_PLAYER2_SHOT_ALT] = true;
	matrix[COLLIDER_ENEMY][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_POWER_UP] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_SHIELD_1] = true;
	matrix[COLLIDER_ENEMY][COLLIDER_SHIELD_2] = true;
	matrix[COLLIDER_ENEMY][COLLIDER_NONE] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_NONE_PLAYER_2] = false;
	matrix[COLLIDER_ENEMY][COLLIDER_ULTIMATES] = true;
	matrix[COLLIDER_ENEMY][COLLIDER_ULTIMATES_P2] = true;

	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_WALL] = true;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_PLAYER] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_PLAYER_2] = true;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_ENEMY] = true;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_PLAYER_SHOT_ALT] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_PLAYER2_SHOT] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_PLAYER2_SHOT_ALT] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_POWER_UP] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_SHIELD_1] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_SHIELD_2] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_NONE] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_NONE_PLAYER_2] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_ULTIMATES] = false;
	matrix[COLLIDER_PLAYER_SHOT][COLLIDER_ULTIMATES_P2] = false;

	matrix[COLLIDER_ULTIMATES][COLLIDER_WALL] = true;
	matrix[COLLIDER_ULTIMATES][COLLIDER_PLAYER] = false;
	matrix[COLLIDER_ULTIMATES][COLLIDER_PLAYER_2] = true;
	matrix[COLLIDER_ULTIMATES][COLLIDER_ENEMY] = true;
	matrix[COLLIDER_ULTIMATES][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_ULTIMATES][COLLIDER_PLAYER_SHOT_ALT] = false;
	matrix[COLLIDER_ULTIMATES][COLLIDER_PLAYER2_SHOT] = false;
	matrix[COLLIDER_ULTIMATES][COLLIDER_PLAYER2_SHOT_ALT] = false;
	matrix[COLLIDER_ULTIMATES][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_ULTIMATES][COLLIDER_POWER_UP] = false;
	matrix[COLLIDER_ULTIMATES][COLLIDER_SHIELD_1] = false;
	matrix[COLLIDER_ULTIMATES][COLLIDER_SHIELD_2] = false;
	matrix[COLLIDER_ULTIMATES][COLLIDER_NONE] = false;
	matrix[COLLIDER_ULTIMATES][COLLIDER_NONE_PLAYER_2] = false;
	matrix[COLLIDER_ULTIMATES][COLLIDER_ULTIMATES_P2] = false;
	matrix[COLLIDER_ULTIMATES][COLLIDER_ULTIMATES] = false;

	matrix[COLLIDER_ULTIMATES_P2][COLLIDER_WALL] = true;
	matrix[COLLIDER_ULTIMATES_P2][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_ULTIMATES_P2][COLLIDER_PLAYER_2] = false;
	matrix[COLLIDER_ULTIMATES_P2][COLLIDER_ENEMY] = true;
	matrix[COLLIDER_ULTIMATES_P2][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_ULTIMATES_P2][COLLIDER_PLAYER_SHOT_ALT] = false;
	matrix[COLLIDER_ULTIMATES_P2][COLLIDER_PLAYER2_SHOT] = false;
	matrix[COLLIDER_ULTIMATES_P2][COLLIDER_PLAYER2_SHOT_ALT] = false;
	matrix[COLLIDER_ULTIMATES_P2][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_ULTIMATES_P2][COLLIDER_POWER_UP] = false;
	matrix[COLLIDER_ULTIMATES_P2][COLLIDER_SHIELD_1] = false;
	matrix[COLLIDER_ULTIMATES_P2][COLLIDER_SHIELD_2] = false;
	matrix[COLLIDER_ULTIMATES_P2][COLLIDER_NONE] = false;
	matrix[COLLIDER_ULTIMATES_P2][COLLIDER_NONE_PLAYER_2] = false;
	matrix[COLLIDER_ULTIMATES_P2][COLLIDER_ULTIMATES_P2] = false;
	matrix[COLLIDER_ULTIMATES_P2][COLLIDER_ULTIMATES] = false;

	matrix[COLLIDER_PLAYER_SHOT_ALT][COLLIDER_WALL] = true;
	matrix[COLLIDER_PLAYER_SHOT_ALT][COLLIDER_PLAYER] = false;
	matrix[COLLIDER_PLAYER_SHOT_ALT][COLLIDER_PLAYER_2] = true;
	matrix[COLLIDER_PLAYER_SHOT_ALT][COLLIDER_ENEMY] = true;
	matrix[COLLIDER_PLAYER_SHOT_ALT][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_PLAYER_SHOT_ALT][COLLIDER_PLAYER_SHOT_ALT] = false;
	matrix[COLLIDER_PLAYER_SHOT_ALT][COLLIDER_PLAYER2_SHOT] = false;
	matrix[COLLIDER_PLAYER_SHOT_ALT][COLLIDER_PLAYER2_SHOT_ALT] = false;
	matrix[COLLIDER_PLAYER_SHOT_ALT][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_PLAYER_SHOT_ALT][COLLIDER_POWER_UP] = false;
	matrix[COLLIDER_PLAYER_SHOT_ALT][COLLIDER_SHIELD_1] = false;
	matrix[COLLIDER_PLAYER_SHOT_ALT][COLLIDER_SHIELD_2] = false;
	matrix[COLLIDER_PLAYER_SHOT_ALT][COLLIDER_NONE] = false;
	matrix[COLLIDER_PLAYER_SHOT_ALT][COLLIDER_NONE_PLAYER_2] = false;
	matrix[COLLIDER_PLAYER_SHOT_ALT][COLLIDER_ULTIMATES_P2] = false;
	matrix[COLLIDER_PLAYER_SHOT_ALT][COLLIDER_ULTIMATES] = false;

	matrix[COLLIDER_PLAYER2_SHOT][COLLIDER_WALL] = true;
	matrix[COLLIDER_PLAYER2_SHOT][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_PLAYER2_SHOT][COLLIDER_PLAYER_2] = false;
	matrix[COLLIDER_PLAYER2_SHOT][COLLIDER_ENEMY] = true;
	matrix[COLLIDER_PLAYER2_SHOT][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_PLAYER2_SHOT][COLLIDER_PLAYER_SHOT_ALT] = false;
	matrix[COLLIDER_PLAYER2_SHOT][COLLIDER_PLAYER2_SHOT] = false;
	matrix[COLLIDER_PLAYER2_SHOT][COLLIDER_PLAYER2_SHOT_ALT] = false;
	matrix[COLLIDER_PLAYER2_SHOT][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_PLAYER2_SHOT][COLLIDER_POWER_UP] = false;
	matrix[COLLIDER_PLAYER2_SHOT][COLLIDER_SHIELD_1] = false;
	matrix[COLLIDER_PLAYER2_SHOT][COLLIDER_SHIELD_2] = false;
	matrix[COLLIDER_PLAYER2_SHOT][COLLIDER_NONE] = false;
	matrix[COLLIDER_PLAYER2_SHOT][COLLIDER_NONE_PLAYER_2] = false;
	matrix[COLLIDER_PLAYER2_SHOT][COLLIDER_ULTIMATES_P2] = false;
	matrix[COLLIDER_PLAYER2_SHOT][COLLIDER_ULTIMATES] = false;

	matrix[COLLIDER_PLAYER2_SHOT_ALT][COLLIDER_WALL] = true;
	matrix[COLLIDER_PLAYER2_SHOT_ALT][COLLIDER_PLAYER] = false;
	matrix[COLLIDER_PLAYER2_SHOT_ALT][COLLIDER_PLAYER_2] = true;
	matrix[COLLIDER_PLAYER2_SHOT_ALT][COLLIDER_ENEMY] = true;
	matrix[COLLIDER_PLAYER2_SHOT_ALT][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_PLAYER2_SHOT_ALT][COLLIDER_PLAYER_SHOT_ALT] = false;
	matrix[COLLIDER_PLAYER2_SHOT_ALT][COLLIDER_PLAYER2_SHOT] = false;
	matrix[COLLIDER_PLAYER2_SHOT_ALT][COLLIDER_PLAYER2_SHOT_ALT] = false;
	matrix[COLLIDER_PLAYER2_SHOT_ALT][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_PLAYER2_SHOT_ALT][COLLIDER_POWER_UP] = false;
	matrix[COLLIDER_PLAYER2_SHOT_ALT][COLLIDER_SHIELD_1] = false;
	matrix[COLLIDER_PLAYER2_SHOT_ALT][COLLIDER_SHIELD_2] = false;
	matrix[COLLIDER_PLAYER2_SHOT_ALT][COLLIDER_NONE] = false;
	matrix[COLLIDER_PLAYER2_SHOT_ALT][COLLIDER_NONE_PLAYER_2] = false;
	matrix[COLLIDER_PLAYER2_SHOT_ALT][COLLIDER_ULTIMATES_P2] = false;
	matrix[COLLIDER_PLAYER2_SHOT_ALT][COLLIDER_ULTIMATES] = false;

	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_WALL] = true;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_PLAYER_2] = true;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_PLAYER_SHOT_ALT] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_PLAYER2_SHOT] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_PLAYER2_SHOT_ALT] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_POWER_UP] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_SHIELD_1] = true;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_SHIELD_2] = true;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_NONE] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_NONE_PLAYER_2] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_ULTIMATES_P2] = false;
	matrix[COLLIDER_ENEMY_SHOT][COLLIDER_ULTIMATES] = false;

	matrix[COLLIDER_POWER_UP][COLLIDER_WALL] = false;
	matrix[COLLIDER_POWER_UP][COLLIDER_PLAYER] = true;
	matrix[COLLIDER_POWER_UP][COLLIDER_PLAYER_2] = true;
	matrix[COLLIDER_POWER_UP][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_POWER_UP][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_POWER_UP][COLLIDER_PLAYER_SHOT_ALT] = false;
	matrix[COLLIDER_POWER_UP][COLLIDER_PLAYER2_SHOT] = false;
	matrix[COLLIDER_POWER_UP][COLLIDER_PLAYER2_SHOT_ALT] = false;
	matrix[COLLIDER_POWER_UP][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_POWER_UP][COLLIDER_POWER_UP] = false;
	matrix[COLLIDER_POWER_UP][COLLIDER_SHIELD_1] = false;
	matrix[COLLIDER_POWER_UP][COLLIDER_SHIELD_2] = false;
	matrix[COLLIDER_POWER_UP][COLLIDER_NONE] = true;//
	matrix[COLLIDER_POWER_UP][COLLIDER_NONE_PLAYER_2] = true;
	matrix[COLLIDER_POWER_UP][COLLIDER_ULTIMATES_P2] = false;
	matrix[COLLIDER_POWER_UP][COLLIDER_ULTIMATES] = false;

	matrix[COLLIDER_SHIELD_1][COLLIDER_WALL] = false;
	matrix[COLLIDER_SHIELD_1][COLLIDER_PLAYER_2] = false;
	matrix[COLLIDER_SHIELD_1][COLLIDER_ENEMY] = true;
	matrix[COLLIDER_SHIELD_1][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_SHIELD_1][COLLIDER_PLAYER_SHOT_ALT] = false;
	matrix[COLLIDER_SHIELD_1][COLLIDER_PLAYER2_SHOT] = false;
	matrix[COLLIDER_SHIELD_1][COLLIDER_PLAYER2_SHOT_ALT] = false;
	matrix[COLLIDER_SHIELD_1][COLLIDER_ENEMY_SHOT] = true;
	matrix[COLLIDER_SHIELD_1][COLLIDER_POWER_UP] = false;
	matrix[COLLIDER_SHIELD_1][COLLIDER_SHIELD_1] = false;
	matrix[COLLIDER_SHIELD_1][COLLIDER_SHIELD_2] = false;
	matrix[COLLIDER_SHIELD_1][COLLIDER_NONE] = false;
	matrix[COLLIDER_SHIELD_1][COLLIDER_NONE_PLAYER_2] = false;
	matrix[COLLIDER_SHIELD_1][COLLIDER_ULTIMATES_P2] = false;
	matrix[COLLIDER_SHIELD_1][COLLIDER_ULTIMATES] = false;

	matrix[COLLIDER_SHIELD_2][COLLIDER_WALL] = false;
	matrix[COLLIDER_SHIELD_2][COLLIDER_PLAYER_2] = false;
	matrix[COLLIDER_SHIELD_2][COLLIDER_ENEMY] = true;
	matrix[COLLIDER_SHIELD_2][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_SHIELD_2][COLLIDER_PLAYER_SHOT_ALT] = false;
	matrix[COLLIDER_SHIELD_2][COLLIDER_PLAYER2_SHOT] = false;
	matrix[COLLIDER_SHIELD_2][COLLIDER_PLAYER2_SHOT_ALT] = false;
	matrix[COLLIDER_SHIELD_2][COLLIDER_ENEMY_SHOT] = true;
	matrix[COLLIDER_SHIELD_2][COLLIDER_POWER_UP] = false;
	matrix[COLLIDER_SHIELD_2][COLLIDER_SHIELD_1] = false;
	matrix[COLLIDER_SHIELD_2][COLLIDER_SHIELD_2] = false;
	matrix[COLLIDER_SHIELD_2][COLLIDER_NONE] = false;
	matrix[COLLIDER_SHIELD_2][COLLIDER_NONE_PLAYER_2] = false;
	matrix[COLLIDER_SHIELD_2][COLLIDER_ULTIMATES_P2] = false;
	matrix[COLLIDER_SHIELD_2][COLLIDER_ULTIMATES] = false;

	matrix[COLLIDER_NONE][COLLIDER_WALL] = false;
	matrix[COLLIDER_NONE][COLLIDER_PLAYER_2] = false;
	matrix[COLLIDER_NONE][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_NONE][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_NONE][COLLIDER_PLAYER_SHOT_ALT] = false;
	matrix[COLLIDER_NONE][COLLIDER_PLAYER2_SHOT] = false;
	matrix[COLLIDER_NONE][COLLIDER_PLAYER2_SHOT_ALT] = false;
	matrix[COLLIDER_NONE][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_NONE][COLLIDER_POWER_UP] = true; 
	matrix[COLLIDER_NONE][COLLIDER_SHIELD_1] = false;
	matrix[COLLIDER_NONE][COLLIDER_SHIELD_2] = false;
	matrix[COLLIDER_NONE][COLLIDER_NONE] = false;
	matrix[COLLIDER_NONE][COLLIDER_NONE_PLAYER_2] = false;
	matrix[COLLIDER_NONE][COLLIDER_ULTIMATES_P2] = false;
	matrix[COLLIDER_NONE][COLLIDER_ULTIMATES] = false;

	matrix[COLLIDER_NONE_PLAYER_2][COLLIDER_WALL] = false;
	matrix[COLLIDER_NONE_PLAYER_2][COLLIDER_PLAYER_2] = false;
	matrix[COLLIDER_NONE_PLAYER_2][COLLIDER_ENEMY] = false;
	matrix[COLLIDER_NONE_PLAYER_2][COLLIDER_PLAYER_SHOT] = false;
	matrix[COLLIDER_NONE_PLAYER_2][COLLIDER_PLAYER_SHOT_ALT] = false;
	matrix[COLLIDER_NONE_PLAYER_2][COLLIDER_PLAYER2_SHOT] = false;
	matrix[COLLIDER_NONE_PLAYER_2][COLLIDER_PLAYER2_SHOT_ALT] = false;
	matrix[COLLIDER_NONE_PLAYER_2][COLLIDER_ENEMY_SHOT] = false;
	matrix[COLLIDER_NONE_PLAYER_2][COLLIDER_POWER_UP] = true; //
	matrix[COLLIDER_NONE_PLAYER_2][COLLIDER_SHIELD_1] = false;
	matrix[COLLIDER_NONE_PLAYER_2][COLLIDER_SHIELD_2] = false;
	matrix[COLLIDER_NONE_PLAYER_2][COLLIDER_NONE] = false;
	matrix[COLLIDER_NONE_PLAYER_2][COLLIDER_NONE_PLAYER_2] = false;
	matrix[COLLIDER_NONE_PLAYER_2][COLLIDER_ULTIMATES_P2] = false;
	matrix[COLLIDER_NONE_PLAYER_2][COLLIDER_ULTIMATES] = false;

}

// Destructor
ModuleCollision::~ModuleCollision()
{}

update_status ModuleCollision::PreUpdate()
{
	// Remove all colliders scheduled for deletion
	for (uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if (colliders[i] != nullptr && colliders[i]->to_delete == true)
		{
			delete colliders[i];
			colliders[i] = nullptr;
		}
	}

	// Collision detection and callbacks 
	Collider* c1;
	Collider* c2;

	for (uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		// skip empty colliders
		if (colliders[i] == nullptr)
			continue;

		c1 = colliders[i];

		// avoid checking collisions already checked
		for (uint k = i + 1; k < MAX_COLLIDERS; ++k)
		{
			// skip empty colliders
			if (colliders[k] == nullptr)
				continue;

			c2 = colliders[k];

			if (c1->CheckCollision(c2->rect) == true)
			{

				if (matrix[c1->type][c2->type] && c1->callback)
					c1->callback->OnCollision(c1, c2);

				if (matrix[c2->type][c1->type] && c2->callback)
					c2->callback->OnCollision(c2, c1);

			}
		}
	}


	return UPDATE_CONTINUE;
}

// Called before render is available
update_status ModuleCollision::Update()
{
	if (App->input->keyboard[SDL_SCANCODE_F1] == KEY_DOWN)
		debug = !debug;

	if (debug == false)
		return UPDATE_CONTINUE;

	Uint8 alpha = 80;
	for (uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if (colliders[i] == nullptr)
			continue;

		switch (colliders[i]->type)
		{
		case COLLIDER_NONE: // white
			App->render->DrawQuad(colliders[i]->rect, 255, 255, 255, alpha);
			break;
		case COLLIDER_NONE_PLAYER_2:
			App->render->DrawQuad(colliders[i]->rect, 255, 255, 255, alpha);
			break;
		case COLLIDER_WALL: // blue
			App->render->DrawQuad(colliders[i]->rect, 0, 0, 255, alpha);
			break;
		case COLLIDER_PLAYER: // green
			App->render->DrawQuad(colliders[i]->rect, 0, 255, 0, alpha);
			break;
		case COLLIDER_PLAYER_2: // green
			App->render->DrawQuad(colliders[i]->rect, 0, 255, 0, alpha);
			break;
		case COLLIDER_ENEMY: // red
			App->render->DrawQuad(colliders[i]->rect, 255, 0, 0, alpha);
			break;
		case COLLIDER_PLAYER_SHOT: // yellow
			App->render->DrawQuad(colliders[i]->rect, 255, 255, 0, alpha);
			break;
		case COLLIDER_PLAYER_SHOT_ALT: // yellow
			App->render->DrawQuad(colliders[i]->rect, 255, 255, 0, alpha);
			break;
		case COLLIDER_PLAYER2_SHOT: // yellow
			App->render->DrawQuad(colliders[i]->rect, 255, 255, 0, alpha);
			break;
		case COLLIDER_PLAYER2_SHOT_ALT: // yellow
			App->render->DrawQuad(colliders[i]->rect, 255, 255, 0, alpha);
			break;
		case COLLIDER_ENEMY_SHOT: // magenta
			App->render->DrawQuad(colliders[i]->rect, 0, 255, 255, alpha);
			break;
		case COLLIDER_POWER_UP: // red, it "acts" as an enemy
			App->render->DrawQuad(colliders[i]->rect, 255, 0, 0, alpha);
			break;
		case COLLIDER_SHIELD_1: // white
			App->render->DrawQuad(colliders[i]->rect, 255, 255, 255, alpha);
			break;
		case COLLIDER_SHIELD_2: //white
			App->render->DrawQuad(colliders[i]->rect, 255, 255, 255, alpha);
			break;
		case COLLIDER_ULTIMATES: // yellow
			App->render->DrawQuad(colliders[i]->rect, 255, 255, 0, alpha);
			break;
		case COLLIDER_ULTIMATES_P2: // yellow
			App->render->DrawQuad(colliders[i]->rect, 255, 255, 0, alpha);
			break;
		}
	}

	return UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleCollision::CleanUp()
{
	LOG("Freeing all colliders");

	for (uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if (colliders[i] != nullptr)
		{
			delete colliders[i];
			colliders[i] = nullptr;
		}
	}

	return true;
}

Collider* ModuleCollision::AddCollider(SDL_Rect rect, COLLIDER_TYPE type, Module* callback)
{
	Collider* ret = nullptr;

	for (uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if (colliders[i] == nullptr)
		{
			ret = colliders[i] = new Collider(rect, type, callback);
			break;
		}
	}

	return ret;
}

// -----------------------------------------------------

bool Collider::CheckCollision(const SDL_Rect& r) const
{
	return (rect.x < r.x + r.w &&
		rect.x + rect.w > r.x &&
		rect.y < r.y + r.h &&
		rect.h + rect.y > r.y);
}