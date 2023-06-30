#include <bits/stdc++.h>
using namespace std;

class StockPrice
{
public:
    unordered_map<int, int> map;
    priority_queue<pair<int, int>> PQ;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ_MIN;

    int currentPrice = 0;
    int currentTime = 0;

    StockPrice() {}
    void update(int timestamp, int price)
    {

        map[timestamp] = price;

        PQ.push({price, timestamp});
        PQ_MIN.push({price, timestamp});

        // updating the current
        if (timestamp >= currentTime)
        {
            currentTime = timestamp;
            currentPrice = price;
        }
        // updating the max
        while (map[PQ.top().second] != PQ.top().first)
        {
            PQ.pop();
        }
        // updating the min
        while (map[PQ_MIN.top().second] != PQ_MIN.top().first)
        {
            PQ_MIN.pop();
        }
    }
    int current()
    {
        return currentPrice;
    }

    int maximum()
    {
        return PQ.top().first;
    }

    int minimum()
    {
        return PQ_MIN.top().first;
    }
};
/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */