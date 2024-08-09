//Jakub Kozub
#include <iostream>
using namespace std;

long long iloscTowSklad; // ilosc towaru w calym skladzie
const unsigned short liczbaMax = 128;
const unsigned short towarMax = 65535;

struct Place {
    unsigned short iloscTow;
    char label[2];
};

struct Shelf {
    short liczbaMiejsc;
    Place miejsce[liczbaMax];
};

struct Rack {
    short liczbaPolek;
    Shelf polka[liczbaMax];
};

struct Warehouse {
    short liczbaReg;
    Rack regal[liczbaMax];
    Shelf polPodrM;
};

struct Storage {
    short liczbaMag;
    Warehouse magazyn[liczbaMax];
    Rack regPodr;
    Shelf polPodrS;
};

Storage sklad;

void getW();
void getRW();
void getRH();
void getSW();
void getSH();
void getSR();
void getS();
void putW(int w, int r, int s, int p, int a);
void putH(int w, int p, int a);
void putR(int s, int p, int a);
void putS(int p, int a);
void popW(int w, int r, int s, int p, int a);
void popH(int w, int p, int a);
void popR(int s, int p, int a);
void popS(int p, int a);
void movW(int wb, int rb, int sb, int we, int re, int se, int p, int a);
void movH(int w, int r, int s, int p, int a);
void movR(int w, int r, int sb, int se, int p, int a);
void movS(int s, int p, int a);
void setAP(int wb, int rb, int sb, int Pe);
void setAS(int wb, int rb, int Se, int Pe);
void setAR(int wb, int Re, int Se, int Pe);
void setAW(int We, int Re, int Se, int Pe);
void setHW(int w, int P);
void setHR(int S, int P);
void setHS(int P);
void setLW();
void setLH();
void setLR();
void setLS();
void getLW();
void getLH();
void getLR();
void getLS();
void fillS();

// ------------------------------------------------------------------------

int main()
{
    int mag; // nr magazynu
    int reg; // nr regalu
    int pol; // nr polki
    int msc; // nr miejsca
    int ile; // ilosc towaru na danym miejscu
    int magB;
    int magE;
    int regB;
    int regE;
    int polB;
    int polE;
    int liczbaMsc;
    int liczbaPol;
    int liczbaReg;
    int liczbaMag;
    string polecenie; // okreslenie polecenia

    polecenie = "A";
    while (polecenie != "END") {
        cin >> polecenie;
        if (polecenie == "GET-E") {
            cout << iloscTowSklad << endl;
        }
        else if (polecenie == "GET-W") { //ilosc towaru w magazynie w
            getW();
        }
        else if (polecenie == "GET-RW") { //ilosc towaru na regale r w magazynie w
            getRW();
        }
        else if (polecenie == "GET-RH") { //ilosc towaru na podrecznym regale skladu
            getRH();
        }
        else if (polecenie == "GET-SW") { //ilosc towaru na polce s regalu r w magazynie w
            getSW();
        }
        else if (polecenie == "GET-SH") { //ilosc towaru na podrecznej polce magazynu w
            getSH();
        }
        else if (polecenie == "GET-SR") { //ilosc towaru na podrecznym regale skladu na polce s
            getSR();
        }
        else if (polecenie == "GET-S") { //ilosc towaru na podrecznej polce skladu
            getS();
        }
        else if (polecenie == "PUT-W") {
            cin >> mag >> reg >> pol >> msc >> ile;
            putW(mag, reg, pol, msc, ile);
        }
        else if (polecenie == "PUT-H") {
            cin >> mag >> msc >> ile;
            putH(mag, msc, ile);
        }
        else if (polecenie == "PUT-R") {
            cin >> pol >> msc >> ile;
            putR(pol, msc, ile);
        }
        else if (polecenie == "PUT-S") {
            cin >> msc >> ile;
            putS(msc, ile);
        }
        else if (polecenie == "POP-W") {
            cin >> mag >> reg >> pol >> msc >> ile;
            popW(mag, reg, pol, msc, ile);
        }
        else if (polecenie == "POP-H") {
            cin >> mag >> msc >> ile;
            popH(mag, msc, ile);
        }
        else if (polecenie == "POP-R") {
            cin >> pol >> msc >> ile;
            popR(pol, msc, ile);
        }
        else if (polecenie == "POP-S") {
            cin >> msc >> ile;
            popS(msc, ile);
        }
        else if (polecenie == "MOV-W") {
            cin >> magB >> regB >> polB >> magE >> regE >> polE >> msc >> ile;
            movW(magB, regB, polB, magE, regE, polE, msc, ile);
        }
        else if (polecenie == "MOV-H") {
            cin >> mag >> reg >> pol >> msc >> ile;
            movH(mag, reg, pol, msc, ile);
        }
        else if (polecenie == "MOV-R") {
            cin >> mag >> reg >> polB >> polE >> msc >> ile;
            movR(mag, reg, polB, polE, msc, ile);
        }
        else if (polecenie == "MOV-S") {
            cin >> pol >> msc >> ile;
            movS(pol, msc, ile);
        }
        else if (polecenie == "SET-AP") {
            cin >> mag >> reg >> pol >> liczbaMsc;
            setAP(mag, reg, pol, liczbaMsc);
        }
        else if (polecenie == "SET-AS") {
            cin >> mag >> reg >> liczbaPol >> liczbaMsc;
            setAS(mag, reg, liczbaPol, liczbaMsc);
        }
        else if (polecenie == "SET-AR") {
            cin >> mag >> liczbaReg >> liczbaPol >> liczbaMsc;
            setAR(mag, liczbaReg, liczbaPol, liczbaMsc);
        }
        else if (polecenie == "SET-AW") {
            cin >> liczbaMag >> liczbaReg >> liczbaPol >> liczbaMsc;
            setAW(liczbaMag, liczbaReg, liczbaPol, liczbaMsc);
        }
        else if (polecenie == "SET-HW") {
            cin >> mag >> liczbaMsc;
            setHW(mag, liczbaMsc);
        }
        else if (polecenie == "SET-HR") {
            cin >> liczbaPol >> liczbaMsc;
            setHR(liczbaPol, liczbaMsc);
        }
        else if (polecenie == "SET-HS") {
            cin >> liczbaMsc;
            setHS(liczbaMsc);
        }
        else if (polecenie == "SET-LW") {
            setLW();
        }
        else if (polecenie == "SET-LH") {
            setLH();
        }
        else if (polecenie == "SET-LR") {
            setLR();
        }
        else if (polecenie == "SET-LS") {
            setLS();
        }
        else if (polecenie == "GET-LW") {
            getLW();
        }
        else if (polecenie == "GET-LH") {
            getLH();
        }
        else if (polecenie == "GET-LR") {
            getLR();
        }
        else if (polecenie == "GET-LS") {
            getLS();
        }
        else if (polecenie == "FILL") {
            fillS();
        }
    }
    return 0;
}

