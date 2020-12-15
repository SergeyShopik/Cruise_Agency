#include"mainHeader.h"

class completedRout : public Ship, public Rout
{
public:
	completedRout() = default;
	~completedRout() = default;

	string getDepartureDate() const { return departureDate; }
	size_t getTicketsSold() const { return ticketsSold; }

	void setDepartureDate(string dd) { departureDate = dd; }
	void setTicketsSold(size_t ts) { ticketsSold = ts; }

	bool operator==(const completedRout&);

	friend std::ostream& operator<<(std::ostream& out, const completedRout& c);

private:
	string departureDate;
	size_t ticketsSold;
};

std::ostream& operator<<(std::ostream& out, const completedRout& c)
{
	out << "Ship: " << c.getShipName() << " Rout: " << c.getRoutName() << " Departure: " <<
		c.getDepartureDate() << " Tickets sold: " << c.getTicketsSold() << endl;
	return out;
}
