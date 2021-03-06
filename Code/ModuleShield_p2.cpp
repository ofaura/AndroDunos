#include <math.h>
#include "p2Point.h"
#include "Globals.h"
#include "Application.h"
#include "ModuleShield_p2.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleParticles.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModuleShield.h"

#define RADIUS (27)

int give_position_y_(int radius, float angle_deg) // preparations for later
{
	int center_y = 0; // to be determined

	float rad = ((angle_deg * PI) / 180);

	return radius * sinf(rad)*(-1) + center_y;

}
int give_position_x_(int radius, float angle_deg) // preparations for later
{
	int center_x = 5; // to be determined

	float rad = ((angle_deg * PI) / 180);

	return radius * cosf(rad)*(1) + center_x;
}


ModuleShield_p2::ModuleShield_p2() {

	circ = 0;

	// ---- Animation for the base od the shield
	base_anim.PushBack({ 0, 0, 9, 16 });
	base_anim.PushBack({ 11, 0, 9, 16 });
	base_anim.PushBack({ 22, 0, 9, 16 });
	base_anim.PushBack({ 33, 0, 9, 16 });
	base_anim.PushBack({ 44, 0, 9, 16 });
	base_anim.PushBack({ 55, 0, 9, 16 });
	base_anim.loop = true;
	base_anim.speed = 0.2f;

	// ---- Animation for lvl1 LaserShield (Red)
	lvl1.PushBack({ 46, 18, 5, 14 });
	lvl1.PushBack({ 0, 18, 5, 14 });
	lvl1.PushBack({ 7, 18, 5, 14 });
	lvl1.PushBack({ 0, 18, 5, 14 });
	lvl1.loop = true;
	lvl1.speed = 0.5f;

	// ---- Animation for the TYPE-1 laser's shield (rotating)
	rotation_lvl1[0].PushBack({ 0,0,9,16 });
	rotation_lvl1[0].PushBack({ 11,0,9,16 });
	rotation_lvl1[0].PushBack({ 22,0,9,16 });
	rotation_lvl1[0].PushBack({ 33,0,9,16 });
	rotation_lvl1[0].PushBack({ 44,0,9,16 });
	rotation_lvl1[0].PushBack({ 57,0,9,16 });
	rotation_lvl1[0].loop = true;
	rotation_lvl1[0].speed = 0.25f;

	rotation_lvl1[1].PushBack({ 128,16,9,16 });
	rotation_lvl1[1].PushBack({ 117,16,9,16 });
	rotation_lvl1[1].PushBack({ 106,16,9,16 });
	rotation_lvl1[1].PushBack({ 95,16,9,16 });
	rotation_lvl1[1].PushBack({ 84,16,9,16 });
	rotation_lvl1[1].PushBack({ 72,16,9,16 });
	rotation_lvl1[1].loop = true;
	rotation_lvl1[1].speed = 0.25f;

	rotation_lvl1[2].PushBack({ 109,52,14,16 });
	rotation_lvl1[2].PushBack({ 109,75,15,14 });
	rotation_lvl1[2].PushBack({ 109,98,14,16 });
	rotation_lvl1[2].PushBack({ 107,16,16,15 });
	rotation_lvl1[2].loop = true;
	rotation_lvl1[2].speed = 0.25f;

	rotation_lvl1[3].PushBack({ 87,50,14,16 });
	rotation_lvl1[3].PushBack({ 84,73,15,14 });
	rotation_lvl1[3].PushBack({ 86,95,14,16 });
	rotation_lvl1[3].PushBack({ 86,117,16,15 });
	rotation_lvl1[3].loop = true;
	rotation_lvl1[3].speed = 0.25f;

	rotation_lvl1[4].PushBack({ 56,45,9,16 });
	rotation_lvl1[4].PushBack({ 56,56,9,16 });
	rotation_lvl1[4].PushBack({ 56,67,9,16 });
	rotation_lvl1[4].PushBack({ 56,78,9,16 });
	rotation_lvl1[4].PushBack({ 56,89,9,16 });
	rotation_lvl1[4].PushBack({ 56,102,9,16 });
	rotation_lvl1[4].loop = true;
	rotation_lvl1[4].speed = 0.25f;

	rotation_lvl1[5].PushBack({ 3,98,16,9 });
	rotation_lvl1[5].PushBack({ 3,87,16,9 });
	rotation_lvl1[5].PushBack({ 3,76,16,9 });
	rotation_lvl1[5].PushBack({ 3,67,16,9 });
	rotation_lvl1[5].PushBack({ 3,54,16,9 });
	rotation_lvl1[5].PushBack({ 3,42,16,9 });
	rotation_lvl1[5].loop = true;
	rotation_lvl1[5].speed = 0.25f;

	rotation_lvl1[6].PushBack({ 109,52,14,16 });
	rotation_lvl1[6].PushBack({ 109,75,15,14 });
	rotation_lvl1[6].PushBack({ 109,98,14,16 });
	rotation_lvl1[6].PushBack({ 107,16,16,15 });
	rotation_lvl1[6].loop = true;
	rotation_lvl1[6].speed = 0.25f;

	rotation_lvl1[7].PushBack({ 87,50,14,16 });
	rotation_lvl1[7].PushBack({ 84,73,15,14 });
	rotation_lvl1[7].PushBack({ 86,95,14,16 });
	rotation_lvl1[7].PushBack({ 86,117,16,15 });
	rotation_lvl1[7].loop = true;
	rotation_lvl1[7].speed = 0.25f;

	for (int counter = 0; counter < ROT_STEPS; counter++)
	{
		rotation_level[counter] = rotation_lvl1[counter];
	}

}

