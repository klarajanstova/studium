/*
  Tento zdrojovy kod jsem vypracovala zcela samostatne bez cizi pomoci
 * Nekopirovala jsem ani neopsala jsem cizi zdrojove kody
 * Nikdo me pri vypracovani neradil
 * Pokud nektery radek porusuje toto pravidlo je oznacen
 * NENI MOJE TVORBA
 * Poruseni techto pravidel se povazuje za podvod, ktery lze potrestat VYLOUCENIM ZE STUDIA
 * Klara Janstova, 35925
 */



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

 

 /*8.	DOMÁCÍ ÚKOL È. 1 - Kalkulaèka: Napište program, který bude s uživatelem komunikovat pomocí pøíkazové øádky a bude poèítat
 +, -, *, /, sin, cos, tan, druhou odmocninu. Vždy se zadává pouze èíslo nebo operace, není tøeba parsovat výraz.
 Program bude pracovat jako obyèejná kalkulaèka: uživatel zadá jednociferné èíslo, pak zadá operaci.
 V pøípadì funkcí typu "sin" dostane výsledek, v pøípadì operátorù typu "+" zadá další jednociferné èíslo a poté získá výsledek.
 S výsledkem musí jít dále pracovat, tedy rovnou mùžeme zadat další operaci.
 Program se ukonèí zadáním operace "Q".
 */
