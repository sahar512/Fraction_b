#include <iostream>
#include <stdio.h>
#include <math.h>
#include <iomanip>
#include <numeric>
#include <algorithm>
#include <math.h>
#include <limits>
#include "Fraction.hpp"
using namespace std; 
namespace ariel{ 
    //default constructor
    Fraction::Fraction():num(0), den(1){}  
    Fraction::Fraction(const Fraction& other): num(other.num), den(other.den){} 
    Fraction::Fraction(Fraction&& other) noexcept: num(other.num), den(other.den){}  
    Fraction::Fraction(int num0, int den0):num(num0),den(den0){
        if (den ==0) throw std::invalid_argument("denominator cannot be 0."); 
        reduce(); 
        
    }     

    // Fraction::Fraction(int num, int den){
    //     if (den ==0){
    //         throw std::invalid_argument("denominator cannot be 0."); 
    //     }
    //     else if(num ==0){
    //         this->num=0;
    //         this->den=1;  

    //     }
    //     else{
    //         this->num = num; 
    //         this->den = den; 
    //         this->reduse(); 
    //     }
    // }
    Fraction::Fraction(float nume){
        int n =(int)nume; 
        int n0 = round((nume-n)*1000); //3 dicinal
        int d=1000; 
        if(n0 ==0 ){
            num=(int)nume; 
            den=1; 
        }
        else{
            int g =std::__gcd(n0,d); 
            num=(n * d + n0)/g;
            den = d/g; 
        }
        reduce(); 
    }

    // Fraction::~Fraction{

    // }; 
    void Fraction::setNumerator(int num){

        this->num=num; 

    }
    int Fraction::getNumerator()const{
        //return this->num; 
        return num; 
    }
    void Fraction::setDenominator(int den){
        if(den ==0){
            throw std::invalid_argument("invalid denominator");
        }
        this->den=den; 
    }
    int Fraction::getDenominator()const{
        //return this->den;
        return den;  
    }
    //operator +
    const Fraction Fraction::operator+(const Fraction& other)const{
        long long newNum= (long long) (this->num * other.den)+(this->den * other.num); 
        long long newDen= (long long) this->den * other.den; 
        if((newNum < std::numeric_limits<int>::min()) || (newNum > std::numeric_limits<int>::max()) || (newDen > std::numeric_limits<int>::max()) ||(newNum < std::numeric_limits<int>::min()) ){
            throw std::overflow_error("overflow error!!"); 
        }
        return Fraction(newNum, newDen); 

    }
    const Fraction Fraction::operator+(const float& num)const{
        return (*this)+ Fraction (num); 
    }
    const Fraction operator+(const float& num, const Fraction& other){
        Fraction frac(num); 
        int newNum = (frac.getNumerator()* other.getDenominator())+ (other.getNumerator()*frac.getDenominator()); 
        int newDen = frac.getDenominator() * other.getDenominator(); 

        return Fraction(newNum,newDen);
    }
    Fraction &Fraction::operator++(){
        num += den;
        reduce(); 
        return*this; 
    }
    Fraction Fraction::operator++(int){
        Fraction f = *this; 
        ++(*this); 
        return f ; 
    }
    //operator -

     const Fraction Fraction::operator-(const Fraction& other)const{
        long long newNum= (long long) (this->num * other.den)-(this->den * other.num); 
        long long newDen= (long long) this->den * other.den; 
        long long GCD = __gcd(num,den); 
        newNum = newNum/GCD; 
        newDen = newDen/GCD; 
        if((newNum < std::numeric_limits<int>::min()) || (newNum > std::numeric_limits<int>::max()) || (newDen > std::numeric_limits<int>::max()) ||(newNum < std::numeric_limits<int>::min()) ){
            throw std::overflow_error("overflow error!!"); 
        }
        int numerator= (this->num * other.getDenominator())-(other.getNumerator()* this->den); 
        int denominator = (this->den * other.getDenominator());  
        return Fraction(numerator, denominator);
    }
    const Fraction Fraction::operator-(const float& num)const{
        return (*this) - Fraction(num); 

    }
    const Fraction operator-(const float& num , const Fraction& other){
        Fraction frac(num); 
        int newNum = (frac.getNumerator()* other.getDenominator()) - (other.getNumerator()*frac.getDenominator()); 
        int newDen = frac.getDenominator() * other.getDenominator(); 

        return Fraction(newNum,newDen);
        
        
    }
    Fraction &Fraction::operator--(){
        num -= den;
        reduce(); 
        return*this; 
    }
    // Fraction& Fraction::operator--(int){
    //     Fraction func0 = *this; 
    //     --(*this); 
    //     return func0 ; 
    // }
    Fraction Fraction::operator--(int){
        Fraction newf(*this); 
        --(*this); 
        return newf; 

    }
    //operator *

