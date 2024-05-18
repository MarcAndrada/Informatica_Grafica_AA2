#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm.hpp>
#include <gtc/type_ptr.hpp>
#include <gtc/matrix_transform.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <stb_image.h>

#include "ModelManager.h"
#include "Texture.h"
#include "ProgramManager.h"
#include "GLManager.h"
#include "Camera.h"
#include "GameObjectManager.h"
#include "TextureManager.h"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

void main() {

	GLM.Init();

	TEXTURES.InitTextures();

	//Inicializamos GLEW y controlamos errores
	if (glewInit() == GLEW_OK) {

		//Declarar instancia de camara
		Camera camera;

		//Compilar shaders
		PROGRAMS.Compile();

		//Cargamos los modelos
		MODELS.LoadAllModels();

		//Inicializamos todos los gameobjects del juego
		GAME_OBJECTS.InitializeGameObjects();

		//Activamos el Depth test con lo que arreglamos el Z Fighting
		glEnable(GL_DEPTH_TEST);  

		//Load Texture
		TEXTURES.LoadTextures();

		//Definimos color para limpiar el buffer de color
		glClearColor(0.f, 0.992f, 1.f, 1.f);

		//Definimos modo de dibujo para cada cara
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

		//Generamos el game loop
		while (GLM.IsRunnig()) {

			//Pulleamos los eventos (botones, teclas, mouse...)
			glfwPollEvents();

			//Limpiamos los buffers
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

			GAME_OBJECTS.GameObjectsUpdate();

			// Controlador de la camara
			camera.UpdateCamera();


			GLM.ChangeBuffers();
		}

		//Eliminar programa
		PROGRAMS.DeletePrograms();

	}
	else {
		std::cout << "Ha petao." << std::endl;
		glfwTerminate();
	}

	//Finalizamos GLFW
	glfwTerminate();

}