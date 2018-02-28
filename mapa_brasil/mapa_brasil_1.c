#include <GL/glut.h>
#include <stdio.h>

int xi = 0, yi = 0, xf = 0, yf = 0, win;
GLint view_w, view_h;
int count = 0;
int pontos[100][2]; //par que define os pontos

// Função callback chamada para fazer o desenho da linha
void Desenha(void){
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINE_LOOP); //Função "GL_LINE_LOOP" define um conjunto de linhas interligadas onde o último vértice liga-se com o primeiro

    glVertex2i(pontos[0][0], pontos[0][1]);
    glVertex2i(pontos[3][0], pontos[1][1]);
    glVertex2i(pontos[5][0], pontos[4][1]);
    glVertex2i(pontos[1][0], pontos[66][1]);
    glVertex2i(pontos[10][0], pontos[68][1]);
    glVertex2i(pontos[11][0], pontos[71][1]);
    glVertex2i(pontos[19][0], pontos[88][1]);
    glVertex2i(pontos[21][0], pontos[90][1]);
    glVertex2i(pontos[30][0], pontos[98][1]);
    
    glEnd();//Fim da função "glBegin()"
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
    //Esses if's servem para ajustar o redimensionamento da tela
    if(count % 2 != 0){
        xi = ((2 * win * x) / view_w) - win;
        yi = (((2 * win) * (y - view_h)) / -view_h) - win;
    }
    if(count % 2 == 0){
        xf = ((2 * win * x) / view_w) - win;
        yf = (((2 * win) * (y - view_h)) / -view_h) - win;
        glutPostRedisplay();
        //Coeficiente angular
        //float CA = (yf-yi / xf-xi);
        //printf("COEFICIENTE ANGULAR ENTRE OS PONTOS ");
        //printf("X(%d, %d) e Y(%d, %d) EH: %f\n", xi, xf, yi, yf, CA);
    }
    
}

