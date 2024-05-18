#pragma once

#include "Model.h"
#include "Transform.h"
#include "GLManager.h"


class GameObject
{
public:
	GameObject(GLuint _program, glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale, Model _model, int _textureId);

	void Update();
	void Render();
private:
	Model model;
	GLuint program;
	glm::vec3 position, rotation, scale;
	int textureId;


	glm::mat4 GenerateTranslationMatrix(glm::vec3 translation);
	glm::mat4 GenerateRotationMatrix(glm::vec3 axis, float fDegrees);
	glm::mat4 GenerateScaleMatrix(glm::vec3 _scale);
};

