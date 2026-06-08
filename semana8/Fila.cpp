#include <bits/stdc++.h> 
using namespace std;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    int n;
    
    if (cin >> n) {

        vector<int> fila_original(n);
        for (int i = 0; i < n; i++) {
            cin >> fila_original[i];
        }

        int m;
        cin >> m;

        vector<bool> ja_saiu(100005, false);

        for (int i = 0; i < m; i++) {
            int pessoa_que_desistiu;
            cin >> pessoa_que_desistiu;
            
            ja_saiu[pessoa_que_desistiu] = true;
        }

        bool flag_primeiro = true;

        for (int i = 0; i < n; i++) {
            int id_verificado_agora = fila_original[i];
            
            if (ja_saiu[id_verificado_agora] == false) { 
                
                if (!flag_primeiro) {
                    cout << " ";
                }
                
                cout << id_verificado_agora;
                flag_primeiro = false;
            }
        }
        cout << "\n";
    }

    return 0;
}
