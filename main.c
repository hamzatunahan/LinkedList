#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct komsu
{
    int plaka_komsu;

    struct komsu *next;
};

struct sehir
{
    int plaka;
    char *ad;
    char *bolge;
    int komsu_sayisi;

    struct sehir *next;
    struct sehir *prev;

    struct komsu *sonraki;
};

struct sehir *ilk=NULL, *son=NULL;
struct komsu *kilk=NULL, *kson=NULL;
struct komsu *k1ilk=NULL, *k1son=NULL;
int satir;

void SonaEkle(int pl,char *Ad[],char *Bolge[],int komsusayi)
{
    // FILE *cikti;
    // cikti=fopen("cikti.txt","a");
    struct sehir *yeni = (struct sehir*) malloc(sizeof(struct sehir));
    while(yeni->next!=NULL)
    {
        yeni=yeni->next;
    }

    yeni->plaka=pl;
    yeni->ad=Ad;
    yeni->bolge=Bolge;
    yeni->komsu_sayisi=komsusayi;

    if(ilk==NULL)
    {
        ilk=yeni;
        son=yeni;
        son->next=son;
        son->prev=ilk;
    }
    else
    {
        son->next=yeni;
        yeni->prev=son;
        yeni->next=ilk;
        ilk->prev=yeni;
        son=yeni;
    }
}
void Listele2(int a[],int komsu_sayi[],int satir)
{
    FILE *cikti;
    cikti=fopen("cikti.txt","a");
    struct sehir *iter = (struct sehir*)malloc(sizeof(struct sehir));
    struct komsu *yeni;
    iter=ilk;
    yeni=iter->sonraki;
    int j=0;
    int i=0;
    int z=0;
    for(j=0; j<satir; j++)
    {

        yeni=kilk;
        printf("%d  \t",iter->plaka);
        printf("%s  ",iter->ad);
        printf("\t komsu sayisi :%d  ",iter->komsu_sayisi);
        printf("\t%s\n",iter->bolge);
        fprintf(cikti,"%d  \t",iter->plaka);
        fprintf(cikti,"%s  ",iter->ad);
        fprintf(cikti,"\t komsu sayisi :%d  ",iter->komsu_sayisi);
        fprintf(cikti,"\t%s\n",iter->bolge);
        //printf("\n %d.Komsulari \n",j+1);
        // fprintf(cikti,"\n %d.Komsulari \n",j+1);
        for(i=0; i<(komsu_sayi[j]); i++)
        {
            yeni = (struct komsu*) malloc(sizeof(struct komsu));

            yeni->plaka_komsu=a[z+i];
            printf("--> %d ",yeni->plaka_komsu);
            fprintf(cikti,"--> %d ",yeni->plaka_komsu);
            // fprintf(cikti,"--> %d \n",yeni->plaka_komsu);
            yeni=yeni->next;
        }
        printf("\n\n\n");
        fprintf(cikti,"\n\n\n");

        iter=iter->next;
        z+=komsu_sayi[j];
    }
    fclose(cikti);
}



void Listele()
{
    FILE *cikti;
    cikti=fopen("cikti.txt","a");
    fopen("cikti","a");
    struct sehir *liste=ilk;

    //int uzunluk;
    while(liste->next!=ilk)
    {

        printf("%d  \t",liste->plaka);
        printf("%s  ",liste->ad);
        printf("\t komsu sayisi :%d  ",liste->komsu_sayisi);
        printf("\t%s\n",liste->bolge);
        fprintf(cikti,"\t%d",liste->plaka);
        fprintf(cikti,"\t|->\t\t%s\t",liste->ad);
        fprintf(cikti,"|->\t\t%d",liste->komsu_sayisi);
        fprintf(cikti,"\t|->\t\t%s\n",liste->bolge);



        liste=liste->next;
    }
    printf("%d  \t ",liste->plaka);
    printf("%s  ",liste->ad);
    printf("\t komsu sayisi :%d  ",liste->komsu_sayisi);
    printf("\t%s\n",liste->bolge);
    fprintf(cikti,"\t%d",liste->plaka);
    fprintf(cikti,"\t|->\t\t%s",liste->ad);
    fprintf(cikti,"\t|->\t%d",liste->komsu_sayisi);
    fprintf(cikti,"\t|->%s\n",liste->bolge);
    fclose(cikti);

}

