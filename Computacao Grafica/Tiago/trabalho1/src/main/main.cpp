#include <iostream>  
#include <vector>
#include "include.hpp"

using namespace std;

vector<Vetor> pontos;
int window_width = 500;
int window_height = 500; 

void Mouse (int botao, int estado, int x, int y) {
    if (botao == GLUT_LEFT_BUTTON)
        if (estado == GLUT_DOWN) {
            double newx = ((x / (double) window_width)  - 0.5) * 2.0;
            double newy = (0.5 - (y / (double) window_height)) * 2.0;
            pontos.push_back(Vetor(newx, newy));
        }
    glutPostRedisplay();
}

void Teclado (unsigned char tecla, int x, int y) {
    vector<Vetor> novo;
    unsigned i = 0;
    for (Vetor ponto : pontos) {
        if (i == 0) {
            novo.push_back(ponto);
            i++;
            continue;
        }
        
        Vetor pedaco (ponto.subt(pontos[i-1]).divisao_escalar(4.0));
        novo.push_back(pedaco.soma(pontos[i-1]));
        novo.push_back(pedaco.multiplicacao_escalar(3.0).soma(pontos[i-1]));

        if (i == pontos.size()-1) {
            novo.push_back(ponto);
        }
        i++;
    }

    pontos = novo;

    glutPostRedisplay();
}

void Tela() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
    glEnable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

    glPointSize(3.0);

    glBegin(GL_LINE_STRIP);
        for (Vetor ponto : pontos)
            ponto.gl();
    glEnd();

    glBegin(GL_POINTS);
        for (Vetor ponto : pontos)
            ponto.gl();
    glEnd();

    glFlush();
}
 
int main(int argc, char** argv) {
    glutInitWindowSize(window_width, window_height);
    glutInitWindowPosition(50, 50);
    glutInit(&argc, argv);
    glutCreateWindow("Trabalho 1");
    glutMouseFunc(Mouse);
    glutKeyboardFunc(Teclado);
    glutDisplayFunc(Tela);
    glutMainLoop();

    return 0;
}