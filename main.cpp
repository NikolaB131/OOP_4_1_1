#include <stdlib.h>
#include <stdio.h>
#include "Application.h"

int main()
{
    Application firstApplication(nullptr);
    firstApplication.buildPathTree();
    return firstApplication.execApp();
}
