//Jakub Kozub
#include <iostream>
using namespace std;

long long Wyznacznik (long long macierz[][32], int rozmiar) {
    long long det;
    //int znak;
    int tmp;
    int rowne;
    int i;
    int j;
    int k;
    long long macierzSkr[32][32];
    /*if (rozmiar == 1)
        det = macierz[0][0];*/
    if (rozmiar == 2) {
        det = (((macierz[0][0])*(macierz[1][1])) - ((macierz[0][1])*(macierz[1][0])));
    }
    else if (rozmiar == 3) {
        det = (((macierz[0][0])*(macierz[1][1])*(macierz[2][2])) + ((macierz[0][1])*(macierz[1][2])*(macierz[2][0])) + ((macierz[0][2])*(macierz[1][0])*(macierz[2][1])) - ((macierz[2][0])*(macierz[1][1])*(macierz[0][2])) - ((macierz[2][1])*(macierz[1][2])*(macierz[0][0])) - ((macierz[2][2])*(macierz[1][0])*(macierz[0][1])));
    }
    else {
        det = 0;
        //sprawdzenie czy w macierzy wystepuja identyczne wiersze lub kolumny:
        rowne = 0;
        i = 0;
        while (i < rozmiar) {
            j = 0;
            while (j < rozmiar) {
                if ((macierz[0][i] == macierz[0][j])&&(i != j)) {
                    k = 1;
                    rowne = 1;
                    while ((k < rozmiar)&&(rowne == 1)) {
                        if ((macierz[k][i] != macierz[k][j])) {
                            rowne = 0;
                        }
                        k++;
                    }
                }
                j++;
            }
            i++;
        }
        i = 0;
        while (i < rozmiar) {
            j = 0;
            while (j < rozmiar) {
                if ((macierz[i][0] == macierz[j][0])&&(i != j)) {
                    k = 1;
                    rowne = 1;
                    while ((k < rozmiar)&&(rowne == 1)) {
                        if ((macierz[i][k] != macierz[j][k])) {
                            rowne = 0;
                        }
                        k++;
                    }
                }
                j++;
            }
            i++;
        }
        if (rowne == 1)
            det = 0;
        else {
            // rozwiniecie LaPlace'a wzgl 0-wego wiersza:
            i = 0;
            while (i < rozmiar) {
                if (macierz[0][i] != 0) {
                    tmp = macierz[0][i];
                    j = 0;
                    while (j < rozmiar-1) { // skreslenie 0-wego wiersza i i-tej kolumny
                        k = 0;
                        while (k < rozmiar-1) {
                            if (k < i) {
                                macierzSkr[j][k] = macierz[j+1][k];
                            }
                            else {
                                macierzSkr[j][k] = macierz[j+1][k+1];
                            }
                            k++;
                        }
                        j++;
                    }
                    if ((i+2)%2 == 0) { // parzysty wykladnik czyli znak dodatni
                        det += tmp*Wyznacznik(macierzSkr, rozmiar-1);
                    }
                    else { // nieparzysty wykladnik czyli znak ujemny
                        det -= tmp*Wyznacznik(macierzSkr, rozmiar-1);
                    }
                }
                i++;
            }
        }
    }
    return det;
}
//---------------------------------------------------------------------------------------------
long Prostopadloscian (int Dane[][32][32], int rozm, int wierzchL, int wierzchV, int wierzchP, int wys, int szer, int gleb) {
    long suma;
    int h;
    int w;
    int d;
    int zwrotH;
    int zwrotW;
    int zwrotD;
    int srodek;
    zwrotH = 1;
    zwrotW = 1;
    zwrotD = 1;
    srodek = rozm/2;
    suma = 0;
    if ((wys == 0)&&(szer == 0)&&(gleb == 0)) {
        if ((wierzchL >= 0)&&(wierzchV >= 0)&&(wierzchP >= 0)&&(wierzchL <= rozm)&&(wierzchV <= rozm)&&(wierzchP <= rozm))
        suma = Dane[wierzchL][wierzchV][wierzchP];
    }
    else {
        if (wierzchL > srodek) {
            zwrotH = -1;
        }
        if (wierzchV > srodek) {
            zwrotW = -1;
        }
        if (wierzchP > srodek) {
            zwrotD = -1;
        }
        d = wierzchP;
        while ((zwrotD*(d - wierzchP)) <= gleb) {
            h = wierzchL;
            while ((zwrotH*(h - wierzchL)) <= wys) {
                w = wierzchV;
                while ((zwrotW*(w - wierzchV)) <= szer) {
                    if ((d >= 0)&&(d <= rozm)&&(h >= 0)&&(h <= rozm)&&(w >= 0)&&(w <= rozm))
                        suma += Dane[h][w][d];
                    w += zwrotW;
                }
                h += zwrotH;
            }
            d += zwrotD;
        }

    }
    return suma;
}
//---------------------------------------------------------------------
long Czworoscian (int Dane[][32][32], int rozm, int wierzchL, int wierzchV, int wierzchP, int krawedz) {
    long suma;
    int h;
    int w;
    int d;
    int zwrotH;
    int zwrotW;
    int zwrotD;
    int srodek;
    zwrotH = 1;
    zwrotW = 1;
    zwrotD = 1;
    srodek = rozm/2;
    suma = 0;
    if (krawedz == 0) {
        if ((wierzchL >= 0)&&(wierzchV >= 0)&&(wierzchP >= 0)&&(wierzchL <= rozm)&&(wierzchV <= rozm)&&(wierzchP <= rozm))
            suma = Dane[wierzchL][wierzchV][wierzchP];
    }
    else {
        if (wierzchL > srodek) {
            zwrotH = -1;
        }
        if (wierzchV > srodek) {
            zwrotW = -1;
        }
        if (wierzchP > srodek) {
            zwrotD = -1;
        }
        d = wierzchP;
        while ((zwrotD*(d - wierzchP)) <= krawedz) {
            h = wierzchL;
            while ((zwrotH*(h - wierzchL)) <= krawedz) {
                w = wierzchV;
                while ((zwrotW*(w - wierzchV)) <= krawedz) {
                    if ((d >= 0)&&(d <= rozm)&&(h >= 0)&&(h <= rozm)&&(w >= 0)&&(w <= rozm)&&(((zwrotH*(h - wierzchL)) + (zwrotW*(w - wierzchV)) + (zwrotD*(d - wierzchP))) <= krawedz))
                        suma += Dane[h][w][d];
                    w += zwrotW;
                }
                h += zwrotH;
            }
            d += zwrotD;
        }

    }
    return suma;
}
//----------------------------------------------------------------------
long Oktal (int Dane[][32][32], int rozm, int srodekL, int srodekV, int srodekP, int promien) {
    long suma;
    int h;
    int w;
    int d;
    int zwrotH;
    int zwrotW;
    int zwrotD;
    int srodekSzescianu;
    zwrotH = 1;
    zwrotW = 1;
    zwrotD = 1;
    srodekSzescianu = rozm/2;
    suma = 0;
    if (promien == 0) {
        if ((srodekL >= 0)&&(srodekV >= 0)&&(srodekP >= 0)&&(srodekL <= rozm)&&(srodekV <= rozm)&&(srodekP <= rozm))
        suma = Dane[srodekL][srodekV][srodekP];
    }
    else {
        if (srodekL > srodekSzescianu) {
            zwrotH = -1;
        }
        if (srodekV > srodekSzescianu) {
            zwrotW = -1;
        }
        if (srodekP > srodekSzescianu) {
            zwrotD = -1;
        }
        d = srodekP;
        while ((zwrotD*(d - srodekP)) <= promien) {
            h = srodekL;
            while ((zwrotH*(h - srodekL)) <= promien) {
                w = srodekV;
                while ((zwrotW*(w - srodekV)) <= promien) {
                    if ((h >= 0)&&(h <= rozm)&&(w >= 0)&&(w <= rozm)&&(d >= 0)&&(d <= rozm)&&((h - srodekL)*(h - srodekL) + (w - srodekV)*(w - srodekV) + (d - srodekP)*(d - srodekP) <= promien*promien))
                        suma += Dane[h][w][d];
                    w += zwrotW;
                }
                h += zwrotH;
            }
            d += zwrotD;
        }
    }
    return suma;
}
//----------------------------------------------------------------------

