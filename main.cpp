#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "gl/glut.h"

// 轨道宽度
const GLfloat INNER_TORUS_RADIUS = 0.02;

GLfloat originX = 0.0;
GLfloat originY = 0.0;
GLfloat originZ = -20.0;

GLfloat speedRatio = 1.0;

// 行星
GLfloat rot0 = 0.0;
GLfloat rot1 = 0.0;
GLfloat rot2 = 0.0;
GLfloat rot3 = 0.0;
GLfloat rot4 = 0.0;
GLfloat rot5 = 0.0;
GLfloat rot6 = 0.0;
GLfloat rot7 = 0.0;
GLfloat rot8 = 0.0;
GLfloat rot9 = 0.0;

void solidSphere(GLdouble radius, GLint slices = 32, GLint stacks = 32)
{
	glutSolidSphere(radius, slices, stacks);
}

void drawPlanet(GLfloat r, GLfloat g, GLfloat b, GLfloat torus_radius, GLfloat angularSpeed, 
                GLfloat radius, void (*fun)() = NULL)
{
	glPushMatrix();
	glColor3f(r, g, b);
	// 辅助轨道
	glRotatef(90, 1.0, 0, 0.0);
	glutSolidTorus(INNER_TORUS_RADIUS, torus_radius, 10, 64);
	glRotatef(-90, 1.0, 0, 0.0);
	// 公转速度
	glRotatef(angularSpeed, 0.0, 1.0, 0.0);
	// 公转半径
	glTranslatef(torus_radius, 0.0, 0.0);
	solidSphere(radius);
	if (fun != NULL)
		fun();
	glPopMatrix();
}

// 绘制地球的卫星-月亮
void drawMoon()
{
	const GLfloat r = 0.6;
	glColor3f(0.5, r, 0.5);
	glRotatef(rot9, 0.0, 1.0, 0.0);
	glTranslatef(r, 0.0, 0.0);
	solidSphere(0.1, 10, 8);
}

// 绘制土星光环
void drawSaturnRing()
{
	glRotatef(90, 1.0, 0, 0.0);
	glutSolidTorus(0.1, 1.25, 10, 64);
	glutSolidTorus(0.07, 1.65, 10, 64);
}

void display()
{
	// 清空画面
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glLoadIdentity();

	glTranslatef(originX, originY, originZ);
	glRotatef(90.0, 1.0, 0.0, 0);
	// 太阳
	glColor3f(1.0, 0.0, 0.0);
	solidSphere(2.0);
	
	// 水星
	drawPlanet(0.0, 1.0, 1.0, 2.5, rot0, 0.2);
	// 金星
	drawPlanet(0.0, 1.0, 0.0, 3.4, rot1, 0.3);
	// 地球
	drawPlanet(0.0, 0.0, 1.0, 5.0, rot2, 0.4, drawMoon);
	// 火星
	drawPlanet(1.0, 0.0, 0.0, 6.6, rot3, 0.5);
	// 木星
	drawPlanet(1.0, 0.1, 1.0, 8.5, rot4, 1.0);
	// 土星
	drawPlanet(1.0, 1.0, 0.0, 12.5, rot5, 0.85, drawSaturnRing);
	// 天王星
	drawPlanet(0.0, 1.0, 1.0, 15.5, rot6, 0.15);
	// 海王星
	drawPlanet(0.0, 0.0, 0.5, 17.5, rot7, 0.145);
	// 冥王星
	drawPlanet(0.5, 0.5, 0.5, 19.5, rot8, 0.145);

	glutSwapBuffers();
	glFlush();
}

void rotate(GLfloat& rot, GLfloat angle)
{
	rot += angle * speedRatio;
	if (rot >= 360.0)
		rot -= 360.0;
}

void idle()
{
	rotate(rot2, 0.1);
	rotate(rot0, 0.416);
	rotate(rot1, 0.1631);
	rotate(rot3, 0.053);
	rotate(rot4, 0.0083);
	rotate(rot5, 0.0034);
	rotate(rot6, 0.00119);
	rotate(rot7, 0.00069);
	rotate(rot8, 0.0008);
	rotate(rot9, 1.0);

	glutPostRedisplay();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70.0, (GLdouble)w / (GLdouble)h, 1.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
}

void onSpecialKeyDown(int key, int x, int y)
{
	printf("%d\n", key);
	switch(key) 
	{
	case 101:
		originY -= 0.2;
		break;
	case 103:
		originY += 0.2;
		break;
	case 100:
		originX += 0.2;
		break;
	case 102:
		originX -= 0.2;
		break;
	case 104:
		speedRatio += 0.1;
		break;
	case 105:
		speedRatio -= 0.1;
		break;
	}
}

void onNormalKeyDown(unsigned char key, int x, int y)
{
	if (key == '-')
	{
		originZ -= 0.2;
	}
	else if (key == '=')
	{
		originZ += 0.2;
	}
	else if (key == 27)
	{
		exit(0);
	}
}

void main(int argc, char **argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(900, 600);
	glutInitWindowPosition(80, 80);
	glutCreateWindow("九大行星运行模拟");
	
	glutKeyboardFunc(onNormalKeyDown);
	glutSpecialFunc(onSpecialKeyDown);

	// 设置背景色为黑色
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClearDepth(1.0);
	glShadeModel(GL_FLAT);

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(idle);
	glutMainLoop();

	return;
}