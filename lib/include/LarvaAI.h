#pragma once

#include "AI.h"
#include "SphereCollider.h"
#include "typedefs.h"

class LarvaAI : public AI {

public:
	LarvaAI() {};
	LarvaAI(gameObjectPtr parent) : AI(parent) {};
	~LarvaAI() {};

	void onCollisionEnter(BoxCollider collided) override;
	void onTriggerEnter(BoxCollider collided) override;
	void update(GLFWwindow* window, float deltaTime) override;

	std::vector<glm::vec3>* lights;
	std::vector<gameObjectPtr>* larvas;

private:

	bool active = false;
	float speed = 30.0f;
	

};