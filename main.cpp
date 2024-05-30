#include <stdio.h>
#include <glew.h>
#include <glut.h>
#include <ogldev_math_3d.h>

GLuint VBO;

static void RenderSceneCB()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glDisableVertexAttribArray(0);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glDrawArrays(GL_POINTS, 0, 1);

	glDisableVertexAttribArray(0);

	glutSwapBuffers();
}

static void createVertexBuffer()
{
	Vector3f Vertices[1];
	Vertices[0] = Vector3f(0.0f, 0.0f, 0.0f);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_ALPHA);

	int width = 1920;
	int height = 1080;

	int x = 200;
	int y = 100;
	glutInitWindowPosition(x, y);
	int win = glutCreateWindow("Render Engine");
	
	// must be done after glut init
	GLenum res = glewInit();
	if (res != GLEW_OK) {
		fprintf(stderr, "Erroor: '%s'\n", glewGetErrorString(res));
	}

	GLclampf Red = 0.0f, Green = 0.0f, Blue = 0.0f, Alpha = 0.0f;
	glClearColor(Red, Green, Blue, Alpha);

	createVertexBuffer();

	glutDisplayFunc(RenderSceneCB);

	glutMainLoop();

	return 0;
}