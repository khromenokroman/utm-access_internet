#include<iostream>
#include<fstream>

#include "header.h"

using namespace std;

void clear_conf(string PATH)
{
    ofstream file(PATH);
    file<<"";
}

void replace_conf(string PATH)
{
    int item = 0, char_position;
    int const MAX_SIZE = get_count_line(PATH);
    string text_line[MAX_SIZE], line_in, line_out, str_original, str_replace, text_replace;
    fstream file_in, file_out;

    file_in.open(PATH, fstream::in);
    for (line_in; getline(file_in, line_in);)
    {
        text_line[item] = line_in;
        item++;
    }
    file_in.close();

    str_original = text_line[MAX_SIZE-2];
    text_replace = "attempt";
    char_position = str_original.find(text_replace);
    str_replace = str_original.replace(char_position, text_replace.length(), "access");

    text_line[MAX_SIZE-1] = str_replace;

    clear_conf(PATH);

    file_out.open(PATH,fstream::app);
    for (int i=0; i<MAX_SIZE; i++)
    {
        file_out << text_line[i] << endl;
    }
    file_out.close();
}