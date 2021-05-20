#include "Application.h"
#include "Future2.h"
#include "Future3.h"
#include "Future4.h"

void Application::buildTree()
{
    string root, parent, child;
    Base *temp = this; // позже присваивается последний созданный объект
    cin >> root;
    setName(root); // установка имени корневого объекта
    cin >> parent;
    cin >> child;
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
        cin >> parent;
        cin >> child;
    }
}

void Application::buildStateTree()
{
    string root, parent, child;
    int relateClass, state;
    Base *temp;
    cin >> root;
    setName(root); // установка имени корневого объекта
    cin >> parent;
    cin >> child;
    cin >> relateClass;
    cin >> state;
    while (true)
    {
        if (findObject(child) == nullptr) // проверка на уникальность имени объекта
        {
            switch (relateClass) // опредление класса принадлежности объекта
            {
                case 2:
                    temp = findObject(parent); // посик указателся на нужного родителя
                    new Future2(temp, child); // создание объекта с классом принадлежности Future2
                    break;
                case 3:
                    temp = findObject(parent); // посик указателся на нужного родителя
                    new Future3(temp, child); // создание объекта с классом принадлежности Future3
                    break;
                case 4:
                    temp = findObject(parent); // посик указателся на нужного родителя
                    new Future4(temp, child); // создание объекта с классом принадлежности Future4
                    break;
                default:
                    break;
            }
        }
        else // если имя объекта не уникально
            break;
        cin >> parent;
        if (parent == "endtree")
            break;
        cin >> child;
        cin >> relateClass;
        cin >> state;
    }
}

int Application::execApp()
{
    showStateTree();
    return 0;
}