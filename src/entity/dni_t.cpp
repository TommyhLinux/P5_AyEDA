/* 
 * @file   dni_t.cpp
 * @author Tomás González Martín
 * @brief  Práctica #05: Ordenación
 *
 * Created on 16 de Abril de 2018, 05:49
 */
#include "../../lib/dni_t.h"


dni_t::dni_t(void){
    //srand (time(NULL));
    dni_ = 30000000 + rand() % 99999999;
   
}

dni_t::dni_t(int dni, char character):
dni_(dni),
character_(character)
{}

dni_t::dni_t(int dni, char character, string name, string surname):
dni_(dni),
character_(character),
name_(name),
surname_(surname)
{}

dni_t::dni_t(const dni_t& dni):
dni_(dni.dni_),
character_(dni.character_),
name_(dni.name_),
surname_(dni.surname_)
{}

dni_t::~dni_t(){
    dni_ = -1;
    character_ = ' ';
    name_.clear();
    surname_.clear();
}

int dni_t::getDni(void){
    return dni_;
}

char dni_t::getCharacter(void){
    return character_;
}

string dni_t::getName(void){
    return name_;
}

string dni_t::getSurname(void){
    return surname_;
}

void dni_t::setDni(int dni){
    dni_ = dni;
}

void dni_t::setCharacter(int character){
    character_ = character;
}
   
void dni_t::setName(string name){
    name_ = name;
}
    
void dni_t::setSurname(string surname){
    surname_ = surname;
}


bool dni_t::operator ==(const dni_t& dni){
    return (dni_ == dni.dni_ && character_ == dni.character_);
}

bool dni_t::operator <=(const dni_t& dni){
    return (dni_ <= dni.dni_) || (dni_ == dni.dni_ && character_ <= dni.character_);
}

bool dni_t::operator <(const dni_t& dni){
    return (dni_ < dni.dni_) || (dni_ == dni.dni_ && character_ < dni.character_);
}

bool dni_t::operator >=(const dni_t& dni){
    return (dni_ >= dni.dni_) || (dni_ == dni.dni_ && character_ >= dni.character_);
}

bool dni_t::operator >(const dni_t& dni){
    return (dni_ > dni.dni_) || (dni_ == dni.dni_ && character_ > dni.character_);
}

bool dni_t::operator !=(const dni_t& dni){
    return (dni_ != dni.dni_ && character_ != dni.character_);
}


bool dni_t::operator==(int num){
    return dni_ == num;
}

bool dni_t::operator<=(int num){
    return dni_ <= num;
}

bool dni_t::operator<(int num){
    return dni_ < num;
}

bool dni_t::operator>=(int num){
    return dni_ >= num;
}

bool dni_t::operator>(int num){
    return dni_ > num;
}

bool dni_t::operator!=(int num){
    return dni_ != num;
}



dni_t::operator int() const{
    return dni_;
}


ostream& operator<<(ostream& os, dni_t& dni){
    os << dni.getDni() << "-" << dni.getCharacter() << endl;//"\t" << dni.getName() << " " << dni.getSurname() << endl;
    return os;
}

istream& operator>>(istream& is, dni_t& dni){
    int interger = 0;
    is >> interger;
    dni.setDni(interger);
}