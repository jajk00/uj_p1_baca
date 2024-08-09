//Jakub Kozub
#include <iostream>
using namespace std;

void Cardinality (int zbior[], int *moc) {
    int i;
    i = 0;
    while (zbior[i] != -1) {
        i++;
    }
    *moc = i;
}

void Display (int tablica[]) {
    int i;
    i = 0;
    while (tablica[i] != -1) {
        cout << tablica[i] << " ";
        i++;
    }
    cout << endl;
}

bool Element(int a, int zbior[]) {
    bool nalezy;
    int i;
    nalezy = 0;
    if ((a >= 1)&&(a <= 4095)) {
        i = 0;
        while (zbior[i] != -1) {
            if (a == zbior[i])
                nalezy = 1;
            i++;
        }
    }
    return nalezy;
}

void bSort(int tablica[]) {
    int i;
    int j;
    int m;
    int tmp;
    int *wm;
    wm = &m;
    Cardinality(tablica, wm);
    i = 0;
    while (i < m-1) {
        j = 0;
        while (j < m-1) {
            if (tablica[j] > tablica[j+1]) {
                tmp = tablica[j];
                tablica[j] = tablica[j+1];
                tablica[j+1] = tmp;
            }
            j++;
        }
        i++;
    }
}

void Add(int a, int zbior[]) {
    int i;
    int j;
    int n;
    int tmp;
    int powt;
    powt = 0;
    if ((a >= 1)&&(a <= 4095)) {
        i = 0;
        while (zbior[i] != -1) {
            if (a == zbior[i])
                powt = 1;
            i++;
        }
        n = i + 1; // liczba elementow zbioru po dodaniu elementu
        if (powt == 0) {
            zbior[n-1] = a;
            zbior[n] = -1;
        }
    }
    bSort(zbior);
}

void AddWS(int a, int zbior[]) {
    int i;
    int j;
    int n;
    int tmp;
    int powt;
    powt = 0;
    if ((a >= 1)&&(a <= 4095)) {
        i = 0;
        while (zbior[i] != -1) {
            if (a == zbior[i])
                powt = 1;
            i++;
        }
        n = i + 1; // liczba elementow zbioru po dodaniu elementu
        if (powt == 0) {
            zbior[n-1] = a;
            zbior[n] = -1;
            //bSort(zbior);
        }
    }
}

void Create(int n, int zrodlo[], int zbior[]) {
    int i;
    int j;
    int m;
    //int tmp;
    int *wm;
    wm = &m;
    zbior[0] = -1;
    i = 0;
    while (i < n) {
        Add(zrodlo[i], zbior);
        i++;
    }
    Cardinality(zbior, wm);
    zbior[m] = -1;
    //bSort(zbior);
}

void Union(int zbior1[], int zbior2[], int suma[]) {
    int i;
    int m;
    int *wm;
    wm = &m;
    suma[0] = -1;
    i = 0;
    while (zbior1[i] != -1) {
        AddWS(zbior1[i], suma);
        i++;
    }
    i = 0;
    while (zbior2[i] != -1) {
        AddWS(zbior2[i], suma);
        i++;
    }
    Cardinality(suma, wm);
    suma[m] = -1;
    bSort(suma);
}

void Intersection(int zbior1[], int zbior2[], int iloczyn[]) {
    int i;
    int j;
    int m;
    int *wm;
    wm = &m;
    iloczyn[0] = -1;
    i = 0;
    while (zbior1[i] != -1) {
        j = 0;
        while (zbior2[j] != -1) {
            if (zbior1[i] == zbior2[j])
                AddWS(zbior2[j], iloczyn);
            j++;
        }
        i++;
    }

    Cardinality(iloczyn, wm);
    iloczyn[m] = -1;
    bSort(iloczyn);
}

bool Subset(int zbior1[], int zbior2[]) {
    bool nalezy;
    int i;
    i = 0;
    nalezy = 1;
    while (zbior1[i] != -1) {
        if (Element(zbior1[i], zbior2) == 0)
            nalezy = 0;
        i++;
    }
    return nalezy;
}


