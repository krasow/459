#include "test.h"

#include <stdio.h>
#include <fstream>
using namespace std;

int main()
{
  ac_int<4,false> data0; // 4 bit unsigned, 0 to 15
  ac_fixed<5,5,false> data1;
  ac_channel<ac_int<4,false> > chan_in;
  ac_int<3,false> wrap_behavior;
  ac_fixed<3,3,false,AC_RND,AC_SAT> sat_behavior;
  ac_int<5,false> shift_behavior;
  ac_channel<ac_int<4,false> > chan_out;

  for (int i=0; i<16; i++) {
    if (i>0) {
      chan_in.write(i);
    }
    data0 = i;
    data1 = i;

    test(data0,data1,chan_in,wrap_behavior,sat_behavior,shift_behavior,chan_out);

    printf("Input = %2d wrap_behavior = %2d, sat_behavior = %2d, shift_behavior = %2d\n",
           data0.to_uint(),wrap_behavior.to_uint(),sat_behavior.to_uint(),shift_behavior.to_uint());
  }
  printf("\nChannel data = ");
  while (chan_out.available(1)) { // while data in channel, keep reading
    ac_int<4,false> data = chan_out.read();
    printf("%2d ",data.to_uint());
  }
  printf("\n\n");
  return 0;
}

