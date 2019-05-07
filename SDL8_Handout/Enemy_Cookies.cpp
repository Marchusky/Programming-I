#include "Application.h"
#include "Enemy_Cookies.h"
#include "ModuleCollision.h"
#include "Path.h"


Enemy_Cookies::Enemy_Cookies(int x, int y) : Enemy(x, y)
{
	fly.PushBack({ 5,72,21,22 });
	fly.speed = 0.2f;

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 24, 24 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_y = y;
}

void Enemy_Cookies::Move()
{
	Cookie_Path.PushBack(Cookie_speed, Cookie_step.frames, Cookie_step.animation);

}
