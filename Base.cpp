#include "Base.h"

Base::Base(Base* pParent, string name)
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
    // корневой объект не удаляется т.к. удаляются только потомки у каждого объекта
    for (list<Base*>::iterator itChild = children.begin(); itChild != children.end(); itChild++)
    {
        delete *itChild; // удаление потомка
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

void Base::setParent(Base* ptrParent)
{
    if (ptrParent) // если указатель, переданный методу не 0, тогда true
    {
        // удаление объекта из списка потомков у старого родителя
        for (list<Base*>::iterator itChild = pParent->children.begin(); itChild != pParent->children.end(); itChild++)
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

Base* Base::getParent()
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

Base* Base::findObject(string name)
{
    if (this->name == name) // если имя найдено
    {
        return this;
    }
    for (list<Base*>::iterator itChild = children.begin(); itChild != children.end(); itChild++) // поиск имени в потомках, если они есть
    {
        // спускаемся на уровень ниже, до тех пор, пока не найдем нужное имя
        if ((*itChild)->findObject(name) != nullptr) // чтобы переборка потомков не заканчивалась на первом неудачном варианте
        {
            return (*itChild)->findObject(name); // если имя найдено
        }
    }
    return nullptr; // если имя в потомках не найдено
}

Base* Base::findObjectByPath(string path)
{
    if (path.substr(0, 2) == "//") // если использовался уникальный поиск по имени
    {
        return findObject(path.substr(2)); // то можем использовать findObject()
    }
    else if (path.substr(0, 1) == "/") // если использовался поиск по пути
    {
        if (this->getName() != getPathItem(path, 1))
        {
            return nullptr; // если имя корневого объекта не совпадает с именем корневого объекта в пути
        }
        Base* child;
        Base* parent = this;
        int level = 2; // level равен 2, т.к. мы начинаем с подстроки стоящей после подстроки с корневым объектом
        bool found;
        string pathItem = getPathItem(path, level);
        while (!pathItem.empty()) // если выделенная подстрока пути не пустая
        {
            found = false; // возвращение к значению по умолчанию
            for (list<Base*>::iterator itChild = parent->children.begin(); itChild != parent->children.end(); itChild++)
            {
                if ((*itChild)->getName() == pathItem) // если имя найдено
                {
                    found = true;
                    child = *itChild; // запись указателя на необходимый объект
                    break;
                }
            }
            if (!found) // если имя не найдено
            {
                return nullptr;
            }
            parent = child; // спускаемся на уровень ниже
            pathItem = getPathItem(path, ++level); // получение следующей подстроки пути
        }
        return parent;
    }
    return nullptr; // если path начинается не с "/" или "//"
}

string Base::getPathItem(string path, int level)
{
    int end, start = 1, levelCurrent = 1; // индекс в start указывает на первый символ после первого '/'
    while (start != 0) // пока start не вышел за пределы строки с путём
    {
        end = path.find('/', start); // следующий '/' после start, find() возвращает -1 если ничего не нашел
        if (levelCurrent == level) // если необходимый уровень достигнут
        {
            return path.substr(start, end - start);
        }
        levelCurrent++; // переходим к следующему имени
        start = end + 1; // если find() ничего не найдет, тогда start будет равен 0
    }
    return ""; // если имя не было найдено
}

Base* Base::getChild(string name)
{
    for (list<Base*>::iterator itChild = children.begin(); itChild != children.end(); itChild++) // проход по всем потомкам
    {
        if ((*itChild)->getName() == name) // если имя найдено
        {
            return *itChild;
        }
    }
    return nullptr; // если имя не найдено
}

void Base::showTree(Base* parent)
{
    if (parent == nullptr) // для корневого объекта (чтобы с чего-то начать рекурсию)
    {
        parent = this;
    }
    if (parent->pParent == nullptr && children.empty()) // если в иерархии только корневой объект
    {
        cout << getName();
        return;
    }
    else if (parent->pParent == nullptr) // вывод корневого объекта
    {
        cout << getName() << endl;
    }
    cout << parent->getName(); // вывод имени родителя
    list<Base*>::iterator itChild = parent->children.begin(); // инициализация итератора списка
    while (itChild != parent->children.end()) // проход по всем потомкам
    {
        cout << "  " << (*itChild)->getName(); // вывод имени потомка
        itChild++;
    }
    itChild--; // возврат итератора к последнему потомку списка
    if ((*itChild)->children.empty()) // если у последнего потомка нету потомков
    {
        return; // выход из рекурсии
    }
    else
    {
        cout << endl;
        showTree(*itChild); // вызов того же самого для потмока
    }
}

void Base::showStateTree(Base* parent)
{
    if (parent == nullptr) // для корневого объекта (чтобы с чего-то начать рекурсию)
    {
        parent = this;
    }
    if (parent->pParent == nullptr) // для корневого объекта
    {
        cout << "Test result";
        if (getState() > 0)
        {
            cout << "\nThe object " << getName() << " is ready";
        }
        else // меньше либо равно 0
        {
            cout << "\nThe object " << getName() << " is not ready";
        }
    }
    for (list<Base*>::iterator itChild = parent->children.begin(); itChild != parent->children.end(); itChild++) // проход по всем потомкам
    {
        if ((*itChild)->getState() > 0)
        {
            cout << "\nThe object " << (*itChild)->getName() << " is ready";
        }
        else // меньше либо равно 0
        {
            cout << "\nThe object " << (*itChild)->getName() << " is not ready";
        }
        showStateTree(*itChild); // вызов того же самого для потмока
    }
}

void Base::showBetterTree(Base* parent, int level)
{
    if (parent == nullptr) // для корневого объекта (чтобы с чего-то начать рекурсию)
    {
        parent = this;
    }
    if (parent->pParent == nullptr) // для корневого объекта
    {
        cout << "Object tree\n" << getName();
    }
    for (list<Base*>::iterator itChild = parent->children.begin(); itChild != parent->children.end(); itChild++) // проход по всем потомкам
    {
        string spaces;
        spaces.append(level * 4, ' '); // 4 пробела умножаются на текущий уровень
        cout << endl << spaces << (*itChild)->getName();
        showBetterTree(*itChild, level + 1); // вызов того же самого для потмока
    }
}

void Base::showSearch()
{
    string path;
    while (true)
    {
        cin >> path;
        if (path == "//")
        {
            break;
        }
        if (findObjectByPath(path) && path.rfind('/') != path.length()) // если объект найден и строка пути не содержит '/' в конце
        {
            cout << endl << path << " Object name: " << path.substr(path.rfind('/') + 1) ;
        }
        else
        {
            cout << endl << path << " Object not found" ;
        }
    }
}
