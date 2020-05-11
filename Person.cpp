#include"Person.h"
using namespace std;

date a(0,0,0);

date::date(date& temp)
{
    day=temp.day;
    month=temp.day;
    year=temp.year;
    isvalid=temp.isvalid;
}

date::date(int day=0,int month=0,int year=0)
{ 
if( month>0 && month<=12 && day>0 && day<=31)
    	if(day==31 && (month == 4 || month == 6 || month ==9 || month ==11))
	    {
	    		isvalid=0;
		cout<<"Date not valid";	
		}
		else
		if(day >= 29 && year%4==0 && month == 2)
		{
	    		isvalid=0;
		cout<<"Date not valid";	
		}
		else
		if(day >= 28 && year%4!=0 && month == 2)
		{
					isvalid=0;
		cout<<"Date not valid";
		}
		else 
		   {
			this->day=day;
			this->month=month;
			this->year=year;
			isvalid=1;
			}
    else
    {
        		isvalid=0;
		cout<<"Date not valid";
    }
}    
ostream& operator<<(ostream &out,date temp)
{
    if(temp.isvalid)
        out<<temp.day<<"/"<<temp.month<<"/"<<temp.year;
    else
        out<<"Date not valid"<<endl;
    return out;
}
date::~date()
{
    
}
date date::operator=(date temp)
{
    day=temp.day;
    month=temp.month;
    year=temp.year;
    isvalid=temp.isvalid;
    return *this;
}

Person::Person(string id="",string name="",date& birthday=a)
{
    this->id=id;
    this->name=name;
    this->birthday=birthday;
}

void Person::set_id(string id)
{
    this->id=id;
}

void Person::set_name(string name)
{
    this->name=name;
}

void Person::set_birthday(date birthday)
{
    this->birthday=birthday;
}

string Person::get_id()
{
    return id;
}

string Person::get_name()
{
    return name;
}

date Person::get_birthday()
{
    return birthday;
}

ostream& operator<<(std::ostream& out ,Person temp)
{
    out<<"Id: "<<temp.id<<endl;
    out<<"Name: "<<temp.name<<endl;
    out<<"Birthday: "<<temp.birthday;
    return out;
}

Student* Student::head=NULL;
Student* Student::tail=NULL;
Student::Student(float dtb=5,string name="",string id="",date birthday=a)
{
    Person(id,name,birthday);
    if(dtb<0||dtb>10)
        {
            isvaild=0;
        }
    isvaild=1;
    this->dtb=dtb;
    if(head==NULL)
    {
        head=tail=this;
    }
    else 
    tail->next=this;
    tail=this;
}
