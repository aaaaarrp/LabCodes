
#include <iostream>
using namespace std;

// Base class
class Animal
{
public:
    void animalSound()
    {
        cout << "\nThe animal makes a sound. \n";
    }
};

// Derived class
class Pig : public Animal
{
public:
    void animalSound()
    {
        cout << "The pig says: wee wee! \n";
    }
};

// Derived class
class Dog : public Animal
{
public:
    void animalSound()
    {
        cout << "The dog says: bow wow! \n";
    }
};

// Derived class
class Cat : public Animal
{
public:
    void animalSound()
    {
        cout << "The cat says: meow meow! \n";
    }
};

int main()
{
    Animal myAnimal;
    Pig myPig;
    Dog myDog;
    Cat myCat;

    myAnimal.animalSound();
    myPig.animalSound();
    myDog.animalSound();
    myCat.animalSound();
    return 0;
}