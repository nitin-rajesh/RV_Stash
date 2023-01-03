#include <iostream>
#include <GL/glut.h>
#include <math.h>

#define W_H 500
#define W_W 500

using std::cout;
using std::endl;

int xc1, yc1, x2, y2;

void drawPixel(int x, int y){
    glColor3f(0,0,1);
    glPointSize(5);
    glBegin(GL_POINTS);
        glVertex2i(x,y);
    glEnd();
}

void drawLine(){
    int dx = x2-xc1, dy = y2-yc1;
    int incx = 1, incy = 1, inc1, inc2;
    int x = xc1, y = yc1, p;

    if(dx < 0){
        dx = fabs(dx);
        incx = -1;
    }
    if(dy < 0){
        dy = fabs(dy);
        incy = -1;
    }

    //For slope < 1
    if(dx > dy){
        drawPixel(x,y);
        p = 2*dy - dx;

        inc1 = 2*(dy - dx);
        inc2 = 2*dy;
        for(int i = 0; i < dx; i++){
            if(p > 0){
                y += incy;
                p += inc1;
            }
            else{
                p += inc2;
            }
            x += incx;
            drawPixel(x,y);
        }
    }
    //For slope > 1
    else{
        drawPixel(x,y);
        p = 2*dx - dy;
        inc1 = 2*(dx-dy);
        inc2 = 2*dx;
        for(int i = 0; i < dy; i++){
            if(p > 0){
                x += incx;
                p += inc1;
            }
            else{
                p += inc2;
            }
            y += incy;
            drawPixel(x,y);
        } 
    }

    glFlush();
}

void display(){}

void myInit(){
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(-250,250,-250,250);
}

void mouse(int button, int state, int x, int y){
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        xc1 = x - W_W/2;
        yc1 = W_H/2 - y;
    }
    if(button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        x2 = x - W_W/2;
        y2 = W_H/2 - y;
        cout<<"Drawn line from "<<xc1<<","<<yc1<<" to "<<x2<<","<<y2<<endl;
        drawLine();
    }
    
}

int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(W_W, W_H);
    glutCreateWindow("Bresenham Line Drawing");
    myInit();
    glutMouseFunc(mouse);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}