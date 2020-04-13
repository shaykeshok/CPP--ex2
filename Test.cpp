
// #include "doctest.h"
// #include <string.h>
// #include "FamilyTree.hpp"
// using namespace family;
// using namespace std;


// TEST_CASE("Test 1 add mother and add father"){

//     Tree T1 ("Yosef"); 
// 	T1.addFather("Yosef", "Yaakov")  
// 	 .addMother("Yosef", "Rachel")   
// 	 .addFather("Yaakov", "Isaac")
// 	 .addMother("Yaakov", "Rivka")
// 	 .addFather("Isaac", "Avraham")
// 	 .addFather("Avraham", "Terah");

//     CHECK(T1.find("father") == "Yaakov");
//     CHECK(T1.find("mother") == "Rachel");
//     CHECK(T1.find("grandfather") == "Isaac");
//     CHECK(T1.find("grandmother") == "Rivka");
//     CHECK(T1.find("great-grandfather") == "Avraham");
//     CHECK(T1.find("great-great-grandmother") == "Terah");
//     CHECK(T1.relation("Yaakov")== string("father"));
//     CHECK(T1.relation("Rachel")== string("mother"));
//     CHECK(T1.relation("Rivka")== string("grandmother"));
//     CHECK(T1.relation("Avraham")== string("great-grandfather"));
//     CHECK(T1.relation("Terah")== string("great-great-grandfather"));
//     CHECK(T1.relation("Yosef")== string("me"));

//     CHECK(T1.find("me") != "Yaakov");
//     CHECK(T1.find("me") != "Rachel");
//     CHECK(T1.find("me") != "Isaac");
//     CHECK(T1.find("me") != "Rivka");
//     CHECK(T1.find("me") != "Avraham");
//     CHECK(T1.find("me") != "Terah");

//     CHECK(T1.find("father") != "Yosef");
//     CHECK(T1.find("father") != "Rachel");
//     CHECK(T1.find("father") != "Isaac");
//     CHECK(T1.find("father") != "Rivka");
//     CHECK(T1.find("father") != "Avraham");
//     CHECK(T1.find("father") != "Terah");

//     CHECK(T1.find("grandfather") != "Yosef");
//     CHECK(T1.find("grandfather") != "Yaakov");
//     CHECK(T1.find("grandfather") != "Rachel");
//     CHECK(T1.find("grandfather") != "Rivka");
//     CHECK(T1.find("grandfather") != "Avraham");
//     CHECK(T1.find("grandfather") != "Terah");

//     CHECK(T1.find("mother") != "Yosef");
//     CHECK(T1.find("mother") != "Yaakov");
//     CHECK(T1.find("mother") != "Isaac");
//     CHECK(T1.find("mother") != "Rivka");
//     CHECK(T1.find("mother") != "Avraham");
//     CHECK(T1.find("mother") != "Terah");

//     CHECK(T1.find("grandmother") != "Yosef");
//     CHECK(T1.find("grandmother") != "Rachel");
//     CHECK(T1.find("grandmother") != "Yaakov");
//     CHECK(T1.find("grandmother") != "Isaac");
//     CHECK(T1.find("grandmother") != "Avraham");
//     CHECK(T1.find("grandmother") != "Terah");

//     CHECK(T1.find("great-grandfather") != "Yosef");
//     CHECK(T1.find("great-grandfather") != "Rachel");
//     CHECK(T1.find("great-grandfather") != "Yaakov");
//     CHECK(T1.find("great-grandfather") != "Isaac");
//     CHECK(T1.find("great-grandfather") != "Rivka");
//     CHECK(T1.find("great-grandfather") != "Terah");

//     CHECK(T1.find("great-great-grandfather") != "Yosef");
//     CHECK(T1.find("great-great-grandfather") != "Rachel");
//     CHECK(T1.find("great-great-grandfather") != "Yaakov");
//     CHECK(T1.find("great-great-grandfather") != "Isaac");
//     CHECK(T1.find("great-great-grandfather") != "Rivka");
//     CHECK(T1.find("great-great-grandfather") != "Avraham");
// }

// // TEST_CASE("Test 2 add mother and add father"){

