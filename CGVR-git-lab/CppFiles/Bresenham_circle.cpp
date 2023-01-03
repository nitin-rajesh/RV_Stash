#include<iostream>
#include<GL/glut.h>
#include<math.h>
using std::cout;

#define W_H 500
#define W_W 500

int xc, yc, xr, yr, r;

void drawCircle(int xc, int yc, int x, int y){
    glColor3f(0,0,1);
    glPointSize(3);
    glBegin(GL_POINTS);
        glVertex2i(xc+x,yc+y);
        glVertex2i(xc-x,yc+y);
        glVertex2i(xc+x,yc-y);
        glVertex2i(xc-x,yc-y);

        glVertex2i(xc+y,yc+x);
        glVertex2i(xc+y,yc-x);
        glVertex2i(xc-y,yc+x);
        glVertex2i(xc-y,yc-x);
    glEnd();
}

void bresCircle(int xc, int yc, int r){
    int x = 0, y = r;
    int d = 3 - 2*r;
    while(x < y){
        drawCircle(xc,yc,x,y);
        x++;
        if(d < 0){
            d += 4*x+6;
        }
        else{
            y--;
            d += 4*(x-y)+10;
        }
        drawCircle(xc,yc,x,y);
    }
    glFlush();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
}

void myInit(){
    glClearColor(1,1,1,1);
    gluOrtho2D(-W_W/2,W_W/2,-W_H/2, W_H/2);
}

void mouse(int button, int state, int x, int y){
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        xc = x - W_W/2;
        yc = W_H/2 - y;
    }
    if(button == GLUT_LEFT_BUTTON && state == GLUT_UP){
        xr = x - W_W/2;
        yr = W_H/2 - y;
        r = sqrt((float)(pow(xc-xr,2) + pow(yc-yr,2)));
        cout<<"Circle with center at "<<xc<<","<<yc<<" and radius"<< r;
        bresCircle(xc,yc,r);
    }
}

int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(W_W,W_H);
    glutCreateWindow("Bresenham circle drawing");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    myInit();
    glutMainLoop();
    return 0;
}