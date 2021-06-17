//Trabalho 1 - Linhas concorrentes

#include <iostream>
#include <GL/glut.h>

class Linha { //classe que define uma linha
	public:
		//construtor da linha, que ja a parametriza
		Linha (float ponto1x, float ponto1y, float ponto2x, float ponto2y) {
			x1 = ponto1x; x2 = ponto2x; y1 = ponto1y; y2 = ponto2y;
			m = (y1 - y2)/(x1 - x2);
		}
		
		void desenha() { //desenha a linha
			glColor3f (1.0, 1.0, 1.0);
			
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
		}
		
		float x1, x2, y1, y2, m; //valores dos pontos e parâmetros da reta
};

void pontoConcorrente (Linha a, Linha b) { //desenha o ponto especifico de encontro
	if (a.m != b.m) {
		float det, s, t, x, y; //parametros da funcao de intersecao
		//calculo do ponto de intersecao
		det = ((b.x2 - b.x1) * (a.y2 - a.y1)) - ((b.y2 - b.y1) * (a.x2 - a.x1));
		s = ((b.x2 - b.x1) * (b.y1 - a.y1) - (b.y2 - b.y1) * (b.x1 - a.x1))/ det ;
		t = ((a.x2 - a.x1) * (b.y1 - a.y1) - (a.y2 - a.y1) * (b.x1 - a.x1))/ det ;
		
		x = a.x1 + (a.x2 - a.x1) * s;
		y = a.y1 + (a.y2 - a.y1) * s;
		
		glColor3f (1.0, 0.0, 0.0);
		glEnable(GL_POINT_SMOOTH);
		glPointSize (6.0);
		glBegin (GL_POINTS);
			glVertex2f (x, y);
		glEnd();
	}
}

void Tela () { //funcao da tela
    glColor3f(0.0, 0.0, 0.0); //fundo preto
    glClear (GL_COLOR_BUFFER_BIT); //limpa a janela
	
	Linha a (0.1, 0.1, 0.6, 0.6);
	Linha b (0.1, 0.6, 0.9, 0.1);
	a.desenha(); b.desenha();
	pontoConcorrente(a, b);
    
    glutSwapBuffers();
}

void Remodela (int largura, int altura) { //função de reshape
	glViewport (0, 0, largura, altura); //atualiza a viewport
	glMatrixMode (GL_PROJECTION);  //atualiza a projeção
	glLoadIdentity ();             //carrega a matriz
	gluOrtho2D (0.0, 1.0, 0.0, 1.0); //define coordenadas
	glMatrixMode (GL_MODELVIEW); 
	glutPostRedisplay ();          //pede o redisplay
}


int main (int argc ,char** argv) {
    
    glutInit (&argc, argv);  //Inicializa o glut e o openGL
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH); //configura os tipos usados
    glutInitWindowSize (500, 500);   //tamanho da tela
    glutInitWindowPosition (300, 200);       //ponto inicial da janela
    glutCreateWindow ("Retas Concorrentes");  //cria a tela
    
	glutDisplayFunc(Tela); //define callback de display
	glutReshapeFunc(Remodela); //define callback de Reshape
	
    glutMainLoop();
    return 0;
}
