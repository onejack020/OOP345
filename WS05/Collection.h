
/*
Name: Md Rafi Al Arabi Bhuiyan
Email: mraabhuiyan@myseneca.ca
Student ID: 147307193
Date: 21/02/2021
Workshop 5

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/



#pragma once

#ifndef SDDS_COLLECTION_H_
#define SDDS_COLLECTION_H_

#include <exception>
#include <functional>
#include <ostream>
#include <iostream>
#include <string>

using namespace std;

namespace sdds {

    template <typename T>
    class Collection {

    private:
        std::string m_name;
        size_t m_size = 0;
        T* m_collection = nullptr;
        std::function<void(const Collection<T>&, const T&)> m_callback = nullptr;

    public:
        Collection(const std::string& name) : m_name(name) {}
       
        Collection(const Collection& other) = delete;
        Collection& operator=(const Collection& rhs) = delete;

        ~Collection() {
            delete[] m_collection; 
        }

        const std::string& name() const { 
            return m_name; 
        }

        size_t size() const { 
            return m_size; 
        }

        void setObserver(void (*observer)(const Collection<T>&, const T&)) {
            m_callback = observer;
        }

        Collection<T>& operator+=(const T& items){

            for (size_t i = 0; i < m_size; ++i) {
                if (items.title() == m_collection[i].title())
                    return *this;
            }

            T* templ = new T[m_size + 1];
      
            for (size_t i = 0; i < m_size; ++i) {
                templ[i] = m_collection[i];
            }

            templ[m_size++] = items;
            delete[] m_collection;
            m_collection = templ;
           
            if (m_callback) {
                m_callback(*this, items);
                return *this;
            }
        }

        T& operator[](size_t idx) const {
            
            if (idx >= m_size) {
                std::string message("Bad index ");
                message += "[" + std::to_string(idx) + "]. Collection has ";
                message += "[" + std::to_string(m_size) + "] items.";
                throw std::out_of_range(message);
            }
            return m_collection[idx];
        }

        T* operator[](const std::string& title) const {

            for (size_t i = 0; i < m_size; ++i) {
                if (title == m_collection[i].title())
                    return &m_collection[i];
            }
            return nullptr;
        }
    };

    template <typename T>
    std::ostream& operator<<(std::ostream& os, const Collection<T>& collection) {

        for (size_t i = 0; i < collection.size(); ++i)
            os << collection[i];
        return os;
    }
}

#endif // SDDS_COLLECTION_H_

