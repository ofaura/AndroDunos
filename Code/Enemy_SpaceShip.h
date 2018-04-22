#ifndef __ENEMY_SPACESHIP_H__
#define __ENEMY_SPACESHIP_H__

#include "Enemy.h"

class Enemy_SpaceShip : public Enemy
{
private:
	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	Animation fly;

public:

	Enemy_SpaceShip(int x, int y);
	virtual void OnCollision(Collider* collider) override;
	void Move();
	bool dead = false;
	int score = 100;
};

#endif // __ENEMY_SPACESHIP_H__