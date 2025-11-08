#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "lista.h"

Solmu * s_luo(const void * data, size_t dataKoko, Solmu *seur)
{
  Solmu *ds = malloc(sizeof(Solmu));
  ds->data = malloc(dataKoko);
  memcpy(ds->data, data, dataKoko);
  ds->seur = seur;
  return ds;
}

Lista * ll_luo(size_t dataKoko, void (*tulostaArvo)(FILE *virta, const void *arvo))
{
  Lista *dl = malloc(sizeof(Lista));
  dl->n = 0;
  dl->paa = NULL;
  dl->tulostaArvo = tulostaArvo;
  dl->dataKoko = dataKoko;
  return dl;
}

void ll_tuhoa(Lista *dl)
{
  while(dl->n > 0)
  {
    ll_poistaEdesta(dl);
  }
  free(dl);
}

Solmu * ll_lisaaEteen(Lista *dl, const void *arvo)
{
  dl->paa = s_luo((void *)arvo, dl->dataKoko, dl->paa);
  dl->n += 1;
  return dl->paa;
}

void ll_poistaEdesta(Lista *dl)
{
  if(dl->n > 0)
  {
    Solmu *vanhaPaa = dl->paa;
    dl->paa = dl->paa->seur;
    free(vanhaPaa->data);
    free(vanhaPaa);
    dl->n -= 1;
  }
}

void ll_tulosta(const Lista *lista, FILE *virta)
{
    Solmu *s;
    if (lista->tulostaArvo == NULL)
    {
       return;
    }
    fprintf(virta, "Lista:");
    for(s = lista->paa; s != NULL; s = s->seur)
    {
    fprintf(virta, " ");
    lista->tulostaArvo(virta, s->data);
    }
    fprintf(virta, "\n");
}

Solmu * ll_moniLisaa(Lista *lista, size_t i, const void *arvo, ...)
{
    va_list ap;
    Solmu *edellinen = NULL;
    Solmu *nykyinen = lista->paa;
    size_t j;
    Solmu *ensimmainenUusiSolmu = NULL;
    Solmu *viimeinenUusiSolmu = NULL;
    const void *nykyinenArvo = arvo;
    size_t lisattyLkm = 0;
    Solmu *solmu;

    va_start(ap, arvo);

    for (j = 0; j < i && nykyinen != NULL; ++j)
    {
        edellinen = nykyinen;
        nykyinen = nykyinen->seur;
    }

    while (nykyinenArvo != NULL)
    {
        Solmu *uusiSolmu = s_luo(nykyinenArvo, lista->dataKoko, nykyinen);
        if (viimeinenUusiSolmu != NULL)
        {
            viimeinenUusiSolmu->seur = uusiSolmu;
        }
        viimeinenUusiSolmu = uusiSolmu;
        if (ensimmainenUusiSolmu == NULL)
        {
            ensimmainenUusiSolmu = uusiSolmu;
        }

        nykyinenArvo = va_arg(ap, const void *);
    }

    if (edellinen != NULL)
    {
        edellinen->seur = ensimmainenUusiSolmu;
    }
    else
    {
        lista->paa = ensimmainenUusiSolmu;
    }

    va_end(ap);

    for (solmu = ensimmainenUusiSolmu; solmu != nykyinen; solmu = solmu->seur)
    {
        ++lisattyLkm;
    }
    lista->n += lisattyLkm;

    return ensimmainenUusiSolmu;
}
