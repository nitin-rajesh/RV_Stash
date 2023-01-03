#include<iostream>
#include<GL/glut.h>
using namespace std;

int poly_size=10, poly_points[20][2]={{65,0},{90,50},{14,55},{105,90},{120,140},{20,140},{35,90},{0,55},{50,50}}, 
    org_poly_size, org_poly_points[20][2];
int clipper_size = 4, clipper_points[20][2] = {{100,100},{400,100},{400,400},{100,400}};
int iter = 0;

const int MAX_POINTS = 20;

void drawPoly(int p[][2], int n){
    glBegin(GL_POLYGON);
    for(int i = 0; i < n; i++){
        glVertex2f(p[i][0], p[i][1]);
    }
    glEnd();
}

int x_intersect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
    int num = (x1*y2 - y1*x2)*(x3 - x4) - (x1 - x2)*(x3*y4 - y3*x4);
    int den = (x1 - x2)*(y3 - y4) - (y1 - y2)*(x3 - x4);
    return num/den;
}

int y_intersect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
    int num = (x1*y2 - y1*x2)*(y3 - y4) - (y1 - y2)*(x3*y4 - y3*x4);
    int den = (x1 - x2)*(y3 - y4) - (y1 - y2)*(x3 - x4);
    return num/den;
}

void clip(int poly_points[][2], int& poly_size, int x1, int y1, int x2, int y2){
    int new_points[MAX_POINTS][2], new_poly_size = 0;

    //(ix, iy) and (kx, ky) are the points
    for(int i = 0; i < poly_size; i++){
        //i and k form a line in the polygon
        int k = (i+1) % poly_size;
        int ix = poly_points[i][0], iy = poly_points[i][1];
        int kx = poly_points[k][0], ky = poly_points[k][1];

        //calculating position of first point w/r to clipper line
        int i_pos = (x2 - x1)*(iy - y1) - (y2 - y1)*(ix - x1);

        //calculating position of second point w/r to clipper line
        int k_pos = (x2 - x1)*(ky - y1) - (y2 - y1)*(kx - x1);

        //Case 1: Both points are inside
        if(i_pos >= 0 && k_pos >= 0){
            //second point is added
            new_points[new_poly_size][0] = kx;
            new_points[new_poly_size][1] = ky;
            new_poly_size++;
        }
        //Case 2: First point is outside
        else if(i_pos < 0 && k_pos >= 0){
            //point of intersection and second point are added
            new_points[new_poly_size][0] = x_intersect(x1, y1, x2, y2, ix, iy, kx, ky);
            new_points[new_poly_size][1] = y_intersect(x1, y1, x2, y2, ix, iy, kx, ky);
            new_poly_size++;

            new_points[new_poly_size][0] = kx;
            new_points[new_poly_size][1] = ky;
            new_poly_size++;
        }
        //Case 3: Second point is outside
        else if(i_pos >= 0 && k_pos < 0){
            //point of intersection is added
            new_points[new_poly_size][0] = x_intersect(x1, y1, x2, y2, ix, iy, kx, ky);
            new_points[new_poly_size][1] = y_intersect(x1, y1, x2, y2, ix, iy, kx, ky);
            new_poly_size++;          
        }
        else{
            //do nothing
        }
    }

    poly_size = new_poly_size;

    for(int i = 0; i < poly_size; i++){
        poly_points[i][0] = new_points[i][0];
        poly_points[i][1] = new_points[i][1];
    }
}

void init(){
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 500, 0, 500, 0, 500);
    glClear(GL_COLOR_BUFFER_BIT);
}

void display(){
    init();
    glColor3f(1,0,0);
    drawPoly(clipper_points, clipper_size);

    glColor3f(0,1,0);
    drawPoly(org_poly_points, org_poly_size);

    for(int i = 0; i < clipper_size; i++){
        int k = (i+1)%clipper_size;

        clip(poly_points, poly_size, 
            clipper_points[i][0],clipper_points[i][1], 
            clipper_points[k][0],clipper_points[k][1]);
    }

    glColor3f(0,0,1);
    drawPoly(poly_points, poly_size);
    glFlush();
}

void mouse(int button, int state, int x, int y){
    if(button == GLUT_LEFT_BUTTON && state == GLUT_UP){
        int xc1 = x;
        int yc1 = y;
        poly_points[iter % poly_size][0] = xc1;
        poly_points[iter % poly_size][1] = yc1;
        org_poly_points[iter % poly_size][0] = xc1;
        org_poly_points[iter % poly_size][1] = yc1;
        iter++;

        if(iter >= 3){
            glColor3f(0,0,1);
            glPointSize(5);
            glBegin(GL_POINTS);
            glVertex2i(xc1,yc1);
            glEnd();

            glutPostRedisplay();
        }
    }
}

int main(int argc, char *argv[]){

    org_poly_size = poly_size;
    for (int i = 0; i < poly_size; i++) {
		org_poly_points[i][0] = poly_points[i][0];
		org_poly_points[i][1] = poly_points[i][1];
	}

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Poly clip");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}