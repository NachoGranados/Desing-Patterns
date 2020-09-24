#include <iostream>

using namespace std;

class Rectangle
{
public:
    virtual void drawAdapter() = 0;
};

class RectangleAdaptee
{
public:
    RectangleAdaptee(int x1, int y1, int x2, int y2) {
        X1 = x1;
        Y1 = y1;
        X2 = x2;
        Y2 = y2;
    }
    void draw() {
        cout << "X1: " << X1 << endl;
        cout << "Y1: " << Y1 << endl;
        cout << "X2: " << X2 << endl;
        cout << "Y2: " << Y2 << endl;
    }
private:
    int X1;
    int Y1;
    int X2;
    int Y2;
};

class RectangleAdapter: public Rectangle, private RectangleAdaptee
{
public:
    RectangleAdapter(int x, int y, int w, int h):
            RectangleAdaptee(x, y, x + w, y + h) {
    }

    void drawAdapter() {
        draw();
    }
};

int main()
{
    int x = 20, y = 50, w = 300, h = 200;
    Rectangle *r = new RectangleAdapter(x,y,w,h);
    r -> drawAdapter();
}
