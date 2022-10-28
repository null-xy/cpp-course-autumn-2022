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

#include <iostream>
#include <memory>

template <class T>
class RestrictedPtr{
    public:
    std::shared_ptr<T> ptr;
    int* counter_;
    
    RestrictedPtr():ptr(nullptr){ 
        counter_ = new int(1);
     }
    RestrictedPtr(T* p):ptr(p){
        counter_ = new int(1);
    }
    RestrictedPtr(RestrictedPtr<T> &t){
        if((*t.counter_)<3){
            (*t.counter_)++;
            ptr=t.ptr;
            counter_=t.counter_;
        }else{
            ptr = nullptr;
            counter_ = new int(1);
        }
    }
    ~RestrictedPtr(){
        if((*counter_)>1){
            (*counter_)--;
        }else{
            (*counter_)--;
            this->Release();
        }
    }
    RestrictedPtr<T>& operator=(const RestrictedPtr<T> &other){
        if((*t.counter_)<3){
            (*t.counter_)++;
            ptr=t.ptr;
            counter_=t.counter_;
        }else{
            ptr = nullptr;
            counter_ = new int(1);
        }
        return *this;
    }
    T& GetData(){
        return *ptr.get();
    }

    T* GetPointer(){
        if(ptr!=nullptr){
            return ptr.get();
        }else{
            return nullptr;
        }
    }
    int GetRefCount() const {
        return *this->counter_;
    }
    void Release(){
        if(this->GetRefCount()==0){
            delete counter_;
        }
    }
};