//
// Created by alki on 21/03/2021.
//

#ifndef ZELDA_ICOMPONENT_H
#define ZELDA_ICOMPONENT_H

#include <typeindex>

class IComponent {
public:
    virtual ~IComponent() = default;
    virtual std::type_index GetType() const = 0;
};

#endif //ZELDA_ICOMPONENT_H
