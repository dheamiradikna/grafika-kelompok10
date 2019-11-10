#include <GL/glut.h>
#include <GL/glu.h>
#include <math.h>
#include <iostream>
using namespace std;

float cc[20][2];

void init(void);
void display(void);
void keyboard(unsigned char, int, int);
void resize(int, int);
void draw_star(float,float);
void house(float,float,float);
void circle1(float);
void stand(float ,float ,float );
float  h=5,h1=6,d1=4,g=1,g1=2;

int main (int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1100, 1100);
	glutInitWindowPosition(100, 10);
	glutCreateWindow("3D map");
	init();
	
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);

	glutReshapeFunc(resize);

	glutMainLoop();
	return 0;
}


void house(float x,float y,float z) // Balok
{
	// Kanan
	glColor3f(0.7,0.7,0.7);
	glBegin(GL_POLYGON);
	glVertex3f(x,y,z);
	glVertex3f(x,y,z+25);
	glVertex3f(x,y+25,z+25);
	glVertex3f(x,y+25,z);
	glEnd();

	// Kiri
	glColor3f(0.7,0.7,0.7);
	glBegin(GL_POLYGON);
	glVertex3f(x-25,y,z);
	glVertex3f(x-25,y+25,z);
	glVertex3f(x-25,y+25,z+25);
	glVertex3f(x-25,y,z+25);
	glEnd();

	// Depan
	glColor3f(0.7,0.7,0.7);
	glBegin(GL_POLYGON);
	glVertex3f(x,y,z+25);
	glVertex3f(x-25,y,z+25);
	glVertex3f(x-25,y+25,z+25);
	glVertex3f(x,y+25,z+25);
	glEnd();

	// Belakang
	glColor3f(0.7,0.7,0.7);
	glBegin(GL_POLYGON);
	glVertex3f(x-25,y,z);
	glVertex3f(x-25,y+25,z);
	glVertex3f(x,y+25,z);
	glVertex3f(x,y,z);
	glEnd();

	// Atas
	glColor3f(0.7,0.7,0.7);
	glBegin(GL_POLYGON);
	glVertex3f(x-25,y+25,z);
	glVertex3f(x,y+25,z);
	glVertex3f(x,y+25,z+25);
	glVertex3f(x-25,y+25,z+25);
	glEnd();
}


void house1() // Kiri(-175) Kanan(150), Atas Bawah, Maju(175) Mundur(-200)
{
	// Baris 1
	house(-175,0,-200);
	house(-175,0,-175);
	house(-175,0,-150);
    house(-175,0,-125);
    house(-175,0,-100);
    house(-175,0,-75);
    house(-175,0,-50);
    house(-175,0,-25);
    house(-175,0,0);
    house(-175,0,25);
    house(-175,0,50);
    house(-175,0,75);
    house(-175,0,100);
    house(-175,0,125);
    house(-175,0,150);
    house(-175,0,175);
    
    // Baris 2
	
	// Baris 3
    house(-125,0,175);
    house(-125,0,-200);
    
    // Baris 4
    house(-100,0,175);
    house(-100,0,-200);
    
    // Baris 5
    house(-75,0,175);
    house(-75,0,-200);
    
	// Baris 6
	house(-50,0,175);
	house(-50,0,-200);
    
	// Baris 5
	house(-25,0,175);
	house(-25,0,-200);
    
	// Baris 6
	house(0,0,175);
	house(0,0,-200);
    
	// Baris 7
	house(25,0,175);
	house(25,0,-200);
    
	// Baris 8
	house(50,0,175);
	house(50,0,-200);
    
	// Baris 9
	house(75,0,175);
	house(75,0,-200);
    
	// Baris 10
	house(100,0,175);
	house(100,0,-200);
    
	// Baris 11
	house(125,0,175);
	house(125,0,-200);
    
	// baris 12
	house(150,0,175);
	house(150,0,-200);
	
	// Baris 13
    
    // Baris 14
	house(200,0,-200);
    house(200,0,-175);
	house(200,0,-150);
    house(200,0,-125);
    house(200,0,-100);
    house(200,0,-75);
    house(200,0,-50);
    house(200,0,-25);
    house(200,0,0);
    house(200,0,25);
    house(200,0,50);
    house(200,0,75);
    house(200,0,100);
    house(200,0,125);
    house(200,0,150);
    house(200,15,175);
}


void init(void)
{
	glClearColor(0.0,0.0,0.0,0.0);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_MODELVIEW);
}


void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	/* draw the floor */
	glBegin(GL_QUADS);
	
	glColor3f(0.8,0.6,0.4);
    glVertex3f(-200.0, 0.0, -200.0);
	
	glColor3f(0.8,0.6,0.4);
	glVertex3f(-200.0, 0.0, 200.0);
	
	glColor3f(0.8,0.6,0.4);
	glVertex3f(200.0, 0.0, 200.0);
	
	glColor3f(0.8,0.6,0.4);
	glVertex3f(200.0, 0.0, -200.0);
	
	glEnd();
	glFlush();
    
	house1();
	glFlush();
	glutSwapBuffers();


}


void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 'a':
		case 'A':
		glTranslatef(5.0, 0.0, 0.0); // Kiri
		break;
		
		case 'd':
		case 'D':
		glTranslatef(-5.0, 0.0, 0.0); // Kanan
		break;
		
		case 'w':
		case 'W':
		glTranslatef(0.0, 0.0, 5.0); // Maju
		break;
	
		case 's':
		case 'S':
		glTranslatef(0.0, 0.0, -5.0); // Mundur
		break;
		
		case 'z':
		case 'Z':
		glTranslatef(0.0, 5.0, 0.0); // Bawah
		break;
		
		case 'x':
		case 'X':
		glTranslatef(0.0, -5.0, 0.0); // Atas
		break;
				
		case 'q':
		case 'Q':
    	glRotatef(-2,1.0,0.0,0.0); // Jempalikan

    	case 'e':
    	case 'E':
        glRotatef(1,0.0,1.0,0.0); // Muter

	}
	display();
}

void resize(int width, int height)
{
	if (height == 0) height = 1;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(80.0, width / height, 1.0, 600.0);
	glTranslatef(0.0, -15.0, -320.0);
	glMatrixMode(GL_MODELVIEW);
}

