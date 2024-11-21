/*
 * DataDisplay.cpp
 *
 */

#include "DataDisplay.h"

DataDisplay::DataDisplay() {
	// TODO Auto-generated constructor stub

}

DataDisplay::~DataDisplay() {
	// TODO Auto-generated destructor stub
}

void DataDisplay::printData(std::vector<std::vector<int>>& data) {

	int i{ 0 };
	for (int x{ 0 }; x <= 100; x++) {
		std::cout << std::string(100, '-') << std::endl;
		for (int z{ 0 }; z <= 25; z++) {
			if ((i) < data.size()) {
				if (data.at(i).at(0) == x && data.at(i).at(1) == z) {
					std::cout << "|" << ((data.at(i).at(2) == 1) ? 'x' : 'o') << "| ";
					i++;
				}
				else {
					std::cout << "|" << " " << "| ";
				}
			}
			else {
				std::cout << "|" << " " << "| ";
			}

		}
		std::cout << "\n";
		std::cout << std::string(100, '-') << std::endl;
	}
	std::cout << "\n\n\n";


}
void printInformation(const std::string& msg) { std::cout << msg << std::endl; }
void DataDisplay::printAllPlanes(const std::vector<Plane>& planes) {

	std::cout << "\n";
	for (const Plane& plane : planes) {
		std::cout << "Plane ID: " << plane.getID() << " ;Position: " << "X position: " << plane.getPosition().at(0) << ",Y position: " << plane.getPosition().at(1) << ",Z position: " << plane.getPosition().at(2);
		std::cout << " ;Speed: " << "X velocity: " << plane.getSpeed().at(0) << ",Y velocity: " << plane.getSpeed().at(1) << ",Z velocity: " << plane.getSpeed().at(2) <<"\n";
	}


}

void  DataDisplay::printPlane(const Plane& plane) {
	std::cout << "\n";
	std::cout << "Plane ID: " << plane.getID() << " ;Position: " << "X position: " << plane.getPosition().at(0) << ",Y position: " << plane.getPosition().at(1) << ",Z position: " << plane.getPosition().at(2);
	std::cout << " ;Speed: " << "X velocity: " << plane.getSpeed().at(0) << ",Y velocity: " << plane.getSpeed().at(1) << ",Z velocity: " << plane.getSpeed().at(2) << "\n";
}

void DataDisplay::printCollisionPlanes(const Plane& plane, const Plane& plane2) {
	std::cout << "Plane: " << plane.getID() << " and Plane: " << plane2.getID() << " are currently in a collision course\n" << std::endl;
}

void DataDisplay::printOutOfBounds(const Plane& plane){
	//std::cout << plane.getID() << " " << plane.getPosition().at(0) << " " << plane.getPosition().at(1) << " " << plane.getPosition().at(2) << " \n";
	std::cout << plane.getID() << " is out of bounds: "<< std::endl;

}