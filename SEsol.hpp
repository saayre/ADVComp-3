// SEsol.hpp, made 2013 December 3, written by Sayre Christenson

#include<stdlib.h>
#include<string.h>
#include<cmath>
#include<complex>
#include<iostream>
#include<fstream>

#define Size 256
#define USE_MATH_DEFINES

// constants in eqns
#define sig 0.2
#define k 0.4

class waveamp {
	complex<double> wave[Size];
	complex<double> next_wave[Size];
	complex<int> I;

  public:
	waveamp (char*);
	void expsolve (double, int, double);
	void impsolve (double, int, double);
	void CNsolve  (double, int, double);
};

waveamp::waveamp(char *pattern) {

	wave = new complex<double>[Size];
	next_wave = new complex<double>[Size]; // for iterating
	I = complex(0,1);
		
	if (strncmp(pattern, 'init', 4) == 0) {

		double x0 = (Size - 1.) / 2;
		double x;
		
		for (int i = 0 ; i < Size ; i++) {
			
			x = i / (Size - 1.);
			wave[i] = exp( -pow(x - x0, 2)/(2 * pow(sig,2)) + I*k0*x) / pow(M_PI*sig*sig, 1/4.);
		}
	}

	else exit(EXIT_FAILURE);
}

void waveamp::expsolve(double V, int N, double delt) {

	double delx = 1 / (Size-1.);
	complex<double> A = complex(0, delt/(2*delx*delx));

	ofstream sequence;
	sequence.open("exp.dat");
	
	for (int n = 0 ; n < N ; n++) {

		next_wave[0] = A*wave[i+1] + (A - I*V[i]*delt + 1) * wave[i];
		sequence << '0 ' << next_wave[0] << '/n';
		
		for (int i = 1 ; i < Size-1 ; i++) {
			next_wave[i] = A*(wave[i-1] + wave[i+1]) + (A - I*V[i]*delt + 1) * wave[i];
			sequence << i << ' ' << next_wave[i] << '\n';
		}

		next_wave[Size-1] = A*wave[i-1] + (A - I*V[i]*delt + 1) * wave[i];
		sequence << Size-1 << ' ' << next_wave[i] << '\n';
		sequence << '\n';
	}
}


void waveamp::impsolve(double V, int N, double delt) {

	double delx = 1 / (Size-1.);
	complex<double> A = complex(0, delt/(2*delx*delx));

	ofstream sequence;
	sequence.open("exp.dat");
	
	for (int n = 0 ; n < N ; n++) {

		next_wave[0] = A*wave[i+1] + (A - I*V[i]*delt + 1) * wave[i];
		sequence << '0 ' << next_wave[0] << '/n';
		
		for (int i = 1 ; i < Size-1 ; i++) {
			next_wave[i] = A*(wave[i-1] + wave[i+1]) + (A - I*V[i]*delt + 1) * wave[i];
			sequence << i << ' ' << next_wave[i] << '\n';
		}

		next_wave[Size-1] = A*wave[i-1] + (A - I*V[i]*delt + 1) * wave[i];
		sequence << Size-1 << ' ' << next_wave[i] << '\n';
		sequence << '\n';
	}
}


