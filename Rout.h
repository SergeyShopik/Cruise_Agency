#include"mainHeader.h"

class Rout
{
public:
	Rout() = default;
	~Rout() = default;

	string getRoutName() const { return name; }
	size_t getDays() const { return days; }
	double getMileage() const { return mileage; }
	size_t getNumOfStops() const { return numOfStops; }
	double getTicketCost() const { return ticketCost; }

	void setRoutName(string n) { name = n; }
	void setTicketCost(double tc) { ticketCost = tc; }

	friend std::istream& operator>>(std::istream& in, Rout& rout);
	friend std::ostream& operator<<(std::ostream& out, const Rout& r);

private:
	string name;
	size_t days;
	double mileage;
	size_t numOfStops;
	double ticketCost;
};

std::istream& operator>>(std::istream& in, Rout& rout)
{
	in >> rout.name >> rout.days >> rout.mileage >> rout.numOfStops >> rout.ticketCost;
	return in;
}
std::ostream& operator<<(std::ostream& out, const Rout& r)
{
	out << " Name: " << r.getRoutName() << " Days: " << r.getDays() << " Mileage: " << r.getMileage()
		<< " Number of stops: " << r.getNumOfStops() << " Ticket cost: " << r.getTicketCost() << endl;
	return out;
}