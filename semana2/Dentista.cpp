#include <bits/stdc++.h> 

using namespace std;

bool finalizaMaisCedo(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second < b.second; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    if (!(cin >> n)) return 0; 

    vector<pair<int, int>> consultas;

    for (int i = 0; i < n; i++) {
        int inicio, fim;
        cin >> inicio >> fim;
        consultas.push_back({inicio, fim}); 
    }

    sort(consultas.begin(), consultas.end(), finalizaMaisCedo);

    int max_atendimentos = 0; 
    
    int horario_cadeira_livre = 0; 

    for (auto const& c : consultas) {
        
        int hora_inicia_atual = c.first;
        int hora_fim_atual = c.second;

        if (hora_inicia_atual >= horario_cadeira_livre) {
            
            max_atendimentos++; 

            horario_cadeira_livre = hora_fim_atual; 
        }
        
    }

    cout << max_atendimentos << "\n";

    return 0;
}
