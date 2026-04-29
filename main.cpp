#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
//#include "SearchAlgorithm.h"
#include "CGridtypeMap.h"

int main() {
	std::string filename = "map03.CSV";
	
	/* -= Test 1: Instanziierung eines Objekts vom Typ CGridtypeMap und Einlesen einer Karte aus einer csv-Datei =- */

	CGridtypeMap map;

	int lines = map.importMap(filename);
	std::cout << "WIDTH: " << map.mapWidth() << "\t HEIGHT: " << map.mapHeight() << "\n";
	

	/* -= Test 2: Ausgabe der eingelesenen Karte in der Konsole =- */
	
	system("pause"); // geändert für bash
	map.toConsole(true);
	
	

	/* -= Test 3: Instanziierung eines Objekts vom Typ CMapIterator =- */
	
	system("pause"); //geändert für bash
	CMapIterator it = map.leapIn(GridCoordinate{ 1, 1 });
	std::cout << "\nAktuelle Position des CMapIterator-Objekts: " << it.getPosition() << "\n";
	
	

	/* -= Test 4: Anwendung des Pfadsuchealgorithmus auf die Karte =- */
	/*
	std::vector<GridCoordinate> A;			// In diesem Vektor wird der gefunden Pfad vom Start zum Ziel gespeichert (wenn es einen gibt)
	GridCoordinate start, ziel;
	start.x = 3; 
	start.y = 9;
	ziel.x = 9;
	ziel.y = 4;

	// Aufruf des Pfadsuche-Algorithmus
	int pathLen = depthFirst(it, start, ziel, A);

	// Ausgabe des Pfades in der ausgegebenen Karte
	if (pathLen > 0) {
		std::cout << "\033[" + std::to_string(start.y + 1) + ";" + std::to_string(start.x + 1) + "H" << "\033[31m";
		for (const auto& i : A) {
			std::cout << "\033[" + std::to_string(i.y + 1) + ";" + std::to_string(i.x + 1) + "H" << "o";
		}
		std::cout << "\033[" + std::to_string(map.mapHeight() + 3) + ";0H" << "\033[37m";
	}
	else 
		std::cout << "Es wurde kein Pfad gefunden.\n";
	*/

	return EXIT_SUCCESS;
}