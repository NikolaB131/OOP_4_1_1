#ifndef BASE_H
#define BASE_H
#include <iostream>
#include <string>
#include <list>
using namespace std;

class Base
{
public:
    Base(Base *pParent = nullptr); // конструктор, указатель на родителя по умолчанию равен 0
    Base(Base *pParent, string name); // конструктор с определением имени класса
    void setName(string name); // определение имени объекта
    string getName(); // получение имени объекта
    void setParent(Base *pParent); // метод переопределения головного объекта
    Base *getParent(); // метод получения указателя на головной объект текущего объекта
    void addChild(Base *pChild);
    list<Base *> children; // список указателей на потомков
    list<Base *>::iterator itChild; // итератор для списка потомков
private:
    string name;
    Base *pParent; // указатель на родителя
};
#endif