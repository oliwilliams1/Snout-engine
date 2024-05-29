#include <stdio.h>
#include <glew.h>
#include <glut.h>

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_ALPHA);

	int width = 1920;
	int height = 1080;

	int x = 200;
	int y = 100;
	glutInitWindowPosition(x, y);
	int win = glutCreateWindow("Render Engine");
	printf("window id: %d\n", win);

	GLclampf Red = 0.0f, Green = 0.0f, Blue = 0.0f, Alpha = 0.0f;
	glClearColor(Red, Green, Blue, Alpha);

	//glutDisplayFunc(RencderSceneCB);
	glutMainLoop();
	return 0;
}