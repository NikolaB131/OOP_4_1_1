#ifndef FUTURE2_H
#define FUTURE2_H
#include "Base.h"

class Future2 : public Base
{
public:
    Future2(Base *pParent, string name):Base(pParent, name) {} // ссылается на конструктор класса Base
private:
};
#endif