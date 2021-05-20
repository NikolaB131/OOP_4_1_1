#include "Base.h"

Base::Base(Base *pParent, string name)
{
    setName(name); // установка имени класса
    this->pParent = pParent; // присваивание указателя на текущий обьект к указателю, передаваемому через конструктор
    if (pParent) // если переданный конструктору указатель равен 0, тогда false
    {
        pParent->children.push_back(this); // запись указателя на текущий обьект в родителя
    }
}

Base::~Base()
{
    string na1me = getName();
    if (!children.empty())
    {
        Base::~Base();
        for (list<Base *>::iterator itChild = children.begin(); itChild != children.end(); itChild++)
        {

        }
    }
    else
        delete *itChild;
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

void Base::setState(int state)
{
    this->state = state;
}

int Base::getState()
{
    return state;
}

Base *Base::findObject(string name, Base *parent)
{
    if (parent == nullptr)
        parent = this;
    if (parent->name == name) // если имя найдено
        return parent;
    list<Base *>::iterator itChild = parent->children.begin();
    while (itChild != parent->children.end()) // если есть потомки
    {
        if (findObject(name, *itChild) != nullptr) // спускаемся на уровень ниже
            return findObject(name, *itChild); // если имя найдено
        itChild++; // проверка следующего потомка
    }
    return nullptr; // если имя не найдено
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
    list<Base *>::iterator itChild = parent->children.begin(); // инициализация итератора списка
    cout << parent->getName(); // вывод имени родителя
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
    if (parent == nullptr) // для корневого объекта (чтобы с чего-то начать рекурсию)
        parent = this;
    if (parent->pParent == nullptr) // для корневого объекта
    {
        cout << "Test result";
        if (getState() > 0)
            cout << "\nThe object " << getName() << " is ready";
        else // меньше либо равно 0
            cout << "\nThe object " << getName() << " is not ready";
    }
    list<Base *>::iterator itChild = parent->children.begin(); // инициализация итератора списка
    while (itChild != parent->children.end()) // проход по всем потомкам
    {
        if ((*itChild)->getState() > 0)
            cout << "\nThe object " << (*itChild)->getName() << " is ready";
        else // меньше либо равно 0
            cout << "\nThe object " << (*itChild)->getName() << " is not ready";
        showStateTree(*itChild); // вызов того же самого для потмока
        itChild++; // переход к следующему потомку
    }
}