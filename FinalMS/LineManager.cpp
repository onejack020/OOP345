
// Name: Md Rafi Al Arabi Bhuiyan
// Seneca Student ID: 147307193
// Seneca email: mraabhuiyan@myseneca.ca
// Date of completion: 10-04-2021
//
// I confirm that I am the only author of this file 
// and the content was created entirely by me.

#include <algorithm>
#include <fstream>

#include "Utilities.h"
#include "LineManager.h"

using namespace std;

namespace sdds {

	LineManager::LineManager(const string& file,const vector<Workstation*>& stations){
		
		ifstream in(file);
		if (!in.is_open()) {
			throw "File could not be opened";
		}

		Utilities object;
		object.setDelimiter('|');

		while (!in.eof()) {
			
			string ptr;
			size_t next = 0;
			bool more = true;
			
			getline(in, ptr);
			ptr.erase(ptr.find_last_not_of("\r") + 1);
			string from = object.extractToken(ptr, next, more);
			
			auto prev_station = *find_if(
				stations.begin(),
				stations.end(),
				[&](Workstation* station) {
					return station->getItemName() == from;
				});
			activeLine.push_back(prev_station);
			if (!more) {
				continue;
			}
			string obj = object.extractToken(ptr, next, more);
			auto last_station = *find_if(
				stations.begin(),
				stations.end(),
				[&](Workstation* station) {
					return station->getItemName() == obj;
				});
			prev_station->setNextStation(last_station);
		}
		Workstation* current_station = nullptr;
		
		for_each(stations.begin(),stations.end(),
			[&](Workstation* templ) {
				current_station = *find_if(stations.begin(),stations.end(),
					[&](Workstation* station) {
						return station->getNextStation() == current_station;
					});
			});

		m_firstStation = current_station;
	}

	void LineManager::linkStations() {
		const Workstation* current_station = m_firstStation;
		size_t i = 0;
		while (current_station != nullptr) {
			activeLine[i++] = const_cast<Workstation*>(current_station);
			current_station = current_station->getNextStation();
		}
	}

	bool LineManager::run(ostream& os) {
		static size_t Iteration = 1;
		os << "Line Manager Iteration: " << Iteration++ << endl;
		
		if (!pending.empty()) {
			*m_firstStation += std::move(pending.front());
			pending.pop_front();
			m_cntCustomerOrder++;
		}
		for (auto& station : activeLine) {
			station->fill(os);
		}
		for (auto& station : activeLine) {
			station->attemptToMoveOrder();
		}
		
		return completed.size() + incomplete.size() == m_cntCustomerOrder;
	}

	void LineManager::display(ostream& os) const {
		for (auto& station : activeLine) {
			if (station != nullptr) {
				station->display(os);
			}
		}
	}
} 
