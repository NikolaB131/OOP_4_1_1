#ifndef APPLICATION_H
#define APPLICATION_H
#include "Base.h"

class Application : public Base
{
public:
    Application(Base *pParent):Base(pParent) {} // ссылается на конструктор класса Base
    void buildTree(); // ввод дерева иерархии
    void buildStateTree(); // ввод дерева иерархии с состоянем объектов
    int execApp(); // запуск приложения
};
#endif