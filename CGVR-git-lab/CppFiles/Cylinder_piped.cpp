#include<iostream>
#include<GL/glut.h>
#include<math.h>
using std::cout;

#define W_H 500
#define W_W 500

int wid1, wid2;

void plotCirclePoints(int xc, int yc, int x, int y) {
    glColor3f(1,0,1);
    glPointSize(3);
    glBegin(GL_POINTS);
        glVertex2i(xc+x,yc+y);
        glVertex2i(xc-x,yc+y);
        glVertex2i(xc+x,yc-y);
        glVertex2i(xc-x,yc-y);

        glVertex2i(xc+y,yc+x);
        glVertex2i(xc+y,yc-x);
        glVertex2i(xc-y,yc-x);
        glVertex2i(xc-y,yc+x);
    glEnd();
}

void drawCircle(int xc, int yc, int r){
    int x = 0, y = r;
    int d = 3 - 2*r;
    while(x < y){
        plotCirclePoints(xc,yc,x,y);
        x++;
        if(d < 0){
            d += 4*x + 6;
        }
        else{
            y--;
            d += 4*(x-y) + 10;
        }
        plotCirclePoints(xc,yc,x,y);
    }
    glFlush();
}

void displayCylinder(){
    glutSetWindow(wid1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,1);
    int xc = 250, yc = 150, r = 50;
    for(int i = 100; i < 150; i += 5){
        drawCircle(xc,yc+i,r);
    }
    glFlush();
}

void drawQuad(int x, int y, int w, int h){
    glColor3f(1,0,0);
    glBegin(GL_LINE_LOOP);
        glVertex2i(x,y);
        glVertex2i(x+w,y);
        glVertex2i(x+w,y+h);
        glVertex2i(x,y+h);
    glEnd();
}

void displayParallelopiped(){
    glutSetWindow(wid2);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
    int x = 150, y = 150, w = 150, h = 150;
    for(int i = 100; i < 150; i += 5){
        drawQuad(x+i,y+i,w,h);
    }
    glFlush();
}

void myInit(){
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,W_W,0,W_H);
    glClearColor(1,1,1,1);
    glColor3f(1,0,0);
}

int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    
    glutInitWindowPosition(100,100);
    glutInitWindowSize(W_W,W_H);
    wid1 = glutCreateWindow("Cylinder");
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutDisplayFunc(displayCylinder);
    myInit();

    glutInitWindowPosition(500,100);
    glutInitWindowSize(W_W,W_H);
    wid2 = glutCreateWindow("Parallelopiped");
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutDisplayFunc(displayParallelopiped);
    myInit();

    glutMainLoop();
    return 0;


}