#include "standard_printer.hpp"

StandardPrinter::StandardPrinter(std::ostream& os):StringPrinter(os){}

StringPrinter& StandardPrinter::operator()(const std::string& a){
    this->os_<<a;
    os_ << std::endl;
    return *this;
}