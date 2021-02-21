#pragma once
class Collider;

enum RenderType : char
{
	FIRST,
	THREE,
	TWO,
	FINSH,
};


class Object
{
public:
	Object();
	virtual ~Object();

	Vector3 vPos = { 0,0,0 };
	Vector3 vRot = { 0,0,0 };
	Vector3 vSize = { 1,1,1 };

	Matrix matWorld;
	Matrix R;
	bool isDestroy = false;

	float hp = 0;
	float damage = 0;
	bool isGravity = false;
	float objHeight = 0;
	wstring key;
	RenderType renderType = RenderType::FIRST;

	virtual void Init() PURE;
	virtual void Update() PURE;
	virtual void Render() PURE;
	virtual void Release() PURE;
	virtual void onCollisionEnter(Collider* col1, Collider* col2) PURE;
	virtual void onCollisionStay(Collider* col1, Collider* col2) PURE;
	virtual void onCollisionExit(Collider* col1, Collider* col) PURE;
	virtual void TransformUpdate();
	virtual void MovePos(Vector3 pos);
	virtual void RotatePos(Vector3 rot);
	virtual void RotateRerpPos(Vector3 rot, float time);
	virtual void SetPos(Vector3 pos);
	virtual void SetRotate(Vector3 rot);

	bool CheckDestroy() { return isDestroy; }
};