#include<iostream>
#include<GL/glut.h>
#include<math.h>
using std::cout;

#define W_H 500
#define W_W 500

int wid1, wid2, t;
static GLfloat spin = 0.0;

void display(){
    glutSetWindow(t);
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glLoadIdentity();
    glRotatef(spin,0,0,1);
    glBegin(GL_POLYGON);
        glColor3f(1,0,0);
        glVertex3f(-0.25,-0.25,0.25);

        glColor3f(0,1,0);
        glVertex3f(0.25,-0.25,0.25);

        glColor3f(0,0,1);
        glVertex3f(0.25,0.25,0.25);

        glColor3f(1,0,1);
        glVertex3f(-0.25,0.25,0.25);
    glEnd();
    glPopMatrix();

    if(t == wid1){
        glFlush();
        t = wid2;
    }
    else{
        glutSwapBuffers();
        t = wid1;
    }
}

void myInit(){
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glOrtho(-1,1,-1,1,-1,1);
    glClearColor(1,1,1,1);
    glColor3f(1,0,0);
}

void spinRect(){
    spin += 0.05;
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y){
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        glutIdleFunc(spinRect);


    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
        glutIdleFunc(NULL);
            
}

int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(W_W, W_H);
    wid1 = glutCreateWindow("Single Buffer");
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    myInit();

    glutInit(&argc, argv);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(W_W, W_H);
    wid1 = glutCreateWindow("Double Buffer");
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    myInit();

    t = wid1;

    glutMainLoop();
    return 0;
}