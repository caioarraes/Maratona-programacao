#include <bits/stdc++.h> 
using namespace std;

int V, E;
vector<vector<int>> adj;
vector<bool> visitado;     
vector<char> grupo_atual;  

void dfs(int u) {
    visitado[u] = true;                 
    
    grupo_atual.push_back((char)(u + 'a')); 

    for (int vizinho : adj[u]) {
        if (!visitado[vizinho]) {
            dfs(vizinho); 
        }
    }
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    int casos_n;
    if (cin >> casos_n) {
        
        for (int c = 1; c <= casos_n; c++) {
            cin >> V >> E;

            adj.assign(V, vector<int>()); 
            visitado.assign(V, false);

            for (int i = 0; i < E; i++) {
                char no1, no2;
                cin >> no1 >> no2;

                int indice_U = no1 - 'a';
                int indice_V = no2 - 'a';

                adj[indice_U].push_back(indice_V);
                adj[indice_V].push_back(indice_U);
            }

            cout << "Case #" << c << ":\n";
            int total_de_grupos = 0;

            for (int i = 0; i < V; i++) {
                
                if (!visitado[i]) {
                    
                    total_de_grupos++; 
                    grupo_atual.clear(); 

                    dfs(i); 

                    sort(grupo_atual.begin(), grupo_atual.end());
                    
                    for(char pessoa_da_ilha : grupo_atual) {
                        cout << pessoa_da_ilha << ",";
                    }
                    cout << "\n";
                }
            }

            cout << total_de_grupos << " connected components\n\n"; 
        }
    }
    return 0;
}
