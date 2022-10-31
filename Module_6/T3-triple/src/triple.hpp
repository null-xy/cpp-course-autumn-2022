/* Add include guards here */

/**
 * @brief: The template class Triple is a container class, which holds three values.
 * All of the values can be of different type. All of the values should be
 * private.
 *
 * The constructor of the class takes three const references to values as a
 * parameter. The parameters are in order, in other words, after construction
 * the first parameter should be accessible through the public member function
 * First, the second parameter through the public member function Second, and
 * the third through the public member function Third. 
 *
 * The default empty constructor should also work.
 *
 * The Triple class should also support the copy constructor, and assignment
 * operations.
 */
 

/* Public member functions:
 * ------------------------
 * The Triple class has three public member functions, which are used to
 * access the stored elements. All three should work with const instances
 * of Triple.
 *
 * Function: First
 * The function takes no parameters.
 * The function returns a const reference to the first value of the triple.
 *
 * Function: Second
 * The function takes no parameters.
 * The function returns a const reference to the second value of the triple.
 *
 * Function: Third
 * The function takes no parameters.
 * The function returns a const reference to the third value of the triple.
 */

/* Non-member functions:
 * ---------------------
 * Function: IsHomogenous
 * The function is a non-member function that takes a Triple as a parameter.
 * The function returns a boolean value indicating whether the triple is
 * homogenous or not. A triple is homogenous if all of its three values are of
 * the same type.
 * Hint: specialisation can help you here.
 */


/* Operator overloads:
 * -------------------
 * The triple class should support the following operators:
 *
 * Assignment operator, =
 * The default functionality should do here.
 *
 * Equality operator, ==
 * You can assume that all the values in the triple can be compared by the
 * == -operator. Two triples are equal if the corresponding values in both
 * of the triples are equal.
 *
 * Inequality operator, !=
 * You can assume that all the values in the triple can be compared by the
 * != -operator. Two triples are inequal if even one corresponding value in
 * the triples is different.
 *
 * The output stream operator, <<
 * You can assume that all the values in the triple support the << -operator.
 * The triple should be printed to the output stream in the following format: 
[<first value>, <second value>, <third value>]
 * Note that there is NO new line at the end of the output.
 */

/* Remember the endif here to close the header guards */

#ifndef AALTO_ELEC_TRIPLE_CLASS
#define AALTO_ELEC_TRIPLE_CLASS

#include <iostream>
#include <type_traits>

template <typename T1, typename T2, typename T3>
//template<class T>
//template<typename T>
class Triple{
    public:
    Triple(){}
    //Triple(const T&a, const T& b, const T& c):val_a_(a),val_b_(b),val_c_(c){
    Triple(const T1&a, const T2& b, const T3& c):val_a_(a),val_b_(b),val_c_(c){
    //Triple(const int&a, const int& b, const int& c):val_a_(a),val_b_(b),val_c_(c){
    }

    const T1& First() const{
    //const std::common_type_t<T1,T2,T3>& First(){
    //const std::common_type_t<T>& First(){
        return this->val_a_;
    }
    
    const T2& Second() const{
    //const std::common_type_t<T1,T2,T3>& Second(){
    //const std::common_type_t<T>& Second(){
        return this->val_b_;
    }

    const T3& Third() const{
    //const std::common_type_t<T1,T2,T3>& Third(){
    //const std::common_type_t<T>& Third(){
        return this->val_c_;
    }

    Triple(const Triple &other){
        val_a_=other.val_a_;
        val_b_=other.val_b_;
        val_c_=other.val_c_;
    }
/*
    //Triple<T1,T2,T3>& operator=(const Triple<T1,T2,T3>& other){
    Triple& operator=(const Triple& other){
        val_a_=other.val_a_;
        val_b_=other.val_b_;
        val_c_=other.val_c_;
        return *this;
    }
*/
    friend bool operator==(const Triple& x, const Triple& y){
        return (x.val_a_==y.val_a_ && x.val_b_==y.val_b_ && x.val_c_==y.val_c_);
    }
    friend bool operator!=(const Triple& x, const Triple& y){
        return !(x==y);
    }
    //Triple<T1,T2,T3>& t
    friend std::ostream& operator<<(std::ostream& out,const Triple& t){
        out<<"[<"<<t.val_a_<<">, <"<<t.val_b_<<">, <"<<t.val_c_<<">]";
        return out;
    }
    private:
    T1 val_a_;
    T2 val_b_;
    T3 val_c_;

   /*
    int val_a_;
    int val_b_;
    int val_c_;
    */
};
template <typename T1, typename T2, typename T3>
bool IsHomogenous(const Triple<T1,T2,T3>& t){
//template<>
//bool IsHomogenous(const Triple& t){
    //if constexpr (std::is_same<T1,T2>::value & std::is_same<T2,T3>::value){
    /*
    if(typeid(t.val_a_).name() == typeid(t.val_b_).name()==typeid(t.val_c_).name())
    {
        return true;
    }else {
        return false;
    }*/
    return (std::is_same<T1,T2>::value & std::is_same<T2,T3>::value);
    //return true;constexpr (std::is_same_v<T, animal>)

}

#endif