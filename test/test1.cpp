#include <assert.h>
#include <set>

#include <cifuzz/cifuzz.h>
#include <fuzzer/FuzzedDataProvider.h>

#include "../src/calculator.h"

FUZZ_TEST_SETUP() {
  // Perform any one-time setup required by the FUZZ_TEST function.
}

FUZZ_TEST(const uint8_t *data, size_t size)
{
  FuzzedDataProvider fuzzed_data(data, size);
  float value1 = fuzzed_data.ConsumeIntegral<int>();
  float value2 = fuzzed_data.ConsumeIntegral<int>();

  std::string random_string = fuzzed_data.ConsumeRandomLengthString();
  char op = random_string[0];

  float res = calculator(value1, op, value2);

  std::set<char> valid_ops({'+', '-', '*', '/'});

  if (valid_ops.find(op) == valid_ops.end())
  {
    assert(res == 1);
  }
}
