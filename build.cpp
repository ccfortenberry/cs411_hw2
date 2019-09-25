/*******************************
*	Curtis Fortenberry
*	build.cpp
*	CS411 - Christopher Hartman
*	hw2
*	last rev: 24-9-2019
*******************************/
#include "build.h"

//vector included
using std::vector;
/* #include <iostream>
using std::cout;
using std::endl; */

// See function info in header
int build(int w, int e, const vector<Bridge> & bridges) {
	// Generate the set of all possible subsets
	// ie. a Power Set
	
	vector<vector<Bridge>> pSet;
	vector<Bridge> nullSet;
	pSet.push_back(nullSet);
	
	for (unsigned int i=0; i < bridges.size(); i++) {
		vector<vector<Bridge>> subset = pSet;
		
		for (unsigned int j=0; j < subset.size(); j++) 
			subset[j].push_back(bridges[i]);
		
		for (unsigned int j=0; j < subset.size(); j++) 
			pSet.push_back(subset[j]);
	}
	
	// Debug output to check if power sets are generating properly
	/* if (pSet.size() < 80) {
		for (auto i=0; i < pSet.size(); i++) {
			for (auto j=0; j < pSet[i].size(); j++)
				cout << "(" << pSet[i][j][0] << "," << pSet[i][j][1] << "," << pSet[i][j][2] << ")";
			cout << endl;
		}
	} */
	
	// Constraints:
	// no city can have more than one bridge reaching it
	// no bridges can cross
	// ---- ie. a-b and c-d, if a<c and b>d then crosses
	
	int maxtoll = 0;
	
	for (auto i=0; i < pSet.size(); i++) {
		int toll = 0;
		bool cross = false;
		bool multi = false;
		
		for (auto j=0; j < pSet[i].size(); j++) {
			for (auto k=0; k < pSet[i].size(); k++) {
				// Check for crossing bridges
				if ((pSet[i][k][0] < pSet[i][j][0]) && (pSet[i][k][1] > pSet[i][j][1])) {
					cross = true;
					break;
				}
				// Check to see if any cities have >1 bridges
				if (((pSet[i][k][0] == pSet[i][j][0]) && (pSet[i][k][1] != pSet[i][j][1])) || 
				((pSet[i][k][0] != pSet[i][j][0]) && (pSet[i][k][1] == pSet[i][j][1]) || 
				((j != k) && (pSet[i][k][0] == pSet[i][j][0]) && (pSet[i][k][1] == pSet[i][j][1])))) {
					multi = true;
					break;
				}
			}
			// Leave if constraints are not met
			if (cross) break;
			if (multi) break;
			
			// Increment total toll if constraints are met
			toll += pSet[i][j][2];
		}
		
		// If the calculated toll is >maxtoll set it as new max
		if (!cross && !multi && toll > maxtoll) maxtoll = toll;
	}
	
	return maxtoll;
}