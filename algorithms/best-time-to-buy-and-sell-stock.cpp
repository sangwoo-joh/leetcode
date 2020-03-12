class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int purchased_price = 0x999999;
    int max_profit = 0;

    for (auto price : prices) {
      int profit = price - purchased_price;

      if (price < purchased_price)
        purchased_price = price;

      if (profit > max_profit)
        max_profit = profit;
    }

    return max_profit;
  }
};