ModuleShield_p2::~ModuleShield_p2() {}

bool ModuleShield_p2::Start() {
	bool ret = true;

	graphics = App->textures->Load("Assets/Sprites/player/shield.png"); //Loads shield image bank

	if (graphics == nullptr) ret = false; //failsafe for wrong address

	timer = 0;

	switch (App->player2->type) {

		// ---- Stays in front of ship
	case bullet_type::TYPE_1:

		//give_position_x(radius, deg);
		//give_position_x(radius, deg);

		pos1_t1_[0].x = App->player2->position.x + give_position_x_(RADIUS, 0.0);
		pos1_t1_[0].y = App->player2->position.y + give_position_y_(RADIUS, 0.0);
		pos2_t1_[0].x = App->player2->position.x + give_position_x_(RADIUS, 180.0);
		pos2_t1_[0].y = App->player2->position.y + give_position_y_(RADIUS, 180.0);

		position1_.x = pos1_t1_[0].x;
		position1_.y = pos1_t1_[0].y;
		position2_.x = pos2_t1_[0].x;
		position2_.y = pos2_t1_[0].y;

		break;

		// ---- Stays on either side of the ship
	case bullet_type::TYPE_2:
		position1_.x = App->player2->position.x + 5;
		position1_.y = App->player2->position.y - 8;
		position2_.x = App->player2->position.x + 5;
		position2_.y = App->player2->position.y + 10;
		break;

		// ---- Stays in front of ship
	case bullet_type::TYPE_3:
		position1_.x = App->player2->position.x + 29;
		position1_.y = App->player2->position.y - 8;
		position2_.x = App->player2->position.x + 29;
		position2_.y = App->player2->position.y + 10;
		break;

		// ---- Stays behind ship
	case bullet_type::TYPE_4:
		position1_.x = App->player2->position.x + 29;
		position1_.y = App->player2->position.y - 8;
		position2_.x = App->player2->position.x + 29;
		position2_.y = App->player2->position.y + 10;
		break;
	}


	// ---- Declares colliders for shield parts individually
	collider1 = App->collision->AddCollider({ position1_.x, position1_.y, 14, 16 }, COLLIDER_SHIELD_2, this);
	collider2 = App->collision->AddCollider({ position2_.x, position2_.y, 14, 16 }, COLLIDER_SHIELD_2, this);


	return ret;
}

