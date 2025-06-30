#include <bits/stdc++.h>

using namespace std;

#define NUMBER_OF_TESTS 50

#define MOD 1e9

mt19937 myrand(22635753012);

string ins = "./tests/test.00.in";
string outs = "./tests/test.00.sol";

fstream in;
ofstream out;
	

int n[NUMBER_OF_TESTS + 1] = {0, 6, 13, 25, 146, 636, 856, 1824, 3295, 4252, 7646,
						  7276, 8756, 9747, 9463, 9774, 36586, 57587, 67747, 73764, 87584,
						  102394, 121104, 132495, 150395, 157934, 160395, 169483, 175396, 185497, 194962,
						  202394, 201104, 202495, 210395, 217934, 220395, 239483, 235396, 245497, 248954,
						  249603, 250140, 257944, 259025, 260491, 264934, 268395, 269483, 275396, 285497};
int m[NUMBER_OF_TESTS + 1] = {0, 13, 25, 36, 89, 213, 547, 983, 1235, 1842, 2398, 
							3401, 4556, 5678, 6984, 7123, 71246, 76253, 80934, 85649, 90201,
							95123, 100642, 106914, 112078, 117320, 123905, 129654, 135256, 141788, 144595,
							203428, 209716, 216467, 223192, 230931, 237523, 244082, 251491, 258214, 261950,
							264587, 271914, 271934, 275971, 278324, 282941, 284096, 289312, 296268, 299586};


void rename(int idx)
{
	ins[13] = '0' + idx / 10;
	ins[14] = '0' + idx % 10;
	outs[13] = '0' + idx / 10;
	outs[14] = '0' + idx % 10;
}

long long generate_in(long long l, long long r)
{
	return myrand() % (r - l + 1) + l;
}

void generate_input(int idx)
{
	cout << idx << endl;
	set<pair<int, int> > points;
	
	in << n[idx] << " " << m[idx] << endl;
	
	long long x, y;
	
	for(int i = 0; i < n[idx]; i++)
	{
		x = generate_in(1, 2 * MOD / n[idx]);
		y = generate_in(1, MOD);
		in << x << " " << y << endl;
	}
	
	for(int i = 0; i < m[idx]; i++)
	{
		do
		{
			x = generate_in(0, MOD);
			y = generate_in(0, MOD);
		}
		while(points.count({x, y}));
		points.insert({x ,y});
		in << x << " " << y << endl;
	}
	
	return;
}

int main()
{
	for(int i = 1; i <= NUMBER_OF_TESTS; i++)
	{
		rename(i);
		in.open (ins, fstream::out);
		out.open(outs, fstream::out);
		
		generate_input(i);
		
		//generate_output(i);
		
		in.close();
		out.close();
	}
	
	
	return 0;
}

/*

4743

*/

