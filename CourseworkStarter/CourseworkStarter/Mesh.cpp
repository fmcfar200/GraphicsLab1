#include "Mesh.h"


Mesh::Mesh()
{
	/*
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
	*/
}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &VAO);
}

void Mesh::initialise(Vertex * vertices, unsigned int numVertices, unsigned int * indices, unsigned int numIndices)
{
	IndexedModel mod;

	for (unsigned int i = 0; i < numVertices; i++)
	{
		mod.positions.push_back(*vertices[i].GetPosition());
		mod.texCoords.push_back(*vertices[i].GetTextureCoord());
		mod.normals.push_back(*vertices[i].GetNorm());
	}

	for (unsigned int i = 0; i < numIndices; i++)
		mod.indices.push_back(indices[i]);

	initialiseModel(mod);

}

void Mesh::loadModelFromFile(const std::string & filename)
{
	IndexedModel mod = OBJModel(filename).ToIndexedModel();
	initialiseModel(mod);

}

void Mesh::initialiseModel(const IndexedModel & model)
{
	drawCount = model.indices.size();

	glGenVertexArrays(1, &VAO); //generate a vertex array and store it in the VAO
	glBindVertexArray(VAO); //bind the VAO (any operation that works on a VAO will work on our bound VAO - binding)

	glGenBuffers(NUM_BUFFER, VABs); //generate our buffers based of our array of data/buffers - GLuint vertexArrayBuffers[NUM_BUFFERS];

	glBindBuffer(GL_ARRAY_BUFFER, VABs[POSITION_VERTEXBUFFER]); //tell opengl what type of data the buffer is (GL_ARRAY_BUFFER), and pass the data
	glBufferData(GL_ARRAY_BUFFER, model.positions.size() * sizeof(model.positions[0]), &model.positions[0], GL_STATIC_DRAW); //move the data to the GPU - type of data, size of data, starting address (pointer) of data, where do we store the data on the GPU (determined by type)
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, VABs[TEXTURECOORDS_VB]); //tell opengl what type of data the buffer is (GL_ARRAY_BUFFER), and pass the data
	glBufferData(GL_ARRAY_BUFFER, model.positions.size() * sizeof(model.texCoords[0]), &model.texCoords[0], GL_STATIC_DRAW); //move the data to the GPU - type of data, size of data, starting address (pointer) of data, where do we store the data on the GPU
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, VABs[NORMAL_VB]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(model.normals[0]) * model.normals.size(), &model.normals[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, VABs[INDEX_VB]); //tell opengl what type of data the buffer is (GL_ARRAY_BUFFER), and pass the data
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, model.indices.size() * sizeof(model.indices[0]), &model.indices[0], GL_STATIC_DRAW); //move the data to the GPU - type of data, size of data, starting address (pointer) of data, where do we store the data on the GPU

	glBindVertexArray(0); // unbind our VAO
}

void Mesh::DrawMesh()
{
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, drawCount);
	glBindVertexArray(0);

}