// -------------------------------------------------------------------------

void getW() {
    int w;
    long long towarMagazyn;
    towarMagazyn = 0;
    cin >> w;
    if ((w < 0)||(w > 127)||(w >= sklad.liczbaMag)) {
        cout << "error" << endl;
    }
    else {
        for (int i = 0; i < sklad.magazyn[w].liczbaReg; i++) {
            for (int j = 0; j < sklad.magazyn[w].regal[i].liczbaPolek; j++) {
                for (int k = 0; k < sklad.magazyn[w].regal[i].polka[j].liczbaMiejsc; k++) {
                    towarMagazyn += sklad.magazyn[w].regal[i].polka[j].miejsce[k].iloscTow;
                }
            }
        }
        for (int k = 0; k < sklad.magazyn[w].polPodrM.liczbaMiejsc; k++) {
            towarMagazyn += sklad.magazyn[w].polPodrM.miejsce[k].iloscTow;
        }
        cout << towarMagazyn << endl;
    }
}

void getRW() {
    int w;
    int r;
    long long towarRegal;
    towarRegal = 0;
    cin >> w >> r;
    if ((w < 0)||(w > 127)||(r < 0)||(r > 127)||(w >= sklad.liczbaMag)||(r >= sklad.magazyn[w].liczbaReg)) {
        cout << "error" << endl;
    }
    else {
        for (int j = 0; j < sklad.magazyn[w].regal[r].liczbaPolek; j++) {
            for (int k = 0; k < sklad.magazyn[w].regal[r].polka[j].liczbaMiejsc; k++) {
                towarRegal += sklad.magazyn[w].regal[r].polka[j].miejsce[k].iloscTow;
            }
        }
        cout << towarRegal << endl;
    }
}

void getRH() {
    long long towarRegPodr;
    towarRegPodr = 0;
    for (int j = 0; j < sklad.regPodr.liczbaPolek; j++) {
        for (int k = 0; k < sklad.regPodr.polka[j].liczbaMiejsc; k++) {
            towarRegPodr += sklad.regPodr.polka[j].miejsce[k].iloscTow;
        }
    }
    cout << towarRegPodr << endl;
}

void getSW() {
    int w;
    int r;
    int s;
    long long towarPolka;
    cin >> w >> r >> s;
    towarPolka = 0;
    if ((w < 0)||(w > 127)||(r < 0)||(r > 127)||(s < 0)||(s > 127)||(w >= sklad.liczbaMag)||(r >= sklad.magazyn[w].liczbaReg)||(s >= sklad.magazyn[w].regal[r].liczbaPolek)) {
        cout << "error" << endl;
    }
    else {
        for (int k = 0; k < sklad.magazyn[w].regal[r].polka[s].liczbaMiejsc; k++) {
            towarPolka += sklad.magazyn[w].regal[r].polka[s].miejsce[k].iloscTow;
        }
        cout << towarPolka << endl;
    }
}

void getSH() {
    int w;
    long long towarPolPodr;
    cin >> w;
    if ((w < 0)||(w > 127)||(w >= sklad.liczbaMag)) {
        cout << "error" << endl;
    }
    else {
        towarPolPodr = 0;
        for (int k = 0; k < sklad.magazyn[w].polPodrM.liczbaMiejsc; k++) {
            towarPolPodr += sklad.magazyn[w].polPodrM.miejsce[k].iloscTow;
        }
        cout << towarPolPodr << endl;
    }
}

void getSR() {
    int s;
    long long towarHRpol;
    cin >> s;
    if ((s < 0)||(s > 127)||(s >= sklad.regPodr.liczbaPolek)) {
        cout << "error" << endl;
    }
    else {
        towarHRpol = 0;
        for (int k = 0; k < sklad.regPodr.polka[s].liczbaMiejsc; k++) {
            towarHRpol += sklad.regPodr.polka[s].miejsce[k].iloscTow;
        }
        cout << towarHRpol << endl;
    }
}

