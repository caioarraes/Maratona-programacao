#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    int n;

    if (!(cin >> n)) return 0;

    vector<int> pares;
    vector<int> impares; 
    
    for(int i = 0 ; i < n ; ++i ) {
       int x;
       cin >> x;
        if(x % 2 == 0){ 
            pares.push_back(x);     
        }else{
             impares.push_back(x); 
        }
    }
    
    sort(pares.begin(), pares.end());
    sort(impares.begin() , impares.end(), greater<int>());

    for( auto n : pares){ cout << n << "\n";}  

    for (auto n : impares){ cout << n << "\n"; } 

 
    return 0;
}
