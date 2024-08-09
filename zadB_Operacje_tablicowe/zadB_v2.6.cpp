//Jakub Kozub
#include <iostream>
using namespace std;

int main()
{
    int liczbaSesji;
    int s;
    int i;
    int j;
    int k;
    int tmp;
    int tmp2;
    int n; // rozmiar tablicy w danej sesji
    int start; // indeks pierwszego elementu fragmentu tablicy
    int frag; // dlugosc fragmentu
    int przes; // przesuniecie
    int przesAbs; // wartosc bezwzgledna przesuniecia
    int m; // liczba fragmentow o zadanej dlugosci mieszczacych sie w tablicy
    int fragX; // dlugosc pozostalego fragmentu krotszego niz frag
    int startX; // indeks poczatku pozostalego fragmentu
    int i1, i2, ik; // indeksy swapowanych elementow tablicy
    char operacja; // okreslenie rodzaju operacji
    cin >> liczbaSesji;
    s = 0;
    while (s < liczbaSesji) {
        cin >> n;
        int A[n];
        i = 0;
        while (i < n) {
            cin >> A[i];
            i++;
        }
        i = 0;
        while (i < n) {
            cout << A[i] << " ";
            i++;
        }
        cout << "\n";
        //cout << "rozmiar: " << n << endl;
        /*i = 0;
        while (i < n) {
            cout << A[i] << " ";
            i++;
        }*/
        operacja = 'A';
        while (operacja != 'F') {
            i = 0;
            cin >> operacja;
            if (operacja != 'F') {
                    //if ((operacja != 'F')&&(frag != 0))
                cin >> start >> frag;
                //if ((frag <= n)&&(frag != 0))
                //if (frag <= n) {
                    if (frag != 0)
                        m = n/frag; // ile fragmentow miesci sie w An
                    else
                        m = 0;
                //}
                //else
            //wyznaczenie faktycznego indeksu pierwszego elementu:
                if (start >= n) {
                    start = start % n;
                }
                else if (start < 0) {
                    start = n + (start % n);
                    if (start % n < 0)
                        start += n;
                }
            //wykonanie stosownych czynnosci w zaleznosci od rodzaju operacji:
                if ((operacja == 'R')&&(frag <= n)&&(frag > 1)) { // odwracanie
                    //cout << "R" << endl;
                    while (i < m) {
                        if (i > 0)
                            start += frag;
                        if (start >= n) {
                            start = start % n;
                        }
                        j = 0;
                        while (j < (frag/2)) {
                            i1 = start+j;
                            i2 = start+(frag - 1 - j);
                            if (i1 > (n-1)) {
                                i1 = i1 % n;
                            }
                            if (i2 > (n-1)) {
                                i2 = i2 % n;
                            }
                            tmp = A[i1];
                            A[i1] = A[i2];
                            A[i2] = tmp;
                            j++;
                        }
                        i++;
                    }
                }
                else if ((operacja == 'S')&&(frag != 0)&&(frag <= n/2)) { // zamiana parami
                    //cout << "S" << endl;
                    if ((m % 2) == 1)
                        m--;
                    while (i < m) {
                        if (i > 0)
                            start += 2*frag;
                        if (start >= n) {
                            start = start % n;
                        }
                        j = 0;
                        while (j < frag) {
                            i1 = start + j;
                            i2 = start + frag + j;
                            if (i1 > (n-1)) {
                                i1 = i1 % n;
                            }
                            if (i2 > (n-1)) {
                                i2 = i2 % n;
                            }
                            tmp = A[i1];
                            A[i1] = A[i2];
                            A[i2] = tmp;
                            j++;
                        }
                        i+=2;
                    }
                }
                else if (operacja == 'C') { // przesuniecie
                    // if (frag != 1)
                    //if (frag != 0)
                    cin >> przes;
                    //cout << "ccc" << endl;
                    /*if (przes < 0)
                        //przes = frag + (przes % frag);
                        przes = przes % frag;*/
                        //cout << "Przesuniecie: " << przes << endl;
                    if ((frag != 1)&&(frag != 0)) {
                        //if (frag != 0) {
                            if (przes >= frag)
                                przes = przes % frag;
                            while (i < m) {
                                if (i > 0)
                                    start += frag;
                                if (start >= n) {
                                    start = start % n;
                                }
                                //cout << "start: " << start << endl;
                                //j = 0;
                                //tmp = A[start];
                                ik = start + frag - 1; // indeks koncowego elementu fragmentu
                                if (ik > (n-1)) {
                                    ik = ik % n;
                                }
                            //przesuniecie w prawo
                                if (przes > 0) {
                                    przesAbs = przes;
                                    j = 0;
                                    while (j < przesAbs) {
                                        k = 0;
                                        tmp = A[ik];
                                        while (k < frag - 1) {
                                            //i1 = start + frag - 1 - k;
                                            i1 = ik - k;
                                            if (i1 < 0) {
                                                i1 = n + (i1 % n);
                                            }
                                            //i2 = start + frag - 1 - k - 1;
                                            i2 = ik - k - 1;
                                            if (i2 < 0) {
                                                i2 = n + (i2 % n);
                                            }
                                            A[i1] = A[i2];
                                            k++;
                                        }
                                        A[start] = tmp;
                                        j++;
                                    }
                                }
                            // przesuniecie w lewo
                                else if (przes < 0) {
                                    przesAbs = (-1)*przes;
                                    j = 0;
                                    while (j < przesAbs) {
                                        k = 0;
                                        tmp = A[start];
                                        while (k < frag - 1) {
                                            i1 = start + k;
                                            if (i1 > (n-1)) {
                                                i1 = i1 % n;
                                            }
                                            i2 = start + k + 1;
                                            if (i2 > (n-1)) {
                                                i2 = i2 % n;
                                            }
                                            A[i1] = A[i2];
                                            k++;
                                        }
                                        A[ik] = tmp;
                                        j++;
                                    }
                                }
                                i++;
                            }
                       // }
                    // przesuniecie pozostalego fragmentu tablicy
                        fragX = n - m*frag;
                        if (fragX > 1) {
                            if (przes >= fragX)
                                przes = przes % fragX;
                            //cout << "ch" << endl;
                            startX = start + frag;
                            if (startX >= n) {
                                startX = startX % n;
                            }
                            ik = startX + fragX - 1; // indeks koncowego elementu fragmentu
                            if (ik > (n-1)) {
                                ik = ik % n;
                            }
                            //tmp = A[startX];
                            //i1 = startX;
                        //przesuniecie w prawo
                            if (przes > 0) {
                                przesAbs = przes;
                                j = 0;
                                while (j < przesAbs) {
                                    k = 0;
                                    tmp = A[ik];
                                    while (k < fragX - 1) {
                                        //i1 = start + frag - 1 - k;
                                        i1 = ik - k;
                                        if (i1 < 0) {
                                            i1 = n + (i1 % n);
                                        }
                                        //i2 = start + frag - 1 - k - 1;
                                        i2 = ik - k - 1;
                                        if (i2 < 0) {
                                            i2 = n + (i2 % n);
                                        }
                                        A[i1] = A[i2];
                                        k++;
                                    }
                                    A[startX] = tmp;
                                    j++;
                                }
                            }
                        // przesuniecie w lewo
                            else if (przes < 0) {
                                przesAbs = (-1)*przes;
                                j = 0;
                                while (j < przesAbs) {
                                    k = 0;
                                    tmp = A[startX];
                                    while (k < fragX - 1) {
                                        i1 = startX + k;
                                        if (i1 > (n-1)) {
                                            i1 = i1 % n;
                                        }
                                        i2 = startX + k + 1;
                                        if (i2 > (n-1)) {
                                            i2 = i2 % n;
                                        }
                                        A[i1] = A[i2];
                                        k++;
                                    }
                                    A[ik] = tmp;
                                    j++;
                                }
                            }
                        }
                    }
                }
            }
        }
        i = 0;
        while (i < n) {
            cout << A[i] << " ";
            i++;
        }
        cout << "\n";
        s++;
    }
    return 0;
}
