#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum class OrderBookType
{
  bid,
  ask
};

void listMenu(vector<string> menu, bool isFirstTime);
int getChoice(vector<string> menu);
void processChoice(int choice, vector<string> menuDetails);

vector<string>
    menu = {
        "Print Help",
        "Print Exchange Stats",
        "Make an Offer",
        "Make a Bid",
        "Print Wallet",
        "Continue"};

vector<string> choiceDetails = {
    "Help - Your aim is to make money. Analyse the market and make offers and bids",
    "Market looks good. You can make a profit",
    "Make an Offer - Enter the amount you want to offer",
    "Make a Bid - Enter the amount you want to bid",
    "Your wallet is empty. You need to make money",
    "Going to next time frame"};

class OrderBookEntry
{
public:
  double price;
  double wallet;
  string timestamp;
  string product;
  OrderBookType orderType;

  OrderBookEntry(
      double _price,
      double _wallet,
      string _timestamp,
      string _product,
      OrderBookType _orderType)
      : price(_price),
        wallet(_wallet),
        timestamp(_timestamp),
        product(_product),
        orderType(_orderType)
  {
  }
};

// Test functions declaration
void computeAveragePrice(vector<OrderBookEntry> orders);
void computeLowPrice(vector<OrderBookEntry> orders);
void computeHighPrice(vector<OrderBookEntry> orders);
void computePriceSpread(vector<OrderBookEntry> orders);

int main()
{

  // int choice = getChoice(menu);
  // processChoice(choice, choiceDetails);

  vector<OrderBookEntry> orders = {
      OrderBookEntry(0.10, 0.1, "2020/03/17 17:01:24.884492", "ETH/BTC", OrderBookType::bid),
      OrderBookEntry(0.11, 0.2, "2020/03/17 17:01:24.884492", "ETH/BTC", OrderBookType::bid),
      OrderBookEntry(0.15, 0.3, "2020/03/17 17:01:24.884492", "ETH/BTC", OrderBookType::bid)};

  for (OrderBookEntry &order : orders)
  {
    cout << "Price: " << order.price << endl;
  }

  // for (unsigned int i = 0; i < orders.size(); ++i)
  // {
  //   cout << orders[i].price << endl;
  //   cout << "Price: " << orders.at(i).price << endl;
  // }

  // Test functions
  computeAveragePrice(orders);
  computeLowPrice(orders);
  computeHighPrice(orders);
  computePriceSpread(orders);

  return 0;
}

void listMenu(vector<string> menu, bool isFirstTime)
{
  for (int i = 0; i < menu.size(); i++)
    cout << i + 1 << ": " << menu[i] << endl;

  cout << "=============================" << endl;
  if (isFirstTime)
    cout << "Type in 1-" << menu.size() << "to select an option: ";
  else
    cout << "Invalid choice. Try again: ";
}

int getChoice(vector<string> menu)
{
  int choice;
  bool isFirstTime = true;

  do
  {
    listMenu(menu, isFirstTime);
    isFirstTime = false;
    cin >> choice;
  } while (choice < 1 || choice > 6);

  return choice;
}

void processChoice(int choice, vector<string> menuDetails)
{
  cout << "You chose: " << choice << endl;
  cout << menuDetails[choice - 1] << endl;
}

// Test functions implementation

void computeAveragePrice(vector<OrderBookEntry> orders)
{
  double sum = 0;
  for (OrderBookEntry &order : orders)
    sum += order.price;

  double average = sum / orders.size();
  cout << "Average price: " << average << endl;
}

void computeLowPrice(vector<OrderBookEntry> orders)
{
  double low = orders[0].price;
  for (OrderBookEntry &order : orders)
    if (order.price < low)
      low = order.price;

  cout << "Low price: " << low << endl;
}

void computeHighPrice(vector<OrderBookEntry> orders)
{
  double high = orders[0].price;
  for (OrderBookEntry &order : orders)
    if (order.price > high)
      high = order.price;

  cout << "High price: " << high << endl;
}

void computePriceSpread(vector<OrderBookEntry> orders)
{
  double low = orders[0].price;
  double high = orders[0].price;
  for (OrderBookEntry &order : orders)
  {
    if (order.price < low)
      low = order.price;
    if (order.price > high)
      high = order.price;
  }

  double spread = high - low;
  cout << "Price spread: " << spread << endl;
}