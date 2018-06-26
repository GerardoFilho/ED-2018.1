#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

           --
         33
       23
      3
0 1 2 3 4 5 6 7 8 9

enum Marcador {VAZIO = 0, CHEIO = 1, DELETADO = 2};

struct Elem {
    int key;
    string value;

    Elem(int key = 0, string value = ""){
        this->key = key;
        this->value = value;
    }

    bool operator ==(Elem other){, DELETADO = 2
        return key == other.key;
    }

    friend ostream& operator << (ostream& os, Elem e){
        os << e.key;
        return os;
    }
};

struct Item {
    Elem elem;
    Marcador marc;
};

struct HashLinear{ //linear probing
    pair<Elem, Marcador> * vet;
    int capacity;
    int size;
    HashLinear(int capacity){
        vet = new pair<Elem, Marcador>[capacity];
        this->capacity = capacity;
        this->size = 0;
        for(int i = 0; i < capacity; i++){
            vet[i].first = Elem();
            vet[i].second = VAZIO;
        }
    }

    bool insert(Elem elem){
		int base = key % this->_capacity;	
        auto pos = find(elem.key);
        while( (vet[pos].second != VAZIO) || (vet[pos].second != DELETADO)){
            pos = (base + 1) % this->_capacity;
		}
        vet[pos].first = elem;
        vet[pos].second = CHEIO;
        size ++;

    }

    bool remove(int key){
        int pos = find(key)
        int base = key % this->_capacity;
        while(vet[pos].second != CHEIO){
			 pos = (base + 1) % this->_capacity;
		 }
        if (vet[pos].second == CHEIO){
            vet[pos].second = DELETADO;
        size--;
	}
		else{
				
	
    }

    //implementação sem marcação, com realocacao
  /*  bool remove(int key){
        int pos = find(key);
        if(pos != -1){
            vet[pos].marcador = VAZIO;
            return false;
        }
        size--;
        pos = (pos + 1) % capacity;
        while(vet[pos].marcador != vazio){
            vet[pos].marcador =  VAZIO;
            inserir(vet[pos].elem);
            pos = (pos + 1) % capacity;
        }
        return true;
    }*/

    //retorna posicao que encontrou o elemento ou -1
    int find(int key){
        int base = key % this->_capacity;
        int i = 0;
        int pos = base;
        while (!(vet[pos] == value) && !(vet[pos].VAZIO)){
            i++;
            pos = (base + i) % this->_capacity;
        }
        if(vet[pos].second == VAZIO)
            return -1;
        return pos;
    }

    /* void resize(int capacity){
        auto vet_old = vet;
        vet = new pair<...>[capacity];
        for(auto i = 0; ...)
            vet[i].marcador = VAZIO;
        for(auto& elem : vet_old)
            insert(elem)
        delete vet_old
    }*/

}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
