#include <stdio.h>
#include <glut.h>

void Display(void);
void Reshape(int, int);
void init();
void Keyboard(unsigned char, int, int);
void Mouse(int, int, int, int);


float color[3] = { 0.0, 0.0, 0.0 };

void init() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(0, 1, 0, 1, 0, 1);
}

void Display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	printf("%f, %f, %f\n", color[0], color[1], color[2]);
	glColor3f(color[0], color[1], color[2]);
	glBegin(GL_TRIANGLES);
	glVertex3f(-0.5, -0.5, 0.0);
	glVertex3f(0.0, 0.5, 0.0);
	glVertex3f(0.5, -0.5, 0.0);
	glEnd();
	glutSwapBuffers();
}

void Reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
}

void Keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'q': case 'Q':
		color[0] += 0.1;
		break;
	case 'a': case 'A':
		color[0] -= 0.1;
		break;
	case 'w': case 'W':
		color[1] += 0.1;
		break;
	case 's': case 'S':
		color[1] -= 0.1;
		break;
	case 'e': case 'E':
		color[2] += 0.1;
		break;
	case 'd': case 'D':
		color[2] -= 0.1;
		break;
	}
	if (color[0] > 1) color[0] = 1.0;
	else if (color[0] < 0) color[0] = 0.0;
	if (color[1] > 1) color[1] = 1.0;
	else if (color[1] < 0) color[1] = 0.0;
	if (color[2] > 1) color[2] = 1.0;
	else if (color[2] < 0) color[2] = 0.0;
	glutPostRedisplay();
}

void Mouse(int btn, int state, int x, int y) {
	printf("%d", btn);
	switch (btn) {
	case GLUT_LEFT_BUTTON:
		printf("%d", btn);
		color[0] -= 0.05;
		color[1] -= 0.05;
		color[2] -= 0.05;
		break;
	case GLUT_RIGHT_BUTTON:
		printf("%d", btn);
		color[0] += 0.05;
		color[1] += 0.05;
		color[2] += 0.05;
		break;
	}
	if (color[0] > 1) color[0] = 1.0;
	else if (color[0] < 0) color[0] = 0.0;
	if (color[1] > 1) color[1] = 1.0;
	else if (color[1] < 0) color[1] = 0.0;
	if (color[2] > 1) color[2] = 1.0;
	else if (color[2] < 0) color[2] = 0.0;
	glutPostRedisplay();
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1024, 768);
	glutCreateWindow("Suck my Dick");

	init();

	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(Keyboard);
	glutMouseFunc(Mouse);

	glutMainLoop();
	return 0;
	
}
