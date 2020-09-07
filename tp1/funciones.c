int suma(int x, int y)
{
    int sumar;
    sumar=x+y;

    return sumar;
}

int resta(int x, int y)
{
    int restar;
    restar=x-y;

    return restar;
}

int multiplicar(int x, int y)
{
    int multi;
    multi=x*y;

    return multi;
}

float dividir(int x, int y)
{
    int div;
    div=x/y;

    return div;
}
int factorial(int x)
{
    int fact = 1;

    for(int i=1; i<=x; i++)
    {
        fact=fact*i;
    }

    return fact;
}

