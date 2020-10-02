#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Empleadous.h"

#define X 1000

int main()
{
    int option;
    int flag=0;

    eEmployees list[X];

    initEmployees(list,X);

    do
    {
        option=getInt("1.Alta\n2.Modificar\n3.Baja\n4.Informar lista de empleados\n5.Salir\nElija una opcion: ");
        system("cls");
        switch(option)
        {
        case 1:
            printf("****Alta De Empleado****\n");
            addEmployee(list,X);
            flag=1;
            break;
        case 2:
            if(flag==1)
            {
                printf("****Modificar Empleado****\n");
                modifyEmployee(list,X);
            }
            else
            {
                printf("No se puede modificar sin anter dar de alta un empleado\n");
            }

            break;
        case 3:
            if(flag==1)
            {
                printf("****Baja De Empleado****\n");
                removeEmployee(list,X);
            }
            else
            {
                printf("No se puede dar de baja sino hay empleados cargados\n");
            }

            break;
        case 4:
            if(flag==1)
            {
                printf("****Listado De Empleados****\n");
                printListEmployees(list,X);
            }
            break;
        }

        system("pause");
        system("cls");
    }
    while(option!=5);

    return 0;
}

