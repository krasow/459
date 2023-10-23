#include "test.h"
#include <mc_scverify.h>

CCS_MAIN(int argv, char **argc)
{
  ac_channel<pack<ac_int<8> > > a_in;
  ac_channel<pack<ac_int<8> > > b_in;
  pack<bool> valid_in;
  ac_channel<ac_int<20> > result;
  ac_channel<pack<ac_int<8> > > a_in_orig;
  ac_channel<pack<ac_int<8> > > b_in_orig;
  ac_channel<ac_int<20> > result_orig;
  pack<ac_int<8> > a, b;

  for (int j=0; j<5; j++) {
    for (int i=0; i<16; i++) {
      a.data[i] = rand();
      b.data[i] = rand();
      valid_in.data[i] = rand();
    }
    a_in.write(a);
    b_in.write(b);
    a_in_orig.write(a);
    b_in_orig.write(b);
    test(a_in,b_in,valid_in,result);
    test_orig(a_in_orig,b_in_orig,valid_in,result_orig);
  }
  int err = 0;
  while (result.available(1) && result_orig.available(1)) {
    if (result.read() != result_orig.read()) {
      err++;
    }
  }
  printf("There were %d errors!!!\n",err);
  CCS_RETURN(0);
}

