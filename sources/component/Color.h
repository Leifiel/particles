//
// Created by alki on 21/03/2021.
//

#ifndef ZELDA_COLOR_H
#define ZELDA_COLOR_H

#include <SFML/Graphics.hpp>
#include "Core.h"
#include "IComponent.h"

class Core::Component::Color : public IComponent {
    std::type_index type_  = typeid(*this);
    sf::Color       color_ = {0, 0, 0, 255};

public:
    explicit Color(sf::Color color) : color_(color) {}

    std::type_index GetType() const override;
    sf::Color &Get();
};


#endif //ZELDA_COLOR_H