    const Fraction Fraction::operator*(const Fraction& other)const{
        if(this->num==0 || other.num ==0 ){
            return Fraction (0); 
        }
        int numerator = (this->num * other.num) ; 
        int denominator = (this->den * other.den); 
        //check overflow 
        if( numerator / other.num !=num ||numerator / num != other.num || denominator / other.den !=den){
            throw overflow_error("overflow error"); 
        }
        return Fraction(numerator, denominator); 

    }
    const Fraction Fraction::operator*(const float& num)const{
        return (*this) * Fraction(num); 

    }
    Fraction operator*(const float& num , const Fraction &other){
        return Fraction(num) * other ; 
    }
    //operator /
    const Fraction Fraction::operator/(const Fraction& other)const{
        if(other.num == 0 ){
            throw runtime_error("ERROR devide by 0"); 
        }
        if((long long)num * other.den > numeric_limits<int>::max()||(long long )den * other.num > numeric_limits<int>::max()){
            throw overflow_error("Error!");
        }
        if((num > 0 && other.num > numeric_limits<int>::max() / den) || (num<0 &&other.num < numeric_limits<int>::min()/ den) ){
            throw overflow_error("overflow Error!");
        }
        if((num > numeric_limits<int>::max() / other.den) || (num < numeric_limits<int>::min()/ other.den) ){
            throw overflow_error("overflow Error!");
        }
        int numerator = (this->num * other.den); 
        int denominator = (this->den * other.num);
        return Fraction(numerator, denominator); 
    }
    const Fraction Fraction::operator/(const float& num)const{
        if(num == 0){
            throw runtime_error("ERROR devide by 0"); 
        }
        return (*this)/ Fraction(num); 
    }
    Fraction operator/(const float& nume , const Fraction& other ){
        if(other.num ==0){
                throw runtime_error("ERROR devide by 0");
        }
        return Fraction(nume) / other; 
    }
    Fraction& Fraction::operator=(const Fraction& frac){
        if( this==&frac){
            return (*this); 
        }
        num=frac.getNumerator(); 
        den=frac.getDenominator(); 
        return(*this); 
    }
    Fraction& Fraction::operator=(Fraction&& other)noexcept{
        if(this != &other){
        num=other.num; 
        den=other.den;
        //other.num=0; 
        //other.den=1;
        }
        return(*this);
    }
    // bool operator==(const Fraction num0,const Fraction num){
    //     return (num0.getNumerator() == num.getNumerator()) && (num0.getDenominator()==num.getDenominator());  
    // }
    bool Fraction::operator==(const Fraction& other)const{
        float fract0 = (float)num / den; 
        float fract1 = (float)other.num / other.den; 
        float temp = 0.001; 
        return abs(fract0 - fract1) < temp ; 
    }
    // bool Fraction::operator==(const float& num)const{
    //     return *this == Fraction(num); 
    // }
    bool operator==(const float& num ,const Fraction& fun){
        return Fraction(num)==fun; 
    }
    bool operator==(const Fraction& fun , const float& num){
        return fun==Fraction(num); 
    }

    // bool Fraction::operator!=(const Fraction& other)const{
    //     return !(*this == other); 
    // }
    // bool Fraction::operator!=(const float& num)const{
    //     return !(*this == Fraction(num)); 
    // }
    // bool operator!=(const float& num , Fraction& fun){
    //     return !(Fraction(num)==fun); 
    // }
    
    // bool Fraction::operator<(const Fraction& other)const{
    //     return (num * other.den) < (other.num * den); 
    // }
    // // bool Fraction::operator<(const float& num)const{
    // //     return *this < Fraction(num); 
    // // }
    // bool operator<(const float& num , Fraction& fun){
    //     return Fraction(num) < fun; 
    // }
    // bool operator<(const Fraction& fun, const float& num ){
    //     return  fun < Fraction(num); 
    // }

    // bool Fraction::operator>(const Fraction& other)const{
    //     return (num * other.den) > (other.num * den); 
    // }
    // // bool Fraction::operator>(const float& num)const{
    // //     return *this > Fraction(num); 
    // // }
    // bool operator>(const float& num , Fraction& fun){
    //     return Fraction(num)>fun; 
    // }
    // bool operator>(const Fraction& fun, const float& num ){
    //     return  fun > Fraction(num); 
    // }
    