void Sil(int x)
{

    FILE *cikti;
    cikti=fopen("cikti.txt","a");

    struct sehir *sil=ilk;
    int kar=0;
    struct sehir *liste=ilk;
    while(liste->next!=ilk)
    {
        if(liste->plaka==x)
        {
            kar=1;
            break;
        }
        liste=liste->next;
    }
    if(liste->plaka==x)
    {
        kar=1;
    }
    if(kar==1)
    {
        while(sil!=NULL)
        {
            if(sil->plaka==x)
                break;
            else
            {
                sil=sil->next;
            }
        }
        if(sil!=NULL)
        {
            if(sil==ilk)
            {
                sil->prev->next=sil->next;
                sil->next->prev=sil->prev;
                ilk=ilk->next;
            }
            else if(sil==son)
            {
                sil->prev->next=sil->next;
                sil->next->prev=sil->prev;
                son=son->prev;
            }
            else
            {
                sil->prev->next=sil->next;
                sil->next->prev=sil->prev;
            }
            fprintf(cikti,"silinen plaka :%d\n",x);

            free(sil);
            fopen("cikti","a");
            Sirala();
            Listele();

        }
        //fopen("cikti","a");

    }
    else
    {
        printf("\n --->%d boyle bir plaka yok! <---\n",x);
        fprintf(cikti,"\n --->%d boyle bir plaka yok! <---\n",x);

        //return 0;
    }
    fclose(cikti);
}
void silBastan()
{
    FILE *cikti;
    cikti=fopen("cikti.txt","a");
    if(kilk != NULL)
    {
        if(kilk->next != NULL)
        {
            struct komsu* temp2 = kilk;
            kilk = kilk->next;
            free(temp2);
        }
        else
        {
            free(kilk);
            kilk = NULL;
        }
    }
    else
    {
        printf("\nSilinecek yok !");
        fprintf(cikti,"\nSilinecek yok !");
    }
    fclose(cikti);
}

void kSil(int x,int komsu_sayi[],int satir)
{
    FILE *cikti;
    cikti=fopen("cikti.txt","a");
    struct sehir *iter = (struct sehir*)malloc(sizeof(struct sehir));
    struct komsu *yeni;

    int j=0;
    int i=0;
    int z=0;
    for(j=0; j<satir; j++)
    {
        yeni=iter->sonraki;
        printf("\n %d.Komsulari \n",j+1);
        fprintf(cikti,"\n %d.Komsulari \n",j+1);
        for(i=0; i<(komsu_sayi[j]); i++)
        {
            if(kilk->plaka_komsu==x)
            {
                silBastan();
            }
            else
            {
                yeni = kilk;
                while(yeni->next->plaka_komsu != x)
                {
                    yeni = yeni->next;
                }
                struct komsu*temp1 = yeni->next->next;
                struct komsu* temp2 = yeni;
                free(yeni->next);
                temp2->next = temp1;
            }
        }
        iter=iter->next;
        z+=komsu_sayi[j];
    }
    fclose(cikti);
}

void komsu_Listele(struct komsu *ara)
{
    FILE *cikti;
    cikti=fopen("cikti.txt","a");

    while (ara != NULL)
    {
        printf("|->|%d\n", ara->plaka_komsu);
        fprintf(cikti,"|->|%d\n", ara->plaka_komsu);
        ara = ara->next;
    }
    fclose(cikti);
}


