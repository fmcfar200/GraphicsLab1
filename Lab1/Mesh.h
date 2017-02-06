#pragma once
#include <glm\glm.hpp>
#include <GL\glew.h>

class Vertex
{
public:
	Vertex(const glm::vec3& pos)
	{
		this->pos = pos;
	}
protected:
private:
	glm::vec3 pos;
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

	GLuint vertexArrayObject;
	GLuint vertexArrayBuffers[NUM_BUFFER];//creates our areray of buffers
	unsigned int drawCount; //how much of the vertexArrayObject do we want to draw


};

