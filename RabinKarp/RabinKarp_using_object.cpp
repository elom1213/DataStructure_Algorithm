#include <iostream>
#include <cstring>
#define DIVISOR 103

using namespace std;

// CLRS 32.2 The Rabin Karp algorithm
class Matcher
{
private:
  const int word_base, divisor;
  int h;
public:
  /**
   * we don't need to set word_base over 1000 since ASCII is less then 256
   * we can just set it to 256 and it works
   * but to simplify calculation we'll set it to 1000
  */
  Matcher()
  : word_base{1000}, divisor{DIVISOR}, h{1} {}

  void set_word_base(int m)
  {
    // h = word_base^(m-1)%div
    for(int i = 1; i<m; ++i)
      h *= word_base%divisor;
    h %= divisor;
  }

  /**
  * word_to_int() turns "a b c" => 97,098,099
  * calculates 97,098,099 % div recursively
  * if word is too long we can't store it to
  * 8 bytes type data, or register
  * need modulo operation
  */

  int word_to_int(const char* T,int m)
  {
    int n{0};
    for(int i=0; i<m; ++i)
      n = (word_base*n + T[i])%divisor;
    return n;
  }

  /**
   * if we move from "abc" to "bcd" we must calculate
   * 97,098,099 to 98,099,100
   * given t1 = 'a' = 97, t2 = 'd' = 100
   * this is done by three steps
   * 
   * 97,098,099 - 97*word_base
   *     98,099 * word_base
   * 98,099,000 + 100*word_base
   * 
   * move_step() just do additional modulo operation recursively
  */

  int& move_step(int &p, int t1, int t2)
  {
    p = (word_base*(p-t1*h) + t2)%divisor;
    if(p < 0) p += divisor;
    return p;
  }
};

int main() {
  // you can set string using STL string and vector
  // we'll define string in C style

  // P : pattern
  // T : text

  const char* P = {"abc"}; // size = m
  const char* T = {"abcddabcdefufukabcloabaabcbieessabcc"}; // size = n

  int m = strlen(P);
  int n = strlen(T);

  int p{0}, t{0};

  Matcher matcher;
  matcher.set_word_base(m);

  // p = 97,098,099 % 103 = 102
  p = matcher.word_to_int(T, m);
  t = matcher.word_to_int(T, m);

  for(int s = 0; s < n-m ; ++s)
  {
    if(p == t)
      cout << "pattern matches at index " << s << '\n'; 
    t = matcher.move_step(t, T[s], T[s+m]); // update t 
  }
}