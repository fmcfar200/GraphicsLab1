#pragma once
#include <glm\glm.hpp>
#include <GL\glew.h>
#include <string>
#include <vector>

class Vertex
{
public:
	Vertex(const glm::vec3& pos, const glm::vec2& textureCoord)
	{
		this->position = pos;
		this->textureCoord = textureCoord;

	}

	glm::vec3 position;
	glm::vec2 textureCoord;

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
		TEXTURECOORDS_VB,
		NUM_BUFFER
	};

	GLuint VAO;
	GLuint VABs[NUM_BUFFER];//creates our areray of buffers
	unsigned int drawCount; //how much of the vertexArrayObject do we want to draw


};

