#ifndef PLAYERDATA_H_
#define PLAYERDATA_H_
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

class playerData
{
public:
	//constructors
	playerData();
	playerData(std::string name);

	//getter methods
	int getNumAttacks();

	//setter methods
	void setTotDmg(int setVal);
	void setRelDmg(int setVal);
	void setName(std::string name);
	void setNumAttacks(int setVal);
	void calcDmgPerAtk();
	void calcRelPercent();

	//mutator methods
	void addTotDmg(int add);
	void addRelDmg(int add);

	//print method
	void print(std::ostream& out, int maxAttacks);

	void debug(std::ostream& out);

private:
	int totalDmg;
	int relevantDmg;
	int numAttacks;
	int dmgPerAtk;
	double percentRel;
	std::string name;
};

#endif // !PLAYERDATA_H_