void getS() {
    long long towarPolPodrS;
    towarPolPodrS = 0;
    for (int k = 0; k < sklad.polPodrS.liczbaMiejsc; k++) {
        towarPolPodrS += sklad.polPodrS.miejsce[k].iloscTow;
    }
    cout << towarPolPodrS << endl;
}

void putW(int w, int r, int s, int p, int a) {
    int wolne; // ile towaru zmiesci sie jeszcze na docelowym miejscu
    if ((w < 0)||(w > 127)||(r < 0)||(r > 127)||(s < 0)||(s > 127)||(p < 0)||(p > 127)||(a < 0)||(w >= sklad.liczbaMag)||(r >= sklad.magazyn[w].liczbaReg)||(s >= sklad.magazyn[w].regal[r].liczbaPolek)||(p >= sklad.magazyn[w].regal[r].polka[s].liczbaMiejsc)) {
        cout << "error" << endl;
    }
    else {
        wolne = towarMax - sklad.magazyn[w].regal[r].polka[s].miejsce[p].iloscTow;
        if (a > wolne) {
            a = wolne;
        }
        sklad.magazyn[w].regal[r].polka[s].miejsce[p].iloscTow += a;
        iloscTowSklad += a;
    }
}

void putH(int w, int p, int a) {
    int wolne; // ile towaru zmiesci sie jeszcze na docelowym miejscu
    if ((w < 0)||(w > 127)||(p < 0)||(p > 127)||(a < 0)||(w >= sklad.liczbaMag)||(p >= sklad.magazyn[w].polPodrM.liczbaMiejsc)) {
        cout << "error" << endl;
    }
    else {
        wolne = towarMax - sklad.magazyn[w].polPodrM.miejsce[p].iloscTow;
        if (a > wolne) {
            a = wolne;
        }
        sklad.magazyn[w].polPodrM.miejsce[p].iloscTow += a;
        iloscTowSklad += a;
    }
}

void putR(int s, int p, int a) {
    int wolne; // ile towaru zmiesci sie jeszcze na docelowym miejscu
    if ((s < 0)||(s > 127)||(p < 0)||(p > 127)||(a < 0)||(s >= sklad.regPodr.liczbaPolek)||(p >= sklad.regPodr.polka[s].liczbaMiejsc)) {
        cout << "error" << endl;
    }
    else {
        wolne = towarMax - sklad.regPodr.polka[s].miejsce[p].iloscTow;
        if (a > wolne) {
            a = wolne;
        }
        sklad.regPodr.polka[s].miejsce[p].iloscTow += a;
        iloscTowSklad += a;
    }
}

void putS(int p, int a) {
    int wolne; // ile towaru zmiesci sie jeszcze na docelowym miejscu
    if ((p < 0)||(p > 127)||(a < 0)||(p >= sklad.polPodrS.liczbaMiejsc)) {
        cout << "error" << endl;
    }
    else {
        wolne = towarMax - sklad.polPodrS.miejsce[p].iloscTow;
        if (a > wolne) {
            a = wolne;
        }
        sklad.polPodrS.miejsce[p].iloscTow += a;
        iloscTowSklad += a;
    }
}

void popW(int w, int r, int s, int p, int a) {
    if ((w < 0)||(w > 127)||(r < 0)||(r > 127)||(s < 0)||(s > 127)||(p < 0)||(p > 127)||(a < 0)||(w >= sklad.liczbaMag)||(r >= sklad.magazyn[w].liczbaReg)||(s >= sklad.magazyn[w].regal[r].liczbaPolek)||(p >= sklad.magazyn[w].regal[r].polka[s].liczbaMiejsc)) {
        cout << "error" << endl;
    }
    else {
        if (a > sklad.magazyn[w].regal[r].polka[s].miejsce[p].iloscTow) {
            a = sklad.magazyn[w].regal[r].polka[s].miejsce[p].iloscTow;
        }
        sklad.magazyn[w].regal[r].polka[s].miejsce[p].iloscTow -= a;
        iloscTowSklad -= a;
    }
}

void popH(int w, int p, int a) {
    if ((w < 0)||(w > 127)||(p < 0)||(p > 127)||(a < 0)||(w >= sklad.liczbaMag)||(p >= sklad.magazyn[w].polPodrM.liczbaMiejsc)) {
        cout << "error" << endl;
    }
    else {
        if (a > sklad.magazyn[w].polPodrM.miejsce[p].iloscTow) {
            a = sklad.magazyn[w].polPodrM.miejsce[p].iloscTow;
        }
        sklad.magazyn[w].polPodrM.miejsce[p].iloscTow -= a;
        iloscTowSklad -= a;
    }
}

void popR(int s, int p, int a) {
    if ((s < 0)||(s > 127)||(p < 0)||(p > 127)||(a < 0)||(s >= sklad.regPodr.liczbaPolek)||(p >= sklad.regPodr.polka[s].liczbaMiejsc)) {
        cout << "error" << endl;
    }
    else {
        if (a > sklad.regPodr.polka[s].miejsce[p].iloscTow) {
            a = sklad.regPodr.polka[s].miejsce[p].iloscTow;
        }
        sklad.regPodr.polka[s].miejsce[p].iloscTow -= a;
        iloscTowSklad -= a;
    }
}

