#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int valorOriginal;
    
    if (cin >> valorOriginal) {
        
        cout << valorOriginal << "\n";
          
        int valores_das_notas[] = {100, 50, 20, 10, 5, 2, 1};

        int sobraAtual = valorOriginal;

        for (int nota : valores_das_notas) {
             
            int quantidade = sobraAtual / nota;
            
            cout << quantidade << " nota(s) de R$ " << nota << ",00\n";
            
            sobraAtual = sobraAtual % nota;
        }
    }
    return 0;
}
