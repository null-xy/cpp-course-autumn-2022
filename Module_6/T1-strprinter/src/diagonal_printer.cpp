#include "diagonal_printer.hpp"

DiagonalPrinter::DiagonalPrinter(const std::string& first,const std::string& last,std::ostream& os)
:StringPrinter(os),first_(first),last_(last){}

DiagonalPrinter* DiagonalPrinter::Clone() const{
    return new DiagonalPrinter(first_,last_,os_);
}

StringPrinter& DiagonalPrinter::operator()(const std::string& a){
    //std::copy(a.begin(), a.end(), std::ostream_iterator<char>(os_));
    os_<<first_<<std::endl;
    for(unsigned int i =0; i<a.length();i++){
        os_<<a.at(i)<<std::endl;
        for(unsigned int j=0;j<=i;j++){
            os_<<" ";
        }
    }
    os_<<last_<<std::endl;
    return *this;
}