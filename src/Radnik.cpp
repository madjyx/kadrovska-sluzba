#include "Radnik.h"

Radnik::Radnik()
{
    //ctor
}

Radnik::~Radnik()
{
    //dtor
}

void Radnik::setIme(std::string ime) {
this-> ime = ime;
}
void Radnik::setPrezime(std::string prezime) {
this-> prezime = prezime;
}
void Radnik::setLK(std::string LK) {
this-> LK = LK;
}

void Radnik::setNaziv(std::string Naziv) {
this-> Naziv = Naziv;
}
void Radnik::setVrsta(std::string Vrsta) {
this-> Vrsta = Vrsta;

}
void  Radnik::setMjesto_Izdavanja(std::string Mjesto_Izdavanja) {
this-> Mjesto_Izdavanja = Mjesto_Izdavanja;
}


void Radnik::setNazivOrgJed(std::string NazivOrgJed) {
this-> NazivOrgJed = NazivOrgJed;
}
void Radnik::setPozicija(std::string Pozicija) {
this-> Pozicija = Pozicija;

}
void Radnik::setemail(std::string email) {
this-> email = email;
}
void Radnik::setbrojtel(std::string brojtel) {
this-> brojtel = brojtel;
}

void Radnik::setidDoc (std::string id) {
this-> idDoc = id;
}
void Radnik::setidOrg(std::string id) {
this-> idOrg = id;
}


