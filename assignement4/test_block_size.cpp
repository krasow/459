#include "test.h"
#include <mc_scverify.h>

void CCS_BLOCK(test)(ac_channel<ac_int<10> > &data_in, ac_int<7> coeffs[4][32],
                     ac_channel<ac_int<5,false> > &coeff_addr, ac_channel<ac_int<19> > &result)
{
  static ac_int<10> regs[4]; // shift register
  ac_int<19> acc = 0;
  ac_int<5,false> addr = coeff_addr.read();
#pragma unroll yes
  SHIFT:for (int i=3; i>=0; i--)
    if (i==0) {
      regs[i] = data_in.read();
    } else {
      regs[i] = regs[i-1];
    }

  MAC:for (int i=0; i<4; i++) {
    acc += regs[i] * coeffs[i][addr];
  }

  result.write(acc);
}
