#include <iostream>
#include "Program.h"
#include "DataDisplay.h"
#include <csignal>
#include <ctime>
#include <thread>
#include <chrono>
#include < windows.h >



Program* prog;




int main() {
	Plane plane1(0, 1, 0, { 0,5000,20000 }, { 500,0,0 });
	Plane plane2(0, 2, 0, { 5000,1000,20000 }, { -500,0,0 });
	//Plane plane2(0,2,0,{100000,100000,15000},{-500,-500,0});
	std::vector<Plane> planes;
	planes.push_back(plane1);
	planes.push_back(plane2);
	prog = new Program(0, planes);


	

	while (true) {
		

		(*prog).Update(1);
	
		
	}











	return 0;
}


// operator consoel called => sring used for command -> program executes string either by using comm system or data display or both