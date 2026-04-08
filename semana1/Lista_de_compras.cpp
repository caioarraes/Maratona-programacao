#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    int n;

    if (!(cin >> n)) return 0;
    
    string descarta_quebra_linha;
    getline(cin, descarta_quebra_linha);

    while (n--) { 
        string linha;
                
        getline(cin, linha); 

        stringstream cortador_palavras(linha); 
        string item;

        set<string> unique_itens; 
         
        while (cortador_palavras >> item) {
            unique_itens.insert(item); 
        }

        bool first_word = true; 

        for (auto palavra_item : unique_itens) { 
            
            if (!first_word) cout << " ";
            cout << palavra_item;
            first_word = false;

        }

        cout << '\n'; 
    }

 
    return 0;
}
