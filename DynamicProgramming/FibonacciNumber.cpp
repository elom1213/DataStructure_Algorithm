#include <iostream>
#define START 0
#define END 100
using namespace std;

typedef unsigned long long int ULLINT;

/**
 * recursive solution
 * 
 * if running time is T(n) given n size data,
 * T(n) = T(n-1) + T(n-2)
 * it'll give thea(2^n) running times
 */

int find_num_recursive(int n)
{
  if(n<=1) return 1;
  return find_num_recursive(n-1) + find_num_recursive(n-2);
}

/**
 * dyanmic solution
 * 
 * in step n, we'll look up memo of index (n-1)%3 and (n-2)%3
 * you can set memo size to END and lookup n-1, n-2 index
 * which takes constant amount of time
 *
 *          memo
 * step 2 : 1 1 2
 * step 3 : 3 1 2
 * step 4 : 3 5 2
 * step 5 : 3 5 8
 */

struct Fibo
{
  ULLINT memo[3]={1, 1, 2};
  ULLINT find_num_dynamic(int n)
  {
    ULLINT f;
    if(n < 3) return memo[n%3];
    else {
      f = find_num_dynamic((n-1)%3) + find_num_dynamic((n-2)%3);
      memo[n%3] = f; // memo
    }
    return f;
  }
};


int main() {

  Fibo fibo;
  for(int i =START; i < END; ++i)
    cout << "step : "<< i << "\tget :" << "\t" << fibo.find_num_dynamic(i) << '\n';

#if 0
  for(int i =START; i < END; ++i)
    cout << "step : "<< i << "\tget :" << "\t" << find_num_recursive(i) << '\n';
#endif
}