void popS(int p, int a) {
    if ((p < 0)||(p > 127)||(a < 0)||(p >= sklad.polPodrS.liczbaMiejsc)) {
        cout << "error" << endl;
    }
    else {
        if (a > sklad.polPodrS.miejsce[p].iloscTow) {
            a = sklad.polPodrS.miejsce[p].iloscTow;
        }
        sklad.polPodrS.miejsce[p].iloscTow -= a;
        iloscTowSklad -= a;
    }
}

void movW(int wb, int rb, int sb, int we, int re, int se, int p, int a) {
    int wolne; // ile towaru zmiesci sie jeszcze na docelowym miejscu
    if ((wb < 0)||(wb > 127)||(rb < 0)||(rb > 127)||(sb < 0)||(sb > 127)||(we < 0)||(we > 127)||(re < 0)||(re > 127)||(se < 0)||(se > 127)||(p < 0)||(p > 127)||(a < 0)||(wb >= sklad.liczbaMag)||(we >= sklad.liczbaMag)||(rb >= sklad.magazyn[wb].liczbaReg)||(re >= sklad.magazyn[we].liczbaReg)||(sb >= sklad.magazyn[wb].regal[rb].liczbaPolek)||(se >= sklad.magazyn[we].regal[re].liczbaPolek)||(p >= sklad.magazyn[wb].regal[rb].polka[sb].liczbaMiejsc)||(p >= sklad.magazyn[we].regal[re].polka[se].liczbaMiejsc)) {
        cout << "error" << endl;
    }
    else {
        if (a > sklad.magazyn[wb].regal[rb].polka[sb].miejsce[p].iloscTow) {
            a = sklad.magazyn[wb].regal[rb].polka[sb].miejsce[p].iloscTow;
        }

        wolne = towarMax - sklad.magazyn[we].regal[re].polka[se].miejsce[p].iloscTow;
        while (a > wolne) {
            a--;
        }
        sklad.magazyn[wb].regal[rb].polka[sb].miejsce[p].iloscTow -= a;
        sklad.magazyn[we].regal[re].polka[se].miejsce[p].iloscTow += a;
    }
}

void movH(int w, int r, int s, int p, int a) {
    int wolne; // ile towaru zmiesci sie jeszcze na docelowym miejscu
    if ((w < 0)||(w > 127)||(r < 0)||(r > 127)||(s < 0)||(s > 127)||(p < 0)||(p > 127)||(a < 0)||(w >= sklad.liczbaMag)||(r >= sklad.magazyn[w].liczbaReg)||(s >= sklad.magazyn[w].regal[r].liczbaPolek)||(p >= sklad.magazyn[w].regal[r].polka[s].liczbaMiejsc)||(p >= sklad.magazyn[w].polPodrM.liczbaMiejsc)) {
        cout << "error" << endl;
    }
    else {
        if (a > sklad.magazyn[w].regal[r].polka[s].miejsce[p].iloscTow) {
            a = sklad.magazyn[w].regal[r].polka[s].miejsce[p].iloscTow;
        }
        wolne = towarMax - sklad.magazyn[w].polPodrM.miejsce[p].iloscTow;
        while (a > wolne) {
            a--;
        }
        sklad.magazyn[w].regal[r].polka[s].miejsce[p].iloscTow -= a;
        sklad.magazyn[w].polPodrM.miejsce[p].iloscTow += a;
    }
}

void movR(int w, int r, int sb, int se, int p, int a) {
    int wolne; // ile towaru zmiesci sie jeszcze na docelowym miejscu
    if ((w < 0)||(w > 127)||(r < 0)||(r > 127)||(sb < 0)||(sb > 127)||(se < 0)||(se > 127)||(p < 0)||(p > 127)||(a < 0)||(w >= sklad.liczbaMag)||(r >= sklad.magazyn[w].liczbaReg)||(sb >= sklad.magazyn[w].regal[r].liczbaPolek)||(se >= sklad.regPodr.liczbaPolek)||(p >= sklad.magazyn[w].regal[r].polka[sb].liczbaMiejsc)||(p >= sklad.regPodr.polka[se].liczbaMiejsc)) {
        cout << "error" << endl;
    }
    else {
        if (a > sklad.magazyn[w].regal[r].polka[sb].miejsce[p].iloscTow) {
            a = sklad.magazyn[w].regal[r].polka[sb].miejsce[p].iloscTow;
        }
        wolne = towarMax - sklad.regPodr.polka[se].miejsce[p].iloscTow;
        while (a > wolne) {
            a--;
        }
        sklad.magazyn[w].regal[r].polka[sb].miejsce[p].iloscTow -= a;
        sklad.regPodr.polka[se].miejsce[p].iloscTow += a;
    }
}

void movS(int s, int p, int a) {
    int wolne; // ile towaru zmiesci sie jeszcze na docelowym miejscu
    if ((s < 0)||(s > 127)||(p < 0)||(p > 127)||(a < 0)||(s >= sklad.regPodr.liczbaPolek)||(p >= sklad.regPodr.polka[s].liczbaMiejsc)||(p >= sklad.polPodrS.liczbaMiejsc)) {
        cout << "error" << endl;
    }
    else {
        if (a > sklad.regPodr.polka[s].miejsce[p].iloscTow) {
            a = sklad.regPodr.polka[s].miejsce[p].iloscTow;
        }
        wolne = towarMax - sklad.polPodrS.miejsce[p].iloscTow;
        while (a > wolne) {
            a--;
        }
        sklad.regPodr.polka[s].miejsce[p].iloscTow -= a;
        sklad.polPodrS.miejsce[p].iloscTow += a;
    }
}

