#ifndef APPLICATION_H
#define APPLICATION_H
#include "Base.h"

class Application : public Base
{
public:
    Application(Base *parent);
    void buildTree(); // ввод дерева иерархии
    void showTree(); // вывод дерева иерархии на экран
    int execApp(); // запуск приложения
private:
    void showObjectNext(Base *parent); // служебный метод
};
#endif