//////////////////////////////////////////////////////////////////////////

  void Radnik::enter(std::map<unsigned long long int,Radnik> &radmap) {

    auto greska = [] (std::string n)  {

	for (int i = 0; i < n.size(); i++)            // lambda funkcija koja provjerava da li nam se uneseni string sastoji samo od karaktera ako ima broj izbacuje gresku
	{
		if (!(isalpha(n[i])))
		{
			return false;
		}
		return true;
	}
};

    unsigned long long int id;  // inicjalizacija kljuc varjable
    Radnik *Radnik_1; // inicjalizacija novog clana klase s pokazivacem
    Radnik_1 = new Radnik; // pravi ne definiran broj objekata u memoriji za spremanje podataka Radnik
    std::cin.ignore();
IMErep:
     std::cout << "Upisite ime Radnika: ";
       getline(std::cin, ime);
       if (greska(ime)!=1){
        std::cout<<"Pogresan unos, ponovite unos obavezno samo slova!" << std::endl;
        goto IMErep;
       }
          Radnik_1->setIme(ime);  // unosimo ime u objekat Radnik_1
PREZIMErep:
     std::cout << "Upisite prezime Radnika: ";
       getline(std::cin, prezime);

        if (greska(prezime)!=1){
        std::cout<<"Pogresan unos, ponovite unos obavezno samo slova!" << std::endl;
        goto PREZIMErep;
       }
          Radnik_1->setPrezime(prezime); // unosimo prezime u objekat Radnik_1
LKrep:
     std::cout << "upisite LK radnka: ";
       std::cin >> LK;

        if (greska(LK)!=0){
        std::cout<<"Pogresan unos, ponovite unos obavezno samo brojevi!" << std::endl;
        goto LKrep;
       }

          Radnik_1->setLK(LK); // unosimo LK u objekat Radnik_1

JMBG:
  std::cin.clear();
  std::cin.ignore(1024,'\n');
     std::cout << "upisite JMBG radnka: " << std::endl;

std::cin >> id;

if (id>9999999999999 || id == 0) {
std::cout<<"Greska! maksimalno 13 cifara samo brojevi!" << std::endl;  // uslov za samo 13 cifara te samo brojevi
goto JMBG;
    }
else
            if (radmap.find(id)!=radmap.end()) {                 // uslov da se ne smije unijeti 2 put isti JMBG unijet ako se unese
                                                                // vrati nas da odaberemo da li zelimo ponoviti postupak unosa
                std::cout<<"Greska taj JMBG vec postoji!" << std::endl<<std::endl;
                std::cout<<"Da li zelite ponoviti radnju?"<<std::endl;
                    std::cout <<"1. Da" << std::endl;
                    std::cout <<"2. Ne" << std::endl;
                    int odg;
                    std::cin >> odg;
                    if (odg==1) {
                        goto JMBG;
                    }

            }
std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
std::cout << std::left << "\n" << std::string(70, '-') << std::endl;
VRSTArep:
     std::cout << "Upisite Vrstu Dokumenta: ";                                          // nakon unosa osnovnih informacija o radniku unosimo informacije za dokument i org jedinicu
                                                                                        // sve informacije se smijestaju u vektor jedna za drugom
       getline(std::cin, Vrsta);

        if (greska(Vrsta)!=1){
        std::cout<<"Pogresan unos, ponovite unos obavezno samo slova!" << std::endl;
        goto VRSTArep;
       }
         Radnik_1->setVrsta(Vrsta);
         Radnik_1->OrgDoc.push_back(Vrsta);

NAZIVDocrep:
     std::cout << "Upisite Naziv Dokumenta: ";
       getline(std::cin, Naziv);

       if (greska(Naziv)!=1){
        std::cout<<"Pogresan unos, ponovite unos obavezno samo slova!" << std::endl;
        goto NAZIVDocrep;
       }
           Radnik_1->setNaziv(Naziv);
         Radnik_1->OrgDoc.push_back(Naziv);
MJESTOrep:
     std::cout << "upisite Mjesto izdavanja Dokumenta: ";
       getline(std::cin,Mjesto_Izdavanja);

       if (greska(Mjesto_Izdavanja)!=1){
        std::cout<<"Pogresan unos, ponovite unos obavezno samo slova!" << std::endl;
        goto MJESTOrep;
       }
          Radnik_1->setMjesto_Izdavanja(Mjesto_Izdavanja);
         Radnik_1->OrgDoc.push_back(Mjesto_Izdavanja);


     std::cout << "upisite KONTROLNI BROJ Dokumenta: ";
     std::string docid;  // inicjalizacija kljuc varjable

         getline(std::cin,docid);
         Radnik_1->setidDoc(docid);
         Radnik_1->OrgDoc.push_back(docid);





NAZIVOrgrep:
     std::cout << "Upisite Naziv Organizacione Jedinice: ";
       getline(std::cin, NazivOrgJed);

       if (greska(NazivOrgJed)!=1){
        std::cout<<"Pogresan unos, ponovite unos obavezno samo slova!" << std::endl;
        goto NAZIVOrgrep;
       }
          Radnik_1->setNaziv(NazivOrgJed);
          Radnik_1->OrgDoc.push_back(NazivOrgJed);

POZICIJArep:
     std::cout << "Upisite Poziciju Ranika u  Organizacionoj Jedinici: " <<std::endl;
       getline(std::cin, Pozicija);

        if (greska(Pozicija)!=1){
        std::cout<<"Pogresan unos, ponovite unos obavezno samo slova!" << std::endl;
        goto POZICIJArep;
       }
          Radnik_1->setPozicija(Pozicija);
          Radnik_1->OrgDoc.push_back(Pozicija);
MAILrep:

     std::cout << "upisite email Radnika: "<<std::endl;
       getline(std::cin,email);

       if (greska(email)!=1){
        std::cout<<"Pogresan unos, ponovite unos obavezno samo slova!" << std::endl;
        goto MAILrep;
       }
          Radnik_1->setemail(email);
          Radnik_1->OrgDoc.push_back(email);

BROJrep:

     std::cout << "upisite broj telefona: "<<std::endl;
       getline(std::cin,brojtel);

       if (greska(brojtel)!=0){
        std::cout<<"Pogresan unos, ponovite unos obavezno samo brojevi!" << std::endl;
        goto BROJrep;
       }
          Radnik_1->setbrojtel(brojtel);
          Radnik_1->OrgDoc.push_back(brojtel);



     std::cout << "upisite Skraceno ime Organizacione Jedinice: "<<std::endl;
        std::string orgid;
         getline(std::cin,orgid);

         Radnik_1->setidOrg(orgid);
          Radnik_1->OrgDoc.push_back(orgid);



       radmap.insert(std::pair<unsigned long long int,Radnik>(id,*Radnik_1)); // pravimo par u mapi s argumentima id i Radnik_1

}

     void Radnik::enterAdditional(std::map<unsigned long long int,Radnik> &addDocOrg){


         auto greska = [] (std::string n)  {

	for (int i = 0; i < n.size(); i++)
	{
		if (!(isalpha(n[i])))
		{
			return false;
		}
		return true;
	}
};

 AGAIN:
system("cls");
std::cout << "Unesite JMBG radnika kojem zelite dodati Dokument ili Org Jedinicu: " << std::endl;
unsigned long long int id;
std::cin >> id;
    if (addDocOrg.find(id)==addDocOrg.end()) {

    std::cout<<"Greska uneseni JMBG ne postoji " << std::endl;
    std::cout<<"Da li zelite ponoviti radnju?"<<std::endl;
                    std::cout <<"1. Da" << std::endl;
                    std::cout <<"2. Ne" << std::endl;
                    int odg;
                    std::cin >> odg;
                    if (odg==1) {
                   goto AGAIN;
                    }
                    else return;
}
std::cout << std::left << "\n" << std::string(70, '-') << std::endl;

auto it = addDocOrg.find(id);


std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

VRSTArep:
     std::cout << "Upisite Vrstu Dokumenta: ";         // na isti nacin kao prilikom unosa u vektor smijestamo dodatne dokumente i organizacju
       getline(std::cin, Vrsta);

        if (greska(Vrsta)!=1){
        std::cout<<"Pogresan unos, ponovite unos obavezno samo slova!" << std::endl;
        goto VRSTArep;
       }

         (*it).second.OrgDoc.push_back(Vrsta);

NAZIVDocrep:
     std::cout << "Upisite Naziv Dokumenta: ";
       getline(std::cin, Naziv);

       if (greska(Naziv)!=1){
        std::cout<<"Pogresan unos, ponovite unos obavezno samo slova!" << std::endl;
        goto NAZIVDocrep;
       }

         (*it).second.OrgDoc.push_back(Naziv);
MJESTOrep:
     std::cout << "upisite Mjesto izdavanja Dokumenta: ";
       getline(std::cin,Mjesto_Izdavanja);

       if (greska(Mjesto_Izdavanja)!=1){
        std::cout<<"Pogresan unos, ponovite unos obavezno samo slova!" << std::endl;
        goto MJESTOrep;
       }

        (*it).second.OrgDoc.push_back(Mjesto_Izdavanja);


     std::cout << "upisite KONTROLNI BROJ Dokumenta: ";
     std::string docid;

         getline(std::cin,docid);
         (*it).second.OrgDoc.push_back(docid);





NAZIVOrgrep:
     std::cout << "Upisite Naziv Organizacione Jedinice: ";
       getline(std::cin, NazivOrgJed);

       if (greska(NazivOrgJed)!=1){
        std::cout<<"Pogresan unos, ponovite unos obavezno samo slova!" << std::endl;
        goto NAZIVOrgrep;
       }

         (*it).second.OrgDoc.push_back(NazivOrgJed);

POZICIJArep:
     std::cout << "Upisite Poziciju Ranika u  Organizacionoj Jedinici: " <<std::endl;
       getline(std::cin, Pozicija);

        if (greska(Pozicija)!=1){
        std::cout<<"Pogresan unos, ponovite unos obavezno samo slova!" << std::endl;
        goto POZICIJArep;
       }

            (*it).second.OrgDoc.push_back(Pozicija);
MAILrep:

     std::cout << "upisite email Radnika: "<<std::endl;
       getline(std::cin,email);

       if (greska(email)!=1){
        std::cout<<"Pogresan unos, ponovite unos obavezno samo slova!" << std::endl;
        goto MAILrep;
       }

           (*it).second.OrgDoc.push_back(email);

BROJrep:

     std::cout << "upisite broj telefona: "<<std::endl;
       getline(std::cin,brojtel);

       if (greska(brojtel)!=0){
        std::cout<<"Pogresan unos, ponovite unos obavezno samo brojevi!" << std::endl;
        goto BROJrep;
       }

         (*it).second.OrgDoc.push_back(brojtel);



     std::cout << "upisite Skraceno ime Organizacione Jedinice: "<<std::endl;
        std::string orgid;  // inicjalizacija kljuc varjable
         getline(std::cin,orgid);

          (*it).second.OrgDoc.push_back(orgid);



     }

