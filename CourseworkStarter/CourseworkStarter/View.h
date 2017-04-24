#pragma once

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <SDL\SDL.h>

using namespace glm;
struct View
{
public:
	View()
	{
		
	};
	void initialiseCamera(const glm::vec3& pos, float fov, float aspect, float nearClip, float farClip)
	{
		this->position = pos;
		this->forward = glm::vec3(0.0f, 0.0f, 1.0f);
		this->up = glm::vec3(0.0f, 1.0f, 0.0f);
		this->projectionMat = glm::perspective(fov, aspect, nearClip, farClip);
		
	}

	inline glm::mat4 GetViewProjectionMatrix() const
	{
		return projectionMat * glm::lookAt(position, position + forward, up);
	}

	void MoveForward(float amount)
	{
		position += forward * amount;
	}

	void MoveBackwards(float amount)
	{
		position -= forward * amount;
	}

	void MoveRight(float amount)
	{
		position -= glm::cross(up, forward) * amount;
	}

	void MoveLeft(float amount)
	{
		position += glm::cross(up, forward) * amount;
	}

	void MoveMouse()
	{
		GLfloat currentFrame = SDL_GetTicks();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		camSpeed = 1.0f * deltaTime;

		int xPos, yPos;
		SDL_GetGlobalMouseState(&xPos,&yPos);

		GLfloat xOffset = xPos - lastX;
		GLfloat yOffset = lastY - yPos;
		lastX = xPos;
		lastY = yPos;

		GLfloat sens = 0.20f;
		xOffset *= sens;
		yOffset *= sens;

		yaw += xOffset;
		pitch += yOffset;

		if (pitch > 89.0f)
		{
			pitch = 89.0f;
		}
		if (pitch < -89.0f)
		{
			pitch = -89.0f;
		}
		
		vec3 front;
		front.x = cos(radians(yaw)) * cos(radians(pitch));
		front.y = sin(radians(pitch));
		front.z = sin(radians(yaw)) * cos(radians(pitch));
		forward = normalize(front);

		
		
	}

private:
	glm::mat4 projectionMat;
	glm::vec3 position;
	glm::vec3 forward;
	glm::vec3 up;


	float lastX = 334;
	float lastY = 512;

	float yaw;
	float pitch;
	float deltaTime = 0.0f;
	float lastFrame = 0.0f;
	float camSpeed = 1.0f;

};