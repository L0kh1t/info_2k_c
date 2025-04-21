#include <iostream>
#include <vector>
#include <memory>

class Individual
{
public:
    virtual void speak() const = 0;
    virtual ~Individual() = default;
};

class Alice : public Individual
{
public:
    void speak() const override
    {
        std::cout << "Hi, I am Alice" << std::endl;
    }
};

class Bob : public Individual
{
public:
    void speak() const override
    {
        std::cout << "Hi, I am Bob" << std::endl;
    }
};

class Casper : public Individual
{
public:
    void speak() const override
    {
        std::cout << "Hi, I am Casper" << std::endl;
    }
};

std::vector<std::unique_ptr<Individual>> createIndividualsSmart() {
    std::vector<std::unique_ptr<Individual>> individuals;
    
    for (int i = 0; i < 3; ++i) {
        individuals.push_back(std::make_unique<Alice>());
    }

    for (int i = 0; i < 2; ++i) {
        individuals.push_back(std::make_unique<Bob>());
    }

    for (int i = 0; i < 4; ++i) {
        individuals.push_back(std::make_unique<Casper>());
    }
    
    return individuals;
}

void letThemSpeak(const std::vector<std::unique_ptr<Individual>>& individuals) {
    for (const auto& individual : individuals) {
        individual->speak();
    }
}