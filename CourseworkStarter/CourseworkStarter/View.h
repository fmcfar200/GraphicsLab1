#pragma once

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <SDL\SDL.h>
#include "Window.h"
using namespace glm;
struct View
{
public:
	View()
	{
		
	};
	void initialiseCamera(const vec3& pos, float fov, float aspect, float nearClip, float farClip)  //all camera values to set to paramter values
	{
		this->position = pos; 
		this->forwardV = vec3(0.0f, 0.0f, 1.0f); 
		this->upV = vec3(0.0f, 1.0f, 0.0f);
		this->projectionMat = perspective(fov, aspect, nearClip, farClip);
		
	}

	void Update(float width, float height) //updates camera projection matrix
	{
		projectionMat = perspective(radians(45.0f),width/height, 0.01f, 1000.0f); //projection matrix is updated
	}

	inline glm::mat4 GetViewProjectionMatrix() const //getter that returns View projection matrix
	{
		return projectionMat * lookAt(position, position + forwardV, upV);
	}

	void MoveForward(float amount) //moves cam forward
	{
		position += forwardV * amount;
	}

	void MoveBackwards(float amount) //moves cam back
	{
		position -= forwardV * amount;
	}

	void MoveRight(float amount) //moves cam right
	{
		position -= cross(upV, forwardV) * amount;
	}

	void MoveLeft(float amount) //moves cam left
	{
		position += cross(upV, forwardV) * amount;
	}

	void MoveMouse()	//moves camera by mouse
	{
		
		GLfloat currentFrame = SDL_GetTicks(); //current frame millseconds
		deltaTime = currentFrame - lastFrame; //delta time is calculated
		lastFrame = currentFrame; //last frame equals current frame

		camSpeed = 1.0f * deltaTime; //camera speed

		int xPos, yPos; //current x and y positions
		SDL_GetGlobalMouseState(&xPos,&yPos); //mouse state is stored in these value variables

		GLfloat xOffset = xPos - lastX; //x Offset of camera
		GLfloat yOffset = lastY - yPos; //y offset of camera
		lastX = xPos; //last x position is equal to current x position
		lastY = yPos; //last y position is equal to current y position

		GLfloat sens = 0.10f; //sensitivy
		//offsets are manipulated by sensitivity value
		xOffset *= sens;
		yOffset *= sens;

		//yaw and pitch is calculated from offset
		yaw += xOffset;
		pitch += yOffset;

		/*
		if (pitch > 89.0f)
		{
			pitch = 89.0f;
		}
		if (pitch < -89.0f)
		{
			pitch = -89.0f;
		}
		*/
		
		vec3 front; //temp forward vector
		front.x = cos(radians(yaw)) * cos(radians(pitch)); //rotation for x y and z
		front.y = sin(radians(pitch));
		front.z = sin(radians(yaw)) * cos(radians(pitch));
		forwardV = normalize(front); //forward vector is set as normalized front vector

		
	}

	glm::vec3 forwardV; //forward vector


private:
	glm::mat4 projectionMat; //prjection matrux
	glm::vec3 position; //camera position
	glm::vec3 upV;	//up vector


	float lastX = 334; //last x
	float lastY = 512;	//last y

	float yaw; //camera yaw
	float pitch;	//camera pitch
	float deltaTime = 0.0f;	//delaTime
	float lastFrame = 0.0f;	//last frame
	float camSpeed = 1.0f;	//camera speed

	Window* display;	//window display pointer
};