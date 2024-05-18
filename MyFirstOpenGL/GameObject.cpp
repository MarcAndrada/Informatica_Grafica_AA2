#include "GameObject.h"

GameObject::GameObject(GLuint _program, glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale, Model _model)
{
	position = _position;
	rotation = _rotation;
	scale = _scale;
	model = _model;
	program = _program;
}

void GameObject::Update()
{
	glUseProgram(program);
	glm::mat4 translationMatrix = MatrixUtilities::GenerateTranslationMatrix(position);
	glm::mat4 rotationMatrix = MatrixUtilities::GenerateRotationMatrix(rotation, rotation.x);
	rotationMatrix *= MatrixUtilities::GenerateRotationMatrix(rotation, rotation.y);
	rotationMatrix *= MatrixUtilities::GenerateRotationMatrix(rotation, rotation.z);
	glm::mat4 scaleMatrix = MatrixUtilities::GenerateScaleMatrix(scale);
	//Asignar valores iniciales al programa
	glUniform2f(glGetUniformLocation(program, "windowSize"), WINDOW_WIDTH, WINDOW_HEIGHT);
	// Pasar las matrices
	glUniformMatrix4fv(glGetUniformLocation(program, "translationMatrix"), 1, GL_FALSE, glm::value_ptr(translationMatrix));
	glUniformMatrix4fv(glGetUniformLocation(program, "rotationMatrix"), 1, GL_FALSE, glm::value_ptr(rotationMatrix));
	glUniformMatrix4fv(glGetUniformLocation(program, "scaleMatrix"), 1, GL_FALSE, glm::value_ptr(scaleMatrix));
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
