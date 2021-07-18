/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <math.h>
#include<stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cmath>
static float firstWindow;
void myinit2(void);
void mydisplay2();
void keyFunc(unsigned char,int,int);
void drawSeat(float,float);
float j2=0.0, k1=0.0, l1=0.0, yMove1=0;
GLfloat a1=0,b1=0,c1=0,d1=0,e1=0;
static int flag5=0, flag6=0, flag7=0,flag8=0,flag9=0,flag10=0;
void *currentfont1;
void mydisplay(void);
void *currentfont;
int flag=0;
void Timer(int value) {
	glutTimerFunc(1000 / 60, Timer, value);
	glutPostRedisplay();
}
void setFont(void *font)
{
    currentfont=font;
}
typedef struct {
	double x;
	double y;
} Point;

Point p1 = {320.0, 480.0};

double time1 = 0.0;


void calc() {
	time1 += 0.2;


	p1.y = (-0.5*9.8)*(time1*time1)+0+150;

	if(p1.y < 0.0) {
		p1.y = 480;
		time1 = 0;
	}
}
void myKeyboardFunc( unsigned char key, int x, int y )
{
    switch(key)
    {
        case 13://Ascii of 'n' key is 110
        flag=1;
        break;
    }
    mydisplay();
}
void drawstring(float x,float y,float z,char *string)
{
    char *c;
    int len = (int) strlen(string);
    int i;
    glRasterPos3f(x,y,z);
    for(i = 0;i<len;i++)
    {
        glColor3f(0.0,0.0,0.0);
        glutBitmapCharacter(currentfont,string[i]);
    }
}
GLfloat a=0,b=0,c=0,d=0,e=0;
void building();
void blast();
void road();
void display2();
void display3();

void update(int value)
{
    a+=20.0; //Plane position takeoff on x axis
    b-=10.0; //Road Strip backward movement
    c+=15; //take off at certain angle on y axis
if(b<=-78.0)// moving of run way
    b=0.0;
glutPostRedisplay();
glutTimerFunc(150,update,0);//delay
}

