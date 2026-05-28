#include <bits/stdc++.h>
using namespace std;

void dfs(int cidade_atual, const vector<vector<int>>& mapa, vector<bool>& visitado) {
    visitado[cidade_atual] = true;
    
    for (int bairro_vizinho : mapa[cidade_atual]) { 
        if (!visitado[bairro_vizinho]) {
            dfs(bairro_vizinho, mapa, visitado);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int qt_interseccoes, qt_ruas;
 
    while (cin >> qt_interseccoes >> qt_ruas && (qt_interseccoes != 0 || qt_ruas != 0)) {

        vector<vector<int>> ruas_Ida(qt_interseccoes + 1);
        vector<vector<int>> ruas_Volt(qt_interseccoes + 1);

        for (int i = 0; i < qt_ruas; i++) {
            int V, W, direcao_P;
            cin >> V >> W >> direcao_P;

            ruas_Ida[V].push_back(W);
            
            ruas_Volt[W].push_back(V); 

            if (direcao_P == 2) {
                ruas_Ida[W].push_back(V);   
                ruas_Volt[V].push_back(W); 
            }
        }

        vector<bool> visitas_Ida(qt_interseccoes + 1, false); 
        dfs(1, ruas_Ida, visitas_Ida); 

        bool sucesso_na_ida = true;
        for (int i = 1; i <= qt_interseccoes; i++) {
            if (!visitas_Ida[i]) {
                sucesso_na_ida = false;
                break;
            }
        }

        if (!sucesso_na_ida) {
            cout << "0\n";
            continue; 
        }
        vector<bool> visitas_Voltas(qt_interseccoes + 1, false);
        dfs(1, ruas_Volt, visitas_Voltas); 

        bool passou_no_test_final = true;
        for (int i = 1; i <= qt_interseccoes; i++) {
            if (!visitas_Voltas[i]) {
                passou_no_test_final = false;
                break;
            }
        }

        if (passou_no_test_final) {
            cout << "1\n"; 
        } else {
            cout << "0\n";
        }
    }

    return 0;
}
