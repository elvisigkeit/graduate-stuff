#include <iostream>  
#include <vector>
#include "include.hpp"

using namespace std;

vector<Vetor> pontos;
Poligono poligono;
double cliqueFora = 0;

int estado_global;

void mostraCriacaoPoligono () {
    glPointSize(3.0);
    
    glBegin(GL_LINE_STRIP);
        for (Vetor ponto : pontos)
            ponto.gl();
    glEnd();

    glBegin(GL_POINTS);
        for (Vetor ponto : pontos)
            ponto.gl();
    glEnd();
}

void mostraVerificacaoPoligono () {
    glBegin(GL_POLYGON);
        poligono.gl();
    glEnd();

    glBegin(GL_POINTS);
        for(Vetor atual : cruzados)
            atual.gl();
    glEnd();
}

void Mouse (int botao, int estado, int x, int y) {
    switch(estado_global) {
    case MONTANDO_POLIGONO:
        if (botao == GLUT_LEFT_BUTTON)
        if (estado == GLUT_DOWN) {
            double newx = ((x / (double) WINDOW_WIDTH)  - 0.5) * 2.0;
            double newy = (0.5 - (y / (double) WINDOW_HEIGHT)) * 2.0;
            if (pontos.size()>2 && pontos[0].dist(Vetor(newx, newy))<(1.0/(WINDOW_WIDTH/30))) {
                estado_global = VERIFICACAO_AREA;
                poligono = Poligono(pontos);
            }
            pontos.push_back(Vetor(newx, newy));
        }
    break;
    case VERIFICACAO_AREA:
        if (botao == GLUT_LEFT_BUTTON) {
            if (estado == GLUT_DOWN) {
                double newx = ((x / (double) WINDOW_WIDTH)  - 0.5) * 2.0;
                double newy = (0.5 - (y / (double) WINDOW_HEIGHT)) * 2.0;
                if (poligono.nrArestasCruzadasParaLateral(Vetor(newx, newy)) % 2 == 1) {
                    poligono.setCor(0, 1, 0, 0.7);
                }
                else {
                    cliqueFora = 0.5;
                }
            }
            if (estado == GLUT_UP) {
                cliqueFora = 0;
                poligono.setCor(1, 1, 1, 0.7);
                cruzados.clear();
            }
        }
    break;
    }
    glutPostRedisplay();
}

void Teclado (unsigned char tecla, int x, int y) {
}

void Tela() {
    glClearColor(0.0f, cliqueFora, 0.0f, 0.7f); 
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
    glEnable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

    switch(estado_global){
    case MONTANDO_POLIGONO:
        mostraCriacaoPoligono ();
    break;
    case VERIFICACAO_AREA:
        mostraVerificacaoPoligono ();
    break;    
    }

    glFlush();
}
 
int main(int argc, char** argv) {
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition(50, 50);
    glutInit(&argc, argv);
    glutCreateWindow("Trabalho 2");
    estado_global = MONTANDO_POLIGONO;
    glutMouseFunc(Mouse);
    glutKeyboardFunc(Teclado);
    glutDisplayFunc(Tela);
    glutMainLoop();

    return 0;
}