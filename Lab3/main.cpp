#include <iostream>
#include <cmath>
using namespace std;

class Punkt
{
protected:
    float x;
    float y;
public:
    Punkt(Punkt& p);
    Punkt(float _x = 0, float _y = 0);
    void dodaj(Punkt& p);
    void dodaj(Punkt* p);
    void drukujP();
    bool porownajP(const Punkt& p) const;
    Punkt& operator+=(Punkt& p);
    bool operator==(Punkt& p);
    Punkt operator+(Punkt& p);
    float PodajX() const;
    float PodajY() const;
    friend ostream& operator<< (ostream& wyjscie, const Punkt& p)
    {
        return wyjscie << "X: " << p.x << " Y: " << p.y << '\n';
    }
};

Punkt::Punkt(Punkt& p)
{
    x = p.x;
    y = p.y;
}
Punkt::Punkt(float _x, float _y)
{
    x = _x;
    y = _y;
}

void Punkt::dodaj(Punkt& p)
{
    x += p.x;
    y += p.y;
}
void Punkt::dodaj(Punkt* p)
{
    x += p->x;
    y += p->y;
}

void Punkt::drukujP()
{
    cout << "x: " << x << "\ty: " << y << "\n";
}

bool Punkt::porownajP(const Punkt& p) const
{
    return (x == p.x && y == p.y);
}

Punkt& Punkt::operator+=(Punkt& p)
{
    x += p.x;
    y += p.y;
    return *this;
}

bool Punkt::operator==(Punkt& p)
{
    if (this->x != p.x) { return false; };
    if (this->y != p.y) { return false; };
    return true;
}

Punkt Punkt::operator+(Punkt& p)
{
    Punkt tmp;
    tmp.x = this->x + p.x;
    tmp.y = this->y + p.y;
    return tmp;
}

float Punkt::PodajX() const
{
    return x;
}

float Punkt::PodajY() const
{
    return y;
}

class Tablica
{
    Punkt* w;
    int dl;
public:
    Tablica(int len = 0);
    Tablica(Tablica& tab);
    Tablica(float* x, float* y, int len = 0);
    ~Tablica();
    void drukuj();
    void dodaj(Tablica& tab);
    bool porownajT(const Tablica& tab);
    Tablica operator=(Tablica& array);
    bool operator==(Tablica& array);
    void operator+=(Tablica& Tablica);
    Punkt& operator[](int element);
    friend ostream& operator<< (ostream& output, const Tablica& Tablica)
    {
        for (int i = 0; i < Tablica.dl; i++)
            output << Tablica.w[i];
        return output;
    }
};

Tablica::Tablica(int len)
{
    dl = len;
    w = new Punkt[len];
    for (int i = 0; i < len; i++)
        w[i] = Punkt(0, 0);
}
Tablica::Tablica(Tablica& tab)
{
    dl = tab.dl;
    w = new Punkt[dl];
    for (int i = 0; i < dl; i++)
        w[i] = Punkt(tab.w[i]);
}
Tablica::Tablica(float* x, float* y, int len)
{
    dl = len;
    w = new Punkt[len];
    for (int i = 0; i < len; i++)
        w[i] = Punkt(x[i], y[i]);
}

Tablica::~Tablica()
{
    delete[] w;
}

void Tablica::drukuj()
{
    for (int i = 0; i < dl; i++)
        w[i].drukujP();
    cout << endl;
}

void Tablica::dodaj(Tablica& tab)
{
    int licznik;
    if (tab.dl > dl)
        licznik = dl;
    else
        licznik = tab.dl;
    for (int i = 0; i < licznik; i++)
        w[i].dodaj(tab.w[i]);
}

bool Tablica::porownajT(const Tablica& w)
{
    if (dl != w.dl)
        return false;
    else
    {
        int i = dl - 1;
        while (i > -1 && this->w[i].porownajP(w.w[i]))
            i--;
        if (i == -1)
            return true;
        else
            return false;
    }
}

Tablica Tablica::operator=(Tablica& array)
{
    bool isEqual = this->porownajT(array);
    if (isEqual)
        return *this;
    for (int i = 0; i < array.dl; i++)
        this->w[i] = array.w[i];
    return *this;
}

bool Tablica::operator==(Tablica& array)
{
    return this->porownajT(array);
}

void Tablica::operator+=(Tablica& Tablica)
{
    int lenghtToUse;
    if (dl < Tablica.dl)
        lenghtToUse = dl;
    else
        lenghtToUse = Tablica.dl;
    for (int i = 0; i < lenghtToUse; i++)
        w[i] += Tablica.w[i];
}

