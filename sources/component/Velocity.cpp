//
// Created by alki on 21/03/2021.
//

#include "Velocity.h"

std::type_index Core::Component::Velocity::GetType() const {
    return this->type_;
}

sf::Vector2<float> &Core::Component::Velocity::Get() {
    return this->velocity_;
}