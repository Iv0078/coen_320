/*
 * CommunicationSystem.cpp
 *
 *  Created on: Nov 4, 2024
 *    
 */

#include "CommunicationSystem.h"

CommunicationSystem::CommunicationSystem() {
	// TODO Auto-generated constructor stub

}

CommunicationSystem::~CommunicationSystem() {
	// TODO Auto-generated destructor stub
}

void CommunicationSystem::changeSpeed(Plane& plane,const std::vector<int>& new_speed) {
	plane.setSpeed(new_speed);
}