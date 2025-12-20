#include <iostream>
using namespace std;

namespace Animal
{
    // Abstract class (acts like an interface)
    class IAnimal
    {
    public:
        virtual void display() = 0;  // pure virtual function
    };

    // Dog class
    class Dog : public IAnimal
    {
    public:
        void display() override  
        {
            cout << "Hi this is a Dog" << endl;
        }
    };

    // Cat class
    class Cat : public IAnimal
    {
    public:
        void display() override
        {
            cout << "Hi this is a Cat" << endl;
        }
    };

}

int main()
{
    IAnimal* a1 = new Dog();
    IAnimal* a2 = new Cat();

    a1->display();
    a2->display();

    delete a1;
    delete a2;

    return 0;
}
