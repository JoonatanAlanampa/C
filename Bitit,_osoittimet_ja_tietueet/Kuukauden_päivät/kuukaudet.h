#ifndef KUUKAUDET_H_INCLUDED
#define KUUKAUDET_H_INCLUDED

enum
{
    TAMMIKUU,
    HELMIKUU,
    MAALISKUU,
    HUHTIKUU,
    TOUKOKUU,
    KESAKUU,
    HEINAKUU,
    ELOKUU,
    SYYSKUU,
    LOKAKUU,
    MARRASKUU,
    JOULUKUU
};

enum
{
    KK_LKM = 12
};

const char *KK_NIMET[KK_LKM];

const char KK_PAIVAT[2][KK_LKM];

int karkausvuosi(int vuosiluku);

char kkPituus(const char *kkNimi, int vuosiluku);

#endif /* KUUKAUDET_H_INCLUDED */
