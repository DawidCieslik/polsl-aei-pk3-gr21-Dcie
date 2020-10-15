#include <iostream>

class Punkt
{
    float x;
    float y;
public:
    Punkt(Punkt& p);
    Punkt(float _x = 0, float _y = 0);
    void dodaj(Punkt& p);
    void dodaj(Punkt* p);
    void drukujP();
    bool porownajP(Punkt& p1, Punkt& p2);
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
    std::cout << "x: " << x << "\ty: " << y << "\n";
}

bool Punkt::porownajP(Punkt& p1, Punkt& p2)
{
    if (p1.x != p2.x || p1.y != p2.y)
        return false;
    else
        return true;
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
    bool porownajT(Tablica& tab);
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
    std::cout << std::endl;
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

bool Tablica::porownajT(Tablica& tab)
{
    bool CzyRowne = false;
    if (tab.dl != dl)
        return CzyRowne;
    for (int i = 0; i < tab.dl; i++)
    {
        int CzyRownePunkt = w[i].porownajP(w[i], tab.w[i]);
        if (CzyRownePunkt == 0)
            return CzyRowne;
    }
    CzyRowne = true;
    return CzyRowne;
}

int main()
{
    Punkt test(3, 7);
    Punkt test2(9, 15);
    Punkt* wsk = &test2;

    test.drukujP();
    test.dodaj(wsk);
    test.drukujP();
    test.dodaj(&test2);
    test.drukujP();
    std::cout << "-----------------" << std::endl;

    Tablica tablica1(5);
    tablica1.drukuj();

    float* tabX = new float[2];
    float* tabY = new float[2];
    tabX[0] = 6;
    tabY[0] = 6;
    tabX[1] = 5;
    tabY[1] = 5;
    Tablica tablica2(tabX, tabY, 2);
    Tablica tablica3(tablica2);
    tablica2.drukuj();
    tablica3.drukuj();

    bool CzyRowne = tablica2.porownajT(tablica3);
    std::cout << "Czy sa rowne: " << CzyRowne << std::endl << std::endl;

    tablica2.dodaj(tablica3);
    tablica2.drukuj();
    tablica3.drukuj();

    CzyRowne = tablica2.porownajT(tablica3);
    std::cout << "Czy sa rowne: " << CzyRowne << std::endl;

    return 0;
}