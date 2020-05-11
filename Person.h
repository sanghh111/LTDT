#pragma once
#include<string>
#include<iostream>
class date;
class Person;
class date
{
    int day,month,year;
    bool isvalid;
    public:
        date(date&);
        date(int , int , int);
        friend std::ostream& operator<<(std::ostream &out,date temp);
        date operator=(date temp);
        // friend std::iostream operator>>(std::iostream &in,date temp);
        ~date();
};

class Person
{
    protected:
        std::string id;
        std::string name;
        date birthday;
    public:
        Person(std::string,std::string,date&);
        void set_id(std::string);
        void set_name(std::string);
        void set_birthday(date);
        std::string get_id();
        std::string get_name();
        date get_birthday();
        friend std::ostream& operator<<(std::ostream&,Person);
};

class Student : public Person
{
    float dtb;
    static Student* head;
    static Student* tail;
    bool isvaild;
    Student* next;
    public:
        Student(float,std::string,std::string,date);
        float get_dtb();
        void set_dtb(float);
        void Rank();
        friend std::ostream& operator<<(std::ostream&,Student);
};

class Teacher : public Person
{
    int hsl;
    public:
        Teacher(int);
        int get_hsl();
        void set_hsl(int);
        void CalSalary();
        friend std::ostream& operator<<(std::ostream&,Teacher);
};