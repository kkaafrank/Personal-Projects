#include "playerData.h"
#include <vector>
#include <algorithm>

struct armorDamageData
{
	int headArmor;
	int torsoArmor;
	int leftArmArmor;
	int leftHandArmor;
	int rightArmArmor;
	int rightHandArmor;
	int leftLegArmor;
	int rightLegArmor;

	void print(std::ostream& out)
	{
		out << headArmor << " " << torsoArmor << " "
			<< leftArmArmor << " " << leftHandArmor << " "
			<< rightArmArmor << " " << rightHandArmor << " "
			<< rightLegArmor << " " << leftLegArmor << std::endl;
	}
};

int calcMohaca(armorDamageData damage)
{
	int relDamage = 0;

	relDamage += damage.headArmor;
	relDamage += damage.leftArmArmor;
	relDamage += damage.leftHandArmor;
	relDamage += damage.rightArmArmor;
	relDamage += damage.rightHandArmor;
	relDamage += damage.leftLegArmor;
	relDamage += damage.rightLegArmor;

	return relDamage;
}

int calcSterl(armorDamageData damage)
{
	int relDamage = 0;

	relDamage += damage.headArmor;
	relDamage += damage.torsoArmor;
	relDamage += damage.rightLegArmor;
	relDamage += damage.rightHandArmor;

	return relDamage;
}

int calcTerro(armorDamageData damage)
{
	int relDamage = 0;

	relDamage += damage.headArmor;
	relDamage += damage.torsoArmor;
	relDamage += damage.rightLegArmor;

	return relDamage;
}

int calcJukk(armorDamageData damage)
{
	int relDamage = 0;

	relDamage += damage.headArmor;
	relDamage += damage.torsoArmor;
	relDamage += damage.leftArmArmor;
	relDamage += damage.leftHandArmor;
	relDamage += damage.rightArmArmor;
	relDamage += damage.rightHandArmor;

	return relDamage;
}

int calcLojak(armorDamageData damage)
{
	int relDamage = 0;

	relDamage += damage.headArmor;
	relDamage += damage.torsoArmor;
	relDamage += damage.leftHandArmor;
	relDamage += damage.rightArmArmor;
	relDamage += damage.rightHandArmor;
	relDamage += damage.leftLegArmor;
	relDamage += damage.rightLegArmor;

	return relDamage;
}

int calcTakedar(armorDamageData damage)
{
	int relDamage = 0;

	relDamage += damage.headArmor;
	relDamage += damage.torsoArmor;
	relDamage += damage.leftArmArmor;
	relDamage += damage.leftHandArmor;
	relDamage += damage.rightArmArmor;
	relDamage += damage.rightHandArmor;
	relDamage += damage.leftLegArmor;
	relDamage += damage.rightLegArmor;

	return relDamage;
}

