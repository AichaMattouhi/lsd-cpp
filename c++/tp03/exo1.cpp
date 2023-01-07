#include <iostream>



using namespace std;

class Contact 
{
  string first_name ;
  string last_name ;
  string nickname;
  string phone_number;
  public:
  Contact() { };

  Contact (string fname,string lname, string nname,string number):first_name(fname),last_name(lname),nickname(nname),phone_number(number) {}
 void set_firstname(string firstname)
  {
     first_name=firstname;
  }
  void set_lastname(string lastname)
  {
     last_name=lastname;
  }
  
  void  set_nickname(string nick_name)
  {
    nickname=nick_name;
  }
  
  void set_phonenumber(string phonenumber)
  {
      phone_number=phonenumber;
  }
  
  string get_firstname()
  {
    return first_name;
  }
  
   string get_lastname()
  {
     return last_name ;
  }
  
   string get_nickname()
  {
     return nickname ;
  }
  
   string get_phonenumber()
  {
     return phone_number;
  }  
};
  

  
  
class phonebook
 {
  Contact* contacts=new Contact [8];
  int nbr_contacts;
  public :
  phonebook();
  void add(string first_name,string last_name, string nickname,string phone_number);
  void display( int i);
  void exit();
 };
 

phonebook::phonebook() 
{
	nbr_contacts=0;
}



void phonebook::add(string firstname,string lastname, string nick_name,string phonenumber)
{
  
  if (nbr_contacts==8)
    {
      contacts[0].set_firstname(firstname);
      contacts[0].set_lastname(lastname);
      contacts[0].set_nickname(nick_name);
      contacts[0].set_phonenumber(phonenumber);
    
    }  
  else 
  {
      int i=nbr_contacts;
      contacts[i].set_firstname(firstname);
      contacts[i].set_lastname(lastname);
      contacts[i].set_nickname(nick_name);
      contacts[i].set_phonenumber(phonenumber);
      nbr_contacts++;
       
  }
  
}


void phonebook ::display( int i)
{
	string extr="          ";
	
	
	printf(" %d |%.10s|%.10s|%.10s|\n",i,(contacts[i].get_firstname()+extr).c_str(),(contacts[i].get_lastname()+extr).c_str(),(contacts[i].get_nickname()+extr).c_str());
	
	
	
	
}

void phonebook::exit()
{
	delete  contacts;
	contacts = new Contact[8];
	cout<<"the phonebook has been cleared"<<endl;
}
   
