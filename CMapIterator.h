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
    CMapIterator(std::vector<std::vector<GridTile>>& m) : map(m)
    {
        posInternal.x = -1;
        posInternal.y = -1;
        lastPos = posInternal;
    };

    GridCoordinate getPosition(){
        return posInternal;
    };

    bool jumpToPosition(const GridCoordinate &position){
        if(position.y > map.size() || position.y < 0) return false;
        if(position.x > map.at(position.y).size() || position.x < 0) return false;
        
        GridTile tile = map.at(position.y).at(position.x);

        if(tile.type != TileType::trail) return false;

        lastPos = posInternal;
        posInternal.x = position.x;
        posInternal.y = position.y;

        return true;
    };
    void moveBack(){
        posInternal = lastPos;
    };
    bool moveNorth(){
        GridCoordinate tmpPos = posInternal;
        tmpPos.y -= 1;
        return jumpToPosition(tmpPos);
    };
    bool moveSouth(){
        GridCoordinate tmpPos = posInternal;
        tmpPos.y += 1;
        return jumpToPosition(tmpPos);
    };
    bool moveWest(){
        GridCoordinate tmpPos = posInternal;
        tmpPos.x -= 1;
        return jumpToPosition(tmpPos);
    };
    bool moveEast(){
        GridCoordinate tmpPos = posInternal;
        tmpPos.x += 1;
        return jumpToPosition(tmpPos);
    };
};
