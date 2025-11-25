#include "NeHeGL.h"

int main()
{
    GL_Window window;
    Keys keys;
    CCamera camera;
    
    if (!Initialize(&window, &keys, &camera))
    {
        return -1;
    }
    
    int frameCount = 0;
    while (frameCount < 100)
    {
        Update();
        DrawScene();
        frameCount++;
    }
    
    Deinitialize();
    
    return 0;
}
