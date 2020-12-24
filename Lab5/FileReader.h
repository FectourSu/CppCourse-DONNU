#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <iostream>
#include <sstream> 
#include <fstream>
#include<map>
#include <algorithm>


class FileReader
{
public:
    std::map< std::string, int> Read()
    {
        bool flag = true;

        std::map< std::string, int > mass;

        std::string line;

        std::ifstream in("D:\\temp.txt");

        if (in.is_open())
        {
            while (getline(in, line))
            {
                const size_t MAXLEN = 1000;

                char text[MAXLEN];

                in.getline(text, MAXLEN);

                char* substr = strtok_s(text, ".,:!;? ", NULL);

                while (substr != 0)
                {
                    std::string word = substr;

                    const char substr_1 = (char)substr;

                    std::transform(word.begin(), word.end(), word.begin(), ::tolower);

                    if (word.size() > 3)
                        for (auto mass_it = mass.begin(); mass_it != mass.end(); ++mass_it)
                            if (mass_it->first == word)
                            {
                                mass_it->second = mass_it->second++;
                                flag = false;
                            }

                    if (flag == true)
                        mass.insert(std::make_pair(word, 1));

                    flag = true;

                    substr = strtok_s(NULL, ".,:!;? ", NULL);
                }
            }
        }
        in.close();
        return mass;
    };
};

