#pragma once

#ifdef _WIN32
#include <windows.h>
#include <mmsystem.h>
#elif defined(_UNIX)
#include <ctime>
#include <sys/time.h>
#endif

class CTimer
{
public:
    CTimer();
    ~CTimer();

    // 更新计时器，计算帧间隔
    void Tick();

    // 获取FPS
    int GetFPS();

    // 获取帧间隔
    float GetFrameDelta();

private:
    // 获取当前时间的静态方法
    static float GetCurrentTime();

    // FPS计数器
    static float FPSLastCheckTime; // 上次FPS检查时间
    static int FPSCounter;         // 帧率计数器
    static int FPS;                // 当前FPS

    // 帧间隔
    static float LastTime;         // 上次更新时间
    static float FrameDelta;       // 帧间隔（秒）
};
