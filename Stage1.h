#pragma once
#include "Scene.h"
class Stage1 :
    public Scene
{
    // Scene��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
};

