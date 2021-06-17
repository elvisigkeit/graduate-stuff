#ifndef _VECTORING_IN_HOME_
#define _VECTORING_IN_HOME_

#include <GL/freeglut.h>  // GLUT, includes glu.h and gl.h
#include <GL/glu.h>
#include <GL/gl.h>

class Vetor {
public:
    Vetor ();
    Vetor (double x, double y);
    Vetor (double x, double y, double r, double g, double b);
    Vetor (double x, double y, double r, double g, double b, double a);
    Vetor  soma  (Vetor dir);
    Vetor  subt  (Vetor dir);
    Vetor  divisao_escalar (double denominador);
    Vetor  multiplicacao_escalar (double operador);
    Vetor  copiaCor (Vetor copia);
    void   gl();
    void   gl_sem_cor();

    void   print ();

    double x;
    double y;
    double a;
    double r;
    double g;
    double b;
private:
};

Vetor::Vetor () {
    x = 0; y = 0;
    r = 1; g = 1; b = 1; a = 1;
}

Vetor::Vetor (double x, double y) {
    this->x = x; this->y = y;
    r = 1; g = 1; b = 1; a = 1;
}

Vetor::Vetor (double x, double y, double r, double g, double b) {
    this->x = x; this->y = y;
    this->r = r; this->g = g; this->b = b; a = 1;
}

Vetor::Vetor (double x, double y, double r, double g, double b, double a) {
    this->x = x; this->y = y;
    this->r = r; this->g = g; this->b = b; this->a = a;
}

Vetor  Vetor::soma (Vetor dir) {
    return Vetor (x+dir.x, y+dir.y);
}
Vetor  Vetor::subt (Vetor dir) {
    return Vetor (x-dir.x, y-dir.y);
}

Vetor Vetor::copiaCor (Vetor copia) {
    this->r = copia.r; this->g = copia.g; 
    this->b = copia.b; this->a = copia.a;
    return *this;
}

Vetor Vetor::multiplicacao_escalar (double operador) {
    x = x*operador; y = y*operador;
    return *this;
}

Vetor Vetor::divisao_escalar (double denominador) {
    x = x/denominador; y = y/denominador;
    return *this;
}

void Vetor::gl () {
    glColor4d(r, g, b, a);
    glVertex2d(x, y);
}

void Vetor::gl_sem_cor () {
    glVertex2d(x, y);
}

void Vetor::print () {
    std::cout << "Vetor: " << x << ", " << y << std::endl;
}


#endif
