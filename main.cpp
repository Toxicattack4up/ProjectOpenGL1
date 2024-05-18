#include <GL/glut.h>

float angle = 0.1;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    glTranslatef(0.0, 0.0, -3.0); // �������� ��� ������ ������
    glRotatef(angle, -1.0, -1.0, -1.0); // ������� � ������ �������

    glBegin(GL_QUADS);
    // �������� �����
    glColor3f(0.5, 0.5, 0.5); // �����
    glVertex3f(-0.5, -0.5, 0.5);
    glVertex3f(0.5, -0.5, 0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(-0.5, 0.5, 0.5);
    // ������ �����
    glColor3f(0.0, 0.5, 0.5); // �����-���������
    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f(0.5, -0.5, -0.5);
    glVertex3f(0.5, 0.5, -0.5);
    glVertex3f(-0.5, 0.5, -0.5);
    // ������� �����
    glColor3f(0.5, 0.0, 0.5); // ���������
    glVertex3f(-0.5, 0.5, 0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(0.5, 0.5, -0.5);
    glVertex3f(-0.5, 0.5, -0.5);
    // ������ �����
    glColor3f(0.5, 0.5, 0.0); // ���������
    glVertex3f(-0.5, -0.5, 0.5);
    glVertex3f(0.5, -0.5, 0.5);
    glVertex3f(0.5, -0.5, -0.5);
    glVertex3f(-0.5, -0.5, -0.5);
    // ����� �����
    glColor3f(0.0, 0.0, 0.5); // �����-�����
    glVertex3f(-0.5, -0.5, 0.5);
    glVertex3f(-0.5, 0.5, 0.5);
    glVertex3f(-0.5, 0.5, -0.5);
    glVertex3f(-0.5, -0.5, -0.5);
    // ������ �����
    glColor3f(0.5, 0.0, 0.0); // �����-�������
    glVertex3f(0.5, -0.5, 0.5);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(0.5, 0.5, -0.5);
    glVertex3f(0.5, -0.5, -0.5);
    glEnd();

    glutSwapBuffers();
}

void timer(int value)
{
    angle += 2.0;

    if (angle > 360)
        angle -= 360;

    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    gluPerspective(45.0, 1.0, 1.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 800); // ����������� ����
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL - Colorful cube");

    init();
    glutDisplayFunc(display);
    glutTimerFunc(16, timer, 0);
    glutMainLoop();
    return 0;
}