Punkt& Tablica::operator[](int element)
{
    return w[element];
}

class Wektor : public Punkt
{
    float dlugosc;
    float kierunek;
public:
    Wektor();
    Wektor(float x, float y);
    Wektor(const Wektor& w);
    void dodaj(Punkt& p);
    void dodaj(Punkt* p);
    void drukujW();
    bool porownajW(const Punkt& p) const;
    bool operator==(Punkt& p) const;
    bool operator==(const Punkt& p) const;
    float getDlugosc();
};

Wektor::Wektor() : dlugosc(0), kierunek(0) {}

Wektor::Wektor(float x_, float y_) : Punkt(x_, y_), dlugosc(sqrt(x_* x_ + y_ * y_)), kierunek(atan(y_ / x_)) {}

Wektor::Wektor(const Wektor& w) : Punkt(w.PodajX(), w.PodajY()), dlugosc(w.dlugosc), kierunek(w.kierunek) {}

void Wektor::dodaj(Punkt& p)
{
    Punkt::dodaj(p);
    dlugosc = sqrt(PodajX() * PodajX() + PodajY() * PodajY());
    kierunek = atan(PodajY() / PodajX());
}

void Wektor::dodaj(Punkt* p)
{
    Punkt::dodaj(p);
    dlugosc = sqrt(PodajX() * PodajX() + PodajY() * PodajY());
    kierunek = atan(PodajY() / PodajX());
}

void Wektor::drukujW()
{
    Punkt::drukujP();
    cout << "Dlugosc: " << dlugosc << ", Kierunek: " << kierunek << endl;
}

bool Wektor::porownajW(const Punkt& p) const
{
    return Punkt::porownajP(p);
}

bool Wektor::operator==(const Punkt& p) const
{
    return Punkt::porownajP(p);
}

float Wektor::getDlugosc()
{
    return dlugosc;
}

class TablicaWektorow
{
public:
    Wektor* w;
    int dl;
    TablicaWektorow(int dl_ = 0);
    TablicaWektorow(float* x, float* y, int dl_);
    ~TablicaWektorow();
    void drukuj();
};

TablicaWektorow::TablicaWektorow(int dl_)
{
    dl = dl_;
    w = new Wektor[dl];
}

TablicaWektorow::TablicaWektorow(float* x, float* y, int dl_)
{
    dl = dl_;
    w = new Wektor[dl];
    for (int i = 0; i < dl; i++)
        w[i] = Wektor(x[i], y[i]);
}

TablicaWektorow::~TablicaWektorow()
{
    delete[] w;
}

void TablicaWektorow::drukuj()
{
    for (int i = 0; i < dl; i++)
        w[i].drukujP();
    cout << endl;
}

class TabWektorowSort : public TablicaWektorow
{
public:
    TabWektorowSort(TablicaWektorow& tab);
    void sort(int dl);
    void wstaw(Wektor& w);
    TabWektorowSort* operator=(Wektor& w);
};

TabWektorowSort::TabWektorowSort(TablicaWektorow& tab)
{
    dl = tab.dl;
    w = tab.w;
    sort(dl);
}

void TabWektorowSort::sort(int dl)
{
    for (int i = 0; i < dl - 1; i++)
    {
        int idxMax = 0;
        for (int j = 1; j < dl - i; j++)
        {
            if (w[j].getDlugosc() > w[idxMax].getDlugosc())
                idxMax = j;
        }
        Wektor temp = w[idxMax];
        w[idxMax] = w[dl - (i + 1)];
        w[dl - (i + 1)] = temp;
    }
}

void TabWektorowSort::wstaw(Wektor& w)
{
    int dl = this->dl + 1;
    Wektor* tab = new Wektor[dl];
    for (int i = 0; i < this->dl; i++)
        tab[i] = this->w[i];
    tab[dl - 1] = w;
    this->w = tab;
    this->dl = dl;
    sort(dl);
}

TabWektorowSort* TabWektorowSort::operator=(Wektor& w)
{
    TabWektorowSort::wstaw(w);
    return this;
}

int main()
{
    Wektor wektor1(40, 40);
    Wektor wektor2(15, 15);
    TablicaWektorow tab(2);
    tab.w[0] = wektor1;
    tab.w[1] = wektor2;
    TabWektorowSort TabSort(tab);
    TabSort.drukuj();
    Wektor wektor3(10, 10);
    TabSort.wstaw(wektor3);
    cout << "___________________" << "\n";
    TabSort.drukuj();
    Wektor wektor4(25, 25);
    TabSort = wektor4;
    TabSort.drukuj();
}