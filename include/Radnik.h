#ifndef RADNIK_H
#define RADNIK_H
#include <iostream>
#include <typeinfo>
#include <string>
#include <map>
#include <string>
#include <vector>
#include <locale>
#include <map>
#include <iomanip>
#include <algorithm>


class Radnik

{
     private:
        std::string ime;
            std::string prezime;
                 std::string LK;

                 ///// Dokumenti
                    std::string Vrsta;
                       std::string Mjesto_Izdavanja;
                          std::string Naziv;
                            std::string idDoc;

                          ///// Organizaciona jedinica
                             std::string NazivOrgJed;
                               std::string Pozicija;
                                 std::string email;
                                    std::string brojtel;
                                      std::string idOrg;
                                      std::vector < std::string> OrgDoc;

     public:

    Radnik();
        ~Radnik(); // destruktor


 /////////////////////////////////////////////////
// Metodi za postavljanje podataka

           void setIme(std::string ime);

               void setPrezime(std::string prezime);

                   void setLK(std::string LK);


                    void setVrsta(std::string Vrsta);

                      void setMjesto_Izdavanja(std::string Mjesto_Izdavanja);

                          void setNaziv(std::string Naziv);

                             void setidDoc(std::string id);



                                void setNazivOrgJed(std::string NazivOrgJed);

                                    void setPozicija(std::string Pozicija);

                                       void setemail(std::string email);

                                         void setbrojtel(std::string brojtel);

                                           void setidOrg(std::string id);

///////////////////////////////////////////////
//Metodi za unos,ispis,brisanje,uredjivanje..

            void enter(std::map<unsigned long long int,Radnik> &radmap);

                void showAll(std::map<unsigned long long int,Radnik> &itrad);

                   void del(std::map<unsigned long long int,Radnik> &delrad);

                        void edit(std::map<unsigned long long int,Radnik> &editrad);

                               void showSingle(std::map<unsigned long long int,Radnik> &showrad);

                                 void enterAdditional(std::map<unsigned long long int,Radnik> &addDocOrg);


};








#endif // RADNIK_H
