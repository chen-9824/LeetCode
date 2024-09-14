/*
509. 斐波那契数
简单
斐波那契数 （通常用 F(n) 表示）形成的序列称为 斐波那契数列 。该数列由 0 和 1
开始，后面的每一项数字都是前面两项数字的和。也就是：
F(0) = 0，F(1) = 1 F(n) = F(n - 1) + F(n - 2)，
其中 n > 1 给定 n ，请计算 F(n) 。
*/
class Solution_509 {
 public:
  /*
  1.dp[i]:i为斐波那契数的n，dp[i]为斐波那契数的值，因为i为下标，所以dp大小应为i
  + 1 2.递推公式：dp[i] = dp[i - 1] + dp[i - 2] 3.dp[i]初始化：dp[0] = 0; dp[1]
  = 1 4.遍历顺序:dp[i]依赖于dp[i - 1]及dp[i -
  2]，所以需要先求得前面的值，遍历顺序为从前到后
  5.举例推导：假设N为10，推导得：0，1，1，2，3，5，8，13，21，34，55
  */
  int fib(int n) {
    if (n < 2) return n;

    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i < n + 1; i++) {
      dp[i] = dp[i - 1] + dp[i - 2];
    }

    std::cout << "F(" << n << ") = ";
    for (auto i : dp) {
      std::cout << i << ", ";
    }
    std::cout << std::endl;

    return dp[n];
  }
};