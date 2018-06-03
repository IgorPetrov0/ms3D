#ifndef GAMEWORLD_H
#define GAMEWORLD_H


#include <vector>
#include "gameobject.h"
#include "gamesector.h"

class gameWorld
{
public:
    gameWorld();

protected:
    std::vector<gameObject*>content;
    std::vector<gameSector*>sectors;



};

#endif // GAMEWORLD_H
