#ifndef APPLICATION_H
#define APPLICATION_H
#include "Base.h"

class Application : public Base
{
public:
    Application(Base* pParent):Base(pParent) {} // ссылается на конструктор класса Base
    void buildTree(); // ввод дерева иерархии
    void buildStateTree(); // ввод дерева иерархии с состоянием объектов (классы принадлежности 2-4)
    void buildBetterTree(); // ввод дерева иерархии с состоянием объектов (классы принадлежности 2-6)
    void buildPathTree(); // ввод дерева иерархии с состоянием объектов
    int execApp(); // запуск приложения
};
#endif
