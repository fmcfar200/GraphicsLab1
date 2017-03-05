#pragma once
#include <glm\glm.hpp>
#include <GL\glew.h>
#include <string>

class Vertex
{
public:
	Vertex(const glm::vec3& pos)
	{
		this->position = pos;
	}
protected:
private:
	glm::vec3 position;
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
		NUM_BUFFER
	};

	GLuint VAO;
	GLuint VABs[NUM_BUFFER];//creates our areray of buffers
	unsigned int drawCount; //how much of the vertexArrayObject do we want to draw


};

