#include "Timer.h"

// 静态成员变量初始化
float CTimer::FPSLastCheckTime = 0.0f;
int CTimer::FPSCounter = 0;
int CTimer::FPS = 0;
float CTimer::LastTime = 0.0f;
float CTimer::FrameDelta = 0.0f;

// 获取当前时间的跨平台实现
float CTimer::GetCurrentTime()
{
#if defined(_WIN32)
    return (float)timeGetTime() * 0.001f; // 转换为秒
#else
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (float)(tv.tv_sec + tv.tv_usec * 0.000001f);
#endif
}

CTimer::CTimer()
{
    // 初始化时间
    LastTime = GetCurrentTime();
    FPSLastCheckTime = LastTime;
    FPSCounter = 0;
    FPS = 0;
    FrameDelta = 0.0f;
}

CTimer::~CTimer()
{
}

void CTimer::Tick()
{
    float currentTime = GetCurrentTime();
    FrameDelta = currentTime - LastTime;
    LastTime = currentTime;
    
    // 计算FPS
    FPSCounter++;
    if (currentTime - FPSLastCheckTime > 1.0f)
    {
        FPS = FPSCounter;
        FPSCounter = 0;
        FPSLastCheckTime = currentTime;
    }
}

int CTimer::GetFPS()
{
    return FPS;
}

float CTimer::GetFrameDelta()
{
    return FrameDelta;
}

