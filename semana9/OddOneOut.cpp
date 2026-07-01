#include <bits/stdc++.h> 
using namespace std;

int main() {
    // Bolierplate Maratona
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        
        while (t--) {
            int a, b, c;
            cin >> a >> b >> c;
            
            // OPERAÇÃO O(1): Mágica dos BITS do XOR cancelando as duplicatas 
            int isolado = a ^ b ^ c; 

            cout << isolado << "\n";
        }
    }
    
    return 0;
}
