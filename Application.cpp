#include "Application.h"
#include "Future2.h"

void Application::buildTree()
{
    string root, parent, child;
    cin >> root;
    setName(root); // установка имени корневого объекта
    Base *temp = this; // позже присваивается последний созданный объект
    cin >> parent;
    cin >> child;
    while (parent != child) {
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
    bool unique = true;
    cin >> root;
    setName(root); // установка имени корневого объекта
    Base *temp = this; // позже присваивается последний созданный объект
    cin >> parent;
    cin >> child;
    cin >> relateClass;
    cin >> state;
    while (parent != "endtree") {
        if (child != temp->findObject(child)->getName())
            switch (relateClass) {
                case 1:
            }
        cin >> parent;
        cin >> child;
    }
}

int Application::execApp()
{
    showTree();
    return 0;
}