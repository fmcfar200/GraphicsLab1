#pragma once
#include <glm\glm.hpp>
#include <GL\glew.h>
#include <string>
#include <vector>
#include "obj_loader.h"
#include "Transform.h"
class VertexManager //vertex object
{
public:
	VertexManager(const glm::vec3& pos, const glm::vec2& textureCoord, const glm::vec3& normal = glm::vec3(0,0,0)) //constructor
	{
		//sets values to constructor parameters
		this->position = pos;
		this->textureCoord = textureCoord;
		this->norm = normal;

	}

	glm::vec3 position; //v position
	glm::vec2 textureCoord; //texture coordinates
	glm::vec3 norm; //normals
	
	//getters for texCoords, pos and normals
	glm::vec3* GetPosition() { return &position; }
	glm::vec2* GetTextureCoord() { return &textureCoord; }
	glm::vec3* GetNorm() { return &norm; }

protected:
private:
	

};

class MeshManager //mesh object
{
public:
	MeshManager(); //constructor
	~MeshManager(); //destructor
	void DrawMesh(); //draw mesh

	void initialise(VertexManager* vertices, unsigned int numVertices, unsigned int* indices, unsigned int numIndices); //initialise mesh data
	void loadModelFromFile(const std::string& filename); //loads model obj from file
	void initialiseModel(const IndexedModel& model); //initialises model values



private:

	//buffer enums
	enum
	{
		POSITION_VERTEXBUFFER,
		TEXTURECOORDS_VB,
		NORMAL_VB,
		INDEX_VB,
		NUM_BUFFER
	};

	GLuint VAO;	//vertex array objects
	GLuint VABs[NUM_BUFFER];//creates our array of buffers
	unsigned int drawCount; //how much of the vertexArrayObject do we want to draw


};

