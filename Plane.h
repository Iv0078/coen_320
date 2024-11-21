/*
 * Plane.h
 *
 */

#ifndef PLANE_H_
#define PLANE_H_
#include <vector>


class Plane {
public:
	Plane();
	Plane(const int& time, const int& id, const int& FL, const std::vector<int>& position,
		const std::vector<int>& speed);
	virtual ~Plane();

	std::vector<int> getPosition() const;
	void Move(const int& dt);

	char getPlane();
	void changePlaneStatus(const bool& collision_detected);

	int getTime() const;
	int getID() const;

	std::vector<int> getSpeed() const;
	void setSpeed(const std::vector<int>& speed);

	int getFL()const;
	void setFL(const int& fl);


private:
	int time;
	int id;
	int FL;
	std::vector<int> position, speed;
	char plane;

};

#endif /* PLANE_H_ */
