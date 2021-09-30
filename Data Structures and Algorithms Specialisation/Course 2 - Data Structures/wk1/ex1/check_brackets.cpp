#include <iostream>
#include <stack>
#include <string>
using namespace std;
/*
 For convenience, the text editor should not only inform the user that there is an error in the usage of brackets, but also point to the exact place in the code with the problematic bracket.
 
 - First priority is to find the first unmatched closing bracket which either doesn’t have an opening bracket before it, like ] in ]() // stack is empty
 or closes the wrong opening bracket, like } in ()[}. //Matchc == false
 
 - If there are no such mistakes, then it should find the first unmatched opening bracket without the corresponding closing bracket after it, like ( in {}([].
    //stack isn't empty after the for loop has finished executed.
 
 - If there are no mistakes, text editor should inform the user that the usage of brackets is correct.
 
 Input Format. Input contains one string 𝑆 which consists of big and small latin letters, digits, punctuation marks and brackets from the set []{}().
 
 Constraints. The length of 𝑆 is at least 1 and at most 10^5.
 
 Output Format. If the code in 𝑆 uses brackets correctly, output “Success" (without the quotes). Otherwise, output the 1-based index of the first unmatched closing bracket, and if there are no unmatched closing brackets, output the 1-based index of the first unmatched opening bracket.

 */
struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);

    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket, write your code here
            opening_brackets_stack.push(Bracket(next, (position+1)));
        }
        if (next == ')' || next == ']' || next == '}') {
            // Process closing bracket, write your code here
            //Corner case where stack is empty
            //Priority 1
            if (opening_brackets_stack.empty()) {cout << position+1 << endl; return 0;}
            //Now check the top of the stack using pop element.
            //Priority 1
            if(!opening_brackets_stack.top().Matchc(next))
            {
                cout<<(position+1)<<endl; return 0;//index of next in text.

            }
            //Substring is balanced. Remove the open bracket from stack.
            opening_brackets_stack.pop();
        }//endif
        //If string is any other character
        else {continue;}
    }//end for
    if (opening_brackets_stack.empty()) {cout << "Success" << endl;}
    else
    {
        // Priority 2
        Bracket first_unclosed_bracket = Bracket('*', -1); // initialised a variable bracket.
        while (!opening_brackets_stack.empty())
        {
            first_unclosed_bracket = opening_brackets_stack.top();
            opening_brackets_stack.pop();
        }
        // Now we have obtained that bracket, print out it's position.
        cout << first_unclosed_bracket.position <<endl;
    }

    // Printing answer, write your code here

    return 0;
}
