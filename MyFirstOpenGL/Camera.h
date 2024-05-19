#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm.hpp>

#include "GLManager.h"
#include "TimeManager.h"

#define CAMERA Camera::Instance()

class Camera
{
public:
    inline static Camera& Instance()
    {
        static Camera camera;
        return camera;
    }

    glm::vec3 position;
    glm::vec3 target;
    glm::vec3 localVectorUp;

    float fFov;
    float fNear;
    float fFar;

    float movementSpeed;

    bool isOrbitating = true;

    Camera();

    void UpdateCamera();

private:
    enum CameraState {
        PROFILE_VIEW_1,
        PROFILE_VIEW_2,
        DOLLY_ZOOM,
        ORBIT
    };

    CameraState currentState = ORBIT;

    void HandleKeyboardInput(GLFWwindow* window);

    void SetCameraPosition(glm::vec3 _position, glm::vec3 _target, float _fFov);

    void ApplyCameraState();

    void Orbit(float deltaTime);
};
