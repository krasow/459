#include <ac_int.h>

void test_orig(int din[40],  uint6 offset,
               int dout[40])
{
  static int regs[40];

  // Loop is fully unrolled
#pragma unroll yes
  for (int i=0; i<40; i++)
    if (i+offset < 40) {
      regs[i + offset] = din[i];
    }
  // Loop is fully unrolled
#pragma unroll yes
  for (int i=0; i<40; i++) {
    dout[i] = regs[i];
  }

}

#pragma hls_design top
void test_orig_wrapper(int din_in[40],  uint6 offset,
                       int dout[40])
{
  int din[40];
#pragma unroll yes
  for (int i=0; i<40; i++) {
    din[i] = din_in[i];
  }

  test_orig(din,offset,dout);
}
