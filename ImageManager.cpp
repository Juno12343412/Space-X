#include "DXUT.h"
#include "ImageManager.h"
#include "MeshLoader.h"


void texture::CenterRender(Vector3 pos, float rot, Vector3 size, D3DCOLOR color)
{
	IMAGE->CenterRender(this, pos, rot, size, color);
}

void texture::Render(Vector3 pos, float rot, Vector3 size, RECT rect, D3DCOLOR color)
{
	IMAGE->Render(this, pos, rot, size, rect, color);
}

void texture::Release()
{
	SAFE_RELEASE(texturePtr);
}


ImageManager::ImageManager()
	:m_sprite(nullptr)
{
	Init();
}


ImageManager::~ImageManager()
{
	Release();
}


texture* ImageManager::AddImage(wstring key, wstring path)
{
	auto find = m_images.find(key);
	if (find == m_images.end())
	{
		LPDIRECT3DTEXTURE9 texturePtr;
		D3DXIMAGE_INFO info;
		TCHAR ch[256];

		if (path.length() <= 13) {
			wsprintf(ch, L"./Resource/2D/%s.png", path.c_str());
		}
		else
		{
			wsprintf(ch, L"%s", path.c_str());
		}
		D3DXGetImageInfoFromFile(ch, &info);
		if (D3DXCreateTextureFromFileEx(g_device, ch, D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2, 0, 0,
			D3DFMT_A8R8G8B8, D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT, NULL, &info, nullptr, &texturePtr) == S_OK)
		{
			texture* text = new texture(texturePtr, info);
			m_images.insert(make_pair(key, text));
			return text;
		}
#pragma region 로딩실패



#pragma endregion
		return nullptr;
	}

	return find->second;
}

texture* ImageManager::FindImage(wstring key)
{
	auto find = m_images.find(key);
	if (find == m_images.end()) return nullptr;
	return find->second;
}

VECtexture* ImageManager::ADDVECIMAGE(wstring key, wstring path, int max)
{
	auto find = vecImages.find(key);
	if (find != vecImages.end())
		return find->second;

	VECtexture* vec = new VECtexture();

	for (int i = 0; i <= max; i++)
	{
		LPDIRECT3DTEXTURE9 lpTexture;
		D3DXIMAGE_INFO info;

		TCHAR ch[256];

		if (path.length() <= 13) {
			wsprintf(ch, L"./Resource/2D/%s/(%d).png", path.c_str(), i);
		}
		else
		{
			wsprintf(ch, L"%s", path.c_str());
		}
		D3DXGetImageInfoFromFile(ch, &info);

		if (D3DXCreateTextureFromFileEx(g_device, ch, D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2, 0, 0,
			D3DFMT_A8R8G8B8, D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT, NULL, &info, nullptr, &lpTexture) == S_OK)
		{
			texture* text = new texture(lpTexture, info);
			vec->ADDIMAGE(text);
		}

	}

	vecImages.insert(make_pair(key, vec));
	return vec;
}

VECtexture* ImageManager::FINDVECIMAGE(wstring key)
{
	return vecImages[key];
}

CMeshLoader* ImageManager::AddMesh(wstring key, wstring path)
{
	auto find = meshes.find(key);
	if (find == meshes.end())
	{
		CMeshLoader* mesh = new CMeshLoader();
		WCHAR ch[256];
		wsprintf(ch, L"./Resource/3D/%s.obj", path.c_str());
		mesh->Create(g_device, ch);
		if (mesh)
		{
			meshes.insert(make_pair(key, mesh));
			return mesh;
		}
#pragma region 로딩실패



#pragma endregion
		return nullptr;
	}

	return find->second;
}

CMeshLoader* ImageManager::FindMesh(wstring key)
{
	auto find = meshes.find(key);
	if (find == meshes.end()) return nullptr;
	return find->second;
}

VECMesh* ImageManager::ADDVECMESH(wstring key, wstring path, int max)
{
	auto find = vecMeshes.find(key);
	if (find == vecMeshes.end()) {
		VECMesh* vec = new VECMesh();

		for (int i = 0; i <= max; i++)
		{
			CMeshLoader* mesh = new CMeshLoader;
			WCHAR ch[256];
			wsprintf(ch, L"./Resource/3D/%s/(%d).obj", path.c_str(), i);
			mesh->Create(g_device, ch);
			if (mesh)
			{
				vec->ADDMESH(mesh);
			}
		}
		vecMeshes.insert(make_pair(key, vec));
		return vec;
	}
	return nullptr;
}

VECMesh* ImageManager::FINDVECMESH(wstring key)
{
	return vecMeshes[key];
}

void ImageManager::Init()
{
	D3DXCreateSprite(g_device, &m_sprite);
}

void ImageManager::Release()
{
	for (auto iter : m_images)
	{
		iter.second->Release();
		SAFE_DELETE(iter.second);
	}
	m_images.clear();

	for (auto iter : vecImages)
	{
		SAFE_DELETE(iter.second);
	}
	vecImages.clear();
	m_sprite->Release();

	for (auto iter : meshes)
	{
		iter.second->Destroy();
		SAFE_RELEASE(iter.second->m_pMesh);
		SAFE_DELETE(iter.second);
	}
	meshes.clear();

	for (auto iter : vecMeshes)
	{
		SAFE_DELETE(iter.second);
	}
	vecMeshes.clear();
}

