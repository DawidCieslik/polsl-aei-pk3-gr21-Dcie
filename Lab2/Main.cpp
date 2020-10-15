#include <iostream>
using namespace std;

class Punkt
{
    float x;
    float y;
public:
    Punkt() {}
    Punkt(Punkt& p)
    {
        x = p.x;
        y = p.y;
    }
    Punkt(float _x, float _y)
    {
        x = _x;
        y = _y;
    }

    Punkt& operator+=(Punkt& p)
    {
        x += p.x;
        y += p.y;
        return *this;
    }
    bool operator==(Punkt& p)
    {
        if (this->x != p.x) { return false; };
        if (this->y != p.y) { return false; };
        return true;
    }
    Punkt operator+(Punkt& p)
    {
        Punkt tmp;
        tmp.x = this->x + p.x;
        tmp.y = this->y + p.y;
        return tmp;
    }
    friend ostream& operator<< (ostream& wyjscie, const Punkt& p)
    {
        return wyjscie << "X: " << p.x << " Y: " << p.y << '\n';
    }
};


class Tablica
{
    Punkt* w;
    int dl;
public:
    Tablica(int len)
    {
        dl = len;
        w = new Punkt[len];
        for (int i = 0; i < len; i++)
            w[i] = Punkt(0, 0);
    }
    Tablica(Tablica& tab)
    {
        dl = tab.dl;
        w = new Punkt[dl];
        for (int i = 0; i < dl; i++)
            w[i] = Punkt(tab.w[i]);
    }
    Tablica(float* x, float* y, int len)
    {
        dl = len;
        w = new Punkt[len];
        for (int i = 0; i < len; i++)
            w[i] = Punkt(x[i], y[i]);
    }

    Tablica operator=(Tablica& array)
    {
        bool isEqual = this->porownaj(array);
        if (isEqual)
            return *this;
        for (int i = 0; i < array.dl; i++)
            this->w[i] = array.w[i];
        return *this;
    }
    bool operator==(Tablica& array)
    {
        return this->porownaj(array);
    }
    void operator+=(Tablica& Tablica)
    {
        int lenghtToUse;
        if (dl < Tablica.dl)
            lenghtToUse = dl;
        else
            lenghtToUse = Tablica.dl;
        for (int i = 0; i < lenghtToUse; i++)
            w[i] += Tablica.w[i];
    }
    friend ostream& operator<< (ostream& output, const Tablica& Tablica)
    {
        for (int i = 0; i < Tablica.dl; i++)
            output << Tablica.w[i];
        return output;
    }

    Punkt& operator[](int element)
    {
        return w[element];
    }

    bool porownaj(Tablica& array)
    {
        bool isEqual = false;
        if (array.dl != this->dl)
            return isEqual;
        for (int i = 0; i < array.dl; i++)
        {
            int isEqualPunkt = (w[i] == array.w[i]);
            if (isEqualPunkt == 0)
                return isEqual;
        }
        isEqual = true;
        return isEqual;
    }

    ~Tablica()
    {
        delete[] w;
    }
};

int main()
{
    Punkt test(3, 7);
    Punkt test2(9, 15);
    test += test2;
    cout << test;
    bool CzyRowne = test == test2;
    cout << CzyRowne << endl;
    Punkt p;
    p = test + test2;
    cout << p;

    cout << "-----------------" << endl;

    Tablica tablica1(5);

    float* tabX = new float[2];
    float* tabY = new float[2];
    tabX[0] = 6;
    tabY[0] = 6;
    tabX[1] = 5;
    tabY[1] = 5;
    Tablica tablica2(tabX, tabY, 2);
    Tablica tablica3(tablica2);
    bool CzyRowne2 = tablica1 == tablica2;
    cout << CzyRowne2 << endl;
    cout << tablica1;
    tablica1 += tablica2;
    cout << tablica1;
    Punkt p1 = tablica1[0];
    Punkt p2(2, 2);
    p1 + p2;
    cout << p1;

    return 0;
}