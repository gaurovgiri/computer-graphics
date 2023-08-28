#include <iostream>
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

void drawBLA()
{
    int dx = abs(x_2 - x_1);
    int dy = abs(y_2 - y_1);
    int x_inc, y_inc, p;
    if (x_2 >= x_1)
        x_inc = 1;
    else
        x_inc = -1;

    if (y_2 >= y_1)
        y_inc = 1;
    else
        y_inc = -1;

    int x = x_1;
    int y = y_1;

    drawPixel(x, y);

    if (dx > dy)
    {
        p = 2 * dy - dx;
        for (int k = 0; k < dx; k++)
        {
            if (p < 0)
            {
                x += x_inc;
                p = p + 2 * dy;
            }
            else
            {
                x += x_inc;
                y += y_inc;
                p = p + 2 * dy - 2 * dx;
            }
            cout << x << " " << y << endl;
            drawPixel(x, y);
        }
    }
    else
    {
        p = 2 * dx - dy;
        for (int k = 0; k < dy; k++)
        {
            if (p < 0)
            {
                y += y_inc;
                p = p + 2 * dx;
            }
            else
            {
                x += x_inc;
                y += y_inc;
                p = p + 2 * dx - 2 * dy;
            }
            cout << x << " " << y << endl;
            drawPixel(x, y);
        }
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0., 0., 0., 1.);
    drawBLA();
    glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
    if (key == 'q' || key == 'Q')
        exit(0);
}

int main(int argc, char *argv[])
{
    cout << "Enter x1 and y1: ";
    cin >> x_1 >> y_1;
    cout << "Enter x2 and y2: ";
    cin >> x_2 >> y_2;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);

    glutCreateWindow("BLA Line Drawing");
    gluOrtho2D(-250, 250, -250, 250);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
