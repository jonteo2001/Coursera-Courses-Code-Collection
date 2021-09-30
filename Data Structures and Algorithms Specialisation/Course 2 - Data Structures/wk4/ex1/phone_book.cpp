#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using std::string;
using std::vector;
using std::cin;
using namespace std;
struct Query {
    string type, name; //public method Query
    int number;
};

vector<Query> read_queries() {
    int n;
    cin >> n;
    vector<Query> queries(n);
    for (int i = 0; i < n; ++i) {
        cin >> queries[i].type;
        if (queries[i].type == "add")
            cin >> queries[i].number >> queries[i].name;
        // for those queries that start with add, look for 2 more parameters (name and num)
        else // for delete number and find queries
            cin >> queries[i].number;
    }
    return queries;
}

void write_responses(const vector<string>& result) {
    for (size_t i = 0; i < result.size(); ++i)
        std::cout << result[i] << "\n";
}
// Some utility functions
bool find(vector<string> contacts, int i) // To see if this vector found is
{
    if (i < contacts.size())
        return (contacts[i] != "not found");
    return false;
}
vector<string> process_queries(const vector<Query>& queries) {
    vector<string> result;
    // Keep list of all existing (i.e. not deleted yet) contacts.
    // Using direct addressing, create a vector of size 10**7.
    // Store strings in this array
    vector<string> contacts(static_cast<double>(pow(10,7)), "not found");
    for (size_t i = 0; i < queries.size(); ++i)
    {
        if (queries[i].type == "add")
        {
            contacts[queries[i].number] = queries[i].name;
        }
        else if (queries[i].type == "del")
        {
            contacts[queries[i].number] = "not found";
        }
        else
        {
            result.push_back(contacts[queries[i].number]);
        }
    }// endfor
    return result;
}

int main() {
    write_responses(process_queries(read_queries()));
    return 0;
}
