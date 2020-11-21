

#include <iostream>
#include <stdio.h>


int vynasob(int c)
{
    int i = 1, v;
    if (c < 1 || c > 10)
        return -1;

  
    for(i; i <= 10; i++)
    {
        v = i * c;
        printf("%d * %d = %d\n", i, c, v);
    }
    return 0;
}


void nazevmesice(int m)
{
    switch (m) {
    case 1:
        m = 1;
        printf("leden\n");
        break;
    case 2:
        m = 2;
        printf("unor\n");
        break;
    case 3:
        m = 3;
        printf("brezen\n");
        break;
    case 4:
        m = 4;
        printf("duben\n");
        break;
    case 5:
        m = 5;
        printf("kveten\n");
        break;
    case 6:
        m = 6;
        printf("cerven\n");
        break;
    case 7:
        m = 7;
        printf("cervenec\n");
        break;
    case 8:
        m = 8;
        printf("srpnen\n");
        break;
    case 9:
        m = 9;
        printf("zari\n");
        break;
    default:
        printf("spatny mesic\n");
        break;
    }
}


int vek(int a, int b, int c, int d, int e, int f)
{
    int vysledek = 0;
    

    int den = (c - f);
    int mes = (b - e);
    int rok = (a - d);
    
    int vysl1 = (rok * 365);
    int vysl2 = ((365 / 12) * mes);
       

        vysledek = den + vysl1 + vysl2;
        printf("pocet dnu = %d\n", vysledek);
        return 0;
    }

int main()
{
    int cislo = 7;
    vynasob(cislo);

    int mesic = 9;
    nazevmesice(mesic);
    
    int a = 2020; 
    int b = 11; 
    int c = 6; 

    int d = 1995; 
    int e = 5; 
    int f = 23;
    vek(a, b, c, d, e, f);
}





