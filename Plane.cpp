/*
 * Plane.cpp
 *
 */

#include "Plane.h"


Plane::Plane() :
	id{ -1 }, FL{ -1 }, position{ -1,-1,-1 }, speed{ -1,-1,-1 }, time{ 99999 }, plane{ 'x' }{}

Plane::Plane(const int& time, const int& id, const int& FL, const std::vector<int>& position,
	const std::vector<int>& speed) : time{ time }, id{ id }, FL{ FL }, position{ position }, speed{ speed }, plane{ 'o' }
{}

Plane::~Plane() {
	// TODO Auto-generated destructor stub
}

void Plane::Move(const int& dt) {
	for (int i{ 0 }; i < position.size(); i++) {
		position.at(i) = position.at(i) + dt * (speed.at(i));
	}


}

int Plane::getTime()const { return time; }

void Plane::setSpeed(const std::vector<int>& speed) {
	this->speed = speed;
}
char Plane::getPlane() { return plane; }
void Plane::changePlaneStatus(const bool& collision_detected) {
	if (collision_detected && plane == 'o') {
		plane = 'x';
	}
	else if(!collision_detected && plane =='x'){
		plane = 'o';
	}
}

int Plane::getID()const { return id; }

std::vector<int> Plane::getPosition() const  { return position; }
std::vector<int> Plane::getSpeed() const  { return speed; }


 int Plane::getFL()const {
	return this->FL;
}
void Plane::setFL(const int& fl) {
	this->FL = fl;
}
