#include <lib/pen.h>

void linha(Pen &p, int lado){

        if(lado < 2)
            return;
        p.setColor(sf::Color::Blue);
        for(int i = 0; i < 5; i++){
        p.walk(lado);
        linha(p, lado *0.36);
        p.setColor(sf::Color::Cyan);

        p.walk(-lado);
        p.right(360/5);
}
        linha(p, lado/lado);



}
void fractal(){
    Pen p(800, 600);
    p.setXY(400, 300);
    p.setHeading(0);
    p.setSpeed(50);

    linha(p, 150);

    p.wait();
}

int main(){
    fractal();
    return 0;
}

