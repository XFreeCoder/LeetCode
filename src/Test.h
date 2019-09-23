#if !defined(LEETCODE_TEST)
#define LEETCODE_TEST

#include <iostream>

using namespace std;

namespace leetcode {
template <typename T>
void test(const char *const testName, const T &output, const T &expect) {
  cout << testName << ": ";
  if (output == expect) {
    cout << "AC" << endl;
  } else {
    cout << "Fail" << endl;
    cout << "  output: " << output << ", expect: " << expect << endl;
  }
}
} // namespace leetcode
#endif // LEETCODE_TEST
