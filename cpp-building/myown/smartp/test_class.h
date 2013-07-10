#ifndef _TESTCLASS_H
 #define _TESTCLASS_H
 
 #include <iostream>
 
 class BaseClass {
 public:
     BaseClass() {
         std::cout << "Base Constructor" << std::endl;
     }
 
     virtual ~BaseClass() {
         std::cout << "Base Destructor" << std::endl;
     }
 
     virtual void print() const{
         std::cout << "Base Class" << std::endl;
     }
 };
 
 class DerivedClass : public BaseClass {
 public:
     DerivedClass() {
         std::cout << "Derived Constructor" << std::endl;
     }
 
     ~DerivedClass() {
         std::cout << "Derived Destructor" << std::endl;
     }
 
     virtual void print() const{
         std::cout << "Derived Class" << std::endl;
     }
 };
 
 #endif //_TESTCLASS_H
