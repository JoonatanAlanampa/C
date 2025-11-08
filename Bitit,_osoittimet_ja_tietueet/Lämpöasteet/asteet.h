#ifndef ASTEET_H_INCLUDED
#define ASTEET_H_INCLUDED

enum Asteikko
{
    Celsius,
    Fahrenheit,
    Kelvin
};

typedef enum Asteikko Asteikko;

struct Lampotila
{
    float lampotila;
    Asteikko asteikko;
};

typedef struct Lampotila Lampotila;

float muunna(Lampotila a, Asteikko b);

float erotus(Lampotila a, Lampotila b, Asteikko c);

#endif /* ASTEET_H_INCLUDED */
