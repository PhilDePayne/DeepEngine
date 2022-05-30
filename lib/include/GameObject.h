#pragma once

#include "Component.h"
#include <vector>

class GameObject {

public:

	GameObject() {};
	~GameObject();

	template <typename T>
	void addComponent(gameObjectPtr self) {

		components.push_back(componentPtr(new T(gameObjectPtr(self)))); //TODO: sprawdzi� dobrze, nwm dlaczego to dzia�a, pewnie mo�na pro�ciej

	};

	void addComponent(componentPtr component, gameObjectPtr self) {

		component->parent = self;
		components.push_back(component);

	};

	template <typename T> //TODO: bez ComponentType, mo�e z castem
	T* getComponent(ComponentType t) {

		for (auto component : components) {

			if (component->isType(t)) return (T*)component.get();

		}

	};

	void test();

private:
	
	std::vector<componentPtr> components;

};