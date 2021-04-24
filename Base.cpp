#include "Base.h"

Base::Base(Base *pParent)
{
    setName("Base"); // имя базового класса "Base"
    this->pParent = pParent; // присваивание указателя на текущий обьект к указателю, передаваемому через конструктор
    if (pParent) // если переданный конструктору указатель равен 0, тогда false
    {
        pParent->addChild(this); // запись указателя на текущий обьект в родителя
    }
}

Base::Base(Base *pParent, string name)
{
    setName(name); // имя класса
    this->pParent = pParent; // присваивание указателя на текущий обьект к указателю, передаваемому через конструктор
    pParent->addChild(this); // запись указателя на текущий обьект в родителя
}

void Base::setName(string name)
{
    this->name = name;
}

string Base::getName()
{
    return name;
}

void Base::setParent(Base *ptrParent)
{
    if (ptrParent) // если указатель, переданный методу не 0, тогда true
    {
        pParent = ptrParent;
        pParent->addChild(this);
    }
}

Base *Base::getParent()
{
    return pParent;
}

void Base::addChild(Base *pChild)
{
    children.push_back(pChild); // запись указателя на потомка в списке потомков у родителя
}