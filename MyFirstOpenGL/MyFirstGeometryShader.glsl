#version 440 core

layout (triangles) in;
layout (triangle_strip, max_vertices = 3) out;

uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

in vec2 uvsGeometryShader[];
out vec2 uvsFragmentShader;

void main(){

	for(int i = 0; i < gl_in.length(); i++){
		gl_Position = projectionMatrix * viewMatrix * gl_in[i].gl_Position;
		uvsFragmentShader = uvsGeometryShader[i];
		EmitVertex();
	}

	EndPrimitive();
}