void display(void)
{
glClear(GL_COLOR_BUFFER_BIT);
road();
glPushMatrix();
glTranslated(a,c,0.0);
glColor3f(1.0,1.0,1.0);

glBegin(GL_POLYGON);//rectangular body
    glVertex2f(0.0,30.0);
    glVertex2f(0.0,55.0);
    glVertex2f(135.0,55.0);
    glVertex2f(135.0,30.0);
glEnd();

glPopMatrix();
glPushMatrix();
glTranslated(a,c,0.0);
glColor3f(1.0,1.0,1.0);

glBegin(GL_POLYGON);//upper triangle construction plane
    glVertex2f(135.0,55.0);
    glVertex2f(150.0,50.0);
    glVertex2f(155.0,45.0);
    glVertex2f(160.0,40.0);
    glVertex2f(135.0,40.0);
glEnd();

glPopMatrix();
glPushMatrix();
glTranslated(a,c,0.0);
glColor3f(0.0,0.0,0.0);

glBegin(GL_LINE_LOOP);//outline of upper triangle plane
    glVertex2f(135.0,55.0);
    glVertex2f(150.0,50.0);
    glVertex2f(155.0,45.0);
    glVertex2f(160.0,40.0);
    glVertex2f(135.0,40.0);
glEnd();

glPopMatrix();
glPushMatrix();
glTranslated(a,c,0.0);
glColor3f(1.0,0.0,0.0);

glBegin(GL_POLYGON);//lower triangle
    glVertex2f(135.0,40.0);
    glVertex2f(160.0,40.0);
    glVertex2f(160.0,37.0);
    glVertex2f(145.0,30.0);
    glVertex2f(135.0,30.0);
glEnd();

glPopMatrix();
glPushMatrix();
glTranslated(a,c,0.0);
glColor3f(1.0,0.0,0.0);

glBegin(GL_POLYGON);//back wing
    glVertex2f(0.0,55.0);
    glVertex2f(0.0,80.0);
    glVertex2f(10.0,80.0);
    glVertex2f(40.0,55.0);
glEnd();

glPopMatrix();
glPushMatrix();
glTranslated(a,c,0.0);
glColor3f(1.0,0.0,0.0);

glBegin(GL_POLYGON);//left side wing
    glVertex2f(65.0,55.0);
    glVertex2f(50.0,70.0);
    glVertex2f(75.0,70.0);
    glVertex2f(90.0,55.0);
glEnd();

glPopMatrix();
glPushMatrix();
glTranslated(a,c,0.0);
glColor3f(1.0,0.0,0.0);

glBegin(GL_POLYGON);//rightside wing
    glVertex2f(70.0,40.0);
    glVertex2f(100.0,40.0);
    glVertex2f(80.0,15.0);
    glVertex2f(50.0,15.0);
glEnd();

glPopMatrix();
if(c>360) //timer to jump to next display
{
display2();
d+=20;//plane takeoff on x in 2nd display
}
if(a>500.0)//window position during take off
{
a=0.0;
b=0.0;
}
if(c>750)//timer to jump to 3rd display
{
display3();
e+=20;//plane takeoff on x in 3rd display
if(e>250)//timer to call blast function
{
blast();
e=250;
calc();

	glBegin(GL_POINTS);

float radius = 10.0;

	glColor3f(1.0,0.90,0.85);

	glBegin(GL_POLYGON);
		for(float i=0;i<360;i+=0.1)
			glVertex2f(cos(i)*radius+p1.x,sin(i)*radius+p1.y+110);
	glEnd();

	radius=3.0;
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
		for(float i=0;i<360;i++)
			glVertex2f(cos(i)*radius+p1.x+5,sin(i)*radius+p1.y+115);
	glEnd();

	radius=1.5;
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		for(float i=0;i<360;i++)
			glVertex2f(cos(i)*radius+p1.x+5,sin(i)*radius+p1.y+115);
	glEnd();
		//Draws the Hair
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glBegin(GL_POLYGON);
		glVertex2f(p1.x-10,p1.y+110);

		glVertex2f(p1.x-10,p1.y+125);

		glVertex2f(p1.x+12,p1.y+125);
		glVertex2f(p1.x+10,p1.y+125);
	glEnd();


	//Draws the Neck
	glColor3f(1.0,0.90,0.85);
	glBegin(GL_POLYGON);
		glVertex2f(p1.x-2.0,p1.y+95.0);
		glVertex2f(p1.x-2.0,p1.y+110.0);
		glVertex2f(p1.x+2.0,p1.y+110.0);
		glVertex2f(p1.x+2.0,p1.y+95.0);
	glEnd();





	//Draws the Red Shirt
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(p1.x-5,p1.y+65);
		glVertex2f(p1.x-5,p1.y+85);
		glVertex2f(p1.x-2,p1.y+95);
		glVertex2f(p1.x+2,p1.y+95);
		glVertex2f(p1.x+5,p1.y+85);
		glVertex2f(p1.x+5,p1.y+65);
	glEnd();


	//Draws the Left Leg
	glColor3f(1.0,0.90,0.85);
	glBegin(GL_POLYGON);
		glVertex2f(p1.x-4,p1.y+55);
		glVertex2f(p1.x-4,p1.y+27);
		glVertex2f(p1.x-2,p1.y+27);
		glVertex2f(p1.x-2,p1.y+55);
	glEnd();

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(p1.x-5,p1.y+25);
		glVertex2f(p1.x-5,p1.y+27);
		glVertex2f(p1.x,p1.y+27);
		glVertex2f(p1.x,p1.y+25);
	glEnd();


	//Draws the Right Leg
	glColor3f(1.0,0.90,0.85);
	glBegin(GL_POLYGON);
		glVertex2f(p1.x+1,p1.y+55);
		glVertex2f(p1.x+1,p1.y+27);
		glVertex2f(p1.x+4,p1.y+27);
		glVertex2f(p1.x+4,p1.y+55);
	glEnd();

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(p1.x+1,p1.y+25);
		glVertex2f(p1.x+1,p1.y+27);
		glVertex2f(p1.x+7,p1.y+27);
		glVertex2f(p1.x+7,p1.y+25);
	glEnd();

	//Draws the Shoes
	//Draws the Trousers
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(p1.x-5,p1.y+55);
		glVertex2f(p1.x-5,p1.y+65);
		glVertex2f(p1.x+5,p1.y+65);
		glVertex2f(p1.x+5,p1.y+55);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(p1.x-5,p1.y+30);
		glVertex2f(p1.x-5,p1.y+55);
		glVertex2f(p1.x-1,p1.y+55);
		glVertex2f(p1.x-1,p1.y+30);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(p1.x+1,p1.y+30);
		glVertex2f(p1.x+1,p1.y+55);
		glVertex2f(p1.x+5,p1.y+55);
		glVertex2f(p1.x+5,p1.y+30);
	glEnd();
	//MOUTH
glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINE_STRIP);
		glVertex2f(p1.x+8,p1.y+106);
		glVertex2f(p1.x+3,p1.y+106);
		glVertex2f(p1.x+3,p1.y+107);
	glEnd();

	//Draws the Right Hand
	glColor3f(1.0,0.90,0.85);
	glBegin(GL_POLYGON);
		glVertex2f(p1.x,p1.y+80);
		glVertex2f(p1.x+3,p1.y+80);
		glVertex2f(p1.x+3,p1.y+60);
		glVertex2f(p1.x,p1.y+60);
	glEnd();



	//Draws the Mouth



	//Draws the Nose


	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(p1.x+1,p1.y+95);
		glVertex2f(p1.x+1,p1.y+150);
		glVertex2f(p1.x+2,p1.y+150);
		glVertex2f(p1.x+2,p1.y+95);
	glEnd();

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(p1.x+3,p1.y+122);
		glVertex2f(p1.x+3,p1.y+150);
		glVertex2f(p1.x+4,p1.y+150);
		glVertex2f(p1.x+4,p1.y+122);
	glEnd();
	//parachute
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(p1.x+15,p1.y+150);
		glVertex2f(p1.x+6,p1.y+150);
		glVertex2f(p1.x-10,p1.y+180);
		glVertex2f(p1.x+20,p1.y+180);

	glEnd();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(p1.x-30,p1.y+150);
		glVertex2f(p1.x-10,p1.y+180);
		glVertex2f(p1.x+6,p1.y+150);


	glEnd();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(p1.x+15,p1.y+150);
		glVertex2f(p1.x+20,p1.y+180);
		glVertex2f(p1.x+40,p1.y+150);

	glEnd();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(p1.x-30,p1.y+150);
		glVertex2f(p1.x-10,p1.y+180);
		glVertex2f(p1.x-25,p1.y+165);


	glEnd();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(p1.x+40,p1.y+150);
		glVertex2f(p1.x+20,p1.y+180);
		glVertex2f(p1.x+35,p1.y+165);


	glEnd();





}
}
glFlush();
}

