#ifndef __ModuleCollision_H__
#define __ModuleCollision_H__

#define MAX_COLLIDERS 200

#include "Module.h"

enum COLLIDER_TYPE
{

	COLLIDER_WALL,
	COLLIDER_PLAYER,
	COLLIDER_PLAYER_2,
	COLLIDER_ENEMY,
	COLLIDER_PLAYER_SHOT,
	COLLIDER_PLAYER_SHOT_ALT,
	COLLIDER_PLAYER2_SHOT,
	COLLIDER_PLAYER2_SHOT_ALT,
	COLLIDER_ENEMY_SHOT,
	COLLIDER_POWER_UP,
	COLLIDER_ENEMY_SHOOTER, 
	COLLIDER_SHIELD_1,
	COLLIDER_SHIELD_2,
	COLLIDER_NONE,
	COLLIDER_NONE_PLAYER_2,
	COLLIDER_ULTIMATES,
	COLLIDER_ULTIMATES_P2,

	COLLIDER_MAX
};

struct Collider
{
	SDL_Rect rect;
	bool to_delete = false;
	COLLIDER_TYPE type;
	Module* callback = nullptr;
	int damage;

	Collider(SDL_Rect rectangle, COLLIDER_TYPE type, Module* callback = nullptr) :
		rect(rectangle),
		type(type),
		callback(callback)
	{}

	void SetPos(int x, int y)
	{
		rect.x = x;
		rect.y = y;
	}

	bool CheckCollision(const SDL_Rect& r) const;
};

class ModuleCollision : public Module
{
public:

	ModuleCollision();
	~ModuleCollision();

	update_status PreUpdate();
	update_status Update();
	bool CleanUp();

	Collider* AddCollider(SDL_Rect rect, COLLIDER_TYPE type, Module* callback = nullptr);


private:
	Collider * colliders[MAX_COLLIDERS] = { nullptr };
	bool matrix[COLLIDER_MAX][COLLIDER_MAX];
	bool debug = false;
};

#endif // __ModuleCollision_H__