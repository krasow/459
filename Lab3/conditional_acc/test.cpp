#include "test.h"
#include <mc_scverify.h>

#pragma hls_design top
void CCS_BLOCK(test)(ac_channel<pack<ac_int<8> > > &a_in, ac_channel<pack<ac_int<8> > > &b_in, pack<bool> valid_in, ac_channel<ac_int<20> > &result)
{
  pack<ac_int<8> > a, b;
  pack<bool> valid;
  ac_int<20> acc = 0;
  a = a_in.read();
  b = b_in.read();
  valid = valid_in;

  MAC:for (int i=0; i<16; i++) {
    acc += valid.data[i] ? a.data[i] * b.data[i] : (ac_int<16>)0;
  }
  result.write(acc);
}

