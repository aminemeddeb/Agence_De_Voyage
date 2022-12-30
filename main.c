#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
struct date{
    int j;
    int m;
    int an;
};
struct voy{
int id;
char dest[100] ;
struct date ddep;
struct date dar;
char hotel[100] ;
int duree;
char desc[2000];
char visa[3];
int prix;

};
void ajouter(struct voy tab[100],int *n){
    struct voy v;
    printf("Entrer l'id du voyage : ");
    scanf("%i",&v.id);
    printf("Entrer la destination du voyage : ");
    scanf("%s",v.dest);
    do{
        printf("Entrer la date du depart du voyage (jj/mm/aaaa): ");
        scanf("%i/%i/%i",&v.ddep.j,&v.ddep.m,&v.ddep.an);}
    while((v.ddep.j>31)||(v.ddep.m>12)||(v.ddep.an<1000)||(v.ddep.j<01)||(v.ddep.m<01)||(v.ddep.an>4000));
    do{
    printf("Entrer la date d'arriver du voyage (jj/mm/aaaa) : ");
    scanf("%i/%i/%i",&v.dar.j,&v.dar.m,&v.dar.an);}
    while((v.dar.j>31)||(v.dar.m>12)||(v.dar.an<1000)||(v.dar.j<01)||(v.dar.m<01)||(v.dar.an>4000));
    printf("Entrer l'hotel du voyage : ");
    scanf("%s",v.hotel);
    printf("Visa demandée (oui/non) : ");
    scanf("%s",v.visa);
    /*
        durée a faire
    */
    printf("Entrer la description du voyage : ");
   scanf("%s",v.desc);

    printf("Entrer le prix du voyage : ");
    scanf("%i",&v.prix);
    tab[*n]=v;
    *n= *n+1;/*
    printf("Entrer l'identifiant du voyage désiré : ");
    int a;
    scanf("%i",&a);
    affdesc(tab,n,a);
    printf("n= %i",n);*/
}
void affdesc(struct voy tab[100],int n,int iden){
    for(int i=0;i<n;i++){
        if(iden == tab[i].id)
            {printf("%s\n",tab[i].desc);}
    }

}
void supp(struct voy tab[100],int iden,int *n){
    for(int i=0;i<*n;i++){
        if ((tab[i].id == iden)&&(i<*n-1)){
            for(int j=i;j<*n-1;j++)
                tab[j]=tab[j+1];
            *n=*n-1;
            break;
        }
        else if(tab[i].id == iden)
            *n=*n-1;
    }

}
void recherche(struct voy tab[100],struct date dd,struct date da,int n){
    for(int i=0;i<n;i++){
            int test1,test2;
            test1=0;
            test2=0;
            if (tab[i].ddep.an>dd.an)
                test1=1;
            else if (tab[i].ddep.an==dd.an){
                if((tab[i].ddep.m>dd.m))
                    test1=1;
                else if(tab[i].ddep.m==dd.m)
                    if(tab[i].ddep.j>=dd.j)
                        test1=1;
                    else
                        test1=0;
                else
                    test1=0;}
            else
                test1=0;
            if (tab[i].dar.an<da.an)
                test2=1;
            else if (tab[i].dar.an==da.an){
                if((tab[i].dar.m<da.m))
                    test2=1;
                else if(tab[i].dar.m==da.m)
                    if(tab[i].dar.j<=da.j)
                        test2=1;
                    else
                        test2=0;
                else
                    test2=0;}
            else
                test2=0;









        if ((test1==1)&&(test2==1))
            printf("Le voyage ayant l identifiant %i est disponible \n",tab[i].id);

}}
void modifier(struct voy tab[100],int iden,int n){
    for(int i=0;i<n;i++){
        if(tab[i].id==iden){
                struct voy v;

    printf("Entrer la nouvelle destination du voyage : ");
    scanf("%s",v.dest);
    do{
        printf("Entrer la nouvelle date du depart du voyage (jj/mm/aaaa): ");
        scanf("%i/%i/%i",&v.ddep.j,&v.ddep.m,&v.ddep.an);}
    while((v.ddep.j>31)||(v.ddep.m>12)||(v.ddep.an<1000));
    do{
    printf("Entrer la nouvelle date d'arriver du voyage (jj/mm/aaaa) : ");
    scanf("%i/%i/%i",&v.dar.j,&v.dar.m,&v.dar.an);}
    while((v.dar.j>31)||(v.dar.m>12)||(v.dar.an<1000));
    printf("Entrer le nouvel hotel du voyage : ");
    scanf("%s",v.hotel);
    printf("Visa demandee (oui/non) : ");
    scanf("%s",v.visa);
    /*
        durée a faire
    */
    printf("Entrer la nouvelle description du voyage : ");
    /*char buf[2000];
    gets(buf);
    v.desc=buf;*/
    scanf("%s",v.desc);

    printf("Entrer le nouveau prix du voyage : ");
    scanf("%i",&v.prix);
    tab[i]=v;

        }
    }

}



