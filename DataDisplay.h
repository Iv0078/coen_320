/*
 * DataDisplay.h
 *
 */

#ifndef SRC_DATADISPLAY_H_
#define SRC_DATADISPLAY_H_
#include <vector>
#include <string>
#include <iostream>
#include "Plane.h"

class DataDisplay {
public:
	DataDisplay();
	virtual ~DataDisplay();

	void printData(std::vector<std::vector<int>>& data);
	void printInformation(const std::string& msg);
	void printAllPlanes(const std::vector<Plane>& planes);
	void printPlane(const Plane& plane);
	void printCollisionPlanes(const Plane& plane, const Plane& plane2);
	void printOutOfBounds(const Plane& plane);

};

#endif /* SRC_DATADISPLAY_H_ */