void setAP(int wb, int rb, int sb, int Pe) {
    int tmp;
    if ((wb < 0)||(wb > 127)||(rb < 0)||(rb > 127)||(sb < 0)||(sb > 127)||(Pe < 0)||(Pe > 128)||(wb >= sklad.liczbaMag)||(rb >= sklad.magazyn[wb].liczbaReg)||(sb >= sklad.magazyn[wb].regal[rb].liczbaPolek)) {
        cout << "error" << endl;
    }
    else {
        tmp = sklad.magazyn[wb].regal[rb].polka[sb].liczbaMiejsc;
        if (Pe >= tmp) {
            for (int i = tmp; i < Pe; i++) {
                sklad.magazyn[wb].regal[rb].polka[sb].miejsce[i].iloscTow = 0;
                sklad.magazyn[wb].regal[rb].polka[sb].miejsce[i].label[0] = '\0';
                sklad.magazyn[wb].regal[rb].polka[sb].miejsce[i].label[1] = '\0';
            }
            sklad.magazyn[wb].regal[rb].polka[sb].liczbaMiejsc = Pe;
        }
        else {
            for (int i = Pe; i < tmp; i++) {
                iloscTowSklad -= sklad.magazyn[wb].regal[rb].polka[sb].miejsce[i].iloscTow;
            }
            sklad.magazyn[wb].regal[rb].polka[sb].liczbaMiejsc = Pe;
        }
    }
}

void setAS(int wb, int rb, int Se, int Pe) {
    int tmp;
    if ((wb < 0)||(wb > 127)||(rb < 0)||(rb > 127)||(Se < 0)||(Se > 128)||(Pe < 0)||(Pe > 128)||(wb >= sklad.liczbaMag)||(rb >= sklad.magazyn[wb].liczbaReg)) {
        cout << "error" << endl;
    }
    else {
        tmp = sklad.magazyn[wb].regal[rb].liczbaPolek;
        if (Se >= tmp) {
            //nowo powstale polki:
            for (int i = tmp; i < Se; i++) {
                sklad.magazyn[wb].regal[rb].polka[i].liczbaMiejsc = Pe;
                for (int j = 0; j < Pe; j++) {
                    sklad.magazyn[wb].regal[rb].polka[i].miejsce[j].iloscTow = 0;
                    sklad.magazyn[wb].regal[rb].polka[i].miejsce[j].label[0] = '\0';
                    sklad.magazyn[wb].regal[rb].polka[i].miejsce[j].label[1] = '\0';
                }
            }
            //dotychczasowe polki o pozostawionych numerach:
            for (int i = 0; i < tmp; i++) {
                setAP(wb, rb, i, Pe);
            }
            sklad.magazyn[wb].regal[rb].liczbaPolek = Se;
        }
        else {
            //dotychczasowe polki niemieszczace sie w zakresie wartosci Se:
            for (int i = Se; i < tmp; i++) {
                for (int j = 0; j < sklad.magazyn[wb].regal[rb].polka[i].liczbaMiejsc; j++) {
                    iloscTowSklad -= sklad.magazyn[wb].regal[rb].polka[i].miejsce[j].iloscTow;
                }
            }
            //dotychczasowe polki o pozostawionych numerach:
            for (int i = 0; i < Se; i++) {
                setAP(wb, rb, i, Pe);
            }
            sklad.magazyn[wb].regal[rb].liczbaPolek = Se;
        }
    }
}

void setAR(int wb, int Re, int Se, int Pe) {
    int tmp;
    if ((wb < 0)||(wb > 127)||(Re < 0)||(Re > 128)||(Se < 0)||(Se > 128)||(Pe < 0)||(Pe > 128)||(wb >= sklad.liczbaMag)) {
        cout << "error" << endl;
    }
    else {
        tmp = sklad.magazyn[wb].liczbaReg;
        if (Re >= tmp) {
            //nowo powstale regaly:
            for (int i = tmp; i < Re; i++) {
                sklad.magazyn[wb].regal[i].liczbaPolek = Se;
                for (int j = 0; j < Se; j++) {
                    sklad.magazyn[wb].regal[i].polka[j].liczbaMiejsc = Pe;
                    for (int k = 0; k < Pe; k++) {
                        sklad.magazyn[wb].regal[i].polka[j].miejsce[k].iloscTow = 0;
                        sklad.magazyn[wb].regal[i].polka[j].miejsce[k].label[0] = '\0';
                        sklad.magazyn[wb].regal[i].polka[j].miejsce[k].label[1] = '\0';
                    }
                }
            }
            //dotychczasowe regaly o pozostawionych numerach:
            for (int i = 0; i < tmp; i++) {
                setAS(wb, i, Se, Pe);
            }
            sklad.magazyn[wb].liczbaReg = Re;
        }
        else {
            //dotychczasowe regaly niemieszczace sie w zakresie wartosci Re:
            for (int i = Re; i < tmp; i++) {
                for (int j = 0; j < sklad.magazyn[wb].regal[i].liczbaPolek; j++) {
                    for (int k = 0; k < sklad.magazyn[wb].regal[i].polka[j].liczbaMiejsc; k++) {
                        iloscTowSklad -= sklad.magazyn[wb].regal[i].polka[j].miejsce[k].iloscTow;
                    }
                }
            }
            //dotychczasowe regaly o pozostawionych numerach:
            for (int i = 0; i < Re; i++) {
                setAS(wb, i, Se, Pe);
            }
            sklad.magazyn[wb].liczbaReg = Re;
        }
    }
}

