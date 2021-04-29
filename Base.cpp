#include "Base.h"

Base::Base(Base *pParent, string name)
{
    setName(name); // имя класса
    this->pParent = pParent; // присваивание указателя на текущий обьект к указателю, передаваемому через конструктор
    if (pParent) // если переданный конструктору указатель равен 0, тогда false
    {
        pParent->children.push_back(this); // запись указателя на текущий обьект в родителя
    }
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
        // удаление объекта из списка потомков у родителя
        for (list<Base *>::iterator itChild = pParent->children.begin(); itChild != pParent->children.end() ; itChild++)
        {
            if (*itChild == this)
            {
                pParent->children.erase(itChild);
            }
        }
        pParent = ptrParent; // присвоение нового родителя
        pParent->children.push_back(this);
    }
}

Base *Base::getParent()
{
    return pParent;
}

void Base::showTree(Base *parent)
{
    if (parent == nullptr)
        parent = this;
    if (parent->pParent == nullptr)
    {
        if (!children.empty()) // если у корневого объекта есть потомки
        {
            cout << getName() << endl; // вывод имени корневого объекта
        }
        else {
            cout << getName();
            return;
        }
    }
    list<Base *>::iterator itChild;
    cout << parent->getName(); // вывод имени родителя
    itChild = parent->children.begin(); // присвоение списку итератора
    while (itChild != parent->children.end()) // проход по всем потомкам
    {
        cout << "  " << (*itChild)->getName(); // вывод имени потомка
        itChild++;
    }
    itChild--; // возврат итератора к последнему потомку списка
    if ((*itChild)->children.empty()) // если у последнего потомка нету потомков
        return; // выход из рекурсии
    else
    {
        cout << endl;
        showTree(*itChild); // вызов того же самого для потмока
    }
}