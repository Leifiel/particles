//
// Created by alki on 21/03/2021.
//

#ifndef ZELDA_VELOCITY_H
#define ZELDA_VELOCITY_H

#include <typeindex>
#include <SFML/System/Vector2.hpp>
#include "Core.h"
#include "IComponent.h"

class Core::Component::Velocity : public IComponent {
    std::type_index    type_     = typeid(*this);
    sf::Vector2<float> velocity_ = {0, 0};

public:
    explicit Velocity(sf::Vector2<float> vel) : velocity_(vel) {}

    std::type_index GetType() const;
    sf::Vector2<float> &Get();
};


#endif //ZELDA_VELOCITY_H
