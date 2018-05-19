#include "Application.h"
#include "Enemy_Pipeliner.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleUserInterface.h"
#include "ModuleEnemies.h"
#include "ModulePlayer.h"
#include "ModuleAudio.h"

#include "SDL\include\SDL_timer.h"

Enemy_Pipeliner::Enemy_Pipeliner(int x, int y) : Enemy(x, y)
{
	fly.PushBack({ 149, 12, 16, 16 });
	animation = &fly;
		
	collider = App->collision->AddCollider({ 0, 0, 16, 16 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);
	
	original_y = y;
}

void Enemy_Pipeliner::Move()
{
	currentTime = SDL_GetTicks();
	
	if (currentTime > lastTimeShoot + 1200) // Shoots every 1.2 seconds
		 {
		App->particles->AddParticle(App->particles->enemy_shot_yellow, position.x - 7, position.y + 4, COLLIDER_ENEMY_SHOT);
		lastTimeShoot = currentTime;
	}
	
	if (position.y > App->player->position.y) {
		position.y--;		
	}
	else {
		+position.y++;		
	}	
		//position.y = original_y + path.GetCurrentPosition().y;
		
		collider->SetPos(position.x, position.y);
}

void Enemy_Pipeliner::OnCollision(Collider* collider)
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