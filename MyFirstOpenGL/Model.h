#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <GL/glew.h>

#include <gtc/matrix_transform.hpp>
#include <stb_image.h>
#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>

class Model {
public:
    Model(const std::vector<float>& vertexs, const std::vector<float>& uvs, const std::vector<float>& normals);
    void Render() const;
    GLuint VAO, VBO, uvVBO;

    unsigned int numVertexs;

private:
};

#endif
