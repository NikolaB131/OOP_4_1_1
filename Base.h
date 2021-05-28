#ifndef BASE_H
#define BASE_H
#include <iostream>
#include <string>
#include <list>
using namespace std;

class Base
{
public:
    Base(Base* pParent = nullptr, string name = "Base");
    ~Base();
    void setName(string name); // определение имени объекта
    string getName(); // получение имени объекта
    void setParent(Base* pParent); // метод переопределения головного объекта
    Base* getParent(); // метод получения указателя на головной объект текущего объекта
    void setState(int state); // установка состояния объекта
    int getState(); // получение состояния объекта
    Base* findObject(string name); // получение указателя на объект по его имени
    Base* findObjectByPath(string path); // получение указателя на объект по его пути
    string getPathItem(string path, int level); // получение необходимого имени из всего пути
    Base* getChild(string name); // получение указателя на потомка по его имени у родителя
    void showTree(Base* parent = nullptr); // вывод дерева иерархии на экран
    void showStateTree(Base* parent = nullptr); // вывод списка готовности объектов
    void showBetterTree(Base* parent = nullptr, int level = 1); // вывод другого дерева иерархии на экран
    void showSearch(); // вывод результата поиска объекта
private:
    string name;
    Base* pParent; // указатель на родителя
    int state; // состояние объекта
protected:
    list<Base*> children; // список указателей на потомков
};
#endif
