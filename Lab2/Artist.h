#include <iostream>
#pragma once

#define PROPERTIES(type, var)  private: type var; \
	public: type get_##var() const { return var; } \
            void set_##var(type val) { var = val; }

class Artist
{
private:

public:
	explicit Artist();
	~Artist();
	Artist(std::string firstName, std::string secondName, std::string musicalInstrument, 
		std::string gender, int rating, int yearOld);


	PROPERTIES(std::string, firstName);
	PROPERTIES(std::string, secondName);
	PROPERTIES(std::string, musicalInstrument);
	PROPERTIES(std::string, gender);
	PROPERTIES(int, yearOld);
	PROPERTIES(int, rating);

};

