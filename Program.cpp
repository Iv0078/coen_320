/*
 * Program.cpp
 *
 */

#include "Program.h"


bool sortcol1(const std::vector<int>& v1, const std::vector<int>& v2) {
	return v1[1] < v2[1];
}
bool sortcol2(const std::vector<int>& v1, const std::vector<int>& v2) {
	return v1[0] < v2[0];
}


int getPositionDifference(const int& a, const int& b) {
	int difference = {a-b};
	if (difference < 0) {
		difference = -1 * difference;
	}
	return difference;
}

void collisionResolution(Plane& plane, const Plane& secondary_plane, const int& lane_detected) {
	int z_change{ 250 };
	CommunicationSystem communication_system;
	std::vector<int> vel = plane.getSpeed();
	int z_diff{ plane.getPosition().at(2) - secondary_plane.getPosition().at(2) };
	if (secondary_plane.getFL() == 0) {
		plane.setFL(1);
		if (z_diff >= 0) {
			vel.at(2) = z_change;
			communication_system.changeSpeed(plane, vel);
		}
		else {
			z_change = -1 * z_change;
			vel.at(2) = z_change;
			communication_system.changeSpeed(plane, vel);
		}
	}
	else {
		if (secondary_plane.getSpeed().at(2) >= 0) {
			z_change = -1 * z_change;
			vel.at(2) = z_change;
			communication_system.changeSpeed(plane, vel);
		}
		else {
			vel.at(2) = z_change;
			communication_system.changeSpeed(plane, vel);
		}
	}
	plane.setFL(1);
}

void checkForCollision(Plane& plane, const int& index, const std::vector<Plane>& planes) {
	bool collision_detected{ false };
	int secondary_plane_index{ 0 };
	int lane_detected{ -1 }; // 0 - x , 1 - y

	for (int i{}; i < planes.size(); i++) {
		if (i != index) {
			int z_diff{ getPositionDifference(plane.getPosition().at(2),planes.at(i).getPosition().at(2)) };
			if (z_diff <= 1000) {
				int x_diff{ getPositionDifference(plane.getPosition().at(0),planes.at(i).getPosition().at(0)) };
				if (x_diff <= 3000) {
					secondary_plane_index = i;
					collision_detected = true;
					lane_detected = 0;
					break;
				}
				int y_diff{ getPositionDifference(plane.getPosition().at(1),planes.at(i).getPosition().at(1)) };
				if (y_diff <= 3000) {
					secondary_plane_index = i;
					collision_detected = true;
					lane_detected = 1;
					break;
				}
			}

		}
	}

	plane.changePlaneStatus(collision_detected);
	if (collision_detected) {
		DataDisplay data_display;
		data_display.printCollisionPlanes(plane, planes.at(secondary_plane_index));
		if (plane.getFL() == 0) {
			collisionResolution(plane, planes.at(secondary_plane_index), lane_detected);
		}

	}

	if (!collision_detected && plane.getFL() != 0) {
		CommunicationSystem communication_system;
		std::vector<int> vel = plane.getSpeed();
		vel.at(2) = 0;
		communication_system.changeSpeed(plane, vel);
		plane.setFL(0);
	}




}







int Program::getPlaneIndex(const int& id) {
	for (int i{}; i < active_planes.size(); i++) {
		if (active_planes.at(i).getID() == id) {
			return i;
		}
	}
	std::cout << "Plane not found!\n";
	return -1;
}

void Program::executePollingServer() {
	for (int i{}; i < polling_server.size(); i++) {
		if (polling_server.at(i).at(0) == 0) {
			data_display.printAllPlanes(active_planes);
		}
		else if (polling_server.at(i).at(0) == 1) {
			int index = this->getPlaneIndex(polling_server.at(i).at(1));
			if (index != -1) {
				data_display.printPlane(active_planes.at(index));
			}

		}
		else if (polling_server.at(i).at(0) == 2) {
			int index = this->getPlaneIndex(polling_server.at(i).at(1));
			if (index != -1) {
				std::cout << "Original values: \n";
				data_display.printPlane(active_planes.at(index));
				std::vector<int> new_speed = polling_server.at(i);
				new_speed.erase(new_speed.begin(), new_speed.begin() + 1);
				communication_system.changeSpeed(active_planes.at(index), new_speed);
				std::cout << "Changed values: \n";
				data_display.printPlane(active_planes.at(index));
			}
		}
	}

	polling_server.clear();

}


Program::Program(const int& time, const std::vector<Plane>& planes) :
 limit{ 3000,3000,1500 }, local_time{ time }
{
	for (int i{ 0 }; i < planes.size(); i++) {
		if ((planes.at(i)).getTime() <= time) {
			active_planes.push_back(planes.at(i));
		}
		else {
			que_planes.push_back(planes.at(i));
		}
	}
	//std::cout << active_planes.size() << " " << que_planes.size() << " " << std::endl;

}

Program::~Program() {
	// TODO Auto-generated destructor stub
}

void Program::Update(const int& dt) {
	local_time += dt;
	radar.Update(dt, local_time, active_planes, que_planes);
	if (local_time % 30 == 0) {
		this->saveData();
	}
	this->Draw();
	this->executePollingServer();

	for (int i{}; i < active_planes.size(); i++) {
		checkForCollision(active_planes.at(i), i, active_planes);
	}

}


void Program::Draw() {
	std::vector<std::vector<int>> display_vect;
	for (Plane& plane : active_planes) {
		int x = plane.getPosition().at(0) / 1000;
		int z = (plane.getPosition().at(2) -15000)/ 400;
		int symbol = (plane.getPlane() == 'x') ? 1 : 0;
		//std::vector<int> vect {};
		display_vect.push_back({ x,z,symbol });
	}
	sort(display_vect.begin(), display_vect.end(), sortcol1);
	sort(display_vect.begin(), display_vect.end(), sortcol2);
	data_display.printData(display_vect);

	//data_display.printAllPlanes(active_planes);
}
void Program::commandTerminal() {
	polling_server.push_back(operator_console.operatorCommand());

}
void Program::saveData() {

}
