#include <stdlib.h>
#include <stdio.h>
#include "Application.h"

int main()
{
    Application firstApplication(nullptr);
    firstApplication.buildStateTree();
    return firstApplication.execApp();
}