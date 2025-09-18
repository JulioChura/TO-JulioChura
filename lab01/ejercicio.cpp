#include <iostream>
#include <vector>
#include <list>

using namespace std;

int countChange(int money, list<int> coins) {
    if (money == 0) {
        return 1;
    }
    
    if (money < 0 || coins.empty()) {
        return 0;
    }
    
    // Obtener la primera moneda y el resto
    int firstCoin = coins.front();
    coins.pop_front();
    list<int> remainingCoins = coins;
    
    return countChange(money - firstCoin, coins) + countChange(money, remainingCoins);
}

int countChangeVector(int money, vector<int> coins, int index = 0) {
    if (money == 0) {
        return 1;
    }
    
    if (money < 0 || index >= coins.size()) {
        return 0;
    }
    
    // Usar la moneda actual + no usar la moneda actual
    return countChangeVector(money - coins[index], coins, index) + 
           countChangeVector(money, coins, index + 1);
}

// Funcion auxiliar para probar los ejemplos
void testCountChange() {
    list<int> coins1 = {1, 2};
    cout << "countChange(4, [1,2]) = " << countChange(4, coins1) << endl;
    
    list<int> coins2 = {1, 2, 3};
    cout << "countChange(5, [1,2,3]) = " << countChange(5, coins2) << endl;
    
    list<int> coins3 = {2, 5, 3, 6};
    cout << "countChange(10, [2,5,3,6]) = " << countChange(10, coins3) << endl;
    
    vector<int> coins4 = {1, 2};
    cout << "countChangeVector(4, [1,2]) = " << countChangeVector(4, coins4) << endl;
}

int main() {
    testCountChange();
    return 0;
}
