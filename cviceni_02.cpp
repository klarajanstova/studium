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





////1.	Napi�te program mal� n�sobilka z p�edn�ky pomoc� for cyklu.
////2.	Napi�te program, kter� pro dan� m�s�c(sta�� jen do z���) v roce zadan� ��slem vyp�e jeho n�zev. 
////3.	Napi�te program, kter� ze standardn�ho vstupu �te tak dlouho text, dokud nen� zad�no p�smeno X.
//4.	Napi�te program, kter� vygeneruje v�echny textov� �et�zce d�lky X = 3 z p�smen T G C A.
//5.	Napi�te program, kter� pro dan� ��slo ur�� v�echny jeho d�litele.
//6.	Napi�te program, kter� k zadan�mu datu narozen� a zadan�mu aktu�ln�mu datumu, ur�i st��� �lov�ka ve dnech.Bez pou�it� knihovny time.h.Funk�nost programu lze zkontrolovat nap��klad zde.
//7.	Program z(4) upravte pro obecn� X.
//8.	DOM�C� �KOL �. 1 - Kalkula�ka: Napi�te program, kter� bude s u�ivatelem komunikovat pomoc� p��kazov� ��dky a bude po��tat + , -, *, / , sin, cos, tan, druhou odmocninu.V�dy se zad�v� pouze ��slo nebo operace, nen� t�eba parsovat v�raz.Program bude pracovat jako oby�ejn� kalkula�ka : u�ivatel zad� jednocifern� ��slo, pak zad� operaci.V p��pad� funkc� typu "sin" dostane v�sledek, v p��pad� oper�tor� typu "+" zad� dal�� jednocifern� ��slo a pot� z�sk� v�sledek.S v�sledkem mus� j�t d�le pracovat, tedy rovnou m��eme zadat dal�� operaci.Program se ukon�� zad�n�m operace "Q".
