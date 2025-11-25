// 跨平台的头文件包含
#include <stdio.h>										// Header File For Standard Input / Output
#include <stdarg.h>										// Header File For Variable Argument Routines
#include <math.h>										// Header File For Math Operations

// OpenGL 相关头文件
#include "GLee.h"

// DevIL 图像库头文件
#ifdef _WIN32
#include <il\il.h>
#include <il\ilu.h>
#include <il\ilut.h>
#else
#include <IL/il.h>
#include <IL/ilu.h>
#include <IL/ilut.h>
#endif

// OpenAL 音频库头文件
#ifdef _WIN32
#include <al\alut.h>
#else
#include <AL/alut.h>
#endif

#include "NeHeGL.h"									// Header File For NeHeGL

#ifdef  _DEBUG
#define IL_DEBUG
#endif //_DEBUG

GL_Window*	g_window;
Keys*		g_keys;
CCamera*	g_camera;

char	appTitle[] = "Sokoban by rtp|software";	//stores the window title
int		screenInfo[3] = {1024,768,32};		//stores resolution and color bits (w,h,bpp)

// User Defined Variables
//#include "FontGL.h"
#include "SokobanApp.h"

SokobanApp Sokoban;

BOOL Initialize (GL_Window* window, Keys* keys, CCamera* camera)	// Any OpenGL Initialization Goes Here
{
	g_window	= window;
	g_keys		= keys;
	g_camera	= camera;

	// setup the sokoban application
	//////////////////////////////////////////////////////////////////////////
	Sokoban.Setup();
	//////////////////////////////////////////////////////////////////////////


	return TRUE;												// Return TRUE (Initialization Successful)
}

void Deinitialize (void)										// Any User DeInitialization Goes Here
{
	// shut down the sokoban application
	//////////////////////////////////////////////////////////////////////////
	Sokoban.Destroy();
}

//handles keyboard processing
void ProcessKeys(void)
{
	// debug keys
	//////////////////////////////////////////////////////////////////////////
	if (g_keys->keyDown[VK_F4])		{	ToggleFullscreen (g_window);			}
	if (g_keys->keyDown[VK_F11])	{	g_camera->ToggleMouseControl();	g_keys->keyDown[VK_F11] = FALSE;	}
	if (g_keys->keyDown[VK_F12])	{	g_camera->DEBUG_WritePositionToFile(); g_keys->keyDown[VK_F12] = FALSE;	}

	// pass all pressed keys into the 
	for(int index = 0; index <= 256; index++)
	{
		if(g_keys->keyDown[index])
		{
			Sokoban.KeyPressed((char) index);

			g_keys->keyDown[index] = false;
		}
	}

}

void Update(void)									// Perform Motion Updates Here
{
	// Color fading background
	//////////////////////////////////////////////////////////////////////////
/*
		static float color = 0.0f;
		static float color2 = 0.3f;
	
		color += 0.0005f;
		color2 += 0.00005f;
	
		if (color > 0.5f) {color = 0.0f; color2 = 0.3f; }
		//if (color2 > 0.7f) color = 0.3f;
	
		glClearColor(0.0f, color, color2, 0.0f);
*/	
	//////////////////////////////////////////////////////////////////////////
	

	ProcessKeys();

	// update sound
	//////////////////////////////////////////////////////////////////////////
	SokobanSoundManager::Instance().Update();

	g_camera->Update();
}

void DrawScene(void)											// Draw Our Scene
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// Clear Screen And Depth Buffer
	glLoadIdentity();											// Reset The Modelview Matrix

	g_camera->Look();

	//////////////////////////////////////////////////////////////////////////
	
	Sokoban.Render();
	
	//////////////////////////////////////////////////////////////////////////
	

	glFlush();													// Flush The GL Rendering Pipeline
}
