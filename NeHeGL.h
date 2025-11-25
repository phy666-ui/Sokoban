/********************
*                   *
*   NeHeGL Header   *
*                   *
**********************************************************************************
*                                                                                *
*	You Need To Provide The Following Functions:                                 *
*                                                                                *
*	BOOL Initialize (GL_Window* window, Keys* keys);                             *
*		Performs All Your Initialization                                         *
*		Returns TRUE If Initialization Was Successful, FALSE If Not              *
*		'window' Is A Parameter Used In Calls To NeHeGL                          *
*		'keys' Is A Structure Containing The Up/Down Status Of keys              *
*                                                                                *
*	void Deinitialize (void);                                                    *
*		Performs All Your DeInitialization                                       *
*                                                                                *
*	void Update (void);                                                          *
*		Perform Motion Updates                                                   *
*                                                                                *
*	void DrawScene(void);                                                        *
*		Perform All Your Scene Drawing                                           *
*                                                                                *
*********************************************************************************/

#ifndef GL_FRAMEWORK__INCLUDED
#define GL_FRAMEWORK__INCLUDED

// 添加BOOL定义
#ifndef BOOL
#define BOOL int
#define TRUE 1
#define FALSE 0
#endif

#include "Camera.h"

struct Keys {
	BOOL keyDown[256];
	BOOL keyUp[256];
};

struct GL_WindowInit {
	char* title;
	int width;
	int height;
	int bitsPerPixel;
	BOOL isFullScreen;
};

struct GL_Window {
	Keys* keys;
	GL_WindowInit init;
	BOOL isVisible;
};

// 这些函数需要由用户提供
BOOL Initialize(GL_Window* window, Keys* keys, CCamera* camera);
void Deinitialize(void);
void Update(void);
void ProcessKeys(void);
void DrawScene(void);

// 全局变量声明
extern int mouse_x;
extern int mouse_y;

extern char appTitle[];
extern int screenInfo[3];

extern GL_Window* g_window;
extern Keys* g_keys;
extern CCamera* g_camera;

#endif
