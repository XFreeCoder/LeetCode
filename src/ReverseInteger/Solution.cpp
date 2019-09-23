#include <climits>
#include <iostream>

using namespace std;

class Solution {
public:
  int reverse(int x) {
    int rev = 0;
    while (x != 0) {
      int pop = x % 10;
      x /= 10;
      if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7))
        return 0;
      if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8))
        return 0;
      rev = rev * 10 + pop;
    }
    return rev;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;

  cout << "case 1: ";
  int result = s.reverse(123);
  if (result == 321) {
    cout << "AC" << endl;
  } else {
    cout << "Fail" << endl;
  }

  cout << "case 2: ";
  result = s.reverse(-123);
  if (result == -321) {
    cout << "AC" << endl;
  } else {
    cout << "Fail" << endl;
  }

  cout << "case 3: ";
  result = s.reverse(120);
  if (result == 21) {
    cout << "AC" << endl;
  } else {
    cout << "Fail" << endl;
  }

  return 0;
}
