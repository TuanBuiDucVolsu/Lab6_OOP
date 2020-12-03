#include<iostream>
#include"tstate.h"
using namespace std;

tstate::tstate(int max_ost, int max_tst)
{
	max_num_ostates = max_ost;
	max_num_tstates = max_tst;
	ostates = new state[max_num_ostates];
	tstates = new state_status[max_num_tstates];
	num_ostates = 0;
	num_tstates = 0;
	cout << "\n selected objects (for original editions) - " << max_num_ostates;
	cout << "\n selected objects(For states with status updates) - " << max_num_tstates;
	cout << "\n loaded states (original) - " << num_ostates;
	cout << "\n loaded states (update) - " << num_tstates;
}

tstate::~tstate()
{
	cout << "\nDestructor of tstate class called:";
	max_num_ostates = 0;
	delete[] ostates;
	num_ostates = 0;
	max_num_tstates = 0;
	delete[] tstates;
	num_tstates = 0;
	cout << "\n allocated memory is freed";
}

void tstate::operator+=(const state& ostate)
{
	if (num_ostates < max_num_ostates)
	{
		ostates[num_ostates] = ostate;
		num_ostates++;
	}
}
void tstate::operator+=(const state_status& tstate)
{
	if (num_tstates < max_num_tstates)
	{
		tstates[num_tstates] = tstate;
		num_tstates++;
	}
}

ostream& operator<<(ostream& stream, const tstate& astste)
{
	stream << "\n\n\nFULL RANGE OF TSTATE:\n";
	stream << "\n A) Original editions\n";
	for (int i = 0; i < astste.num_ostates; i++)
	{
		stream << "------------------------------\n";
		stream << astste.ostates[i] << endl;
	}
	stream << "\n B) Updated status\n";
	for (int i = 0; i < astste.num_tstates; i++)
	{
		stream << "------------------------------\n";
		stream << astste.tstates[i] << endl;
	}
	return stream;
}

void tstate::read_ostates_from_file(string filename)
{
	ifstream infile;
	infile.open(filename);
	if (!infile.is_open())
	{
		cout << "\n\nFile not found!\n";
		system("pause");
		exit(1);
	}
	int N;
	infile >> N;
	infile.get();
	for (int i = 0; i < N; i++)
	{
		state new_state;
		infile >> new_state;
		this->operator+=(new_state);
	}
	infile.close();
	cout << "\n Loaded data from file " << filename << ":";
	cout << "\n number of loaded state - " << num_ostates << endl;
}

void tstate::write_ostates_to_file(string filename)
{
	ofstream outfile;
	outfile.open(filename);
	outfile << num_ostates << endl;
	for (int i = 0; i < num_ostates; i++)
		outfile << ostates[i];
	outfile.close();
	cout << "\nData written to file  " << filename << ":";
	cout << "\n number of written state - " << num_ostates;
}

void tstate::write_ststates_to_file(string filename)
{
	ofstream outfile;
	outfile.open(filename);
	outfile << num_tstates << endl;
	for (int i = 0; i < num_tstates; i++)
		outfile << tstates[i];
	outfile.close();
	cout << "\nData written to file " << filename << ":";
	cout << "\n number of written updated status state -  " << num_tstates;
}

void tstate::Sum(string acontinent)
{
	cout << "\n+Enter the continent : " << acontinent;
	float sumarea = 0;
	int sumpop = 0;
	for (int i = 0; i < num_ostates; i++)
	{
		if (ostates[i].get_continent() == acontinent)
		{
			sumarea += ostates[i].get_area();
			sumpop += ostates[i].get_population();
		}
	}
	cout << "\nSum area : " << sumarea << endl;
	cout << "Sum population : " << sumpop << endl;

}

void tstate::find(string lang)
{
	int max = ostates[0].get_population();
	int j = 0;
	for (int i = 1; i <= num_ostates; i++)
	{
		if (ostates[i].get_lang() == lang)
		{
			if (max < ostates[i].get_population())
			{
				max = ostates[i].get_population();
				j = i;
			}
		}
	}
	cout << "\nName and capital of the largest state in terms of population :" << endl;
	cout << "Country : " << ostates[j].get_country() << endl;
	cout << "Capital : " << ostates[j].get_capital() << endl;
}