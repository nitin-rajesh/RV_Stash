#include<iostream>
#include<GL/glut.h>
#include<math.h>
using std::cout;
using std::endl;

#define W_W 800
#define W_H 600

#define SPR 75.f
#define DPI (3.1415F/180.f)  //Degrees to radians

#define SPHERE_GA(radius,theta,phi) {         \
    (radius)*sin(DPI*(theta))*cos(DPI*(phi)), \
    (radius)*cos(DPI*(theta))*cos(DPI*(phi)), \
    (radius)*sin(DPI*(phi))                   \
}

int rotate = -50;

void displayLoop(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    //green cap
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0,1,0);
    glVertex3f(0,0,-SPR);
    for(int theta1 = -180; theta1 <= 180; theta1 += 10){
        float p1[3] = SPHERE_GA(SPR,theta1,-80);
        glVertex3fv(p1);
    }
    glEnd();

    for(int i = -80; i < 80; i += 10){
        glBegin(GL_QUAD_STRIP);
        for(int theta1 = -180; theta1 <= 180; theta1 += 10){
            glColor3f(1,1,1);
            float p1[3] = SPHERE_GA(SPR,theta1,i);
            glVertex3fv(p1);

            glColor3f(.8f,.8f,.8f);
            float p2[3] = SPHERE_GA(SPR,theta1,i+10);
            glVertex3fv(p2);
        }
        glEnd();
    }

    //red cap
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1,0,0);
    glVertex3f(0,0,SPR);
    for(int theta1 = -180; theta1 <= 180; theta1 += 10){
        float p1[3] = SPHERE_GA(SPR,theta1,80);
        glVertex3fv(p1);
    }
    glEnd();

    glFlush();

}

void mouse(int button, int state, int x, int y){

    if(button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        rotate = (rotate + 1) % 180 - 90;
        
        glRotatef(rotate,0,1,0);
        glutPostRedisplay();
    }
    
}

int main(int argc, char *argv[]){
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(W_W,W_H);
    glutCreateWindow("Sphere approximation");
    glutDisplayFunc(displayLoop);
    glutMouseFunc(mouse);

    glClearColor(0,0,0,1.f);
    glOrtho(-W_W/2,W_W/2,-W_H/2,W_H/2,-W_W/2,W_W/2);

    //Camera angle
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glTranslatef(0,0,-100);
    glRotatef(rotate,0,1,0);
    glutMainLoop();
}