// Programa Principal
int main(int argc, char **argv){

    /*-----DESENHAR PONTOS DA FRONTEIRA DO MAPA DO BRASIL-----*/

    pontos[0][0] = 1;
    pontos[0][1] = 5;
    pontos[1][0] = 58;
    pontos[1][1] = 53;
    pontos[2][0] = 12;
    pontos[2][1] = 21;
    pontos[3][0] = 34;
    pontos[3][1] = 40;
    pontos[4][0] = 79;
    pontos[4][1] = 86;
    pontos[5][0] = 45;
    pontos[5][1] = 67;
    pontos[6][0] = 84;
    pontos[6][1] = 97;
    pontos[7][0] = 03;
    pontos[7][1] = 25;
    pontos[8][0] = 33;
    pontos[8][1] = 45;
    pontos[9][0] = 51;
    pontos[9][1] = 20;
    pontos[10][0] = 77;
    pontos[11][1] = 86;
    pontos[11][0] = 95;
    pontos[12][1] = 04;
    pontos[12][0] = 93;
    pontos[13][1] = 82;
    pontos[13][0] = 63;
    pontos[14][1] = 7;
    pontos[14][0] = 45;
    pontos[15][1] = 20;
    pontos[15][0] = 29;
    pontos[16][1] = 28;
    pontos[16][0] = 37;
    pontos[17][1] = 56;
    pontos[17][0] = 75;
    pontos[18][1] = 94;
    pontos[18][0] = 23;
    pontos[19][1] = 22;
    pontos[19][0] = 41;
    pontos[20][1] = 20;
    pontos[20][0] = 49;
    pontos[21][1] = 28;
    pontos[21][0] = 37;
    pontos[22][1] = 26;
    pontos[22][0] = 1;
    pontos[23][1] = 32;
    pontos[23][1] = 62;
    pontos[24][0] = 52;
    pontos[24][1] = 2;
    pontos[25][0] = 77;
    pontos[25][1] = 27;
    pontos[26][0] = 87;
    pontos[26][1] = 26;
    pontos[27][0] = 95;
    pontos[27][1] = 24;
    pontos[28][0] = 63;
    pontos[28][1] = 22;
    pontos[29][0] = 51;
    pontos[29][1] = 20;
    pontos[30][0] = 49;
    pontos[30][1] = 28;
    pontos[31][0] = 37;
    pontos[31][1] = 26;
    pontos[32][0] = 55;
    pontos[32][1] = 24;
    pontos[33][0] = 93;
    pontos[33][1] = 22;
    pontos[34][0] = 1;
    pontos[34][1] = 20;
    pontos[35][0] = 25;
    pontos[35][1] = 23;
    pontos[36][0] = 27;
    pontos[36][1] = 29;
    pontos[37][0] = 2;
    pontos[37][1] = 42;
    pontos[38][0] = 62;
    pontos[38][1] = 42;
    pontos[39][0] = 32;
    pontos[39][1] = 2;
    pontos[40][0] = 452;
    pontos[40][1] = 2;
    pontos[41][0] = 2;
    pontos[41][1] = 2;
    pontos[42][0] = 2;
    pontos[42][1] = 2;
    pontos[43][0] = 2;
    pontos[43][1] = 2;
    pontos[44][0] = 2;
    pontos[44][1] = 2;
    pontos[45][0] = 2;
    pontos[45][1] = 2;
    pontos[46][0] = 2;
    pontos[46][1] = 2;
    pontos[47][0] = 2;
    pontos[47][1] = 2;
    pontos[48][0] = 2;
    pontos[48][1] = 2;
    pontos[49][0] = 2;
    pontos[49][1] = 2;
    pontos[50][0] = 2;
    pontos[50][1] = 2;
    pontos[51][0] = 2;
    pontos[51][1] = 2;
    pontos[52][0] = 2;
    pontos[52][1] = 2;
    pontos[53][0] = 2;
    pontos[53][1] = 2;
    pontos[54][0] = 2;
    pontos[54][1] = 2;
    pontos[55][0] = 2;
    pontos[55][1] = 2;
    pontos[56][0] = 9;
    pontos[56][1] = 9;
    pontos[57][0] = 9;
    pontos[57][1] = 9;
    pontos[58][0] = 9;
    pontos[58][1] = 9;
    pontos[59][0] = 9;
    pontos[59][1] = 9;
    pontos[60][0] = 9;
    pontos[60][1] = 9;
    pontos[61][0] = 9;
    pontos[61][1] = 9;
    pontos[62][0] = 9;
    pontos[62][1] = 9;
    pontos[63][0] = 9;
    pontos[63][1] = 9;
    pontos[64][0] = 9;
    pontos[64][1] = 9;
    pontos[65][0] = 9;
    pontos[65][1] = 9;
    pontos[66][0] = 9;
    pontos[66][1] = 9;
    pontos[67][0] = 9;
    pontos[67][1] = 9;
    pontos[68][0] = 9;
    pontos[68][1] = 9;
    pontos[69][0] = 9;
    pontos[69][1] = 9;
    pontos[70][0] = 9;
    pontos[70][1] = 9;
    pontos[71][0] = 10;
    pontos[71][1] = 10;
    pontos[72][0] = 10;
    pontos[72][1] = 10;
    pontos[73][0] = 10;
    pontos[73][1] = 10;
    pontos[74][0] = 10;
    pontos[74][1] = 10;
    pontos[74][0] = 10;
    pontos[75][1] = 10;
    pontos[75][0] = 10;
    pontos[76][1] = 10;
    pontos[76][0] = 10;
    pontos[77][1] = 10;
    pontos[77][0] = 10;
    pontos[78][1] = 10;
    pontos[78][0] = 10;
    pontos[79][1] = 10;
    pontos[79][0] = 10;
    pontos[80][1] = 10;
    pontos[80][0] = 10;
    pontos[81][1] = 10;
    pontos[81][0] = 10;
    pontos[82][1] = 10;
    pontos[82][0] = 10;
    pontos[83][1] = 10;
    pontos[83][0] = 10;
    pontos[84][1] = 77;
    pontos[84][0] = 77;
    pontos[85][1] = 77;
    pontos[85][0] = 77;
    pontos[86][1] = 77;
    pontos[86][0] = 77;
    pontos[87][1] = 77;
    pontos[87][0] = 77;
    pontos[88][1] = 77;
    pontos[88][0] = 77;
    pontos[89][1] = 77;
    pontos[89][0] = 77;
    pontos[90][1] = 77;
    pontos[90][0] = 77;
    pontos[91][1] = 77;
    pontos[91][0] = 77;
    pontos[92][1] = 77;
    pontos[92][0] = 77;
    pontos[93][1] = 77;
    pontos[93][0] = 77;
    pontos[94][1] = 77;
    pontos[94][0] = 77;
    pontos[95][1] = 77;
    pontos[95][0] = 77;
    pontos[96][1] = 12;
    pontos[96][0] = 12;
    pontos[97][1] = 12;
    pontos[97][0] = 12;
    pontos[98][1] = 12;
    pontos[98][0] = 12;
    pontos[99][1] = 12;
    pontos[99][0] = 12;
    
    /*----------------------------*/

    glutInit(&argc, argv);//Não sei
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(450, 400);//Definir tamanho da janela inicialmente
    glutInitWindowPosition(400, 150);//Definir posição onde a tela será iniciada
    glutCreateWindow("MAPA DO BRASIL - Fernando, Thiago e Orion");//Criar e definir título para a janela
    glutDisplayFunc(Desenha);//Função que efetivamente desenha a tela (a função passada como parâmetro define as regras do desenho da tela)
    glutReshapeFunc(AlteraTamanhoJanela);//Função que "redenha" a tela caso ela seja alterada de tamanho
    glutMouseFunc(GerenciaMouse);//Lister que gerencia interações com o mouse
    Inicializa();//Nem precisa falar
    glutMainLoop();//Sei lá, sei que precisa
}