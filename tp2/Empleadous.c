#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Empleadous.h"

int getInt(char mensaje[])
{
    int num;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%d", &num);

    return num;
}

void printEmployee(eEmployees unEmpleado)
{
    printf("%d\t%s\t\t%s\t\t%.2f\t\t%d\n", unEmpleado.id,unEmpleado.name, unEmpleado.lastName, unEmpleado.salary,unEmpleado.sector);
}

void printListEmployees(eEmployees list[], int len)
{
    int i;
    eEmployees aux;

    printf("*****   Nombre|          Apellido|        Salario|       Sector|   *****\n\n");

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty!=1)
        {
            orderEmployees(list,len,aux);
            for(i=0; i<len; i++)
            {
                if(list[i].isEmpty!=1)
                {
                    printEmployee(list[i]);
                }
            }
        }
        else
        {
            printf("No hay empleados cargados en el sistema\n");
        }
        break;
    }
}

void initEmployees(eEmployees list[],int len)
{
    int i;
    for(i=0; i<len; i++)
    {
        list[i].isEmpty = 1;
        list[i].id = -1;
    }
}

int findEmployeeById(eEmployees list[],int len)
{
    int i;

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty==1)
        {
            return i;
        }
    }

    return -1;
}

void addEmployee(eEmployees list[],int len)
{
    int i;
    char nombre[51];
    char apellido[51];


    i=findEmployeeById(list,len);

    if(i!=-1)
    {
        list[i].id=i+1;

        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(list[i].name);

        printf("Ingrese apellido: ");
        fflush(stdin);
        gets(list[i].lastName);

        printf("Ingrese sueldo: ");
        scanf("%f", &list[i].salary);

        printf("Ingrese sector: ");
        scanf("%d", &list[i].sector);

        list[i].isEmpty=0;
    }
    else
    {
        printf("No hay lugar disponible\n");
    }
}

void removeEmployee(eEmployees list[],int len)
{
    int i;
    int id;
    int flag=0;

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty !=1)
        {
            id=getInt("ingrese el legajo del empleado a dar de baja: ");

                if(id==list[i].id)
                {
                    printf("ingrese el legajo del empleado a dar de baja:\n");
                    printEmployee(list[i]);
                    list[i].isEmpty=1;
                    flag=1;
                }

            if(flag==0)
            {
                printf("No ingreso un legajo valido\n");
            }
        }
        else
        {
            printf("No hay empleados cargados en el sistema\n");
        }
        break;
    }
}

void modifyEmployee(eEmployees list[],int len)
{
    int i;
    int flag=0;
    int option;
    int id;

     if(list[i].isEmpty!=1)
        {
            id=getInt("Ingrese el id del empleado a modificar: ");

            if (id==list[i].id && list[i].isEmpty==0)
            {
                 printf("Se modificara al siguiente empleado:\n");
                    printEmployee(list[i]);

                    option=getInt("Escoja el campo a modificar:\n1.Nombre\n2.Apellido\n3.Salario\n4.Sector\n5.Salir\nElija una opcion: ");
                    system("cls");
                    switch(option)
                    {
                    case 1:
                        printf("Ingrese el nuevo nombre: ");
                        fflush(stdin);
                        gets(list[i].name);
                        flag=1;
                        break;
                    case 2:
                        printf("Ingrese el nuevo apellido: ");
                        fflush(stdin);
                        gets(list[i].lastName);
                        flag=1;
                        break;
                    case 3:
                        printf("Ingrese el nuevo salario: ");
                        scanf("%f", &list[i].salary);
                        flag=1;
                        break;
                    case 4:
                        printf("Ingrese el nuevo sector: ");
                        scanf("%d", &list[i].sector);
                        flag=1;
                        break;
                    case 5:
                        flag=1;
                        break;
                    }
            }
            if(flag==0)
            {
                printf("No ingreso un legajo valido\n");
            }
        }
        else
            {
               printf("No hay empleados cargados en el sistema\n");
            }

}

void orderEmployees(eEmployees list[],int len,eEmployees aux)
{
   int i;
    int j;

    for(i=0; i<len-1; i++)
    {
        if(list[i].isEmpty==0)
        {
            for(j=i+1; j<len; j++)
            {
                if(list[j].isEmpty==0)
                {
                    if(list[i].sector>list[j].sector)
                    {
                        aux=list[i];
                        list[i]=list[j];
                        list[j]=aux;
                    }
                    else if(list[i].sector==list[j].sector)
                    {
                        if(stricmp(list[i].lastName, list[j].lastName)>0)
                        {
                            aux=list[i];
                            list[i]=list[j];
                            list[j]=aux;
                        }
                        else if(stricmp(list[i].lastName, list[j].lastName)==0)
                        {
                            if(stricmp(list[i].name, list[i].name)>1)
                            {
                                aux=list[i];
                                list[i]=list[j];
                                list[j]=aux;
                            }
                        }
                    }
                }
            }
        }
    }
}


