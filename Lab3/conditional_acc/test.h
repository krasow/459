#ifndef _INCLUDED_TEST_H_
#define _INCLUDED_TEST_H_

#include <ac_int.h>
#include <ac_channel.h>

template<typename T>
struct pack {
  T data[16];
};

void test_orig(ac_channel<pack<ac_int<8> > > &a_in, ac_channel<pack<ac_int<8> > > &b_in, pack<bool> valid_in, ac_channel<ac_int<20> > &result);
void test(ac_channel<pack<ac_int<8> > > &a_in, ac_channel<pack<ac_int<8> > > &b_in, pack<bool> valid_in, ac_channel<ac_int<20> > &result);

#endif

