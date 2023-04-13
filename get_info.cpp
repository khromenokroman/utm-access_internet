#include<iostream>
#include<fstream>
#include<string>
#include <bits/stdc++.h>  

using namespace std;

//разбиваем строку на разделители
string split(string line)
{    
    string str;
    stringstream ss(line); 
  
    while (getline(ss, str, '=')) 
    {
        if (str[0] == ' ')
        {
            return str.erase(0,1);
        }
    } 
    return " ";     
}

// узнам сколько строк в файле
int get_count_line(string PATH)
{
    int count_line = 0;
    string line;
    fstream file(PATH);
    while (getline(file, line))
        ++count_line;
    return count_line;
}

//прочитаем файл и запишем в массив и сравним
bool read_conf(string PATH)
{
    string attempt, access;
    int item = 0;
    int const MAX_SIZE = get_count_line(PATH);
    string text_line[MAX_SIZE];
    fstream file;

    file.open(PATH, fstream::in);
    for (string line; getline(file, line);)
    {
        text_line[item] = line;
        item++;
    }

    attempt = split(text_line[MAX_SIZE-2]);
    access = split(text_line[MAX_SIZE-1]);

    if (attempt == access)
    {
        return true;
    }
    else
    {
        return false;
    }

}


