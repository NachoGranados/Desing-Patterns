#include <iostream>

using namespace std;

class Singleton
{
private:

    static Singleton* instance;

    Singleton();

public:

    static Singleton* getInstance();

};

Singleton* Singleton::instance = 0;

Singleton* Singleton::getInstance()
{
    if (instance == 0)
    {
        instance = new Singleton();
    }

    return instance;
}

Singleton::Singleton()
{}

int main()
{

    Singleton* firstInstance = Singleton::getInstance();
    Singleton* secondInstance = Singleton::getInstance();

    cout << firstInstance << endl;
    cout << secondInstance << endl;

}
