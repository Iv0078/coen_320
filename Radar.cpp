/*
 * Radar.cpp
 *
 */

#include "Radar.h"
 //#include <pthread.h>


void updateSinglePlane(Plane& plane,const int& dt) {
	plane.Move(dt);
}


Radar::Radar() :
	x_begining{ 0 }, x_end{ 100000 }, y_begining{ 0 }, y_end{ 100000 }, z_begining{ 15000 }, z_end{ 25000 }{

}



Radar::~Radar() {
	// TODO Auto-generated destructor stub
}



void Radar::checkIfActive(const int& local_time, std::vector<Plane>& active, std::vector<Plane>& waiting) {
	int p_time{ 0 };
	std::vector<Plane>::iterator iter;
	for (iter = waiting.begin(); iter != waiting.end();) {
		if (waiting.at(p_time).getTime() <= local_time) {
			active.push_back(waiting.at(p_time));
			iter = waiting.erase(iter);
		}
		else {
			iter++;
			p_time++;
		}
	}
}

void  Radar::checkIfOutOfBounds(std::vector<Plane>& active) {
	DataDisplay data_display;
	int i{ 0 };
	std::vector<Plane>::iterator iter;
	for (iter = active.begin(); iter != active.end();) {

		if (active.at(i).getPosition().at(0) > x_end || active.at(i).getPosition().at(0) < x_begining ||
			active.at(i).getPosition().at(1) > y_end || active.at(i).getPosition().at(1) < y_begining || 
			active.at(i).getPosition().at(2) > z_end || active.at(i).getPosition().at(2) < z_begining) {
			data_display.printOutOfBounds(active.at(i));
			iter = active.erase(iter);
		}
		else {
			//std::cout << active.at(i).getID() << " " << active.at(i).getPosition().at(0) << " " << active.at(i).getPosition().at(1) << " " << active.at(i).getPosition().at(2) << " \n";
			iter++;
			i++;
		}
	}

}


void Radar::Update(const int& dt, const int& local_time, std::vector<Plane>& active, std::vector<Plane>& waiting) {

	//std::vector<pthread_t> threads;
	for (Plane& plane : active) {
		updateSinglePlane(plane, dt);
	}

	this->checkIfOutOfBounds(active);
	this->checkIfActive(local_time, active, waiting);
}
