#pragma once
#include <vector>
#include <fstream>
#include <string>
#include <cstring>
#include <algorithm>
#include "Pathfinder.h"

class CGridtypeMap
{
private:
	std::vector<std::vector<GridTile>> map;
public:
	CGridtypeMap() { };

	// reads in a new map
	int importMap(const std::string& fileName) 
	{
		std::ifstream f(fileName);
		if (f.fail()) return 0;

		// clear pervious map
		map.clear();

		char bfr[1024];
		rsize_t bfrmax = sizeof bfr;
		char* token, next_token;
		int line = 0;
		const char* delim = ",;.-";				// ,;.- accepted as delimiter
		while (f.getline(bfr, sizeof bfr)) {
			std::vector<GridTile> v;
			map.push_back(v);				// add empty vector<GridTile>
			token = std::strtok(bfr, delim);		
			while (token != NULL) {
				if (std::isdigit(*token))
					map[line].push_back(GridTile{ TileType::trail, std::stoi(token) });
				else
					map[line].push_back(GridTile{ TileType::obstacle, -1 });

				token = strtok(NULL, delim);
			}
			line++;
		}

		return line;
	}

	void toConsole(bool hideCosts)
	{
		system("cls");
		for (const auto& i : map) {
			for (const auto& j : i) {
				if (j.type == TileType::obstacle) std::cout << char(219);
				else {
					if (hideCosts) std::cout << " ";
					else std::cout << j.cost;
				}
			}
			std::cout << "\n";
		}
	}
};

