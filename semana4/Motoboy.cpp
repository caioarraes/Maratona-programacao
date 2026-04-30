#include <bits/stdc++.h> 

using namespace std;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    int quantidade_pedidos_n;
    while (cin >> quantidade_pedidos_n && quantidade_pedidos_n != 0) {
        
        int limite_pizzas_roberto;
        cin >> limite_pizzas_roberto;
        vector<int> tempo_demora(quantidade_pedidos_n);
        vector<int> pizzas_peso(quantidade_pedidos_n);

        for (int i = 0; i < quantidade_pedidos_n; i++) {
            cin >> tempo_demora[i] >> pizzas_peso[i];
        }
        vector<vector<int>> dp(quantidade_pedidos_n + 1, vector<int>(limite_pizzas_roberto + 1, 0));
        for (int i = 1; i <= quantidade_pedidos_n; i++) {       
            for (int j = 1; j <= limite_pizzas_roberto; j++) {  
                
                if (pizzas_peso[i - 1] > j) { 
                    
                    dp[i][j] = dp[i - 1][j]; 
                    
                } else {
                    dp[i][j] = max( dp[i - 1][j] ,  tempo_demora[i - 1]  + dp[i - 1][ j - pizzas_peso[i - 1] ]); 
                }
            }
        }


        cout << dp[quantidade_pedidos_n][limite_pizzas_roberto] << " min.\n";
    }

    return 0;
}
