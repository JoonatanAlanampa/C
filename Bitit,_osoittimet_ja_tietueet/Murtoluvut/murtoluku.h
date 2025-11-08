#ifndef MURTOLUKU_H_INCLUDED
#define MURTOLUKU_H_INCLUDED

struct Murtoluku
{
    int os;
    int nim;
};

typedef struct Murtoluku Murtoluku;

Murtoluku supistettuML(int os, int nim);

Murtoluku lisaaML(Murtoluku a, Murtoluku b);

Murtoluku vahennaML(Murtoluku a, Murtoluku b);

Murtoluku kerroML(Murtoluku a, Murtoluku b);

Murtoluku jaaML(Murtoluku a, Murtoluku b);

void tulostaML(Murtoluku ml);

#endif /* MURTOLUKU_H_INCLUDED */
