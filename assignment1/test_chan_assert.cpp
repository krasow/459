#include "test.h"

void test(ac_int<4,false> data0,
          ac_fixed<5,5,false> data1,
          ac_channel<ac_int<4,false> > &chan_in,
          ac_int<3,false> &wrap_behavior,
          ac_fixed<3,3,false,AC_RND,AC_SAT> &sat_behavior,
          ac_int<5,false> &shift_behavior,
          ac_channel<ac_int<4,false> > &chan_out)
{
  wrap_behavior = data0;               // will wrap for values > 7
  sat_behavior = data1;                // will clamp to 7 for values > 7
  shift_behavior = data0 << 1;         // will lose MSB after shift

  chan_out.write(chan_in.read());      // will assert if read of empty channel is attempted
}

