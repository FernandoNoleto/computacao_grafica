#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//armazena os vértices de um objeto
typedef struct V {
    int x;
    int y;
}VERTEX;

//armazena a descrição geométrica de um objeto
typedef struct O {
    VERTEX *vertices;
    int nrvertices;
}OBJECT;

OBJECT *object; //objeto global que será desenhado

float rot = 0, trlc = 0, escl = 1; //Parâmetros para rotação, translação e escala

#define v .577350269

static GLfloat vdata[8][3] = {
   {-1.0, -1.0, -1.0}, {1.0, -1.0, -1.0}, {1.0, 1.0, -1.0}, {-1.0, 1.0, -1.0},
   {-1.0, -1.0, 1.0}, {1.0, -1.0, 1.0}, {1.0, 1.0, 1.0}, {-1.0, 1.0, 1.0}
   };

static GLfloat ndata[8][3] = {
   {-v, -v, -v}, {v, -v, -v}, {v,v,-v}, {-v, v, -v},
   {-v, -v, v}, {v, -v, v}, {v,v,v}, {-v, v, v}
   };

static GLuint vindices[6][4] = {
   {0,3,2,1}, {2,3,7,6}, {0,4,7,3},
   {1,2,6,5}, {4,5,6,7}, {0,1,5,4}
   };

static GLfloat m[4][4] = {
   {1.0,0.0,0.0,0.0}, {0.0,1.0,0.0,0.0}, {0.0,0.0,1.0,0.0}, {0.0,0.0,0.0,1.0}
   };

GLfloat spin_x=0.0, spin_y=0.0, spin_z=0.0;

GLint scale=0, shearing=0;

OBJECT *create_object() {
    OBJECT *obj = (OBJECT *)malloc(sizeof(OBJECT));
    obj->nrvertices = 5;
    obj->vertices = (VERTEX *)malloc(obj->nrvertices*sizeof(VERTEX));
    obj->vertices[0].x = 110;
    obj->vertices[0].y = 50;
    obj->vertices[1].x = 110;
    obj->vertices[1].y = 70;
    obj->vertices[2].x = 100;
    obj->vertices[2].y = 80;
    obj->vertices[3].x = 90;
    obj->vertices[3].y = 70;
    obj->vertices[4].x = 90;
    obj->vertices[4].y = 50;
    return obj;
}

VERTEX calculate_centroid(OBJECT *obj) {
    int i;
    VERTEX cent;
    cent.x = 0;
    cent.y = 0;
    for (i=0; i < obj->nrvertices; i++) {
        cent.x += obj->vertices[i].x;
        cent.y += obj->vertices[i].y;
    }
    cent.x /= obj->nrvertices;
    cent.y /= obj->nrvertices;
    return cent;
}

void init(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 200.0, 0.0, 150.0);
    object = create_object(); //cria o objeto
}

void draw_object(OBJECT* obj) {
    int i;
    glBegin(GL_POLYGON); //desenha uma linha
    for (i=0; i < obj->nrvertices; i++){
        glVertex2i(obj->vertices[i].x, obj->vertices[i].y);
    }
    glEnd();
}

void rotacao(void) {
    glClear(GL_COLOR_BUFFER_BIT); //desenha o fundo (limpa a janela)
    glColor3f(1.0, 0.0, 0.0); //altera o atributo de cor
    VERTEX cent = calculate_centroid(object); //calculo o centróide
    glMatrixMode(GL_MODELVIEW); //garante que a matrix seja a ModelView
    glLoadIdentity(); //carrega a matrix identidade
    glTranslatef(cent.x, cent.y, 0); //movo o centróide para a posição original
    glRotatef(rot, 0, 0, 1); //rotaciono
    glTranslatef(-cent.x, -cent.y, 0); //movo o centróide para a origem
    //glTranslatef(50, 0, 0); //faço a translação
    draw_object(object);
    glFlush(); //processa as rotinas OpenGL o mais rápido possível
}

void translacao(void) {
    glClear(GL_COLOR_BUFFER_BIT); //desenha o fundo (limpa a janela)
    glColor3f(1.0, 0.0, 0.0); //altera o atributo de cor
    VERTEX cent = calculate_centroid(object); //calculo o centróide
    glMatrixMode(GL_MODELVIEW); //garante que a matrix seja a ModelView
    glLoadIdentity(); //carrega a matrix identidade
    glTranslatef(cent.x, cent.y, 0); //movo o centróide para a posição original
    //glRotatef(rot, 0, 0, 1); //rotaciono
    glTranslatef(-cent.x, -cent.y, 0); //movo o centróide para a origem
    glTranslatef(trlc, 0, 0); //faço a translação
    draw_object(object);
    glFlush(); //processa as rotinas OpenGL o mais rápido possível
}

void escala(void) {
    glClear(GL_COLOR_BUFFER_BIT); //desenha o fundo (limpa a janela)
    glColor3f(1.0, 0.0, 0.0); //altera o atributo de cor
    VERTEX cent = calculate_centroid(object); //calcula o centróide
    glMatrixMode(GL_MODELVIEW); //garante que a matrix seja a ModelView
    glTranslatef(cent.x, cent.y, 0); //movo o centróide para a posição original
    glScalef(escl, escl, 0); //faço a escala
    glTranslatef(-cent.x, -cent.y, 0); //movo o centróide para a origem
    draw_object(object);
    glFlush(); //processa as rotinas OpenGL o mais rápido possível
}

void cisalhamento(void){
    
}

void keyboard(unsigned char key, int x, int y) {

    switch(key){
        case 27: //ESC: encerra
            if (object != NULL){
                free(object->vertices); //elimina o objeto
                free(object); //elimina o objeto
                exit(1);
            }
        break;
        case 114: //r: rotação
            rot += 10;
            glutDisplayFunc(rotacao); // registra a função de desenho
            glutPostRedisplay();
        break;
        case 116: //t: translação
            trlc += 10;
            glutDisplayFunc(translacao); // registra a função de desenho
            glutPostRedisplay();
        break;
        case 101: //e: escala aumentando
            escl += 0.3;
            glutDisplayFunc(escala); // registra a função de desenho
            glutPostRedisplay();
        break;
        case 100: //d: escala diminuindo
            escl -= 0.1;
            glutDisplayFunc(escala); // registra a função de desenho
            glutPostRedisplay();
        break;
        case 99: //c: cisalhamento
            glutDisplayFunc(cisalhamento); // registra a função de desenho
            glutPostRedisplay();
        break;
    }
}

void draw(void) {
    glClear(GL_COLOR_BUFFER_BIT); //desenha o fundo (limpa a janela)
    glColor3f(1.0, 0.0, 0.0); //altera o atributo de cor
    glMatrixMode(GL_MODELVIEW); //garante que a matrix seja a ModelView
    draw_object(object); //desenha o objeto
    glFlush(); //processa as rotinas OpenGL o mais rápido possível
}


int main(int argc, char**argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50, 100);
    glutInitWindowSize(400, 300);
    glutCreateWindow("Rotação em 2d");
    init(); // inicialização (após a criação da janela)
    glutDisplayFunc(draw); // registra a função de desenho
    glutKeyboardFunc(keyboard);
    glutMainLoop(); // desenha tudo e espera por eventos
    return EXIT_SUCCESS;
}