int main()
{
	////prompts for the name of the raid distribution file (not being used currently)
	//std::cout << "Enter File Name: ";
	//std::string fileName;
	//std::cin >> fileName;
	//std::ifstream input(fileName);

	//uses the default name of the raid distribution file
	std::ifstream input("raid.txt");
	
	//list of players in the clan
	std::vector<playerData> list;

	//sends the first line to the trash
	std::string trash;
	std::getline(input, trash);

	//sets the delimiter used in the raid distribution file
	std::string curr;
	char delimiter = ',';

	//creates a separate input stream specifically to find the number of titans in the raid
	//std::ifstream numTitanInput(fileName);
	std::ifstream numTitanInput("raid.txt");

	//sends the first line to the trash
	std::getline(numTitanInput, trash);

	//creates the variables used to find the number of titans
	int trailingNumTitans = 0;
	int numTitans = 0;
	bool lastTitanFound = true;


	while (lastTitanFound)
	{
		//deletes the player name
		std::getline(numTitanInput, trash, delimiter);

		//deletes the player id
		std::getline(numTitanInput, trash, delimiter);

		//deletes the number of attacks the player did	
		std::getline(numTitanInput, trash, delimiter);

		//keeps the number of the titan
		std::getline(numTitanInput, curr, delimiter);
		trailingNumTitans = numTitans;
		numTitans = stoi(curr);

		//deletes the name of the titan
		std::string titanName;
		std::getline(numTitanInput, titanName, delimiter);

		//deletes the damage dealt
		std::getline(numTitanInput, trash, delimiter);

		//deletes the damage to armor, body, and skeleton
		for (int i = 0; i < 23; i++)
		{
			std::getline(numTitanInput, trash, delimiter);
		}

		//goes to the next line
		std::getline(numTitanInput, trash);

		//loop exit condition
		if (numTitans == 0 && trailingNumTitans != 0)
		{
			lastTitanFound = false;
		}
	}

	while (!(input.eof()))
	{
		//creates player object
		std::getline(input, curr, delimiter);
		playerData player(curr);

		//adds up the raid damage
		for (int i = 0; i <= trailingNumTitans; i++)
		{
			armorDamageData damage;

			//deletes the player name on iterations past the first
			if (i > 0)
			{
				std::getline(input, trash, delimiter);
			}

			//deletes the player id
			std::getline(input, trash, delimiter);

			//gets and assigns the number of attacks the player did	
			std::getline(input, curr, delimiter);
			player.setNumAttacks(stoi(curr));

			//deletes the number of the titan
			std::getline(input, trash, delimiter);

			//gets the name of the titan to determine relevant damage
			std::string titanName;
			std::getline(input, titanName, delimiter);

			//adds to the total damage dealt
			std::getline(input, curr, delimiter);
			player.addTotDmg(stoi(curr));

			//get the damage to armor
			std::getline(input, curr, delimiter);
			damage.headArmor = stoi(curr);

			std::getline(input, curr, delimiter);
			damage.torsoArmor = stoi(curr);

			std::getline(input, curr, delimiter);
			damage.leftArmArmor = stoi(curr);

			std::getline(input, curr, delimiter);
			damage.rightArmArmor = stoi(curr);

			std::getline(input, curr, delimiter);
			damage.leftHandArmor = stoi(curr);

			std::getline(input, curr, delimiter);
			damage.rightHandArmor = stoi(curr);

			std::getline(input, curr, delimiter);
			damage.leftLegArmor = stoi(curr);

			std::getline(input, curr, delimiter);
			damage.rightLegArmor = stoi(curr);

			//gets damage to the body
			for (int i = 0; i < 8; i++)
			{
				std::getline(input, curr, delimiter);
				player.addRelDmg(stoi(curr));
			}

			//ignores damage to the skeleton
			for (int i = 0; i < 7; i++)
			{
				std::getline(input, trash, delimiter);
			}

			//goes to the next line
			std::getline(input, trash);

			//calculates the relevant armor damage based
			// on which titan it is
			if (titanName == "Mohaca the Gale")
			{
				player.addRelDmg(calcMohaca(damage));
			}
			else if (titanName == "Sterl the Unmaker")
			{
				player.addRelDmg(calcSterl(damage));
			}
			else if (titanName == "Terro the Seeker")
			{
				player.addRelDmg(calcTerro(damage));
			}
			else if (titanName == "Lojak the Fissure")
			{
				player.addRelDmg(calcLojak(damage));
			}
			else if (titanName == "Jukk the Overseer")
			{
				player.addRelDmg(calcJukk(damage));
			}
			else
			{
				player.addRelDmg(calcTakedar(damage));
			}
		}

		//calculates the damage per attack and the amount of
		// relevant damage the player dealt and adds the player
		// to the list
		player.calcDmgPerAtk();
		player.calcRelPercent();
		list.push_back(player);
	}

	//opens the output file
	std::ofstream outputFile;
	outputFile.open("report.xml");

	//outputs the overhead needed for the xml file
	outputFile << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << std::endl
		<< "<raid xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xsi:noNamespaceSchemaLocation=\"./raidFormat.xsd\">" << std::endl
		<< "<players>" << std::endl;


	//finds the max number of attacks a player made
	int maxAttacks = -1;
	for (playerData player : list)
	{
		maxAttacks = std::max(maxAttacks, player.getNumAttacks());
	}

	//calculates the threshold depending on how many attack cycles
	// there were
	int threshold = 0;
	if (maxAttacks > 24)
	{
		threshold = 20;
	}
	else if (maxAttacks > 20)
	{
		threshold = 16;
	}
	else if (maxAttacks > 16)
	{
		threshold = 12;
	}
	else if (maxAttacks > 12)
	{
		threshold = 8;
	}
	else if (maxAttacks > 8)
	{
		threshold = 4;
	}
	else
	{}

	//prints the list to the output file
	for (playerData player : list)
	{
		player.print(outputFile, threshold);
	}

	//closes the tags in the xml file
	outputFile << "</players>" << std::endl
		<< "</raid>";

	//closes the input and output files
	input.close();
	outputFile.close();

	//tell the system that it has completed everything successfully
	std::cout << "Sucessfully output to report.txt" << std::endl;

	return 0;
}