void Radnik::showAll(std::map<unsigned long long int,Radnik> &itrad) {
    std::cout << std::left << "\n" << std::string(70, '-') << std::endl;
    std::cout << std::left << " " << std::setw(12) << "Ime:" << std::setw(20) << "Prezime:"
    << std::setw(20) << "LK:" << std::setw(20) << "JMBG:" <<std::endl;                        // ispis tabele za pregled ime,prezime,LK,JMBG

    for (auto it = itrad.begin(); it != itrad.end(); ++it) {                      // kreiranje petlje te postavljanje iteratora na pocetak koji vrsi
                                                                                  // dok ne dodje do kraja mape.

    std::cout << std::setw(14) <<(*it).second.ime <<
    std::setw(20) << (*it).second.prezime << std::setw(20)
    << (*it).second.LK << std::setw(20) <<                                        // pristup podatcima Radnik u mapi pomocu operatora
    (*it).first << std::endl;


}

 std::cout<< std::left << "\n" << std::string(70, '-') << std::endl;

}

void Radnik::showSingle(std::map<unsigned long long int,Radnik> &showrad){

AGAIN:
system("cls");
std::cout << "Unesite JMBG radnika kojeg zelite pogledati: " << std::endl;
unsigned long long int id;
std::cin >> id;
    if (showrad.find(id)==showrad.end()) {

    std::cout<<"Greska uneseni JMBG ne postoji " << std::endl;
    std::cout<<"Da li zelite ponoviti radnju?"<<std::endl;
                    std::cout <<"1. Da" << std::endl;
                    std::cout <<"2. Ne" << std::endl;
                    int odg;
                    std::cin >> odg;
                    if (odg==1) {
                   goto AGAIN;
                    }
                    else return;
}
std::cout << std::left << "\n" << std::string(70, '-') << std::endl;


    auto it = showrad.find(id);

    std::cout  << "Ime: " <<(*it).second.ime << std::endl;
    std::cout <<  "Prezime: " << (*it).second.prezime<< std::endl;
    std::cout << "LK: " <<(*it).second.LK << std::endl;
    std::cout << "JMBG :" << (*it).first << std::endl;
    std::cout<< std::left << "\n" << std::string(70, '-') << std::endl;
    std::cout<<"Dokumenti: " << std::endl;
int tempvar = 0;
int vectorsize = (*it).second.OrgDoc.size()/9;


for(int i = 0; i <vectorsize ; i++){         // for petlja koja ispisje grupu elemenata iz vektora ( 9 elemenata )
std::cout<< std::left << "\n" << std::string(70, '-') << std::endl;
std::cout<< "Vrsta Dokumenta: " << (*it).second.OrgDoc.at(tempvar)<< std::endl;
tempvar +=1;
std::cout<< "Naziv Dokumenta: " << (*it).second.OrgDoc.at(tempvar)<< std::endl;
tempvar +=1;
std::cout<< "Mjesto izdavanja Dokumenta: " << (*it).second.OrgDoc.at(tempvar)<< std::endl;
tempvar +=1;
std::cout<< "Kontrolni broj: " << (*it).second.OrgDoc.at(tempvar)<< std::endl;
tempvar +=1;
std::cout<< std::left << "\n" << std::string(70, '-') << std::endl;
std::cout<< "Naziv Organizacione Jedinice: " << (*it).second.OrgDoc.at(tempvar)<< std::endl;
tempvar +=1;
std::cout<< "Pozicija Radnika u Org. Jedinici: " << (*it).second.OrgDoc.at(tempvar)<< std::endl;
tempvar +=1;
std::cout<< "e-mail: " << (*it).second.OrgDoc.at(tempvar)<< std::endl;
tempvar +=1;
std::cout<< "broj telefona: " << (*it).second.OrgDoc.at(tempvar)<< std::endl;
tempvar +=1;
std::cout<< "Skraceno ime Org: " << (*it).second.OrgDoc.at(tempvar)<< std::endl;
tempvar +=1;
}

std::cout<< std::left << "\n" << std::string(70, '-') << std::endl;



}


