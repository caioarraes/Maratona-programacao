#include <bits/stdc++.h> 

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int quantidade_atracoes, tempo_disponivel_max;
    int numero_instancia = 1;

    while (cin >> quantidade_atracoes >> tempo_disponivel_max && quantidade_atracoes != 0) {
        
        vector<int> duracao(quantidade_atracoes);
        vector<int> pontos(quantidade_atracoes);

        for (int i = 0; i < quantidade_atracoes; i++) {
            cin >> duracao[i] >> pontos[i];
        }

        vector<int> dp(tempo_disponivel_max + 1, 0); 
        for (int i = 0; i < quantidade_atracoes; i++) {
            
            for (int tempoAtual = duracao[i]; tempoAtual <= tempo_disponivel_max; tempoAtual++) {
                
                dp[tempoAtual] = max(dp[tempoAtual] , pontos[i] + dp[tempoAtual - duracao[i]]);
            }
        }
        cout << "Instancia " << numero_instancia++ << "\n";
        cout << dp[tempo_disponivel_max] << "\n";
        cout << "\n"; 
    }

    return 0;
}
