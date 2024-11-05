#include<iostream>
#include<filesystem>
#include<Windows.h>
#include"DL.h"
#include"Tools.h"
#include"set.h"



using namespace std;



const char* arg[] = { "--file","1.json","--query", "SETADD set1 7"};

int main(int argc,const char* argv[])
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    //argv = arg;
    //argc = 4;
    DL<string> files;
    filesystem::path dirPath = "C:\\Users\\user\\source\\repos\\set\\x64\\Debug";

    if (filesystem::exists(dirPath) && filesystem::is_directory(dirPath))
    {
        for (const auto& entry : filesystem::directory_iterator(dirPath))
        {
            if (filesystem::is_regular_file(entry) && entry.path().extension() == ".json")
            {
                const string file = entry.path().string();
                files.LDPUSHT(file);
            }
        }
    }
    else
    {
        cerr << "Такого пути нет" << endl;
    }



    if (argc < 2)
    {
        cout << "Недостаточно аргументов\n";
        return 1;
    }

    string query, file;
    DL<string> args;
    for (int i = 0; i < argc; i++)
    {
        string str(argv[i]);
        if (str == "--file")
        {
            file = string(argv[i + 1]);
        }
        else if (str == "--query")
        {
            query = string(argv[i + 1]);
        }
        args.LDPUSHT(str);
    }
    string Name;
    bool isName = false;
    for (size_t i = 0; i < query.size(); i++)
    {
        if (isName && query[i] == ' ')
        {
            isName = false;
            break;
        }
        if (query[i] == ' ')
        {
            isName = true;
            continue;
        }
        if (isName)
        {
            Name += query[i];
        }
    }

    DL<string> querys = split(query);

    Set exm;

    string fileName = file;
    json j;
    DL<string> listKey;
    if (!(fileExists(fileName) && ValidFile(fileName)))
    {
        createNewFile(fileName, Name);

        ifstream readFile(fileName);
        readFile >> j;
        readFile.close();

        if (j["Set"][Name].is_null())
        {
            j["Set"][Name] = json::array();
        }
    }
    else
    {
        ifstream readFile(fileName);
        readFile >> j;
        readFile.close();

        if (j["Set"][Name].is_null())
        {
            j["Set"][Name] = json::array();

        }
        else
        {
            for (const auto& item : j["Set"][Name])
            {
                listKey.LDPUSHT(item);
                exm.SETADD(item);
            }
        }

        ofstream FileWrite(fileName);
        FileWrite << j.dump(4);
        FileWrite.close();
    }
    string key = querys[2];
    if (querys[0] == "SETADD")
    {
        int len = exm.len;
        exm.SETADD(key);
        if (exm.len > len)
        {
            listKey.LDPUSHT(key);
        }
    }
    else if (querys[0] == "SETDEL")
    {
        listKey.LDDELV(key);
        exm.SETDEL(key);
    }
    else if (querys[0] == "SET_AT")
    {
        if (exm.SET_AT(key))
        {
            cout << "presence" << "\n";
        }
        else
        {
            cout << "not presence\n";
        }
       
    }

    exm.PRINT();

    j["Set"][Name].clear();
    for (int i = 0; i < listKey.len; i++)
    {
        string elem = listKey[i];
        j["Set"][Name].push_back(elem);
    }
    ofstream writeFile(fileName);
    writeFile << j.dump(4);
    writeFile.close();

	return 0;
}