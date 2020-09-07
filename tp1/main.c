#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    int num1;
    int num2;
    int opcion;
    int resultadoSuma;
    int resultadoResta;
    int resultadoMulti;
    float resultadoDiv;
    int factorialA;
    int factorialB;
    int banderaA=0;
    int banderaB=0;
    int banderaCalculo=0;
    int banderaOperandoA=0;
    int banderaOperandoB=0;
    char seguir = 's';
    char confirmar;

    do
    {
        if(banderaA==0)
        {
            printf("1)ingrese el primer operando A=X.\n");
        }
        else
        {
            printf("1)ingrese el primer operando A=%d.\n", num1);
        }
        if(banderaB==0)
        {
            printf("2)ingrese el segundo operando B=Y.\n");
        }
        else
        {
            printf("2)ingrese el segundo operando B=%d.\n", num2);
        }


        printf("3)Calcular todas las operaciones.\n");
        printf("4)Informar resultados.\n");
        printf("5)Salir.\n");
        printf("ingrese un opcion: ");
        scanf("%d", &opcion);



        switch(opcion)
        {
            case 1:
                    printf("1)ingrese el primer operando A=X.\n");
                    scanf("%d",&num1);
                    banderaA=1;

                break;

            case 2:
                    printf("2)ingrese el segundo operando B=Y.\n");
                    scanf("%d",&num2);
                    banderaB=1;
               break;

            case 3:
                if(banderaA==1&&banderaB==1)
                {
                    resultadoSuma=suma(num1,num2);
                    resultadoResta=resta(num1,num2);
                    resultadoMulti=multiplicar(num1,num2);
                    resultadoDiv=dividir(num1,num2);
                    factorialA=factorial(num1);
                    factorialB=factorial(num2);
                    banderaCalculo=1;
                }
                else
                {
                    printf("error, no se puede calcular las operaciones ya que falta algun operador");
                }
                break;

            case 4:
                if(banderaCalculo==1)
                {
                    if(num1==0)
                    {
                        printf("el resultado de la suma es: %d\n", resultadoSuma);
                        printf("el resultado de la resta es: %d\n", resultadoResta);
                        printf("el resultado de la multiplicacion es: %d\n", resultadoMulti);
                        printf("no es posible dividir por 0\n");
                        printf("el factorial de %d es: %d\n",num1, factorialA);
                        printf("el factorial de %d es: %d\n",num2, factorialB);
                    }
                    printf("el resultado de la suma es: %d\n", resultadoSuma);
                    printf("el resultado de la resta es: %d\n", resultadoResta);
                    printf("el resultado de la multiplicacion es: %d\n", resultadoMulti);
                    printf("el resultado de la division es: %.2f\n", resultadoDiv);
                    printf("el factorial de %d es: %d\n",num1, factorialA);
                    printf("el factorial de %d es: %d\n",num2, factorialB);
                }
                else
                {
                    printf("error, no se pueden mostrar los resultados ya que no se calculo antes");
                }
                break;

            case 5:
                    printf("Seguro que quiere salir?: ");
                    fflush(stdin);
                    scanf("%c",&confirmar);

                if(confirmar=='s')
                {
                    seguir='n';
                }
                break;

            default:
                    printf("error, ingrese una opcion valida");
        }

        system("pause");
        system("cls");

    }while(seguir == 's');
    return 0;
}
