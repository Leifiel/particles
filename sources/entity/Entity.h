//
// Created by alki on 21/03/2021.
//

#ifndef ZELDA_ENTITY_H
#define ZELDA_ENTITY_H

#include <vector>
#include <memory>
#include <exception>
#include "Core.h"
#include "component/IComponent.h"

class Core::Entity {
    unsigned int                             id_;
    std::vector<std::shared_ptr<IComponent>> components_;

public:
    explicit Entity(unsigned int);
    ~Entity() = default;
    Entity(const Entity &) = delete;
    Entity &operator=(const Entity &) = delete;

    template<typename T>
    T &GetComponent() {
        for (auto &component : this->components_)
            if (component->GetType() == typeid(T))
                return reinterpret_cast<T &>(*component);
        // TODO: Create custom error type and throw exception
    }

    void AddComponent(std::shared_ptr<IComponent> component);
    unsigned int GetID() const;
    void SetID(unsigned int id);
};
#endif //ZELDA_ENTITY_H
