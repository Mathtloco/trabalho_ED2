#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>
#include <limits>

using namespace std;

// --- exceções para pilha ---
struct EmptyStackError : runtime_error {
    EmptyStackError() : runtime_error("Stack is empty") {}
};

// --- classe Stack genérica ---
template<typename T>
class Stack {
    int _capacity, _top;
    T*  _data;
public:
    Stack(int capacity)
      : _capacity(capacity), _top(-1), _data(new T[capacity]) {}
    ~Stack(){ delete[] _data; }
    void push(const T& v){
        if (_top+1>=_capacity) throw runtime_error("Stack is full");
        _data[++_top]=v;
    }
    T pop(){
        if (_top<0) throw EmptyStackError();
        return _data[_top--];
    }
    bool is_empty() const { return _top<0; }
};

// imprime matriz
void print_matrix(const vector<vector<char>>& M){
    for(auto& row:M){
        for(char c:row) cout<<c;
        cout<<"\n";
    }
}

// flood-fill usando pilha, com pausa a cada P passos
void fill_with_stack(vector<vector<char>>& M, int P){
    int rows = M.size(), cols = M[0].size();
    int sr = -1, sc = -1;
    // encontra o 'X'
    for(int i = 0; i < rows && sr < 0; i++){
        for(int j = 0; j < cols; j++){
            if(M[i][j] == 'X'){
                sr = i; sc = j;
                M[i][j] = '1';
                break;
            }
        }
    }
    if(sr < 0){
        cerr << "Ponto inicial 'X' nao encontrado\n";
        return;
    }

    Stack<pair<int,int>> st(rows * cols);
    st.push({sr, sc});

    auto print_status = [&](int steps){
        if(steps == 0){
            cout << "Passos = 0 (Antes do Processamento)\n";
        } else {
            cout << "Passos = " << steps << "\n";
        }
        print_matrix(M);
    };

    int steps = 0;
    // estado inicial
    print_status(steps);
    if(P > 0){
        cout << "Pressione ENTER para continuar...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // loop principal
    while(!st.is_empty()){
        auto [r,c] = st.pop();
        if(r<0||r>=rows||c<0||c>=cols||M[r][c] != '1') continue;
        M[r][c] = '0';
        ++steps;

        // empilha vizinhos
        st.push({r-1, c});
        st.push({r+1, c});
        st.push({r, c-1});
        st.push({r, c+1});

        // pausa a cada P passos
        if(P > 0 && steps % P == 0){
            cout << "\n";
            print_status(steps);
            cout << "Pressione ENTER para continuar...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    // estado final (caso não tenha saído em múltiplo de P)
    if(P == 0 || steps % P != 0){
        cout << "\n";
        print_status(steps);
    }
}

int main(){
    // leitura do arquivo
    ifstream fin("matriz_de_caracteres.txt");
    if(!fin){ cerr<<"Nao encontrou matriz_de_caracteres.txt\n"; return 1; }
    vector<vector<char>> M;
    string line;
    while(getline(fin,line)){
        if(!line.empty()) M.emplace_back(line.begin(), line.end());
    }
    fin.close();

    int P;
    cout<<"Passos entre visualizacoes (P, 0 = sem paradas): ";
    cin>>P;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    fill_with_stack(M,P);
    return 0;
}
