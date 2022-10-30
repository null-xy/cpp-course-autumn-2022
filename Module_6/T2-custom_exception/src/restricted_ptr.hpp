/* Add include guards here */

/* 
 * Copy your implementation from the last round here (or wait for
 * the example answer to come out and copy that) and wrap it inside a 
 * WeirdMemoryAllocator namespace.
 * 
 * Changes to the class:
 * 
 * Add a new member string to store the use of the RestrictedPtr 
 * and add a new string parameter, which is the use of the pointer, to the 
 * constructor that originally only takes a pointer. Remember to modify
 * copying to also copy the use. If the pointer is automatically set to 
 * a nullptr (i.e. not given in the constructor), the use is "nullptr".
 * 
 * The copy constructor and assigment operators should throw a RestrictedCopyException 
 * if the operations fail (as they in some cases should). When the copying
 * fails, only the exception should be thrown and no changes should be made
 * to the existing pointer.
 * 
 * The GetData function should throw a RestrictedNullException with the use
 * of the RestrictedPtr given to it if the pointer is null.
 * 
 * The class shouldn't leak any memory.
*/
#ifndef AALTO_ELEC_RESTRICTED_PTR_CLASS
#define AALTO_ELEC_RESTRICTED_PTR_CLASS

#include <iostream>
#include <memory>
#include <exception>
#include <sstream>
#include "restricted_ptr_ex.hpp"

namespace WeirdMemoryAllocator{
template <class T>
class RestrictedPtr{
    public:
    std::shared_ptr<T> ptr;
    //T* ptr;
    int* counter_;
    std::string ptr_use_;
    //T ptr_use_;
    
    RestrictedPtr():ptr(nullptr){ 
        //throw RestrictedNullException(ptr_use_); 
        counter_ = new int(1);
        ptr_use_="nullptr";
    }

    RestrictedPtr(T* p):ptr(p){
       // if(p==nullptr){
       //     throw RestrictedNullException(ptr_use_); 
       // }else{
            //this->ptr=p;
            /*const void * address = static_cast<const void*>(p);
            std::stringstream ss;
            ss << address;
            std::string address_str = ss.str();
            ptr_use_=address_str;*/
            ptr_use_="default";
            counter_ = new int(1);
        //}
        //counter_ = new int(1);
        //ptr_use_="nullptr";
    }
    
    RestrictedPtr(T* p, std::string str):ptr(p){
        //if(p==nullptr){
        //    throw RestrictedNullException(str); 
        //}else{
            /*const void * address = static_cast<const void*>(p);
            std::stringstream ss;
            ss << address;
            std::string address_str = ss.str();
            */
            ptr_use_=str;
            counter_ = new int(1);

        //}
        //counter_ = new int(1);
        //ptr_use_="nullptr";
    }
/*
    RestrictedPtr(T* p):ptr(p),counter_(new int(1)),ptr_use_(str){
        if(p==nullptr){
            throw RestrictedNullException(ptr_use_); 
        }else{
            const void * address = static_cast<const void*>(p);
            std::stringstream ss;
            ss << address;
            std::string address_str = ss.str(); 
            //counter_ = ;
             ptr_use_=address_str;
        }
        //counter_ = new int(1);
        //ptr_use_="nullptr";
    }*/

    //RestrictedPtr(std::nullptr_t, const char [17])

    RestrictedPtr(RestrictedPtr<T> &other){
        if((other.GetRefCount())<3){
            (*other.counter_)++;
            ptr=other.ptr;
            counter_=other.counter_;
            //ptr_use_=*ptr;
        }else{
            //ptr = nullptr;
            //counter_ = new int(1);
            throw RestrictedCopyException(other.ptr_use_);
        }
    }
        /*if((*other.counter_)>=3){
            throw RestrictedCopyException(ptr_use_);
            //ptr = nullptr;
            //counter_ = new int(1);
        }else{
            (*other.counter_)++;
            ptr=other.ptr;
            counter_=other.counter_;
            ptr_use_=other.ptr_use_;
        }*/
        /*if((*t.counter_)<3){
            (*t.counter_)++;
            ptr=t.ptr;
            counter_=t.counter_;
        }else{
            ptr = nullptr;
            counter_ = new int(1);
        }
        */

    ~RestrictedPtr(){
        if((*counter_)>1){
            (*counter_)--;
        }else{
            (*counter_)--;
            this->Release();
        }
    }
    RestrictedPtr<T>& operator=(const RestrictedPtr<T> &other){
        if((*other.counter_)>=3){
            throw RestrictedCopyException(other.ptr_use_);
            /*ptr = nullptr;
            counter_ = new int(1);
            ptr_use_="nullptr";*/
        }else{
            (*other.counter_)++;
            ptr=other.ptr;
            counter_=other.counter_;
            ptr_use_=other.ptr_use_;
        }
        return *this;
    }
    //T& GetData() const{
    T& GetData() {
        if(this->ptr==nullptr){
            throw RestrictedNullException(this->ptr_use_);

        }else{
            return *ptr.get();
            //return *ptr;
        }
    }

    T* GetPointer() {
        if(ptr==nullptr){
            return nullptr;
        }else{
            return ptr.get();
        }
    }
    int GetRefCount() const {
        return *this->counter_;
        //return counter_;
    }
    void Release(){
        if(this->GetRefCount()==0){
            delete counter_;
            //delete ptr;
        }
    }

};
}
#endif
