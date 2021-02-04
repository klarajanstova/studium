

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h> 


void alokace() // alokovani prostoru pro matice a zaroven vypis jednoduche matice 
{
    int x = 2; int y= 3;
    int* matice = (int*)malloc(x * y * sizeof(int));

}








void assign(int** arr, int x, int y, int value) // funkce na alokaci matice o velikost 5x5 a pro vkladani prvku na pozici x, y 
{
    arr[x][y] = value;
}





int main(int argc, char** argv[])
{
    char matice[100][100]; // alokace matice n * m způsob 2
    int a = 0, b = 0;
    int n, m;
    int l = 3, k = 3;
    int c, d, t, nsn, nsd;
    int i;
    for (i = 0; i < argc; i++) // vypis poradi argumentu na prikazovem radku (pro kontrolu)
        printf("argv[%d] = %s\n", i, argv[i]);





    printf("\nNapiste dve cisla\n");
    scanf_s("%d%d", &c, &d);

    a = c;
    b = d;

    while (b != 0) {
        t = b;
        b = a % b;
        a = t;
    }

    nsd = a;
    nsn = (c * d) / nsd;


    printf("Nejmensi spolecny nasobek %d a %d je %d\n", c, d, nsn);
    printf("Nejvetsi spolecny delitel %d a %d je %d\n", c, d, nsd);








    if (argc > 6) // pokud je pocet argumentu vetsi nez 5, znamena to, ze mame od uzivatele zadane m i n a pokracujeme vypoctem nsn a nsd, nasledny vypis vysledku a zapis do souboru


    {


        sscanf(argv[5], "%d", &n);
        sscanf(argv[6], "%d", &m);



        a = n;
        b = m;

        while (b != 0) {
            t = b;
            b = a % b;
            a = t;
        }

        nsd = a;
        nsn = (n * m) / nsd;


        printf("Nejmensi spolecny nasobek %d a %d je %d\n", n, m, nsn);
        printf("Nejvetsi spolecny delitel %d a %d je %d\n", n, m, nsd);



        FILE* p_soubor = fopen("matice.txt", "w");
        if (p_soubor == NULL)
        {
            printf("Soubor se nepodařilo otevřít pro zápis, zkontrolujte prosím oprávnění.");
            return 1;
        }

        fprintf(p_soubor, "Nejmensi spolecny nasobek %d a %d je %d\n", n, m, nsn);
        fprintf(p_soubor, "Nejvetsi spolecny delitel %d a %d je %d\n", n, m, nsd);



        if (fclose(p_soubor) == EOF)
        {
            printf("Soubor se nepodařilo uzavřít.");
            return 1;
        }

        //return (EXIT_SUCCESS);


        int** arr = (int**)malloc(l * sizeof(int*));

        for (int r = 0; r < l; r++)
            arr[r] = (int*)malloc(k * sizeof(int));

        //postupně naplnujeme matici 3x3 a pouzivame k tomu pozice jednotlivych prvku, matice je cislovana "programatorsky", tedy od 0 
        assign(arr, 0, 0, 1);
        assign(arr, 0, 1, 2);
        assign(arr, 0, 2, 3);
        assign(arr, 1, 0, 4);
        assign(arr, 1, 1, 5);
        assign(arr, 1, 2, 6);
        assign(arr, 2, 0, 7);
        assign(arr, 2, 1, 8);
        assign(arr, 2, 2, 100);



        // print:
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < l; j++) {
                printf("%d ", arr[i][j]);
            }
            printf("\n");

        }

        free(**arr);
        free(*arr);
        return 0;

    }

    else // pokud se pocet arumentu na prikazovem radku nerovna 6, znamena to, ze jsme dostali pouze n a tim padem musime definovat, ze n = m, nasledne provedeme nsn a nsd a zapiseme do souboru
    {
        sscanf(argv[5], "%d", &n);
        m = n;
        a = n;
        b = m;

        while (b != 0) {
            t = b;
            b = a % b;
            a = t;
        }

        nsd = a;
        nsn = (n * m) / nsd;


        printf("Nejmensi spolecny nasobek %d a %d je %d\n", n, m, nsn);
        printf("Nejvetsi spolecny delitel %d a %d je %d\n", n, m, nsd);



        FILE* p_soubor = fopen("matice.txt", "w");
        if (p_soubor == NULL)
        {
            printf("Soubor se nepodařilo otevřít pro zápis, zkontrolujte prosím oprávnění.");
            return 1;
        }

        fprintf(p_soubor, "Nejmensi spolecny nasobek %d a %d je %d\n", n, m, nsn);
        fprintf(p_soubor, "Nejvetsi spolecny delitel %d a %d je %d\n", n, m, nsd);

        if (fclose(p_soubor) == EOF)
        {
            printf("Soubor se nepodařilo uzavřít.");
            return 1;
        }

        //return (EXIT_SUCCESS);


        int** arr = (int**)malloc(l * sizeof(int*));

        for (int r = 0; r < l; r++)
            arr[r] = (int*)malloc(k * sizeof(int));

        //postupně naplnujeme matici 3x3 a pouzivame k tomu pozice jednotlivych prvku, matice je cislovana "programatorsky", tedy od 0 
        assign(arr, 0, 0, 1);
        assign(arr, 0, 1, 2);
        assign(arr, 0, 2, 3);
        assign(arr, 1, 0, 4);
        assign(arr, 1, 1, 5);
        assign(arr, 1, 2, 6);
        assign(arr, 2, 0, 7);
        assign(arr, 2, 1, 8);
        assign(arr, 2, 2, 100);



        // print:
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < l; j++) {
                printf("%d ", arr[i][j]);
            }
            printf("\n");

        }

        free(**arr);
        free(*arr);

        return 0;
    }

}


