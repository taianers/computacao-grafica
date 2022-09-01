//#include <windows.h>
#include <GL/glut.h>

GLfloat angleX = -45.0f;
GLfloat angleY = 30.0f;

bool temClip = false;

void Display(void) {    
    glEnable(GL_DEPTH_TEST);

    GLdouble eqn[4] = { 0.0, 1.0, 0.0, 0.0 };
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glClipPlane(GL_CLIP_PLANE0, eqn);
    
    temClip ? glEnable(GL_CLIP_PLANE0) : glDisable(GL_CLIP_PLANE0); // verifica se habilita ou desabilita recorte

    glRotatef(90.0, 1.0, 0.0, 0.0);
    glColor3f(0, 0, 0); // cor sólida do cubo
    glutSolidCube(0.6);

    glColor3f(0.4, 0, 1); // linha roxa do cubo
    glutWireCube(0.6);
    glPopMatrix();

    glFlush();
}

void ChangeSize(GLsizei width, GLsizei height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30.0, width / height, 1.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -3.0f);
    glRotatef(angleY, 1.0f, 0.0f, 0.0f);
    glRotatef(angleX, 0.0f, 1.0f, 0.0f);
}

void keyBoardFunc(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_LEFT:
            angleX += 1;
            break;
        case GLUT_KEY_RIGHT:
            angleX -= 1;
            break;
        case GLUT_KEY_DOWN:
            angleY -= 1;
            break;
        case GLUT_KEY_UP:
            angleY += 1;
            break;
        case GLUT_KEY_F12:
            temClip = !temClip; // habilita e desabilita recorte
            break;
    }
    if (angleX == -360) angleX = 0;
    if (angleY == -360) angleY = 0;

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -3.0f);
    glRotatef(angleY, 1.0f, 0.0f, 0.0f);
    glRotatef(angleX, 0.0f, 1.0f, 0.0f);
    Display();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Exercicio-02 - Parte 1 | RECORTE COM F12");
    glutSpecialFunc(keyBoardFunc);
    glutDisplayFunc(Display);
    glutReshapeFunc(ChangeSize);
    glutMainLoop();
    return 0;
}
