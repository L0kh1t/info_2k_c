#include <iostream>
#include <vector>
#include <memory>

class Individual
{
public:
    virtual void speak() const = 0;
    virtual ~Individual() = default;
    virtual int Type() const = 0;
};

class Alice : public Individual
{
public:
    void speak() const override
    {
        std::cout << "Hi, I am Alice" << std::endl;
    }
    int Type() const override { return 0}
};

class Bob : public Individual
{
public:
    void speak() const override
    {
        std::cout << "Hi, I am Bob" << std::endl;
    }

    int Type() const override { return 1}
};

class Casper : public Individual
{
public:
    void speak() const override
    {
        std::cout << "Hi, I am Casper" << std::endl;
    }
    int Type() const override { return 2}
};

//3a

// int identification_a(Individual* p) {
//     return p->Type();
// }

//3b

// int identification_b(Individual* p) {
//     if (dynamic_cast<Alice*>(p)) 
//         return 0;
//     if (dynamic_cast<Bob*>(p)) 
//         return 1;
//     if (dynamic_cast<Casper*>(p)) 
//         return 2;
// }

//3c

int identification(Individual* p) {
    if (typeid(*p) == typeid(Alice)) 
        return 0;
    if (typeid(*p) == typeid(Bob)) 
        return 1;
    if (typeid(*p) == typeid(Casper)) 
        return 2;
}

std::vector<Individual*>  createIndividuals()
{
    std::vector<Individual*> individuals;
    
    for (int i = 0; i < 3; ++i) {
        individuals.push_back(new Alice());
    }

    for (int i = 0; i < 2; ++i) {
        individuals.push_back(new Bob());
    }

    for (int i = 0; i < 4; ++i) {
        individuals.push_back(new Casper());
    }

    return individuals;
}

void letMeSpeak(const std::vector<Individual*>& individuals)
{
    for (const auto* individual: individuals)
        individual->speak();
}

void deleteIndividuals(std::vector<Individual*>& individuals) {
    for (auto* individual : individuals) {
        delete individual;  
    }
}

int main()
{
    Alice a;
    a.speak();
}