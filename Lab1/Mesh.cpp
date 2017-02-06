#include "Mesh.h"


Mesh::Mesh(Vertex* vertices, unsigned int numVertices)
{
	drawCount = numVertices;
	glGenVertexArrays(1, &vertexArrayObject);
	glBindVertexArray(vertexArrayObject);

	glGenBuffers(NUM_BUFFER, vertexArrayBuffers);
	glBindBuffer(GL_ARRAY_BUFFER, vertexArrayBuffers[POSITION_VERTEXBUFFER]);
	glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(vertices[0]), vertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glBindVertexArray(0);

}


Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &vertexArrayObject);

}

void Mesh::Draw()
{
	glBindVertexArray(vertexArrayObject);
	glDrawArrays(GL_TRIANGLES, 0, drawCount);
	glBindVertexArray(0);

}
