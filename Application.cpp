#include "Application.h"
#include "Future2.h"
#include "Future3.h"
#include "Future4.h"
#include "Future5.h"
#include "Future6.h"

void Application::buildTree()
{
    string root, parent, child;
    Base* temp = this; // позже присваивается последний созданный объект
    cin >> root;
    setName(root); // установка имени корневого объекта
    cin >> parent >> child;
    while (parent != child)
    {
        if (parent == temp->getName()) // сравнение с именем предыдущего объекта
        {
            temp = new Future2(temp, child); // родитель - указатель на последний созданный объект
        }
        else if (temp->getParent() != nullptr && parent == temp->getParent()->getName()) // сравнение с именем родителя предыдущего объекта
        {
            temp = new Future2(temp->getParent(), child); // родитель - указатель на родителя последнего созданного объекта
        }
        cin >> parent >> child;
    }
}

void Application::buildStateTree()
{
    string root, parent, child;
    int relateClass, state;
    Base* temp;
    cin >> root;
    setName(root); // установка имени корневого объекта
    setState(1); // установка состояния корневого объекта
    while (true)
    {
        cin >> parent;
        if (parent == "endtree")
        {
            break;
        }
        cin >> child >> relateClass >> state;
        if (findObject(child) == nullptr) // проверка на уникальность имени объекта
        {
            switch (relateClass) // определение класса принадлежности объекта
            {
                case 2:
                    temp = new Future2(findObject(parent), child); // создание объекта с классом принадлежности Future2
                    temp->setState(state); // установка состояния объекта
                    break;
                case 3:
                    temp = new Future3(findObject(parent), child); // создание объекта с классом принадлежности Future3
                    temp->setState(state); // установка состояния объекта
                    break;
                case 4:
                    temp = new Future4(findObject(parent), child); // создание объекта с классом принадлежности Future4
                    temp->setState(state); // установка состояния объекта
                    break;
                default:
                    break;
            }
        }
        else // если имя объекта не уникально
        {
            break;
        }
    }
}

void Application::buildBetterTree()
{
    string root, parent, child;
    int relateClass, state;
    Base* temp;
    cin >> root;
    setName(root); // установка имени корневого объекта
    setState(1); // установка состояния корневого объекта
    while (true)
    {
        cin >> parent;
        if (parent == "endtree")
        {
            break;
        }
        cin >> child >> relateClass >> state;
        if (findObject(child) == nullptr) // проверка на уникальность имени объекта
        {
            switch (relateClass) // определение класса принадлежности объекта
            {
                case 2:
                    temp = new Future2(findObject(parent), child); // создание объекта с классом принадлежности Future2
                    temp->setState(state); // установка состояния объекта
                    break;
                case 3:
                    temp = new Future3(findObject(parent), child); // создание объекта с классом принадлежности Future3
                    temp->setState(state); // установка состояния объекта
                    break;
                case 4:
                    temp = new Future4(findObject(parent), child); // создание объекта с классом принадлежности Future4
                    temp->setState(state); // установка состояния объекта
                    break;
                case 5:
                    temp = new Future5(findObject(parent), child); // создание объекта с классом принадлежности Future5
                    temp->setState(state); // установка состояния объекта
                    break;
                case 6:
                    temp = new Future6(findObject(parent), child); // создание объекта с классом принадлежности Future6
                    temp->setState(state); // установка состояния объекта
                    break;
                default:
                    break;
            }
        }
        else // если имя объекта не уникально
        {
            break;
        }
    }
}

void Application::buildPathTree()
{
    string root, parentPath, child;
    int relateClass, state;
    Base* temp;
    cin >> root;
    setName(root); // установка имени корневого объекта
    setState(1); // установка состояния корневого объекта
    while (true)
    {
        cin >> parentPath;
        if (parentPath == "endtree")
        {
            break;
        }
        cin >> child >> relateClass >> state;
        if (!findObjectByPath(parentPath)->getChild(child)) // проверка на уникальность имени объекта на текущем уровне
        {
            switch (relateClass) // определение класса принадлежности объекта
            {
                case 2:
                    temp = new Future2(findObjectByPath(parentPath), child); // создание объекта с классом принадлежности Future2
                    temp->setState(state); // установка состояния объекта
                    break;
                case 3:
                    temp = new Future3(findObjectByPath(parentPath), child); // создание объекта с классом принадлежности Future3
                    temp->setState(state); // установка состояния объекта
                    break;
                case 4:
                    temp = new Future4(findObjectByPath(parentPath), child); // создание объекта с классом принадлежности Future4
                    temp->setState(state); // установка состояния объекта
                    break;
                case 5:
                    temp = new Future5(findObjectByPath(parentPath), child); // создание объекта с классом принадлежности Future5
                    temp->setState(state); // установка состояния объекта
                    break;
                case 6:
                    temp = new Future6(findObjectByPath(parentPath), child); // создание объекта с классом принадлежности Future6
                    temp->setState(state); // установка состояния объекта
                    break;
                default:
                    break;
            }
        }
        else // если имя объекта не уникально на текущем уровне
        {
            break;
        }
    }
}

int Application::execApp()
{
    showBetterTree();
    showSearch();
    return 0;
}
