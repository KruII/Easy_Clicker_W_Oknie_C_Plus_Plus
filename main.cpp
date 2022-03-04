#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
//Program jest prosta gra dziala tak jak widac
#define PLIK_MENU_ZAPISU_1 1
#define PLIK_MENU_ZAPISU_2 2
#define PLIK_MENU_ZAPISU_3 3
#define PLIK_MENU_WYJSCIE 4
#define PLIK_MENU_INFORMACJE 5
#define PLIK_MENU_WCZYTYWANIA_1 6
#define PLIK_MENU_WCZYTYWANIA_2 7
#define PLIK_MENU_WCZYTYWANIA_3 8
#define OKNO 9
#define ZAKUP1 10
#define ZAKUP2 11

LRESULT CALLBACK ProceduraOkna(HWND,UINT,WPARAM,LPARAM);

void menu(HWND);
void control(HWND);

HWND hgold;
HWND cenamin;
HWND cenamax;
HMENU hMenu;
int goldil=0,minimum=0,maksimum=100,ilmin=1,ilmax=1;
int WINAPI WinMain(HINSTANCE HNormalInst, HINSTANCE HPoprzedniInst, LPSTR args, int pokazywaniecmd)
{
    WNDCLASSW ko={0};
    ko.hbrBackground = (HBRUSH)COLOR_WINDOW;
    ko.hCursor = LoadCursor(NULL,IDC_ARROW);
    ko.hInstance = HNormalInst;
    ko.lpszClassName = L"PracaNaInformatyke";
    ko.lpfnWndProc = ProceduraOkna;
    if (!RegisterClassW(&ko)){return -1;}
    CreateWindowW(L"PracaNaInformatyke",L"Gra",WS_OVERLAPPEDWINDOW | WS_VISIBLE,200,100,1600,900,NULL,NULL,NULL,NULL);
    MSG wiadomosc = {0};
    while (GetMessage(&wiadomosc,NULL,NULL,NULL))
    {
        TranslateMessage(&wiadomosc);
        DispatchMessage(&wiadomosc);
    }
    
    return 0;
}
LRESULT CALLBACK ProceduraOkna(HWND hOkno,UINT wiadomosc,WPARAM wp,LPARAM lp)
{
    LPSTR Bufor;
    DWORD dwRozmiar, dwZapisane, dwPrzeczyt;
    HANDLE hPlik;
    int odp;
        switch (wiadomosc)
        {
            case WM_KEYDOWN:
            {
                switch(wp)
            {
            case VK_ESCAPE:
                DestroyWindow( hOkno );
                break;
                }
            }
                break;
            case WM_COMMAND:
            switch (wp)
            {
            case PLIK_MENU_ZAPISU_1:
                odp = MessageBoxW(hOkno,L"Jestes pewien? Spowoduje to nadpisanie zapisu.",L"Zapis 1",MB_YESNO | MB_ICONEXCLAMATION);
                if(odp==IDYES){
                    hPlik = CreateFile( "save1.save", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 0, NULL );
                    if( hPlik == INVALID_HANDLE_VALUE ) {
                    MessageBox( NULL, "Nie mozna otworzyć pliku.", "A to pech!", MB_ICONEXCLAMATION );
                    PostQuitMessage( 0 );}
                    char goldpo[100];
                    itoa (goldil,goldpo,10);
                    WriteFile(hPlik, goldpo, dwRozmiar,&dwZapisane,NULL);
                    CloseHandle( hPlik );
                    MessageBox(NULL,"Zapisano pomyslnie","Zapis",MB_OK);
                }
                break;
            case PLIK_MENU_ZAPISU_2:
                MessageBoxW(hOkno,L"Jestes pewien? Spowoduje to nadpisanie zapisu.",L"Zapis 2",MB_YESNO | MB_ICONEXCLAMATION);
                if(odp==IDYES){
                    hPlik = CreateFile( "save2.save", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 0, NULL );
                    if( hPlik == INVALID_HANDLE_VALUE ) {
                    MessageBox( NULL, "Nie mozna otworzyć pliku.", "A to pech!", MB_ICONEXCLAMATION );
                    PostQuitMessage( 0 );}
                    char goldpo[100];
                    itoa (goldil,goldpo,10);
                    WriteFile(hPlik, goldpo, dwRozmiar,&dwZapisane,NULL);
                    CloseHandle( hPlik );
                    MessageBox(NULL,"Zapisano pomyslnie","Zapis",MB_OK);
                }
                break;
            case PLIK_MENU_ZAPISU_3:
                MessageBoxW(hOkno,L"Jestes pewien? Spowoduje to nadpisanie zapisu.",L"Zapis 3",MB_YESNO | MB_ICONEXCLAMATION);
                if(odp==IDYES){
                    hPlik = CreateFile( "save3.save", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 0, NULL );
                    if( hPlik == INVALID_HANDLE_VALUE ) {
                    MessageBox( NULL, "Nie mozna otworzyć pliku.", "A to pech!", MB_ICONEXCLAMATION );
                    PostQuitMessage( 0 );}
                    char goldpo[100];
                    itoa (goldil,goldpo,10);
                    WriteFile(hPlik, goldpo, dwRozmiar,&dwZapisane,NULL);
                    CloseHandle( hPlik );
                    MessageBox(NULL,"Zapisano pomyslnie","Zapis",MB_OK);
                }
                break;
            case PLIK_MENU_WYJSCIE:
                DestroyWindow(hOkno);
                break;
            case PLIK_MENU_INFORMACJE:
                MessageBox(NULL,"Wersja v.BETA.0.1\nTworca: Kacper Dobrowolski","Informacje",MB_OK);
                break;
            case PLIK_MENU_WCZYTYWANIA_1:
                MessageBoxW(hOkno,L"Jestes pewien? Spowoduje to utrate niezapisanego postepu.",L"Zapis 1",MB_YESNO | MB_ICONEXCLAMATION);
                if(odp==IDYES){
                    hPlik = CreateFile( "save1.save", GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL );
                    if( hPlik == INVALID_HANDLE_VALUE ) {
                    MessageBox( NULL, "Brak pliku.", "ERROR 404", MB_ICONEXCLAMATION );
                    PostQuitMessage( 0 );}
                    char goldpo[100];
                    ReadFile( hPlik, goldpo, dwRozmiar, & dwPrzeczyt, NULL );
                    goldil=atoi(goldpo);
                    CloseHandle( hPlik );
                    MessageBox(NULL,"Wczytano pomyslnie","Zapis",MB_OK);
                }
                break;
            case PLIK_MENU_WCZYTYWANIA_2:
                MessageBoxW(hOkno,L"Jestes pewien? Spowoduje to utrate niezapisanego postepu.",L"Zapis 2",MB_YESNO | MB_ICONEXCLAMATION);
                if(odp==IDYES){
                    hPlik = CreateFile( "save2.save", GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL );
                    if( hPlik == INVALID_HANDLE_VALUE ) {
                    MessageBox( NULL, "Brak pliku.", "ERROR 404", MB_ICONEXCLAMATION );
                    PostQuitMessage( 0 );}
                    char goldpo[100];
                    ReadFile( hPlik, goldpo, dwRozmiar, & dwPrzeczyt, NULL );
                    goldil=atoi(goldpo);
                    CloseHandle( hPlik );
                    MessageBox(NULL,"Wczytano pomyslnie","Zapis",MB_OK);
                }
                break;
            case PLIK_MENU_WCZYTYWANIA_3:
                MessageBoxW(hOkno,L"Jestes pewien? Spowoduje to utrate niezapisanego postepu.",L"Zapis 3",MB_YESNO | MB_ICONEXCLAMATION);
                if(odp==IDYES){
                    hPlik = CreateFile( "save3.save", GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL );
                    if( hPlik == INVALID_HANDLE_VALUE ) {
                    MessageBox( NULL, "Brak pliku.", "ERROR 404", MB_ICONEXCLAMATION );
                    PostQuitMessage( 0 );}
                    char goldpo[100];
                    ReadFile( hPlik, goldpo, dwRozmiar, & dwPrzeczyt, NULL );
                    goldil=atoi(goldpo);
                    CloseHandle( hPlik );
                    MessageBox(NULL,"Wczytano pomyslnie","Zapis",MB_OK);
                }
                break;
            case OKNO:
                char gold[100];
                goldil+=minimum+rand()%maksimum;
                char goldpo[100];
                itoa (goldil,goldpo,10);
                strcpy(gold,goldpo);
                strcat(gold," Gold");
                SetWindowText(hgold,gold);
                break;
            case ZAKUP1:
                if (goldil>=150*ilmin)
                {
                    char gold[100];
                    goldil-=150*ilmin;
                    ilmin++;
                    char goldpo[100];
                    itoa (goldil,goldpo,10);
                    strcpy(gold,goldpo);
                    strcat(gold," Gold");
                    SetWindowText(hgold,gold);
                    itoa (150*ilmin,goldpo,10);
                    strcpy(gold,goldpo);
                    strcat(gold," Gold");
                    SetWindowText(cenamin,gold);
                    minimum+=25;
                }
                else{
                    MessageBox(NULL,"Nie stac Cie","",MB_OK);
                }
                break;
            case ZAKUP2:
                if (goldil>=100*ilmax)
                {
                    char gold[100];
                    goldil-=100*ilmax;
                    ilmax++;
                    char goldpo[100];
                    itoa (goldil,goldpo,10);
                    strcpy(gold,goldpo);
                    strcat(gold," Gold");
                    SetWindowText(hgold,gold);
                    itoa (100*ilmax,goldpo,10);
                    strcpy(gold,goldpo);
                    strcat(gold," Gold");
                    SetWindowText(cenamax,gold);
                    maksimum+=50;
                }
                else{
                    MessageBox(NULL,"Nie stac Cie","",MB_OK);
                }
                
                break;
            }
            break;
        case WM_CREATE:
            menu(hOkno);
            control(hOkno);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProcW(hOkno,wiadomosc,wp,lp);
        }
}

