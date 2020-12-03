#ifndef TSTATE_H
#define TSTATE_H

#include <string>
#include <fstream>
#include "state.h"
class tstate
{
private:
	int max_num_ostates;
	int max_num_tstates;
	int num_ostates;
	int num_tstates;
	state* ostates; 
	state_status* tstates;
public:
	tstate(int max_ost,int max_tst);
	~tstate();
	void operator +=(const state& ostate);
	void operator +=(const state_status& ststate);
	friend ostream& operator<<(ostream& stream, const tstate& cstate);
	void read_ostates_from_file(string filename);
	void write_ostates_to_file(string filename);
	void write_ststates_to_file(string filename);
	void Sum(string acontinent);
	void find(string lang);
};
#endif
