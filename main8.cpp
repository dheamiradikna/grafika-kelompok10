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


void house(float x,float y,float z) // Ukuran Objek Kubus
{
	// Sisi Kanan
	glColor3f(0.7,0.7,0.7); // warna
	glBegin(GL_POLYGON);
	glVertex3f(x,y,z);
	glVertex3f(x,y,z+25);
	glVertex3f(x,y+25,z+25);
	glVertex3f(x,y+25,z);
	glEnd();

	// Sisi Kiri
	glColor3f(0.7,0.7,0.7); // Warna
	glBegin(GL_POLYGON);
	glVertex3f(x-25,y,z);
	glVertex3f(x-25,y+25,z);
	glVertex3f(x-25,y+25,z+25);
	glVertex3f(x-25,y,z+25);
	glEnd();

	// Sisi Depan
	glColor3f(0.75,0.75,0.75); // Warna
	glBegin(GL_POLYGON);
	glVertex3f(x,y,z+25);
	glVertex3f(x-25,y,z+25);
	glVertex3f(x-25,y+25,z+25);
	glVertex3f(x,y+25,z+25);
	glEnd();

	// Sisi Belakang
	glColor3f(0.75,0.75,0.75); // Warna
	glBegin(GL_POLYGON);
	glVertex3f(x-25,y,z);
	glVertex3f(x-25,y+25,z);
	glVertex3f(x,y+25,z);
	glVertex3f(x,y,z);
	glEnd();

	// Sisi Atas
	glColor3f(0.8,0.8,0.8); // Warna
	glBegin(GL_POLYGON);
	glVertex3f(x-25,y+25,z);
	glVertex3f(x,y+25,z);
	glVertex3f(x,y+25,z+25);
	glVertex3f(x-25,y+25,z+25);
	glEnd();
}


void house1() // Nilai Maksimal Letak Kubus = Kiri(-175) Kanan(150), Atas Bawah, Maju(175) Mundur(-200)
{
	// Baris 1 (Paling kiri dari belakang ke depan)
	house(-175,0,-200); // Paling belakang
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
    house(-175,0,175); // Paling Depan
    
    // Baris 2
    house(-150,0,-25);
	house(-150,0,100);
	house(-150,0,150);
	house(-150,0,175);
	
	// Baris 3
	house(-125,0,-200);
	house(-125,0,-175);
	house(-125,0,-125);
	house(-125,0,-100);
	house(-125,0,-75);
	house(-125,0,-50);
	house(-125,0,25);
	house(-125,0,75);
    house(-125,0,175);
    
    // Baris 4
    house(-100,0,-200);
    house(-100,0,-50);
    house(-100,0,0);
    house(-100,0,75);
    house(-100,0,100);
    house(-100,0,150);
    house(-100,0,175);
    
    // Baris 5
    house(-75,0,-200);
    house(-75,0,-175);
    house(-75,0,-125);
    house(-75,0,-100);
    house(-75,0,-50);
    house(-75,0,25);
    house(-75,0,125);
    house(-75,0,175);
    
	// Baris 6
	house(-50,0,-200);
	house(-50,0,-175);
	house(-50,0,-125);
	house(-50,0,-25);
	house(-50,0,25);
	house(-50,0,75);
	house(-50,0,175);
    
	// Baris 7
	house(-25,0,-200);
	house(-25,0,-150);
	house(-25,0,-75);
	house(-25,0,-50);
	house(-25,0,25);
	house(-25,0,50);
	house(-25,0,100);
	house(-25,0,125);
	house(-25,0,175);
    
	// Baris 8
	house(0,0,-200);
	house(0,0,-100);
	house(0,0,-50);
	house(0,0,0);
	house(0,0,100);
	house(0,0,175);
    
	// Baris 9
	house(25,0,-200);
	house(25,0,-175);
	house(25,0,-125);
	house(25,0,-50);
	house(25,0,0);
	house(25,0,50);
	house(25,0,150);
	house(25,0,175);
    
	// Baris 10
	house(50,0,-200);
	house(50,0,-175);
	house(50,0,-100);
	house(50,0,-50);
	house(50,0,0);
	house(50,0,50);
	house(50,0,100);
	house(50,0,125);
	house(50,0,175);
    
	// Baris 11
	house(75,0,-200);
	house(75,0,-125);
	house(75,0,-75);
	house(75,0,0);
	house(75,0,75);
	house(75,0,175);
    
	// Baris 12
	house(100,0,-200);
	house(100,0,-175);
	house(100,0,-25);
	house(100,0,0);
	house(100,0,50);
	house(100,0,125);
	house(100,0,175);
    
	// Baris 13
	house(125,0,-200);
	house(125,0,-125);
	house(125,0,-100);
	house(125,0,-50);
	house(125,0,100);
	house(125,0,175);
    
	// baris 14
	house(150,0,-200);
	house(150,0,-150);
	house(150,0,-100);
	house(150,0,-50);
	house(150,0,-25);
	house(150,0,25);
	house(150,0,75);
	house(150,0,150);
	house(150,0,175);
	
	// Baris 15
	house(175,0,-200);
	house(175,0,-150);
	house(175,0,-25);
	house(175,0,50);
	house(175,0,100);
    
    // Baris 16
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
    house(200,0,175);
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
    		glRotatef(-2,1.0,0.0,0.0); // Jempalikan (Perlu diatur nilainya)

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