bool Equal(int zbior1[], int zbior2[]) {
    bool rowne;
    if ((Subset(zbior1, zbior2))&&(Subset(zbior2, zbior1)))
        rowne = 1;
    else
        rowne = 0;
    return rowne;
}

bool Empty(int zbior[]) {
    bool pusty;
    int m;
    int *wm;
    wm = &m;
    Cardinality(zbior, wm);
    if (m == 0)
        pusty = 1;
    else
        pusty = 0;
    return pusty;
}

bool Nonempty(int zbior[]) {
    bool niepusty;
    int m;
    int *wm;
    wm = &m;
    Cardinality(zbior, wm);
    if (m == 0)
        niepusty = 0;
    else
        niepusty = 1;
    return niepusty;
}


double Arithmetic(int zbior[]) {
    int i;
    double srednia;
    i = 0;
    srednia = 0;
    if (Nonempty(zbior) == 1) {
        while (zbior[i] != -1) {
            srednia += zbior[i];
            i++;
        }
        srednia /= i;
    }
    return srednia;
}

double Harmonic(int zbior[]) {
    int i;
    double sredniaH;
    if (Nonempty(zbior) == 1) {
         i = 0;
        sredniaH = 0;
        while (zbior[i] != -1) {
            sredniaH += ((double)1/zbior[i]);
            i++;
        }
        sredniaH = i/sredniaH;
    }
    else
        sredniaH = 1.0;
    return sredniaH;
}

void MinMax(int zbior[], int *wmin, int &rmax) {
    int i;

    if (Nonempty(zbior) == 1) {
        i = 0;
        *wmin = 4096;
        rmax = 0;
        while (zbior[i] != -1) {
            if (zbior[i] < *wmin)
                *wmin = zbior[i];
            if (zbior[i] > rmax)
                rmax = zbior[i];
            i++;
        }
    }
}

void Properties(int zbior[], char operacje[], double &sredniaArt, double *sredniaHrm, int &elMin, int *wskMax, int &moc) {
    int i;
    int &elMax = *wskMax;
    int *wskMin;
    int *wskMoc;
    i = 0;
    while (operacje[i] != 0) {
        if (operacje[i] == 'a') {
            sredniaArt = Arithmetic(zbior);
        }
        else if (operacje[i] == 'h') {
            *sredniaHrm = Harmonic(zbior);
        }
        else if (operacje[i] == 'm') {
            wskMin = &elMin;
            MinMax(zbior, wskMin, elMax);
        }
        else if (operacje[i] == 'c') {
            wskMoc = &moc;
            Cardinality(zbior, wskMoc);
        }
        i++;
    }
}

void Difference(int zbior1[], int zbior2[], int roznica[]) {
    int i;
    roznica[0] = -1;
    if (Nonempty(zbior1) == 1) {
        i = 0;
        while (zbior1[i] != -1) {
            if (Element(zbior1[i], zbior2) == 0) {
                AddWS(zbior1[i], roznica);
            }
            i++;
        }
    }
    bSort(roznica);
}

void Symmetric(int zbior1[], int zbior2[], int roznicaS[]) {
    int i;
    i = 0;
    roznicaS[0] = -1;
    if (Nonempty(zbior1) == 1) {
        i = 0;
        while (zbior1[i] != -1) {
            if (Element(zbior1[i], zbior2) == 0) {
                AddWS(zbior1[i], roznicaS);
            }
            i++;
        }
    }
    if (Nonempty(zbior2) == 1) {
        i = 0;
        while (zbior2[i] != -1) {
            if (Element(zbior2[i], zbior1) == 0) {
                AddWS(zbior2[i], roznicaS);
            }
            i++;
        }
    }
    bSort(roznicaS);
}

void Complement(int zbior[], int dopelnienie[]) {
    int i;
    dopelnienie[0] = -1;
    i = 1;
    while (i <= 4095) {
        if (Element(i, zbior) == 0) {
            AddWS(i, dopelnienie);
        }
        i++;
    }
}


