#include <stdio.h>
#include <stdlib.h>

int EstaDentroDelRango(int,int,int);
int LeerYValidar(int,int);

int main()
{
    int cant100y500=0,cantpares500y1200=0,cant1200y2000=0,sumcant1200y2000=0,prom1200y2000=0,num;

    num=LeerYValidar(99,2000);

    while(num!=99)
    {
        cant100y500+=EstaDentroDelRango(num,100,500);
        if(num%2==0&&EstaDentroDelRango(num,500,1200))
        {
            cantpares500y1200++;
        }
        if(EstaDentroDelRango(num,1200,2000))
        {
            cant1200y2000++;
            sumcant1200y2000+=num;
        }
        num=LeerYValidar(99,2000);
    }
    printf("La cantidad de numeros entre 100 y 500 es de: %d\n",cant100y500);
    printf("La cantidad de numeros pares entre 500 y 1200 es de: %d\n",cantpares500y1200);
    prom1200y2000=sumcant1200y2000/cant1200y2000;
    if(cant1200y2000>0)
        printf("El promedio de numeros ingresados entre 1200 y 2000 es de: %d\n",prom1200y2000);
    else
        printf("No se ingresaron numeros entre 1200 y 2000");

    return 0;
}

int EstaDentroDelRango(int n,int a,int b)
{
    int dentro;

    if(n>=a&&n<=b)
        dentro=1;
    else
        dentro=0;

    return dentro;
};

int LeerYValidar(int a,int b)
{
    int error=0,n;

    do{
    if(error!=0)
    {
        printf("Valor Incorrecto\n");
    }
    printf("Ingrese un valor: ");
    scanf("%d",&n);
    error=1;
    }while(EstaDentroDelRango(n,a,b)==0);

    return n;
};
