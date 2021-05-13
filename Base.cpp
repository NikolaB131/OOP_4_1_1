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
        // удаление объекта из списка потомков у старого родителя
        for (list<Base *>::iterator itChild = pParent->children.begin(); itChild != pParent->children.end(); itChild++)
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

int Base::getState()
{
    return state;
}

Base *Base::findObject(string name, Base *parent)
{
    if (parent == nullptr)
        parent = this;
    list<Base *>::iterator itChild;
    itChild = parent->children.begin(); // присвоение списку итератора
    while (itChild != parent->children.end()) // проход по всем потомкам
    {
        if (parent->name == name) // если имя найдено
            return parent; // возврат указателя на объект
        itChild++;
    }
    itChild--; // возврат итератора к последнему потомку списка
    if ((*itChild)->children.empty()) // если объект не найден
        return nullptr; // выход из рекурсии
    else
    {
        cout << endl;
        findObject(name, *itChild); // вызов того же самого для потмока
    }
}

void Base::showTree(Base *parent)
{
    if (parent == nullptr) // для корневого объекта (чтобы с чего-то начать рекурсию)
        parent = this;
    if (parent->pParent == nullptr && children.empty()) // если в иерархии только корневой объект
    {
        cout << getName();
        return;
    }
    else if (parent->pParent == nullptr) // вывод корневого объекта
    {
        cout << getName() << endl;
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

void Base::showStateTree(Base *parent)
{

}