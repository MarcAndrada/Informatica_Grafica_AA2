#include "Camera.h"

Camera::Camera()
    : position(glm::vec3(0.5f, 0.5f, 1.f)),
    localVectorUp(glm::vec3(0.f, 1.f, 0.f)),
    fFov(45.f),
    fNear(0.1f),
    fFar(10.f),
    movementSpeed(0.01f) {}

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

    // Zoom
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
    if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS)
    {
        fFov -= 0.1f;
        position.z += movementSpeed;
    }
}

void Camera::UpdateCamera()
{
    HandleKeyboardInput(GLM.GetWindow());

    //Genero matriz vista
    glm::mat4 viewMatrix = glm::lookAt(position, position + glm::vec3(0.f, 0.f, -1.f), localVectorUp);

    //Genero matriz de proyeccion
    glm::mat4 projectionMatrix = glm::perspective(glm::radians(fFov), (float)WINDOW_WIDTH / (float)WINDOW_HEIGHT, fNear, fFar);

    // Pasamos las variables a la GPU
    glUniformMatrix4fv(glGetUniformLocation(PROGRAMS.GetCompiledPrograms()[0], "viewMatrix"), 1, GL_FALSE, glm::value_ptr(viewMatrix));
    glUniformMatrix4fv(glGetUniformLocation(PROGRAMS.GetCompiledPrograms()[0], "projectionMatrix"), 1, GL_FALSE, glm::value_ptr(projectionMatrix));

}
