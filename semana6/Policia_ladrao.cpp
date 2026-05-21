#include <bits/stdc++.h> 
using namespace std;

int matriz_labirinto[5][5];
bool rastreio_visita[5][5];

void investigarDFS(int eixo_x, int eixo_y) {
    if (eixo_x < 0 || eixo_x >= 5 || eixo_y < 0 || eixo_y >= 5) {
        return;
    }
    
    if (matriz_labirinto[eixo_x][eixo_y] == 1 || rastreio_visita[eixo_x][eixo_y]) {
        return;
    }

    rastreio_visita[eixo_x][eixo_y] = true;

    investigarDFS(eixo_x + 1, eixo_y); 
    investigarDFS(eixo_x - 1, eixo_y); 
    investigarDFS(eixo_x, eixo_y + 1); 
    investigarDFS(eixo_x, eixo_y - 1); 
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    int test;
    if (cin >> test) {
        
        while (test--) {
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    cin >> matriz_labirinto[i][j];
                    rastreio_visita[i][j] = false; 
                }
            }

            if (matriz_labirinto[0][0] == 0) {
                 investigarDFS(0, 0); 
            }

            if (rastreio_visita[4][4]) {
                cout << "COPS\n";
            } else {
                cout << "ROBBERS\n";
            }
        }
    }
    return 0;
}
