#include <bits/stdc++.h> 

using namespace std;

void encontrar_posordem(string preordem, string inordem) {
    if (preordem.empty()) return;

    char raiz_atual = preordem[0];

    int posicao_raiz_na_inordem = inordem.find(raiz_atual);

    int tamanho_lado_esquerdo = posicao_raiz_na_inordem;

    string esq_inordem = inordem.substr(0, posicao_raiz_na_inordem);
    string esq_preordem = preordem.substr(1, tamanho_lado_esquerdo); 

    string dir_inordem = inordem.substr(posicao_raiz_na_inordem + 1);
    string dir_preordem = preordem.substr(1 + tamanho_lado_esquerdo);

    encontrar_posordem(esq_preordem, esq_inordem);
    encontrar_posordem(dir_preordem, dir_inordem);
    
    cout << raiz_atual;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string prefix, infix;

    while (cin >> prefix >> infix) {

        encontrar_posordem(prefix, infix);
        
        cout << "\n";
    }

    return 0;
}
