#pragma once
#include <glm\glm.hpp>
#include <GL\glew.h>
#include "vector"

class Vertex
{
public:
	Vertex(const glm::vec3& pos, const glm::vec2& texCoord)
	{
		this->pos = pos;
		this->texCoord = texCoord;
	}

	glm::vec3 pos;
	glm::vec2 texCoord;

protected:
private:
	
};

class Mesh
{
public:
	Mesh(Vertex* vertices, unsigned int numVertices);
	~Mesh();
	void Draw();

private:

	enum
	{
		POSITION_VERTEXBUFFER,
		TEXCOORD_VB,
		NUM_BUFFER
	};

	GLuint vertexArrayObject;
	GLuint vertexArrayBuffers[NUM_BUFFER];//creates our areray of buffers
	unsigned int drawCount; //how much of the vertexArrayObject do we want to draw




};

