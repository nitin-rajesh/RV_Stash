#include<stdlib.h>
#include<GL/glut.h>
#include<time.h>
#include<Windows.h>

GLfloat vertices[] = {
	-1.0,-1.0,-1.0,
	 1.0,-1.0,-1.0,
	 1.0, 1.0,-1.0, 
	-1.0, 1.0,-1.0, 
	-1.0,-1.0, 1.0,
	 1.0,-1.0, 1.0, 
	 1.0, 1.0, 1.0, 
	-1.0, 1.0, 1.0 
};

GLfloat colors[] = {
        0,0,0,
        1,0,0,
        1,1,0,
        0,1,0,
        0,0,1,
        0,1,0,
        1,1,1,
        0,1,1
};

GLubyte cubeIndices[] = {
    0,3,2,1,
    2,3,7,6,
    0,4,7,3,
    1,2,6,5,
    4,5,6,7,
    0,1,5,4
};

static GLfloat theta[] = {0,0,0};
static GLfloat beta[] = {0,0,0};
static GLint axis = 2;

void displaySingle(void){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glRotatef(theta[0], 1.0, 0.0, 0.0);
    glRotatef(theta[1], 0.0, 1.0, 0.0);
    glRotatef(theta[2], 0.0, 0.0, 1.0);

    glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, cubeIndices);

    glBegin(GL_LINES);
        glVertex3f(0,0,0);
        glVertex3f(1,1,1);
    glEnd();

    glFlush();
}

void spinCube(){
    Sleep(2);
    theta[axis] += 2.0;
    if(theta[axis] > 360.0)
        theta[axis] -= 360.0;
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y){
    if(button = GLUT_LEFT_BUTTON && state == GLUT_DOWN) axis = 0;
    if(button = GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) axis = 1;
    if(button = GLUT_LEFT_BUTTON && state == GLUT_DOWN) axis = 2;
}

void myReshape(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(-2.0, 2.0, -2.0 * (GLfloat)h / (GLfloat)w,
			2.0 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);
	else
		glOrtho(-2.0 * (GLfloat)w / (GLfloat)h,
			2.0 * (GLfloat)w / (GLfloat)h, -2.0, 2.0, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Color cube");
    glutDisplayFunc(displaySingle);
    glutReshapeFunc(myReshape);
    glutIdleFunc(spinCube);
    glutMouseFunc(mouse);
    glEnable(GL_DEPTH_TEST);
    glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, colors);
    glColor3f(1,1,1);
    glutMainLoop();
}
