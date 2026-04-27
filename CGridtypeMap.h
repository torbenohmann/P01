#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include "Pathfinder.h"
#include "CMapIterator.h"

using namespace std;


class CGridtypeMap{
    private:
        vector<vector<GridTile>> map;
        CMapIterator it;
    public:
        CGridtypeMap() : it(map) { 
            map = {};
        };
        unsigned int mapWidth(){
            int maxWidth = 0;
            for(int i = 0;i<map.size();i++){
                if(maxWidth < map.at(i).size()) maxWidth = map.at(i).size();
            }
            return maxWidth;
        }

        unsigned int mapHeight(){
            return map.size();
        }

        int importMap(const string& filename){
            ifstream csvFile(filename);
            if(csvFile.fail()) return 0;

            map.clear();
            
            string line;
            while (getline(csvFile, line)) {
                map.push_back({});
                for(char& c : line){
                    if(c == '*'){
                        map.back().push_back({TileType::obstacle,0});
                    }else if (c>= '1' && c<= '9'){
                        map.back().push_back({TileType::trail,c-'1'+1});
                    }        
                }
            }
            return map.size();
        }

        void toConsole(bool displayCost){
            system("clear");
            for(auto& line : map){
                for(auto& tile : line){
                    if(tile.type == TileType::obstacle) cout << "#";
                    else if (tile.type == TileType::trail) cout << (displayCost ? to_string(tile.cost) : " ");
                }
                cout << endl;
            }
        }

        CMapIterator& leapIn(const GridCoordinate& coords){
            it.jumpToPosition(coords);
            return it;
        };
};