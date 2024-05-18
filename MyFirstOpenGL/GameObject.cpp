#include "GameObject.h"

GameObject::GameObject(GLuint _program, glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale, Model _model, Light _light, int _textureId)
{
	position = _position;
	rotation = _rotation;
	scale = _scale;
	model = _model;
	program = _program;

	textureId = _textureId;
	light = _light;
}

void GameObject::Update()
{
	glUseProgram(program);
	glm::mat4 translationMatrix = GenerateTranslationMatrix(position);
	glm::mat4 rotationMatrix = GenerateRotationMatrix(rotation, rotation.x);
	rotationMatrix *= GenerateRotationMatrix(rotation, rotation.y);
	rotationMatrix *= GenerateRotationMatrix(rotation, rotation.z);
	glm::mat4 scaleMatrix = GenerateScaleMatrix(scale);
	//Asignar valores iniciales al programa
	glUniform2f(glGetUniformLocation(program, "windowSize"), WINDOW_WIDTH, WINDOW_HEIGHT);
	glUniform1i(glGetUniformLocation(program, "textureSampler"), textureId);

	// Pasar las matrices
	glUniformMatrix4fv(glGetUniformLocation(program, "translationMatrix"), 1, GL_FALSE, glm::value_ptr(translationMatrix));
	glUniformMatrix4fv(glGetUniformLocation(program, "rotationMatrix"), 1, GL_FALSE, glm::value_ptr(rotationMatrix));
	glUniformMatrix4fv(glGetUniformLocation(program, "scaleMatrix"), 1, GL_FALSE, glm::value_ptr(scaleMatrix));


	glUniform3f(glGetUniformLocation(program, "ambientLight.color"), light.color.x, light.color.y, light.color.z);
	glUniform1f(glGetUniformLocation(program, "ambientLight.ambientIntensity"), light.ambientIntensity);
}

void GameObject::Render()
{
	//Vinculo su VAO para ser usado
	glBindVertexArray(model.VAO);

	// Dibujamos
	glDrawArrays(GL_TRIANGLES, 0, model.numVertexs);

	//Desvinculamos VAO
	glBindVertexArray(0);
}

glm::mat4 GameObject::GenerateTranslationMatrix(glm::vec3 translation)
{
	return glm::translate(glm::mat4(1.f), translation);
}

glm::mat4 GameObject::GenerateRotationMatrix(glm::vec3 axis, float fDegrees)
{
	return glm::rotate(glm::mat4(1.f), glm::radians(fDegrees), glm::normalize(axis));
}

glm::mat4 GameObject::GenerateScaleMatrix(glm::vec3 _scale)
{
	return glm::scale(glm::mat4(1.f), _scale);
}
