#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }

// int knapsack(int *weights, int *values, int n, int W) {
//     int dp[n + 1][W + 1];
//     for (int i = 0; i <= n; i++) {
//         for (int w = 0; w <= W; w++) {
//             if (i == 0 || w == 0) {
//                 dp[i][w] = 0;
//             } else if (weights[i - 1] <= w) {
//                 dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]],
//                 dp[i - 1][w]);
//             } else {
//                 dp[i][w] = dp[i - 1][w];
//             }
//         }
//     }
//     return dp[n][W];
// }

int knapsack(int *weights, int *values, int n, int W) {

  if (n == 0 || W == 0)
    return 0;

  if (weights[n - 1] > W) {
    return knapsack(weights, values, n - 1, W);
  } else {
    return max(values[n - 1] +
                   knapsack(weights, values, n - 1, W - weights[n - 1]),
               knapsack(weights, values, n - 1, W));
  }
}

int main() {
  int n = 3;
  int W = 50;
  int weights[] = {10, 20, 30};
  int values[] = {60, 100, 120};
  printf("%d\n", knapsack(weights, values, n, W)); // Output: 220
  return 0;
}
