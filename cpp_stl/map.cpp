#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main() {
    map<string, int> m;

    m["tv"] = 50;
    m["laptop"] = 100;
    m["headphones"] = 120;
    m["smart watch"] = 50;

    m.insert({"camera", 45});
    m.emplace("glasses", 75);

    m["camera"] = 50; // The camera key's value will be overwritten here

    m.erase("tv");

    for (auto p: m) { // the map has pair kind of data, auto will set the datatype a spair
        cout << p.first << " " << p.second << endl;
    } 

    cout << "Count = " << m.count("laptop") << endl;   
    cout << "Laptop's value = " << m["laptop"] << endl;   

    if (m.find("camera") != m.end()) {
        cout << "Found" << endl;
    } else {
        cout << "Found" << endl;
    }

    cout << "Size = " << m.size() <<  endl;
    cout << "Is empty = " << m.empty() <<  endl;

    cout << endl;

    multimap<string, int> mm;

    // mm["saad"] = 22; Not allowed
    mm.insert({"saad", 22});
    mm.emplace("saad", 21); // the saad key will be duplicated

    // mm.erase("saad"); // all saad key value pairs will be erased

    // if we want to erase only one instance of saad, we can use an iterator
    mm.erase(mm.find("saad")); // find returns memory location of first instanc of key saad and erase it

    for (auto p: mm) { // the map has pair kind of data, auto will set the datatype a spair
        cout << p.first << " " << p.second << endl;
    }

    cout << endl;

    unordered_map<string, int> um;

    um["tv"] = 50;
    um["laptop"] = 100;
    um["headphones"] = 120;
    um["smart watch"] = 50;

    um.insert({"camera", 45});
    um.emplace("glasses", 75);

    um["camera"] = 50; // The camera key's value will be overwritten here

    um.erase("tv");

    for (auto p: um) { // the map has pair kind of data, auto will set the datatype a spair
        cout << p.first << " " << p.second << endl;
    }
    
    return 0;
}