void setAW(int We, int Re, int Se, int Pe) {
    int tmp;
    if ((We < 0)||(We > 128)||(Re < 0)||(Re > 128)||(Se < 0)||(Se > 128)||(Pe < 0)||(Pe > 128)) {
        cout << "error" << endl;
    }
    else {
        tmp = sklad.liczbaMag;
        if (We >= tmp) {
            //nowo powstale magazyny:
            for (int i = tmp; i < We; i++) {
                sklad.magazyn[i].liczbaReg = Re;
                for (int j = 0; j < Re; j++) {
                    sklad.magazyn[i].regal[j].liczbaPolek = Se;
                    for (int k = 0; k < Se; k++) {
                        sklad.magazyn[i].regal[j].polka[k].liczbaMiejsc = Pe;
                        for (int l = 0; l < Pe; l++) {
                            sklad.magazyn[i].regal[j].polka[k].miejsce[l].iloscTow = 0;
                            sklad.magazyn[i].regal[j].polka[k].miejsce[l].label[0] = '\0';
                            sklad.magazyn[i].regal[j].polka[k].miejsce[l].label[1] = '\0';
                        }
                    }
                }
            }

            //dotychczasowe magazyny o pozostawionych numerach:
            for (int i = 0; i < tmp; i++) {
                setAR(i, Re, Se, Pe);
            }
            sklad.liczbaMag = We;
        }
        else {
            //dotychczasowe magazyny niemieszczace sie w zakresie wartosci We:
            for (int i = We; i < tmp; i++) {
                for (int j = 0; j < sklad.magazyn[i].liczbaReg; j++) {
                    for (int k = 0; k < sklad.magazyn[i].regal[j].liczbaPolek; k++) {
                        for (int l = 0; l < sklad.magazyn[i].regal[j].polka[k].liczbaMiejsc; l++) {
                            iloscTowSklad -= sklad.magazyn[i].regal[j].polka[k].miejsce[l].iloscTow;
                        }
                    }
                }
            }
            //dotychczasowe magazyny o pozostawionych numerach:
            for (int i = 0; i < We; i++) {
                setAR(i, Re, Se, Pe);
            }
            sklad.liczbaMag = We;
        }
    }
}

void setHW(int w, int P) {
    int tmp;
    if ((w < 0)||(w > 127)||(P < 0)||(P > 128)||(w >= sklad.liczbaMag)) {
        cout << "error" << endl;
    }
    else {
        tmp = sklad.magazyn[w].polPodrM.liczbaMiejsc;
        if (P >= tmp) {
            //nowo powstale miejsca:
            for (int i = tmp; i < P; i++) {
                sklad.magazyn[w].polPodrM.miejsce[i].iloscTow = 0;
                sklad.magazyn[w].polPodrM.miejsce[i].label[0] = '\0';
                sklad.magazyn[w].polPodrM.miejsce[i].label[1] = '\0';
            }
            sklad.magazyn[w].polPodrM.liczbaMiejsc = P;
        }
        else {
            //dotychczasowe miejsca niemieszczace sie w zakresie wartosci P:
            for (int i = P; i < tmp; i++) {
                iloscTowSklad -= sklad.magazyn[w].polPodrM.miejsce[i].iloscTow;
            }
            sklad.magazyn[w].polPodrM.liczbaMiejsc = P;
        }
    }
}

void setHR(int S, int P) {
    int tmp;
    int tmp2;
    if ((S < 0)||(S > 128)||(P < 0)||(P > 128)) {
        cout << "error" << endl;
    }
    else {
        tmp = sklad.regPodr.liczbaPolek;
        if (S >= tmp) {
            //nowo powstale polki:
            for (int i = tmp; i < S; i++) {
                sklad.regPodr.polka[i].liczbaMiejsc = P;
                for (int j = 0; j < P; j++) {
                    sklad.regPodr.polka[i].miejsce[j].iloscTow = 0;
                    sklad.regPodr.polka[i].miejsce[j].label[0] = '\0';
                    sklad.regPodr.polka[i].miejsce[j].label[1] = '\0';
                }
            }
            //dotychczasowe polki o pozostawionych numerach:
            for (int i = 0; i < tmp; i++) {
                tmp2 = sklad.regPodr.polka[i].liczbaMiejsc;
                if (P >= tmp2) {
                    for (int j = tmp2; j < P; j++) {
                        sklad.regPodr.polka[i].miejsce[j].iloscTow = 0;
                        sklad.regPodr.polka[i].miejsce[j].label[0] = '\0';
                        sklad.regPodr.polka[i].miejsce[j].label[1] = '\0';
                    }
                    sklad.regPodr.polka[i].liczbaMiejsc = P;
                }
                else {
                    for (int j = P; j < tmp2; j++) {
                        iloscTowSklad -= sklad.regPodr.polka[i].miejsce[j].iloscTow;
                    }
                    sklad.regPodr.polka[i].liczbaMiejsc = P;
                }
            }
            sklad.regPodr.liczbaPolek = S;
        }
        else {
            //dotychczasowe polki niemieszczace sie w zakresie wartosci S:
            for (int i = S; i < tmp; i++) {
                for (int j = 0; j < sklad.regPodr.polka[i].liczbaMiejsc; j++) {
                    iloscTowSklad -= sklad.regPodr.polka[i].miejsce[j].iloscTow;
                }
            }
            //dotychczasowe polki o pozostawionych numerach:
            for (int i = 0; i < S; i++) {
                tmp2 = sklad.regPodr.polka[i].liczbaMiejsc;
                if (P >= tmp2) {
                    for (int j = tmp2; j < P; j++) {
                        sklad.regPodr.polka[i].miejsce[j].iloscTow = 0;
                        sklad.regPodr.polka[i].miejsce[j].label[0] = '\0';
                        sklad.regPodr.polka[i].miejsce[j].label[1] = '\0';
                    }
                    sklad.regPodr.polka[i].liczbaMiejsc = P;
                }
                else {
                    for (int j = P; j < tmp2; j++) {
                        iloscTowSklad -= sklad.regPodr.polka[i].miejsce[j].iloscTow;
                    }
                    sklad.regPodr.polka[i].liczbaMiejsc = P;
                }
            }
            sklad.regPodr.liczbaPolek = S;
        }
    }
}

