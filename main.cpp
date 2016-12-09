#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "gl/glut.h"
//����
GLfloat rot0 = 0.0;
GLfloat rot1 = 0.0;
GLfloat rot2 = 0.0;
GLfloat rot3 = 0.0;
GLfloat rot4 = 0.0;
GLfloat rot5 = 0.0;
GLfloat rot6 = 0.0;
GLfloat rot7 = 0.0;
GLfloat rot8 = 0.0;
//����
GLfloat rot9 = 0.0;
GLfloat rot10 = 0.0;
GLfloat rot11 = 0.0;

void init()
{
	glClearColor(0.0,0.0,0.0,0.0);
	glClearDepth(1.0);
	glShadeModel(GL_FLAT);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0,1.0,1.0);
	glLoadIdentity();
	//gluLookAt(0, 10, 10, 0,0,0,0, 1,0);
	//glRotatef(45.0,0.0,0.0,1.0);
	glTranslatef(0.0,0.0,-20.0);
	glRotatef(90.0,1.0,0.0,0);
	glPushMatrix();
	//����̫��
	glColor3f(1.0,0.0,0.0);
	glutSolidSphere(2.0,32,32);
	//���Ƶ���
	glPushMatrix();
	glColor3f(0.0,0.0,1.0);
	// ���Ƹ������
	glRotatef(90,1.0,0,0.0);
	glutSolidTorus(0.02, 5.0, 10, 64);
	glRotatef(-90,1.0,0,0.0);
	// ���õ���ת�ٶ�
	glRotatef(rot0,0.0,1.0,0.0);
	// ���õ���뾶
	glTranslatef(5.0,0.0,0.0);
	// ���õ�����ת�ٶ�
	//glRotatef(rot1,0.0,1.0,0.0);
	// ���Ƶ���
	glutSolidSphere(0.4,32,32);

	// ���Ƶ��������-����
	glColor3f(0.5,0.6,0.5);
	// ����������תӰ��
	//glRotatef(-rot1,0.0,1.0,0.0);

	// ���Ƹ������
	glRotatef(90,1.0,0,0.0);
	
	glRotatef(-90,1.0,0,0.0);
	// ����������ת�ٶ�
	glRotatef(rot9,0.0,1.0,0.0);
	// ����������ת�뾶
	glTranslatef(0.6,0.0,0.0);
	// ��������
	glutSolidSphere(0.1,10,8);
	glPopMatrix();

	// ����ˮ��
	glPushMatrix();
	glColor3f(0.0,1.0,1.0);
	// ���Ƹ������
	glRotatef(90,1.0,0,0.0);
	glutSolidTorus(0.02, 2.5, 10, 64);
	glRotatef(-90,1.0,0,0.0);
	// ����ˮ�ǹ�ת�ٶ�
	glRotatef(rot1,0.0,1.0,0.0);
	// ����ˮ�ǹ�ת�뾶
	glTranslatef(2.5,0.0,0.0);
	// ����ˮ���Դ�
	glRotatef(rot3,0.0,1.0,0.0);
	// ����ˮ��
	glutSolidSphere(0.2,32,32);
	glPopMatrix();
	
	//���ƽ���
	glPushMatrix();
	glColor3f(0.0,1.0,0.0);
	//���Ƹ������
	glRotatef(90,1.0,0,0.0);
	glutSolidTorus(0.02, 3.4, 10, 64);
	glRotatef(-90,1.0,0,0.0);
	// ���ý��ǹ�ת�ٶ�
	glRotatef(rot2,0.0,3.0,0.0);
	// ���ý��ǹ�ת�뾶
	glTranslatef(3.4,0.0,0.0);
	// ���ý����Դ�
	glRotatef(rot0,0.0,1.0,0.0);
	// ���ƽ���
	glutSolidSphere(0.3,32,32);
	glPopMatrix();

	//���ƻ���
	glPushMatrix();
	glColor3f(1.0,0.0,0.0);
	//���Ƹ������
	glRotatef(90,1.0,0,0.0);
	glutSolidTorus(0.02, 6.6, 10, 64);
	glRotatef(-90,1.0,0,0.0);
	// ���û��ǹ�ת�ٶ�
	glRotatef(rot3,0.0,4.0,0.0);
	// ���û��ǹ�ת�뾶
	glTranslatef(6.6,0.0,0.0);
	// ���û����Դ�
	glRotatef(rot7,0.0,2.0,0.0);
	// ���ƻ���
	glutSolidSphere(0.5,32,32);
	glPopMatrix();


	//����ľ��
	glPushMatrix();
	glColor3f(2.0,0.1,1.0);
	//���Ƹ������
	glRotatef(90,1.0,0,0.0);
	glutSolidTorus(0.02, 8.5, 10, 64);
	glRotatef(-90,1.0,0,0.0);
	// ����ľ�ǹ�ת�ٶ�
	glRotatef(rot4,0.0,0.4,0.0);
	// ����ľ�ǹ�ת�뾶
	glTranslatef(8.5,0.0,0.0);
	// ����ľ���Դ�
	glRotatef(rot3,0.0,0.3,0.0);
	// ����ľ��
	glutSolidSphere(1.0,32,32);
	
