// SEsol.hpp, made 2013 December 3, written by Sayre Christenson

#include<stdlib.h>
#include<string.h>
#include<cmath>
#include<complex>
#include<iostream>
#include<fstream>

#define Size 256
#define USE_MATH_DEFINES

using namespace std;

class waveamp {
	complex<double> *wave;
	complex<double> *next_wave;
	complex<int> I;

  public:
	waveamp (int);
	void expsolve (double[Size], int, double);
	void impsolve (double[Size], int, double);
	void CNsolve  (double[Size], int, double);
};

waveamp::waveamp(int pattern) {

	wave = new complex<double>[Size];
	next_wave = new complex<double>[Size];

	complex<double> I (0,1);
		
	if (pattern == 0) {

		double x0 = 0.5;
		double x;
		double sig = 0.2;
		double k0 = 0.4;
		
		for (int i = 0 ; i < Size ; i++) {
			
			x = i / (Size - 1.);
			wave[i] = exp( -pow(x - x0, 2)/(2 * pow(sig,2)) ) * exp(I*k0*x) / pow(M_PI*sig*sig, 1/4.);
			// cout << wave[i] << '\n';
		}
	}

	else exit(EXIT_FAILURE);
}

void waveamp::expsolve(double V[Size], int N, double delt) {

	double delx = 1 / (Size-1.);
	complex<double> A(0, delt/(2*delx*delx));
	complex<double> I(0,1);

	ofstream sequence;
	sequence.open("exp.dat");

	// print initial wave
	for (int i = 0 ; i < Size ; i++) sequence << i / (Size - 1.) << ' ' << abs(wave[i]) << '\n';
	sequence << '\n';

	for (int n = 0 ; n < N ; n++) {
		
		for (int i = 1 ; i < Size-1 ; i++) {
			int down = (i-1) <  0    ? Size-1 : (i-1);
			int up   = (i+1) >= Size ? 0      : (i+1);
			next_wave[i] = A*(wave[down] + wave[up]) + (A - I*V[i]*delt + 1.) * wave[i];
			sequence << i / (Size - 1.) << ' ' << abs(next_wave[i]) << '\n';
		}

		sequence << "\n\n";

		// update
		for (int i = 0 ; i < Size ; i++) wave[i] = next_wave[i];
	}
}


void waveamp::impsolve(double V[Size], int N, double delt) {

	double delx = 1 / (Size-1.);
	complex<double> A(0, delt/(2*delx*delx));
	complex<double> I(0,1);

	ofstream sequence;
	sequence.open("imp.dat");

	// print initial wave
	for (int i = 0 ; i < Size ; i++) sequence << i / (Size - 1.) << ' ' << abs(wave[i]) << '\n';
	sequence << '\n';
		
	for (int n = 0 ; n < N ; n++) {
		
		for (int i = 0 ; i < Size ; i++) {
			int down = (i-1) <  0    ? Size-1 : (i-1);
			int up   = (i+1) >= Size ? 0      : (i+1);
			next_wave[i] = -A*(wave[down] + wave[up]) + (-A + I*V[i]*delt + 1.) * wave[i];
			sequence << i / (Size - 1.) << ' ' << abs(next_wave[i]) << '\n';
		}

		sequence << "\n\n";

		// update
		for (int i = 0 ; i < Size ; i++) wave[i] = next_wave[i];
	}
}

	


