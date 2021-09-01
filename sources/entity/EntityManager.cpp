//
// Created by alki on 21/03/2021.
//

#include <iostream>
#include <algorithm>
#include <memory>
#include "Entity.h"
#include "EntityManager.h"

struct {
    bool operator()(int i, int j) { return (i < j); }
} objsort;

Core::Entity &Core::EntityManager::Create() {
    if (!this->unused_id_.empty()) {
        unsigned int id = 0;

        std::sort(this->unused_id_.begin(), this->unused_id_.end(), objsort);
        id = this->unused_id_.back();
        this->entities_[this->unused_id_.back()] = std::make_unique<Core::Entity>(id);
        this->unused_id_.pop_back();
        return reinterpret_cast<Core::Entity &>(*this->entities_[id].get());
    }

    unsigned int new_id = this->entities_.size();
    this->entities_.emplace_back(std::make_unique<Core::Entity>(new_id));
    return reinterpret_cast<Core::Entity &>(*this->entities_[new_id].get());
}

void Core::EntityManager::Remove(unsigned int id) {
    try {
        this->entities_.erase(this->entities_.begin() + id);
        this->entities_.insert(this->entities_.begin() + id, std::make_unique<Core::Entity>(id));
        this->unused_id_.emplace_back(id);
    } catch (std::exception &exception) {
        std::cerr << "couldn't remove entity with id " << id << std::endl;
    }
}

std::vector<std::shared_ptr<Core::Entity>> Core::EntityManager::GetEntities() {
    return this->entities_;
}

std::shared_ptr<Core::Entity> Core::EntityManager::GetByID(unsigned int id) {
    return this->entities_[id];
}