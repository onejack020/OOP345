
// Name: Md Rafi Al Arabi Bhuiyan
// Seneca Student ID: 147307193
// Seneca email: mraabhuiyan@myseneca.ca
// Date of completion: 10-04-2021
//
// I confirm that I am the only author of this file 
//   and the content was created entirely by me.

#include "Utilities.h"

using namespace std;

namespace sdds {

	char Utilities::m_delimiter = ' ';

	Utilities::Utilities() : m_widthField(1) {}


	void Utilities::setFieldWidth(size_t newWidth) {
		m_widthField = newWidth;
	}


	size_t Utilities::getFieldWidth() const {
		return m_widthField;
	}


	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {

		size_t startingPosition = next_pos;
		string count = "";

		next_pos = str.find(m_delimiter, startingPosition);

		if (next_pos == string::npos) {
			count = str.substr(startingPosition);
			m_widthField = max(count.length(), m_widthField);
			more = false;
		}
		else if (startingPosition == next_pos) {
			more = false;
			throw "ERROR: There are no token!";
		}
		else {
			count = str.substr(startingPosition, next_pos - startingPosition);
			m_widthField = max(count.length(), m_widthField);
			more = true;
		}

		next_pos++;
		return count;
	}


	void Utilities::setDelimiter(char newDelimiter) {
		m_delimiter = newDelimiter;
	}


	char Utilities::getDelimiter() {
		return m_delimiter;
	}
}