void menu(HWND hOkno)
{
    srand(time(0));
    hMenu = CreateMenu();
    HMENU hPlikiMenu = CreateMenu();
    HMENU hZapisyMenu = CreateMenu();
    HMENU hZapisyMenuW = CreateMenu();

    AppendMenu(hZapisyMenu,MF_STRING,PLIK_MENU_ZAPISU_1,"Zapis 1");
    AppendMenu(hZapisyMenu,MF_STRING,PLIK_MENU_ZAPISU_2,"Zapis 2");
    AppendMenu(hZapisyMenu,MF_STRING,PLIK_MENU_ZAPISU_3,"Zapis 3");

    AppendMenu(hZapisyMenuW,MF_STRING,PLIK_MENU_WCZYTYWANIA_1,"Zapis 1");
    AppendMenu(hZapisyMenuW,MF_STRING,PLIK_MENU_WCZYTYWANIA_2,"Zapis 2");
    AppendMenu(hZapisyMenuW,MF_STRING,PLIK_MENU_WCZYTYWANIA_3,"Zapis 3");

    AppendMenu(hPlikiMenu,MF_POPUP,(UINT_PTR)hZapisyMenu,"Nowy Zapis");
    AppendMenu(hPlikiMenu,MF_POPUP,(UINT_PTR)hZapisyMenuW,"Wczytaj Zapis");
    AppendMenu(hPlikiMenu,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hPlikiMenu,MF_STRING,PLIK_MENU_INFORMACJE,"Informacje");
    AppendMenu(hPlikiMenu,MF_SEPARATOR,NULL,NULL);
    AppendMenu(hPlikiMenu,MF_STRING,PLIK_MENU_WYJSCIE,"Wyjdz");
    
    AppendMenu(hMenu,MF_POPUP,(UINT_PTR)hPlikiMenu,"Opcje");

    SetMenu(hOkno,hMenu);
}
void control(HWND hOkno){
    CreateWindowW(L"static",L"Prosta Gra O Klikaniu",WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER,0,0,1600,50,hOkno,NULL,NULL,NULL );
    CreateWindowW(L"Button",L"Kop zloto",WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER,200,100,100,50,hOkno,(HMENU)OKNO,NULL,NULL );
    cenamax = CreateWindowW(L"Button",L"100 Gold",WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER,600,100,100,50,hOkno,(HMENU)ZAKUP2,NULL,NULL );
    cenamin = CreateWindowW(L"Button",L"150 Gold ",WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER,600,150,100,50,hOkno,(HMENU)ZAKUP1,NULL,NULL );
    CreateWindowW(L"static",L"Ulepsz maksymalne zloto:",WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER,500,100,100,50,hOkno,NULL,NULL,NULL );
    CreateWindowW(L"static",L"Ulepsz minimalne zloto:",WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER,500,150,100,50,hOkno,NULL,NULL,NULL );
    hgold = CreateWindowW(L"static",L"0",WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER,200,300,100,50,hOkno,NULL,NULL,NULL );
}
