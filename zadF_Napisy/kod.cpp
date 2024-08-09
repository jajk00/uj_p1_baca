//Jakub Kozub
#include <string>
using namespace std;

string NajwiekszeSlowo(string napis) {
    string najw;
    string slowo;
    int pocz;
    int rozm;
    int dlugosc;
    int i;
    int j;
    rozm = napis.size();
    najw = napis;
    pocz = 0;
    i = 0;
    while (i < rozm) {
        if ((napis[i+1] == ' ')||(i + 1 == rozm)) {
            if (pocz == 0) {
                najw.resize(i+1);
            }
            else {
                dlugosc = i + 1 - pocz;
                slowo.resize(dlugosc);
                for (int j = 0; j < dlugosc; j++) {
                    slowo[j] = napis[pocz + j];
                }
                if (najw < slowo) {
                    najw.resize(dlugosc);
                    najw = slowo;
                }
            }
            pocz = i + 2;
        }
        i++;
    }
    return najw;
}

string UsunSlowo (string napis, int numerU) {
    string wynik;
    int rozm;
    int numer;
    int dlugosc;
    int i;
    int j;
    wynik = napis;
    rozm = wynik.size();
    numer = 0;
    i = 0;
    while (i < rozm) {
        if (wynik[i] != ' ') {
            numer++;
            j = i;
            while ((wynik[j] != ' ')&&(j < rozm)) {
                j++;
            }
            dlugosc = j - i;
            if (numer == numerU) {
                for (int k = i; k <= rozm - dlugosc; k++) { // k <= i + rozm - (i + dlugosc)
                    wynik[k] = wynik[k + dlugosc];
                }
                rozm -= dlugosc;
                wynik.resize(rozm);
            }
            i += dlugosc; // i = j
        }
        else
            i++;
    }
    return wynik;
}

string NormalizujNapis(string napis) {
    string wynik;
    int i;
    int rozm;
    wynik = napis;
    rozm = wynik.size();
    //usuniecie poczatkowych spacji:
    while (wynik[0] == ' ') {
        for (int j = 0; j < rozm; j++) {
            wynik[j] = wynik[j + 1];
        }
        rozm--;
        wynik.resize(rozm);
    }
    //usuniecie spacji na koncu:
    while (wynik[rozm - 1] == ' ') {
        rozm--;
        wynik.resize(rozm);
    }
    //redukcja zbednych spacji w reszcie napisu
    i = 1;
    while (i < rozm - 1) {
        if (((wynik[i] == ' ')&&(wynik[i+1] == ' '))||((wynik[i] == ' ')&&(wynik[i+1] == ','))||((wynik[i] == ' ')&&(wynik[i+1] == '.'))) {
            for (int j = i; j < rozm; j++) {
                wynik[j] = wynik[j + 1];
            }
            rozm--;
            wynik.resize(rozm);
        }
        else
        i++;
    }
    //dodanie brakujacych spacji po znakach interpunkcyjnych
    i = 0;
    while (i < rozm - 1) {
        if (((wynik[i] == '.')||(wynik[i] == ','))&&(wynik[i + 1] != ' ')) {
            rozm++;
            wynik.resize(rozm);
            for (int j = rozm - 1; j >= i + 2; j--) {
                wynik[j] = wynik[j - 1];
            }
            wynik[i + 1] = ' ';
        }
        i++;
    }
    return wynik;
}

string FormatujNapis(string napis, string par1, string par2, string par3) {
    string wynik;
    string cz1;
    string cz2;
    char c;
    int i;
    int n;
    int m;
    int rozm;
    wynik = napis;
    rozm = wynik.size();
    i = 0;
    while (i < rozm) {
        if (wynik[i] == '{') {
            n = static_cast<int>(wynik[i+3]) - 48;
            if (wynik[i + 1] == 'p') {
                c = wynik[i+5];
                if (n > 7) {
                    rozm += (n - 7);
                    wynik.resize(rozm);
                    for (int j = 0; j < n - 7; j++) {
                        for (int k = rozm - 1; k >= i + 7; k--) {
                            wynik[k] = wynik[k - 1];
                        }
                    }
                }
                else if (n < 7) {
                    for (int j = 0; j < 7 - n; j++) {
                        for (int k = i + n; k < rozm - 1; k++) {
                            wynik[k] = wynik[k + 1];
                        }
                    }
                    rozm += (n - 7);
                    wynik.resize(rozm);
                }
                for (int j = i; j < i + n; j++) {
                    wynik[j] = c;
                }
                i += n;
            }
            else if (wynik[i + 1] == 'u') {
                if (n > rozm - (i + 4))
                    n = rozm - (i + 4);
                for (int j = i; j <= rozm - (5 + n); j++) { // j <= i + rozm - (i + 5 + n)
                    wynik[j] = wynik[j + n + 5];
                }
                rozm -= (n + 5);
                wynik.resize(rozm);
            }
            else if (wynik[i + 1] == 'U') {
                if (n > i)
                    n = i;
                for (int j = i - n; j <= rozm - (5 + n); j++) { // j <= i - n + rozm - (i + 5)
                    wynik[j] = wynik[j + n + 5];
                }
                rozm -= (n + 5);
                wynik.resize(rozm);
                i -= n;
            }
            else if (wynik[i + 1] == 'w') {
                cz1 = wynik;
                cz1.resize(i);
                cz2 = wynik;
                for (int j = 0; j < rozm - (i + 5); j++) {
                    cz2[j] = cz2[j + i + 5];
                }
                cz2.resize(rozm - (i + 5));
                wynik = "";
                if (n == 1)
                    wynik += cz1 + par1 + cz2;
                else if (n == 2)
                    wynik += cz1 + par2 + cz2;
                else if (n == 3)
                    wynik += cz1 + par3 + cz2;
                rozm = wynik.size();
                i++;
            }
            else if (wynik[i + 1] == 'W') {
                m = static_cast<int>(wynik[i+5]) - 48;
                cz1 = wynik;
                cz1.resize(i);
                cz2 = wynik;
                for (int j = 0; j < rozm - (i + 7); j++) {
                    cz2[j] = cz2[j + i + 7];
                }
                cz2.resize(rozm - (i + 7));
                wynik = "";
                wynik += cz1;
                if (n == 1) {
                    par1.resize(m, ' ');
                    wynik += par1;
                }
                else if (n == 2) {
                    par2.resize(m, ' ');
                    wynik += par2;
                }
                else if (n == 3) {
                    par3.resize(m, ' ');
                    wynik += par3;
                }
                wynik += cz2;
                rozm = wynik.size();
                i += m;
            }
        }
        else
            i++;
    }
    return wynik;
}
