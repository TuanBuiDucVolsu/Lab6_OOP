#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class state
{
private :
    string country;
    string capital;
    string government;
    string language;
    string religion;
    string continent;
    float area;
    int population;
public:
    state() : country(""), capital(""), government(""), language(""), religion(""), continent(""), area(0), population(0) {};
    state(string, string, string, string, string, string, float, int);
    string get_continent();
    string get_lang();
    string get_country();
    string get_capital();
    float get_area();
    int get_population();
    friend bool operator ==(state state1,state state2);
    friend ostream& operator<<(ostream& stream, const state& astate);
    friend istream& operator>>(istream& stream, state& astate);
    friend ofstream& operator<<(ofstream& stream, const state& astate);
    friend ifstream& operator>>(ifstream& stream, state& astate);
};
class state_status : public state
{
private:
    string status;
    float GDP;
public:
    state_status() : state(), status(""), GDP(0) {};
    state_status(string, string, string, string, string, string, float, int,string,float);
    friend bool operator ==(state_status state1, state_status state2);
    friend ostream& operator<<(ostream& stream, const state_status& astate);
    friend istream& operator>>(istream& stream, state_status& astate);
    friend ofstream& operator<<(ofstream& stream, const state_status& astate);
    friend ifstream& operator>>(ifstream& stream, state_status& astate);
};
#endif 
