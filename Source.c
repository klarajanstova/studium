// Tento zdrojovy kod jsem vyparcovala zcela samostate bez cizi pomoci
// Neokopiroval jsem ani neopsal jsem cizi zdrojove kody
// Nikdo me pri vypracovavani neradil
// Pokud nektery radek porusuje toto pravidlo je oznacen komentarem
// NENI MOJE TVORBA
// Poruseni techto pravidel se povazuje za podvod, ktery lze potrestat VYLOUCENIM ZE STUDIA
// Klara Janstova, 35925 


//ucelem tohoto programu je ukazka nekolika funkci, ktere programovani v C nabizi a ktere jsme se ucili 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include<windows.h> // abychom mohli menit barvu pisma 
#define MAX 100 // velikost zasobniku pro nacitani do konzole pro fgets 
#define PI 3.14159265 // definice velikosti PI pro kalkulacku 



int board[10] = { 2,2,2,2,2,2,2,2,2,2 };
int turn = 1, flag = 0;
int player, comp;

void menu_1();
void go(int n);
void start_game();
void check_draw();
void draw_board();
void player_first();
void put_X_O(char ch, int pos);
COORD coord = { 0,0 }; //nastaveni do leveho horniho horu obrazovky pro funkci piskvorky 
void gotoxy(int x, int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int prestupnyrok(int year, int mon)  
//kontrola prestupneho roku 
{
    int flag = 0;
    if (year % 100 == 0)
    {
        if (year % 400 == 0)
        {
            if (mon == 2)
            {
                flag = 1;
            }
        }
    }
    else if (year % 4 == 0)
    {
        if (mon == 2)
        {
            flag = 1;
        }
    }
    return (flag);
}


int vypocet_stari()
{
    int DaysInMon[] = { 31, 28, 31, 30, 31, 30,
                       31, 31, 30, 31, 30, 31 };
    int days, month, year;
    char dob[100];
    time_t ts;
    struct tm* ct;

    //zde naèítáme od uživatele jeho datum narození 
    printf("Zadej datum tveho narozeni, DEN: ");
    scanf("%d", &days);

    printf("Zadej datum tveho narozeni, MESIC: ");
    scanf("%d", &month);

    printf("Zadej datum tveho narozeni, ROK: ");
    scanf("%d", &year);


   

    //tato fuknce nám získá aktuální datum a èas 
    ts = time(NULL);
    ct = localtime(&ts);



    days = DaysInMon[month - 1] - days + 1;

    //kontrola prestupneho roku a pripadna uprava poctu dnu 
    if (prestupnyrok(year, month))
    {
        days = days + 1;
    }



    //osetreni dnu pro prestupny rok a 29. unor 
    if (prestupnyrok((ct->tm_year + 1900), (ct->tm_mon + 1)))
    {
        if (days >= (DaysInMon[ct->tm_mon] + 1))
        {
            days = days - (DaysInMon[ct->tm_mon] + 1);
            month = month + 1;
        }
    }
    else if (days >= DaysInMon[ct->tm_mon])
    {
        days = days - (DaysInMon[ct->tm_mon]);
        month = month + 1;
    }

    if (month >= 12)
    {
        year = year + 1;
        month = month - 12;
    }

    //vypocet poctu let, mesicu a dnu od data narozeni 
    days = days + ct->tm_mday;
    month = (12 - month) + (ct->tm_mon);
    year = (ct->tm_year + 1900) - year - 1;


    //vyprintovani presneho stari s presnosti na dny 
    printf("\nJe vam presne  %d let %d mesicu a %d dni\n", year, month, days);


}


void kalkulacka()
//tuto kalkulacku jsem zkopirovala ze cviceni, ktere jsme delali v ramci cviceni, respektive jedna se o prvni domaci ukol
        //jelikoz se jedna o celkem frekventovane zadani pouzivane v ramci vyuky programovani v C, rozhodla jsem se kalkulacku sem zaradit 
{
    char volba;
    double x, y, vysledek;


    printf("Vitejte v teto kalkulacce, zadejte prvni cislo: ");
    scanf("%lf", &x);

    //nejprve musime nacist prvni cislo od uzivatele, se kterym budeme nasledne pracovawt 

    do
    {

        // mame tedy ulozene cislo a nyni s nim muzeme delat dalsi operace, na dalsim vstupu se tedy dotazeme na konkretni operaci 
        printf("Vyberte si z nasledujicich operaci\n +, -, *, /, (s) - sin, (c) - cos, (t) - tan, (o) - odmocnina, (q) - ukonceni programu: ");
        scanf(" %c", &volba);

        //jakmile nacteme typ operace, kterou chce uzivatel provest, program se prepne do menu, podle volby, kde program pokracuje dal.. 
        //pokud by uzivatel nevyuzil ani jednu z uvedenych voleb, program vyhodi chybovou hlasku 

        switch (volba)
        {
        case '+':

            printf("Zadejte druhe cislo: ");
            scanf("%lf", &y);
            vysledek = x + y;
            printf("%lf + %lf = %lf\n", x, y, vysledek);
            x = vysledek;
            return main_menu();
            break;

        case '-':
            printf("Zadejte druhe cislo: ");
            scanf("%lf", &y);
            vysledek = x - y;
            printf("%lf - %lf = %lf\n", x, y, vysledek);
            x = vysledek;
            return main_menu();
            break;

        case '*':
            printf("Zadejte druhe cislo: ");
            scanf("%lf", &y);
            vysledek = x * y;
            printf("%lf * %lf = %lf\n", x, y, vysledek);
            x = vysledek;
            return main_menu();
            break;

        case '/':
            printf("Zadejte druhe cislo: ");
            scanf("%lf", &y);
            vysledek = x / y;
            printf("%lf / %lf = %lf\n", x, y, vysledek);
            x = vysledek;
            return main_menu();
            break;
        case 'c':

            y = 180.0 / PI;
            vysledek = acos(x) * y;
            printf("cosinus %lf je %lf rad.\n", x, vysledek);
            x = vysledek;
            return main_menu();
            break;
        case 's':
            y = 180.0 / PI;
            vysledek = asin(x) * y;
            printf("sinus %lf je %lf rad.\n", x, vysledek);
            x = vysledek;
            return main_menu();
            break;
        case 't':
            y = 180.0 / PI;
            vysledek = atan(x) * y;
            printf("tangens %lf je %lf rad.\n", x, vysledek);
            x = vysledek;
            return main_menu();
            break;
        case 'o':
            vysledek = sqrt(x);
            printf("druha odmocnina %lf je %lf\n", x, vysledek);
            x = vysledek;
            return main_menu();
            break;
        case 'q':
            printf("konec programu, dekuji a tesim se priste :)");
            return main_menu();
            break;
        default:
            printf("spatny vstup, zkus to znovu\n");
        }

    } while (volba != 'q');
    return 0;


}

void soubor()
{

    FILE* file;
    int i;
    char jmeno[32];
    char prijmeni[32];
    int found = 0;
    int pocet_studentu = 0;

    //v teto casti programu nacteme od uzivatele pocet studentu, ktere chce do databaze zapsat 

    printf("Vitej v databazi studentu, kolik si jich prejes zapsat?\n");
    scanf("%d", &pocet_studentu);

    // v teto casti otevreme soubor a pokud by soubor otevrit nesel, vyhodi to chybu 


   
    
    //v teto casti postupne nacitame studenty, respektive text do souboru 

    
    for (i = 0; i < pocet_studentu; ++i)
    {
        
        printf("Student #%d\n", i + 1);
        printf("Jmeno: "); scanf("%s", jmeno);
        printf("Prijmeni:  "); scanf("%s", prijmeni);
        printf("\n");

        file = fopen("databaze.txt", "a");
        if (!file)
        {
            printf("Soubor nejde otevrit :/ \a");
            getchar();
            return -1;
        }


        fprintf(file, "\n%s\t%s\n", jmeno, prijmeni);
        if (fclose(file) == EOF)
        {
            printf("Soubor se nepodaøilo uzavøít.");
            return 1;
        }
        //v  teto casti nactenou cast ulozime do souboru 

        
    }



} 



//dalsi zajimavym odvetvim v programovani je prace s polem, mnohdy velmi mandatorni, v nize uvedenych funkcich si tak vyzkousime zakladni principy
//budeme vytvaret pole, vkladat do pole, mazat a zobrazovat si nejmensi a nejvetsi prvek v poli 




   
void insert() {
   

    int array[100], position, c, n, value;

    //nejprve si tedy pole musime vytvorit, dotazeme se tedy na pocet prvku, ktere pole bude obsahovat 

    printf("Pole musime vytvorit, z kolika cisel se bude skladat? \n");
    scanf("%d", &n);

    //v dalsi casti potrebujeme znat jednotlive prvky pole, ktere uzivatel zada do konzole a oddeli je klavesou enter 

    printf("Tak jo, zadej mi ted postupne vsechna cisla v poli\n", n);
    for (c = 0; c < n; c++)
        scanf("%d", &array[c]);

    //zde prichazi prave zminovama funkce insertu, kdy muzeme vlozit do pole nejaky dalsi prvek
    //nejprve se ovsem musime dotazat, na kterou pozici chceme prvek vlozit

    printf("Zapomnel/a si na nejake cislo? Nevadi, napis mi pozici, kam chces cislo vlozit\n");

    scanf("%d", &position);

    //dale pak musime znat hodnotu, kterou chce uzivatel vlozit

    printf("Jakou hodnotu tam vlozime?\n");
    scanf("%d", &value);

    //tato cast ma na starost posouvani prvku v poli az do pozice n, kterou uzivatel zvolil 
    for (c = n - 1; c >= position - 1; c--)
        array[c + 1] = array[c];

    //v teto casti pak uz jen danou hodnotu prvku vlozime do pole na vybranou pozici 

    array[position - 1] = value;    

    //tady tedy uzivateli vyprintujeme pole na obrazovku, pole bude nyni vyssi o 1 prvek 

    printf("Upravene pole: \n");
    
    for (c = 0; c <= n; c++)
        printf("%d  ", array[c]);

    return prace_s_polem();

}

void mazani() {

    // podobnì jako u insertu i u mazani nejprve musime nacist vstupy od uzivatele 

    int array[100], position, c, n, value;

    // tady tedy nacitame velikost pole, ktere chce uzivatel vytvaret 
    
    printf("Pole musime vytvorit, z kolika cisel se bude skladat? \n");
    scanf("%d", &n);

    //zde postupne nacitame jednotlive hodnoty pole 

    printf("Tak jo, zadej mi ted postupne vsechna cisla v poli\n", n);
    for (c = 0; c < n; c++)
        scanf("%d", &array[c]);

    //zde nasimulujeme mazani v poli, dotazeme se tedy uzivatele na index prvku, ktery chce smazat

    printf("Chces nejake cislo v poli smazat? Napis mi pozici, kam chces cislo vlozit\n");
    scanf("%d", &position);

    //pokud udana pozice neexistuje, zaloguje chybu 

    if (position >= n + 1) {
        printf("Tady to mazani nepujde :( \n");
    }

    // pokud udana pozice existuje, pokracuje ve zmene prvku na zadanem indexu 
    else {
        
        for (c = position - 1; c < n - 1; c++)
            array[c] = array[c + 1];
    }

    // nakonec for cyklem vyprintuje upravene pole 

    printf("Upravene pole : \n");
   
    for (c = 0; c < n - 1; c++)
        printf("%d  ", array[c]);

    return prace_s_polem();

}

void nejmensi_nejvetsi()
{

    //v posledni oblasti prace s polem jsem zaradila naleznuti nejmensi a nejvetsiho prvku v poli 

    int a[50], size, i, big, nejmensi;

    //od uzivatele tedy stejnym zpusobem nacteme velikost pole 

    printf("Pole musime vytvorit, z kolika cisel se bude skladat? \n");
    scanf("%d", &size);

    //dale pak nechame uzivatele zadat vsechny prvky pole 

    printf("Tak jo, zadej mi ted postupne vsechna cisla v poli\n", size);
    for (i = 0; i < size; i++)
        scanf("%d", &a[i]);

    // od druheho prvku po posleni hledame ten nejvetsi a pokud existuje, ulozi si novou hodnotu 

    big = a[0]; 
   
    for (i = 1; i < size; i++)
    {
        if (big < a[i])   // pokud najde vetsi prvek 
        {
            big = a[i]; // ulozi si do promenne nalezeny prvek 
        }
    }

      //nalezeny prvek vyprintuje do konzole 

    printf("Nejvetsi prvek je %d\n", big);
   

    //podobnym zpusobem pote pokracuje pri hledani nejmensiho prvku 


    nejmensi = a[0];   
    
    // od druheho prvku po posleni hledame ten nejmensi a pokud existuje, ulozi si novou hodnotu 

    for (i = 1; i < size; i++)
    {
        if (nejmensi > a[i])   // pokud najde mensi prvek 
        {
            nejmensi = a[i];   // ulozi si do promenne nalezeny prvek
        }
    }

    //nalezeny prvek vyprintuje do konzole 

    printf("Nejmensi prvek je %d\n", nejmensi);

    return prace_s_polem();
}

void celsius()
{
    //tato funkce velmi jednoduse prevadi udana celsia na stupnici fahrenheit
    //od uzivatele nacte stupne v Celsia, vynasobi konstatntim cislem 1,8 a k vysledku pricte 32

    float celsius, fahrenheit;
    printf("Zadej stupne v Celsius: \n");
    scanf("%f", &celsius);

    fahrenheit = (1.8 * celsius) + 32;

    printf("Teploota ve stupnici Fahrenheit je %f ", fahrenheit);


}



int prace_s_polem() 
{

    //specialni vlastni switch menu pro praci s polem, jakmile uzivatel vybere, co chce s polem delat, menu se switchne na danou hodnotu a pote na funkci 
    
    int volba;
   
  
        
        printf("\n===========================\n");
        printf("Co s polem budeme tvorit? \n");

        printf("(1). Insert\n");

        printf("(2). Mazani\n");

        printf("(3). Nejmensi a nejvetsi prvek pole\n");


        printf("(0). Konec\n");
        printf("===========================\n\n");


        scanf("%d", &volba);



       

            switch (volba) {

            case 1:
                insert();              
                
                break;

            case 2:
                mazani();
                
                break;

            case  3:               
                nejmensi_nejvetsi();
                
                break;

            case 0:
                return main_menu();
                break;

            }

            // pokud by zvolil 0, aplikace se vypne 

       
}



void kouzlo() 
{

    //tato funkce je spise doplnkem a na velmi jednoduchem principu vypoctu dokaze uzivateli "odhalit" co si mysli za cislo 

    printf("Mysli si nejake cislo....\n"); 
    
    //funguje to jednodusse, pokud si uzivatel mysli napr. cislo 3

    printf("Pricti ke svemu cislu 5\n");

    // 3 + 5 = 8 

    printf("Pricti ke svemu cislu 12\n");

    // 8 + 12 = 20 

    printf("Pricti ke svemu cislu 2\n");

    // 20 + 2 = 22 

    printf("Odecti od sveho cisla 4\n");

    // 22 - 4 = 18 

    printf("Vyslo ti nejake cislo? Dobre, odecti od nej 15 a vyslo ti tve cislo, ktere sis myslel/a :)");

    // 18 - 15 = 3 = cislo, ktere si uzivatel myslel 

 }


//do sve prace jsem tatkez zaradila velmi jednoduchou hru na naprogramovani a to piskvorky na principu matic


//nejprve tedy inicializujeme velikost matice 3x3, coz bude nase herni pole 
char matrix[3][3];  


//funkce na kontrolu viteze 
char check(void);

//funkce na inicializaci matice 
void init_matrix(void);

//funkce na nacitani, kam uzivatel umisti svoji volbu 
void get_player_move(void);

// funkce na nacitani, kam pc vlozi svoji volbu
void get_computer_move(void);

//funkce na vyprintovani matice na obrazovku 
void disp_matrix(void);



   
    void init_matrix(void)
    {
        int i, j;

        for (i = 0; i < 3; i++)
            for (j = 0; j < 3; j++) matrix[i][j] = ' ';
    }

   
    void get_player_move(void)
    {
        int x, y;

        printf("Budes mit znamenko(X), nyni vloz pozici, kam chces svoje X vlozit, napr. pozice 1,1:\n ");
        scanf("%d%*c%d", &x, &y);

        x--; y--;


        //pokud by se uzivatel pokusil vlozit svoje X na pozici, kde uz se nejake X nebo O nachazi, vyprintuje chybu a ceka na spravny vstup 

        if (matrix[x][y] != ' ') {
            printf("Spatny vstup, zkus to znovu.\n");
            get_player_move();
        }
        else matrix[x][y] = 'X';
    }

   
    void get_computer_move(void)
    {
        int i, j;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++)
                if (matrix[i][j] == ' ') break;
            if (matrix[i][j] == ' ') break;
        }

        //pokud by vsechna pole byla zaplnena a stejne by ani jeden (pc nebo uzivatel) nemeli tri hodnoty ve stejnem radku nebo sloupci, vyprintuje remizu 

        if (i * j == 9) {
            printf("Remiza\n");
            exit(0);
        }
        else
            matrix[i][j] = 'O';
    }


    void disp_matrix(void)
    {
        int t;

        for (t = 0; t < 3; t++) {
            printf(" %c | %c | %c ", matrix[t][0],
                matrix[t][1], matrix[t][2]);
            if (t != 2) printf("\n---|---|---\n");
        }
        printf("\n");
    }

    
    //funkce na kontrolu viteze hry 

    char check(void)
    {
        int i;

        //v teto casti kontrole radky 

        for (i = 0; i < 3; i++) 
            if (matrix[i][0] == matrix[i][1] &&
                matrix[i][0] == matrix[i][2]) return matrix[i][0];

        //v teto casti kontroluje sloupce 

        for (i = 0; i < 3; i++)  
            if (matrix[0][i] == matrix[1][i] &&
                matrix[0][i] == matrix[2][i]) return matrix[0][i];

        
        //v teto casti jeste zkontroluje i diagonaly 

        if (matrix[0][0] == matrix[1][1] &&
            matrix[1][1] == matrix[2][2])
            return matrix[0][0];

        if (matrix[0][2] == matrix[1][1] &&
            matrix[1][1] == matrix[2][0])
            return matrix[0][2];

        return ' ';

    }


    void piskvorky()
    {

        char done;

        printf("Práve sis zapnul/a piskorky, budes hrat proti chytremu PC.\n");


        done = ' ';
        init_matrix();

        do {
            disp_matrix();
            get_player_move();

            //zkontroluje viteze 

            done = check(); 
            if (done != ' ') break; 


            get_computer_move();
            done = check(); 


        } while (done == ' ');

        if (done == 'X') printf("Jsi viteeeez\n");

        else printf("Porazil te pocitac :/, jsi druhy....\n");


        disp_matrix(); 

     


   }

    struct bin_tree
    {
        int data;
        struct bin_tree* right, * left;
    };

    typedef struct bin_tree node;

    void insert_strom(node** tree, int val)

        // tato funkce ma za ukol ulozit do stromu jednotlive polohy uzlu (nodu) a nove uzly (nody) pridavat 


    {
        node* temp = NULL;
        if (!(*tree))
        {
            temp = (node*)malloc(sizeof(node));
            temp->left = temp->right = NULL;
            temp->data = val;
            *tree = temp;
            return;
        }

        //funkce vyse kontrluje jestli je strom prazdny a pokud ano, ulozi node jako root( koren) 


        if (val < (*tree)->data)
            //tato podminka kontroluje, ze hodnota, kterou vkladame, je mensi nez hodnota rootu (korenu)

        {
            insert_strom(&(*tree)->left, val);
        }

        else if (val > (*tree)->data) 
            //pokud je to opacne, prehodi poradi, aby byla zachovana spravna velikost a poradi ulozenych v pameti jako root (node)

        {
            insert_strom(&(*tree)->right, val);
        }

    }

    void print_preorder(node* tree)
    {



        if (tree)
        {
            printf("%d\n", tree->data);

            //tato cast vyprintuje root (koren) node 

            print_preorder(tree->left);

            print_preorder(tree->right);

        }

    }

    void print_inorder(node* tree)
    {
        if (tree)
        {
            print_inorder(tree->left);

            printf("%d\n", tree->data);

            //tato cast vyprintuje root (koren) node

            print_inorder(tree->right);

        }
    }

    void print_postorder(node* tree)
    {
        if (tree)
        {
            print_postorder(tree->left);

            print_postorder(tree->right);

            printf("%d\n", tree->data);

            //tato cast vyprintuje root (koren) node 
        }
    }

    void deltree(node* tree)

        //tato funkce po vyprintovani na obrazovku maze vsechny nody stromu a to tak, ze leva strana, prava strana a root (koren)

    {
        if (tree)
        {
            deltree(tree->left);
            deltree(tree->right);
            free(tree);
        }
    }

   


    void strom() 
    {

        node* root;
        node* tmp;
        

        root = NULL;
       


        insert_strom(&root, 55);
        insert_strom(&root, 16);
        insert_strom(&root, 2);
        insert_strom(&root, 8);
        insert_strom(&root, 99);
        insert_strom(&root, 4);
        insert_strom(&root, 11);

 
    
        printf("Puvodni strom\n");
        print_preorder(root);

        printf("Zesortovany strom formou NLR \n");
        print_inorder(root);

        printf("Presortovany strom  formou LRN\n");
        print_postorder(root);


     

        //smazani vsech nodu - vycisteni stromu 

        deltree(root);
   
    }


    



    main_menu()
    {
        int menu;
        
        do
        {

            printf("\n===========================\n");
            printf("Vyber si z menu cokoliv te napadne\n");

            printf("(1). Chci napsat basen a ulozi to do souboru :O \n");

            printf("(2). Rad bych vyuzil/a sluzby kalkulacky\n");

            printf("(3). Prace s polem\n");

            printf("(4). Prevod Celsius na Fahrenheit\n");

            printf("(5). Kouzlo....\n");

            printf("(6). Piskvorky\n");

            printf("(7). DFS strom\n");
           
            printf("(8). BONUS: chci vedet, kolik je mi let\n");

            printf("(9). Zmena barvy pozadi\n");
                    
            printf("(0). Konec\n");
            printf("===========================\n\n");


            scanf("%d", &menu);




            switch (menu) {

            case 1:

                soubor();
                break;

            case 2:

                kalkulacka();
                break;

            case 3:

                prace_s_polem();
                break;

            case 4:

                celsius();
                break;

            case 5:

                kouzlo();
                break;

            case 6:

                piskvorky();
                break;

            case 7:
                strom();
                break;

            case 8:

                vypocet_stari();
                break;
            case 9:
                zmena_barvy();
                break;
            case 0:
                exit(EXIT_SUCCESS);
                break;

            }


        } while (menu != 0);



}

    //velmi jednoduche menu na zmenu barvy textu, uzivatel muze vybrat ze zakladnich barev 1 - 9

    int zmena_barvy()
    {
        int zmena_barvy_volba = 0;

        printf("Vyber si jakou barvu chces:\n");
        printf("1 = cerna\n");
        printf("2 = zelena\n");
        printf("3 = modra\n");
        printf("4 = cervena\n");
        printf("5 = fialova\n");
        printf("6 = zluta\n");
        printf("7 = bila\n");
        printf("8 = seda\n");
        printf("9 = svetle modra\n");
        printf("0 = zpet\n");

        scanf("%d", &zmena_barvy_volba);

       


        switch (zmena_barvy_volba)
        {

        case 1:
            system("color 1");
            return main_menu();

        case 2:
            system("color 2");
            return main_menu();

        case 3:
            system("color 3");
            return main_menu();

        case 4:
            system("color 4");
            return main_menu();

        case 5:
            system("color 5");
            return main_menu();

        case 6:
            system("color 6");
            return main_menu();

        case 7:
            system("color 7");
            return main_menu();

        case 8:
            system("color 8");
            return main_menu();

        case 9:
            system("color 9");
            return main_menu();

        case 0:
           
            return main_menu();
        }


   }


int main(void)
{



    time_t t = time(NULL);
    struct tm tm = *localtime(&t);


    char name[MAX];



    printf("Ahoj, jmenuji se ERTA, jsem multifunkcni konzole a umim spoustu veci, jak se jmenujes ty? \n");

    fgets(name, MAX, stdin);
    printf("Tak to te rada poznavam % s", name);

    printf("Aktualni datum a cas: %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);

   

    main_menu();
}




