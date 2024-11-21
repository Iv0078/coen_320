/*
 * CommunicationSystem.h
 *
 *  Created on: Nov 4, 2024
 *     
 */

#ifndef COMMUNICATIONSYSTEM_H_
#define COMMUNICATIONSYSTEM_H_

#include "Plane.h"

class CommunicationSystem {
public:
	CommunicationSystem();
	virtual ~CommunicationSystem();
	void changeSpeed(Plane& plane, const std::vector<int>& new_speed);
};

#endif /* COMMUNICATIONSYSTEM_H_ */