void building()
{
glColor3f(0.60,0.40,0.70);

glBegin(GL_POLYGON);
glVertex2f(350.0,80.0);
glVertex2f(350.0,480.0);
glVertex2f(400.0,400.0);
glVertex2f(400.0,0.0);
glEnd();
glColor3f(0.75,0.75,0.75);

glBegin(GL_POLYGON);
glVertex2f(400.0,0.0);
glVertex2f(400.0,400.0);
glVertex2f(450.0,400.0);
glVertex2f(450.0,0.0);
glEnd();
glColor3f(1.0,1.0,1.0);

glBegin(GL_POLYGON);
glVertex2f(400.0,400.0);
glVertex2f(350.0,480.0);
glVertex2f(400.0,480.0);
glVertex2f(450.0,400.0);
glEnd();
glColor3f(0.60,0.40,0.70);

glBegin(GL_POLYGON);//upper triangle of building
glVertex2f(400.0,400.0);
glVertex2f(350.0,480.0);
glVertex2f(400.0,480.0);
glEnd();
glColor3f(0.0,0.0,0.0);

}


void blast(void)//blast polygon construction
{
glPushMatrix();
glTranslated(-10.0,-60.0,0.0);
glColor3f(1.0,1.0,0.0);

glBegin(GL_POLYGON);
glVertex2f(404.4,320.0);
glVertex2f(384.0,285.0);
glVertex2f(368.0,344.5);
glVertex2f(344.0,355.0);
glVertex2f(347.2,414.5);
glVertex2f(332.8,442.5);
glVertex2f(347.2,477.5);
glVertex2f(352.0,530.0);
glVertex2f(379.2,519.5);
glVertex2f(396.8,565.0);
glVertex2f(416.0,530.0);
glVertex2f(440.0,547.5);
glVertex2f(452.8,512.5);
glVertex2f(472.0,512.5);
glVertex2f(475.2,470.5);
glVertex2f(488.0,442.5);
glVertex2f(488.0,404.0);
glVertex2f(470.0,372.5);
glVertex2f(475.2,337.5);
glVertex2f(464.0,306.0);
glVertex2f(444.8,320.0);
glVertex2f(425.6,285.0);
glVertex2f(404.8,320.0);
glEnd();
glPopMatrix();
}

