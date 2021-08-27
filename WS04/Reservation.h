
/*Name: singh Azorawar
ID : 138497193
Email : sazorawar@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef Reservation_H
#define Reservation_H

#include <string>
#include <algorithm>

namespace sdds
{
    class Reservation
    {

    private:



        std::string id;
        std::string name;

        std::string email;

        size_t num_ppl;
        size_t day;

        size_t hour;

    public:
        //contructor
        Reservation();

        Reservation(const std::string& str);

        void display(std::ostream& os) const;
        friend std::ostream& operator<<(std::ostream& os, const Reservation& src)
        {
            src.display(os);
            return os;
        }


        //decontructor
        ~Reservation();
    };
} 


#endif // !SICT_MESSAGE_H
