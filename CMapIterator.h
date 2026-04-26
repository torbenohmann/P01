#pragma once
#include <vector>
#include "Pathfinder.h"

class CMapIterator
{
private:
    GridCoordinate posInternal;
    GridCoordinate lastPos;
    std::vector<std::vector<GridTile>> &map;

public:
    CMapIterator(std::vector<std::vector<GridTile>> &map);

    GridCoordinate getPosition();
    bool jumpToPosition(const GridCoordinate &position);
    void moveBack();
    bool moveNorth();
    bool moveSouth();
    bool moveWest();
    bool moveEast();
};
