#pragma once
#include <vector>
#include <string>
#include <Pathfinder.h>
#include <CMapIterator.h>
using namespace std;


class CGridtypeMap{
    private:
        vector<vector<GridTile>> map;
        CMapIterator it;
    public:
        unsigned int mapWidth();
        unsigned int mapHeight();
        int importMap(const string& filename);
        void toConsole(bool);
        CMapIterator& leapIn(const GridCoordinate& coords);
};