#ifndef BUILD_HPP_INCLUDED
#define BUILD_HPP_INCLUDED

/*******************************
*	Curtis Fortenberry
*	build.h
*	CS411 - Christopher Hartman
*	hw2
*	last rev: 24-9-2019
*******************************/

/*************************************************************
*	Desc:
	Find an optimal solution via Brute-Force/Exhaustive Search
	
*	Problem:
	Cities exist on either side of a river (w, e) and we wish
	to build bridges across the river such that we get the
	maximal amount of toll from people crossing them.
*************************************************************/

#include <vector> //std::vector
using Bridge = std::vector<int>;

/***************************************************************
*	func Build
*	Given the number of cities on the west bank (w :- int) and
	east bank (e :- int) and the plans for bridges between them
	(bridges :- std::vector< std::vector<int> > by const ref), 
	brute force the optimal solution.
*	Output: maxtoll :- int
***************************************************************/
int build(int, int, const std::vector<Bridge>&);

#endif //BUILD_HPP_INCLUDED