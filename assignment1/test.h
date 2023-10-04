#ifndef _INCLUDED_TEST_H_
#define _INCLUDED_TEST_H_

#include <ac_int.h>         // Algortihmic C integer data types
#include <ac_fixed.h>       // Algortihmic C fixed-point data types
#include <ac_channel.h>     // Algorithmic C channel class

void test(ac_int<4,false> data0,
          ac_fixed<5,5,false> data1,
          ac_channel<ac_int<4,false> > &chan_in,
          ac_int<3,false> &wrap_behavior,
          ac_fixed<3,3,false,AC_RND,AC_SAT> &sat_behavior,
          ac_int<5,false> &shift_behavior,
          ac_channel<ac_int<4,false> > &chan_out);
#endif

