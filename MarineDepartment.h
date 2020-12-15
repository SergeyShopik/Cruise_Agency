#include"mainHeader.h"

class MarineDepartment
{
public:
	MarineDepartment() = default;
	~MarineDepartment() = default;

	void readShips(std::istream&);
	void readRouts(std::istream&);
	void addCompletedRout(string);
	void printShips(std::ostream& out);
	void printRouts(std::ostream& out);
	void printCompletedRouts(std::ostream& out);
	void findInfo(string);

private:
	vector<Ship> ships;
	vector<Rout> routs;
	vector<completedRout> completedRouts;
};

void MarineDepartment::readShips(std::istream& in)
{
	while (!in.eof())
	{
		Ship tempShip;
		in >> tempShip;
		ships.push_back(tempShip);
	}
}
void MarineDepartment::readRouts(std::istream& in)
{
	while (!in.eof())
	{
		Rout tempRout;
		in >> tempRout;
		routs.push_back(tempRout);
	}
}
void MarineDepartment::addCompletedRout(string name)
{
	auto it = std::find_if(routs.begin(), routs.end(), [name](const Rout& r)
		{
			return name == r.getRoutName();
		});
	if (it == routs.end())
	{
		std::cerr << "rout not found.\n";
		return;
	}
	completedRout temp;
	temp.setTicketCost(it->getTicketCost());
	temp.setRoutName(it->getRoutName());

goAgain:
	cout << "Enter num of ship needed:\n";

	int counter = 0;
	std::for_each(ships.begin(), ships.end(), [&counter](Ship b)
		{
			cout << counter++ << " " << b << "\n";
		});

	cin >> counter;

	temp.setLicencse(ships[counter].getLicense());

	string strD;
	size_t numTicketsSold;

	cout << "Enter departure and num of tickets sold:\n";
	cin >> strD >> numTicketsSold;
	if (numTicketsSold > maxPsngs)
	{
		cout << "Too many tickets sold.\n";
		goto goAgain;
	}
	temp.setDepartureDate(strD);
	temp.setTicketsSold(numTicketsSold);

	completedRouts.push_back(temp);
}
void MarineDepartment::findInfo(string str)
{
	cout << "Rout: ";
	std::copy_if(routs.begin(), routs.end(), std::ostream_iterator<Rout>(cout, "\n"), [str](Rout& r)
		{
			return str == r.getRoutName();
		});
	cout << "\nShips completed the rout:\n";
	vector<Ship> ship1;
	ship1 = this->ships;
	std::for_each(completedRouts.begin(), completedRouts.end(), [ship1, str](completedRout& temp)
		{
			if (temp.getRoutName() == str)
			{
				string lic = temp.getLicense();
				std::copy_if(ship1.begin(), ship1.end(), std::ostream_iterator<Ship>(cout, "\n"),
					[lic](Ship b)
					{
						return lic == b.getLicense();
					});
			}
		});
}

void MarineDepartment::printShips(std::ostream& out)
{
	std::copy(ships.begin(), ships.end(), std::ostream_iterator<Ship>(cout, "\n"));
}
void MarineDepartment::printRouts(std::ostream& out)
{
	std::copy(routs.begin(), routs.end(), std::ostream_iterator<Rout>(cout, "\n"));
}
void MarineDepartment::printCompletedRouts(std::ostream& out)
{
	std::copy(completedRouts.begin(), completedRouts.end(), std::ostream_iterator<completedRout>(cout, "\n"));
}
