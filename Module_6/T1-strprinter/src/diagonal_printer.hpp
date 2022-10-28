/* Add include guards here */

/**
 * @brief A class that is used to print strings diagonally (see below). The
 * class inherits (public inheritance) class StringPrinter.
 * 
 * TODO: Implement the following:
 * ------------
 * Functions:
 * 
 * A constructor that takes three parameters:
 *  - The first line, which is "" by default, i.e. it is not printed at all
 *  - The last line, which is "" by default, i.e. it is not printed at all either
 *  - A reference to the output stream, which is std::cout by default
 * 
 * Overrides the necessary members from the base class.
 * ------------
 * Other:
 * DiagonalPrinter prints a string diagonally. For the string "like this":
<first line>\n
l        \n
 i       \n
  k      \n
   e     \n
         \n
     t   \n
      h  \n
       i \n
        s\n
<last line>\n
 * where <first line> and <last line> are replaced by the strings given in the
 * constructor. If the first line is empty, it is not printed. The same applies
 * to the last line.
 */

#ifndef AALTO_ELEC_DIAGONAL_PRINTER_CLASS
#define AALTO_ELEC_DIAGONAL_PRINTER_CLASS
#include "string_printer.hpp"

class DiagonalPrinter : public StringPrinter{
    public:
    DiagonalPrinter(const std::string& first = "",const std::string& last = "",std::ostream& os = std::cout);
    /*DiagonalPrinter(const std::string& first,const std::string& last,std::ostream& os ){
        os_=std::cout;
        first="";
        this->last_="";
    }*/
    virtual DiagonalPrinter* Clone() const;
    virtual StringPrinter& operator()(const std::string& a);

    private:
    const std::string& first_;
    const std::string& last_;
};
#endif