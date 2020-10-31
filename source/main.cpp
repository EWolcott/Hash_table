#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "hash.h"

using namespace cs273;

std::string getname() //make a random name
{
    std::vector<std::string> _firstNames;
    std::vector<std::string> _lastNames;

    _firstNames = {"Roy", "Wyatt", "Owen", "Herschel", "Bill", "Florencio", "Guy", "Renato", "Octavio", "Alexis",
                   "Gaylord", "Kyle", "Danny", "Aurelio", "Wilfredo", "Mel", "Rosario", "Clay", "Max", "Dino", "Elvin",
                   "Donnell", "Darrell", "Seymour", "Chong", "Lionel", "Noel", "Victor", "Marc", "Trevor", "Rusty", "Russ",
                   "Jonathan", "Chris", "Chauncey", "Emmitt", "Antony", "Deandre", "Anthony", "Raymond", "Eliseo", "Kris",
                   "Travis", "Felton", "Britt", "Pierre", "Patrick", "Mauro", "Erwin", "Gregorio"};
    _lastNames = {"Parrish", "Garner", "Blackwell", "Valentine", "Guerra", "Cox", "Kirk", "Clements", "Pratt",
                  "Coffey", "Romero", "Mayo", "Patel", "Page", "Oneal", "Bowen", "Chapman", "Buchanan", "Schmitt", "Mckee",
                  "Foster", "Collier", "Shea", "Velez", "Booth"};

    std::string first = _firstNames[rand() % 50];
    std::string last = _lastNames[rand() % 25];
    std::string name = first + " " + last;
    return name;
}

int getid() //make a random number
{
    int id = (rand() % 9999 + 1000);
    return id;
}

Hash<int> repeat(Hash<int> htable)
{                           //display all functions...PLUS RECURSION!!
    pair<int> p("Age", 77); //build a pair
    std::cout << "Displaying an empty hash table:" << std::endl;
    htable.displayHash();
    htable.insert(p);
    std::cout << "Inserting a pair value:" << std::endl;
    htable.displayHash();
    htable.remove(p);
    std::cout << "Removing the value based on a pair parameter:" << std::endl;
    htable.displayHash();
    htable.insert(p);
    std::cout << "Reinserting pair:" << std::endl;
    htable.displayHash();
    htable.remove("Age");
    std::cout << "Removing the value based on key parameter" << std::endl;
    htable.displayHash();
    htable.insert(p);
    pair<int> q("Ages", 79);
    pair<int> r("Age", 23);
    pair<int> s("fire", 8675309);
    htable.insert(q);
    htable.insert(r);
    htable.insert(s);
    std::cout << "Inserting same pair and four additional pairs:" << std::endl;
    htable.displayHash();
    htable.remove(p);
    htable.insert(r);
    std::cout << "Removing the pair and replacing it with a duplicate pair:" << std::endl;
    htable.displayHash();
    std::list<pair<int>>::iterator iter;
    iter = htable.locate("Ages");
    iter->second = 99999;
    std::cout << "Locating pair with iterator and changing value to 99999:" << std::endl;
    htable.displayHash();
    for (int i = 0; i < 60; i++)
    {
        std::string name = getname();
        int number = getid();
        pair<int> X(name, number);
        htable.insert(X);
    }

    std::cout << "Now let's make 60 pairs at random and see what happens:" << std::endl;
    htable.displayHash();

    std::cout << "Do you want to repeat all of the previous function tests but with the now much more robust hash table?" << std::endl;
    std::cout << "1. Yup, let's fill up that screen some more!" << std::endl;
    std::cout << "2. No thank you, I'm rather content." << std::endl;
    int choice;
    std::cin >> choice;
    switch (choice)
    {
    case 1:
        htable = repeat(htable);
        break;
    case 2:
        std::cout << "Understandable." << std::endl;
        break;
        break;
    }
    return htable;
}

int main()
{

    srand(time(NULL));                 //seed a random number
    Hash<int> htable(20);              //build a hash table for which to begin
    Hash<int> copyhtable(20);          //build a hash table for which to copy
    copyhtable = repeat(htable);       //demonstrate all functions
    Hash<int> emptyhtable(copyhtable); //copy!

    std::cout << "Just one last test: The copy constructor!" << std::endl;
    emptyhtable.displayHash();

    std::cout << "Have a lovely day!" << std::endl; //be polite

    return 0;
}
