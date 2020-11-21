// cviceni_02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Tento zdrojovy kod jsem vyparcovala zcela samostate bez cizi pomoci
// Neokopiroval jsem ani neopsal jsem cizi zdrojove kody
// Nikdo me pri vypracovavani neradil
// Pokud nektery radek porusuje toto pravidlo je oznacen komentarem
// NENI MOJE TVORBA
// Poruseni techto pravidel se povazuje za podvod, ktery lze potrestat VYLOUCENIM ZE STUDIA
// Klara Janstova, 35925 

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





////1.	Napište program malá násobilka z pøednášky pomocí for cyklu.
////2.	Napište program, který pro daný mìsíc(staèí jen do záøí) v roce zadaný èíslem vypíše jeho název. 
////3.	Napište program, který ze standardního vstupu ète tak dlouho text, dokud není zadáno písmeno X.
//4.	Napište program, který vygeneruje všechny textové øetìzce délky X = 3 z písmen T G C A.
//5.	Napište program, který pro dané èíslo urèí všechny jeho dìlitele.
//6.	Napište program, který k zadanému datu narození a zadanému aktuálnímu datumu, urèi stáøí èlovìka ve dnech.Bez použití knihovny time.h.Funkènost programu lze zkontrolovat napøíklad zde.
//7.	Program z(4) upravte pro obecné X.
//8.	DOMÁCÍ ÚKOL È. 1 - Kalkulaèka: Napište program, který bude s uživatelem komunikovat pomocí pøíkazové øádky a bude poèítat + , -, *, / , sin, cos, tan, druhou odmocninu.Vždy se zadává pouze èíslo nebo operace, není tøeba parsovat výraz.Program bude pracovat jako obyèejná kalkulaèka : uživatel zadá jednociferné èíslo, pak zadá operaci.V pøípadì funkcí typu "sin" dostane výsledek, v pøípadì operátorù typu "+" zadá další jednociferné èíslo a poté získá výsledek.S výsledkem musí jít dále pracovat, tedy rovnou mùžeme zadat další operaci.Program se ukonèí zadáním operace "Q".
