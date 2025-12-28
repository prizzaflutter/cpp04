#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "iostream"

class Brain {
    private: 
        std::string ideas[100];
    public:
        Brain();
        Brain(const Brain& other);
        Brain& operator=(const Brain& other);
        ~Brain();
        void setIndea(int index, const std::string& idea);
        std::string getIdes(int index) const;
};

#endif