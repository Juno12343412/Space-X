#pragma once

enum ColliderTag
{
	NONE,
	ENEMY,
	ENEMYATTACK,
	PLAYER,
	PLAYERATTACK,
	UI,
	MOUSE,
	END,
};

class Object;


class Collider
{
public:
	texture* img = nullptr;
	Object* parent = nullptr;
	Vector3 colPos = Vector3(0, 0, 0);
	ColliderTag colTag = ColliderTag::NONE;
	float colRadius = 0;
	bool isEnter = false;
	bool isActive = true;
	bool isDestroy = false;
	Collider();
	virtual ~Collider();

	virtual void OnEnterCollision(Collider* col1, Collider* col2);
	virtual void OnExitCollision(Collider* col1, Collider* col2);
	void RangeRender();
};

