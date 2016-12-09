#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "gl/glut.h"
// ����
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

// ������
GLfloat INNER_TORUS_RADIUS = 0.02;

void solidSphere(GLdouble radius, GLint slices = 32, GLint stacks = 32)
{
	glutSolidSphere(radius, slices, stacks);
}

void init()
{
	// ���ñ���ɫΪ��ɫ
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClearDepth(1.0);
	glShadeModel(GL_FLAT);
}

void drawPlanet(GLfloat r, GLfloat g, GLfloat b, GLfloat torus_radius, GLfloat angularSpeed, GLfloat radius)
{
	glPushMatrix();
	glColor3f(r, g, b);
	// ���Ƹ������
	glRotatef(90, 1.0, 0, 0.0);
	glutSolidTorus(INNER_TORUS_RADIUS, torus_radius, 10, 64);
	glRotatef(-90, 1.0, 0, 0.0);
	// ���ù�ת�ٶ�
	glRotatef(angularSpeed, 0.0, 1.0, 0.0);
	// ���ù�ת�뾶
	glTranslatef(torus_radius, 0.0, 0.0);
	solidSphere(radius);
	glPopMatrix();
}

void display()
{
	// ��ջ���
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glLoadIdentity();
	//gluLookAt(0, 10, 10, 0, 0, 0, 0, 1, 0);
	//glRotatef(45.0, 0.0, 0.0, 1.0);
	glTranslatef(0.0, 0.0, -20.0);
	glRotatef(90.0, 1.0, 0.0, 0);
	// ����̫��
	glColor3f(1.0, 0.0, 0.0);
	solidSphere(2.0);
	// ���Ƶ���
	glPushMatrix();
	glColor3f(0.0, 0.0, 1.0);
	// ���Ƹ������
	glRotatef(90, 1.0, 0, 0.0);
	glutSolidTorus(INNER_TORUS_RADIUS, 5.0, 10, 64);
	glRotatef(-90, 1.0, 0, 0.0);
	// ���õ���ת�ٶ�
	glRotatef(rot0, 0.0, 1.0, 0.0);
	// ���õ���뾶
	glTranslatef(5.0, 0.0, 0.0);
	// ���õ�����ת�ٶ�
	//glRotatef(rot1,0.0,1.0,0.0);
	// ���Ƶ���
	solidSphere(0.4);

	// ���Ƶ��������-����
	glColor3f(0.5, 0.6, 0.5);
	// ����������תӰ��
	//glRotatef(-rot1,0.0,1.0,0.0);

	// ����������ת�ٶ�
	glRotatef(rot9, 0.0, 1.0, 0.0);
	// ����������ת�뾶
	glTranslatef(0.6, 0.0, 0.0);
	// ��������
	solidSphere(0.1, 10, 8);
	glPopMatrix();

	// ����ˮ��
	drawPlanet(0.0, 1.0, 1.0, 2.5, rot1, 0.2);

	// ���ƽ���
	drawPlanet(0.0, 1.0, 0.0, 3.4, rot2, 0.3);

	// ���ƻ���
	drawPlanet(1.0, 0.0, 0.0, 6.6, rot3, 0.5);

	// ����ľ��
	drawPlanet(1.0, 0.1, 1.0, 8.5, rot4, 1.0);

	// ��������
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 0.0f);
	// ���Ƹ������
	glRotatef(90, 1.0, 0, 0.0);
	glutSolidTorus(INNER_TORUS_RADIUS, 12.5, 10, 64);
	glRotatef(-90, 1.0, 0, 0.0);
	// �������ǹ�ת�ٶ�
	glRotatef(rot5, 0.0, 0.4, 0.0);
	// �������ǹ�ת�뾶
	glTranslatef(12.5, 0.0, 0.0);
	// ���������Դ�
	glRotatef(rot3, 0.0, 0.3, 0.0);
	// ��������
	solidSphere(0.85);

	// �������ǹ⻷
	glRotatef(90, 1.0, 0, 0.0);
	glutSolidTorus(0.1, 1.25, 10, 64);
	glRotatef(-90, 1.0, 0, 0.0);
	glRotatef(90, 1.0, 0, 0.0);

	glutSolidTorus(0.07, 1.65, 10, 64);
	glRotatef(-90, 1.0, 0, 0.0);
	glPopMatrix();

	// ����������
	drawPlanet(0.0, 1.0, 1.0, 15.5, rot6, 0.15);

	// ���ƺ�����
	drawPlanet(0.0, 0.0, 0.5, 17.5, rot7, 0.145);

	// ����ڤ����
	drawPlanet(0.5, 0.5, 0.5, 19.5, rot8, 0.145);

	glutSwapBuffers();

	glFlush();
}

void rotate(GLfloat* rot, GLfloat angle)
{
	*rot += angle;
	if (*rot >= 360.0)
		*rot -= 360.0;
}

void idle()
{
	rotate(&rot0, 0.1);
	rotate(&rot1, 0.416);
	rotate(&rot2, 0.1631);
	rotate(&rot3, 0.053);
	rotate(&rot4, 0.0083);
	rotate(&rot5, 0.0034);
	rotate(&rot6, 0.00119);
	rotate(&rot7, 0.00069);
	rotate(&rot8, 0.0008);
	rotate(&rot9, 1.0);

	glutPostRedisplay();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLdouble)w / (GLdouble)h, 1.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
}

void main(int argc, char **argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 450);
	glutInitWindowPosition(500, 500);
	glutCreateWindow("�Ŵ���������ģ��");
	init();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(idle);
	glutMainLoop();

	return;
}