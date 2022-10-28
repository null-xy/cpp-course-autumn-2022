#include "standard_printer.hpp"

StandardPrinter::StandardPrinter(std::ostream& os):StringPrinter(os){}

StandardPrinter* StandardPrinter::Clone() const{
    return new StandardPrinter(os_);
}

StringPrinter& StandardPrinter::operator()(const std::string& a){
    this->os_<<a;
    os_ << std::endl;
    return *this;
}