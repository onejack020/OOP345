

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "SongCollection.h"

using namespace std;

namespace sdds {

	void SongCollection::trunc(string& str) {

		size_t pos = str.find_first_not_of(" ");
		str.erase(0, pos);
		pos = str.find_last_not_of(" ");
		if (string::npos != pos) {
			str.erase(pos + 1);
		}
	}

	SongCollection::SongCollection(string fileName) {

		ifstream file(fileName);

		if (!file) {
			throw "Invalid filename";
		}
		while (file)
		{
			Song song;
			std::string str;
			std::getline(file, str);

			if (file) {
				trunc(song.m_title = str.substr(0, 25));
				trunc(song.m_artist = str.substr(25, 25));
				trunc(song.m_album = str.substr(50, 25));

				try {
					song.m_year = std::stoi(str.substr(75, 5));
				}
				catch (...)
				{
					song.m_year = 0;
				}
				song.m_length = std::stoi(str.substr(80, 5));
				song.m_price = std::stod(str.substr(85, 5));

				s_song.push_back(song);
			}
		}
		file.close();
	}


	void SongCollection::display(ostream& out) const {

		for_each(s_song.begin(), s_song.end(), [&out](const Song& collection) {
			out << collection << std::endl;
			});

		out << setw(89) << setfill('-') << '\n' << setfill(' ');

		int sum = std::accumulate(s_song.begin(), s_song.end(), 0, [](int x, const Song& collection)->int {
			return x + collection.m_length;
			});

		int hour = sum / 3600;
		int min = (sum % 3600) / 60;
		int second = sum % 60;

		out << "| " << right << setw(77) << "Total Listening Time: " << hour << ":" << min << ":" << second << " |" << endl;
	}

	void SongCollection::sort(std::string field){

		if (field == "title") {
			std::sort(s_song.begin(), s_song.end(), [](const Song& a, const Song& b) {return !(a.m_title > b.m_title); });
		}
		else if (field == "album") {
			std::sort(s_song.begin(), s_song.end(), [](const Song& a, const Song& b) {return !(a.m_album > b.m_album); });
		}
		else if (field == "length") {
			std::sort(s_song.begin(), s_song.end(), [](const Song& a, const Song& b) {return a.m_length < b.m_length; });
		}
	}

	ostream& operator<<(ostream& out, const Song& theSong) {

		out << "| " << left << setw(20) << theSong.m_title;
		out << " | " << left << setw(15) << theSong.m_artist;
		out << " | " << left << setw(20) << theSong.m_album;
		out << " | " << right << setw(6);

		if (theSong.m_year == 0) {
			out << " ";
		}
		else {
			out << theSong.m_year;
		}

		out << " | " << theSong.m_length / 60 << ":" << setw(2) << setfill('0') << theSong.m_length % 60
			<< " | " << fixed << setprecision(2) << theSong.m_price << " |" << setfill(' ');

		return out;
	}

	void SongCollection::cleanAlbum() {
		for_each(s_song.begin(), s_song.end(), [](Song& a) {
			if (a.m_album == "[None]") {
				a.m_album = "";
			}
			});
	}

	bool SongCollection::inCollection(string artist) const {
		
		bool found = any_of(s_song.begin(), s_song.end(), [=](const Song& a)->bool {
			return a.m_artist == artist;
		});
		return found;
	}

	list<Song> SongCollection::getSongsForArtist(string artist) const {

		std::list<Song> theSongs;
		for_each(s_song.begin(), s_song.end(), [&](Song i) {
			if (artist == i.m_artist) theSongs.push_back(i); 
		});
		
		return theSongs;
	}
}