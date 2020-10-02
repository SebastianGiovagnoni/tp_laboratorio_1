#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
} eEmployees;

int getInt(char[]);

void initEmployees(eEmployees[],int);

int findEmployeeById(eEmployees[],int);

void addEmployee(eEmployees[],int);

void removeEmployee(eEmployees[],int);

void modifyEmployee(eEmployees[],int);

void orderEmployees(eEmployees[],int,eEmployees);

void printEmployee(eEmployees);

void printListEmployees(eEmployees[],int);





