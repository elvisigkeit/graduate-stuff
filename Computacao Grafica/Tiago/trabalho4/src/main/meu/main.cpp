/*#include <iostream>  
#include <vector>
#include "include.hpp"

using namespace std;

vector<Vetor> pontos;
Poligono poligono;
double cliqueFora = 0;

int estado_global;

void mostraCriacaoPoligono () {
    glPointSize(3.0);

    glBegin(GL_POINTS);
        for (Vetor ponto : pontos)
            ponto.gl();
    glEnd();
}

void mostraFechoConvexo () {
    glPointSize(3.0);

    glBegin(GL_POINTS);
        for (Vetor ponto : pontos)
            ponto.gl();
    glEnd();
    
    glBegin(GL_POINTS);
        poligono.gl_cor_individual();
    glEnd();

    glBegin(GL_LINE_STRIP);
        poligono.gl_cor_individual();
    glEnd();
}

void Mouse (int botao, int estado, int x, int y) {
    switch(estado_global) {
    case ADICIONANDO_PONTOS:
        if (botao == GLUT_LEFT_BUTTON)
        if (estado == GLUT_DOWN) {
            double newx = ((x / (double) WINDOW_WIDTH)  - 0.5) * 2.0;
            double newy = (0.5 - (y / (double) WINDOW_HEIGHT)) * 2.0;
            //if (pontos.size() == 0 || pontos[0].dist(Vetor(newx, newy))>(1.0/(WINDOW_WIDTH/30))) {
            pontos.push_back(Vetor(newx, newy));
        }
    break;
    }
    glutPostRedisplay();
}

void Teclado (unsigned char tecla, int x, int y) {
    if (tecla == 'g') {
        poligono = recuperaFechoConvexo(pontos);
        estado_global = FECHO_CONVEXO_MOSTRA;
        glutPostRedisplay();
    }
}

void Tela() {
    glClearColor(0.0f, cliqueFora, 0.0f, 0.7f); 
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
    glEnable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);

    switch(estado_global){
    case ADICIONANDO_PONTOS:
        mostraCriacaoPoligono ();
    break;
    case FECHO_CONVEXO_MOSTRA:
        mostraFechoConvexo ();
    break;
    }

    glFlush();
}
 
int main(int argc, char** argv) {
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitDisplayMode ( GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH | GLUT_ALPHA );
    glutCreateWindow("Trabalho 4");
    glutInitWindowPosition(50, 50);
    glutInit(&argc, argv);
    
    estado_global = ADICIONANDO_PONTOS;

    glutMouseFunc(Mouse);
    glutKeyboardFunc(Teclado);
    glutDisplayFunc(Tela);
    
    glutMainLoop();

    return 0;
}*/