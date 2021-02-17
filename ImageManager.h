#pragma once
#include "singleton.h"
#include "MeshLoader.h"

struct texture
{
    LPDIRECT3DTEXTURE9 texturePtr;
    D3DXIMAGE_INFO info;

    texture(LPDIRECT3DTEXTURE9 texturePtr, D3DXIMAGE_INFO info)
        :texturePtr(texturePtr), info(info)
    {
    }

    void CenterRender(Vector3 pos, float rot = 0, Vector3 size = { 1,1,1 }, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));
    void Render(Vector3 pos, float rot = 0, Vector3 size = { 1,1,1 }, RECT rect = {1,1,1,1}, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));
    void Release();
};

struct VECtexture {
    vector<texture*> m_VecTex;
public:
    VECtexture();
    ~VECtexture();

    void ADDIMAGE(texture* tempImage);
    texture* FINDIMAGE(int count = -1);
};

struct VECMesh
{
    vector<CMeshLoader*> vecMesh;
public:
    VECMesh();
    ~VECMesh();

    void ADDMESH(CMeshLoader* tempImage);
    CMeshLoader* FINDMESH(int count = -1);
};

class ImageManager :
    public singleton<ImageManager>
{
public:
    LPD3DXSPRITE m_sprite;
    map<wstring, texture*> m_images;
    map<wstring, VECtexture*> vecImages;
    map<wstring, CMeshLoader*> meshes;
    map<wstring, VECMesh*> vecMeshes;

    LPD3DXFONT lpFont;

    void Init();
    void Release();

    ImageManager();
    ~ImageManager();

    texture* AddImage(wstring key, wstring path);
    texture* FindImage(wstring key);

    VECtexture* ADDVECIMAGE(wstring key, wstring path, int max);
    VECtexture* FINDVECIMAGE(wstring key);

    CMeshLoader* AddMesh(wstring key, wstring path);
    CMeshLoader* FindMesh(wstring key);

    VECMesh* ADDVECMESH(wstring key, wstring path, int max);
    VECMesh* FINDVECMESH(wstring key);

    void Begin(bool isUi, bool isBill);
    void ReBegin(bool isUi, bool isBill);
    void End();

    void CenterRender(texture* texturePtr, Vector3 pos, float rot = 0, Vector3 size = { 1,1,1 }, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));
    void Render(texture* texturePtr, Vector3 pos, float rot = 0, Vector3 size = { 1,1,1 }, RECT rect = {1,1,1,1}, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));
    
    void MeshRender(CMeshLoader* meshPtr, Matrix matWorld, bool isCCW);
    void TextDraw(wstring str, Vector3 pos, float size, D3DCOLOR color, bool center);

    void LostDevice();
    void ResetDevice();
};

#define IMAGE ImageManager::GetInstance()