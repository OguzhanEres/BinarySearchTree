#include <stdio.h>
#include <stdlib.h>

struct tree{
    int data;
    struct tree* sag;
    struct tree* sol;
};
//tree deki en kück deger
int min(struct tree* agac){
    while (agac->sol!=NULL){
        agac=agac->sol;
    }
    return agac->data;
}
//tree deki en büyük deger
int max(struct tree* agac){
    while (agac->sag!=NULL){
        agac=agac->sag;
    }
    return agac->data;
}




//tree için silme fonksiyonu
//silinecek değerin yerine ya sağ tarafının en küçüğü ya da sol tarafının en büyüğü gelmeli
struct tree* sil(struct tree* agac,int aranan){
    //1. durum null olma
    if(agac==NULL){
        return NULL;
    }
    //2.durum aranan değer olma
    if(agac->data==aranan){
        if(agac->sag==NULL&&agac->sol==NULL)//leaf olma durumu çocuğu yoksa direkt null return
        {
            return NULL;
        }

        if (agac->sag!=NULL)//sağ taraf null değilse sağ tarafın en kücük değerini bulma
        {
            agac->data= min(agac->sag);
            agac->sag= sil(agac->sag, min(agac->sag));
            return agac;
        }
        //agacın sadece sol tarafı null değişlse durumu
        agac->data= max(agac->sol);
        agac->sol= sil(agac->sol, max(agac->sol));
        return agac;
    }
    //seacrh mantığı
    if(agac->data<aranan){
        agac->sag= sil(agac->sag,aranan);
        return agac;
    }
    agac->sol= sil(agac->sol,aranan);
    return agac;
}
 void search(struct tree* agac,int aranan){
    if(agac!=NULL) {
        if (agac->data == aranan) {
            printf("aranan deger bulundu: %d",agac->data);
        }
        if (agac->data < aranan) {
            search(agac->sag, aranan);
        }
        else
            search(agac->sol, aranan);
    }
    else
        printf("aranan deger bulunamadi");
}
struct tree* insert(struct tree* agac,int data){
    if(agac==NULL){
        struct tree* root=(struct tree*) malloc(sizeof(struct tree));
        root->data=data;
        root->sag=NULL;
        root->sol=NULL;
        return root;
    }
    if(agac->data<data){
        agac->sag= insert(agac->sag,data);
        return agac;
    }
    agac->sol= insert(agac->sol,data);
    return agac;
}
void yazdir(struct tree* agac){
    if(agac==NULL){
        return;
    }
    yazdir(agac->sol);
    printf("%d  ",agac->data);
    yazdir(agac->sag);
}
int main() {
    struct tree* agac=NULL;
    agac= insert(agac,5);
    agac= insert(agac,45);
    agac= insert(agac,511);
    agac= insert(agac,13);
    agac= insert(agac,486);
    agac= insert(agac,450);
    agac= insert(agac,64);
    agac= insert(agac,131);
    yazdir(agac);
    printf("\n");

    search(agac,486);
    printf("\n");
    printf("en kucuk deger: %d",min(agac));
    printf("\n");
    printf("en buyuk deger: %d", max(agac));
    printf("\n");
    sil(agac,450);

    yazdir(agac);


    return 0;
}
