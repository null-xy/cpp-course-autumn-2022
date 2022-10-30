/* Add include guards here */

/**
 * @brief a wrapper for class RestrictedPtr
 * 
 * TODO: Implement the following methods:
 *
 * MakeRestricted: a template function that takes any type of
 * pointer as a parameter and returns a RestrictedPtr holding
 * that pointer with the use set to "RestrictedPtr instance".
 * 
 * CopyRestricted: a template function that takes a reference to
 * a RestrictedPtr as a parameter and returns a copy of it. If
 * the copying fails, prints the error in the exception to
 * standard output with a newline appended and returns a
 * default constructed RestrictedPtr.
 *
 * operator<<: a template function that takes in a ostream 
 * reference and a RestrictedPtr reference, prints the object
 * pointed to by the pointer to the stream using the << operator 
 * and returns a reference to the stream. If the pointer is null,
 * prints the return value of GetError of the exception thrown by 
 * GetData instead.
*/
#ifndef AALTO_ELEC_RESTRICTED_INTERFACE_CLASS
#define AALTO_ELEC_RESTRICTED_INTERFACE_CLASS
#include "restricted_ptr.hpp"

using namespace WeirdMemoryAllocator;

//WeirdMemoryAllocator::RestrictedPtr<int> &MakeRestricted<int>(int *p)
template <typename T>
    RestrictedPtr<T> MakeRestricted(T* p) noexcept{
        RestrictedPtr<T> new_p(p,"default");
        //delete p;
        return new_p;
        /*const void * address = static_cast<const void*>(p);
        std::stringstream ss;
        ss << address;
        std::string address_str = ss.str();*/
        //p=reinterpret_cast<RestrictedPtr<T>>(new_p);
        //new_p.counter_= new int(1);
        //new_p.ptr_use_=*ptr;
        //RestrictedPtr<T> new_p = p;
        //return std::shared_ptr<T>(new_p,p);
    }

template <typename T>
    RestrictedPtr<T> CopyRestricted(RestrictedPtr<T>& other_p){
            T* temp=new T(other_p.GetData());
            RestrictedPtr<T> new_p(temp,"default");
        try{
            RestrictedPtr<T> new_p = other_p;
            //using std::swap;
            //swap(new_p,other_p);
            //return other_p;
            //return new_p;
        }
        catch(RestrictedCopyException& copyex){
            std::cout << copyex.GetError() << std::endl;            
        }
        /*catch(RestrictedNullException& nullex){
            std::cout << nullex.GetError() << std::endl;
        }*/
        //RestrictedPtr<T> new_p = p;
        //return new_p;
        return new_p;
    }

template <typename T>
    std::ostream& operator<<(std::ostream& os, RestrictedPtr<T>& p){
        try{
            os<<p.GetData();
        }catch(RestrictedNullException &nullex){
            //std::cout << nullex.GetError() << std::endl;
            os<<nullex.GetError() << std::endl;
        }
        /*os<<p.GetData();
        return os;*/
        return os;
    }

#endif