update_status ModuleShield_p2::Update() {

	/*if (life == 1) current_lvl = &lvl1;
	else if (life == 2)	current_lvl = &lvl2;
	else if (life == 3)	current_lvl = &lvl3;
	*/
	current_lvl = &lvl1;

	// ---- Keeps realtive position to the ship
	switch (App->player2->type) {

		// ---- Stays in front of ship
	case bullet_type::TYPE_1:

		pos1_t1_[0].x = App->player2->position.x + give_position_x_(RADIUS, 0.0);
		pos1_t1_[0].y = App->player2->position.y + give_position_y_(RADIUS, 0.0);
		pos2_t1_[0].x = App->player2->position.x + give_position_x_(RADIUS, 180.0);
		pos2_t1_[0].y = App->player2->position.y + give_position_y_(RADIUS, 180.0);

		pos1_t1_[1].x = App->player2->position.x + give_position_x_(RADIUS, 90 + 67.5);
		pos1_t1_[1].y = App->player2->position.y + give_position_y_(RADIUS, 90 + 67.5);
		pos2_t1_[1].x = App->player2->position.x + give_position_x_(RADIUS, 270 + 67.5);
		pos2_t1_[1].y = App->player2->position.y + give_position_y_(RADIUS, 270 + 67.5);

		pos1_t1_[2].x = App->player2->position.x + give_position_x_(RADIUS, 90 + 45.0);
		pos1_t1_[2].y = App->player2->position.y + give_position_y_(RADIUS, 90 + 45.0);
		pos2_t1_[2].x = App->player2->position.x + give_position_x_(RADIUS, 270 + 45.0);
		pos2_t1_[2].y = App->player2->position.y + give_position_y_(RADIUS, 270 + 45.0);

		pos1_t1_[3].x = App->player2->position.x + give_position_x_(RADIUS, 90 + 22.5);
		pos1_t1_[3].y = App->player2->position.y + give_position_y_(RADIUS, 90 + 22.5);
		pos2_t1_[3].x = App->player2->position.x + give_position_x_(RADIUS, 270 + 22.5);
		pos2_t1_[3].y = App->player2->position.y + give_position_y_(RADIUS, 270 + 22.5);

		pos1_t1_[4].x = App->player2->position.x + give_position_x_(RADIUS, 90.0);
		pos1_t1_[4].y = App->player2->position.y + give_position_y_(RADIUS, 90.0);
		pos2_t1_[4].x = App->player2->position.x + give_position_x_(RADIUS, 270.0);
		pos2_t1_[4].y = App->player2->position.y + give_position_y_(RADIUS, 270.0);

		pos1_t1_[5].x = App->player2->position.x + give_position_x_(RADIUS, 67.5);
		pos1_t1_[5].y = App->player2->position.y + give_position_y_(RADIUS, 67.5);
		pos2_t1_[5].x = App->player2->position.x + give_position_x_(RADIUS, 180.0 + 67.5);
		pos2_t1_[5].y = App->player2->position.y + give_position_y_(RADIUS, 180.0 + 67.5);

		pos1_t1_[6].x = App->player2->position.x + give_position_x_(RADIUS, 45.0);
		pos1_t1_[6].y = App->player2->position.y + give_position_y_(RADIUS, 45.0);
		pos2_t1_[6].x = App->player2->position.x + give_position_x_(RADIUS, 180 + 45.0);
		pos2_t1_[6].y = App->player2->position.y + give_position_y_(RADIUS, 180.0 + 45.0);

		pos1_t1_[7].x = App->player2->position.x + give_position_x_(RADIUS, 22.5);
		pos1_t1_[7].y = App->player2->position.y + give_position_y_(RADIUS, 22.5);
		pos2_t1_[7].x = App->player2->position.x + give_position_x_(RADIUS, 180.0 + 22.5);
		pos2_t1_[7].y = App->player2->position.y + give_position_y_(RADIUS, 180.0 + 22.5);

		position1_.x = pos1_t1_[circ].x;
		position1_.y = pos1_t1_[circ].y;
		position2_.x = pos2_t1_[circ].x;
		position2_.y = pos2_t1_[circ].y;
		break;

		// ---- Stays on either side of the ship
	case bullet_type::TYPE_2:
		position1_.x = App->player2->position.x + 5;
		position1_.y = App->player2->position.y - 15;
		position2_.x = App->player2->position.x + 5;
		position2_.y = App->player2->position.y + 17;
		break;

		// ---- Stays in front of ship
	case bullet_type::TYPE_3:
		position1_.x = App->player2->position.x + 29;
		position1_.y = App->player2->position.y - 8;
		position2_.x = App->player2->position.x + 29;
		position2_.y = App->player2->position.y + 10;
		break;

		// ---- Stays behind ship
	case bullet_type::TYPE_4:
		position1_.x = App->player2->position.x - 16;
		position1_.y = App->player2->position.y - 8;
		position2_.x = App->player2->position.x - 16;
		position2_.y = App->player2->position.y + 10;
		break;
	}

	// ---- Updates colliders
	collider1->SetPos(position1_.x, position1_.y);
	collider2->SetPos(position2_.x, position2_.y);

	SDL_Rect base = base_anim.GetCurrentFrame();
	SDL_Rect light = current_lvl->GetCurrentFrame();

	timer++;

	// ---- Draw Everything
	if (App->player2->type == bullet_type::TYPE_1)
	{
		App->render->Blit(graphics, position1_.x, position1_.y, &rotation_level[0].GetCurrentFrame());
		App->render->Blit(graphics, position2_.x, position2_.y, &rotation_level[1].GetCurrentFrame());

		if (timer >= 3)
		{
			circ++;
			timer = 0;
		}

		if (circ > 7)
		{
			circ = 0;
		}
	}

	else
	{
		App->render->Blit(graphics, position1_.x, position1_.y, &base);
		App->render->Blit(graphics, position2_.x, position2_.y, &base);
		App->render->Blit(graphics, position1_.x + 8, position1_.y + 1, &light);
		App->render->Blit(graphics, position2_.x + 8, position2_.y + 1, &light);
	}

	return update_status::UPDATE_CONTINUE;
}

void ModuleShield_p2::OnCollision(Collider* col_1, Collider* col_2) {
	if (collider1 == col_1 || collider2 == col_1)
		if (IsEnabled())
		{
			App->player2->Shield2--;

			if (App->player2->Shield2 == 0)
			{
				circ = 0;
				collider1->to_delete = true;
				collider2->to_delete = true;
				collider1 = nullptr;
				collider2 = nullptr;
				Disable();
			}

		}

}

bool ModuleShield_p2::CleanUp() {

	// Remove all memory leaks
	LOG("Unloading shield");
	App->textures->Unload(graphics);

	//Get rid of colliders;
	collider1 = nullptr;
	collider2 = nullptr;

	return true;
}