#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct Record
{
    int emp_id;
    string emp_name;
    Record(int a, string b) : emp_id(a) , emp_name(b) {
    }
};

class HashTable
{
    private:
        int N = 0;
        vector<vector<Record>> T;

    public:
        HashTable(int key_size);
        void insert(int key, string value);
        bool search(int key);
        bool remove(int key);

        int Hash(int key);
        int size();
        void display();
        void loadData(string filename, int line_limit);
};

HashTable::HashTable(int key_size) 
{
    if(key_size <= 0) {
        key_size = 11; // default, guarantee
    }

    this->N = key_size;
    this->T.resize(key_size);
}

void HashTable::insert(int key, string value)
{
    Record tmp(key, value);
    T[Hash(key)].push_back(tmp);    // separate chaining

    cout << "[INSERTED] key: " << key << ", value: " << value << endl;

}

bool HashTable::search(int key)
{
    vector<Record> idx = T[Hash(key)];
    for(int i = 0; i < idx.size(); i++) {
        if (idx[i].emp_id == key) {
            cout << "[FOUND] key: " << key << ", value: " << idx[i].emp_name << endl;
            return true;
        }
    }

    cout << "[NOT FOUND] key: " << key << endl;
    return false;
}


bool HashTable::remove(int key)
{
    vector<Record> idx = T[Hash(key)];
    for(int i = 0; i < idx.size(); i++) {
        if (idx[i].emp_id == key) {
            cout << "[REMOVED] key: " << key << ", value: " << idx[i].emp_name << endl;
            T[Hash(key)].erase(T[Hash(key)].begin() + i);
            return true;
        }
    }

    cout << "[NOT FOUND] key: " << key << endl;
    return false;
}


int HashTable::Hash(int key)
{
    if(N) return key % N;
}

int HashTable::size() 
{
    return N;
}

void HashTable::display()
{
    cout << endl << "[DISPLAYING TABLE]" << endl;
    for(int i = 0; i < N > 0; i++) {
        if (T[i].size() > 0) {
            cout << "TABLE_KEY = " << i << endl << "--------------" << endl;

            for(int j = 0; j < T[i].size(); j++) {
                cout << T[i][j].emp_id << ", " << T[i][j].emp_name << endl;
            }
            cout << endl;
        }
    }
    cout << endl;
}

void HashTable::loadData(string filename, int line_limit) {
    ifstream fp(filename);
    int count = 0;
    string k, v;
    while(fp && !fp.eof() && count != line_limit) {
        getline(fp, v, ',');
        getline(fp, k);

        insert(stoi(k), v);
        count++;
    }
    fp.close();
    cout << "[LOAD DATA] Total records imported: " << count << endl << endl;
}