#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

struct Segment {
  int start, end;
};

bool overlap (Segment &a, Segment &b)
{
    return (a.end >= b.start && b.end >= a.start)
}
bool sortbylower (Segment &a, Segment &b)
{
    return (a.start < b.start);
}

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
    int disjoint = 1;
  //write your code here
    //Sort the segments with respect to their first element
    sort(segments.begin(), segments.end(), sortbylower);
    //First find the minimum number of disjointed sets
    int i = 0;
    while (i < segments.size())
    {
        int j = i+1;
        while (j < segments.size())
        {
            if (overlap(segments[i], segments[j]) == true) {continue;}
            else
            {//Since i and j don't overlap, there are at least 1 more disjoint set.
                disjoint+=1;
                break; // out of the while loop.
            }
            j++;
            //If j reaches segments.size(), it means that all the segments are connected, and only 1 segment is required.
        }//If not, however, j breaks out of the loop
        
    }
  for (size_t i = 0; i < segments.size(); ++i) {
    points.push_back(segments[i].start);
    points.push_back(segments[i].end);
  }
  return points;
}
int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