int main()
{
    int a; //dlugosc krawedzi szescianu - liczba parzysta od 2 do 32
    int h;
    int w;
    int d;
    int l; // wspolrzedna poziomu wierzcholka/srodka
    int v; // wspolrzedna pionu wierzcholka/srodka
    int p; // wspolrzedna panelu wierzcholka/srodka
    int hp; // wysokosc prostopadloscianu
    int wp; // szerokosc prostopadloscianu
    int dp; // glebokosc prostopadloscianu
    int e; // dlugosc krawedzi prostopadlych czworoscianu
    int r; // dlugosc promienia oktala
    int i;
    int j;
    int k;
    char operacja; // okreslenie rodzaju operacji
    char id; // identyfikator okreslajacy orientacje macierzy (poziom/pion/panel)
    int n; // indeks okreslajacy numer poziomu/pionu/panelu, ktorego wyznacznik ma byc obliczony

    cin >> a;
    int Szescian[32][32][32]; // szescian danych

    d = 0;
    while (d < a) {
        h = 0;
        while (h < a) {
            w = 0;
            while (w < a) {
                cin >> Szescian[h][w][d]; // [l/h - poziom][v/w - pion][p/d - panel]
                w++;
            }
            h++;
        }
        d++;
    }
    //cin << operacja;
    operacja = 'A';
    while (operacja != 'E') {
        cin >> operacja;
        if (operacja == 'C') { //przeciecie prostopadloscianu z szescianem
            cin >> l >> v >> p >> hp >> wp >> dp;
            cout << Prostopadloscian(Szescian, a, l, v, p, hp, wp, dp) << endl;
        }
        else if (operacja == 'T') { //przeciecie czworoscianu z szescianem
            cin >> l >> v >> p >> e;
            cout << Czworoscian(Szescian, a, l, v, p, e) << endl;
        }
        else if (operacja == 'O') { //przeciecie oktala z szescianem
            cin >> l >> v >> p >> r;
            cout << Oktal(Szescian, a, l, v, p, r) << endl;
        }
        else if (operacja == 'D') { //wyznacznik n-tego poziomu/pionu/panelu
            long long Macierz[32][32];
            cin >> id >> n;
            if (id == 'p') { // wyznacznik panelu o indeksie n
                i = 0;
                while (i < a) {
                    j = 0;
                    while (j < a) {
                        Macierz[i][j] = Szescian[i][j][n];
                        j++;
                    }
                    i++;
                }
            }
            else if (id == 'l') { // wyznacznik poziomu o indeksie n
                i = 0;
                while (i < a) {
                    j = 0;
                    while (j < a) {
                        Macierz[i][j] = Szescian[n][i][j];
                        j++;
                    }
                    i++;
                }
            }
            else if (id == 'v') { // wyznacznik pionu o indeksie n
                i = 0;
                while (i < a) {
                    j = 0;
                    while (j < a) {
                        Macierz[i][j] = Szescian[i][n][j];
                        j++;
                    }
                    i++;
                }
            }
            cout << Wyznacznik(Macierz, a) << endl;
        }
    }
/*
    i = 0;
    while (i < a) {
        j = 0;
        while (j < a) {
            k = 0;
            while (k < a) {
                cout << cube[i][j][k] << "\n";
                k++;
            }
            j++;
        }
        i++;
    }
*/
    return 0;
}
