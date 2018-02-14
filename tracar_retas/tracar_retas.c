#include <GL/glut.h>

int xi = 0, yi = 0, xf = 0, yf = 0, win;
GLint view_w, view_h;
int count = 0;

// Função callback chamada para fazer o desenho da linha
void Desenha(void){
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES); //inicia desenho da linha
    glVertex2i(xi, yi); //define o inicio da linha
    glVertex2i(xf, yf); //define o final da linha
    glEnd();
    glFlush();
}

// Inicializa parâmetros de rendering
void Inicializa(void){
    // Define a cor de fundo da janela de visualização como preta
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    win = 250.0f;
}

// Função callback chamada quando o tamanho da janela é alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h){
    // Especifica as dimensões da Viewport
    glViewport(0, 0, w, h);
    view_w = w;
    view_h = h;

    // Inicializa o sistema de coordenadas
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-win, win, -win, win);
}

// Função callback chamada para gerenciar eventos de teclado
void GerenciaTeclado(unsigned char key, int x, int y){
    switch (key)
    {
    case 'R':
    case 'r': // muda a cor corrente para vermelho
        glColor3f(1.0f, 0.0f, 0.0f);
        break;
    case 'G':
    case 'g': // muda a cor corrente para verde
        glColor3f(0.0f, 1.0f, 0.0f);
        break;
    case 'B':
    case 'b': // muda a cor corrente para azul
        glColor3f(0.0f, 0.0f, 1.0f);
        break;
    }
    glutPostRedisplay();
}


// Função callback chamada para gerenciar eventos do mouse
void GerenciaMouse(int button, int state, int x, int y){
    if (button == GLUT_LEFT_BUTTON)
        if (state == GLUT_DOWN) {
            count++;
        }
    if(count % 2 != 0){
        xi = ((2 * win * x) / view_w) - win;
        yi = (((2 * win) * (y - view_h)) / -view_h) - win;
    }
    if(count % 2 == 0){
        xf = ((2 * win * x) / view_w) - win;
        yf = (((2 * win) * (y - view_h)) / -view_h) - win;
        glutPostRedisplay();
    }
    
}

// Função callback chamada para gerenciar eventos do teclado
// para teclas especiais, tais como F1, PgDn e Home
void TeclasEspeciais(int key, int x, int y){
    if (key == GLUT_KEY_UP)
    {
        win -= 20;
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(-win, win, -win, win);
    }
    if (key == GLUT_KEY_DOWN)
    {
        win += 20;
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(-win, win, -win, win);
    }
    glutPostRedisplay();
}

// Programa Principal
int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(350, 300);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("Desenhar retas");
    glutDisplayFunc(Desenha);
    glutReshapeFunc(AlteraTamanhoJanela);
    //glutKeyboardFunc(GerenciaTeclado);
    glutMouseFunc(GerenciaMouse);
    //glutSpecialFunc(TeclasEspeciais);
    Inicializa();
    glutMainLoop();
}