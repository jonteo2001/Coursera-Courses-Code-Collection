/*
 Problem Introduction
 In this problem you will simulate a program that processes a list of jobs in parallel. Operating systems such as Linux, MacOS or Windows all have special programs in them called schedulers which do exactly this with the programs on your computer.
 
 Problem Description
 Task. You have a program which is parallelized and uses 𝑛 independent threads to process the given list of 𝑚 jobs.
 Threads take jobs in the order they are given in the input.
 If there is a free thread, it immediately takes the next job from the list.
 If a thread has started processing a job, it doesn’t interrupt or stop until it finishes processing the job.
 If several threads try to take jobs from the list simultaneously,
 the thread with smaller index takes the job.
 For each job you know exactly how long it will take any thread to process this job, and this time is the same for all the threads.
 You need to determine for each job which thread will process it and when will it start processing.
 
 Input Format. The first line of the input contains integers 𝑛 and 𝑚.
 
 The second line contains 𝑚 integers 𝑡𝑖 — the times in seconds it takes any thread to process 𝑖-th job. The times are given in the same order as they are in the list from which threads take jobs.
 Threads are indexed starting from 0.
 
 Constraints. 1 ≤ 𝑛 ≤ 10^5; 1 ≤ 𝑚 ≤ 10^5; 0 ≤ 𝑡𝑖 ≤ 10^9.
 
 Output Format. Output exactly 𝑚 lines.
 𝑖-th line (0-based index is used) should contain two space- separated integers — the 0-based index of the thread
 which will process the 𝑖-th job and the time in seconds when it will start processing that job.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using std::vector;
using std::cin;
using std::cout;

struct thread
{
    int thread_idx; // index of thread
    long long finish_time = 0;
}
class JobQueue {
 private:
  int num_workers_;
  vector<int> jobs_;
    vector<Thread> threads; // vector of threads

  vector<int> assigned_workers_;
  vector<long long> start_times_;

  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }
    
  void ReadData() {
    int m;
    cin >> num_workers_ >> m;
      //Create a vector
    jobs_.resize(m);
      threads.resize(num_workers); // My own code
    for(int i = 0; i < m; ++i)
      cin >> jobs_[i];
  }
    //Some utility functions ---------------------
    int Parent(int i) {return (static_cast<double>(i-1)/2);}
    int LeftChild(int i){return (2*i + 1);}
    int RightChild(int i){return (2*i + 2);}
    void BuildHeap(vector<long long> array);
    {
        for(int i = floor (static_cast<double>(array.size()))
    }
            // use finish_time to determine order
            void SiftDown(int i){
                int minIndex = i;
                int l = LeftChild(i);
                // if both finish_time are the same compare index of threads
                if(l < threads.size()){
                    if((threads[l].finish_time < threads[minIndex].finish_time)
                       || (threads[l].finish_time == threads[minIndex].finish_time
                       && threads[l].threadIndex < threads[minIndex].threadIndex)) {
                        minIndex = l;
                    }
                }
                int r = RightChild(i);
                if(r < threads.size()){
                    if((threads[r].finish_time < threads[minIndex].finish_time)
                       || (threads[r].finish_time == threads[minIndex].finish_time
                       && threads[r].threadIndex < threads[minIndex].threadIndex)){
                        minIndex = r;
                    }
                }
                if(i != minIndex){
                    swap(threads[i], threads[minIndex]);
                    SiftDown(minIndex);
                }
            }
  void AssignJobs() {
    // TODO: replace this code with a faster algorithm.
      /*
       Think about the sequence of events when one of the threads becomes free (at the start and later after completing some job). How to apply priority queue to simulate processing of these events in the required order? Remember to consider the case when several threads become free simultaneously.
       */
            for(int i = 0; i < num_workers_; i++){
                threads[i].threadIndex = i;
                threads[i].finish_time = 0;
            }
            assigned_workers_.resize(jobs_.size());
            start_times_.resize(jobs_.size());
            for (int i = 0; i < jobs_.size(); ++i){
                assigned_workers_[i] = threads[0].threadIndex;
                start_times_[i] = threads[0].finish_time;
                // update finish time of root
                long long new_finish_time = threads[0].finish_time + jobs_[i];
                threads[0].finish_time = new_finish_time;
                // check after updating finish_time of root whether if the heap change or not
                SiftDown(0);
    }
  }

 public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
