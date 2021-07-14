#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // creating file and writing some content to it
    ofstream fout;
    fout.open("test.txt", ios::out);
    if(!fout) {
        cout << "File Opening/Creation Failed" << endl;
        return 1;
    }

    string content = "This is the content to be written in the file.\nExample of writing and reading the file.\n100 Days of Code Challenge";
    fout << content;

    fout.close();

    // reading from the file
    ifstream fin;
    fin.open("test.txt");
    if(!fin.is_open()) {
        cout << "File opening failed" << endl;
    }

    string temp;
    while(!fin.eof()) {
        getline(fin, temp);
        cout << temp << endl;
    }

    int noOfWords = 0;
    fin.seekg(0, ios::beg);
    while(!fin.eof()) {
        fin >> temp;
        noOfWords++;
    }
    cout << "\nTotal Number of words in file: " << noOfWords << endl;

    int noOfChars = 0;
    char t;
    fin.seekg(0, ios::beg);
    while(!fin.eof()) {
        t = fin.get();
        noOfChars++;
    }
    cout << "Total Number of chars in file: " << noOfChars << endl;

    fin.close();

    return 0;
}