void setHS(int P) {
    int tmp;
    if ((P < 0)||(P > 128)) {
        cout << "error" << endl;
    }
    else {
        tmp = sklad.polPodrS.liczbaMiejsc;
        if (P >= tmp) {
            //nowo powstale miejsca:
            for (int i = tmp; i < P; i++) {
                sklad.polPodrS.miejsce[i].iloscTow = 0;
                sklad.polPodrS.miejsce[i].label[0] = '\0';
                sklad.polPodrS.miejsce[i].label[1] = '\0';
            }
            sklad.polPodrS.liczbaMiejsc = P;
        }
        else {
            //dotychczasowe miejsca niemieszczace sie w zakresie wartosci P:
            for (int i = P; i < tmp; i++) {
                iloscTowSklad -= sklad.polPodrS.miejsce[i].iloscTow;
            }
            sklad.polPodrS.liczbaMiejsc = P;
        }
    }
}

void setLW() {
    int w;
    int r;
    int s;
    int p;
    char dd[2];
    cin >> w >> r >> s >> p >> dd[0] >> dd[1];
    if ((w < 0)||(w > 127)||(r < 0)||(r > 127)||(s < 0)||(s > 127)||(p < 0)||(p > 127)||(w >= sklad.liczbaMag)||(r >= sklad.magazyn[w].liczbaReg)||(s >= sklad.magazyn[w].regal[r].liczbaPolek)||(p >= sklad.magazyn[w].regal[r].polka[s].liczbaMiejsc)) {
        cout << "error" << endl;
    }
    else {
        sklad.magazyn[w].regal[r].polka[s].miejsce[p].label[0] = dd[0];
        sklad.magazyn[w].regal[r].polka[s].miejsce[p].label[1] = dd[1];
    }
}

void setLH() {
    int w;
    int p;
    char dd[2];
    cin >> w >> p >> dd[0] >> dd[1];
    if ((w < 0)||(w > 127)||(p < 0)||(p > 127)||(w >= sklad.liczbaMag)||(p >= sklad.magazyn[w].polPodrM.liczbaMiejsc)) {
        cout << "error" << endl;
    }
    else {
        sklad.magazyn[w].polPodrM.miejsce[p].label[0] = dd[0];
        sklad.magazyn[w].polPodrM.miejsce[p].label[1] = dd[1];
    }
}

void setLR() {
    int s;
    int p;
    char dd[2];
    cin >> s >> p >> dd[0] >> dd[1];
    if ((s < 0)||(s > 127)||(p < 0)||(p > 127)||(s >= sklad.regPodr.liczbaPolek)||(p >= sklad.regPodr.polka[s].liczbaMiejsc)) {
        cout << "error" << endl;
    }
    else {
        sklad.regPodr.polka[s].miejsce[p].label[0] = dd[0];
        sklad.regPodr.polka[s].miejsce[p].label[1] = dd[1];
    }
}

void setLS() {
    int p;
    char dd[2];
    cin >> p >> dd[0] >> dd[1];
    if ((p < 0)||(p > 127)||(p >= sklad.polPodrS.liczbaMiejsc)) {
        cout << "error" << endl;
    }
    else {
        sklad.polPodrS.miejsce[p].label[0] = dd[0];
        sklad.polPodrS.miejsce[p].label[1] = dd[1];
    }
}

void getLW() {
    int w;
    int r;
    int s;
    int p;
    cin >> w >> r >> s >> p;
    if ((w < 0)||(w > 127)||(r < 0)||(r > 127)||(s < 0)||(s > 127)||(p < 0)||(p > 127)||(w >= sklad.liczbaMag)||(r >= sklad.magazyn[w].liczbaReg)||(s >= sklad.magazyn[w].regal[r].liczbaPolek)||(p >= sklad.magazyn[w].regal[r].polka[s].liczbaMiejsc)) {
        cout << "error" << endl;
    }
    else {
        if ((sklad.magazyn[w].regal[r].polka[s].miejsce[p].label[0] == '\0')&&(sklad.magazyn[w].regal[r].polka[s].miejsce[p].label[1] == '\0')) {
            cout << "--" << endl;
        }
        else {
            cout << sklad.magazyn[w].regal[r].polka[s].miejsce[p].label[0] << sklad.magazyn[w].regal[r].polka[s].miejsce[p].label[1] << endl;
        }
    }
}

