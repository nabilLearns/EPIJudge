#include "test_framework/generic_test.h"
short Parity(unsigned long long x) {
  // TODO - you fill in here.
  // count each bit (average running time: 9 us, median running time: 3 us)
  short bit_count = 0;
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