void kBasaEkle(int a)
{
    //FILE *cikti;
    // cikti=fopen("cikti.txt","a");
    struct komsu *yeni = (struct komsu*) malloc(sizeof(struct komsu));
    yeni->plaka_komsu=a;
    if(kilk==NULL)
    {
        kilk=yeni;
        kson=yeni;
        kson->next=NULL;
    }
    else
    {
        yeni->next=kilk;
        kilk=yeni;
    }
}
void kSonaEkle(int a)
{
    //FILE *cikti;
    // cikti=fopen("cikti.txt","a");
    struct komsu *yeni = (struct komsu*) malloc(sizeof(struct komsu));

    yeni->plaka_komsu=a;
    if(kilk==NULL)
    {
        kilk=yeni;
        kson=yeni;
        kson->next=NULL;
    }
    else
    {
        kson->next=yeni;
        kson=yeni;
        kson->next=NULL;
    }
}
/*int kEkle(int eklenen,int eklenti,int komsu_sayi[])
{
  struct sehir iter = (struct sehir)malloc(sizeof(struct sehir));
    struct komsu *yeni=kilk;
yeni=iter->sonraki;
    int j=0;
    int i=0;
    int z=0;
    iter=ilk;
    for(j=0; j<eklenen-1; j++)
    {
        iter=iter->next;
    }
    printf("\n BRA %d BRASDAD\n ",iter->plaka);
    //yeni=iter->sonraki;

    while(i!=komsu_sayi[i])
    {
        //yeni = (struct komsu*) malloc(sizeof(struct komsu));
          yeni=yeni->next;

         // yeni->plaka_komsu=eklenti;

         // printf("--> aha %d \n",yeni->plaka_komsu);
          i++;
    }


yeni = (struct komsu*) malloc(sizeof(struct komsu));
        yeni->plaka_komsu=eklenti;
        printf("deneme2");
        komsu_sayi[eklenen-1]+=1;
         printf("--> aha %d \n",yeni->plaka_komsu);


        // fprintf(cikti,"--> %d \n",yeni->plaka_komsu);
        return komsu_sayi[eklenen-1];
}*/


void komsu_ekle(int a[],int komsu_sayi[],int satir)
{
    FILE *cikti;
    cikti=fopen("cikti.txt","a");

    struct sehir *iter = (struct sehir*)malloc(sizeof(struct sehir));
    struct komsu *yeni;
    iter=ilk;
    yeni=iter->sonraki;
    int j=0;
    int i=0;
    int z=0;
    for(j=0; j<satir; j++)
    {

        yeni=kilk;

        // printf("\n %d.Komsulari \n",j+1);
        // fprintf(cikti,"\n %d.Komsulari \n",j+1);
        for(i=0; i<(komsu_sayi[j]); i++)
        {
            yeni = (struct komsu*) malloc(sizeof(struct komsu));

            yeni->plaka_komsu=a[z+i];
            // printf("--> %d \n",yeni->plaka_komsu);
            // fprintf(cikti,"--> %d \n",yeni->plaka_komsu);
            yeni=yeni->next;
        }
        iter=iter->next;
        z+=komsu_sayi[j];
    }
    fclose(cikti);
}
void bonusKriter(int altSinir,int Ustsinir,int satir,char komsu_matris[][20],int komsusayisi[])
{
    FILE *cikti;
    cikti=fopen("cikti.txt","a");
    struct sehir *kriter = ilk;
    int temp;
    if(altSinir>Ustsinir)
    {
        temp=altSinir;
        altSinir=Ustsinir;
        Ustsinir=temp;
    }

    while(kriter->next!=ilk)
    {
        if(altSinir<=kriter->komsu_sayisi && kriter->komsu_sayisi<=Ustsinir)
        {
            printf("%d  \t",kriter->plaka);
            printf("%s  ",kriter->ad);
            printf("\t komsu sayisi :%d  ",kriter->komsu_sayisi);
            printf("\t%s\n",kriter->bolge);
            fprintf(cikti,"%d",kriter->plaka);
            fprintf(cikti,"\t|->|%s",kriter->ad);
            fprintf(cikti,"\t|->|:%d",kriter->komsu_sayisi);
            fprintf(cikti,"\t|->|%s\n",kriter->bolge);



            kriter=kriter->next;
        }
        else
        {
            kriter=kriter->next;
        }

    }
    if(altSinir<=kriter->komsu_sayisi && kriter->komsu_sayisi<=Ustsinir)
    {
        printf("%d  \t ",kriter->plaka);
        printf("%s  ",kriter->ad);
        printf("\t komsu sayisi :%d  ",kriter->komsu_sayisi);
        printf("\t%s\n",kriter->bolge);
        fprintf(cikti,"%d",kriter->plaka);
        fprintf(cikti,"\t|->|%s",kriter->ad);
        fprintf(cikti,"\t|->|:%d",kriter->komsu_sayisi);
        fprintf(cikti,"\t|->|%s\n",kriter->bolge);

    }


    /* kriter=ilk;
     char sehir1,sehir2;
     printf("Aranacak 1.sehiri giriniz\n");
     scanf("%s",&sehir1);
     printf("Aranacak 2.sehiri giriniz\n");
     scanf("%s",&sehir2);
     int i=0,j=0,z=0;
     for(i=0; i<satir; i++)      /** Tum sehirleri dolasir
     {

         for(j=0; j<=komsusayisi[i]; j++)    /**dolasýlan sehirlerin komsu sayisi kadar dongude doner
         {


             if(komsu_matris[i][j]==sehir1)  /**1.sehre komsu sehir bulununca girer (komsu olan sehir i sehri)
             {
                 printf("sehir1: %s \n",sehir1);

                 for(z=0; z<=komsusayisi[i]; z++)    /**i þehrinin komsularinda aradigimiz 2. sehiri arar
                 {
                     // printf("komsu_matris: %s\n",komsu_matris[i][z]);
                     if(komsu_matris[i][z]==sehir2)  /**i sehirinin komsularinda aradigimiz 2. sehiri buldugunda girer
                     {
                         printf("DENEME");

                     }

                 }
             }
         }

     }*/

    fclose(cikti);

}

