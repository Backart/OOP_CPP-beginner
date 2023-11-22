//
//  main.cpp
//  OOP_
//
//  Created by admin on 08.11.2023.
//

#include <iostream>
using std::string;

class AbstractEmployee{
    virtual void AskForPromotion()=0;
};

class Employee:AbstractEmployee{ 
private:
    int Age;
    string Company;
protected:
    string Name;
public:
    void setAge(int age){
        if(age >= 18)
        Age = age;
    }
    int getAge(){
        return Age;
    }
    void setCompany(string company){
        Company = company;
    }
    string getCompany(){
        return Company;
    }
    void setName(string name){
        Name = name;
    }
    string getName(){
        return Name;
    }

    void IntroduceYourself(){
        std::cout << "Name - " << Name << std::endl;
        std::cout << "Company - " << Company << std::endl;
        std::cout << "Age - " << Age << std::endl;
    }
    Employee(int age, string name, string company){
        Name = name;
        Company = company;
        Age= age;
    }

    void AskForPromotion(){
        if(Age > 30)
        std::cout << Name << " got promoted!" << std::endl;
        else
        std::cout << Name << " sorry no promotion for u!" << std::endl;
    }

    virtual void Work(){
        std::cout << Name << "is cheking email, task backlog, performing task..." << std::endl;
    }
};

class Developer:public Employee{
public:
    string FavProgLang;
    //Constructor
    Developer(string name, string company, int age, string favProgLang)
        :Employee(age, name, company)
    {
        FavProgLang = favProgLang;
    }
    void FixBug(){
        std::cout << Name << " fixed bug using " << FavProgLang << std::endl;
    }

    void Work(){
        std::cout << Name << " fixied bug using " << FavProgLang << std::endl;
    }
};

class Teacher:public Employee{
public:
    string Subject;
    void PrepareLesson(){
        std::cout << Name << " is preparing " << Subject << " lesson " << std::endl;
    }
    //Constructor
    Teacher(string name, string company, int age, string subject)
        :Employee(age, name, company)
    {
        Subject = subject;
    }

    void Work(){
        std::cout << Name << " is teaching " << Subject << std::endl;
    }
};

int main(int argc, const char * argv[]) {
    Developer d = Developer("Sladina", "YT-CodeBeauty", 25, "C++");
    Teacher t = Teacher("Jack", "Cool School", 35, "History");

    Employee* e1 = &d;
    Employee* e2 = &t;

    e1->Work();
    e2->Work();

    return 0;
}
