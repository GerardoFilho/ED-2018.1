#include <lib/pen.h>

void linha(Pen &p, int lado){

    if(lado < 1)
            return;
        p.circle(lado);
        for(int i = 0; i < 6; i++){
            p.left(60);
            p.up();
            p.walk(lado);
            p.down();
            linha(p,lado*2/6);
            p.up();
            p.setColor(sf::Color::Red);
            p.walk(-lado);
            p.down();
        }
    }





void fractal(){
    Pen p(800, 600);
    p.setXY(300, 200);
    p.setHeading(0);
    p.setSpeed(30);

    linha(p, 100);

    p.wait();
}

int main(){
    fractal();
    return 0;
}
