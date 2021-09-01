//
// Created by alki on 21/03/2021.
//

#include <memory>
#include "component/IComponent.h"
#include "Entity.h"

Core::Entity::Entity(unsigned int id) : id_(id) {}

void Core::Entity::AddComponent(std::shared_ptr<IComponent> component) {
    this->components_.push_back(std::move(component));
}

unsigned int Core::Entity::GetID() const {
    return this->id_;
}

void Core::Entity::SetID(unsigned int id) {
    this->id_ = id;
}