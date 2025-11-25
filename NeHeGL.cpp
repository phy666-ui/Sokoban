#include "Platform.h"
#include "GLee.h"
#include <gl/glu.h>
#include "Camera.h"
#include "NeHeGL.h"

// 全局变量
GL_Window* g_window;
Keys* g_keys;

// 窗口参数
BOOL keys[256];
BOOL active = TRUE;
BOOL fullscreen = FALSE;

// 鼠标位置
int mouse_x, mouse_y;

// 终止应用程序
void TerminateApplication(GL_Window* window)
{
    // 跨平台实现由main.cpp中的GLFW处理
    g_isProgramLooping = FALSE;
}

// 切换全屏模式
void ToggleFullscreen(GL_Window* window)
{
    // 跨平台实现由main.cpp中的GLFW处理
    fullscreen = !fullscreen;
}

// 调整OpenGL视口
void ReshapeGL(int width, int height)
{
    if (height == 0) height = 1;

    glViewport(0, 0, (GLsizei)(width), (GLsizei)(height));
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (GLfloat)(width)/(GLfloat)(height), 1.0f, 700.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// 跨平台窗口创建占位符
BOOL CreateWindowGL(GL_Window* window)
{
    // 存储窗口指针
    g_window = window;
    return TRUE;
}

// 全局变量
static BOOL g_isProgramLooping = TRUE;
static BOOL g_createFullScreen = FALSE;
