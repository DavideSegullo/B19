#include <iostream>
#include <stdlib.h>
using namespace std;

struct Albero{

    char nodo;  //Il dato contenuto nel nodo
    Albero *sinistra; //Puntatore al sottoalbero sinistro
    Albero *destra; //Puntatore al sottoalbero destro

};

class Tree{
private:
    Albero *root;

public:
    Tree(){

        root=nullptr;

    }

    bool Vuoto(Albero *p){

        return (p==nullptr);

    }

    Albero *Sinistro(Albero *p){
        if(Vuoto(p)) return nullptr;
        else return p->sinistra;
    }

    Albero *Destro(Albero *p){
        if(Vuoto(p)) return nullptr;
        else return p->destra;
    }

    Albero *Inserisci(bool choose,Albero *p){
        if(Vuoto(p)){
            p=new(Albero);
            cout<<"Lettera:";
            cin>>p->nodo;
            p->sinistra=nullptr;
            p->destra=nullptr;
            root=p;
          return p;
        }
        else{
            if(choose){
                p->destra=Inserisci(choose,Destro(p));
                root=p;
                return p;
            }
            else{
                p->sinistra=Inserisci(choose,Sinistro(p));
                root=p;
                return p;
            }

        }

    }



    Albero *getter(){return root;}

    void Stampa(Albero *p){

    if(p!=nullptr){

       cout<<p->nodo<<" ";
       Stampa(p->sinistra);
       Stampa(p->destra);

     }

    }


};

int main()
{
     Tree l;
     int scelta;
     bool choose;
     do{
        cout<<endl<<"1. INSERIMENTO"<<endl<<"2. STAMPA"<<endl<<"3. PULISCI SCHERMO"<<endl<<"0. ESCI"<<endl;
        cin>>scelta;

        switch(scelta){
        case 1:
            if(l.getter()!=nullptr){
            cout<<"1. DESTRA"<<"   0.SINISTRA"<<endl;
            cin>>choose;}
            l.Inserisci(choose,l.getter());
            break;
        case 2:
            l.Stampa(l.getter());
            break;
        case 3:
            system("cls");
            break;
        }
     }
     while(scelta!=0);

    return 0;
}
