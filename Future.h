#ifndef FUTURE_H
#define FUTURE_H
#include "Base.h"

class Future : public Base
{
public:
    Future(Base *pParent, string name):Base(pParent, name) {} // ссылается на конструктор класса Base
private:
};
#endif