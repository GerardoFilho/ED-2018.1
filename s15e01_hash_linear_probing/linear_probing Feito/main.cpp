#include <iostream>
#include <vector>
#include <tuple>
using namespace std;



enum Marcador {VAZIO = 0, CHEIO = 1, DELETADO = 2};

struct Elem {
    int key;
    string value;

    Elem(int key = 0, string value = ""){
        this->key = key;
        this->value = value;
    }

    bool operator ==(Elem other){
        return key == other.key;
    }

    friend ostream& operator << (ostream& os, Elem e){
        os << e.key;
        return os;
    }
};

//struct Item {
//    Elem elem;
//    Marcador marc;
//};

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
        int i = find(elem.key);
        if(i == -1)
            return false;
        int pos = elem.key % this->size;
        while( (this->vet[pos].second != VAZIO) || (this->vet[pos].second != DELETADO)){
            pos = (pos + 1) % capacity;
        }
        this->vet[pos].first = elem;
        this->vet[pos].second = CHEIO;
        this->size ++;

    }

    void remove(int key){
        int pos = find(key);
        if(key != -1)
            this->vet[pos].second = DELETADO;
        size--;
            }


    //implementação sem marcação, com realocacao
    bool realoc_remove(int key){
       int pos = find(key);
       if (pos != -1){
           vet[pos].second = VAZIO;
           return false;
        }
       size--;
       pos = (pos + 1) % capacity;
       while(vet[pos].second != VAZIO){
                  vet[pos].second =  VAZIO;
                  insert(vet[pos].first);
                  pos = (pos + 1) % capacity;
              }
              return true;
          }

    //retorna posicao que encontrou o elemento ou -1
    int find(int key){
        int base = key % capacity;
        int i = 0;
        int pos = base;
        while ((this->vet[pos].first == NULL) || (this->vet[pos].second != VAZIO)){
            i++;
            pos = (base + i) % capacity;
        }
        if(vet[pos].second == VAZIO)
            return -1;
        return pos;
    }


};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
