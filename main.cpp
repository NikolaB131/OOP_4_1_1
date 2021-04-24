#include <stdlib.h>
#include <stdio.h>
#include "Application.h"

int main()
{
    Application firstApplication(nullptr);
    firstApplication.buildTree();
    return firstApplication.execApp();
}