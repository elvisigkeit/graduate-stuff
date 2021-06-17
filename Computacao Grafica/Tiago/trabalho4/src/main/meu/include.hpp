/*#ifndef _VECTORING_IN_HOME_
#define _VECTORING_IN_HOME_

#include <GL/freeglut.h>  // GLUT, includes glu.h and gl.h
#include <GL/glu.h>
#include <GL/gl.h>
#include <math.h>
#include <algorithm>
#include <unistd.h>

#define ADICIONANDO_PONTOS    1
#define FECHO_CONVEXO_MOSTRA  2
#define WINDOW_WIDTH          500
#define WINDOW_HEIGHT         500

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
    double modulo();
    void   gl();
    void   gl_sem_cor();
    double dot(Vetor proximo);
    double cross(Vetor proximo);
    double dist(Vetor ponto);
    bool   operator< (Vetor proximo);

    void   print ();
    
    double x;
    double y;
    double a;
    double r;
    double g;
    double b;
private:
};

Vetor inferior (WINDOW_WIDTH, WINDOW_HEIGHT);

class Poligono {
public:
    Poligono(std::vector<Vetor> lista);
    Poligono() {Poligono(std::vector<Vetor> ());}

    int    nrArestasCruzadasParaLateral(Vetor ponto);
    void   gl();
    void   gl_cor_individual();
    void   gl_cor(double r, double g, double b, double a);
    void   setCor(double r, double g, double b, double a);

    std::vector<Vetor> pontos;
    double a;
    double r;
    double g;
    double b;
private:
};

std::vector<Vetor> cruzados;

//0 - colinear; 1 - horario; 2 - antihorario;
int orientacao (Vetor p, Vetor q, Vetor r) {
    double valor = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

    if (valor < 1.0e-10 && valor > -1.0e-10)
        return 0;
    if (valor > 0)
        return 1;
    return 2;
}

bool Vetor::operator< (Vetor proximo) {
    int orient = orientacao(inferior, *this, proximo);

    if(orient == 0)
        return ((*this).subt(inferior).modulo()
                < proximo.subt(inferior).modulo());
    if(orient == 1)
        return false;
    return true;
}

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

double Vetor::dot(Vetor vetor) {
    return x*vetor.x + y*vetor.y;
}

double Vetor::cross(Vetor vetor) {
   return (x * vetor.y) - (y * vetor.x);
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

double Vetor::dist(Vetor ponto) {
    return sqrt(((ponto.x-x)*(ponto.x-x))+((ponto.y-y)*(ponto.y-y)));
}

double Vetor::modulo() {
    return dist(Vetor(0, 0));
}

Poligono::Poligono(std::vector<Vetor> lista) {
    r = 1; g = 1; b = 1; a = 0.7;

    for(Vetor atual : lista)
        pontos.push_back(atual);
}

void Poligono::setCor(double r, double g, double b, double a) {
    this->r = r; this->g = g; this->b = b; this->a = a;
}

void Poligono::gl(){
    glColor4d(r, g, b, a);
    for(Vetor atual : pontos)
        atual.gl_sem_cor();
}

void Poligono::gl_cor_individual(){
    for(Vetor atual : pontos) 
        atual.gl();
}

void Poligono::gl_cor(double r, double g, double b, double a) {
    glColor4d(r, g, b, a);
    for(Vetor atual : pontos)
        atual.gl_sem_cor();
}

int Poligono::nrArestasCruzadasParaLateral(Vetor ponto) {
    Vetor apoio = Vetor(WINDOW_WIDTH*2, WINDOW_HEIGHT*2);
    int vezesCruzadas = 0;

    for(unsigned i = 0; i<(pontos.size()); i++) {
        Vetor AB = apoio.subt(ponto);
        Vetor AD;
        if (i == pontos.size()-1)
            AD = pontos[0].subt(ponto);
        else
            AD = pontos[i+1].subt(ponto);
        Vetor AC = pontos[i].subt(ponto);
        double p1 = AB.cross(AD) * AB.cross(AC);
        
        Vetor CD;
        if (i == pontos.size()-1)
            CD = pontos[0].subt(pontos[i]);
        else
            CD = pontos[i+1].subt(pontos[i]);
        Vetor CA = ponto.subt(pontos[i]);
        Vetor CB = apoio.subt(pontos[i]);
        double p2 = CD.cross(CA) * CD.cross(CB);

        if (p1 < 0 && p2 < 0) {
            vezesCruzadas++;
            cruzados.push_back(pontos[i]);
            cruzados.push_back(pontos[i+1]);
        }
    }

    return vezesCruzadas;
}

Poligono recuperaFechoConvexo(std::vector<Vetor> pontos) {
    std::vector<Vetor> resultado;
    int menorIndice = 0;
    int ir = 0;
    for (int i=0; i<pontos.size(); i++) {
        if (pontos[i].y<inferior.y) {
            inferior = pontos[i];
            menorIndice = i;
        }
    }

    Vetor aux = pontos[menorIndice];
    pontos[menorIndice] = pontos[0];
    pontos[0] = aux;
    
    std::sort(pontos.begin()+1, pontos.end());
    for (int i=0; i<pontos.size(); i++) {
        switch(i%3) {
        case 0:
            pontos[i].g = 0; pontos[i].b = 0;
        break;
        case 1:
            pontos[i].r = 0; pontos[i].b = 0;
        break;
        case 2:
            pontos[i].g = 0; pontos[i].r = 0;
        break;
        }

        if(i<3) {
            resultado.push_back(pontos[i]);
            ir++;
        } else {
            int orient = orientacao(resultado[ir-2], resultado[ir-1], pontos[i]);
            std::cout << orient << std::endl;
            if (orient == 1) {
                while (ir > 2 && orient == 1) {
                    resultado.pop_back();
                    ir--;
                    orient = orientacao(resultado[ir-2], resultado[ir-1], pontos[i]);
                }
                resultado.push_back(pontos[i]);
                ir++;
            } else {
                resultado.push_back(pontos[i]);
                ir++;
            }
        }

    }

    return Poligono(resultado);
}

#endif
*/