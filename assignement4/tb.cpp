#include "test.h"
#include <mc_scverify.h>

CCS_MAIN(int argv, char **argc)
{
  ac_channel<ac_int<10> > data_in;
  ac_int<7> coeffs[32][4];
  ac_channel<ac_int<5,false> > coeff_addr;
  ac_channel<ac_int<19> > result;
  ac_int<10> data;
  ac_int<5,false> addr;
  for (int i=0; i<32; i++) {
    for (int j=0; j<4; j++) {
      coeffs[i][j] = rand();
    }
  }
  for (int i=0; i<10; i++) {
    data = rand();
    data_in.write(data);
    addr = rand();
    coeff_addr.write(addr);
    test(data_in,coeffs,coeff_addr,result);
  }
  while (result.available(1)) {
    printf("Result = %6d\n",result.read().to_int());
  }
  CCS_RETURN(0);
}

