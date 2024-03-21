#include <bits/stdc++.h>

using namespace std;

class Regat{
protected:
    string nume{};
    unsigned trupe_proprii{};
    string cultura{};
    bool esteVasal{};
public:
    virtual void trimiteTrupe(Regat*) = 0;
    virtual void creeazaRegatul(string, unsigned, string) = 0;
    virtual void setTrupe(unsigned) = 0;
    virtual void scadeTrupe(unsigned) = 0;
    virtual unsigned getTrupe() = 0;
    virtual void afiseazaNumeTrupe() = 0;
    virtual string getNume() = 0;
    virtual void setVasalitate() = 0;
    virtual bool verificaVasalitate() = 0;

};
class RegatBizantin: public Regat{
private:
    unsigned numar_fix_trupe{};
public:
    void setTrupe(unsigned x)  override{
        trupe_proprii = trupe_proprii + x;
    }
    void scadeTrupe(unsigned x) override{
        trupe_proprii = trupe_proprii - x;
    }
    unsigned getTrupe()  override{
        return trupe_proprii;
    }
    string getNume() override{
        return nume;
    }
    void setVasalitate() override{
        esteVasal = true;
    }
    bool verificaVasalitate() override{
        return esteVasal;
    }
    void trimiteTrupe(Regat* regatSuzeran) override{
        unsigned x = numar_fix_trupe;
        unsigned y = trupe_proprii / 2;
        if (x <=  y){
            regatSuzeran->setTrupe(x);
            trupe_proprii = trupe_proprii - x;
        }
        else if (x > y){
            regatSuzeran->setTrupe(y);
            trupe_proprii = trupe_proprii - y;
        }
    }
    void creeazaRegatul(string Nume, unsigned Trupe_proprii, string Cultura) override{
        nume = Nume;
        trupe_proprii = Trupe_proprii;
        cultura = Cultura;
        cin >> numar_fix_trupe;
        esteVasal = false;
    }
    void afiseazaNumeTrupe() override{
        cout << nume << " " << trupe_proprii << endl;
    }
};
class RegatFrank: public Regat{
private:
    unsigned procent_trupe{};
public:
    void setTrupe(unsigned x) override{
        trupe_proprii = trupe_proprii + x;
    }
    unsigned getTrupe() override{
        return trupe_proprii;
    }
    string getNume() override{
        return nume;
    }
    void setVasalitate() override{
        esteVasal = true;
    }
    bool verificaVasalitate() override{
        return esteVasal;
    }
    void scadeTrupe(unsigned x) override{
        trupe_proprii = trupe_proprii - x;
    }
    void trimiteTrupe(Regat* regatSuzeran) override{
        unsigned x = (procent_trupe * trupe_proprii) / 100;
        unsigned y = trupe_proprii / 2;
        if (x <=  y){
            regatSuzeran->setTrupe(x);
            trupe_proprii = trupe_proprii - x;
        }
        else if (x > y){
            regatSuzeran->setTrupe(y);
            trupe_proprii = trupe_proprii - y;
        }
    }
    void creeazaRegatul(string Nume, unsigned Trupe_proprii, string Cultura) override{
        nume = Nume;
        trupe_proprii = Trupe_proprii;
        cultura = Cultura;
        cin >> procent_trupe;
        esteVasal = false;
    }
    void afiseazaNumeTrupe() override{
        cout << nume << " " << trupe_proprii << endl;
    }
};
class RegatAngloSaxon: public Regat{
private:
    unsigned procent_trupe{};
    unsigned numar_minim_trupe{};
public:
    void setTrupe(unsigned x) override{
        trupe_proprii = trupe_proprii + x;
    }
    unsigned getTrupe() override{
        return trupe_proprii;
    }
    string getNume() override{
        return nume;
    }
    void setVasalitate() override{
        esteVasal = true;
    }
    bool verificaVasalitate() override{
        return esteVasal;
    }
    void scadeTrupe(unsigned x) override{
        trupe_proprii = trupe_proprii - x;
    }
    void trimiteTrupe(Regat* regatSuzeran) override{
        unsigned x = (procent_trupe * trupe_proprii) / 100;
        unsigned y = trupe_proprii / 2;
        if(x >= numar_minim_trupe){
            if (x <=  y){
                regatSuzeran->setTrupe(x);
                trupe_proprii = trupe_proprii - x;
            }
            else if (x > y){
                regatSuzeran->setTrupe(y);
                trupe_proprii = trupe_proprii - y;
            }
        }
        else if (x < numar_minim_trupe){
            if (numar_minim_trupe <=  y){
                regatSuzeran->setTrupe(numar_minim_trupe);
                trupe_proprii = trupe_proprii - numar_minim_trupe;
            }
            else if (numar_minim_trupe > y){
                regatSuzeran->setTrupe(y);
                trupe_proprii = trupe_proprii - y;
            }

        }
    }
    void creeazaRegatul(string Nume, unsigned Trupe_proprii, string Cultura) override{
        nume = Nume;
        trupe_proprii = Trupe_proprii;
        cultura = Cultura;
        cin >> procent_trupe >> numar_minim_trupe;
        esteVasal = false;
    }
    void afiseazaNumeTrupe() override{
        cout << nume << " " << trupe_proprii << endl;
    }
};


int main() {

    vector<Regat*> regate;
    unsigned N, M;
    int numarator1 = 0;
    int numarator2 = 0;
    int indice_vasal = 0;
    int indice_suzeran = 0;
    string nume;
    string regat_vasal;
    string regat_suzeran;
    unsigned trupeProprii  = 0;
    string cultura;
    cin >> N >> M;
    for (int i = 0; i < N; i++){
        cin >> nume >> trupeProprii;
        cin >> cultura;
        if (cultura == "BYZANTINE"){
            regate.push_back(new RegatBizantin);
            regate[i]->creeazaRegatul(nume, trupeProprii, cultura);
        }
        else if (cultura == "FRANK"){
            regate.push_back(new RegatFrank);
            regate[i]->creeazaRegatul(nume, trupeProprii, cultura);
        }
        else if (cultura == "ANGLO-SAXON"){
            regate.push_back(new RegatAngloSaxon);
            regate[i]->creeazaRegatul(nume, trupeProprii, cultura);
        }
    }
      for (int i = 0; i < M; i++){
        cin >> regat_vasal >> regat_suzeran;
        for (int j = 0; j < N && numarator1 == 0; j++){
            if ((regate[j]->getNume() == regat_vasal) && (regate[j]->verificaVasalitate() == false)){
                indice_vasal = j;
                regate[j]->setVasalitate();
                numarator1++;
            }
        }
        for (int k = 0; k < N && numarator2 == 0; k++){
            if (regate[k]->getNume() == regat_suzeran){
                indice_suzeran = k;
                numarator2++;
            }
        }
        regate[indice_vasal]->trimiteTrupe(regate[indice_suzeran]);
        numarator2 = 0;
        numarator1 = 0;
    }
    for (int i = 0; i < N; i++){
        regate[i]->afiseazaNumeTrupe();
    }



    return 0;
}