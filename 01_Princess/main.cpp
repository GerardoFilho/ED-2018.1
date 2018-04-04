#include <iostream>
#include <list>

using namespace std;

void rodar(list<int> &lista){

    lista.push_back(lista.front());
    lista.pop_front();
}

int main(){

    cout << "Digite qtd, salto e o primeiro" << endl;
    int qtd = 0;
    int n=0;
    int primeiro = 1;
    cin >> qtd;
    cin >> n;
    cin >> primeiro;

    list<int> lista;
    for(int i = 1; i <= qtd; i++)
        lista.push_back(i);

    while(lista.front() != primeiro)
        rodar(lista);

    while(lista.size() > 1){
        for( int cont=1; cont<=n; cont++)
        rodar(lista);
        lista.pop_front();

    }

    cout<< lista.front() << endl;
    return 0;
}





