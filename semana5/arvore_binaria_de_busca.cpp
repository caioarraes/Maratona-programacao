#include <bits/stdc++.h> 

using namespace std;

struct Node {
    int valor;
    Node* left;
    Node* right;
};

Node* criar(int data) {
    Node* Novo = new Node;
    Novo->valor = data;
    Novo->left = NULL;
    Novo->right = NULL;
    return Novo;
}

Node* inserir(int data, Node* N) {
    if (N == NULL) {
        return criar(data);
    }
    if (N->valor > data) {
        N->left = inserir(data, N->left); 
    } else {
        N->right = inserir(data, N->right); 
    }
    return N;
}

void pre_ordem(Node* N, vector<int>& lista) {
    if (N == NULL) return;
    lista.push_back(N->valor);    
    pre_ordem(N->left, lista);    
    pre_ordem(N->right, lista);   
}

void em_ordem(Node* N, vector<int>& lista) {
    if (N == NULL) return;
    em_ordem(N->left, lista);     
    lista.push_back(N->valor);    
    em_ordem(N->right, lista);    
}

void pos_ordem(Node* N, vector<int>& lista) {
    if (N == NULL) return;
    pos_ordem(N->left, lista);    
    pos_ordem(N->right, lista);   
    lista.push_back(N->valor);    
}

void imprimeFormatado(string tipoDaRegra, vector<int>& lista) {
    cout << tipoDaRegra;
    for(int i = 0; i < lista.size(); i++){
        if (i > 0) cout << " ";
        cout << lista[i];
    }
    cout << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int casos_c;
    if(cin >> casos_c) {
        
        for(int t = 1; t <= casos_c; t++) {
            
            int n_elementos;
            cin >> n_elementos;

            Node* raiz_da_arvore = NULL; 

            for(int i = 0; i < n_elementos; i++){
                int valorLido;
                cin >> valorLido;
                raiz_da_arvore = inserir(valorLido, raiz_da_arvore);
            }

            vector<int> res_pre, res_em, res_pos;

            pre_ordem(raiz_da_arvore, res_pre);
            em_ordem(raiz_da_arvore, res_em);
            pos_ordem(raiz_da_arvore, res_pos);

            cout << "Case " << t << ":\n";
            imprimeFormatado("Pre.: ", res_pre);
            imprimeFormatado("In..: ", res_em);
            imprimeFormatado("Post: ", res_pos);
            
            cout << "\n"; 
        }
    }

    return 0;
}
