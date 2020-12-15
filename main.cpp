#include"mainHeader.h"

int main()
{
	MarineDepartment md;

	std::ifstream inShip("ships.txt");
	std::ifstream inRout("routs.txt");

	md.readShips(inShip);
	md.readRouts(inRout);

	/*while (cin)
	{
		string str;
		cout << "Enter rout: ";
		cin >> str;
		md.addCompletedRout(str);
	}*/
	
	//md.addCompletedRout("Pacific");
	md.findInfo("Atlantic");

	return 0;
}