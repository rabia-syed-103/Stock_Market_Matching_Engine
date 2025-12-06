.#ifndef TRADE_H
#define TRADE_H

#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>
#include "order.h"
using namespace std;
class Trade {
public:
    int tradeID;               // Unique ID of trade
    int buyOrderID;            // Order ID of BUY order
    int sellOrderID;          // Order ID of SELL order
    string buyUserID;         // User who bought
    string sellUserID;        // User who sold
    string symbol;           // Stock symbol
    double price;           // Traded price per unit
    int quantity;           // Trade quantity
    time_t timestamp;       // Trade execution time

public:
    // Constructor
    Trade(int tid, Order* buyOrder, Order* sellOrder, int qty, double prc);
        : tradeID(tid),
          buyOrderID(buyOrder->orderID),
          sellOrderID(sellOrder->orderID),
          buyUserID(buyOrder->userID),
          sellUserID(sellOrder->userID),
          symbol(buyOrder->symbol),
          price(prc),
          quantity(qty)
    {
        timestamp = std::time(nullptr);
    }

    // Displayable format
    std::string toString() const; {
        std::ostringstream oss;
        oss << "TradeID: " << tradeID
            << " | Symbol: " << symbol
            << " | Qty: " << quantity
            << " | Price: $" << std::fixed << std::setprecision(2) << price
            << " | BuyOrder: " << buyOrderID << " (" << buyUserID << ")"
            << " | SellOrder: " << sellOrderID << " (" << sellUserID << ")"
            << " | Timestamp: " << timestamp;
        return oss.str();
    }
};

#endif // TRADE_H
