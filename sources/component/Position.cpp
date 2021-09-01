//
// Created by alki on 21/03/2021.
//

#include "Position.h"

std::type_index Core::Component::Position::GetType() const {
    return this->type_;
}

sf::Vector2<float> &Core::Component::Position::Get() {
    return this->position_;
}
