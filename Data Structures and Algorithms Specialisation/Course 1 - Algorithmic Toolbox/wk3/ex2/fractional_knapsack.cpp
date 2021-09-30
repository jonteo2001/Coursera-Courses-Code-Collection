#include <iostream>
#include <vector>
#include <algorithm> //contains merge sort
#include <utility> //contains pair data type
#include <iomanip> //for the precision operator
using namespace std;
//Global variable

//Sorting the second variable of a pair
bool sortbysec(const pair<int, double> &a, const pair<int, double> &b)
{
    return (a.second < b.second);
}

//Create a vector that gives the minimum cost
vector<pair<int, double> > get_unit_cost (vector<int> weights, vector<int> values)
{//Initialise vector set all pair values to 0
    vector<pair<int, double> > unitcost;
    for (int i = 0; i < weights.size(); i++)
    {
        pair<int,double> index_cost;
        index_cost.first = i;
        index_cost.second = static_cast<double>(values[i])/static_cast<double>(weights[i]);
        unitcost.push_back(index_cost);
    }
    //Sort elements in reverse order with highest value/weight first.
    sort(unitcost.rbegin(), unitcost.rend(), sortbysec);
    return unitcost;
}

//Get optimal weight
double get_optimal_value(int capacity, vector<int> weights, vector<int> values, vector<pair<int,double> >unitcost)
{
    double value = 0.00000;
    // write your code here
    //There exists an optimal solution that uses as much as possible of an item with the maximal value per unit of weight.
    int i = 0;
    while (i < unitcost.size())
    {
        //cout << "capacity = " << capacity <<  "| Value = " << setprecision(10)<< value<< endl;//
        if (capacity == 0)
        {
            return value;
        }
        int weight = weights[unitcost[i].first];
        if (capacity >= weight)
        {//Take the entire weight
            capacity = capacity-weight;
            value = value + static_cast<double>(values[unitcost[i].first]);
        }
        else // capacity < weight
        {//remaining weight * cost per unit mass = value
            value = value + static_cast<double>(capacity) * unitcost[i].second;
            capacity = 0;
        }
        //Run this iteratively until capacity == 0
        i++;
    }
    return value;
}

int main() {
    int n;
    int capacity;
    std::cin >> n >> capacity;
    vector<int> values(n);
    vector<int> weights(n);
    for (int i = 0; i < n; i++)
    {
        cin >> values[i] >> weights[i];
    }
    vector<pair<int, double> > unitcost(n);
    unitcost = get_unit_cost(weights,values);
    
    std::cout << setprecision(10) << get_optimal_value(capacity, weights, values, unitcost)<< std::endl;
    return 0;
}
