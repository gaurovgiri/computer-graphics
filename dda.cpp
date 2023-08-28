/* OpenGL Implementation for DDA (Differential Digital Analyzer) */

#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>

using namespace std;

int x_1, y_1, x_2, y_2;

void drawPixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

void drawDDA()
{
    
    int dx = x_2 - x_1;
    int dy = y_2 - y_1;

    int steps = max(dx, dy);

    int x_inc = dx / steps;
    int y_inc = dy / steps;

    int x = x_1;
    int y = y_1;

    for (int i = 0; i < steps; i++)
    {
        drawPixel(x, y);
        x += x_inc;
        y += y_inc;
        cout << x << " " << y << endl;
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    drawDDA();
    glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
    if (key == 'q' || key == 'Q')
        exit(0);
}

int main(int argc, char **argv)
{
    cout << "Enter x1 and y1: ";
    cin >> x_1 >> y_1;

    cout << "Enter x2 and y2: ";
    cin >> x_2 >> y_2;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);

    glutCreateWindow("DDA Line Drawing");
    gluOrtho2D(-250, 250, -250, 250);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}