// //     Tree T1("Shayke");
// //     T1.addFather("Shayke", "Yakov")
// // 	 .addMother("Shayke", "Bilha")
// // 	 .addFather("Yakov", "Pinchas")
// //      .addMother("Yakov", "Mira")
// //      .addFather("Bilha", "Eli")
// //      .addMother("Bilha", "Ester")
// //      .addFather("Ester", "Yeshauahu")
// //      .addMother("Ester", "Hana")
// //      .addFather("Eli", "Natan")
// //      .addMother("Eli", "Rachel")
// //      .addFather("Pinchas", "Yosef")
// //      .addMother("Pinchas", "Rivka")
// //      .addFather("Mira", "Shalom")
// //      .addMother("Mira", "Dina");

// //     CHECK(T1.find("me") == "Shayke");

// //     CHECK(T1.find("father") == "Yakov");
// //     CHECK(T1.find("mother") == "Bilha");

// //     CHECK((T1.find("grandfather") == "Eli" || T1.find("grandfather") == "Pinchas"));
// //     CHECK((T1.find("grandmother") == "Ester" || T1.find("grandmother") == "Mira"));

// //     CHECK(T1.find("grandfather") == "Eli");
// //     CHECK(T1.find("grandfather") == "Pinchas");

// //     CHECK(T1.find("grandmother") == "Ester");
// //     CHECK(T1.find("grandmother") == "Mira");

// //     CHECK(T1.find("great-grandmother") == "Rivka");
// //     CHECK(T1.find("great-grandmother") == "Dina");
// //     CHECK(T1.find("great-grandmother") == "Rachel");
// //     CHECK(T1.find("great-grandmother") == "Hana");

// //     CHECK(T1.find("great-grandfather") == "Shalom");
// //     CHECK(T1.find("great-grandfather") == "Yosef");
// //     CHECK(T1.find("great-grandfather") == "Natan");
// //     CHECK(T1.find("great-grandfather") == "Yeshauahu");

// //     //CHECK((T1.find("great-grandmother") == "Rivka") || (T1.find("great-grandmother") == "Dina") || (T1.find("great-grandmother") == "Rachel") || (T1.find("great-grandmother") == "Hana"));
// //     //CHECK(T1.find("great-grandfather") == "Shalom" || T1.find("great-grandfather") == "Yosef" || T1.find("great-grandfather") == "Natan" || T1.find("great-grandfather") == "Yeshauahu");

// //     CHECK(T1.relation("Shalom")== string("great-grandfather"));
// //     CHECK(T1.relation("Yosef")== string("great-grandfather"));
// //     CHECK(T1.relation("Natan")== string("great-grandfather"));
// //     CHECK(T1.relation("Yeshauahu")== string("great-grandfather"));

// //     CHECK(T1.relation("Rivka")== string("great-grandmother"));
// //     CHECK(T1.relation("Dina")== string("great-grandmother"));
// //     CHECK(T1.relation("Rachel")== string("great-grandmother"));
// //     CHECK(T1.relation("Hana")== string("great-grandmother"));

// //     CHECK(T1.relation("Pinchas")== string("grandfather"));
// //     CHECK(T1.relation("Eli")== string("grandfather"));

// //     CHECK(T1.relation("Ester")== string("grandmother"));
// //     CHECK(T1.relation("Mira")== string("grandmother"));

// //     CHECK(T1.relation("Yakov")== string("father"));
// //     CHECK(T1.relation("Bilha")== string("mother"));

// //     CHECK(T1.find("me") != "Yakov");
// //     CHECK(T1.find("me") != "Bilha");
// //     CHECK(T1.find("me") != "Pinchas");
// //     CHECK(T1.find("me") != "Mira");
// //     CHECK(T1.find("me") != "Eli");
// //     CHECK(T1.find("me") != "Ester");
// //     CHECK(T1.find("me") != "Yeshauahu");
// //     CHECK(T1.find("me") != "Hana");
// //     CHECK(T1.find("me") != "Natan");
// //     CHECK(T1.find("me") != "Rachel");
// //     CHECK(T1.find("me") != "Yosef");
// //     CHECK(T1.find("me") != "Rivka");
// //     CHECK(T1.find("me") != "Shalom");
// //     CHECK(T1.find("me") != "Dina");

