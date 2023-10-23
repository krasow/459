#include "test.h"
#include <stdio.h>
#include <mc_scverify.h>

CCS_MAIN(int argv, char *argc)
{
  int din[40];
  uint4 offset;
  int dout[40];
  int dout_orig[40];

  for (int i=0; i<20; i++) {
    for (int j=0; j<40; j++) {
      din[j] = i+j;
    }
    offset = i;
    CCS_DESIGN(test)(din,offset,dout);
    test_orig(din,offset,dout_orig);
    for (int j=0; j<40; j++) {
      printf("%d ",dout_orig[j]);
      if (dout_orig[j] != dout[j]) {
        printf("ERROR");
        break;
      }
    }
    printf("\n");
  }

  CCS_RETURN(0);
}

