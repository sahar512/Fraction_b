#include <iostream>
#pragma once 
using namespace std; 
namespace ariel{
    class Fraction{
        private:
        int num; 
        int den; 
        void reduce(); //reduce the fraction

        public:
        //getters and setters
        int getNumerator()const; 
        int getDenominator()const; 
        void setNumerator(int num); 
        //void static setden(int den); 
        void setDenominator(int den); 
        
        Fraction(); //default constructor 
        Fraction(int num0, int den0); //fraction constructor
        Fraction(float nume);
        Fraction (const Fraction& other); //copy constructor 
        Fraction (Fraction&& other)noexcept; //move constructor 
        ~Fraction()=default; //destructor 
        //+
        const Fraction operator+(const Fraction& other)const ; 
        const Fraction operator+(const float& num)const; 
        friend const  Fraction operator+(const float& num , const Fraction &other); 
        //const Fraction operator+( float& num ,  Fraction &fun); 
        Fraction &operator ++(); 
        Fraction operator++(int);
        //-
        const Fraction operator-(const Fraction& other)const;
        const Fraction operator-(const float& num)const;
        friend const Fraction operator-(const float& num , const Fraction &other); 
        Fraction &operator --();
        Fraction operator--(int);
        //*
        const Fraction operator*(const Fraction& other)const;
        const Fraction operator*(const float& num)const;
        friend Fraction operator*(const float& num , const Fraction &other);
        // /
        const Fraction operator/(const Fraction& other)const;
        const Fraction operator/(const float& num)const;
        friend Fraction operator/(const float& nume , const Fraction& other);
        //=
        Fraction &operator=(const Fraction& frac); 
        Fraction &operator=(Fraction&& other)noexcept; 
        //==
        bool operator==(const Fraction& other)const;
        friend bool operator==(const Fraction& fun ,const float& num);
        friend bool operator==(const float& num , const Fraction& fun);
        //!=
        // bool operator!=(const Fraction& other)const;
        // bool operator!=(const float& num)const;
        // friend bool operator!=(const float& num , const Fraction& fun);
        //<
        bool operator<(const Fraction& other)const; 
        friend bool operator<(const Fraction& fun ,const float& num);
        friend bool operator<(const float& num , const Fraction& fun);
        //<=
        bool operator<=(const Fraction& other)const; 
        friend bool operator<=(const Fraction& fun ,const float& num);
        friend bool operator<=(const float& num , const Fraction& fun);
        //>
        bool operator>(const Fraction& other)const; 
        friend bool operator>(const Fraction& fun ,const float& num);
        friend bool operator>(const float& num , const Fraction& fun);
        //>=
        bool operator>=(const Fraction& other)const;
        friend bool operator>=(const Fraction& fun ,const float& num);
        friend bool operator>=(const float& num , const Fraction& fun);

        // bool operator>>(const Fraction& other)const{
        //     return true;
        // }; 
        // bool operator>>(float num){
        //     return true;
        // };
        //friend std::ostream& operator<<(std::ostream& anum ,const Fraction& fun ); 

        // bool operator<<(const Fraction& other)const{
        //     return true;
        // }; 
        // bool operator<<(float num){
        //     return true;
        // };

        friend std::ostream& operator<<(std::ostream& anum, const Fraction& fun); //input stream
        //friend std::istream& operator>>(std::istream& istr,  const Fraction& fun); 
        friend std::istream& operator>>(std::istream& istr, Fraction& fun); //output stream 
        //void reduce(); 










    };
}