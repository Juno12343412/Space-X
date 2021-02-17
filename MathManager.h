#pragma once
#include "singleton.h"
class MathManager :
    public singleton<MathManager>
{
public:
	template <typename T>
	void Lerp(T* target, T& start, T& finsh, float time)
	{
		*target = start + (finsh - start) * time * D_TIME;
	}

	Vector3 GetDirections(Vector3 start, Vector3 end)
	{
		Vector3 dir = end - start;
		D3DXVec3Normalize(&dir, &dir);

		return dir;
	}
};

#define MATH MathManager::GetInstance()