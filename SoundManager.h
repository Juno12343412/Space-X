#pragma once
#include "singleton.h"
class SoundManager :
    public singleton<SoundManager>
{
private:
    map<string, CSound*> sounds;
    CSoundManager* manager;
public:
    SoundManager();
    virtual ~SoundManager();

    void AddSound(string key, wstring path);
    void Play(string key, BOOL isLoop);
    void Copy(string key, long volume = -1000);
    void Stop(string key);
};

#define SOUND SoundManager::GetInstance()