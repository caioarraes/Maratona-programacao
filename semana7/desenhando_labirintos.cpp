#include <bits/stdc++.h> 
using namespace std;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    int test_cases;
    
    if (cin >> test_cases) {
        
        while (test_cases--) {
            int nodo_inicio;
            int total_nos, linhas_lidas;
            cin >> nodo_inicio;
            cin >> total_nos >> linhas_lidas;

            bool matriz_adj[50][50] = {false};
            
            int quantidade_de_linhas_unicas = 0; 

            for (int i = 0; i < linhas_lidas; i++) {
                int origem, destino;
                cin >> origem >> destino;

                if (!matriz_adj[origem][destino]) {
                    
                    matriz_adj[origem][destino] = true; 
                    matriz_adj[destino][origem] = true;
                    
                    quantidade_de_linhas_unicas++;
                }
            }

            int  movimentoS_canaeat= quantidade_de_linhas_unicas * 2;

            cout << movimentoS_canaeat << "\n";
        }
    }

    return 0;
}