void getLH() {
    int w;
    int p;
    cin >> w >> p;
    if ((w < 0)||(w > 127)||(p < 0)||(p > 127)||(w >= sklad.liczbaMag)||(p >= sklad.magazyn[w].polPodrM.liczbaMiejsc)) {
        cout << "error" << endl;
    }
    else {
        if ((sklad.magazyn[w].polPodrM.miejsce[p].label[0] == '\0')&&(sklad.magazyn[w].polPodrM.miejsce[p].label[1] == '\0')) {
            cout << "--" << endl;
        }
        else {
            cout << sklad.magazyn[w].polPodrM.miejsce[p].label[0] << sklad.magazyn[w].polPodrM.miejsce[p].label[1] << endl;
        }
    }
}

void getLR() {
    int s;
    int p;
    cin >> s >> p;
    if ((s < 0)||(s > 127)||(p < 0)||(p > 127)||(s >= sklad.regPodr.liczbaPolek)||(p >= sklad.regPodr.polka[s].liczbaMiejsc)) {
        cout << "error" << endl;
    }
    else {
        if ((sklad.regPodr.polka[s].miejsce[p].label[0] == '\0')&&(sklad.regPodr.polka[s].miejsce[p].label[1] == '\0')) {
            cout << "--" << endl;
        }
        else {
            cout << sklad.regPodr.polka[s].miejsce[p].label[0] << sklad.regPodr.polka[s].miejsce[p].label[1] << endl;
        }
    }
}

void getLS() {
    int p;
    cin >> p;
    if ((p < 0)||(p > 127)||(p >= sklad.polPodrS.liczbaMiejsc)) {
        cout << "error" << endl;
    }
    else {
        if ((sklad.polPodrS.miejsce[p].label[0] == '\0')&&(sklad.polPodrS.miejsce[p].label[1] == '\0')) {
            cout << "--" << endl;
        }
        else {
            cout << sklad.polPodrS.miejsce[p].label[0] << sklad.polPodrS.miejsce[p].label[1] << endl;
        }
    }
}

void fillS() {
    int w;
    int r;
    int s;
    int p;
    int a;
    cin >> w >> r >> s >> p >> a;
    if ((w >= 0)&&(w <= liczbaMax)&&(r >= 0)&&(r <= liczbaMax)&&(s >= 0)&&(s <= liczbaMax)&&(p >= 0)&&(p <= liczbaMax)&&(a >= 0)&&(a <= towarMax)) {
        iloscTowSklad = 0;
        sklad.liczbaMag = w;
        sklad.regPodr.liczbaPolek = s;
        sklad.polPodrS.liczbaMiejsc = p;
        for (int i = 0; i < w; i++) {
            sklad.magazyn[i].liczbaReg = r;
            sklad.magazyn[i].polPodrM.liczbaMiejsc = p;
            for (int j = 0; j < r; j++) {
                sklad.magazyn[i].regal[j].liczbaPolek = s;
                for (int k = 0; k < s; k++) {
                    sklad.magazyn[i].regal[j].polka[k].liczbaMiejsc = p;
                    for (int l = 0; l < p; l++) {
                        sklad.magazyn[i].regal[j].polka[k].miejsce[l].iloscTow = a;
                        sklad.magazyn[i].regal[j].polka[k].miejsce[l].label[0] = '\0';
                        sklad.magazyn[i].regal[j].polka[k].miejsce[l].label[1] = '\0';
                        iloscTowSklad += sklad.magazyn[i].regal[j].polka[k].miejsce[l].iloscTow;
                    }
                }
            }
            for (int l = 0; l < p; l++) {
                sklad.magazyn[i].polPodrM.miejsce[l].iloscTow = a;
                sklad.magazyn[i].polPodrM.miejsce[l].label[0] = '\0';
                sklad.magazyn[i].polPodrM.miejsce[l].label[1] = '\0';
                iloscTowSklad += sklad.magazyn[i].polPodrM.miejsce[l].iloscTow;
            }
        }
        for (int k = 0; k < s; k++) {
            sklad.regPodr.polka[k].liczbaMiejsc = p;
            for (int l = 0; l < p; l++) {
                sklad.regPodr.polka[k].miejsce[l].iloscTow = a;
                sklad.regPodr.polka[k].miejsce[l].label[0] = '\0';
                sklad.regPodr.polka[k].miejsce[l].label[1] = '\0';
                iloscTowSklad += sklad.regPodr.polka[k].miejsce[l].iloscTow;
            }
        }
        for (int l = 0; l < p; l++) {
            sklad.polPodrS.miejsce[l].iloscTow = a;
            sklad.polPodrS.miejsce[l].label[0] = '\0';
            sklad.polPodrS.miejsce[l].label[1] = '\0';
            iloscTowSklad += sklad.polPodrS.miejsce[l].iloscTow;
        }
    }
    else {
        cout << "error" << endl;
    }
}

