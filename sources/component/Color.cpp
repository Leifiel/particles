//
// Created by alki on 21/03/2021.
//

#include "Color.h"

std::type_index Core::Component::Color::GetType() const {
    return this->type_;
}

sf::Color &Core::Component::Color::Get() {
    return color_;
}