void road()
{
glColor3f(0.0,0.0,0.0);

glBegin(GL_POLYGON);//black road
glVertex2f(0.0,0.0);
glVertex2f(0.0,100.0);
glVertex2f(500.0,100.0);
glVertex2f(500.0,0.0);
glEnd();
glPopMatrix();
glPushMatrix();
glTranslated(b,0.0,0.0);
glColor3f(1.0,1.0,1.0);

glBegin(GL_POLYGON);//white strips on roadglVertex2f(0.0,40.0);
glVertex2f(8.0,60.0);
glVertex2f(58.0,60.0);
glVertex2f(50.0,40.0);
glEnd();
glPopMatrix();
glPushMatrix();
glTranslated(b,0.0,0.0);
glColor3f(1.0,1.0,1.0);

glBegin(GL_POLYGON);
glVertex2f(100.0,40.0);
glVertex2f(108.0,60.0);
glVertex2f(158.0,60.0);
glVertex2f(150.0,40.0);
glEnd();
glPopMatrix();
glPushMatrix();
glTranslated(b,0.0,0.0);
glColor3f(1.0,1.0,1.0);

glBegin(GL_POLYGON);
glVertex2f(200.0,40.0);
glVertex2f(208.0,60.0);
glVertex2f(258.0,60.0);
glVertex2f(250.0,40.0);
glEnd();
glPopMatrix();
glPushMatrix();
glTranslated(b,0.0,0.0);
glColor3f(1.0,1.0,1.0);

glBegin(GL_POLYGON);
glVertex2f(300.0,40.0);
glVertex2f(308.0,60.0);
glVertex2f(358.0,60.0);
glVertex2f(350.0,40.0);
glEnd();
glPopMatrix();
glPushMatrix();
glTranslated(b,0.0,0.0);
glColor3f(1.0,1.0,1.0);

glBegin(GL_POLYGON);
glVertex2f(400.0,40.0);
glVertex2f(408.0,60.0);
glVertex2f(458.0,60.0);
glVertex2f(450.0,40.0);
glEnd();
glPopMatrix();
}

void display2()
{
glClear(GL_COLOR_BUFFER_BIT);
glPushMatrix();
glTranslated(d,300.0,0.0);
glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(0.0,30.0);
glVertex2f(0.0,55.0);
glVertex2f(135.0,55.0);
glVertex2f(135.0,30.0);
glEnd();
glPopMatrix();
glPushMatrix();
glTranslated(d,300.0,0.0);
glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(135.0,55.0);
glVertex2f(150.0,50.0);
glVertex2f(155.0,45.0);
glVertex2f(160.0,40.0);
glVertex2f(135.0,40.0);
glEnd();glPopMatrix();
glPushMatrix();
glTranslated(d,300.0,0.0);
glColor3f(0.0,0.0,0.0);
glBegin(GL_LINE_LOOP);
glVertex2f(135.0,55.0);
glVertex2f(150.0,50.0);
glVertex2f(155.0,45.0);
glVertex2f(160.0,40.0);
glVertex2f(135.0,40.0);
glEnd();
glPopMatrix();
glPushMatrix();
glTranslated(d,300.0,0.0);
glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(135.0,40.0);
glVertex2f(160.0,40.0);
glVertex2f(160.0,37.0);
glVertex2f(145.0,30.0);
glVertex2f(135.0,30.0);
glEnd();
glPopMatrix();
glPushMatrix();
glTranslated(d,300.0,0.0);
glColor3f(1.0,0.0,0.0);

glBegin(GL_POLYGON);
glVertex2f(0.0,55.0);
glVertex2f(0.0,80.0);
glVertex2f(10.0,80.0);
glVertex2f(40.0,55.0);
glVertex2f(165.0,40.0);
glEnd();
glPopMatrix();
glPushMatrix();
glTranslated(d,300.0,0.0);
glColor3f(1.0,0.0,0.0);

glBegin(GL_POLYGON);
glVertex2f(65.0,55.0);
glVertex2f(50.0,70.0);
glVertex2f(75.0,70.0);
glVertex2f(90.0,55.0);
glEnd();
glPopMatrix();
glPushMatrix();
glTranslated(d,300.0,0.0);
glColor3f(1.0,0.0,0.0);

glBegin(GL_POLYGON);
glVertex2f(70.0,40.0);
glVertex2f(100.0,40.0);
glVertex2f(80.0,15.0);
glVertex2f(50.0,15.0);
glEnd();
glPopMatrix();
}

void display3()
{

glClear(GL_COLOR_BUFFER_BIT);
building();
glPushMatrix();
glTranslated(e,300.0,0.0);
glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(0.0,30.0);
glVertex2f(0.0,55.0);
glVertex2f(135.0,55.0);
glVertex2f(135.0,30.0);
glEnd();glPopMatrix();
glPushMatrix();
glTranslated(e,300.0,0.0);
glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(135.0,55.0);
glVertex2f(150.0,50.0);
glVertex2f(155.0,45.0);
glVertex2f(160.0,40.0);
glVertex2f(135.0,40.0);
glEnd();
glPopMatrix();
glPushMatrix();
glTranslated(e,300.0,0.0);
glColor3f(0.0,0.0,0.0);
glBegin(GL_LINE_LOOP);
glVertex2f(135.0,55.0);
glVertex2f(150.0,50.0);
glVertex2f(155.0,45.0);
glVertex2f(160.0,40.0);
glVertex2f(135.0,40.0);
glEnd();
glPopMatrix();glPushMatrix();
glTranslated(e,300.0,0.0);
glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(135.0,40.0);
glVertex2f(160.0,40.0);
glVertex2f(160.0,37.0);
glVertex2f(145.0,30.0);
glVertex2f(135.0,30.0);
glEnd();
glPopMatrix();
glPushMatrix();
glTranslated(e,300.0,0.0);
glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(0.0,55.0);
glVertex2f(0.0,80.0);
glVertex2f(10.0,80.0);
glVertex2f(40.0,55.0);
//glVertex2f(165.0,40.0);
glEnd();
glPopMatrix();
glPushMatrix();
glTranslated(e,300.0,0.0);
glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(65.0,55.0);
glVertex2f(50.0,70.0);
glVertex2f(75.0,70.0);
glVertex2f(90.0,55.0);
//glVertex2f(165.0,40.0);
glEnd();
glPopMatrix();
glPushMatrix();
glTranslated(e,300.0,0.0);
glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);
    glVertex2f(70.0,40.0);
    glVertex2f(100.0,40.0);
    glVertex2f(80.0,15.0);
    glVertex2f(50.0,15.0);
