#include "state.h"
#include<iostream>
using namespace std;

state::state(string cou, string cap, string gov, string lag, string rel, string con, float are, int pop)
{
	country = cou;
	capital = cap;
	government = gov;
	language = lag;
	religion = rel;
	continent = con;
	area = are;
	population = pop;
	cout << "\nClass constructor called state";
}
string state::get_continent()
{
	return continent;
}
string state::get_lang()
{
	return language;

}
string state::get_country()
{
	return country;
}
string state::get_capital()
{
	return capital;
}
float state::get_area()
{
	return area;
}
int state::get_population()
{
	return population;
}

bool operator ==(state state1, state state2)
{
	if (state1.country != state2.country) return false;
	if (state1.capital != state2.capital) return false;
	if (state1.government != state2.government) return false;
	if (state1.language != state2.language) return false;
	if (state1.religion != state2.religion) return false;
	if (state1.continent != state2.continent) return false;
	if (state1.area != state2.area) return false;
	if (state1.population != state2.population) return false;
	return true;
}
ostream& operator<<(ostream& stream, const state& astate)
{
	stream << "Country: " << astate.country << endl;
	stream << "Capital: " << astate.capital << endl;
	stream << "Government : " << astate.government << endl;
	stream << "Language : " << astate.language << endl;
	stream << "Religion : " << astate.religion << endl;
	stream << "Continent : " << astate.continent << endl;
	stream << "Area : " << astate.area << endl;
	stream << "Population : " << astate.population << endl;
	return stream;
}
istream& operator>>(istream& stream, state& astate)
{
	getline(stream, astate.country);
	getline(stream, astate.capital);
	getline(stream, astate.government);
	getline(stream, astate.language);
	getline(stream, astate.religion);
	getline(stream, astate.continent);
	stream >> astate.area;
	stream >> astate.population;
	stream.get();
	return stream;
}

ofstream& operator<<(ofstream& stream, const state& astate)
{
	stream << astate.country << endl;
	stream << astate.capital << endl;
	stream << astate.government << endl;
	stream << astate.language << endl;
	stream << astate.religion << endl;
	stream << astate.continent << endl;
	stream << astate.area << endl;
	stream << astate.population << endl;
	return stream;
}

ifstream& operator>>(ifstream& stream, state& astate)
{

	getline(stream, astate.country);
	getline(stream, astate.capital);
	getline(stream, astate.government);
	getline(stream, astate.language);
	getline(stream, astate.religion);
	getline(stream, astate.continent);
	stream >> astate.area;
	stream >> astate.population;
	stream.get();
	return stream;
}

state_status::state_status(string cou, string cap, string gov, string lag, string rel, string con, float are, int pop, string sta, float G) :
	state(cou, cap, gov, lag, rel, con, are, pop), status(sta), GDP(G)
{
	cout << "\nClass constructor called state_status";
}

bool operator ==(state_status state1, state_status state2)
{
	bool are_equal_states = static_cast<state>(state1) == static_cast<state>(state2);
	bool are_equal_status = state1.status == state2.status;
	bool are_equal_GDP = state1.GDP == state2.GDP;
	if (are_equal_states && are_equal_status && are_equal_GDP)
		return true;
	return false;
}

ostream& operator<<(ostream& stream, const state_status& zstate)
{
	stream << static_cast<state>(zstate);
	stream << "Status: " << zstate.status << endl;
	stream << "GDP : " << zstate.GDP << endl;
	return stream;
}

istream& operator>>(istream& stream, state_status& zstate)
{
	//stream >> static_cast<state>(zstate);
	getline(stream, zstate.status);
	stream >> zstate.GDP;
	return stream;
}

ofstream& operator<<(ofstream& stream, const state_status& zstate)
{
	stream << static_cast<state>(zstate);
	stream << zstate.status << endl;
	stream << zstate.GDP << endl;
	return stream;
}

ifstream& operator>>(ifstream& stream, state_status& zstate)
{
	//stream >> static_cast<state>(zstate);
	getline(stream, zstate.status);
	stream >> zstate.GDP;
	return stream;
}

