#include <math.h>
#include "p2Point.h"
#include "Globals.h"
#include "Application.h"
#include "ModuleShield.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleParticles.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"

#define RADIUS (27)

int give_position_y(int radius, float angle_deg) // preparations for later
{
	int center_y = 0; // to be determined

	float rad = ((angle_deg * PI) / 180);

	return radius * sinf(rad)*(-1) + center_y;

}
int give_position_x(int radius, float angle_deg) // preparations for later
{
	int center_x = 5; // to be determined

	float rad = ((angle_deg * PI) / 180);

	return radius * cosf(rad)*(1) + center_x;
}

ModuleShield::ModuleShield() {

	circ = 0;

	base_anim_2.PushBack({ 72, 16, 9, 16 });
	base_anim_2.PushBack({ 84, 16, 9, 16 });
	base_anim_2.PushBack({ 95, 16, 9, 16 });
	base_anim_2.PushBack({ 106, 16, 9, 16 });
	base_anim_2.PushBack({ 117, 16, 9, 16 });
	base_anim_2.PushBack({ 128, 16, 9, 16 });
	base_anim_2.loop = true;
	base_anim_2.speed = 0.2f;

	lvl1_behind.PushBack({ 124, 0, 6, 14 });
	lvl1_behind.PushBack({ 132, 0, 6, 14 });
	lvl1_behind.PushBack({ 124, 0, 6, 14 });
	lvl1_behind.PushBack({ 0, 45, 6, 14 });
	lvl1_behind.loop = true;
	lvl1_behind.speed = 0.5f;

	base_anim_3[0].PushBack({ 3, 42, 16, 9 });
	base_anim_3[0].PushBack({ 3, 54, 16, 9 });
	base_anim_3[0].PushBack({ 3, 65, 16, 9 });
	base_anim_3[0].PushBack({ 3, 76, 16, 9 });
	base_anim_3[0].PushBack({ 3, 87, 16, 9 });
	base_anim_3[0].PushBack({ 3, 98, 16, 9 });
	base_anim_3[0].loop = true;
	base_anim_3[0].speed = 0.2f;

	lvl1_sides[0].PushBack({ 21, 94, 14, 6 });
	lvl1_sides[0].PushBack({ 21, 102, 14, 6 });
	lvl1_sides[0].PushBack({ 21, 94, 14, 6 });
	lvl1_sides[0].PushBack({ 0, 45, 1, 1 });
	lvl1_sides[0].loop = true;
	lvl1_sides[0].speed = 0.5f;

	base_anim_3[1].PushBack({ 56, 102, 16, 9 });
	base_anim_3[1].PushBack({ 56, 89, 16, 9 });
	base_anim_3[1].PushBack({ 56, 78, 16, 9 });
	base_anim_3[1].PushBack({ 56, 67, 16, 9 });
	base_anim_3[1].PushBack({ 56, 56, 16, 9 });
	base_anim_3[1].PushBack({ 56, 45, 16, 9 });
	base_anim_3[1].loop = true;
	base_anim_3[1].speed = 0.2f;

	lvl1_sides[1].PushBack({ 40, 52, 14, 6 });
	lvl1_sides[1].PushBack({ 40, 45, 14, 6 });
	lvl1_sides[1].PushBack({ 40, 52, 14, 6 });
	lvl1_sides[1].PushBack({ 0, 45, 1, 1 });
	lvl1_sides[1].loop = true;
	lvl1_sides[1].speed = 0.5f;


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
	rotation_lvl1[0].PushBack({ 240, 7, 17, 16 });
	rotation_lvl1[0].PushBack({ 280, 6, 16, 17 });
	rotation_lvl1[0].PushBack({ 260, 7, 17, 16 });
	rotation_lvl1[0].PushBack({ 299, 6, 16, 17 });
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

	for (int counter = 0; counter < ROT_STEPS; counter++) // write ROT_ANIM instead once animation for rotation is fully ready
	{
		rotation_level[counter] = rotation_lvl1[counter];
	}

}

ModuleShield::~ModuleShield() 
{
	delete current_lvl;
	delete current_base;
	delete collider1;
	delete collider2;
	delete graphics;
}

