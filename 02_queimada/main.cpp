#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;


const int nc = 60;
const int nl = 20;


void mostrar(vector<string>& mat){
    cout << string(50, '\n');
    for(string s : mat)
        cout << s << endl;
    getchar();
}

struct Par{
    int l, c;
    Par(int l = 0, int c = 0){
        this->l = l;
        this->c = c;
    }
};

vector<Par> getneib(Par p){
    vector<Par> v;
    v.push_back(Par(p.l, p.c + 1));
    v.push_back(Par(p.l, p.c - 1));
    v.push_back(Par(p.l + 1, p.c));
    v.push_back(Par(p.l - 1, p.c));
    return v;
}
vector<Par> embaralhar(vector<Par> vet){
    for(int i = 0; i < vet.size(); i++){
        int aleat = rand() % vet.size();
        swap(vet[i], vet[aleat]);
    }
    return vet;
}

int queimar(vector<string> &mat, int l, int c, int nivel) {
    if(l < 0 || l >= nl)
        return 0;
    if(c < 0 || c >= nc)
        return 0;
    if(mat[l][c] != '#')
        return 0;
    else{
        int cont = 0;
        if (nivel==10)
            nivel=nivel%10;
       mat[l][c] = '0' + nivel;
        nivel += 1;
        cont += 1;
    }


    mostrar(mat);
    int sum = 0;
   for(Par p : embaralhar(getneib(Par(l,c))))
   sum += queimar(mat, p.l, p.c, nivel);

//    int e = queimar(mat, l, c-1, nivel);
//    int d = queimar(mat, l, c+1, nivel);
//    int u = queimar(mat, l+1, c, nivel);
//    int b = queimar(mat, l-1, c, nivel);
    mat[l][c] = '.';
    return 1+sum;
}


int main()
{
    srand(time(NULL));
    vector<string> mat(nl, string(nc, ' '));
    int narvores = nl * nc * 1.5;
      for(int i = 0; i < narvores; i++){
      mat[rand() % nl][rand() % nc] = '#';
      }

    mostrar(mat);
    int total = queimar(mat, 0, 0, 0);
    cout << total << " arvores queimaram\n";

    return 0;
}
