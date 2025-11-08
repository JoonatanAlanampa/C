#include "asteet.h"

float muunna(Lampotila a, Asteikko b)
{
    if (a.asteikko == b)
    {
        return a.lampotila;
    }

    if (a.asteikko == Celsius)
    {
        if (b == Fahrenheit)
        {
            return a.lampotila * 1.8 + 32;
        }
        else if (b == Kelvin)
        {
            return a.lampotila + 273.15;
        }
    }
    else if (a.asteikko == Fahrenheit)
    {
        if (b == Celsius)
        {
            return (a.lampotila - 32) / 1.8;
        }
        else if (b == Kelvin)
        {
            return (a.lampotila - 32) / 1.8 + 273.15;
        }
    }
    else if (a.asteikko == Kelvin)
    {
        if (b == Celsius)
        {
            return a.lampotila - 273.15;
        }
        else if (b == Fahrenheit)
        {
            return (a.lampotila - 273.15) * 1.8 + 32;
        }
    }
    return -1;

}

float erotus(Lampotila a, Lampotila b, Asteikko c)
{
    float muutettu_b_lampotila = muunna(b, a.asteikko);
    float erotus_lampotila = a.lampotila - muutettu_b_lampotila;

    Lampotila erotus_temp;
    erotus_temp.lampotila = erotus_lampotila;
    erotus_temp.asteikko = a.asteikko;

    if(a.asteikko==Kelvin || a.asteikko==Celsius)
    {
        if(c == Kelvin || c==Celsius)
        {
            return erotus_temp.lampotila;
        }
        else
        {
            return erotus_temp.lampotila*1.8;
        }
    }

    if(a.asteikko == Fahrenheit)
    {
        if(c==Kelvin || c==Celsius)
        {
            return erotus_temp.lampotila/1.8;
        }
    }

    return muunna(erotus_temp, c);

}
