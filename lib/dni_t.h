/* 
 * @file   dni_t.h
 * @author Tomás González Martín
 * @brief  Práctica #05: Ordenación
 *
 * Created on 16 de Abril de 2018, 05:49
 */
#pragma once

#include <vector>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <ctime>

#ifndef DNI_T_H
#define DNI_T_H

using namespace std;

class dni_t{
public:
    dni_t(void);
    dni_t(int dni, char character);
    dni_t(int dni, char character, string name, string surname);
    dni_t(const dni_t& dni);
    ~dni_t(void);
    
    int getDni(void);
    char getCharacter(void);
    string getName(void);
    string getSurname(void);
    void setDni(int);
    void setCharacter(int);
    void setName(string);
    void setSurname(string);
    
    
    bool operator==(const dni_t& dni);
    bool operator<=(const dni_t& dni);
    bool operator<(const dni_t& dni);
    bool operator>=(const dni_t& dni);
    bool operator>(const dni_t& dni);
    bool operator!=(const dni_t& dni);
    
    bool operator==(int num);
    bool operator<=(int num);
    bool operator<(int num);
    bool operator>=(int num);
    bool operator>(int num);
    bool operator!=(int num);
    
        
    operator int() const;
    
    
    
private:
    int dni_;
    char character_;
    string name_;
    string surname_;
};



#endif /* DNI_T_H */

