



#include <math.h>

#define PI 3.14159265

int main()
{
    char volba;
    double x, y, vysledek;


    printf("Vitejte v teto kalkulacce, zadejte prvni cislo: ");
    scanf("%lf", &x);

    do
    {
        
        printf("Vyberte si z nasledujicich operaci\n +, -, *, /, (s) - sin, (c) - cos, (t) - tan, (o) - odmocnina, (q) - ukonceni programu: ");
        scanf(" %c", &volba);

        switch (volba)
        {
        case '+':

            printf("Zadejte druhe cislo: ");
            scanf("%lf", &y);
            vysledek = x + y;
            printf("%lf + %lf = %lf\n", x, y, vysledek);
            x = vysledek;
            break;

        case '-':
            printf("Zadejte druhe cislo: ");
            scanf("%lf", &y);
            vysledek = x - y;
            printf("%lf - %lf = %lf\n", x, y, vysledek);
            x = vysledek;
            break;

        case '*':
            printf("Zadejte druhe cislo: ");
            scanf("%lf", &y);
            vysledek = x * y;
            printf("%lf * %lf = %lf\n", x, y, vysledek);
            x = vysledek;
            break;

        case '/':
            printf("Zadejte druhe cislo: ");
            scanf("%lf", &y);
            vysledek = x / y;
            printf("%lf / %lf = %lf\n", x, y, vysledek);
            x = vysledek;
            break;
        case 'c':

            y = 180.0 / PI;
            vysledek = acos(x) * y;
            printf("cosinus %lf je %lf rad.\n", x, vysledek);
            x = vysledek;
            break;
        case 's':
            y = 180.0 / PI;
            vysledek = asin(x) * y;
            printf("sinus %lf je %lf rad.\n", x, vysledek);
            x = vysledek;
            break;
        case 't':
            y = 180.0 / PI;
            vysledek = atan(x) * y;
            printf("tangens %lf je %lf rad.\n", x, vysledek);
            x = vysledek;
            break;
        case 'o':
            vysledek = sqrt(x);
            printf("druha odmocnina %lf je %lf\n", x, vysledek);
            x = vysledek;
            break;
        case 'q':
            printf("konec programu, dekuji a tesim se priste :)");
            break;
        default:
            printf("spatny vstup, zkus to znovu\n");
        }
       
    } while (volba != 'q');
    return 0;
    
    
}

 

