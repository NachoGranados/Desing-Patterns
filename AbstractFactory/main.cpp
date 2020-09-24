#include <iostream>

using namespace std;

class Shape {
  public:
    Shape() {
    }
    virtual void draw() = 0;

};

class Circle : public Shape {
  public:
    void draw() {
      cout << "circle " << endl;
    }
};

class Square : public Shape {
  public:
    void draw() {
      cout << "square " << endl;
    }
};

class AbstractFactory {
  public:
    virtual Shape* createCircle() = 0;
    virtual Shape* createSquare() = 0;
};

class Factory : public AbstractFactory {
  public:
    Shape* createCircle() {
      return new Circle;
    }
    Shape* createSquare() {
      return new Square;
    }
};

int main() {

    AbstractFactory* factory = new Factory;

  Shape* shapes[2];

  shapes[0] = factory -> createCircle();
  shapes[1] = factory -> createSquare();

  for (int i=0; i < 3; i++) {

    shapes[i] -> draw();

  }

}
