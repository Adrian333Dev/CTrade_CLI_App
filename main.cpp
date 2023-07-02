#include <iostream>
#include <vector>
#include <string>
using namespace std;

void listMenu(vector<string> menu, bool isFirstTime)
{
  for (int i = 0; i < menu.size(); i++)
    cout << i + 1 << ": " << menu[i] << endl;

  cout << "=============================" << endl;
  if (isFirstTime)
    cout << "Type in 1-6 to select an option: ";
  else
    cout << "Invalid choice. Try again: ";
}

int main()
{
  vector<string> menu = {
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

  int choice;
  bool isFirstTime = true;

  do
  {
    listMenu(menu, isFirstTime);
    isFirstTime = false;
    cin >> choice;
  } while (choice < 1 || choice > 6);

  cout << "You chose: " << choice << endl;
  cout << choiceDetails[choice - 1] << endl;

  return 0;
}
