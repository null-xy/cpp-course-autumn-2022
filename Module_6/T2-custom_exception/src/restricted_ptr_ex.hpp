/* Add include guards here */

/* TODO: classes RestrictedPtrException, RestrictedCopyException 
 * and RestrictedNullException
 * ------------
 * Description:
 * Exception classes used by the RestrictedPtr class.
 * PtrException is a abstract base class of the other two and inherits
 * std::exception.
 * CopyException signifies a copying error.
 * NullException signifies a nullptr error.
 * ------------
 * Functions:
 * 
 * All of them should have a constructor taking a single const 
 * reference to a string which is the use of the RestrictedPtr that 
 * caused the exception.
 * 
 * GetError: A function that takes no arguments and returns 
 * a string description of the error (see "Other" section for details).
 * Calling GetError on RestrictedPtrException should return the
 * error description of the actual exception type (Null- or 
 * CopyException).
 * 
 * GetUse: takes no parameters and returns the string given as a 
 * parameter to the constructor. 
 * ------------
 * Other:
 * As always, any function that doesn't modify the object or allow
 * modifying the object's members from the outside should be const.
 * 
 * Wrap everything inside the WeirdMemoryAllocator namespace.
 * 
 * GetError format:
 * RestrictedCopyException:
<use>: Too many copies of RestrictedPtr!
 * RestrictedNullException:
<use>: nullptr exception!
 * where <use> is replaced by the string given in to the constructor.
*/
#ifndef AALTO_ELEC_RESTRICTED_PTR_EX_CLASS
#define AALTO_ELEC_RESTRICTED_PTR_EX_CLASS
#include <sstream>

namespace WeirdMemoryAllocator{

class RestrictedPtrException : public std::exception {
    public:
    RestrictedPtrException(const std::string& t):ptr_use_(t){}
    
    virtual const std::string GetError() const noexcept 
    {//virtual const std::string* GetError() const noexcept 
        return "see \"Other\" section for details";
    }
    const std::string& GetUse () const{
        return ptr_use_;
    }

    protected:
    const std::string& ptr_use_;
};


class RestrictedCopyException : public RestrictedPtrException{
    public:
    RestrictedCopyException(const std::string& t) : RestrictedPtrException(t){}
    
    const std::string GetError() const noexcept 
    //const std::string* GetError() const noexcept 
    {
        std::stringstream ss;
        ss<<"<"<<this->GetUse()<<">: Too many copies of RestrictedPtr!";
        std::string s=ss.str();
        return s;
        //return &s;
        //return "<use>: Too many copies of RestrictedPtr!";
    }
};

class RestrictedNullException : public RestrictedPtrException{
    public:
    RestrictedNullException(const std::string& t) : RestrictedPtrException(t){}
    
    const std::string GetError() const noexcept 
    //const std::string* GetError() const noexcept 
    {
        std::stringstream ss;
        ss<<"<"<<this->GetUse()<<">: nullptr exception!";
        std::string s=ss.str();
        return s;
        //return &s;
        //return "<use>: nullptr exception!";
    }
};

}


#endif