bool ModuleShield::Start() {
	bool ret = true;

	graphics = App->textures->Load("Assets/Sprites/player/shield.png"); //Loads shield image bank

	if (graphics == nullptr) ret = false; //failsafe for wrong address
	
	timer = 0;

	switch (App->player->type) {

		// ---- Stays in front of ship
	case bullet_type::TYPE_1:
		
		//give_position_x(radius, deg);
		//give_position_x(radius, deg);

		pos1_t1[0].x = App->player->position.x + give_position_x(RADIUS, 0.0);
		pos1_t1[0].y = App->player->position.y + give_position_y(RADIUS, 0.0);
		pos2_t1[0].x = App->player->position.x + give_position_x(RADIUS, 180.0);
		pos2_t1[0].y = App->player->position.y + give_position_y(RADIUS, 180.0);

		position1.x = pos1_t1[0].x;
		position1.y = pos1_t1[0].y;
		position2.x = pos2_t1[0].x;
		position2.y = pos2_t1[0].y;

		break;

		// ---- Stays on either side of the ship
	case bullet_type::TYPE_2:
		position1.x = App->player->position.x + 5;
		position1.y = App->player->position.y - 19;
		position2.x = App->player->position.x + 5;
		position2.y = App->player->position.y + 27;
		break;

		// ---- Stays in front of ship
	case bullet_type::TYPE_3:
		position1.x = App->player->position.x + 29;
		position1.y = App->player->position.y - 8;
		position2.x = App->player->position.x + 29;
		position2.y = App->player->position.y + 10;
		break;

		// ---- Stays behind ship
	case bullet_type::TYPE_4:
		position1.x = App->player->position.x - 16;
		position1.y = App->player->position.y - 8;
		position2.x = App->player->position.x - 16;
		position2.y = App->player->position.y + 10;
		break;
	}


	// ---- Declares colliders for shield parts individually
	collider1 = App->collision->AddCollider({ position1.x, position1.y, 14, 16 }, COLLIDER_SHIELD_1, this);
	collider2 = App->collision->AddCollider({ position2.x, position2.y, 14, 16 }, COLLIDER_SHIELD_1, this);


	return ret;
}