glEnd();
glPopMatrix();

}

void myinitt()
{glClearColor(0.0f,0.0f,1.0f,0.0f);
glColor3f(1.0,0.0,0.0);
glPointSize(1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,499.0,0.0,499.0);
}
void myinit()
{
    glClearColor(0,0,0,0);
    glOrtho(-100.0,100.0,-100.0,100.0,-50.0,50.0);
}

void frontscreen(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(0.2,0.8,1);
    drawstring(40-50,60,0.0,"AIRPLANE CRASH");
    glColor3f(1,0.5,0);
    drawstring(10-50,34,0.0,"Sourabha                           (4NM18CS186)");
    glColor3f(1,0.5,0);
    drawstring(10-50,40,0.0,"Shetty  Shreya Prakash     (4NM18CS168)");
    glColor3f(0.7,0.8,1);
    drawstring(32-50,10,0.0," PRESS ENTER TO GO TO NEXT PAGE");
    glutSwapBuffers();
    glFlush();
}



void setFont1(void *font)
{
    currentfont1=font;
}


void passenger(float x,float y, int color)
{
    //Head
    float radius = 2.5;
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		for(float i=0;i<360;i++)
			glVertex2f(cos(i)*radius+x,sin(i)*radius+y);
	glEnd();

	//Neck
	glColor3f(1.0,0.90,0.85);
	glBegin(GL_POLYGON);
		glVertex2f(x-0.8,y-2.5);
		glVertex2f(x-0.8,y-4.0);
		glVertex2f(x+0.8,y-4.0);
		glVertex2f(x+0.8,y-2.5);
	glEnd();

	//Hands
	glColor3f(1.0,0.90,0.85);
	glBegin(GL_POLYGON);
		glVertex2f(x-2.3,y-4);
		glVertex2f(x-2.3,y-9);
		glVertex2f(x+2.3,y-9);
		glVertex2f(x+2.3,y-4);
	glEnd();

	//Shirt
	if(color==1)
		glColor3f(1.0,0.5,0.0);
	else if(color==2)
		glColor3f(0.419608,0.556863,0.137255);
	else if(color==3)
		glColor3f(2.0,0.5,1.0);

	glBegin(GL_POLYGON);
		glVertex2f(x-1.5,y-4);
		glVertex2f(x-1.5,y-9);
		glVertex2f(x+1.5,y-9);
		glVertex2f(x+1.5,y-4);
	glEnd();

	//Trousers
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(x-1.5,y-9);
		glVertex2f(x-1.5,y-11);
		glVertex2f(x+1.5,y-11);
		glVertex2f(x+1.5,y-9);
	glEnd();

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(x-1.5,y-11);
		glVertex2f(x-1.5,y-17);
		glVertex2f(x-0.2,y-17);
		glVertex2f(x-0.2,y-11);
	glEnd();

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(x+1.5,y-11);
		glVertex2f(x+1.5,y-17);
		glVertex2f(x+0.2,y-17);
		glVertex2f(x+0.2,y-11);
	glEnd();

	glColor3f(0.0,0.0,0.0);//bag
	glBegin(GL_POLYGON);
		glVertex2f(x+1.5,y-12);
		glVertex2f(x+1.5,y-18);
		glVertex2f(x+4,y-18);
		glVertex2f(x+4,y-12);
     glEnd();
     glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(x+2,y-9);
		glVertex2f(x+2,y-13);
		glVertex2f(x+2.2,y-13);
		glVertex2f(x+2.2,y-9);
     glEnd();
      glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(x+2.7,y-9);
		glVertex2f(x+2.7,y-13);
		glVertex2f(x+2.9,y-13);
		glVertex2f(x+2.9,y-9);
     glEnd();
     glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(x+2.7,y-9.5);
		glVertex2f(x+2.7,y-9);
		glVertex2f(x+2.2,y-9);
		glVertex2f(x+2.2,y-9.5);
     glEnd();
}
void myinit2(void)
{
	glClearColor(0.9,0.9,0.9,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,1300,0,700);
	//gluOrtho2D(0,500,0,500);
	glMatrixMode(GL_MODELVIEW);
	glPointSize(5.0);
}


