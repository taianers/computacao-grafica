//#include <windows.h>
#include <GL/glut.h>

GLfloat rotate = 0;
GLfloat translateX = 0;
GLfloat translateY = 0;

void rotacionar(unsigned char key, int x, int y) {
    if (key == 'q') rotate++; // rotaciona para esquerda
	if (key == 'w') rotate--; // rotaciona para direita
    if (key == 27) exit(0); // ESC encerra o programa
}

void transladar(unsigned char key, int x, int y) {
    if (key == 's') translateX++; // para esquerda
	if (key == 'a') translateX--; // para direita
    if (key == 'x') translateY++; // para cima
	if (key == 'z') translateY--; // para baixo
}

void base(){
    glBegin(GL_LINE_LOOP);
	glVertex2f(5, 5);
	glVertex2f(5, 255);
	glVertex2f(255, 255);
	glVertex2f(255, 5);
	glEnd();
}

void porta() {
	
    glBegin(GL_LINE_STRIP);
	glVertex2f(200, 5);
	glVertex2f(200, 10);
	glVertex2f(250, 10);
	glVertex2f(250, 5);
	glEnd();
}

void cama(){

	//base cama
    glBegin(GL_LINE_LOOP);
	glVertex2f(20, 20);
	glVertex2f(20, 120);
	glVertex2f(80, 120);
	glVertex2f(80, 20);
	glEnd();

	//travesseiro
	glBegin(GL_LINE_LOOP);
	glVertex2f(30, 25);
	glVertex2f(30, 40);
	glVertex2f(70, 40);
	glVertex2f(70, 25);
	glEnd();

	//cobertor
	glBegin(GL_LINE_STRIP);
	glVertex2f(20, 45);
	glVertex2f(80, 45);
	glEnd();
}

void quardaRoupa(){

    glBegin(GL_LINE_LOOP);
	glVertex2f(10, 162);
	glVertex2f(10, 248);
	glVertex2f(53, 248);
	glVertex2f(53, 162);
	glEnd();
}

void escrivaninha(){
	
    glBegin(GL_LINE_STRIP);
	glVertex2f(200, 255);
	glVertex2f(200, 240);
	glVertex2f(235, 240);
	glVertex2f(235, 200);
	glVertex2f(255, 200);
	glEnd();
}

void cadeira(){

	//base de fora
    glBegin(GL_LINE_LOOP);
	glVertex2f(203, 208);
	glVertex2f(203, 233);
	glVertex2f(228, 233);
	glVertex2f(228, 208);
	glEnd();

	//base de dentro
    glBegin(GL_LINE_LOOP);
	glVertex2f(208, 213);
	glVertex2f(208, 228);
	glVertex2f(228, 228);
	glVertex2f(228, 213);
	glEnd();
}

void lixeira(){

	glPushMatrix();
    glRotatef(rotate, 0, 0, 1);
    glTranslatef(translateX, translateY, 1);
	
	glBegin(GL_LINE_LOOP);
	glVertex2f(240, 183);
	glVertex2f(240, 195);
	glVertex2f(252, 195);
	glVertex2f(252, 183);
	glEnd();
	
	glBegin(GL_LINE_STRIP);
	glVertex2f(240, 183);
	glVertex2f(252, 195);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2f(240, 195);
	glVertex2f(252, 183);
	glEnd();

	glPopMatrix();
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f (0.0, 0.0, 0.0);

	
    base();
    cama();
    quardaRoupa();
    escrivaninha();
    cadeira();
	porta();
	lixeira();

	glutKeyboardFunc(rotacionar);
	glutKeyboardFunc(transladar);
    glutPostRedisplay();
	glFlush();
}

void init(void){
    glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 260, 0, 260);
}

int main (int argc, char **argv){
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(830, 410);
	glutCreateWindow("Quarto - EP01");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
