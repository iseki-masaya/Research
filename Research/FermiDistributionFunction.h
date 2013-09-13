//
//  FermiDistributionFunction.h
//  FermiDistributionFunction
//
//  Created by iseki on 2013/09/11.
//  Copyright (c) 2013年 iseki. All rights reserved.
//

#ifndef __FermiDistributionFunction__FermiDistributionFunction__
#define __FermiDistributionFunction__FermiDistributionFunction__

#include <iostream>
#include <cmath>
#include "Constants.h"
#include "Utility.h"

#endif /* defined(__FermiDistributionFunction__FermiDistributionFunction__) */

namespace Fermi {

	/*
	 ・引数
	 E_lim : 価電子帯の上端又は伝導帯の下端
	 n : キャリア密度
	 ・説明
	 擬フェルミ準位を算出する。
	 E_limの値により、価電子帯の場合と伝導帯の場合それぞれ計算できる。
	 */
	long double
	calcFermiQuasiPotentialConduction(long double E_lim,long double n) {
		return E_lim + powl(3.0*M_PI*M_PI, 2.0/3.0)*(hbar*hbar/(2*m_ee))*powl(n, 2.0/3.0);
	}
	
	/*
	 ・引数
	 E_fc : 擬似フェルミ準位
	 E_ch : エネルギー(この値のエネルギーでの存在確率を戻り値として返す。)
	 E_lim : 価電子帯の上端又は伝導帯の下端
	 ・説明
	 キャリアの存在確率を算出する。 f_c(E_ch)
	 */
	long double
	calcFermiDistribution(long double E_fc,long double E_ch,long double E_lim) {
		return 1.0 / (1.0 + exp2l( ( m_eh/(m_eh+m_ee)*(E_ch - E_g) - E_fc + E_lim ) / (k_b*T) ));
	}
	
	/*
	 ・引数
	 int k : 波数k(kの値がマイナスの時は、逆方向の運動を示す。)
	 ・説明
	 伝導帯でのエネルギーを算出する。
	 */
	long double
	calcConductionBandEnergy(int k) {
		return ( sq(h*k)/(3*m_ee) ) + ( sq(hbar*(k-(M_PI/width)))/m_ee );
	}
	
	/*
	 ・引数
	 int k : 波数k(kの値がマイナスの時は、逆方向の運動を示す。)
	 ・説明
	 価電子帯でのエネルギーを算出する。
	 */
	long double
	calcValenceBandEnergy(int k) {
		return ( sq(hbar*(M_PI/width))/(6*m_0) - 3*sq(hbar*k)/m_0 );
	}
		
}// Fermi