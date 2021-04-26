#include "Application.h"

Application::Application(Base *parent) {} // ссылается на коструктор по умолчанию класса Base

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
            temp = new Base(temp, child); // родитель - указатель на последний созданный объект
        }
        else if (temp->getParent() != nullptr && parent == temp->getParent()->getName()) // сравнение с именем родителя предыдущего объекта
        {
            temp = new Base(temp->getParent(), child); // родитель - указатель на родителя последнего созданного объекта
        }
        cin >> parent;
        cin >> child;
    }
}

void Application::showTree()
{
    if (!children.empty()) // если у корневого объекта есть потомки
    {
        cout << getName() << endl; // вывод имени корневого объекта
        showObjectNext(this);
    }
    else
        cout << getName();
}

int Application::execApp()
{
    showTree();
    return 0;
}

void Application::showObjectNext(Base *parent)
{
    cout << parent->getName(); // вывод имени родителя
    parent->itChild = parent->children.begin(); // присвоение списку итератора
    while (parent->itChild != parent->children.end()) // проход по всем потомкам
    {
        cout << "  " << (*parent->itChild)->getName(); // вывод имени потомка
        parent->itChild++;
    }
    parent->itChild--; // возврат итератора к последнему потомку списка
    if ((*parent->itChild)->children.empty()) // если у последнего потомка нету потомков
        return; // выход из рекурсии
    else
    {
        cout << endl;
        showObjectNext(*parent->itChild); // вызов того же самого для потмока
    }
}