// 
//Additional Function : Truck can be moved by left and right arrow buttons
// 
//Deficits : Truck can be moved after stopping the animation


#include <GL/glut.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdarg.h>

#define windowWidth 1000
#define windowHeight 600

#define PI 3.1416

// For Animation
float shift = 0;//It ables to move the truck right or left
GLfloat cloud1Coor = 0.0;
GLfloat cloud1Speed = 3.0;
GLfloat cloud2Coor = 0.0;
GLfloat cloud2Speed = 6.0;
GLfloat cloud3Coor = 0.0;
GLfloat cloud3Speed = 5.0;
GLboolean animationEnabled = GL_TRUE;

//For Resize
int  winWidth, winHeight;//Global variables


//For Filled Circle
void circle(int x, int y, int r) {
	float angle;
	glBegin(GL_POLYGON);
	for (int i = 0; i < 100; i++) {
		angle = 2 * PI * i / 100;
		glVertex2f(x + r * cos(angle), y + r * sin(angle));
	}
	glEnd();
}


//For Clouds
void drawCloud1(int x, int y)
{
	glColor3f(1, 1, 1); 
	circle(cloud1Coor + 0 + x, 0 + y, 30);
	circle(cloud1Coor - 25 + x, y, 20);
	circle(cloud1Coor + 25 + x, -2 + y, 29);
	circle(cloud1Coor + 21 + x, -19 + y, 10);
}

void drawCloud2(int x, int y)
{
	glColor3f(1, 1, 1); 
	circle(cloud2Coor + 0 + x, 0 + y, 30);
	circle(cloud2Coor - 25 + x, y, 15);
	circle(cloud2Coor + 25 + x, -2 + y, 20);
	circle(cloud2Coor + 21 + x, -19 + y, 10);
}

void drawCloud3(int x, int y)
{
	glColor3f(1, 1, 1); 
	circle(cloud3Coor + 0 + x, 0 + y, 20);
	circle(cloud3Coor - 25 + x, y, 20);
	circle(cloud3Coor + 25 + x, -2 + y, 20);
	circle(cloud3Coor + 21 + x, -19 + y, 10);
}

