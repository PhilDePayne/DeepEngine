#pragma once

#include "Component.h"
#include <vector>

class GameObject {

public:

	GameObject() {
		//gameObjectPtr tmp_self(this);
		//self = tmp_self;
		//tmp_self.~shared_ptr();
	};
	~GameObject();

	template <typename T>
	void addComponent(gameObjectPtr self) {

		components.push_back(componentPtr(new T(gameObjectPtr(self)))); //TODO: sprawdzi� dobrze, nwm dlaczego to dzia�a, pewnie mo�na pro�ciej

	};

	template <typename T> //TODO: bez ComponentType
	T* getComponent(ComponentType t) {

		for (auto component : components) {

			if (component->isType(t)) return (T*)component.get();

		}

	};

	void test();

private:
	
	std::vector<componentPtr> components;

	//gameObjectPtr self;

};