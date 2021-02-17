#include "DXUT.h"
#include "InputManager.h"

InputManager::InputManager()
{
}

InputManager::~InputManager()
{
}

void InputManager::Update()
{
	memcpy(last, current, sizeof(current));

	for (int i = 0; i < 256; i++)
	{
		current[i] = false;
		if (GetAsyncKeyState(i))
			current[i] = true;
	}
}

bool InputManager::KeyDown(BYTE key)
{
	return current[key] && !last[key];
}

bool InputManager::KeyUp(BYTE key)
{
	return !current[key] && last[key];

}

bool InputManager::KeyPress(BYTE key)
{
	return current[key] && last[key];

}
