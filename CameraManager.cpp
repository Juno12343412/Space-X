#include "DXUT.h"
#include "CameraManager.h"


CameraManager::CameraManager()
{
	Init();
}


CameraManager::~CameraManager()
{
	Release();
}

void CameraManager::Init()
{
	m_vCameraPos = Vector3(0, 100, 0);
	m_vViewSize = Vector3((float)WINSIZEX, (float)WINSIZEY, 0);
	m_vScale = m_vEndScale = Vector3(1, 1, 1);

	m_ShakeTime = 0;
	m_vCameraRot = Vector3(0, -0.8f, 1);
	D3DXMatrixOrthoLH(&m_matProj, m_vViewSize.x, -m_vViewSize.y, m_vViewSize.z, 1);
	D3DXMatrixPerspectiveFovLH(&m_matProj, D3DX_PI / 4.f, 16.f / 9.f, 1.f, 1000000);
}

void CameraManager::Release()
{
}

void CameraManager::SetTransform()
{
	DXUTGetD3D9Device()->SetTransform(D3DTS_VIEW, &m_matView);
	DXUTGetD3D9Device()->SetTransform(D3DTS_PROJECTION, &m_matProj);
}

void CameraManager::MoveCamera(const Vector3& vPlusPos)
{
	m_vCameraPos += vPlusPos;
}

void CameraManager::RotateCamera(const Vector3& vPlusRot)
{
	m_vCameraRot += vPlusRot;
	D3DXVec3Normalize(&m_vCameraRot, &m_vCameraRot);
}

void CameraManager::SetCamera(const Vector3& vSetPos)
{
	m_vCameraPos = vSetPos;
}

void CameraManager::Update()
{
	if (m_ShakeTime >= timeGetTime())
	{
		Vector3 shakePos = (m_vCameraPos + Vector3(rand() % 20 - 10, rand() % 20 - 10, 0));
		MATH->Lerp<Vector3>(&m_vCameraPos, m_vCameraPos, shakePos, 1.0f);
	}

	D3DXMatrixLookAtLH(&m_matView, &(m_vCameraPos), &(m_vCameraPos + m_vCameraRot), &Vector3(0, 1, 0));
}

void CameraManager::Reset()
{
	m_vCameraPos = Vector3(1, 100, 0);
	m_vCameraRot = Vector3(0, 0, 0);

	m_vScale = m_vEndScale = D3DXVECTOR3(1, 1, 1);
	m_vCameraRot = Vector3(0, -0.8f, 1);
	D3DXMatrixOrthoLH(&m_matProj, m_vViewSize.x, -m_vViewSize.y, m_vViewSize.z, 1);
	D3DXMatrixPerspectiveFovLH(&m_matProj, D3DX_PI / 4.f, 16.f / 9.f, 1.f, 1000000);
}

void CameraManager::CameraShake(float _time)
{
	if (m_ShakeTime <= _time + timeGetTime())
		m_ShakeTime = _time + timeGetTime();
}
