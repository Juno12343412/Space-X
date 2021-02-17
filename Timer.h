#pragma once
class Timer
{
public:
    float start = 0;
    float delay = 0;

    bool Update();
    void SetTimer(float time) { delay = time; };
};

