#include <vector>
#include "Pathfinder.h"
#include <iostream>
#include <fstream>
#include <string>

std::vector<std::vector<GridTile>> map;

int importMap_Vorbereitung(std::string path){
    std::ifstream csvFile(path);
    if(csvFile.fail()) return 0;
    map.clear();
    std::string line;
    while (std::getline(csvFile, line)) {
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

int main(){
    int readLines = importMap_Vorbereitung("map03.CSV");
    std::cout << "Read Lines: " << readLines << std::endl;
    for(auto& line : map){
        for(auto& tile : line){
            switch (tile.type)
            {
            case TileType::obstacle :
                std::cout << '*'<< "  ";
                break;
            case TileType::trail :
                std::cout << tile.cost << "  ";
                break;
            default:
                std::cout << '?'<< "  ";
            }
        }
        std::cout << std::endl;
    }
    return 0;

}