void keyFunc(unsigned char key,int x,int y)
{
    if(key=='x'||key=='X')
		exit(0);
	if(key=='5')
        flag9=1;
}


void mydisplay2()
{
	glClear(GL_COLOR_BUFFER_BIT);

	//Floor
	glColor3f(0.75,0.75,0.75);
	glBegin(GL_POLYGON);
        glVertex2f(0,0);
        glVertex2f(1300,0);
        glVertex2f(1300,144);
        glVertex2f(0,144);
	glEnd();

	//Ceiling
	glColor3f(0.8,0.8,0.8);
	glBegin(GL_POLYGON);
        glVertex2f(0,500);
        glVertex2f(1300,500);
        glVertex2f(1300,700);
        glVertex2f(0,700);
	glEnd();

	//Window
	glColor3f(0.74902,0.847059,0.847059);
	glBegin(GL_POLYGON);
        glVertex2f(250,340);
        glVertex2f(350,340);
        glVertex2f(350,470);
        glVertex2f(250,470);
	glEnd();

	glBegin(GL_POLYGON);
        glVertex2f(600,340);
        glVertex2f(700,340);
        glVertex2f(700,470);
        glVertex2f(600,470);
	glEnd();

	glBegin(GL_POLYGON);
        glVertex2f(950,340);
        glVertex2f(1050,340);
        glVertex2f(1050,470);
        glVertex2f(950,470);
	glEnd();

    //Seats
    drawSeat(400,200);
 float radius = 25.0;
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		for(float i=0;i<360;i++)
			glVertex2f(cos(i)*radius+410,sin(i)*radius+325);
	glEnd();
	  glBegin(GL_LINES);//person's body
        glVertex2f(410.0,300.0);//line for body
        glVertex2f(410.0,250.0);

    glEnd();

    drawSeat(750,200);
    //float radius = 25.0;
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		for(float i=0;i<360;i++)
			glVertex2f(cos(i)*radius+760,sin(i)*radius+325);
	glEnd();
	glBegin(GL_LINES);//person's body
        glVertex2f(760.0,300.0);//line for body
        glVertex2f(760.0,250.0);

    glEnd();
    drawSeat(1100,200);
glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		for(float i=0;i<360;i++)
			glVertex2f(cos(i)*radius+1110,sin(i)*radius+325);
	glEnd();
	glBegin(GL_LINES);//person's body
        glVertex2f(1110.0,300.0);//line for body
        glVertex2f(1110.0,250.0);

    glEnd();
    glutPostRedisplay();
	glFlush();


	if(flag9==1)
    {
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(1500,1500);
glutInitWindowPosition(0,0);
glutCreateWindow("Airplane Takeoff");
glutDisplayFunc(display);
myinitt();
glutTimerFunc(100,update,0);
glutMainLoop();

    }
}


void drawSeat(float x,float y)
{
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_POLYGON);
        glVertex2f(x-60,y+10);
		glVertex2f(x+60,y+10);
		glVertex2f(x+75,y-60);
		glVertex2f(x-75,y-60);
    glEnd();

    glColor3f(0.137255,0.419608,0.556863);
    glBegin(GL_POLYGON);
        glVertex2f(x-80,y+10);
		glVertex2f(x+80,y+10);
		glVertex2f(x+80,y+50);
		glVertex2f(x-55,y+50);
		glVertex2f(x-80,y+30);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(x+30,y+50);
		glVertex2f(x+80,y+50);
		glVertex2f(x+90,y+220);
		glVertex2f(x+55,y+220);
		glVertex2f(x+40,y+200);
    glEnd();

    glColor3f(0.5,0.5,0.5);
    glBegin(GL_POLYGON);
        glVertex2f(x-50,y+100);
		glVertex2f(x+34,y+100);
		glVertex2f(x+32,y+75);
		glVertex2f(x-50,y+75);
    glEnd();
}
void display10(void);
void myKeyboardFunc10( unsigned char key, int x, int y )
{
     switch(key)
    {
        case 110://Ascii of 'n' key is 110
        flag10=1;
        break;
    }
    display10();

}
void display10(void)
{
glClear(GL_COLOR_BUFFER_BIT);
//runway();
glPushMatrix();
glTranslated(a,c,0.0);
glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);//rectangular body
glVertex2f(0.0,30.0);
glVertex2f(0.0,55.0);
glVertex2f(135.0,55.0);
glVertex2f(135.0,30.0);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslated(a,c,0.0);
glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);//upper triangle construction plane
glVertex2f(135.0,55.0);
glVertex2f(150.0,50.0);
glVertex2f(155.0,45.0);
glVertex2f(160.0,40.0);
glVertex2f(135.0,40.0);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslated(a,c,0.0);
glColor3f(0.0,0.0,0.0);
glBegin(GL_LINE_LOOP);//outline of upper triangle plane
glVertex2f(135.0,55.0);
glVertex2f(150.0,50.0);
glVertex2f(155.0,45.0);
glVertex2f(160.0,40.0);
glVertex2f(135.0,40.0);
glEnd();
glPopMatrix();


