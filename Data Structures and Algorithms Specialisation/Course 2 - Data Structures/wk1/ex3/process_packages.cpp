
/*
 Problem Description
 Task. You are given a series of incoming network packets, and your task is to simulate their processing. Packets arrive in some order. For each packet number 𝑖, you know the time when it arrived 𝐴𝑖 and the time it takes the processor to process it 𝑃𝑖 (both in milliseconds). There is only one processor, and it processes the incoming packets in the order of their arrival. If the processor started to process some packet, it doesn’t interrupt or stop until it finishes the processing of this packet, and the processing of packet 𝑖 takes exactly 𝑃𝑖 milliseconds.
 The computer processing the packets has a network buffer of fixed size 𝑆. /// Queue of fixed size S.
 When packets ar- rive, they are stored in the buffer before being processed. However, if the buffer is full when a packet arrives (there are 𝑆 packets which have arrived before this packet, and the computer hasn’t finished processing any of them), it is dropped and won’t be processed at all. /// Try to insert into the queue, if cannot insert then return -1.
 
 If several packets arrive at the same time, they are first all stored in the buffer (some of them may be dropped because of that — those which are described later in the input). The computer processes the packets in the order of their arrival, and it starts processing the next available packet from the buffer as soon as it finishes processing the previous one. If at some point the computer is not busy, and there are no packets in the buffer, the computer just waits for the next packet to arrive.
 /// Note that a packet leaves the buffer and frees the space in the buffer as soon as the computer finishes processing it.
 /// Seems to be a circular list implementation of a queue.
 
 Input Format. The first line of the input contains the size 𝑆 of the buffer and the number 𝑛 of incoming network packets. Each of the next 𝑛 lines contains two numbers. 𝑖-th line contains the time of arrival 𝐴𝑖 and the processing time 𝑃𝑖 (both in milliseconds) of the 𝑖-th packet. It is guaranteed that the sequence of arrival times is non-decreasing (however, it can contain the exact same times of arrival in milliseconds — in this case the packet which is earlier in the input is considered to have arrived earlier).
 
 /// Size S No.of packets n
 /// Arrival Time, Processing Time -- Ai, Pi
 
 
 Constraints. All the numbers in the input are integers. 1 ≤ 𝑆 ≤ 105; 0 ≤ 𝑛 ≤ 105; 0 ≤ 𝐴𝑖 ≤ 106; 0≤𝑃𝑖 ≤103;𝐴𝑖 ≤𝐴𝑖+1 for1≤𝑖≤𝑛−1.
 
 Output Format. For each packet output either the moment of time (in milliseconds) when the processor began processing it or −1 if the packet was dropped (output the answers for the packets in the same order as the packets are given in the input).

 */
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Request {
    Request(int arrival_time, int process_time):
        arrival_time(arrival_time),
        process_time(process_time) // constructor
    {}

    int arrival_time;
    int process_time;
};

struct Response {
    Response(bool dropped, int start_time):
        dropped(dropped),
        start_time(start_time)// constructor
    {}

    bool dropped;
    int start_time;
};

class Buffer {
public:
    Buffer(int size):
        size_(size),
        finish_time_()
    {}
    Response Process(const Request &request) {
        // write your code here
        // let's start by clearing all the tasks that should be already processed.
        while (!finish_time_.empty() && finish_time_.front() <= request.arrival_time)
        {
            finish_time_.pop();
        }
        bool dropped = ((this->finish_time_.size() == this->size_) && (request.arrival_time < this->finish_time_.back()));
        int start_time = -1;
        if (!dropped) {
            if (finish_time_.empty())
                start_time = request.arrival_time;
            else
                start_time = std::max(finish_time_.back(), request.arrival_time);

            finish_time_.push(start_time + request.process_time);
        }
        return Response(dropped, start_time);
    }
private:
    int size_;
    std::queue <int> finish_time_;
};

std::vector <Request> ReadRequests() { /* Code that creates a request using the Request                                                    constructor, and inserts it in the vector 'requests'.
                                        */

    std::vector <Request> requests;
    int count;
    std::cin >> count;
    for (int i = 0; i < count; ++i) {
        int arrival_time, process_time;
        std::cin >> arrival_time >> process_time;
        requests.push_back(Request(arrival_time, process_time));
    }
    return requests;
}

std::vector <Response> ProcessRequests(const std::vector <Request> &requests, Buffer *buffer) {
    /*
     With the stored variables from the request vector, the Process method in the buffer class
     processes each of the request in requests.
     Insert the response for each request into the responses vector.
     */
    std::vector <Response> responses;
    for (int i = 0; i < requests.size(); ++i)
        responses.push_back(buffer->Process(requests[i]));
    return responses;
}

void PrintResponses(const std::vector <Response> &responses) {
    for (int i = 0; i < responses.size(); ++i)
        std::cout << (responses[i].dropped ? -1 : responses[i].start_time) << std::endl;
}

int main() {
    int size;
    std::cin >> size;
    std::vector <Request> requests = ReadRequests();

    Buffer buffer(size);
    std::vector <Response> responses = ProcessRequests(requests, &buffer);

    PrintResponses(responses);
    return 0;
}
