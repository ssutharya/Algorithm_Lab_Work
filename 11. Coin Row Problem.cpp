//coin row problem

#include <iostream>
using namespace std;


#include <iostream>
#include <algorithm>

const int MAX_COINS = 100;
int coins[MAX_COINS];
int dp[MAX_COINS];
int selectedCoins[MAX_COINS];

int maxSum(int n) {
    if (n <= 0) {
        return 0;
    }

    dp[0] = coins[0];
    selectedCoins[0] = 1;

    if (n == 1) {
        return dp[0];
    }

    dp[1] = max(coins[0], coins[1]);
    selectedCoins[1] = (coins[0] > coins[1]) ? 1 : 2;

    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + coins[i]);
        if (dp[i] == dp[i - 1]) {
            selectedCoins[i] = selectedCoins[i - 1];
        } else {
            selectedCoins[i] = i + 1;
        }
    }

    return dp[n - 1];
}

int main() {
    int n;
    cout << "Enter the number of coins: ";
    cin >> n;

    cout << "Enter the values of the coins: ";
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    int maxSumValue = maxSum(n);

    cout << "Maximum sum of non-adjacent coins: " << maxSumValue << endl;
    return 0;
}
