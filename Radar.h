/*
 * Radar.h
 *
 */

#ifndef RADAR_H_
#define RADAR_H_
#include "Plane.h"
#include "DataDisplay.h"
#include <iostream>


class Radar {
public:
	Radar();
	virtual ~Radar();

	void Update(const int& dt,const int& local_time, std::vector<Plane>& active, std::vector<Plane>& waiting);



private:
	void checkIfActive( const int& local_time, std::vector<Plane>& active, std::vector<Plane>& waiting);
	void checkIfOutOfBounds(std::vector<Plane>& active);
	int x_begining, x_end, y_begining, y_end, z_begining, z_end;

};

#endif /* RADAR_H_ */
