#pragma once
#include <GL/glew.h>
#include <gtc/matrix_transform.hpp>
#include <stb_image.h>
#include <fstream>
#include <vector>
#include <sstream>

#include "Model.h"

class ModelManager
{
private:

public:
	std::vector<Model> models;




	static Model LoadOBJModel(const std::string& filePath);



};

