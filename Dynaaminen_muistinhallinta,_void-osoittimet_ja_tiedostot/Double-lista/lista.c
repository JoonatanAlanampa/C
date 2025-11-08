#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

DblSolmu * ds_luo(double data, DblSolmu *seur)
{
  DblSolmu *ds = malloc(sizeof(DblSolmu));
  ds->data = data;
  ds->seur = seur;
  return ds;
}

DblLista * dl_luo(void)
{
  DblLista *dl = malloc(sizeof(DblLista));
  dl->n = 0;
  dl->paa = NULL;
  return dl;
}

void dl_tuhoa(DblLista *dl)
{
  while(dl->n > 0)
  {
    dl_poistaEdesta(dl);
  }
  free(dl);
}

DblSolmu * dl_lisaaEteen(DblLista *dl, double arvo)
{
  dl->paa = ds_luo(arvo, dl->paa);
  dl->n += 1;
  return dl->paa;
}

double dl_poistaEdesta(DblLista *dl)
{
  double arvo = 0;
  if(dl->n > 0)
  {
    DblSolmu *vanhaPaa = dl->paa;
    arvo = dl->paa->data;
    dl->paa = dl->paa->seur;
    free(vanhaPaa);
    dl->n -= 1;
  }
  return arvo;
}

void dl_tulosta(const DblLista *lista)
{
  DblSolmu *s;
  printf("Lista:");
  for(s = lista->paa; s != NULL; s = s->seur)
  {
    printf(" %.1f", s->data);
  }
  printf("\n");
}

double dl_alkio(const DblLista *lista, size_t i)
{
    size_t j;

    DblSolmu *s = lista->paa;

    if(i>=lista->n)
    {
        return 0;
    }

    for(j=0; j<i; j++)
    {
        s=s->seur;
    }

    return s->data;
}

DblSolmu * dl_lisaa(DblLista *lista, size_t i, double arvo)
{
    size_t j;

    DblSolmu *s=lista->paa, *e=NULL;

    DblSolmu *uusi = ds_luo(arvo, NULL);

    if(i==0 || lista->paa==NULL)
    {
        uusi->seur = lista->paa;
        lista->paa = uusi;
    }
    else
    {
        for(j=0; j<i && s!=NULL; j++)
        {
            e = s;
            s = s->seur;
        }
        e->seur = uusi;
        uusi->seur = s;
    }

    lista->n++;
    return uusi;
}

double dl_poista(DblLista *lista, size_t i)
{
    double tmp;

    size_t j;

    DblSolmu *s = lista->paa, *e=NULL;

    if(i>=lista->n)
    {
        return 0;
    }

    for(j=0; j<i; j++)
    {
        e=s;
        s=s->seur;
    }

    tmp=s->data;

    if(e!=NULL)
    {
        e->seur = s->seur;
    }
    else
    {
        lista->paa = s->seur;
    }

    free(s);

    lista->n--;

    return tmp;
}
