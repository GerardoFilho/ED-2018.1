#include <iostream>
#include <list>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "libs/sftext.h"

using namespace std;

struct Ambiente{
    list<char> texto;
    list<char>::iterator cursor;
    Ambiente(){
        cursor = texto.end();
    }

    string toString(){
        stringstream ss;
        for(auto it = texto.begin(); it != texto.end(); it++){
            if(it == cursor)
                ss << "#";
            ss << (*it);
        }
        if(cursor == texto.end())
            ss << "#";
        return ss.str();
    }
};

int main()
{
    Ambiente amb;

    list<Ambiente> Z;
    list<Ambiente> R;

    sf::RenderWindow janela(sf::VideoMode(800, 600), "Janela");

    while(janela.isOpen()){

        sf::Event event;
        while(janela.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                janela.close();
            if(event.type == sf::Event::KeyPressed){
                if(event.key.control && (event.key.code == sf::Keyboard::Z)){
                cout << "control z" << endl;
                R.push_back(amb);
                                 if(!Z.empty()){
                                     amb = Z.back();
                                     Z.pop_back();
               }


                }
                else if(event.key.control && (event.key.code == sf::Keyboard::R)){
                        cout << "control r" << endl;
                        if(!R.empty()){
                                                    amb = R.back();
                                                    R.pop_back();
                                                    amb.cursor=amb.texto.end();
                        }
                     }
                else if((event.key.code >= sf::Keyboard::A) && (event.key.code <= sf::Keyboard::Z)){
                    char tecla = (event.key.code - sf::Keyboard::A) + 'a';
                    cout << tecla << endl;
                    amb.texto.insert(amb.cursor, tecla);
                    Z.push_back(amb);
                }
                else if((event.key.code == sf::Keyboard::Return)){
                    cout << "enter" << endl;
                    amb.texto.insert(amb.cursor, '\n');
                    Z.push_back(amb);
                }
                else if((event.key.code == sf::Keyboard::Space)){
                    cout << "espaco" << endl;
                    amb.texto.insert(amb.cursor, ' ');
                    Z.push_back(amb);
                }
                else if(event.key.code == sf::Keyboard::BackSpace){
                    cout << "backspace" << endl;

                if(amb.cursor != amb.texto.begin())
                    amb.cursor = amb.texto.erase( (prev) (amb.cursor++));

                }
                else if(event.key.code == sf::Keyboard::Delete){
                    cout << "delete" << endl;
                    if(amb.cursor == amb.texto.end()){

                    }else{
                         amb.texto.erase(amb.cursor++);
                    }
                }
                else if(event.key.code == sf::Keyboard::Left){
                     if(amb.cursor == amb.texto.begin()){

                     }else{
                         amb.cursor--;
                     }
                }
                else if(event.key.code == sf::Keyboard::Right){
                     if(amb.cursor == amb.texto.end()){

                     }else{
                         amb.cursor++;
                     }
                }
            }
        }

        auto pos = sf::Vector2f(30, 50);
        janela.clear();
        janela.draw(sfText(pos, amb.toString(), sf::Color::White, 30));
        janela.display();
    }
    return 0;
}



