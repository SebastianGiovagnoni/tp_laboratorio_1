#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Empleadous.h"

#define X 1000

int main()
{
    int option;

    eEmployees list[X];

    initEmployees(list,X);

    do
    {
        option=getInt("1.Alta\n2.Modificar\n3.Baja\n4.Informar lista de empleados\n5.Salir\nElija una opcion: ");
        switch(option)
        {
        case 1:
            addEmployee(list,X);
            break;
        case 2:
            modifyEmployee(list,X);
            break;
        case 3:
            removeEmployee(list,X);
            break;
        case 4:
            printListEmployees(list,X);
            break;
        }

        system("pause");
        system("cls");
    }
    while(option!=5);

    return 0;
}