void Radnik::del(std::map<unsigned long long int,Radnik> &delrad) {


JMBG:
    std::cin.clear();
    std::cin.ignore(1024,'\n');
    std::cout << "Unesite JMBG Radnika" << std::endl;
    unsigned long long int id = 0;
    int odg;

 std::cin >> id;

 if (id>9999999999999 || id == 0) {
std::cout<<"Greska! maksimalno 13 cifara samo brojevi! " << std::endl;
goto JMBG;
    }
else;

    if (delrad.find(id)==delrad.end()) {                 // uslov da se ne smije unijeti 2 put isti JMBG unijet ako se unese
                                                                // vrati nas da odaberemo da li zelimo ponoviti postupak unosa
                std::cout<<"Greska taj JMBG ne postoji!" << std::endl<<std::endl;
                std::cout<<"Da li zelite ponoviti radnju?"<<std::endl;
                    std::cout <<"1. Da" << std::endl;
                    std::cout <<"2. Ne" << std::endl;
                    int odg;
                    std::cin >> odg;
                    if (odg==1) {
                        goto JMBG;
                    }
                else return;
            }


auto it = delrad.find(id);   // trazi Radnika po kljucu JMBG
    system("cls");
    std::cout << "Jeste sigurni da zelite izbrisati Radnika:   " << (*it).second.ime << "    " << (*it).second.prezime<< std::endl;
    std::cout <<"1. Da" << std::endl;
    std::cout <<"2. Ne" << std::endl;
    std::cin >> odg;
   if(odg == 1) {                  // postavljanje uslova jesmo sigurni za brisanje ako da onda se preko erase brise zeljeni Radnik
    delrad.erase(it);



}

}


