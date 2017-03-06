#include "Mesh.h"

Mesh::Mesh(Vertex * vertices, unsigned int numVertices)
{
	std::vector<glm::vec3> positions; //holds the position data
	std::vector<glm::vec2> textureCoords; //holds the texture coordinate data

	positions.reserve(numVertices);
	textureCoords.reserve(numVertices);

	for (int i = 0; i < numVertices; i++)
	{
		positions.push_back(vertices[i].position);
		textureCoords.push_back(vertices[i].textureCoord);
	}

	drawCount = numVertices;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(NUM_BUFFER, VABs);
	glBindBuffer(GL_ARRAY_BUFFER, VABs[POSITION_VERTEXBUFFER]);
	glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(positions[0]), &positions[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	
	glBindBuffer(GL_ARRAY_BUFFER, VABs[TEXTURECOORDS_VB]);
	glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(textureCoords[0]), &textureCoords[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

	glBindVertexArray(0); //unbind VAO
}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &VAO);
}

void Mesh::Draw()
{
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, drawCount);
	glBindVertexArray(0);

}
