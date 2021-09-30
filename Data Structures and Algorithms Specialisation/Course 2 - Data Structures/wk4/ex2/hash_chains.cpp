#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;
using std::cin;
using namespace std;
struct Query {
    string type, s;
    size_t ind;
};

class QueryProcessor {
    int bucket_count;
    // store all strings in one vector
    vector<string> elems;
    vector < vector<string> > hash_table; // hash table
    
    size_t hash_func(const string& s) const {
        static const size_t multiplier = 263;
        static const size_t prime = 1000000007;
        unsigned long long hash = 0;
        for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
            hash = (hash * multiplier + s[i]) % prime;
        return hash % bucket_count;
    }
    // Some utility functions
    // Add function
    void add(string s, int hashval)
    {
       //Check if there is something in the vector
        vector<string> chosenOne = hash_table[hashval];
        for (int i = 0; i < chosenOne.size(); i++)
        {
           if (chosenOne[i] == s)
               return;
        }
        hash_table[hashval].insert(hash_table[hashval].begin(), s);
    }
    void del(string s, int hashval)
    {
        vector<string> chosenOne = hash_table[hashval];
        for (int i = 0; i < chosenOne.size(); i++)
        {
            if (chosenOne[i] == s)
            {
                // Remove the ith element then return
                hash_table[hashval].erase(hash_table[hashval].begin()+i);
                return;
            }
        }
        return;
    }
    void find(string s, int hashval)
    {
        vector<string> chosenOne = hash_table[hashval];
        for (int i = 0; i < chosenOne.size(); i++)
        {
            if (chosenOne[i] == s)
            {
                cout << "yes" <<endl;
                return;
            }
        }
        cout << "no" << endl;
    }
    void check(int bucketval)
    {
        vector<string> chosenOne = hash_table[bucketval];
        for (int i = 0; i < chosenOne.size(); i++)
        {
            cout << chosenOne[i] << " ";
        }
        cout << endl;
        return;
    }
public:
    explicit QueryProcessor(int bcount)
    {
        bucket_count = bcount;
        hash_table.resize(bucket_count);
    }

    Query readQuery() const {
        Query query;
        cin >> query.type;
        if (query.type != "check")
            cin >> query.s; // look for the next string
        else
            cin >> query.ind; // look for the value of m
        return query;
    }

    void writeSearchResult(bool was_found) const {
        std::cout << (was_found ? "yes\n" : "no\n");
    }

    void processQuery(const Query& query) {
        /*if (query.type == "check") {
            // use reverse order, because we append strings to the end
            for (int i = static_cast<int>(elems.size()) - 1; i >= 0; --i)
                if (hash_func(elems[i]) == query.ind)
                    std::cout << elems[i] << " ";
            std::cout << "\n";
        } else {
            vector<string>::iterator it = std::find(elems.begin(), elems.end(), query.s);
            if (query.type == "find")
                writeSearchResult(it != elems.end());
            else if (query.type == "add") {
                if (it == elems.end())
                    elems.push_back(query.s);
            } else if (query.type == "del") {
                if (it != elems.end())
                    elems.erase(it);
            }
        }*/
        if (query.type == "check")
        {
            check(static_cast<int>(query.ind));
        }
        else if (query.type == "find")
        {
            int hashval = static_cast<int>(hash_func(query.s));
            find(query.s, hashval);
        }
        else if (query.type == "del")
        {
            int hashval = static_cast<int>(hash_func(query.s));
            del(query.s, hashval);
        }
        else
        {
            int hashval = static_cast<int>(hash_func(query.s));
            add(query.s, hashval);
        }
    }

    void processQueries() {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            processQuery(readQuery());
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    int bucket_count;
    cin >> bucket_count;
    QueryProcessor proc(bucket_count);
    proc.processQueries();
    return 0;
}
