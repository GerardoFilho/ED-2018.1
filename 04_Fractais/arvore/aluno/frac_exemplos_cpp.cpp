#include <lib/pen.h>

void linha(Pen &p, int lado){
    float ang = 30;
    float dec = 10;
    lado-= (p.rand() % 7 -2);

        if(lado < 20)
            return;
             p.walk(lado);
             p.right(ang);
            linha(p, lado - dec);
            p.left(ang-10);
            linha(p, lado - dec);
            p.left(ang-10);
            linha(p, lado - dec);
            p.left(ang-10);
            linha(p, lado - dec);
            p.right(ang);
          p.setColor( 0 , rand() % 255, 0);
          if(lado>=90.1)
             p.setThickness(6);
            p.walk(-lado);
}
void fractal(){
    Pen p(800, 600);
    p.setXY(400, 590);
    p.setHeading(90);
    p.setSpeed(500);

    linha(p, 100);

    p.wait();
}

int main(){
    fractal();
    return 0;
}
