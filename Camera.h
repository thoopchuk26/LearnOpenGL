#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <vector>

enum cameraMovement {
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT
};

class Camera {
public:
	// camera Attributes
	glm::vec3 Position = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 Up;
	glm::vec3 Front = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 Right;
	glm::vec3 WorldUp = glm::vec3(0.0f, 1.0f, 0.0f);
	//default camera variables
	float Yaw = -90.0f;
	float Pitch = 0.0f;
	float Speed = 5.0f;
	float Sensitivity = 0.1f;
	float Zoom = 45.0f;

	Camera(glm::vec3 position);
	// returns the view matrix calculated using Euler Angles and the LookAt Matrix
	glm::mat4 getViewMatrix();
	void processMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch);
	void processKeyboard(cameraMovement direction, float deltaTime);
	void processMouseScroll(float yoffset);

private:
	void updateCameraVectors();
};