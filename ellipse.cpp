#include <iostream>
#include <GL/glut.h>
#include <cmath>

using namespace std;

int xc, yc, a, b;

void drawPixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

void drawEllipse()
{
    // For Region 1
    int x = 0, y = b;
    int p = pow(b, 2) - pow(a, 2) * b + pow(a, 2) / 4; // p = b^2 - a^2 * b + a^2 / 4

    drawPixel(x + xc, y + yc);   // (x,y)
    drawPixel(x + xc, -y + yc);  // (x,-y)
    drawPixel(-x + xc, -y + yc); // (-x,-y)
    drawPixel(-x + xc, y + yc);  // (-x,y)

    while (2 * pow(b, 2) * x <= 2 * pow(a, 2) * y)
    {
        if (p < 0)
        {
            x = x + 1;
            p = p + 2 * pow(b, 2) * x + pow(b, 2);
        }
        else
        {
            x = x + 1;
            y = y - 1;
            p = p + 2 * pow(b, 2) * x - 2 * pow(a, 2) * y + pow(b, 2);
        }

        drawPixel(x + xc, y + yc);   // (x,y)
        drawPixel(x + xc, -y + yc);  // (x,-y)
        drawPixel(-x + xc, -y + yc); // (-x,-y)
        drawPixel(-x + xc, y + yc);  // (-x,y)
    }

    // For Region 2
    p = pow(b * (x + 0.5), 2) + pow(a * (y - 1), 2) - pow(a * b, 2); // p = b^2 * (x+1/2)^2 + a^2 * (y-1)^2 - a^2 * b^2

    while (y >= 0)
    {
        if (p < 0)
        {
            x = x + 1;
            y = y - 1;
            p = p + 2 * pow(b, 2) * x - 2 * pow(a, 2) * y + pow(a, 2);
        }
        else
        {
            y = y - 1;
            p = p - 2 * pow(a, 2) * y + pow(a, 2);
        }
        drawPixel(x + xc, y + yc);   // (x,y)
        drawPixel(x + xc, -y + yc);  // (x,-y)
        drawPixel(-x + xc, -y + yc); // (-x,-y)
        drawPixel(-x + xc, y + yc);  // (-x,y)
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0, 0, 0, 1);
    drawEllipse();
    glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
    if (key == 'q' || key == 'Q')
        exit(0);
}

int main(int argc, char **argv)
{
    cout << "Enter x and y: ";
    cin >> xc >> yc;
    cout << "Major axis (a): ";
    cin >> a;
    cout << "Minor axis (b): ";
    cin >> b;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);

    glutCreateWindow("Ellipse Drawing Using Mid-Point");
    gluOrtho2D(-250, 250, -250, 250);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutMainLoop();

    return 0;
}
