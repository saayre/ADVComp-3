// SEsol.cpp, made December 3, 2013, written by Sayre Christenson

#include"SEsol.hpp"

using namespace std;

int main(int argc, char* argv[])
{
	// input
	if (argc == 1) {
		cout << "usage: SEsol N delt V\n";
		exit(EXIT_SUCCESS);
	}
	
	int N = atoi(argv[1]);
	double delt = atof(argv[2]);
	double V[Size];
	if ( strncmp(argv[3], "null", 4) == 0) {
		for (int i = 0 ; i < Size ; i++) V[i] = 0;
	}

	// 0 is for given waveform
	waveamp exp (0);
	waveamp imp (0);
	// waveamp CN  ("init");

	exp.expsolve(V, N, delt);
	imp.impsolve(V, N, delt);
	// CN.CNsolve  (V, N, delt);

	return 0;
}
