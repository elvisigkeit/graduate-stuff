//Trabalho 1 - Linhas concorrentes

#include <iostream>
#include <GL/glut.h>

void Linha(float ponto1x, float ponto1y, float ponto2x, float ponto2y) { //desenha uma linha
	glColor3f (1.0, 1.0, 1.0);
	
	glEnable (GL_LINE_SMOOTH);
	glBegin (GL_LINES);
		glVertex2f (ponto1x, ponto1y);
		glVertex2f (ponto2x, ponto2y);
	glEnd();
	
	glEnable(GL_POINT_SMOOTH);
	glPointSize (6.0);
	glBegin (GL_POINTS);
		glVertex2f (ponto1x, ponto1y);
		glVertex2f (ponto2x, ponto2y);
	glEnd();
}

void pontoConcorrente (float x, float y) { //desenha o ponto especifico de concorrencia
	
}

void Tela () { //funcao da tela
    glColor3f(0.0, 0.0, 0.0); //fundo preto
    glClear (GL_COLOR_BUFFER_BIT); //limpa a janela
	
	Linha (0.1, 0.1, 0.6, 0.6);
	Linha (0.1, 0.6, 0.6, 0.1);
    
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
