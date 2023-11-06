#ifndef _INCLUDED_TEST_H_
#define _INCLUDED_TEST_H_

#include <ac_channel.h>     // Algorithmic C channel class
#include <ac_int.h>         // Algortihmic C integer data types

void test(ac_channel<ac_int<10> > &data_in, ac_int<7> coeffs[32][4],
          ac_channel<ac_int<5,false> > &coeff_addr, ac_channel<ac_int<19> > &result);

#endif

