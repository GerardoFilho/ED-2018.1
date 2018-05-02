#include <iostream>

using namespace std;

struct  Node{
    int value;
    Node* next;

    Node(int value = 0, Node * next = nullptr){
        this->value = value;
        this->next = next;
    }
};

struct SList{

    Node* head;

    SList(){
        this->head = nullptr;
    }

    ~SList(){
        deletarTudo(head);
    }

    Node * deletarTudo(Node * node){
	if(node == nullptr)
		return nullptr;
	deletarTudo(node->next);
	delete node;
	return nullptr;
	

    }

   // 5 4 7 8 9 3 1
   // cortarRabo(8)
   // 5 4 7

    //procura o valor, remove desse no em diante
    Node * cortarRabo(Node * node, int value){
	if(node == nullptr)
	return nullptr;
	node->next = cortarRabo(node->next, value);
	if(node->next == nullptr){
	if(node->value != value){
	delete node;
	return nullptr;
	}
	else{
		return node;
	 }
	}
	return node;
      } 
	
	void _cortarRabo(int value){
	cortarRabo(head, value);
    }
         

     Node * arrancaVenta(Node * node, int value){
        if(node == nullptr)
            return nullptr;
        node->next = arrancaVenta(node->next, value);
        if(node->next == nullptr){
            if(node->value != value){
                delete node;
                return nullptr;
            }else{
                return node;
            }
        }
        return node;
}


    void push_front(int value){
        //this->head = new Node(value, this->head);
        Node * node = new Node(value);
        node->next = head;
        this->head = node;
    }

    void pop_front(){
        if(head == nullptr)
            return;
        Node * aux = head;
        head = head->next;
        delete aux;
    }

    void push_back(int value){
        if(head == nullptr){
            head = new Node(value);
            return;
        }
        auto node = head;
        while(node->next != nullptr)
            node = node->next;
        node->next = new Node(value);
    }




    Node * _push_back(Node * node, int value){
         if(node->next == nullptr){
	 node->next = new Node (value);
	 return node->next;
	}
	return _push_back(node->next, value);
	}

    void rpush_back(int value){
	_push_back(head, value);
      }
	

    }

    void pop_back(){
        if(head == nullptr)
            return;
        if(head->next == nullptr){
            delete head;
            head = nullptr;
            return;
        }
        auto node = head;
        while(node->next->next != nullptr)
            node = node->next;
        delete node->next;
        node->next = nullptr;
    }

    Node * _rpop_back(Node * node){
        if(node->next == nullptr){
            delete node;
            return nullptr;
        }
        node->next = _rpop_back(node->next);
    }

    void rpop_back(){
        this->head = _rpop_back(head);
    }

    void ishow(){
        auto node = head;
        while(node != nullptr){
            cout << node->value << " ";
            node = node->next;
        }
        cout << endl;
    }
private:
    void _rshow(Node * node){
        if(node == nullptr)
            return;
        cout << node->value << " ";
        _rshow(node->next);
    }
public:
    void rshow(){
        _rshow(head);
        cout << endl;
    }

    Node * _remove(Node * node, int value){
        if(node == nullptr)
            return nullptr;
        if(node->value == value){
            auto aux = node->next;
            delete node;
            return aux;
        }
        node->next = _remove(node->next, value);
    }

    void rremove(int value){
        head = _remove(head, value);
    }

    void iremove(int value){
	auto node = head;
        if(node == nullptr)
            return nullptr;
        
        if(head->value == value){
            auto aux = head;
            head = head->next;
            delete aux;
            return head;
        }
        while(node->next != nullptr){
            if(node->next->value == value){
                auto aux = node->next;
                node->next = node->next->next;
                delete aux;
                return node->next;
            }
            node = node->next;
        }
        return node;
}


    /*
    head = 900;
    900:{1 500};
    500:{2 700};
node700:{4 250};
    300:{6 0};
    250:{5 300};
    */

    //5
    //2 >4 X 6
    Node * _rinserir_ordenado(Node * node, int value){
        if(node == nullptr || (node->value >= value))
            return new Node(value, node);
        node->next = _rinserir_ordenado(node->next, value);
        return node;
    }

    void rinserir_ordenado(int value){
        head = _rinserir_ordenado(head, value);
}

    int size(){
	int count = 0;
	if(node == nullptr){
	return 0;
	}
	count++;
	size(node->next);
	
        return count;
    }
   int _size(){
	return size(head);
}

    int rsomar(Node * node){
        if(node == nullptr){
          return 0;
}
	return node->value += rsomar(node->next);
    }

   int _Somar(){
	return rsomar(head);
     }

    int rmin(Node * node){
        if(node->next == nullptr)
            return node->value;
        return std::min(node->value, rmin(node->next));
    }

   int itmin(Node * node){ 
        int min = node->value;
        while (node != nullptr) {
            if(node->value < min)
                min = node->value;
            node = node->next;
        }
        return min;
    }
    int Min(){
        return itmin(head);
    }
};

int main(){
    SList lista;
    lista.push_back(5);
    lista.push_back(6);
    lista.push_back(7);
    lista.push_back(10);
    return 0;
}


//push_back recursivo ok
//deletarTudo ok
//cortarRabo ok
//somar recursivo ok
//min recursivo ok
//inserir_ordenado ok
//iremove ok
//size ok



//int main()
//{
//    SList lista;
//    lista._rshow(lista.head);
//    return 0;
//}

////int mainc(){
////    char produto[] = "nescau 200 ml 10.00 5 laticineos";
////    char str[50];
////    float valor = 4.50;
////    int qtd = 10;
////    char setor[] = "hortifruti";
////    sprintf(str, "uva %f %d %s", valor, qtd, setor);
////    char nome[50];
////    sscanf(produto, "%s %f %d %s", nome, &valor, &qtd, setor);
////    return 0;
////}

////#include <fstream>

////int maincpp(){
////    int x;
////    ofstream asaida("../lista/saida.txt");
////    ifstream ainput("../lista/entrada.txt");
////    string linha;
////    getline(ainput, linha, ';');
////    asaida << "digite um inteiro" << endl;
////    ainput >> x;
////    asaida << "digite um nome bonito" << endl;
////    string s;
////    ainput >> s;
////    asaida << "x = " << x << ", s = " << s << endl;

////    return 0;
////}

////#include <sstream>
////int main(){
////    stringstream ss;
////    ss << "hoje " << 24 << "abril de 2014, temp=" << 27.73 << endl;
////    cout << ss.str();

////    string str("44 38");
////    stringstream ss2(str);
////    int lixo;
////    int i;
////    ss2 >> lixo >> i;
////    return 0;
////}



