#include <lib/pen.h>

void linha(Pen &p, int lado){
    float ang = 36;



    if(lado < 1)
        return;
    p.setColor(sf::Color::Green);
    for(int i = 0; i < 4; i++){
    p.walk(lado);
    p.right(ang);
    linha(p, lado/3);
    p.left(ang*2);
    linha(p, lado/3);
    p.right(ang);
}
    p.setColor(sf::Color::Yellow);
    p.walk(-lado*4);
}

void fractal(){
    Pen p(800, 600);
    p.setXY(400, 590);
    p.setHeading(90);
    p.setSpeed(300);
    p.setThickness(1);
    linha(p, 100);

    p.wait();
}

int main(){
    fractal();
    return 0;
}
