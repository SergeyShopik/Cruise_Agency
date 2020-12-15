#include"mainHeader.h"

constexpr size_t maxPsngs = 200;

class Ship
{
public:
	Ship() = default;
	~Ship() = default;

	string getShipName() const { return name; }
	string getLicense() const { return license; }
	size_t getRelease() const { return release; }
	size_t getLifeCycle() const { return lifeCycle; }
	size_t getCrew() const { return crew; }
	//double getTicketCost() const { return ticketCost; }

	//void setTicketCost(double _cost) { ticketCost = _cost; }
	void setLicencse(string l) { license = l; }

	const bool operator==(const Ship&) const;

	friend std::istream& operator>>(std::istream& in, Ship& ship);
	friend std::ostream& operator<<(std::ostream& out, const Ship& ship);


private:
	string name;
	string license;
	size_t release;
	size_t lifeCycle;
	size_t crew;
	//double ticketCost;
};

std::istream& operator>>(std::istream& in, Ship& ship)
{
	in >> ship.name >> ship.license >> ship.release >> ship.lifeCycle
		>> ship.crew; //>> ship.ticketCost;
	return in;
}
std::ostream& operator<<(std::ostream& out, const Ship& ship)
{
	out << "Name: " << ship.getShipName() << " License: " << ship.getLicense() << " Release: " <<
		ship.getRelease() << " Life cycle: " << ship.getLifeCycle() << " Crew: " << ship.getCrew() <<
		" Ticket cost: " /*<< ship.getTicketCost()*/ << endl;
	return out;
}