#include "Camera.h"

Camera::Camera()
    : position(glm::vec3(5.f, 5.f, 5.f)),
    target(glm::vec3(0.f, 0.f, 0.f)),
    localVectorUp(glm::vec3(0.f, 1.f, 0.f)),
    fFov(45.f),
    fNear(0.1f),
    fFar(1000.f),
    movementSpeed(0.1f) {}

void Camera::HandleKeyboardInput(GLFWwindow* window) 
{
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    {
        position += movementSpeed * glm::vec3(0.f, 1.f, 0.f);
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    {
        position -= movementSpeed * glm::vec3(0.f, 1.f, 0.f);
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    {
        position += movementSpeed * glm::vec3(1.f, 0.f, 0.f);
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    {
        position -= movementSpeed * glm::vec3(1.f, 0.f, 0.f);
    }
    if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS)
    {
        position += movementSpeed * glm::vec3(0.f, 0.f, 1.f);
    }
    if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS)
    {
        position -= movementSpeed * glm::vec3(0.f, 0.f, 1.f);
    }

    if (glfwGetKey(window, GLFW_KEY_PERIOD) == GLFW_PRESS)
    {
        fFov += 1.f;
        if (fFov > 180.f) {
            fFov = 180.f;
        }
    }
    if (glfwGetKey(window, GLFW_KEY_COMMA) == GLFW_PRESS)
    {
        fFov -= 1.f;
        if (fFov > -180.f) {
            fFov = -180.f;
        }
    }
    // Dolly View
    if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS)
    {
        fFov -= 0.1f;
        position.z += movementSpeed;
    }

    // Orbit controls
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
    {
        // Orbit left
        float angle = 0.01f;
        glm::vec3 relativePos = position - target;
        position.x = target.x + cos(angle) * relativePos.x - sin(angle) * relativePos.z;
        position.z = target.z + sin(angle) * relativePos.x + cos(angle) * relativePos.z;
    }
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
    {
        // Orbit right
        float angle = -0.01f;
        glm::vec3 relativePos = position - target;
        position.x = target.x + cos(angle) * relativePos.x - sin(angle) * relativePos.z;
        position.z = target.z + sin(angle) * relativePos.x + cos(angle) * relativePos.z;
    }
}

void Camera::UpdateCamera()
{
    HandleKeyboardInput(GLM.GetWindow());

    //Genero matriz vista
    glm::mat4 viewMatrix = glm::lookAt(position /* Eye */, target /* Target */, localVectorUp /* Up */);

    //Genero matriz de proyeccion
    glm::mat4 projectionMatrix = glm::perspective(glm::radians(fFov), (float)WINDOW_WIDTH / (float)WINDOW_HEIGHT, fNear, fFar);

    // Pasamos las variables a la GPU
    glUniformMatrix4fv(glGetUniformLocation(PROGRAMS.GetCompiledPrograms()[0], "viewMatrix"), 1, GL_FALSE, glm::value_ptr(viewMatrix));
    glUniformMatrix4fv(glGetUniformLocation(PROGRAMS.GetCompiledPrograms()[0], "projectionMatrix"), 1, GL_FALSE, glm::value_ptr(projectionMatrix));

}
