#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm.hpp>

#include "GLManager.h"

class Camera
{
public:
    glm::vec3 position;
    glm::vec3 localVectorUp;
    float fFov;
    float fNear;
    float fFar;
    float movementSpeed;

    Camera();

    void UpdateCamera();

private:
    void HandleKeyboardInput(GLFWwindow* window);

};