glPushMatrix();
glTranslated(a,c,0.0);
glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);//lower triangle
glVertex2f(135.0,40.0);
glVertex2f(160.0,40.0);
glVertex2f(160.0,37.0);
glVertex2f(145.0,30.0);
glVertex2f(135.0,30.0);
glEnd();
glPopMatrix();


glPushMatrix();
glTranslated(a,c,0.0);
glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);//back wing
glVertex2f(0.0,55.0);
glVertex2f(0.0,80.0);
glVertex2f(10.0,80.0);
glVertex2f(40.0,55.0);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslated(a,c,0.0);
glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);//left side wing
glVertex2f(65.0,55.0);
glVertex2f(50.0,70.0);
glVertex2f(75.0,70.0);
glVertex2f(90.0,55.0);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslated(a,c,0.0);
glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);//rightside wing
glVertex2f(70.0,40.0);
glVertex2f(100.0,40.0);
glVertex2f(80.0,15.0);
glVertex2f(50.0,15.0);


glEnd();
 glPushMatrix(); //for door
    //glTranslated(a,c,0.0);
    glColor3f(0.5,0.5,0.5);
    glBegin(GL_POLYGON);
        glVertex2f(300.0,200.0);
        glVertex2f(300.0,270.0);
        glVertex2f(360.0,270.0);
        glVertex2f(360.0,200.0);
    glEnd();
    glPopMatrix();

     glPushMatrix(); //for ladder right edge
    //glTranslated(a,c,0.0);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
        glVertex2f(380.0,30.0);
        glVertex2f(360.0,200.0);
        glVertex2f(390.0,90.0);
    glEnd();
    glPopMatrix();
    glColor3f(0.5,0.5,0.5);//ladder floor
    glBegin(GL_POLYGON);
        glVertex2f(320.0,30.0);
        glVertex2f(330.0,90.0);
        glVertex2f(300.0,200.0);
        glVertex2f(360.0,200.0);
        glVertex2f(380.0,30.0);
    glEnd();
    glPopMatrix();

glPopMatrix();
if(a>500.0)//window position during take off
{
	a=0.0;
	b=0.0;
}
if(flag10==1)
{
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1520,1000);
	glutInitWindowPosition(0,0);
	firstWindow=glutCreateWindow("PLANE CRASH");
	glutDisplayFunc(mydisplay2);
	glutKeyboardFunc(keyFunc);
	myinit2();

	glutMainLoop();
}
glFlush();
glutSwapBuffers();
}


myinitt10()
{

glClearColor(0.0f,0.0f,1.0f,0.0f);
glColor3f(1.0,0.0,0.0);
glPointSize(1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,499.0,0.0,499.0);

}

void display1(void)
{ int x=100;
int y=20;

glClear(GL_COLOR_BUFFER_BIT);
//runway();

    glColor3f(0.0,0.0,0.0); //Runway
	glBegin(GL_POLYGON);
		glVertex2f(0,0);
		glVertex2f(499,0);
		glVertex2f(499,30);
		glVertex2f(0,30);
	glEnd();

glPushMatrix();
glTranslated(a1,c1,0.0);
glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);//rectangular body
glVertex2f(0.0,30.0+10);
glVertex2f(0.0,55.0+10);
glVertex2f(135.0,55.0+10);
glVertex2f(135.0,30.0+10);
glEnd();
glPopMatrix();

    glColor3f(0.0,0.0,0.0);//Door
	glBegin(GL_POLYGON);
		glVertex2f(113,45+10);
		glVertex2f(120,45+10);
		glVertex2f(120,30+10);
		glVertex2f(113,30+10);
	glEnd();

	glColor3f(0.7,0.7,0.7);//AirStair
	glBegin(GL_POLYGON);
		glVertex2f(113,30+10);
		glVertex2f(110,0+10);
		glVertex2f(123,0+10);
		glVertex2f(120,30+10);
	glEnd();

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
		glVertex2f(111,5+10);
		glVertex2f(122,5+10);
		glVertex2f(111.5,10+10);
		glVertex2f(121.5,10+10);
		glVertex2f(112,15+10);
		glVertex2f(121,15+10);
		glVertex2f(112.5,20+10);
		glVertex2f(120.5,20+10);
		glVertex2f(113,25+10);
		glVertex2f(120,25+10);
	glEnd();