void secBolge(char bolge[])
{
    FILE *cikti;
    cikti=fopen("cikti.txt","a");

    struct sehir *list=ilk;

    while(list->next!=ilk)
    {
        if(strstr(bolge,list->bolge)!=0)
        {
            printf("%d  \t",list->plaka);
            printf("%s  ",list->ad);
            printf("\t  %d  ",list->komsu_sayisi);
            printf("%s\n",list->bolge);
            fprintf(cikti,"%d",list->plaka);
            fprintf(cikti,"\t|->|%s",list->ad);
            fprintf(cikti,"\t|->|%d ",list->komsu_sayisi);
            fprintf(cikti,"\t|->|%s\n",list->bolge);

            list=list->next;
        }
        else
            list=list->next;
    }
    if(strstr(bolge,list->bolge)!=0)
    {
        printf("%d  \t ",list->plaka);
        printf("%s  ",list->ad);
        printf("\t  %d  ",list->komsu_sayisi);
        printf("%s\n\n",list->bolge);
        fprintf(cikti,"%d",list->plaka);
        fprintf(cikti,"\t|->|%s",list->ad);
        fprintf(cikti,"\t|->|%d",list->komsu_sayisi);
        fprintf(cikti,"\t|->|%s\n",list->bolge);

    }
    fclose(cikti);
}
void komsuKriter(int x)
{
    FILE *cikti;
    cikti=fopen("cikti.txt","a");
    struct sehir *kriter = ilk;

    while(kriter->next!=ilk)
    {
        if(x<=kriter->komsu_sayisi)
        {
            printf("%d  \t",kriter->plaka);
            printf("%s  ",kriter->ad);
            printf("\t komsu sayisi :%d  ",kriter->komsu_sayisi);
            printf("\t%s\n",kriter->bolge);
            fprintf(cikti,"%d",kriter->plaka);
            fprintf(cikti,"\t |->| %s",kriter->ad);
            fprintf(cikti,"\t|->|%d",kriter->komsu_sayisi);
            fprintf(cikti,"\t|->|%s\n",kriter->bolge);


            kriter=kriter->next;
        }
        else
        {
            kriter=kriter->next;
        }

    }
    if(x<=kriter->komsu_sayisi)
    {
        printf("%d  \t ",kriter->plaka);
        printf("%s  ",kriter->ad);
        printf("\t komsu sayisi :%d  ",kriter->komsu_sayisi);
        printf("\t%s\n",kriter->bolge);
        fprintf(cikti,"%d|",kriter->plaka);
        fprintf(cikti,"  |->  %s",kriter->ad);
        fprintf(cikti,"  |->  %d  ",kriter->komsu_sayisi);
        fprintf(cikti,"  |->  %s\n",kriter->bolge);

    }
    fclose(cikti);
}
void Sirala()
{
//    FILE *cikti;
    // cikti=fopen("cikti.txt","a");
    int temp,temp4;
    char *temp2,*temp3;
    struct sehir *dolas=ilk;
    while(dolas->next!=ilk)
    {
        if(dolas->plaka>dolas->next->plaka)
        {
            temp=dolas->plaka;
            dolas->plaka=dolas->next->plaka;
            dolas->next->plaka=temp;
            temp2=dolas->ad;
            dolas->ad=dolas->next->ad;
            dolas->next->ad=temp2;
            temp3=dolas->bolge;
            dolas->bolge=dolas->next->bolge;
            dolas->next->bolge=temp3;
            temp4=dolas->komsu_sayisi;
            dolas->komsu_sayisi=dolas->next->komsu_sayisi;
            dolas->next->komsu_sayisi=temp4;
            dolas=ilk;

        }
        else
        {
            dolas=dolas->next;
        }

    }


}

