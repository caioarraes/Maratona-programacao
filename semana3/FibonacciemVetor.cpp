#include <bits/stdc++.h> 

using namespace std;

int main() {
    
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    vector<unsigned long long> tabela_fibonacci(61);

    tabela_fibonacci[0] = 0;
    tabela_fibonacci[1] = 1;

    for (int i = 2; i <= 60; i++) {
        tabela_fibonacci[i] = tabela_fibonacci[i - 1] + tabela_fibonacci[i - 2];
    }


    int testes;
    if (cin >> testes) {
        
        while (testes--) {
            int numeroPedido;
            cin >> numeroPedido;
            
            cout << "Fib(" << numeroPedido << ") = " << tabela_fibonacci[numeroPedido] << "\n";
        }
    }

    return 0;
}