glPushMatrix();
glTranslated(a1,c1,0.0);
glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);//upper triangle construction plane
glVertex2f(135.0,55.0+10);
glVertex2f(150.0,50.0+10);
glVertex2f(155.0,45.0+10);
glVertex2f(160.0,40.0+10);
glVertex2f(135.0,40.0+10);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslated(a1,c1,0.0);
glColor3f(0.0,0.0,0.0);
glBegin(GL_LINE_LOOP);//outline of upper triangle plane
glVertex2f(135.0,55.0+10);
glVertex2f(150.0,50.0+10);
glVertex2f(155.0,45.0+10);
glVertex2f(160.0,40.0+10);
glVertex2f(135.0,40.0+10);
glEnd();
glPopMatrix();


glPushMatrix();
glTranslated(a1,c1,0.0);
glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);//lower triangle
glVertex2f(135.0,40.0+10);
glVertex2f(160.0,40.0+10);
glVertex2f(160.0,37.0+10);
glVertex2f(145.0,30.0+10);
glVertex2f(135.0,30.0+10);
glEnd();
glPopMatrix();


glPushMatrix();
glTranslated(a1,c1,0.0);
glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);//back wing
glVertex2f(0.0,55.0+10);
glVertex2f(0.0,80.0+10);
glVertex2f(10.0,80.0+10);
glVertex2f(40.0,55.0+10);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslated(a1,c1,0.0);
glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);//left side wing
glVertex2f(65.0,55.0+10);
glVertex2f(50.0,70.0+10);
glVertex2f(75.0,70.0+10);
glVertex2f(90.0,55.0+10);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslated(a1,c1,0.0);
glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);//rightside wing
glVertex2f(70.0,40.0+10);
glVertex2f(100.0,40.0+10);
glVertex2f(80.0,15.0+10);
glVertex2f(50.0,15.0+10);
glEnd();


   // passenger(116.5,20);
    if(j2 < 30.0 && flag5 == 1) //Press 1
	{
		passenger(116.5,24+j2,1);
		j2 += 0.02;
	}
	else if(j2 < 30)
	{
		passenger(116.5,24+j2,1);
	}

	if(k1 < 50.0 && flag6 == 1) //Press 2
	{
		passenger(116.5,0+k1,2);
		k1 += 0.02;
	}
	else if(k1 < 50)
	{
		passenger(116.5,0+k1,2);
	}

	if(l1 < 50.0 && flag7 == 1) //Press 3
	{
		passenger(116.5,0+l1,3);
		l1 += 0.02;
	}
	else if(l1 < 50)
	{
		passenger(116.5,0+l1,3);
	}

	if(flag8==1)
    {
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
glutInitWindowSize(1500,1500);
glutInitWindowPosition(50,50);
glutCreateWindow("Airplane");
glutDisplayFunc(display10);
myinitt10();
glClearColor(0.0f,0.0f,1.0f,0.0f);
glColor3f(1.0,0.0,0.0);
glPointSize(1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0,200,0,200);
glutKeyboardFunc(myKeyboardFunc10);

//glutTimerFunc(100,update,0);
glutMainLoop();
    }




/*if(a>500.0)//window position during take off
{
	a=0.0;
	b=0.0;
}*/
glutPostRedisplay();
glFlush();
glutSwapBuffers();
}


myinitt1()
{

glClearColor(0.0f,0.0f,1.0f,0.0f);
glColor3f(1.0,0.0,0.0);
glPointSize(1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,499.0,0.0,499.0);

}


void KeyboardFunc( unsigned char key, int x, int y )
{
    if(key=='x'||key=='X')
		exit(0);
	if(key=='1')
		flag5=1;
    if(key=='2')
		flag6=1;
    if(key=='3')
		flag7=1;
    if(key=='4')
		flag8=1;

}
void mydisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	if(flag==0)
		frontscreen();
	if(flag==1){
            glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
glutInitWindowSize(1500,1500);
glutInitWindowPosition(0,0);
glutCreateWindow("Airplane Takeoff ");
glutDisplayFunc(display1);
myinitt();
glClearColor(0.0f,0.0f,1.0f,0.0f);
glColor3f(1.0,0.0,0.0);
glPointSize(1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0,200,0,200);
glutKeyboardFunc(KeyboardFunc);
//glutTimerFunc(100,update,0);
glutMainLoop();
		//display();

	}

}
int main(int argc, char* argv[])
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(1500,1500);
glutCreateWindow("AEROPLANE");
glutDisplayFunc(mydisplay);

glutKeyboardFunc(myKeyboardFunc);
myinit();
glutMainLoop();
return 0;
}
