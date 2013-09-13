//
//  Constants.hpp
//  FermiDistributionFunction
//
//  Created by iseki on 2013/09/10.
//  Copyright (c) 2013年 iseki. All rights reserved.
//

#ifndef FermiDistributionFunction_Constants_hpp
#define FermiDistributionFunction_Constants_hpp
/* pysical parameter */
//temperture [K]
const long double T = 300;
//plank's constant [J*s]
const long double h = 6.62606957e-34;
//Dirac's constant [J*s]
const long double hbar = h/(2*M_PI);
//elementary charge [C]
const long double e = 1.60217657e-19;
//boltzmann constant [J/K]
const long double k_b = 1.3806488e-23;
//mass of electron [g]
const long double m_0 = 9.10938291e-34;
//effective mass of electron in InP [g]
const long double m_ee = 0.082*m_0;
//effective mass of hole in InP [g]
const long double m_eh = 0.6*m_0;
//bandgap in InP [J]
const long double E_g = 1.27*e;
//device length [m]
const long double width = 10e-9;
//device depth [m]
const long double depth = 1e-7;
#endif
