#include<GL/glut.h>


double xmin, ymin, xmax, ymax;
double xvmin, yvmin, xvmax, yvmax;

typedef int outcode;

const int RIGHT = 4;
const int LEFT = 8;
const int TOP = 1;
const int BOTTOM = 2;

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

outcode computeOutcode(double x, double y){
    outcode code = 0;
    if(y > ymax)
        code |= TOP;
    else if(y < ymin)
        code |= BOTTOM;
    if(x > xmax)
        code |= RIGHT;
    else if(x < xmin)
        code |= LEFT;

    return code;     
}

void cohenSutherland(double x0, double y0, double x1, double y1){
    outcode oc0, oc1, ocOut;

    bool accept = false, done = false;

    oc0 = computeOutcode(x0,y0);
    oc1 = computeOutcode(x1,y1);

    do{
        if(!(oc0|oc1)){
            accept = true;
            done = true;
        }
        else if(oc0 & oc1){
            done = false;
        }
        else{
            double x, y;

            ocOut = oc0 ? oc0 : oc1;
            
            if(ocOut & TOP){
                x = x0 + (x1-x0)*(ymax-y0)/(y1-y0);
                y = ymax;
            }
            else if (ocOut & BOTTOM){
                x = x0 + (x1-x0)*(ymin-y0)/(y1-y0);
                y = ymin;
            }
            else if (ocOut & RIGHT){
                y = y0 + (y1-y0)*(xmax-x0)/(x1-x0);
                x = xmin;
            }
            else{
                y = y0 + (y1-y0)*(xmin-x0)/(x1-x0);
                x = xmin;
            }

            if(ocOut == oc0){
                x0 = x;
                y0 = y;
                oc0 = computeOutcode(x0,y0);
            }
            else{
                x1 = x;
                y1 = y;
                oc1 = computeOutcode(x1,y1);
            }
        }
            
    }while(!done);

    if(accept){
        double sx = (xvmax-yvmin)/(xmax-xmin);
        double sy = (yvmax-yvmin)/(ymax-ymin);
        double vx0 = xvmin + (x0-xmin)*sx;
        double vx1 = xvmin + (x1-xmin)*sx;
        double vy0 = yvmin + (y0-ymin)*sy;
        double vy1 = yvmin + (y1-ymin)*sy;

        glColor3f(0,0,1);
        glBegin(GL_LINES);
            glVertex2d(vx0,vy0);
            glVertex2d(vx1,vy1);
        glEnd();
    }
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,1);
    glBegin(GL_LINE_LOOP);
        glVertex2f(xmin,ymin);
        glVertex2f(xmax,ymin);
        glVertex2f(xmax,ymax);
        glVertex2f(xmin,ymax);
    glEnd();

    //draw unclipped lines
    for(int i = 0; i < n; i++){
        glBegin(GL_LINES);
            glVertex2d(ls[i].x1, ls[i].y1);
            glVertex2d(ls[i].x2, ls[i].y2);
        glEnd();
    }

    //draw viewport
    glColor3f(1,0,0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(xvmin, yvmin);
        glVertex2f(xvmax, yvmin);
        glVertex2f(xvmax, yvmax);
        glVertex2f(xvmin, yvmax);
    glEnd();

    //clip lines with cohen sutherland
    for(int i = 0; i < n; i++){
        cohenSutherland(ls[i].x1, ls[i].y1, ls[i].x2, ls[i].y2);
    }

    glFlush();
}

void myinit(){
    glClearColor(1,1,1,1);
    glColor3f(1,0,0);
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,500,0,500);
}

int main(int argc, char *argv[]){
    xmin = 10, ymin = 10, xmax = 350, ymax = 350;
    xvmin = 120, yvmin = 120, xvmax = 380, yvmax = 380;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("CS Clipper");
    myinit();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}