void drawTruck()
{
	//Truck's body
	glColor3ub(255, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(shift - 153, -166);
	glVertex2f(shift - 93, -166);
	glVertex2f(shift - 93, -98);
	glVertex2f(shift - 153, -98);
	glEnd();
	
	//Truck's roof
	glColor3ub(133, 133, 133);
	glBegin(GL_POLYGON);
	glVertex2f(shift - 155, -92);
	glVertex2f(shift - 155, -98);
	glVertex2f(shift - 91, -98);
	glVertex2f(shift - 91, -92);
	glEnd();

	//Amblem on ice-truck
	glColor3ub(139, 69 ,19);
	glBegin(GL_TRIANGLES);
	glVertex2f(shift - 133, -120);
	glVertex2f(shift - 113, -120);
	glVertex2f(shift - 123, -150);
	glColor3ub(255, 255, 255);
	circle(shift - 123, -120, 10);
	glEnd();

	//Truck's Head
	glColor3ub(100, 139, 139);
	glBegin(GL_POLYGON);
	glVertex2f(shift - 93, -158);
	glVertex2f(shift - 63, -158);
	glVertex2f(shift - 63, -128);
	glVertex2f(shift - 93, -128);
	glEnd();

	//Truck's Head
	glColor3ub(100, 139, 139);
	glBegin(GL_POLYGON);
	glVertex2f(shift - 93, -128);
	glVertex2f(shift - 73, -128);
	glVertex2f(shift - 83, -108);
	glVertex2f(shift - 93, -108);
	glEnd();

	//window
	glColor3ub(127, 255, 212);
	glBegin(GL_POLYGON);
	glVertex2f(shift - 93, -128);
	glVertex2f(shift - 78, -128);
	glVertex2f(shift - 83, -113);
	glVertex2f(shift - 93, -113);
	glEnd();

	//Wheels
	glColor3ub(0, 0, 0);
	circle(shift - 140, -168, 10);
	circle(shift - 95, -168, 10);

}


void road()
{
	//Road
	glColor3ub(105, 105, 105);
	glRectf(-150, -200, 147, -140);

	//Road Lines
	glColor3ub(0, 0, 0);
	glRectf(-145, -170, -100, -165);
	glRectf(-90, -170, -45, -165);
	glRectf(-35, -170, 10, -165);
	glRectf(20, -170, 65, -165);
	glRectf(75, -170, 120, -165);
	glRectf(130, -170, 147, -165);

}

void vprint(int x, int y, void* font, const char* string, ...) {

	va_list ap;
	va_start(ap, string);
	char str[1024];
	vsprintf_s(str, string, ap);
	va_end(ap);

	int len, i;
	glRasterPos2f(x, y);
	len = (int)strlen(str);
	for (i = 0; i < len; i++)
		glutBitmapCharacter(font, str[i]);

}

void timer(int value) {
	glutPostRedisplay();
	glutTimerFunc(16, timer, 0);
}


void init() {
	// Smoothing shapes
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void frame()
{
	//Window Frame
	glLineWidth(3);
	glColor3ub(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2f(-160, 210);
	glVertex2f(-160, -210);
	glVertex2f(160, 210);
	glVertex2f(160, -210);
	glVertex2f(-160, 210);
	glVertex2f(160, 210);
	glVertex2f(-160, -210);
	glVertex2f(160, -210);
	glEnd();

	//Window Frame Paint
	glColor3ub(139, 69, 19);
	glRectf(-158, 209, 158, 200);
	glColor3ub(139, 69, 19);
	glRectf(-159, 209, -150, -208);
	glColor3ub(139, 69, 19);
	glRectf(-150, -208, 150, -199);
	glColor3ub(139, 69, 19);
	glRectf(147, -208, 158, 208);

	//Window Handle
	glColor3f(0, 0, 0);
	glBegin(GL_QUADS);
	circle(153, 40, 5);
	glColor3ub(0, 0, 0);
	glRectf(155, 40, 151, 10);
}

void landscape()
{

	//Creates landscape
	glColor3ub(0, 191, 255);
	glRectf(-152, -201, 150, 201);

}


void background()
{
	//Background
	glColor3ub(84, 84, 84);
	glRectf(-500, 300, -152, -300);

	glColor3ub(84, 84, 84);
	glRectf(152, 300, 500, -300);

	glColor3ub(84, 84, 84);
	glRectf(-201, -211, 500, -300);

	glColor3ub(84, 84, 84);
	glRectf(-201, 211, 500, 300);


}


void keyboard(unsigned char key, int x, int y) {
	// Animation On/Off
	if (key == ' ') {
		animationEnabled = !animationEnabled;
	}

}

//Moves truck left and right with arrow buttons
void key(int key, int x, int y) {
	switch (key)
	{
	case GLUT_KEY_LEFT:
		shift -= 5;
		glutPostRedisplay();
		break;
	case GLUT_KEY_RIGHT:
		shift += 5;
		glutPostRedisplay();
		break;
	}
}

//Creates black stripes at background
void wallpaper()
{
	glColor3ub(0, 0, 0);
	glRectf(-490, 300, -500, -300);
	glRectf(-440, 300, -460, -300);
	glRectf(-390, 300, -410, -300);
	glRectf(-340, 300, -360, -300);
	glRectf(-310, 300, -290, -300);
	glRectf(-240, 300, -260, -300);
	glRectf(-190, 300, -210, -300);
	glRectf(-240, 300, -260, -300);
	glRectf(490, 300, 500, -300);
	glRectf(440, 300, 460, -300);
	glRectf(390, 300, 410, -300);
	glRectf(340, 300, 360, -300);
	glRectf(310, 300, 290, -300);
	glRectf(240, 300, 260, -300);
	glRectf(190, 300, 210, -300);
	glRectf(240, 300, 260, -300);

}

//Text's frame
void textWindow()
{

	glColor3ub(148, 0, 211);
	glRectf(-160, 240, 160, 220);
	glColor3ub(0, 0, 0);
	glRectf(-155, 235, -157, 250);
	circle(-156, 250, 2);
	glColor3ub(0, 0, 0);
	glRectf(155, 235, 157, 250);
	circle(156, 250, 2);

}

void display() {


	landscape();
	road();

	drawTruck();
	if (animationEnabled) {// Reset truck's position if you go back or forward 
		if (shift > (windowWidth - 650))
			shift = -(windowWidth - 860);
		if (shift < (windowWidth - 1350))
			shift = (windowWidth - 700);
	}
	drawCloud1(-100, 130);
	if (animationEnabled) {
		cloud1Coor += cloud1Speed;
		if (cloud1Coor > (windowWidth - 650))
			cloud1Coor = -(windowWidth - 860);  // Reset cloud's position 
	}

	drawCloud2(-50, 70);
	if (animationEnabled) {
		cloud2Coor += cloud2Speed;
		if (cloud2Coor > (windowWidth - 650))
			cloud2Coor = -(windowWidth - 860);  // Reset cloud's position 
	}

	drawCloud3(-55, 150);
	if (animationEnabled) {
		cloud3Coor += cloud3Speed;
		if (cloud3Coor > (windowWidth - 650))
			cloud3Coor = -(windowWidth - 860);  // Reset cloud's position 
	}


	background();
	frame();
	textWindow();
	wallpaper();

	//Writing
	glColor3ub(1, 1, 0);
	vprint(-159, 227, GLUT_BITMAP_8_BY_13, "Ice-Truck and Clouds ");


	glutSwapBuffers();
}


void onResize(int w, int h) {
	winWidth = w;
	winHeight = h;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-w / 2, w / 2, -h / 2, h / 2, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	display();
}



int main(int argc, char* argv[]) {

	glutInit(&argc, argv);
	glutInitWindowSize(windowWidth, windowHeight);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutCreateWindow("Batuhan Kaan Pat");

	glutDisplayFunc(display);
	glutReshapeFunc(onResize);

	glutKeyboardFunc(keyboard);//Space for stopping animation
	glutSpecialFunc(key);//Left and Right on keyboard to move truck
	glutTimerFunc(0, timer, 0);

	init();

	glutMainLoop();

	return 0;
}
