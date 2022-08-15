#include <iostream>
#include <vector>

int minCoins(std::vector<int> coins, int maney) {

    if (maney == 0) return 0;
    int amount = maney + 1;
    for (int i = 0; i < coins.size(); ++i) {
        if (coins[i] <= maney) {
            int sub = minCoins(coins, maney-coins[i]);
            if (sub != maney + 1 && sub + 1 < amount) {
                amount = sub + 1;
            }
        }
    }
    return amount;
}

int main() {
	std::vector<int> coins {50, 100, 200, 500};
	int maney = 1250;
	std::cout << "Minimum amount of coins: " << minCoins(coins, maney) << std::endl;
	return 0;
}
