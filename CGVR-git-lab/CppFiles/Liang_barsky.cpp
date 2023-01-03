#include<stdio.h>
#include<GL/glut.h>

double xmin, ymin, xmax, ymax;
double xvmin, yvmin, xvmax, yvmax;

int n = 4;

struct line_segment{
    int x1;
    int y1;
    int x2;
    int y2;
};

struct line_segment ls[10] = {
    {20,30,120,40},
    {20,120,50,30},
    {120,400,70,300},
    {430,200, 71, 15},
};

bool clipTest(double p, double q, double *u1, double *u2){
    double r;

    if(p) r = q/p;

    if(p < 0.0){
        if(r > *u1) *u1 = r;
        if(r > *u2) return false; //line is outside
    }
    else{
        if(p > 0.0){
            if(r < *u2) *u2 = r;
            if(r < *u1) return false; //line is outside
        }
        else{
            if(p == 0.0){
                if(q < 0.0) return false; //line parallel, but outside
            }
        }
    }
    return true;
}

void liangBarsky(double x0, double y0, double x1, double y1){
    double dx = x1 - x0, dy = y1 - y0, u1 = 0.0, u2 = 1.0;

    glColor3f(1.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(xvmin, yvmin);
        glVertex2f(xvmax, yvmin);
        glVertex2f(xvmax, yvmax);
        glVertex2f(xvmin, yvmax);
    glEnd();

    if(clipTest(-dx, x0-xmin, &u1, &u2))
    if(clipTest( dx, xmax-x0, &u1, &u2))
    if(clipTest(-dy, y0-ymin, &u1, &u2))
    if(clipTest( dy, ymax-y0, &u1, &u2)){
        if(u2 < 1.0){
            x1 = x0 + u2*dx;
            y1 = y0 + u2*dy;
        }
        if(u1 > 0.0){
            x0 = x0 + u1*dx;
            y0 = y0 + u1*dy;
        }

        double sx = (xvmax-xvmin)/(xmax-xmin);
        double sy = (yvmax-yvmin)/(ymax-ymin);
        double vx0 = xvmin + (x0-xmin)*sx;
        double vy0 = yvmin + (y0-ymin)*sy;
        double vx1 = xvmin + (x1-xmin)*sx;
        double vy1 = yvmin + (y1-ymin)*sy;

        glColor3f(0.0,0.0,1.0);

        glBegin(GL_LINES);
            glVertex2d(vx0,vy0);
            glVertex2d(vx1,vy1);
        glEnd();
    }
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);
    for(int i = 0; i < n; i++){
        glBegin(GL_LINES);
            glVertex2d(ls[i].x1, ls[i].y1);
            glVertex2d(ls[i].x2, ls[i].y2);
        glEnd();
    }

    glColor3f(0.0,0.0,1.0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(xmin,ymin);
        glVertex2f(xmax,ymin);
        glVertex2f(xmax,ymax);
        glVertex2f(xmin,ymax);
    glEnd();

    for(int i = 0; i < n; i++){
        liangBarsky(ls[i].x1, ls[i].x2, ls[i].y1, ls[i].y2);
    }
    glFlush();
}

void myinit(){
    glClearColor(1,1,1,1);
    glColor3f(1,0,0);
    glLineWidth(2);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,500,0,500);
}

int main(int argc, char *argv[]){
    xmin = 10, ymin = 10, xmax = 350, ymax = 350;
    xvmin = 120, yvmin = 120, xvmax = 380, yvmax = 380;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);

    glutCreateWindow("LB Clipper");
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();

}
