#pragma once

#include "Manager.h"
#include <iostream>
#include <string>

class Core {
private:
	Manager manager;
	std::string version;
	bool run;

public:
	Core(int prio = 3, std::string ver = "unknown");
	Core(int prio, int rcb, int *rcbNum, std::vector<std::string> nm, std::string ver = "unknown");
	~Core();

	bool initial(int rcb, int * rcbResNum, std::vector<std::string> nm);

	int begin();

	int createPcb(int prio = 1, std::string nm = "Unknown");

	bool deletePcbByPid(int pid);

	bool deletePcbByName(std::string nm);

	void addRcb(std::string nm = "Unknown", int rcbResNum = 1);

	bool requestRcb(int rid, int num = 1);
	bool requestRcb(std::string nm, int num = 1);

	bool releaseRcb(int rid);
	bool releaseRcb(std::string nm);

	int suspendCore();

	std::vector<PcbInfo> getTotalPcbInfo();
	std::vector<RcbInfo> getTotalRcbInfo();

	int timeOut();

	void exit();

	std::string getVersion();

	bool isRunning();

};
