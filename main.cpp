#include <iostream>
#include <typeinfo>
#include <string>
#include <map>
#include <string>
#include <vector>
#include <locale>
#include "Radnik.h"



int main()
{


    std::map <unsigned long long int,Radnik> Radnik_M;
    Radnik rad_1;


enum Izbornik {glMeni, RadMeni, DokMeni, OrgJMeni,exit};

    int Radnici = 0;
    int Dokumenti = 0;
    int Organizacione_jedinice = 0;
    int Izlaz = 0;

    system("Color 0A");
        system("cls");




    auto izbor = [=](std::string a ){
   std::cout<<"Da li zelite da se vratite na meni "<< a << std::endl;
        std::cout <<"1. DA" << std::endl;                                        // funkcija za preglede da bi nas vratila na gl meni radnika,dok itd.
        int odg;
        std::cin>> odg;
    return odg;
    };



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



    RadMeni:
    system("cls");
    system("COLOR 0A");
     std::cout << "               Dobrodosli u program Kadrovska Sluzba!" << std::endl << std::endl << std::endl ;
    std::cout << " " << std::string(60, '=') << std::endl;
    std::cout << " ||                Opcije za radnike su:                   ||"<<  std::endl;
    std::cout << " ||                                                        ||" << std::endl;
    std::cout << " ||    (1)                 Unos                            ||"<<  std::endl;
    std::cout << " ||                                                        ||" << std::endl;
    std::cout << " ||    (2)    Dodatni unos Dokumenata i Org Jed            ||"<<  std::endl;
    std::cout << " ||                                                        ||"<<  std::endl;
    std::cout << " ||    (3)                Izmjena                          ||"<<  std::endl;
    std::cout << " ||                                                        ||"<<  std::endl;
    std::cout << " ||    (4)                Pregled                          ||"<<  std::endl;
    std::cout << " ||                                                        ||"<<  std::endl;
    std::cout << " ||    (5)           Pregled Pojedinacnog                  ||"<<  std::endl;
    std::cout << " ||                                                        ||"<<  std::endl;
    std::cout << " ||    (6)                Brisanje                         ||"<<  std::endl;
    std::cout << " ||                                                        ||"<<  std::endl;
    std::cout << " ||    (7)                 IZLAZ                           ||"<<  std::endl;
    std::cout << " " << std::string(60, '=') << std::endl;
    int radnikMeni;
    std::cin>> radnikMeni;

    switch (radnikMeni) {

    case 1:
        system("cls");
        std::cout<< "Odabrali ste Unos" << std::endl;
        rad_1.enter(Radnik_M);
        goto RadMeni;
        break;

    case 2:
        system("cls");
        std::cout<< "Odabrali dodatni unos" << std::endl;
        rad_1.enterAdditional(Radnik_M);
        goto RadMeni;
        break;



    case 3:
        system("cls");
        std::cout<< "Odabrali ste Izmjena" << std::endl;
        rad_1.edit(Radnik_M);
        goto RadMeni;
        break;

    case 4:
        system("cls");
        std::cout<< "Odabrali ste Pregled" << std::endl << std::endl;
        rad_1.showAll(Radnik_M);
        if (izbor("Radnik")==1){
            goto RadMeni;
        }
        break;
 case 5:
        system("cls");
        std::cout<< "Odabrali Pregled pojedinacnog radnika" << std:: endl;
        rad_1.showSingle(Radnik_M);

         if (izbor("Radnik")==1){
            goto RadMeni;
        }
        break;
    case 6:
        system("cls");
        std::cout<< "Odabrali ste Brisanje" <<std:: endl;
        rad_1.del(Radnik_M);
        goto RadMeni;
        break;

    case 7:
        std::cout<< "Hvala na koristenju!";
        return 0;


    default:
        std::cout<<"Pogresan izbor!" << std::endl;
        break;


}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

return 0;
}



