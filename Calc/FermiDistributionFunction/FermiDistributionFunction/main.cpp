//
//  main.cpp
//  FermiDistributionFunction
//
//  Created by iseki on 2013/09/10.
//  Copyright (c) 2013年 iseki. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#define _USE_MATH_DEFINES
#include <cmath>

#include "../../../Research/Constants.h"
#include "../../../Research/FermiDistributionFunction.h"
//#include "FermiDistributionFunction.h"

int main(int argc, const char * argv[])
{
	std::string fname = "data/conduction.csv";
	std::ofstream ofs(fname);
	if (&ofs == NULL) {
		std::cout << fname << "can't open.";
		return -1;
	}
	long double n = 1e15;
	long double E_c = Fermi::calcConductionBandEnergy(0);
	long double E_fc = Fermi::calcFermiQuasiPotentialConduction(E_c, n);
	long double t;
	const long double coeff = 1e-20;
	std::cout << sq(5.0) << std::endl;
	for (long double i=1.71e-19; i<2.7e-19; i+=coeff/100.0) {
		t = Fermi::calcFermiDistribution(E_fc, i, E_c);
		ofs << i << "," << t << std::endl;
		std::cout << i << "," << t << std::endl;
	}
}