struct sehir *Ara(int secim,int satir,int *komsu_sayi)
{
    FILE *cikti;

    cikti=fopen("cikti.txt","a");
    struct sehir *ara=ilk;
    int i=0,j=0;

    if(secim==1)
    {
        char arama[20];
        printf("Hangi sehiri aramak istiyorsunuz\n");
        //fprintf(cikti,"Hangi sehiri aramak istiyorsunuz\n");
        scanf("%s",&arama);
        while(ara->next!=ilk)
        {
            if(strstr(arama,ara->ad))
            {
                printf("plaka no: %d\n sehir adi:%s\n bolgesi: %s\n komsusayisi:%d",ara->plaka,ara->ad,ara->bolge,ara->komsu_sayisi);
                fprintf(cikti,"plaka no: %d\n sehir adi:%s\n bolgesi: %s\n komsusayisi:%d",ara->plaka,ara->ad,ara->bolge,ara->komsu_sayisi);
                return arama;
            }

            ara=ara->next;
            i++;
        }
        return 0;
    }
    else if(secim==2)
    {
        ara=ilk;
        int z,a,arama;
        struct komsu  *yeni=ara->sonraki;
        printf("Hangi plakayi aramak istiyorsunuz");
        //fprintf(cikti,"Hangi plakayi aramak istiyorsunuz");
        scanf("%d",&arama);
        while(i!=satir)
        {
            //printf("%d\n",ara->plaka);
            if((ara->plaka)==arama)
            {
                printf("plaka no: %d\n sehir adi:%s\n bolgesi: %s\n komsusayisi:%d\n",ara->plaka,ara->ad,ara->bolge,ara->komsu_sayisi);
                fprintf(cikti,"plaka no: %d  |->|  sehir adi:%s  |->|  bolgesi:%s  |->|  komsusayisi:%d\n",ara->plaka,ara->ad,ara->bolge,ara->komsu_sayisi);

                /*printf("komsuÇ: %s",ara->sonraki->plaka_komsu);
                // yeni=ara->sonraki;
                printf("\n Komsulari \n");
                for(a=0; a<ara->komsu_sayisi; a++)
                {
                    //yeni = (struct komsu*) malloc(sizeof(struct komsu));
                    printf("merhaba");
                    printf("--> %d \n",yeni->plaka_komsu);
                    printf("merhaba2\n");
                    komsu_Listele(yeni);

                    yeni=yeni->next;

                }

                while (yeni != NULL)
                {

                    komsu_Listele(yeni);
                    printf("->> %d\n", yeni->plaka_komsu);
                    yeni = yeni->next;
                }*/


                return arama;
            }
            ara=ara->next;
            i++;
        }
        return 0;
    }
    fclose(cikti);
}
int main()
{

    FILE *dosya;
    dosya=fopen("sehirler.txt","r");
    FILE *cikti;
    cikti=fopen("cikti.txt","w");
    if(dosya==NULL)
    {
        puts("sehirler.txt bulunamadi");
        exit(1);
    }
    fopen("cikti.txt","w");


    int plakalar[81];
    char dizi[100];
    char *sad[81][20];//sad[100][20]; sad[i]=strcpy(
    char *s_bolge[100][5];
    char komsular[500][20];
    int komsu_plakalar[500];
    char * pch;
    struct sehir *iter = (struct sehir*)malloc(sizeof(struct sehir));
    struct komsu *k = (struct komsu*)malloc(sizeof(struct komsu));

    int komsusayisi[81]= {0},sayac=0,j=0,z=0,i =0;

    //int satir=0;
    /*while((fgets(dizi,100,dosya))!=NULL){
        satir++;
    }*/

    fseek(dosya,-1L,SEEK_CUR);
    while((fgets(dizi,100,dosya))!=NULL)
    {
        satir++;
        // fgets(dizi,100,dosya);
        //printf("\n %s \n ",dizi);

        pch = strtok (dizi," , ");
        sayac=0;
        while (pch != NULL)
        {
            //printf ("\nsayac:%d  pch :: %s",sayac,pch);


            if(sayac==0)
            {
                plakalar[j]=atoi(pch);
                //printf(" BR %d \n",plakalar[j]);
            }
            else if(sayac==1)
            {
                strcpy(sad[j],pch);
                //printf(" BK %s \n",sad[j]);
            }
            else if(sayac==2)
            {
                strcpy(s_bolge[j],pch);
                //printf(" BK %s \n",s_bolge[j]);
            }
            else
            {
                komsusayisi[i]++;
                if(komsusayisi[i]==(sayac-2))
                {
                    strcpy(komsular[z],pch);
                    z++;
                }
                /*  k=iter->sonraki;
                  k->next->*/
            }


            pch = strtok (NULL,",""\n");
            sayac++;
        }
        SonaEkle(plakalar[j],sad[j],s_bolge[j],komsusayisi[i]);
        j++;
        //printf("\n olmasi gereken plaka: %s \n",dizi);
        i++;

    }
    //printf("\nsatir :%d\n",satir);
    j=0,z=0,i=0;
    int y=0;
    char komsu_matris[satir][20];
    for(i=0; i<satir; i++)
    {
        for(j=0; j<komsusayisi[i]; j++)
        {
            for(y=0; y<satir; y++)
            {
                // printf("sehir:: %s  komsu:%s\n",sad[y],komsular[z+j]);

                if(strcmp(sad[y],komsular[z+j])==0)
                {
                    //printf("komsular:: %d\n",plakalar[y]);
                    //kSonaEkle(plakalar[y]);
                    komsu_plakalar[z+j]=plakalar[y];
                    komsu_matris[i][j]=plakalar[y];
                }
            }

        }
        z+=komsusayisi[i];
    }
    komsu_ekle(komsu_plakalar,komsusayisi,satir);
    int secim=1,karar=0;
    Sirala();
    Listele2(komsu_plakalar,komsusayisi,satir);

    // komsusayisi[80]=kEkle(81,2,komsusayisi);

    // komsusayisi[80]=kEkle(81,3,komsusayisi);
    while(secim!=0)
    {
        fopen("cikti","w");
        printf("1-) Yeni Sehir ekle\n");
        printf("2-) Sehir veya komsu kaydi sil\n");
        printf("3-) Aranan sehrin veya plakanin sehir bilgileri ve komsu bilgilerini listele\n");
        printf("4-) Herhangi bir bolgede bulunan sehirlerin bilgilerini yazdir\n");
        printf("5-)  Belli bir komsu sayisi kriterine uyan sehirleri goster\n");
        printf("6-)  Bonus kriter\n");
        printf("0-)  CIKIS\n ");
        /*fprintf(cikti,"1-) Yeni Sehir ekle\n");
        fprintf(cikti,"2-) Sehir veya komsu kaydi sil\n");
        fprintf(cikti,"3-) Aranan sehrin veya plakanin sehir bilgileri ve komsu bilgilerini listele\n");
        fprintf(cikti,"4-) Herhangi bir bolgede bulunan sehirlerin bilgilerini yazdir\n");
        fprintf(cikti,"5-)  Belli bir komsu sayisi kriterine uyan sehirleri goster\n");
        fprintf(cikti,"6-)  Bonus kriter\n");
        fprintf(cikti,"0-)  CIKIS\n ");*/
        scanf("%d",&secim);
        printf("SECILEN:%d\n",secim);
        //fprintf(cikti,"SECILEN:%d\n",secim);







        fclose(cikti);
        switch(secim)
        {
        //fopen("cikti","a");

        case 1:
        {
            fprintf(cikti,"\n");

            int plaka2,komsusay;
            char *ad[20][20];
            char *bolge[20][20];
            struct sehir *liste=ilk;

            printf("Sehirin ismini giriniz  ");
            //fprintf(cikti,"Sehirin ismini giriniz  ");
            scanf("%s",&ad[karar]);
            printf("\nSehirin plakasini giriniz  ");
            //fprintf(cikti,"\nSehirin plakasini giriniz  ");
            scanf("%d",&plaka2);
            printf("\nSehirin bolgesini giriniz  ");
            //fprintf(cikti,"\nSehirin bolgesini giriniz  ");
            scanf("%s",&bolge[karar]);
            printf("\nSehirin komsu sayisini giriniz  ");
            //fprintf(cikti,"\nSehirin komsu sayisini giriniz  ");
            scanf("%d",&komsusay);
            printf("eklenecek::  %s  %d   %s   %d\n",ad[karar],plaka2,bolge[karar],komsusay);
            fprintf(cikti," %s  |->|  %d  |->|  %s  |->|  %d\n",ad,plaka2,bolge,komsusay);
            fclose(cikti);


            liste=ilk;
            int say=0;
            i=0;
            for(i=0; i<satir; i++)
            {

                if(strstr(ad[karar],liste->ad))
                {
                    printf(" \nSEHIR ADLARI AYNI\n");
                    fprintf(cikti," \nSEHIR ADLARI AYNI\n\n");
                    say++;
                    break;
                }
                else if((liste->plaka)==plaka2)
                {
                    printf(" \PLAKALAR AYNI \n");
                    fprintf(cikti," \PLAKALAR AYNI \n\n");
                    say++;
                    break;
                }
                liste=liste->next;
            }
            fclose(cikti);
            if(say==0)
            {
                fopen("cikti","a");
                fprintf(cikti,"%d eklendi",plaka2);
                fclose(cikti);
                SonaEkle(plaka2,ad[karar],bolge[karar],komsusay);
                Sirala();
                Listele();
            }

            karar++;
            fclose(cikti);
            break;
        }
        case 2:
        {
            int v;
            fopen("cikti.txt","a");
            printf("\nSilmek istediginiz plakayi giriniz : ");
            //fprintf(cikti,"\nSilmek istediginiz plakayi giriniz : ");
            scanf("%d",&v);
            Sil(v);
            /*if( !=0)
            {
                fopen("cikti","a");
                Sirala();
                Listele();
            }*/
            fclose(cikti);
            break;
        }
        case 3:
        {

            //Listele();
            fclose(cikti);
            Sirala();
            // Listele();
            fopen("cikti.txt","a");
            fprintf(cikti,"\n");
            int secim2;
            // printf("\n \t%d\n",satir);
            printf("Sehir aramak icin 1'e plaka aramak icin 2'ye basiniz\n");
            //fprintf(cikti,"\n \t%d\n",satir);
            //fprintf(cikti,"Sehir aramak icin 1'e plaka aramak icin 2'ye basiniz  ");
            scanf("%d",&secim2);
            if(Ara(secim2,satir,komsusayisi)==0)
            {
                printf("Sehir listede yok eklemek ister misiniz?");
                printf("\t Evet : 1  Hayir : 2\n");
                fprintf(cikti,"Sehir listede yok eklemek ister misiniz?");
                fprintf(cikti,"\t Evet : 1  Hayir : 2\n");

                int sec;
                int plaka2;
                char *ad[20][20];
                char *bolge[20][20];
                int komsusayisi2=0;
                scanf("%d",&sec);
                if(sec==1)
                {

                    struct sehir *liste=ilk;
                    // struct komsu *yeni=liste->sonraki;
                    printf("Plaka giriniz : ");
                    // fprintf(cikti,"Plaka giriniz : ");
                    scanf("%d",&plaka2);
                    printf("Sehrin adini giriniz : ");
                    // fprintf(cikti,"Sehrin adini giriniz : ");
                    scanf("%s",&ad[karar]);
                    printf("Bolgesini giriniz : ");
                    //fprintf(cikti,"Bolgesini giriniz : ");
                    scanf("%s",&bolge[karar]);
                    printf("Komsu sayisini giriniz:");
                    //fprintf(cikti,"Komsu sayisini giriniz:");
                    scanf("%d",&komsusayisi2);
                    // fprintf("%s  |->|  %d  |->|  %s  |->|  %d",ad,plaka2,bolge,komsusayisi2);

                    satir++;
                    printf("deneme");
                    // fclose(cikti);

                    fopen("cikti","a");


                    liste=ilk;
                    int say=0;
                    i=0;
                    for(i=0; i<satir; i++)
                    {

                        if(strstr(ad[karar],liste->ad))
                        {
                            printf(" \nSEHIR ADLARI AYNI\n");
                            fprintf(cikti," \nSEHIR ADLARI AYNI\n");
                            say++;
                            break;
                        }
                        else if((liste->plaka)==plaka2)
                        {
                            printf(" \PLAKALAR AYNI \n");
                            fprintf(cikti," \PLAKALAR AYNI \n");
                            say++;
                            break;
                        }
                        liste=liste->next;
                    }
                    fclose(cikti);
                    if(say==0)
                    {
                        SonaEkle(plaka2,ad[karar],bolge[karar],komsusayisi2);
                        Sirala();
                        Listele();
                    }

                    karar++;
                    fopen("cikti","a");
                }
                else if(sec==2)
                {
                    printf("Sehir eklenmek istenmedi\n");
                }

            }

            fclose(cikti);
            break;
        }
        case 4:
        {
            fopen("cikti.txt","a");

            char secim2[4];
            printf("Hangi bolge icin arama yapmak istersiniz(KISALTILMISI ILE GIRINIZ)\n");
            fprintf(cikti,"Hangi bolge icin arama yapmak istersiniz(KISALTILMISI ILE GIRINIZ)\n");
            scanf("%s",&secim2);
            fclose(cikti);
            secBolge(secim2);
            fopen("cikti.txt","a");
            fprintf(cikti,"\n\n\n");
            fclose(cikti);
            break;

        }
        case 5:
        {

            int secim2;
            printf("Komsu sayisi kriteri kac olsun?\n");
            fprintf(cikti,"Komsu sayisi kriteri kac olsun?\n");
            scanf("%d",&secim2);

            fopen("cikti.txt","a");
            fprintf(cikti,"KOMSU KRITERI: %d\n",secim2);
            fclose(cikti);
            komsuKriter(secim2);
            fopen("cikti.txt","a");
            fprintf(cikti,"\n\n\n");
            fclose(cikti);
            break;

        }
        case 6:
        {
            fclose(cikti);
            int sayi1,sayi2;
            printf("Komsu sayi araligi icin 1. sayi giriniz\n");
            scanf("%d",&sayi1);
            printf("\nKomsu sayi araligi icin 2. sayi giriniz\n");
            scanf("%d",&sayi2);

            bonusKriter(sayi1,sayi2,satir,komsu_matris,komsusayisi);
            fclose(cikti);
            break;
        }
        case 0:
        {
            fclose(dosya);
            exit(1);
        }
        }
    }

    /*kSil(34,komsusayisi[33],satir);
    komsu_ekle(komsu_plakalar,komsusayisi,satir);*/
    printf("\ntoplam komsu %d ",z);
    fprintf(cikti,"\ntoplam komsu %d ",z);
    return 0;
}
