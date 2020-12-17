

#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;
 
class Trie {
public:
    bool hava_Authority = false;
    bool isInherient = true;
    unordered_map<string, Trie*> ls;
    string name;
    Trie(bool au, string str) {
        hava_Authority = au;
        name = str;
    }
    Trie() {
 
    }
    void insert(bool au, vector<string> str) {
        if (str.empty()) {
            this->isInherient = false;
            this->hava_Authority = true;
            return;
        }
        Trie* node = this;
        for (int i = 0; i < str.size(); i++) {
            if (node->ls.find(str[i]) == node->ls.end()) {
                Trie* tmp = new Trie(node->hava_Authority, str[i]);
                node->ls.insert(make_pair(str[i], tmp));
            }
            node = node->ls.find(str[i])->second;
        }
        if (node->isInherient)
            node->hava_Authority = au;
        node->isInherient = false;
    }
 
    bool query(vector<string> str) {
        Trie* node = this;
        for (int i = 0; i < str.size(); i++) {
            if (node->ls.find(str[i]) == node->ls.end()) {
                break;
            }
            node = node->ls.find(str[i])->second;
        }
        return node->hava_Authority;
    }
 
    void update() {
        Trie* node = this;
        for (auto it = node->ls.begin(); it != node->ls.end(); it++) {
            if (it->second->isInherient) {
                node->ls[it->first]->hava_Authority = node->hava_Authority;
            }
            node->ls[it->first]->update();
        }
    }
};
 
vector<string> split(string str) {
    str += "/";
    str = str.substr(1);
    vector<string> res;
    string tmp;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '/') {
            if (tmp.size())
                res.push_back(tmp);
            continue;
        }
        tmp += str[i];
    }
    return res;
}
 
int main() {
    Trie* root = new Trie();
    int n;
    cin >> n;
    vector<vector<string>> query;
    while (n--) {
        string t;
        cin >> t;
        query.push_back(split(t));
    }
    cin >> n;
    string a, b;
    while (n--) {
        cin >> a >> b;
        if (a == "Y") {
            root->insert(true, split(b));
        }
        else {
            root->insert(false, split(b));
        }
    }
    root->update();
    for (int i = 0; i < query.size(); i++) {
        if (root->query(query[i])) {
            cout << "Y\n";
        }
        else {
            cout << "N\n";
        }
    }
    return 0;
 
}
