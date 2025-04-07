#include <stdio.h>
#include <string.h>

typedef struct
{
    char nom[50];
    char code[20];
    int jourfab, moisfab, anfab;
    int jourper, moisper, anper;
    float prix;
    int nbvendus;
    int stock;
} Medicament;

void echanger(Medicament *a, Medicament *b)
{
    Medicament temp = *a;
    *a = *b;
    *b = temp;
}

void trier_par_peremption(Medicament tab[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            Medicament a = tab[j];
            Medicament b = tab[j + 1];
            if (a.anper > b.anper)
            {
                echanger(&tab[j], &tab[j + 1]);
            }
            else if (a.anper == b.anper)
            {
                if (a.moisper > b.moisper)
                {
                    echanger(&tab[j], &tab[j + 1]);
                }
                else if (a.moisper == b.moisper)
                {
                    if (a.jourper > b.jourper)
                    {
                        echanger(&tab[j], &tab[j + 1]);
                    }
                }
            }
        }
    }
}

void initialiser_medicaments(Medicament tab[], int *n)
{
    *n = 4;

    strcpy(tab[0].nom, "Doliprane");
    strcpy(tab[0].code, "DOL123");
    tab[0].jourfab = 10; tab[0].moisfab = 1; tab[0].anfab = 2022;
    tab[0].jourper = 10; tab[0].moisper = 1; tab[0].anper = 2025;

    strcpy(tab[1].nom, "Efferalgan");
    strcpy(tab[1].code, "EFF456");
    tab[1].jourfab = 5; tab[1].moisfab = 6; tab[1].anfab = 2021;
    tab[1].jourper = 5; tab[1].moisper = 6; tab[1].anper = 2024;

    strcpy(tab[2].nom, "Spasfon");
    strcpy(tab[2].code, "SPA789");
    tab[2].jourfab = 12; tab[2].moisfab = 3; tab[2].anfab = 2023;
    tab[2].jourper = 12; tab[2].moisper = 3; tab[2].anper = 2026;

    strcpy(tab[3].nom, "Ibuprofene");
    strcpy(tab[3].code, "IBU321");
    tab[3].jourfab = 1; tab[3].moisfab = 11; tab[3].anfab = 2020;
    tab[3].jourper = 1; tab[3].moisper = 11; tab[3].anper = 2023;
}

void afficher_medicaments(Medicament tab[], int n)
{
    int i;
    printf("\n--- Liste des medicaments tries par date de peremption ---\n");
    for (i = 0; i < n; i++)
    {
        printf("%s - Peremption : %02d/%02d/%04d\n", tab[i].nom, tab[i].jourper, tab[i].moisper, tab[i].anper);
    }
}

int main()
{
    Medicament tab[80];
    int n;

    initialiser_medicaments(tab, &n);
    trier_par_peremption(tab, n);
    afficher_medicaments(tab, n);

    return 0;
}
