#include "Error.h"

void Blad(int RodzajBledu)
{
    switch (RodzajBledu)
    {
    case 1:
    {
        fputs("Niewlasciwe parametry.", stderr);
        break;
    }
    case 2:
    {
        fputs("Nie moge otworzyc pliku!", stderr);
        break;
    }
    case 3:
    {
        fputs("Plik jest pusty.", stderr);
        break;
    }
    case 4:
    {
        fputs("Blad alokacji pamieci.", stderr);
        break;
    }
    }
}