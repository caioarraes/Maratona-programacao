#include <bits/stdc++.h> 

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int dias_n;
    
    while (cin >> dias_n) { 
        int custoDiario;
        cin >> custoDiario;

        int max_lucro_guardado = 0; 
        int lucro_consecutivo_atual = 0; 

        for (int i = 0; i < dias_n; i++) {
            int receitaDiaria;
            cin >> receitaDiaria;

            int lucro_liquido_deste_dia = receitaDiaria - custoDiario;


            lucro_consecutivo_atual += lucro_liquido_deste_dia;

            if (lucro_consecutivo_atual < 0) {
                lucro_consecutivo_atual = 0; 
            }

           
            if (lucro_consecutivo_atual > max_lucro_guardado) {
                max_lucro_guardado = lucro_consecutivo_atual; 
            }
        }

   
        cout << max_lucro_guardado << "\n";
    }

    return 0;
}
