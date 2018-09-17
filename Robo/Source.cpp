#include <stdio.h>
#include <glut.h>

void Display(void);
void Reshape(int, int);

int win[2] = { 0, 0 };
int pos[2] = { 0, 0 };

void Display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutSwapBuffers();
}

void Reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1024, 768);
	glutCreateWindow("Suck my Dick");

	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);

	glutMainLoop();
	system("pause");
	return 0;
	
}
