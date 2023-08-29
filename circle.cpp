#include <iostream>
#include <GL/glut.h>

using namespace std;

int xc, yc, r;
/*
    xc and yc -> coordinate of circle's center
    r -> radius of circle
*/

void drawPixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

void drawCircle()
{
    int x = 0, y = r;
    int p = 1 - r;

    drawPixel(x + xc, y + yc);
    drawPixel(x + xc, -y + yc);

    while (y >= x)
    {
        if (p < 0)
        {
            x = x + 1;
            p = p + 2 * x + 1;
        }
        else
        {
            x = x + 1;
            y = y - 1;
            p = p + 2 * x - 2 * y + 1;
        }

        drawPixel(y + xc, x + xc);   // (y,x)
        drawPixel(x + xc, y + yc);   // (x,y)
        drawPixel(x + xc, -y + yc);  // (x,-y)
        drawPixel(y + xc, -x + yc);  // (y,-x)
        drawPixel(-y + xc, -x + yc); // (-y, -x)
        drawPixel(-x + xc, -y + yc); // (-x, -y)
        drawPixel(-x + xc, y + yc);  // (-x, y)
        drawPixel(-y + xc, x + yc);  // (-y, x)
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0, 0, 0, 1);
    drawCircle();
    glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
    if (key == 'q' || key == 'Q')
        exit(0);
}

int main(int argc, char **argv)
{
    cout << "Enter xc and yc: ";
    cin >> xc >> yc;
    cout << "Enter radius: ";
    cin >> r;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);

    glutCreateWindow("Circle Drawing Using Mid-Point");
    gluOrtho2D(-250, 250, -250, 250);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;
}