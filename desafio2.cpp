#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// três “pinos” (torres)
vector<vector<int>> pegs(3);
// contadores de movimento
unsigned long long move_count = 0;
unsigned long long total_moves = 0;
// quantos movimentos entre cada print
unsigned long long M;

// imprime o estado atual das torres
void print_state(unsigned long long steps) {
    if (steps == 0) {
        cout << "Posicao Inicial: 0 passos\n";
    } else if (steps == total_moves) {
        cout << "Posicao Final : " << steps << " passos\n";
    } else {
        cout << "Posicao Atual : " << steps << " passos\n";
    }
    // saída horizontal: [ 3 2 1 ]
    for (int i = 0; i < 3; ++i) {
        const auto &peg = pegs[i];
        if (peg.empty()) {
            cout << "[]\n";
        } else {
            cout << "[ ";
            for (int d : peg) cout << d << " ";
            cout << "]\n";
        }
    }
    // pausa se for estado intermediário
    if (steps != 0 && steps != total_moves) {
        cout << "Pressione ENTER para continuar...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// move um disco de um pino para outro
void move_disk(int from, int to) {
    int disk = pegs[from].back();
    pegs[from].pop_back();
    pegs[to].push_back(disk);
    move_count++;
    // a cada M movimentos imprima
    if (move_count % M == 0) {
        cout << "\n";
        print_state(move_count);
    }
}

// rotina recursiva de Hanoi
void hanoi(int n, int from, int to, int aux) {
    if (n == 0) return;
    hanoi(n - 1, from, aux, to);
    move_disk(from, to);
    hanoi(n - 1, aux, to, from);
}

int main() {
    int N;
    cout << "Numero de discos (N): ";
    cin >> N;
    cout << "Movimentos por visualizacao (M, 0 = sem paradas intermediarias): ";
    cin >> M;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // total de movimentos = 2^N – 1
    total_moves = (1ULL << N) - 1;
    // se M==0, não queremos paradas, então definimos M > total_moves
    if (M == 0) M = total_moves + 1;

    // inicializa pino 0 com discos N,N-1,...,1
    for (int d = N; d >= 1; --d)
        pegs[0].push_back(d);

    // imprime estado inicial
    print_state(0);

    // resolve
    hanoi(N, /*from=*/0, /*to=*/2, /*aux=*/1);

    // caso o final não caia exatamente num múltiplo de M, imprime de novo
    if (move_count % M != 0) {
        cout << "\n";
        print_state(move_count);
    }

    return 0;
}
