/*
 * Program.h
 *
 */

#ifndef PROGRAM_H_
#define PROGRAM_H_
#include "Plane.h"
#include "Radar.h"
#include "DataDisplay.h"
#include "CommunicationSystem.h"
#include "OperatorConsole.h"
#include <algorithm>
#include <string>

class Program {
public:
	Program(const int& time, const std::vector<Plane>& planes);
	virtual ~Program();

	void Update(const int& dt);
	void commandTerminal();
	void Draw();
	void saveData();


private:

	int getPlaneIndex(const int& id);
	void executePollingServer();

	Radar radar;
	DataDisplay data_display;
	CommunicationSystem communication_system;
	OperatorConsole operator_console;

	std::vector<Plane> active_planes;
	std::vector<Plane> que_planes;
	std::vector<int> limit;
	int local_time;
	std::vector<std::vector<int>> polling_server;


};



#endif /* PROGRAM_H_ */
