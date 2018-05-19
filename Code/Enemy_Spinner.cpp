#include "Application.h"
#include "Enemy_Spinner.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleUserInterface.h"
#include "ModuleEnemies.h"
#include "ModuleAudio.h"

Enemy_Spinner::Enemy_Spinner(int x, int y) : Enemy(x, y)
{
	//fly.PushBack({ 132, 42, 41, 36 });
	//fly.PushBack({ 195, 42, 41, 36 });
	//fly.PushBack({ 258, 44, 41, 36 });
	//fly.PushBack({ 132, 89, 41, 36 });
	//fly.PushBack({ 195, 89, 41, 36 });
	//fly.PushBack({ 258, 90, 41, 36 });
	//fly.PushBack({ 132, 131, 41, 36 });
	//fly.PushBack({ 195, 129, 41, 36 });
	//fly.PushBack({ 258, 129, 41, 36 });
	//fly.PushBack({ 132, 169, 41, 36 });
	//fly.PushBack({ 195, 168, 41, 36 });
	//fly.PushBack({ 258, 168, 41, 36 });

	fly.PushBack({ 150, 455, 16, 16 });
	fly.PushBack({ 179, 455, 16, 16 });
	fly.PushBack({ 208, 455, 16, 16 });
	fly.PushBack({ 150, 475, 16, 16 });
	fly.PushBack({ 179, 475, 16, 16 });
	fly.PushBack({ 208, 475, 16, 16 });

	fly.loop = true;
	fly.speed = 0.5f;

	//fly.loop = true;
	//fly.speed = 0.3f;

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 41, 36 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
}

void Enemy_Spinner::Move()
{
	
}

void Enemy_Spinner::OnCollision(Collider* collider)
{
	App->particles->AddParticle(App->particles->enemy_explosion, position.x, position.y, COLLIDER_NONE);
	App->audio->PlayFx(App->enemies->medium_enemy_death);

	if (dead == false)
	{

		if (collider->type == COLLIDER_PLAYER_SHOT)
		{
			App->user_interface->score1 += score;
		}
		if (collider->type == COLLIDER_PLAYER2_SHOT)
		{
			App->user_interface->score2 += score;
		}
	}

	dead = true;
}