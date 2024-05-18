#include "Camera.h"

Camera::Camera()
    : position(glm::vec3(0.f, 5.f, 10.f)),
    target(glm::vec3(0.f, 0.f, 0.f)),
    localVectorUp(glm::vec3(0.f, 1.f, 0.f)),
    fFov(45.f),
    fNear(0.1f),
    fFar(100.f),
    movementSpeed(0.1f),
    isOrbitating(true),
    currentState(ORBIT) {}

void Camera::HandleKeyboardInput(GLFWwindow* window) 
{
    if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
    {
        position = glm::vec3(0.5f, 2.f, 0.25f);
        target = glm::vec3(1.f, 2.f, 0.25f);
        fFov = 45;

        currentState = PROFILE_VIEW_1;
    }
    else if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS)
    {
        position = glm::vec3(1.f, 2.f, 0.f);
        target = glm::vec3(-1.f, 2.f, 0.f);
        fFov = 45;

        currentState = PROFILE_VIEW_2;
    }
    else if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS)
    {
        position = glm::vec3(0.f, 2.f, 15.f);
        target = glm::vec3(0.f, 2.f, 0.f);
        fFov = 15;

        currentState = DOLLY_ZOOM;
    }
    else if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
    {
        position = glm::vec3(0.f, 5.f, 10.f);
        target = glm::vec3(0.f);
        fFov = 45;

        currentState = ORBIT;
    }
}

void Camera::ApplyCameraState()
{
    switch (currentState) {
    case PROFILE_VIEW_1:
    case PROFILE_VIEW_2:
        break;
    case DOLLY_ZOOM:
        fFov -= 0.1f;
        position.z += movementSpeed;
        break;
    case ORBIT:
    default:
        Orbit();
        break;
    }
}

void Camera::Orbit()
{
    float angle = 0.01f;
    glm::vec3 relativePos = position - target;

    float newX = cos(angle) * relativePos.x - sin(angle) * relativePos.z;
    float newZ = sin(angle) * relativePos.x + cos(angle) * relativePos.z;

    position.x = target.x + newX;
    position.z = target.z + newZ;
}

void Camera::UpdateCamera()
{
    HandleKeyboardInput(GLM.GetWindow());
    ApplyCameraState();

    glm::mat4 viewMatrix = glm::lookAt(position /* Eye */, target /* Target */, localVectorUp /* Up */);

    glm::mat4 projectionMatrix = glm::perspective(glm::radians(fFov), (float)WINDOW_WIDTH / (float)WINDOW_HEIGHT, fNear, fFar);

    for (GLuint program : PROGRAMS.GetCompiledPrograms())
    {
        glUniformMatrix4fv(glGetUniformLocation(program, "viewMatrix"), 1, GL_FALSE, glm::value_ptr(viewMatrix));
        glUniformMatrix4fv(glGetUniformLocation(program, "projectionMatrix"), 1, GL_FALSE, glm::value_ptr(projectionMatrix));
    }
    
}