void Radnik::edit(std::map<unsigned long long int,Radnik> &editrad) {

auto izbor = [=](){
std::cout<<"Da li zelite da izmjenite jos nesto?"<<std::endl;
std::cout <<"1. Da" << std::endl;
std::cout <<"2. Ne" << std::endl;
int odg;
std::cin >> odg;
return odg;
};




AGAIN:
    system("cls");
    std::cout << "Unesite JMBG Radnika kojeg zelite urediti : " << std::endl;
    std::string izmjenastr;
    unsigned long long int id;
    std::cin >> id;

    auto it = editrad.find(id);
     if (editrad.find(id)==editrad.end()) {

                std::cout<<"Greska uneseni kontrolni broj ne postoji " << std::endl;

                std::cout<<"Da li zelite ponoviti radnju?"<<std::endl;
                    std::cout <<"1. Da" << std::endl;
                    std::cout <<"2. Ne" << std::endl;
                    int odg;
                    std::cin >> odg;
                    if (odg==1) {
                   goto AGAIN;
                    }
                    else return;
}
         system("cls");

            int editMeni;
            std::cout << "Odaberite zeljenu opciju za mjenjanje podatka clana:  " << std::endl;

            std::cout << "Ime: "<<(*it).second.ime <<"  " <<"Prezime: "  << (*it).second.prezime << "  " << "Broj LK: "
             <<(*it).second.LK <<"  "<<"JMBG: " <<(*it).first << std::endl;


            std::cout << " 1 : Ime:" << std::endl;
            std::cout << " 2 : Prezime:" << std::endl;
            std::cout << " 3 : LK:"  << std::endl;

            std::cin>>editMeni;

            switch (editMeni) {

                case (1):
                    std::cin.clear();
                    std::cout << "Unesite novo Ime:" << std::endl;
                    std::cin >> izmjenastr;
                    (*it).second.ime = izmjenastr;
                     break;

                case (2):
                    std::cin.clear();
                    std::cout << "Unesite novo Prezime: " << std::endl;
                    std::cin >>izmjenastr;
                    (*it).second.prezime = izmjenastr;
                    break;

                case (3):
                    std::cin.clear();
                    std::cout << "Unesite novi broj LK" << std::endl;
                    std::cin >>izmjenastr;
                    (*it).second.LK = izmjenastr;
                    break;


                    default:
                    std::cout<<"Pogresan izbor!" << std::endl;
                    break;

            }

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
















