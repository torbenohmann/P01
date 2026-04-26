#pragma once

#include "Pathfinder.h"
#include "CMapIterator.h"
#include <vector>
#include <algorithm>

int depthFirst(CMapIterator& it, const GridCoordinate A, const GridCoordinate B, std::vector<GridCoordinate>& Aset)
{
	// step 1: init
	if (!it.jumpToPosition(B)) return -1;		// B is not reachable
	if (!it.jumpToPosition(A)) return -1;		// A is not reachable
	std::vector<GridCoordinate> Mset;			// set of marked nodes
	Mset.push_back(A);
	Aset.clear();
	Aset.push_back(A);

	while (it.getPosition() != B) {
		// step 2: search
		bool stepDone = false;
		for (int i = 0; i < 4 && !stepDone; i++) {
			switch (i) {
				case 0: stepDone = it.moveNorth(); break;
				case 1: stepDone = it.moveEast(); break;
				case 2: stepDone = it.moveSouth(); break;
				case 3: stepDone = it.moveWest();
			}
			
			if (stepDone) {
				// New node is marked already 
				if (std::find(Mset.begin(), Mset.end(), it.getPosition()) != Mset.end()) {
					stepDone = false;
					it.moveBack();
				}
				// New node is not in the set of marked nodes
				else {
					Mset.push_back(it.getPosition());
					Aset.push_back(it.getPosition());
				}
			}
		}

		// There is no step to an unmarked node
		if (!stepDone) {
			Aset.pop_back();
			if (Aset.size() > 0)
				it.jumpToPosition(Aset.back());
			else
				return 0;
		}
	}
	return Aset.size();
}