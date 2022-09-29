#ifndef AALTO_ELEC_CPP_PERSON
#define AALTO_ELEC_CPP_PERSON

// declare your Person class here
#include <string>

class Person{
public:
    Person(const std::string& name, const int birthyear);

    const std::string& GetName() const;
    int GetAge(int currentyear);
private:
    std::string name_;
    int birthyear_;
    int age_;

};
#endif