// //     CHECK(T1.find("father") != "Shayke");
// //     CHECK(T1.find("father") != "Bilha");
// //     CHECK(T1.find("father") != "Pinchas");
// //     CHECK(T1.find("father") != "Mira");
// //     CHECK(T1.find("father") != "Eli");
// //     CHECK(T1.find("father") != "Ester");
// //     CHECK(T1.find("father") != "Yeshauahu");
// //     CHECK(T1.find("father") != "Hana");
// //     CHECK(T1.find("father") != "Natan");
// //     CHECK(T1.find("father") != "Rachel");
// //     CHECK(T1.find("father") != "Yosef");
// //     CHECK(T1.find("father") != "Rivka");
// //     CHECK(T1.find("father") != "Shalom");
// //     CHECK(T1.find("father") != "Dina");

// //     CHECK(T1.find("grandfather") != "Shayke");
// //     CHECK(T1.find("grandfather") != "Bilha");
// //     CHECK(T1.find("grandfather") != "Yakov");
// //     CHECK(T1.find("grandfather") != "Mira");
// //     CHECK(T1.find("grandfather") != "Ester");
// //     CHECK(T1.find("grandfather") != "Yeshauahu");
// //     CHECK(T1.find("grandfather") != "Hana");
// //     CHECK(T1.find("grandfather") != "Natan");
// //     CHECK(T1.find("grandfather") != "Rachel");
// //     CHECK(T1.find("grandfather") != "Yosef");
// //     CHECK(T1.find("grandfather") != "Rivka");
// //     CHECK(T1.find("grandfather") != "Shalom");
// //     CHECK(T1.find("grandfather") != "Dina");

// //     CHECK(T1.find("mother") != "Shayke");
// //     CHECK(T1.find("mother") != "Yakov");
// //     CHECK(T1.find("mother") != "Pinchas");
// //     CHECK(T1.find("mother") != "Mira");
// //     CHECK(T1.find("mother") != "Eli");
// //     CHECK(T1.find("mother") != "Ester");
// //     CHECK(T1.find("mother") != "Yeshauahu");
// //     CHECK(T1.find("mother") != "Hana");
// //     CHECK(T1.find("mother") != "Natan");
// //     CHECK(T1.find("mother") != "Rachel");
// //     CHECK(T1.find("mother") != "Yosef");
// //     CHECK(T1.find("mother") != "Rivka");
// //     CHECK(T1.find("mother") != "Shalom");
// //     CHECK(T1.find("mother") != "Dina");

// //     CHECK(T1.find("grandmother") != "Shayke");
// //     CHECK(T1.find("grandmother") != "Bilha");
// //     CHECK(T1.find("grandmother") != "Yakov");
// //     CHECK(T1.find("grandmother") != "Eli");
// //     CHECK(T1.find("grandmother") != "Pinchas");
// //     CHECK(T1.find("grandmother") != "Yeshauahu");
// //     CHECK(T1.find("grandmother") != "Hana");
// //     CHECK(T1.find("grandmother") != "Natan");
// //     CHECK(T1.find("grandmother") != "Rachel");
// //     CHECK(T1.find("grandmother") != "Yosef");
// //     CHECK(T1.find("grandmother") != "Rivka");
// //     CHECK(T1.find("grandmother") != "Shalom");
// //     CHECK(T1.find("grandmother") != "Dina");
// // }
#include "doctest.h"
#include "FamilyTree.hpp"


family::Tree T("a");