update_status ModuleShield::Update() {

	/*if (life == 1) current_lvl = &lvl1;
	else if (life == 2)	current_lvl = &lvl2;
	else if (life == 3)	current_lvl = &lvl3;
*/
	

	// ---- Keeps realtive position to the ship
	switch (App->player->type) {

		// ---- Stays in front of ship
	case bullet_type::TYPE_1:

		pos1_t1[0].x = App->player->position.x + give_position_x(RADIUS, 0.0);
		pos1_t1[0].y = App->player->position.y + give_position_y(RADIUS, 0.0);
		pos2_t1[0].x = App->player->position.x  + give_position_x(RADIUS, 180.0);
		pos2_t1[0].y = App->player->position.y + give_position_y(RADIUS, 180.0);

		pos1_t1[1].x = App->player->position.x + give_position_x(RADIUS, 90 + 67.5);
		pos1_t1[1].y = App->player->position.y + give_position_y(RADIUS, 90 + 67.5);
		pos2_t1[1].x = App->player->position.x + give_position_x(RADIUS, 270 + 67.5);
		pos2_t1[1].y = App->player->position.y + give_position_y(RADIUS, 270 + 67.5);

		pos1_t1[2].x = App->player->position.x + give_position_x(RADIUS, 90 + 45.0);
		pos1_t1[2].y = App->player->position.y + give_position_y(RADIUS, 90 + 45.0);
		pos2_t1[2].x = App->player->position.x + give_position_x(RADIUS, 270 + 45.0);
		pos2_t1[2].y = App->player->position.y + give_position_y(RADIUS, 270 + 45.0);

		pos1_t1[3].x = App->player->position.x + give_position_x(RADIUS, 90 + 22.5);
		pos1_t1[3].y = App->player->position.y + give_position_y(RADIUS, 90 + 22.5);
		pos2_t1[3].x = App->player->position.x + give_position_x(RADIUS, 270 + 22.5);
		pos2_t1[3].y = App->player->position.y + give_position_y(RADIUS, 270 + 22.5);

		pos1_t1[4].x = App->player->position.x + give_position_x(RADIUS, 90.0);
		pos1_t1[4].y = App->player->position.y + give_position_y(RADIUS, 90.0);
		pos2_t1[4].x = App->player->position.x + give_position_x(RADIUS, 270.0);
		pos2_t1[4].y = App->player->position.y + give_position_y(RADIUS, 270.0);

		pos1_t1[5].x = App->player->position.x + give_position_x(RADIUS, 67.5);
		pos1_t1[5].y = App->player->position.y + give_position_y(RADIUS, 67.5);
		pos2_t1[5].x = App->player->position.x + give_position_x(RADIUS, 180.0 + 67.5);
		pos2_t1[5].y = App->player->position.y + give_position_y(RADIUS, 180.0 + 67.5);

		pos1_t1[6].x = App->player->position.x + give_position_x(RADIUS, 45.0);
		pos1_t1[6].y = App->player->position.y + give_position_y(RADIUS, 45.0);
		pos2_t1[6].x = App->player->position.x + give_position_x(RADIUS, 180 + 45.0);
		pos2_t1[6].y = App->player->position.y + give_position_y(RADIUS, 180.0 + 45.0);

		pos1_t1[7].x = App->player->position.x + give_position_x(RADIUS, 22.5);
		pos1_t1[7].y = App->player->position.y + give_position_y(RADIUS, 22.5);
		pos2_t1[7].x = App->player->position.x + give_position_x(RADIUS, 180.0 + 22.5);
		pos2_t1[7].y = App->player->position.y + give_position_y(RADIUS, 180.0 + 22.5);

		position1.x = pos1_t1[circ].x;
		position1.y = pos1_t1[circ].y;
		position2.x = pos2_t1[circ].x;
		position2.y = pos2_t1[circ].y;
		
		current_lvl = &lvl1;
		current_base = &base_anim;


		break;

		// ---- Stays on either side of the ship
	case bullet_type::TYPE_2:
		position1.x = App->player->position.x + 5;
		position1.y = App->player->position.y - 19;		
		position2.x = App->player->position.x + 5;
		position2.y = App->player->position.y + 27;

		current_lvl = &lvl1;
		current_base = &base_anim;

		break;

		// ---- Stays in front of ship
	case bullet_type::TYPE_3:
		position1.x = App->player->position.x + 29;
		position1.y = App->player->position.y - 8;
		position2.x = App->player->position.x + 29;
		position2.y = App->player->position.y + 10;

		current_lvl = &lvl1;
		current_base = &base_anim;

		break;

		// ---- Stays behind ship
	case bullet_type::TYPE_4:
		position1.x = App->player->position.x - 16;
		position1.y = App->player->position.y - 8;
		position2.x = App->player->position.x - 16;
		position2.y = App->player->position.y + 10;

		current_lvl = &lvl1_behind;
		current_base = &base_anim_2;


		break;
	}

	SDL_Rect base, base_2;
	SDL_Rect light, light_2;

	if (App->player->type == bullet_type::TYPE_2)
	{
		collider1->SetPos(position1.x + 1, position1.y - 5);
		collider2->SetPos(position2.x + 1, position2.y);

		base = base_anim_3[0].GetCurrentFrame();
		base_2 = base_anim_3[1].GetCurrentFrame();

		light = lvl1_sides[0].GetCurrentFrame();
		light_2 = lvl1_sides[1].GetCurrentFrame();
	}
	else
	{
		base = current_base->GetCurrentFrame();
		light = current_lvl->GetCurrentFrame();
		collider1->SetPos(position1.x, position1.y);
		collider2->SetPos(position2.x, position2.y);
	}

	timer++;

	// ---- Draw Everything
	if(App->player->type == bullet_type::TYPE_1)
	{
		App->render->Blit(graphics, position1.x, position1.y, &rotation_level[0].GetCurrentFrame());
		App->render->Blit(graphics, position2.x, position2.y, &rotation_level[0].GetCurrentFrame());

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

	else if (App->player->type == bullet_type::TYPE_2) // side (up, down)
	{
		App->render->Blit(graphics, position1.x, position1.y, &base);
		App->render->Blit(graphics, position2.x, position2.y, &base_2);
		App->render->Blit(graphics, position1.x + 1, position1.y - 5, &light);
		App->render->Blit(graphics, position2.x + 1, position2.y + 8, &light_2);
	}

	else if (App->player->type == bullet_type::TYPE_3) // front
	{
		App->render->Blit(graphics, position1.x, position1.y, &base);
		App->render->Blit(graphics, position2.x, position2.y, &base);
		App->render->Blit(graphics, position1.x + 8, position1.y + 1, &light);
		App->render->Blit(graphics, position2.x + 8, position2.y + 1, &light);
	}

	else if (App->player->type == bullet_type::TYPE_4) // behind
	{
		App->render->Blit(graphics, position1.x, position1.y, &base);
		App->render->Blit(graphics, position2.x, position2.y, &base);
		App->render->Blit(graphics, position1.x - 5, position1.y + 1, &light);
		App->render->Blit(graphics, position2.x - 5, position2.y + 1, &light);
	}

	return update_status::UPDATE_CONTINUE;
}

void ModuleShield::OnCollision(Collider* col_1, Collider* col_2) {
	if (collider1 == col_1 || collider2 == col_1)
		if (IsEnabled()) {
			App->player->Shield--;
			if (App->player->Shield == 0)
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

bool ModuleShield::CleanUp() {

	// Remove all memory leaks
	LOG("Unloading shield");
	App->textures->Unload(graphics);

	//Get rid of colliders;

	collider1 = nullptr;
	collider2 = nullptr;
	current_lvl = nullptr;
	current_base = nullptr;
	graphics = nullptr;

 	return true;
}