#pragma once

class Number
{
   char* value;
   int base;
   long long convertToBase10() const;
   void convertFromBase10(long long val,int otherbase);

public:
   Number(const char * value, int base); // where base is between 2 and 16
   ~Number();

   Number(const Number& other);
   Number(Number&& other);

   Number& operator= (const Number& other);
   Number& operator= (Number&& other);

   Number(int val);
   Number& operator=(int value);
   Number& operator=(const char* value);

   friend Number operator+(const Number& n1,const Number& n2);
   friend Number operator-(const Number& n1,const Number& n2);

   Number& operator+=(const Number& other);

   char operator[](int index) const;

   bool operator>(const Number& other) const;
   bool operator<(const Number& other) const;
   bool operator>=(const Number& other) const;
   bool operator<=(const Number& other) const;
   bool operator==(const Number& other) const;
   bool operator!=(const Number& other) const;

   Number& operator--();
   Number operator--(int);

   void SwitchBase(int newBase);
   void Print() const;
   int  GetDigitsCount() const; // returns the number of digits for the current number
   int  GetBase() const; // returns the current base
};
