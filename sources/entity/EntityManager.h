//
// Created by alki on 21/03/2021.
//

#ifndef ZELDA_ENTITYMANAGER_H
#define ZELDA_ENTITYMANAGER_H

#include <vector>
#include <memory>
#include "Core.h"

class Core::EntityManager {
private:
    std::vector<std::shared_ptr<Core::Entity>> entities_;
    std::vector<unsigned int>                  unused_id_;


public:
    std::vector<std::shared_ptr<Core::Entity>> GetEntities();

    std::shared_ptr<Core::Entity> GetByID(unsigned int);

    Core::Entity &Create();

    void Remove(unsigned int);
};

#endif //ZELDA_ENTITYMANAGER_H