// ����ľ������-ľ��1
	glColor3f(0.4,0.3,0.5);
	// ����������תӰ��
	//glRotatef(-rot1,0.0,1.0,0.0);

	// ���Ƹ������
	glRotatef(90,1.0,0,0.0);
	
	glRotatef(-90,1.0,0,0.0);
	// ����ľ��1��ת�ٶ�
	glRotatef(rot10,0.0,1.0,0.0);
	// ����ľ��1��ת�뾶
	glTranslatef(1.3,0.0,0.0);
	// ����ľ��1
	glutSolidSphere(0.1,10,8);

	// ����ľ������-ľ��2
	glColor3f(0.5f,0.5f,0.5f);
	// ����������תӰ��
	//glRotatef(-rot1,0.0,1.0,0.0);

	// ���Ƹ������
	glRotatef(90,1.0,0,0.0);

	glRotatef(-90,1.0,0,0.0);
	// ����ľ��2��ת�ٶ�
	glRotatef(rot11,0.0,1.0,0.0);
	// ����ľ��2��ת�뾶
	glTranslatef(1.2,0.0,0.0);
	// ����ľ��2
	glutSolidSphere(0.08,10,8);
	glPopMatrix();



	//��������
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 0.0f);
	//���Ƹ������
	glRotatef(90,1.0,0,0.0);
	glutSolidTorus(0.02, 12.5, 10, 64);
	glRotatef(-90,1.0,0,0.0);
	// �������ǹ�ת�ٶ�
	glRotatef(rot5,0.0,0.4,0.0);
	// �������ǹ�ת�뾶
	glTranslatef(12.5,0.0,0.0);
	// ���������Դ�
	glRotatef(rot3,0.0,0.3,0.0);
	// ��������
	glutSolidSphere(0.85,32,32);

	//�������ǹ⻷
	glRotatef(90,1.0,0,0.0);
	glutSolidTorus(0.1, 1.25, 10, 64);
	glRotatef(-90,1.0,0,0.0);
	glRotatef(90,1.0,0,0.0);

	glutSolidTorus(0.07, 1.65, 10, 64);
	glRotatef(-90,1.0,0,0.0);
	glPopMatrix();
	glPopMatrix();

	//����������
	glPushMatrix();
	glColor3f(0.0f, 1.0f, 1.0f);
	//���Ƹ������
	glRotatef(90,1.0,0,0.0);
	glutSolidTorus(0.02, 15.5, 10, 64);
	glRotatef(-90,1.0,0,0.0);
	// ���������ǹ�ת�ٶ�
	glRotatef(rot6,0.0,0.4,0.0);
	// ���������ǹ�ת�뾶
	glTranslatef(15.5,0.0,0.0);
	// �����������Դ�
	glRotatef(rot1,0.0,0.3,0.0);
	// ����������
	glutSolidSphere(0.15,32,32);
	glPopMatrix();

	//���ƺ�����
	glPushMatrix();
	glColor3f(0.0f, 0.0, 8.0f);
	//���Ƹ������
	glRotatef(90,1.0,0,0.0);
	glutSolidTorus(0.02, 17.5, 10, 64);
	glRotatef(-90,1.0,0,0.0);
	// ���ú����ǹ�ת�ٶ�
	glRotatef(rot7,0.0,0.4,0.0);
	// ���ú����ǹ�ת�뾶
	glTranslatef(17.5,0.0,0.0);
	// ���ú������Դ�
	glRotatef(rot3,0.0,0.3,0.0);
	// ���ƺ�����
	glutSolidSphere(0.145,32,32);
	glPopMatrix();

	//����ڤ����
	glPushMatrix();
	glColor3f(0.5f, 0.5f, 0.5f);
	//���Ƹ������
	glRotatef(90,1.0,0,0.0);
	glutSolidTorus(0.02, 19.5, 10, 64);
	glRotatef(-90,1.0,0,0.0);
	// ����ڤ���ǹ�ת�ٶ�
	glRotatef(rot8,0.0,0.4,0.0);
	// ����ڤ���ǹ�ת�뾶
	glTranslatef(19.5,0.0,0.0);
	// ����ڤ�����Դ�
	glRotatef(rot2,0.0,0.3,0.0);
	// ����ڤ����
	glutSolidSphere(0.145,32,32);
	glPopMatrix();

	glutSwapBuffers();

	glFlush();
}

void rotate(GLfloat* rot,GLfloat angle)
{
	*rot+=angle;
	if(*rot>=360.0)
		*rot-=360.0;
}

void idle()
{
	rotate(&rot0,0.1);
	rotate(&rot1,0.416);
	rotate(&rot2,0.1631);
	rotate(&rot3,0.053);
	rotate(&rot4,0.0083);
	rotate(&rot5,0.0034);
	rotate(&rot6,0.00119);
	rotate(&rot7,0.00069);
	rotate(&rot8,0.0008);
	rotate(&rot9,1.0);
	rotate(&rot10,0.005);
	rotate(&rot11,0.01);

	glutPostRedisplay();
}

void reshape(int w,int h)
{
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0,(GLdouble)w/(GLdouble)h,1.0,100.0);
	glMatrixMode(GL_MODELVIEW);
}

void main(int argc,char **argv)
{
	glutInit(&argc,argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600,400);
	glutInitWindowPosition(500,500);
	glutCreateWindow("planet sim");
	init();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(idle);
	glutMainLoop();
	
	return;
}