void ImageManager::ReBegin(bool isUi, bool isBill)
{
	End(); Begin(isUi, isBill);
}

void ImageManager::Begin(bool isUi, bool isBill)
{
	if (isBill)
	{
		m_sprite->SetWorldViewLH(NULL, &CAMERA->m_matView);
		m_sprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_OBJECTSPACE | D3DXSPRITE_BILLBOARD);
	}
	else
	{
		if (!isUi)
			m_sprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_OBJECTSPACE);
		else {
			m_sprite->Begin(D3DXSPRITE_ALPHABLEND);
		}
	}

}

void ImageManager::End()
{
	m_sprite->End();
}

void ImageManager::CenterRender(texture* texturePtr, Vector3 pos, float rot, Vector3 size, D3DCOLOR color)
{
	if (texturePtr)
	{
		Matrix matworld;
		g_device->SetTransform(D3DTS_WORLD, D3DXMatrixIdentity(&matworld));
		Matrix mSize, mPos, mRot;
		D3DXMatrixScaling(&mSize, size.x, size.y, size.z);
		D3DXMatrixTranslation(&mPos, pos.x, pos.y, pos.z);
		D3DXMatrixRotationZ(&mRot, D3DXToRadian(rot));

		m_sprite->SetTransform(&(mSize * mRot * mPos));
		m_sprite->Draw(texturePtr->texturePtr, NULL, &Vector3(texturePtr->info.Width / 2, texturePtr->info.Height / 2, 0), NULL, color);
	}
}

void ImageManager::Render(texture* texturePtr, Vector3 pos, float rot, Vector3 size, RECT rect, D3DCOLOR color)
{
	if (texturePtr)
	{
		Matrix matworld;
		g_device->SetTransform(D3DTS_WORLD, D3DXMatrixIdentity(&matworld));
		Matrix mSize, mPos, mRot;
		D3DXMatrixScaling(&mSize, size.x, size.y, size.z);
		D3DXMatrixTranslation(&mPos, pos.x, pos.y, 0);
		D3DXMatrixIdentity(&mRot);

		m_sprite->SetTransform(&(mSize * mRot * mPos));
		m_sprite->Draw(texturePtr->texturePtr, &rect, NULL, NULL, D3DCOLOR_ARGB(255, 255, 255, 255));

	}
}

void ImageManager::MeshRender(CMeshLoader* meshPtr, Matrix matWorld, bool isCCW)
{
	if (meshPtr)
	{

		if (isCCW)
			g_device->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);

		else
			g_device->SetRenderState(D3DRS_CULLMODE, D3DCULL_CW);


		g_device->SetTransform(D3DTS_WORLD, &matWorld);

		for (int i = 0; i < meshPtr->GetNumMaterials(); ++i)
		{
			g_device->SetTexture(0, meshPtr->GetMaterial(i)->pTexture);
			meshPtr->GetMesh()->DrawSubset(i);
		}

		Matrix iden;
		D3DXMatrixIdentity(&iden);
		g_device->SetTransform(D3DTS_WORLD, &iden);

	}
}


void ImageManager::TextDraw(wstring str, Vector3 pos, float size, D3DCOLOR color, bool Center)
{
	Matrix mat;

	if (!Center) {

		D3DXCreateFontA(g_device, size, 0, 10, 1, FALSE, HANGEUL_CHARSET, 0, 0, 0, "Fixedsys", &lpFont);
		D3DXMatrixTranslation(&mat, pos.x, pos.y, pos.z);
	}
	else {
		D3DXCreateFontA(g_device, size, 0, 0, 1, FALSE, HANGEUL_CHARSET, 0, 0, 0, "Fixedsys", &lpFont);
		D3DXMatrixTranslation(&mat, pos.x - size * (str.size() * 0.25), pos.y - size / 2.f, pos.z);
	}

	m_sprite->SetTransform(&mat);
	lpFont->DrawTextW(m_sprite, str.c_str(), str.size(), NULL, DT_NOCLIP, color);

	SAFE_RELEASE(lpFont);
}


void ImageManager::LostDevice()
{
	m_sprite->OnLostDevice();
}

void ImageManager::ResetDevice()
{
	m_sprite->OnResetDevice();
}


VECtexture::VECtexture()
{
}

VECtexture::~VECtexture()
{
	for (auto iter : m_VecTex) {
		iter->Release();
		SAFE_DELETE(iter);
	}
	m_VecTex.clear();
}

void VECtexture::ADDIMAGE(texture* tempImage)
{
	m_VecTex.push_back(tempImage);
}

texture* VECtexture::FINDIMAGE(int count)
{
	if (count == -1)
		return m_VecTex[0];
	else
		return m_VecTex[count];
}

VECMesh::VECMesh()
{

}

VECMesh::~VECMesh()
{
	for (auto iter : vecMesh) {
		iter->Destroy();
		SAFE_DELETE(iter);
	}
	vecMesh.clear();
}

void VECMesh::ADDMESH(CMeshLoader* tempMesh)
{
	vecMesh.push_back(tempMesh);
}

CMeshLoader* VECMesh::FINDMESH(int count)
{
	if (count == -1)
		return vecMesh[0];
	else
		return vecMesh[count];
}