    // bool Fraction::operator<=(const Fraction& other)const{
    //     return (num * other.den) <= (other.num * den);  ; 
    // }
    // // bool Fraction::operator<=(const float& num)const{
    // //     return !(*this > Fraction(num)); 
    // // }
    // bool operator<=(const float& num , Fraction& fun){
    //     return Fraction(num) <= fun; 
    // }
    // bool operator<=(const Fraction& fun, const float& num){
    //     return fun <= Fraction(num); 
    // }
    // bool Fraction::operator>=(const Fraction& other)const{
    //     return (num * other.den) >= (other.num * den); 
    // }
    // // bool Fraction::operator>=(const float& num)const{
    // //     return !(*this < Fraction(num)); 
    // // }
    // bool operator>=(const float& num , Fraction& fun){
    //     return Fraction(num) >= fun; 
    // }
    // bool operator>=(const Fraction& fun, const float& num){
    //     return fun >= Fraction(num); 
    //}
    // ostream &operator<<(ostream &anum, const Fraction &fun){
    //     int n =fun.getNumerator();
    //     int d =fun.getDenominator(); 
    //     if(n<0 || d<0){
    //         n=abs(n); 
    //         d=abs(d); 
    //         anum<<""; 

    //     }
    //     anum <<n<<"/"<<d; 
    //     return anum; 
    // }
    bool Fraction::operator>(const Fraction& fun )const{
        return num * fun.den > fun.num * den; 
    }
    bool Fraction::operator>=(const Fraction& fun )const{
        return num * fun.den >= fun.num * den; 
    }
    bool Fraction::operator<=(const Fraction& fun )const{
        return num * fun.den <= fun.num * den; 
    }
    bool Fraction::operator<(const Fraction& fun )const{
        return num * fun.den < fun.num * den; 
    }
    bool operator<(const float& num , const Fraction& fun){
        return Fraction(num) < fun; 
    }
    bool operator<=(const float& num , const Fraction& fun){
        return Fraction(num) <= fun; 
    }
    bool operator>(const float& num , const Fraction& fun){
        return Fraction(num) > fun; 
    }
    bool operator>=(const float& num , const Fraction& fun){
        return Fraction(num) >= fun; 
    }
    bool operator<(const Fraction& fun , const float& num){
        return fun < Fraction(num); 
    }
    bool operator<=(const Fraction& fun , const float& num){
        return fun <= Fraction(num); 
    }
    bool operator>=(const Fraction& fun , const float& num){
        return fun >= Fraction(num); 
    }
    bool operator>(const Fraction& fun , const float& num){
        return fun > Fraction(num); 
    }

    
    istream& operator>>(istream &istr , Fraction& fun){
        int numm ; 
        int denn; 
        if(!(istr >> numm >> denn )) throw runtime_error("error"); 
        if(denn ==0)throw runtime_error("error"); 
        fun = Fraction(numm,denn); 
        return istr; 

    }
    ostream& operator<<(ostream &anum, const Fraction& fun){
        anum << fun.num <<"/"<<fun.den; 
        return anum; 

    }
    // istream &operator>>(istream &istr , Fraction &fun){
    //     int num ; 
    //     int den; 
    //     istr >>num>>den; 
    //     if(istr && den!=0){
    //         fun.setNumerator(num); 
    //         fun.setDenominator(den); 
    //     }
    //     else{
    //         __throw_runtime_error("error input"); 
    //     }
    //     return istr; 

    // }
    // bool operator==(const float& num)const{
    //     return *this ==Fraction(num); 
        
    // }
    // void Fraction::reduse(){
    //     int n = this->num; 
    //     int d = this->den; 
    //     if (d == 0) {
    //         throw std::invalid_argument("invalid denominator");

    //     }
    //     if (n == 0) {
    //         d = 1;
    //         return;
    //     }
    //     int gcd = std::__gcd(n, d); 
    //     n /= gcd;
    //     d /= gcd;
    //     if (d < 0) {
    //         n = -n;
    //         d = -d;
    //     } 
    // }       
    void Fraction::reduce(){
        int gcd = std::__gcd(num,den); 
        if(den==0){
            throw("den cant be zero"); 

        }
        num/=gcd; 
        den/=gcd; 
        if(den<0){
            num =-num; 
            den =-den; 
        }
    }



}