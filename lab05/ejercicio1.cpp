#include <iostream>
#include <cstdlib>
#include <ctime>   
#include <vector>

using namespace std;

void generarVector(vector<int>& v, int n);
void imprimirVector(const vector<int>& v);
void filtrar(const vector<int>& v);

int main() {
    srand(time(0));
    const int n = 10;
    vector<int> v;
    generarVector(v, n);
    imprimirVector(v);
    filtrar(v);
    return 0;
}

void generarVector(std::vector<int>& v, int n) {
    for (int i = 0; i < n; i++) {
        v.push_back(rand() % 100);
    }
}

void imprimirVector(const std::vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

void filtrar(const vector<int>& v) {
    auto esCorrecto = [](int numero) {
        return numero % 2 != 0 && numero < 20 ;
    };
    int count = 0;
    for ( int n : v ) {
        if ( esCorrecto(n) ) {
            count ++;
        }
    }
    cout << "Cantidad: " << count << endl;

}