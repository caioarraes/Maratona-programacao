#include <bits/stdc++.h>

using namespace std;

void resolver() {
    int n, k;
    cin >> n >> k;
    if (k == 1) {
        cout << n << "\n";
        return;
    }
    int total_operacoes = 0;

    while (n > 0) {
        total_operacoes += (n % k);
        n = n / k; 
    }

    cout << total_operacoes << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            resolver();
        }
    }
    
    return 0;
}
