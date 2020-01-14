#include "playerData.h"

playerData::playerData()
{
	totalDmg = 0;
	relevantDmg = 0;
	numAttacks = 0;
	dmgPerAtk = 0;
	name = "";
}

playerData::playerData(std::string name)
{
	totalDmg = 0;
	relevantDmg = 0;
	numAttacks = 0;
	dmgPerAtk = 0;
	this->name = name;
}

int playerData::getNumAttacks()
{
	return numAttacks;
}

void playerData::setTotDmg(int setVal)
{
	totalDmg = setVal;
}

void playerData::setRelDmg(int setVal)
{
	totalDmg = setVal;
}

void playerData::setName(std::string name)
{
	this->name = name;
}

void playerData::setNumAttacks(int setVal)
{
	this->numAttacks = setVal;
}

void playerData::calcDmgPerAtk()
{
	if (numAttacks != 0)
	{
		double div = totalDmg / numAttacks;
		div = floor(div);
		dmgPerAtk = static_cast<int>(div);
	}
	else
	{
		dmgPerAtk = 0;
	}
}

void playerData::calcRelPercent()
{
	if (totalDmg != 0)
	{
		double percent = static_cast<double>(relevantDmg) / totalDmg * 100;
		percentRel = percent;
	}
	else
	{
		percentRel = 0;
	}
}

void playerData::addTotDmg(int add)
{
	totalDmg += add;
}

void playerData::addRelDmg(int add)
{
	relevantDmg += add;
}

void playerData::print(std::ostream& out, int threshold)
{
	out << std::setw(25) << std::left << this->name;
		
	if (this->numAttacks < threshold - 4)
	{
		out << "-";
	}
	else if (this->numAttacks < threshold)
	{
		out << "*";
	}
	else
	{
		out << " ";
	}

	out << std::setw(19) << this->numAttacks;

	if (this->dmgPerAtk <= 250000)
	{
		out << "*";
	}
	else
	{
		out << " ";
	}

	out	<< std::setw(19) << this->dmgPerAtk
		<< std::setw(20) << std::setprecision(4) << this->percentRel 
		<< std::endl;
}

void playerData::debug(std::ostream& out)
{
	out << "Name " << name << " Total Damage: " << totalDmg << " Relevant Damage: " << relevantDmg 
		<< " Number of Attacks: " << numAttacks << " Damage Per Attack " << dmgPerAtk 
		<< " Percent Relevance: " << percentRel << std::endl;
}