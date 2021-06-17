//Trabalho 1 - Linhas concorrentes

#include <iostream>
#include <cmath>
#include <GL/glut.h>

class Linha { //classe que define uma linha
	public:
		//construtor da linha, que ja a parametriza
		Linha (float ponto1x, float ponto1y, float ponto2x, float ponto2y) {
			x1 = ponto1x; x2 = ponto2x; y1 = ponto1y; y2 = ponto2y;
			m = (y1 - y2)/(x1 - x2);
			b = y1 - m*x1;
		}
		
		void desenha() { //desenha a linha
			glColor3f (0.9, 0.6, 0.9);
			
			glEnable (GL_LINE_SMOOTH);
			glBegin (GL_LINES);
				glVertex2f (x1, y1);
				glVertex2f (x2, y2);
			glEnd();
			
			glEnable(GL_POINT_SMOOTH);
			glPointSize (6.0);
			glBegin (GL_POINTS);
				glVertex2f (x1, y1);
				glVertex2f (x2, y2);
			glEnd();
			
			m = (y1 - y2)/(x1 - x2);
			b = y1 - m*x1;
		}
		
		float x1, x2, y1, y2, m, b; //valores dos pontos e parâmetros da reta
};

//Criacao das linhas globais
Linha linhaA (0.1, 0.1, 0.6, 0.6);
Linha linhaB (0.1, 0.6, 0.9, 0.1);

bool dentroSegReta (float x, float y, Linha a) { //funcao que retorna se existe ponto de intersecao
	bool resultado;
	if (a.x1<a.x2) {
		if (a.y1<a.y2) {
			resultado = (x>a.x1)&&(x<a.x2)&&(y>a.y1)&&(y<a.y2);
		}else {
			resultado = (x>a.x1)&&(x<a.x2)&&(y<a.y1)&&(y>a.y2);
		}
	}else {
		if (a.y1<a.y2) {
			resultado = (x<a.x1)&&(x>a.x2)&&(y>a.y1)&&(y<a.y2);
		}else {
			resultado = (x<a.x1)&&(x>a.x2)&&(y<a.y1)&&(y>a.y2);
		}		
	}
	return resultado;
}

void pontoConcorrente (Linha a, Linha b) { //desenha o ponto especifico de encontro
	if (a.m != b.m) { //se os coeficientes angulares as linhas sao paralelas
		float det, s, t, x, y; //parametros da funcao de intersecao
		//calculo do ponto de intersecao
		det = ((b.x2 - b.x1) * (a.y2 - a.y1)) - ((b.y2 - b.y1) * (a.x2 - a.x1));
		s = ((b.x2 - b.x1) * (b.y1 - a.y1) - (b.y2 - b.y1) * (b.x1 - a.x1))/ det ;
		t = ((a.x2 - a.x1) * (b.y1 - a.y1) - (a.y2 - a.y1) * (b.x1 - a.x1))/ det ;
		
		x = a.x1 + (a.x2 - a.x1) * s;
		y = a.y1 + (a.y2 - a.y1) * s;
		if (dentroSegReta(x, y, a)&&dentroSegReta(x, y, b)) {
			glColor3f (1.0, 0.0, 0.0);
			glEnable(GL_POINT_SMOOTH);
			glPointSize (6.0);
			glBegin (GL_POINTS);
				glVertex2f (x, y);
			glEnd();
		}
	}
}

void Tela () { //funcao da tela
    glColor3f(0.0, 0.0, 0.0); //fundo preto
    glClear (GL_COLOR_BUFFER_BIT); //limpa a janela
	
	linhaA.desenha(); linhaB.desenha(); //desenha as duas linhas
	pontoConcorrente(linhaA, linhaB); //desenha o ponto concorrente
    
    glutSwapBuffers();
}

void Remodela (int largura, int altura) { //função de reshape
	glViewport (0, 0, largura, altura); //atualiza a viewport
	glMatrixMode (GL_PROJECTION);  //atualiza a projeção
	glLoadIdentity ();             //carrega a matriz
	gluOrtho2D (0.0, 1.0, 1.0, 0.0); //define coordenadas
	glMatrixMode (GL_MODELVIEW); 
	glutReshapeWindow (500, 500); //manter o tamanho da tela fixo em 500x500
	glutPostRedisplay ();          //pede o redisplay
}

float distanciaPontos (float x1, float y1, float x2, float y2) { //verifica a distancia entre dois pontos
	float distancia = sqrt ((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
	return distancia;
}

void movePonto (int intX, int intY) {
	float x = ((float)intX)/500; float y = ((float)intY)/500;
	if (distanciaPontos(x, y, linhaA.x1, linhaA.y1)<0.016) {
		linhaA.x1 = x; linhaA.y1 = y;
	}else {
		if (distanciaPontos(x, y, linhaA.x2, linhaA.y2)<0.016) {
			linhaA.x2 = x; linhaA.y2 = y;
		}else {
			if (distanciaPontos(x, y, linhaB.x1, linhaB.y1)<0.016) {
				linhaB.x1 = x; linhaB.y1 = y;
			}else {
				if (distanciaPontos(x, y, linhaB.x2, linhaB.y2)<0.016) {
					linhaB.x2 = x; linhaB.y2 = y;
				}
			}
		}
	}
	
	Tela ();
}

int main (int argc ,char** argv) {
    
    glutInit (&argc, argv);  //Inicializa o glut e o openGL
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH); //configura os tipos usados
    glutInitWindowSize (500, 500);   //tamanho da tela
    glutInitWindowPosition (300, 200);       //ponto inicial da janela
    glutCreateWindow ("Retas Concorrentes");  //cria a tela
    
	glutMotionFunc (movePonto); //define funcao de arrasto do mouse
	glutDisplayFunc(Tela); //define callback de display
	glutReshapeFunc(Remodela); //define callback de Reshape
	
    glutMainLoop();
    return 0;
}
