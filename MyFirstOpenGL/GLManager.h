#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm.hpp>
#include <gtc/type_ptr.hpp>
#include <iostream>
#include <string>
#include "ProgramManager.h"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 640

#define GLM GLManager::Instance()

class GLManager
{
private:

	enum DrawMode
	{
		FILL,
		LINE
	};

	GLFWwindow* window;
	bool paused;
	DrawMode drawMode;

	GLManager()
	{
		window = nullptr;
		paused = false;
	}

	GLManager(const GLManager&) = delete;
	GLManager& operator =(const GLManager&) = delete;

public:
	inline static GLManager& Instance()
	{
		static GLManager manager;
		return manager;
	}

	void Init();

	void ClearColor();

	void ClearBuffers();

	void ChangeBuffers();

	void Pause();
	
	void SwapDrawMode();

	inline bool GetPaused() { return paused; }
	inline GLFWwindow* GetWindow() { return window; }
	inline bool IsRunnig() { return !glfwWindowShouldClose(window); }
};

