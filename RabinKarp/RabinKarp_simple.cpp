#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

// CLRS 32.2 The Rabin Karp algorithm
int main() {

  // P : pattern
  // T : text

  const char* P = {"abc"}; // size : m
  const char* T = {"abcddabcdefufukabcloabaabcbieessabcc"}; // size : n

  int m = strlen(P);
  int n = strlen(T);
  int d = 1000; 
  int q = 103; // divisor
  int h = (int)pow(d,m-1)%q;

  int p{0}, t{0};

  // p = 97,098,099 % 103 = 102
  for(int i=0; i<m; ++i)
  {
    p = (d*p + P[i])%q;
    t = (d*t + T[i])%q;
  }

  for(int s = 0; s < n-m ; ++s)
  {
    if(p == t) 
      cout << "pattern matches at index " << s << '\n'; 

    // move next step and update t
    t = (d*(t-T[s]*h) + T[s+m])%q;
    if(t < 0) t+= q;
  }
}