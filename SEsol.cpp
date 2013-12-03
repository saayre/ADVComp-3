// SEsol.cpp, made December 3, 2013, written by Sayre Christenson

#include"SEsol.hpp"

using namespace std;

int main(int argc, char* argv[])
{
	// input
	if (argc == 1) {
		cout << 'usage: SEsol N delt\n';
		exit(EXIT_SUCCESS);
	}

	int N = atoi(argv[1]);
	double delt = atof(argv[2]);

	waveamp exp ('init');
	waveamp imp ('init');
	waveamp CN  ('init');

	exp.expsolve(V, N, delt);
	imp.impsolve(V, N, delt);
	CN.CNsolve  (V, N, delt);

	return 0;
}
