//
// Created by alki on 21/03/2021.
//

#ifndef ZELDA_POSITION_H
#define ZELDA_POSITION_H

#include <SFML/Graphics.hpp>
#include <typeindex>
#include "Core.h"
#include "IComponent.h"

class Core::Component::Position : public IComponent {
    std::type_index    type_     = typeid(*this);
    sf::Vector2<float> position_ = {0, 0};

public:
    explicit Position(sf::Vector2<float> pos) : position_(pos) {}

    std::type_index GetType() const override;
    sf::Vector2<float> &Get();
};


#endif //ZELDA_POSITION_H
