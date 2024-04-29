#pragma once
#include <GL/glew.h>
#include <stb_image.h>
#include <string>

class Texture
{
public:
	void InitTexture(const char* path);
	void LoadTexture();

private:
	int width, height, nrChanels;
	unsigned char* textureInfo;
	GLuint textureID;
};

