#include<bits/stdc++.h>

using namespace std;

int main() {

    unordered_map<string, int> m;

    //insertion
    //1
    pair<string, int> p = make_pair("hi", 3);
    m.insert(p);

    //2
    pair<string, int> q("name", 1);
    m.insert(q);

    //3
    m["neeraj"] = 1;

    m["neeraj"] = 2;

    //search
    cout << m["neeraj"] << endl;
    cout << m.at("hi") << endl;
    // cout << m.at("unknown key") << endl; //we'll get error
    cout << m["unknown key"] << endl; //the string is added to map and value 0 is assigned
    cout << m.at("unknown key") << endl;
    
    //size
    cout << m.size() << endl;

    //check presence
    cout << m.count("bro") << endl; //absent returns 0 and present returns 1

    //erase
    m.erase("hi");
    cout << m.size() << endl;

    //iteration1
    for(auto i : m) {
        cout << i.first << " " << i.second << endl;
    }

    //iteration2
    unordered_map<string, int> :: iterator it = m.begin();

    while (it != m.end())
    {
        cout << it -> first << " " << it -> second << endl;
        it++;
    }
    

    return 0;
}