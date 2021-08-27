

#pragma once

#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <list>

namespace sdds {

	struct Song {
		std::string m_artist;
		std::string m_title;
		std::string m_album;

		double m_price;

		int m_year;
		size_t m_length;
	};

	class SongCollection {

		std::vector<sdds::Song> s_song;
		void trunc(std::string&);

	public:
		SongCollection(std::string);
		void display(std::ostream& out) const;
		void sort(std::string);
		void cleanAlbum();
		bool inCollection(std::string) const;
		std::list<Song> getSongsForArtist(std::string) const;
	};

	std::ostream& operator<<(std::ostream& out, const Song& theSong);
}

#endif//SDDS_SONGCOLLECTION_H




