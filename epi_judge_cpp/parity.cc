#include "test_framework/generic_test.h"
short Parity(unsigned long long x) {
  // TODO - you fill in here.
  // use lookup table (average running time: <1 us, median running time: <1 us)
  short bit_count = 0;
  int bitcount_lookup[16] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4};
  int res;
  int curr_count;
  while (x > 0) {
    res = 0b1111 & x; //isolate last 4 bits
    curr_count = bitcount_lookup[res]; // bitcount_lookup[res] has the num_1_bits in the binary representation of res
    bit_count += curr_count;
    x = x >> 4;
  }
  return (bit_count % 2);
  

  // count each bit (average running time: 9 us, median running time: 3 us)
  bit_count = 0;
  while(x > 0) {
    bit_count += x & 1;
    x = x >> 1;
  }
  std::cout << bit_count << std::endl;
  return (bit_count % 2);
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "parity.cc", "parity.tsv", &Parity,
                         DefaultComparator{}, param_names);
}