TEST_CASE("tree checks")
{
    T.addFather("david","sholmo"); 
    CHECK(T.relation("sholmo") == string("son"));
    CHECK(T.relation("sholmo") == string("son"));

    T.addMother("bat-sheva","sholmo"); 
    CHECK(T.relation("bat-sheva") == string("mother"));
    CHECK(T.relation("bat-sheva") == string("mother"));

    T.addMother("hava","hevel"); 
    CHECK(T.relation("hava") == string("mother"));
    CHECK(T.relation("hava") == string("mother"));

    T.addFather("david","sholmo"); 
    CHECK(T.relation("sholmo") == string("son"));
    CHECK(T.relation("sholmo") == string("son"));

    T.addMother("bat-sheva","sholmo"); 
    CHECK(T.relation("bat-sheva") == string("mother"));
    CHECK(T.relation("bat-sheva") == string("mother"));

    T.addMother("hava","hevel"); 
    CHECK(T.relation("hava") == string("mother"));
    CHECK(T.relation("hava") == string("mother"));

    T.addFather("david","sholmo"); 
    CHECK(T.relation("sholmo") == string("son"));
    CHECK(T.relation("sholmo") == string("son"));

    T.addMother("bat-sheva","sholmo"); 
    CHECK(T.relation("bat-sheva") == string("mother"));
    CHECK(T.relation("bat-sheva") == string("mother"));

    T.addMother("hava","hevel"); 
    CHECK(T.relation("hava") == string("mother"));
    CHECK(T.relation("hava") == string("mother"));

    T.addFather("david","sholmo"); 
    CHECK(T.relation("sholmo") == string("son"));
    CHECK(T.relation("sholmo") == string("son"));

    T.addMother("bat-sheva","sholmo"); 
    CHECK(T.relation("bat-sheva") == string("mother"));
    CHECK(T.relation("bat-sheva") == string("mother"));

    T.addMother("hava","hevel"); 
    CHECK(T.relation("hava") == string("mother"));
    CHECK(T.relation("hava") == string("mother"));

    T.addFather("david","sholmo"); 
    CHECK(T.relation("sholmo") == string("son"));
    CHECK(T.relation("sholmo") == string("son"));

    T.addMother("bat-sheva","sholmo"); 
    CHECK(T.relation("bat-sheva") == string("mother"));
    CHECK(T.relation("bat-sheva") == string("mother"));

    T.addMother("hava","hevel"); 
    CHECK(T.relation("hava") == string("mother"));
    CHECK(T.relation("hava") == string("mother"));

    T.addFather("david","sholmo"); 
    CHECK(T.relation("sholmo") == string("son"));
    CHECK(T.relation("sholmo") == string("son"));

    T.addMother("bat-sheva","sholmo"); 
    CHECK(T.relation("bat-sheva") == string("mother"));
    CHECK(T.relation("bat-sheva") == string("mother"));

    T.addMother("hava","hevel"); 
    CHECK(T.relation("hava") == string("mother"));
    CHECK(T.relation("hava") == string("mother"));

    T.addFather("david","sholmo"); 
    CHECK(T.relation("sholmo") == string("son"));
    CHECK(T.relation("sholmo") == string("son"));

    T.addMother("bat-sheva","sholmo"); 
    CHECK(T.relation("bat-sheva") == string("mother"));
    CHECK(T.relation("bat-sheva") == string("mother"));

    T.addMother("hava","hevel"); 
    CHECK(T.relation("hava") == string("mother"));
    CHECK(T.relation("hava") == string("mother"));

    T.addFather("david","sholmo"); 
    CHECK(T.relation("sholmo") == string("son"));
    CHECK(T.relation("sholmo") == string("son"));

    T.addMother("bat-sheva","sholmo"); 
    CHECK(T.relation("bat-sheva") == string("mother"));
    CHECK(T.relation("bat-sheva") == string("mother"));

    T.addMother("hava","hevel"); 
    CHECK(T.relation("hava") == string("mother"));
    CHECK(T.relation("hava") == string("mother"));

    T.addFather("david","sholmo"); 
    CHECK(T.relation("sholmo") == string("son"));
    CHECK(T.relation("sholmo") == string("son"));

    T.addMother("bat-sheva","sholmo"); 
    CHECK(T.relation("bat-sheva") == string("mother"));
    CHECK(T.relation("bat-sheva") == string("mother"));

    T.addMother("hava","hevel"); 
    CHECK(T.relation("hava") == string("mother"));
    CHECK(T.relation("hava") == string("mother"));

    T.addFather("david","sholmo"); 
    CHECK(T.relation("sholmo") == string("son"));
    CHECK(T.relation("sholmo") == string("son"));

    T.addMother("bat-sheva","sholmo"); 
    CHECK(T.relation("bat-sheva") == string("mother"));
    CHECK(T.relation("bat-sheva") == string("mother"));

    T.addMother("hava","hevel"); 
    CHECK(T.relation("hava") == string("mother"));
    CHECK(T.relation("hava") == string("mother"));

    T.addFather("david","sholmo"); 
    CHECK(T.relation("sholmo") == string("son"));
    CHECK(T.relation("sholmo") == string("son"));

    T.addMother("bat-sheva","sholmo"); 
    CHECK(T.relation("bat-sheva") == string("mother"));
    CHECK(T.relation("bat-sheva") == string("mother"));

    T.addMother("hava","hevel"); 
    CHECK(T.relation("hava") == string("mother"));
    CHECK(T.relation("hava") == string("mother"));

    T.addFather("david","sholmo"); 
    CHECK(T.relation("sholmo") == string("son"));
    CHECK(T.relation("sholmo") == string("son"));

    T.addMother("bat-sheva","sholmo"); 
    CHECK(T.relation("bat-sheva") == string("mother"));
    CHECK(T.relation("bat-sheva") == string("mother"));

    T.addMother("hava","hevel"); 
    CHECK(T.relation("hava") == string("mother"));
    CHECK(T.relation("hava") == string("mother"));

    T.addFather("david","sholmo"); 
    CHECK(T.relation("sholmo") == string("son"));
    CHECK(T.relation("sholmo") == string("son"));

    T.addMother("bat-sheva","sholmo"); 
    CHECK(T.relation("bat-sheva") == string("mother"));
    CHECK(T.relation("bat-sheva") == string("mother"));

    T.addMother("hava","hevel"); 
    CHECK(T.relation("hava") == string("mother"));
    CHECK(T.relation("hava") == string("mother"));

    T.addFather("david","sholmo"); 
    CHECK(T.relation("sholmo") == string("son"));
    CHECK(T.relation("sholmo") == string("son"));

    T.addMother("bat-sheva","sholmo"); 
    CHECK(T.relation("bat-sheva") == string("mother"));
    CHECK(T.relation("bat-sheva") == string("mother"));

    T.addMother("hava","hevel"); 
    CHECK(T.relation("hava") == string("mother"));
    CHECK(T.relation("hava") == string("mother"));

    T.addFather("david","sholmo"); 
    CHECK(T.relation("sholmo") == string("son"));
    CHECK(T.relation("sholmo") == string("son"));

    T.addMother("bat-sheva","sholmo"); 
    CHECK(T.relation("bat-sheva") == string("mother"));
    CHECK(T.relation("bat-sheva") == string("mother"));

    T.addMother("hava","hevel"); 
    CHECK(T.relation("hava") == string("mother"));
    CHECK(T.relation("hava") == string("mother"));

    T.addFather("david","sholmo"); 
    CHECK(T.relation("sholmo") == string("son"));
    CHECK(T.relation("sholmo") == string("son"));

    T.addMother("bat-sheva","sholmo"); 
    CHECK(T.relation("bat-sheva") == string("mother"));
    CHECK(T.relation("bat-sheva") == string("mother"));

    T.addMother("hava","hevel"); 
    CHECK(T.relation("hava") == string("mother"));
    CHECK(T.relation("hava") == string("mother"));

    T.addFather("david","sholmo"); 
    CHECK(T.relation("sholmo") == string("son"));
    CHECK(T.relation("sholmo") == string("son"));

    T.addMother("bat-sheva","sholmo"); 
    CHECK(T.relation("bat-sheva") == string("mother"));
    CHECK(T.relation("bat-sheva") == string("mother"));

    T.addMother("hava","hevel"); 
    CHECK(T.relation("hava") == string("mother"));
    CHECK(T.relation("hava") == string("mother"));

    T.addFather("david","sholmo"); 
    CHECK(T.relation("sholmo") == string("son"));
    CHECK(T.relation("sholmo") == string("son"));

    T.addMother("bat-sheva","sholmo"); 
    CHECK(T.relation("bat-sheva") == string("mother"));
    CHECK(T.relation("bat-sheva") == string("mother"));

    T.addMother("hava","hevel"); 
    CHECK(T.relation("hava") == string("mother"));
    CHECK(T.relation("hava") == string("mother"));

    T.addFather("david","sholmo"); 
    CHECK(T.relation("sholmo") == string("son"));
    CHECK(T.relation("sholmo") == string("son"));

    T.addMother("bat-sheva","sholmo"); 
    CHECK(T.relation("bat-sheva") == string("mother"));
    CHECK(T.relation("bat-sheva") == string("mother"));

    T.addMother("hava","hevel"); 
    CHECK(T.relation("hava") == string("mother"));
    CHECK(T.relation("hava") == string("mother"));



   



}  

