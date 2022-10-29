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
    RestrictedPtr<T>& MakeRestricted(T* p){
        RestrictedPtr<T> new_p(p);
        //delete p;
        return new_p;
    }

template <typename T>
    RestrictedPtr<T>& CopyRestricted(RestrictedPtr<T>& p){
        try{
            RestrictedPtr<T> new_p = p;
            return new_p;
        }
        catch(RestrictedCopyException& copyex){
            std::cout << copyex.GetError() << std::endl;
        }
        catch(RestrictedNullException& nullex){
            std::cout << nullex.GetError() << std::endl;
        }
        //RestrictedPtr<T> new_p = p;
        //return new_p;
    }

template <typename T>
    std::ostream &operator<<(std::ostream& os, RestrictedPtr<T>& p){
        try{
            os<<p.GetData();
            return os;
        }catch(RestrictedNullException &nullex){
            std::cout << nullex.GetError() << std::endl;
        }
        /*os<<p.GetData();
        return os;*/
    }

/*
class RestrictedInterface{
        RestrictedInterface(){};
        virtual ~RestrictedInterface() {}

        static RestrictedPtr<T>& MakeRestricted(T* p)=0;

        virtual RestrictedPtr<T>& CopyRestricted(const RestrictedPtr<T>& p)=0;

        virtual std::ostream &operator<<(std::ostream& os, RestrictedPtr<T>& p)=0;
};
*/

#endif