int main()
{
    int n;
    int a,b,c;
    n=0;
    int choix;
    system ("COLOR F2");

    struct voy tab[100];
    printf("\n           ________                _       ______       _____          _      ________    _____ \n");
    printf("\\      /  |        |    \\   /     / \\     |	 |     |         *    / \\    |        |  |     |\n");
    printf(" \\    /   |        |     \\ /     /___\\    |   _____    |______   *   /___\\   |        |  |_____|__            \n");
    printf("  \\  /    |        |      |     /     \\   |        |   |         *  /     \\  |        |  |        | \n");
    printf("   \\/     |________|      |    /       \\  |_______ |   |_______  * /       \\ |________|  |________|  \n");
    printf("------------------------------------------------------------------------\n(1) Ajouter un voyage. \n(2) Afficher la description d un voyage. \n(3) Supprimer un voyage.\n(4) Modifier un voyage.\n(5) Recherche des voyages disponibles selon des dates precises.\n(6) Details sur l'application. \n(-) Autre caractere pour quitter.\n------------------------------------------------------------------------\n");    printf("Entrer votre choix. ");
    scanf("%i",&choix);
    while((choix>0)&&(choix<7))

    {   printf("\n");
        switch (choix){
        case 1: ajouter(tab,&n);
        break;
        case 2:

        printf("Entrer l'identifiant du voyage desire : ");
        scanf("%i",&a);
        affdesc(tab,n,a);
        break;
        case 3:
        {

        printf("Entrer l'identifiant du voyage qui sera supprimé : ");
        scanf("%i",&b);
        supp(tab,b,&n);
        }
        break;

        case 4 :{
            printf("Entrer l'identifiant du voyage qui sera modifie : ");
            scanf("%i",&c);
            modifier(tab,c,n);
        }
        break;
        case 5:{
            struct date dd;
            printf("Entrer les dates desires \nDate de debut de periode : ");
            scanf("%i/%i/%i",&dd.j,&dd.m,&dd.an);
            struct date dar;
            printf("Date de fin de periode : ");
            scanf("%i/%i/%i",&dar.j,&dar.m,&dar.an);
            recherche(tab,dd,dar,n);

        }
        break;
        case 6:{
            printf("Agence_De_Voyage\nNotre projet 'Voyage A.O.B.' est une application cmd qui est destinee a gerer une base de donnees d'une agence\n de voyages.\n\n'Voyage A.O.B.'offre plusieurs fonctionnalites citees ci-dessous:\n1- Ajouter un voyage.\n2- Afficher la description d’un voyage.\n3- Supprimer un voyage.\n4- Modifier un voyage.\n5- Recherche des voyages disponibles selon des dates precises.\n6- Details.\n Conditions d'utilisation a respecter :\n\n-Pour remplir les champs avec un paragraphe, s'il vous plait utilisez le caractere'_' au lieu de l'espace ' ' pour ne\npas avoir de problemes en cours d'execution du programme.\nN.B: On a essayer d'utiliser la fonction 'gets()' et 'fgets()' mais on a eu un probleme d'execution.\n-Pour entrer les champs contenant une date, s'il vous plat inserez la date sous ce format: jj/mm/aaaa.\n\nOn espere que votre experience en utilisant notre application, travaille avec beaucoup de passion et assiduite, soit agreable.\n\n");
        }
        break;

        }
        printf("------------------------------------------------------------------------\n(1) Ajouter un voyage. \n(2) Afficher la description d un voyage. \n(3) Supprimer un voyage.\n(4) Modifier un voyage.\n(5) Recherche des voyages disponibles selon des dates precises.\n(6) Details sur l'application. \n(-) Autre caractere pour quitter.\n------------------------------------------------------------------------\n");
        printf("Entrer votre choix. ");
        scanf("%i",&choix);
    }
    printf("Merci pour votre temps cher client!\nA bientot! ");
    getch();
    return 0;}


