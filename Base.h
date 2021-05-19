#ifndef BASE_H
#define BASE_H
#include <iostream>
#include <string>
#include <list>
using namespace std;

class Base
{
public:
    Base(Base *pParent = nullptr, string name = "Base");
    void setName(string name); // определение имени объекта
    string getName(); // получение имени объекта
    void setParent(Base *pParent); // метод переопределения головного объекта
    Base *getParent(); // метод получения указателя на головной объект текущего объекта
    int getState(); // возвращает значение состояния объекта
    Base *findObject(string name, Base *parent = nullptr); // получение указателя на объект по его имени
    void showTree(Base *parent = nullptr); // вывод дерева иерархии на экран
    void showStateTree(Base *parent = nullptr); // вывод спписка готовности объектов
private:
    string name;
    Base *pParent; // указатель на родителя
    int state; // состояние оъекта
protected:
    list<Base *> children; // список указателей на потомков
};
#endif