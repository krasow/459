#include <ac_int.h>

void test(int din[40],  uint6 offset,
          int dout[40])
{
  static int regs[40];

#pragma unroll yes
  for (int i=0; i<40; i++) {
#pragma unroll yes
    for (int j=0; j<40; j++) {
      if ((j==offset) & (j+i<40)) {
        regs[j+i] = din[i];
      }
    }
  }

  // Loop is fully unrolled
#pragma unroll yes
  for (int i=0; i<40; i++) {
    dout[i] = regs[i];
  }
}

#pragma hls_design top
void test_wrapper(int din_in[40],  uint6 offset,
                  int dout[40])
{
  int din[40];
#pragma unroll yes
  for (int i=0; i<40; i++) {
    din[i] = din_in[i];
  }

  test(din,offset,dout);
}

