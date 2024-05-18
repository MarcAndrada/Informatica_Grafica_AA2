#pragma once

#include "Model.h"
#include "Texture.h"
#include "Transform.h"

class GameObject
{
public:
	GameObject(GLuint _program, glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale, Model _model);

	void Update();
	void Render();
private:
	Model model;
	GLuint program;
	glm::vec3 position, rotation, scale;
};

