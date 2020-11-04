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
	out << "<player>" << std::endl
			<< "<Username>" << this->name << "</Username>" << std::endl
			<< "<Number_of_Attacks>" << this->numAttacks << "</Number_of_Attacks>" << std::endl
			<< "<Damage_per_Attack>" << this->dmgPerAtk << "</Damage_per_Attack>" << std::endl
			<< "<Percent_Relevance>" << std::setprecision(4) << this->percentRel << "</Percent_Relevance>" << std::endl
		<< "</player>" << std::endl;

}

void playerData::debug(std::ostream& out)
{
	out << "Name " << name << " Total Damage: " << totalDmg << " Relevant Damage: " << relevantDmg 
		<< " Number of Attacks: " << numAttacks << " Damage Per Attack " << dmgPerAtk 
		<< " Percent Relevance: " << percentRel << std::endl;
}