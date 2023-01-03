#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<time.h>
#include<GL/glut.h>
#include<Windows.h>
using std::cout;

#define MAX_POINTS 100
#define W_H 500
#define W_W 500

int m = 0, pointCount = 4; 
int iter = 0;
typedef float point[2];
point p[MAX_POINTS];
static float intx[10] = {0};

void drawLine(float x1, float y1, float x2, float y2){
    Sleep(1);
    glColor3f(0,0,1);
    glBegin(GL_LINES);
        glVertex2f(x1,y1);
        glVertex2f(x2,y2);
    glEnd();
    glFlush();
}

void edgeDetect(float x1, float y1, float x2, float y2, int scanline){
    float temp;
    if(y2 < y1){
        temp = y1;
        y1 = y2;
        y2 = temp;

        temp = x1;
        x1 = x2;
        x2 = temp;
    }
    if(scanline > y1 && scanline < y2){
        intx[m++] = x1 + (x2-x1)*(scanline-y1)/(y2-y1);
    }
}

void scanFill(point p[]){
    for(int s1 = -W_H/2; s1 <= W_H/2; s1++){
        m = 0;
        for(int i = 0; i < pointCount; i++){
            edgeDetect(p[i][0], p[i][1], p[(i+1)%pointCount][0],p[(i+1)%pointCount][1],s1);
        }
        std::sort(intx,intx+m);
        if(m >= 2){
            for(int i = 0; i < m-1; i+= 2){
                drawLine(intx[i],s1,intx[i+1],s1);
            }
        }
    }
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_LINE_LOOP);
    for(int i = 0; i < pointCount; i++){
        glVertex2fv(p[i]);
    }
    glEnd();
    scanFill(p);
    glFlush();
}

void myInit(){
    glClearColor(1.0,1.0,1.0,1.0);
    gluOrtho2D(-W_W/2,W_W/2,-W_H/2,W_H/2);

}

void mouse(int button, int state, int x, int y){
    if(button == GLUT_LEFT_BUTTON && state == GLUT_UP){
        int xc1 = x - W_W/2;
        int yc1 = W_H/2 - y;
        p[iter % pointCount][0] = xc1;
        p[iter % pointCount][1] = yc1;
        iter++;
        glColor3f(0,0,1);
        glPointSize(5);
        glBegin(GL_POINTS);
            glVertex2i(xc1,yc1);
        glEnd();

        glutPostRedisplay();

    }
}
    

int main(int argc, char *argv[]){
    if(argc > 1){
        pointCount = atoi(argv[1]);
    }
    if(pointCount < 3)
        pointCount = 3;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(W_W,W_H);
    glutInitWindowPosition(100,100);

    glutCreateWindow("Scan line");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    myInit();
    glutMainLoop();
    return 0;
}
