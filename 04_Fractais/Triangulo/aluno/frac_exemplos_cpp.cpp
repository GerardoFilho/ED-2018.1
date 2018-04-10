#include <lib/pen.h>

void linha(Pen &p, int lado){
    float ang = 120;
    // float dec = 15;
            if(lado<7)
            return;
    p.setColor(sf::Color::Green);
    p.walk(lado);
    p.right(ang);
    p.walk(lado);
    p.right(ang);
    p.walk(lado);
    p.right(ang);
    linha(p, lado/2);

    p.setColor(sf::Color::Blue);
    p.walk(lado);
    p.right(ang);
    linha(p, lado/2);
    p.walk(lado);
    p.right(ang);
    p.walk(lado);
    p.right(ang);

    p.setColor(sf::Color::Red);
    p.walk(lado);
    p.right(ang);
    p.walk(lado);
    p.right(ang);
    linha(p, lado/2);
    p.walk(lado);
    p.right(ang);

}

void fractal(){
    Pen p(800, 600);
    p.setXY(100, 100);
    p.setHeading(0);
    p.setSpeed(5);

    linha(p, 500);

    p.wait();
}

int main(){
    fractal();
    return 0;
}
