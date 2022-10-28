#ifndef AALTO_ELEC_CPP_RESTRICTED_PTR_CLASS
#define AALTO_ELEC_CPP_RESTRICTED_PTR_CLASS

#include "restricted_ref_counter.hpp"

/*
    Implement a class RestrictedPtr that holds a pointer of any type with at least the following members:
        - default constructor (takes no parameters)
        - constructor with a raw pointer parameter
        - copy constructor
        - destructor
        - copy assignment operator
        - function GetData that takes no parameters and returns the data the raw pointer refers to.
            The data returned should be such that modifying it modifies the data the pointer refers to.
        - function GetPointer that takes no parameters and returns the raw pointer
        - function GetRefCount that takes no parameters and returns an int with the reference count
    
    At any time the objects should keep track of how many references there are to a pointer
    and not allow more than 3 references. If the reference count drops to 0, the referenced
    pointer's memory should be released. If the reference count is already 3 when copying,
    the copier should set it's pointer to nullptr and reference count to 1.
    NOTE: GetPointer, GetData and GetRefCount are needed for the tests to run
*/

#include <iostream>
template <class T>
class RestrictedPtr{
    T* ptr;
    Restricted_ref_counter* counter_;

    public:
    //default constructor
    //RestrictedPtr(){}

    RestrictedPtr():ptr(nullptr),counter_(nullptr){ }
    //constructor with a raw pointer parameter
    RestrictedPtr(T* p){
        ptr=p;
        counter_=new Restricted_ref_counter();
        counter_->SetRef();
    }
    //copy constructor
    //RestrictedPtr(const T& p);
    RestrictedPtr(RestrictedPtr<T> &t){
        if((t.counter_->GetRefCnt())<3){
            //t.counter_->reference_cnt_++;
            t.counter_->AddRef();
            //*t.counter_).reference_cnt_++;
            ptr=t.ptr;
            counter_=t.counter_;
        }else{
            ptr = nullptr;
            counter_=new Restricted_ref_counter();
            counter_->SetRef();
        }
    }
    //RestrictedPtr<double>::RestrictedPtr()
    //RestrictedPtr<T*>()
    //undefined reference to `RestrictedPtr<Car>::RestrictedPtr(Car*)'
    //destructor
    ~RestrictedPtr() { 
        if( (this->counter_) && ((*counter_).GetRefCnt()>1)){
            //(*counter_).reference_cnt_--;
            counter_->RemoveRef();
            //std::cout << "reference_cnt_--:  "<<(*counter_).reference_cnt_ << std::endl;
        }else{
            counter_->RemoveRef();
            this->Release();
            //delete (counter_);
            //delete (ptr);
            //std::cout << "destructor "<<(*counter_).reference_cnt_ << std::endl;
        }
        }

    //copy assignment operator
    //‘RestrictedPtr<T>& RestrictedPtr<T>::operator=(const RestrictedPtr<T>&) [with T = int]
    RestrictedPtr<T>& operator=(const RestrictedPtr<T> &other){
    //RestrictedPtr<T>& operator=(const RestrictedPtr<T> &other){
        if((other.counter_->GetRefCnt())<3){
            ptr=other.ptr;
            counter_=other.counter_;
        }else{
            ptr = nullptr;
            counter_=new Restricted_ref_counter();
            counter_->SetRef();
        }
        return *this;
    }

//template <typename T1>
    T& GetData(){
        return (*ptr);
    }

    T* GetPointer(){
        return ptr;
    }
    int GetRefCount(){
        return this->counter_->GetRefCnt();
    }
    void Release(){
        if(this->GetRefCount()==0){
            delete this->ptr;
            delete this->counter_;
        }
    }
};


#endif