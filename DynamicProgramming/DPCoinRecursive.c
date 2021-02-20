#include <stdio.h>
#include <time.h>

#define MIN(a, b)((a)>=(b) ? (b) : (a))

#define INF 0x7ffffffe
#define MAX_MEMO_SIZ 100
#define COIN_SIZ    3
#define TRUE        1
#define FALSE       0

int coins[COIN_SIZ] = {1, 3, 4};
int is_memoized[MAX_MEMO_SIZ] = {FALSE};
int memo[MAX_MEMO_SIZ] = {0};

/**
 * guid to Competitive programming 6.1 Dyanamic programming
 * 
 * given a coins size of 1, 3, 4 
 * you have to fill arbitrary "amount" using 1, 3, 4
 * we want to minimize the use of coins
 * overall problem is related with each subproblem
 * so memo each subproblem and lookup the memo for each problem
 * base case : memo[0] = 0
*/

int solution(int amount)
{
  if(amount < 0) return INF;
  if(amount == 0) return 0; // base case
  if(is_memoized[amount]) return memo[amount];  // lookup

  int min_coin_num = INF;
  for(int i = 0; i < COIN_SIZ ; i++)
    min_coin_num = MIN(min_coin_num, solution(amount - coins[i]) + 1);

  is_memoized[amount] = TRUE;
  memo[amount] = min_coin_num; // update memo

  return min_coin_num;
}

int main(void) {
  int ans;
  float res;
  
  ans = solution(10);
  printf("%d\n", ans);

  ans = solution(30);
  printf("%d\n", ans);

  ans = solution(100);
  printf("%d\n", ans);

  for(int i=0;i<20;++i)
    printf("%d  ", memo[i]);

  return 0;
}