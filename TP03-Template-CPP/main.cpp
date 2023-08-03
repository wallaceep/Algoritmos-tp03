#include <iostream>
#include <vector>

#define INF 0x3f3f3f3f

using namespace std;

void minLigas(int N, int W, vector<int>& ligas) {

    vector<int> dp(W+1, INF);
    dp[0] = 0;

    // Calcula o número mínimo de ligações para cada valor de demanda
    for (int i = 1; i <= W; i++) {
        for (int j = 0; j < N; j++) {
            // Verifica se é possível usar uma ligação do tipo 'ligas[j]' para atender a demanda 'i'
            if (i - ligas[j] >= 0) {
                // Atualiza o número mínimo de ligações para atender a demanda 'i'
                dp[i] = min(dp[i], dp[i - ligas[j]] + 1);
            }
        }
    }
    
    cout << dp[W] << endl;
}

int main(int argc, char const *argv[]) {
    int numTestes, tipoLiga, demanda;

    cin >> numTestes;

    vector<int> size;

    for(int i=0; i<numTestes; i++){
        cin >> tipoLiga >> demanda;
        size.resize(tipoLiga);

        for (int i=0; i < tipoLiga; i++)
            cin >> size[i];

        minLigas(tipoLiga, demanda, size);
    }

    return 0;
}