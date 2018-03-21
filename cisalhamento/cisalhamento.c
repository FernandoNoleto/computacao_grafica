#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float cisx1 = 0.5, cisy1 = 0.5, cisx2 = 0, cisy2 = 0.5;


void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y) {

    switch(key){
        case 100: //e: para esquerda
            cisx1 += 0.1;
            cisx2 += 0.1;
            glutPostRedisplay();
        break;
        case 101: //d: para direita
            cisx1 -= 0.1;
            cisx2 -= 0.1;
            glutPostRedisplay();
        break;
    }
}

void draw(void) {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON); //inicia desenho da linha
    glVertex2f(0, 0); //define o inicio da linha
    glVertex2f(0.5, 0); //define o final da linha
    glVertex2f(cisx1, cisy1); //define o final da linha
    glVertex2f(cisx2, cisy2); //define o final da linha
    glEnd();
    glFlush();
}


int main(int argc, char**argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50, 100);
    glutInitWindowSize(400, 300);
    glutCreateWindow("Cisalhamento em 2d");
    init(); // inicialização (após a criação da janela)
    glutDisplayFunc(draw); // registra a função de desenho
    glutKeyboardFunc(keyboard);
    glutMainLoop(); // desenha tudo e espera por eventos
    return EXIT_SUCCESS;
}
