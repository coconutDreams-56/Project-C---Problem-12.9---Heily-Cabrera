// # Project-C--Problem-12.9---Heily-Cabrera

/**Sometimes, directory or file names have numbers in the middle, and there may be more than one number, for example, sec3_14.txt or sec10_1.txt. 
Provide a comparison operator that can compare such strings in a way that makes sense to humans. 
Break each string into strings not containing digits and digit groups. 
Then compare two strings by comparing the first non-digit groups as strings, the first digit groups as integers, and so on. **/

//Programmer: Heily Cabrera
//Tester: Giannfranco Brance

// Group Project C //
/***** Members *****/
/***** Ashley Jacobson *****/
/***** Giannfranco Brance *****/
/***** Audrey Tapia *****/
/***** Heily Cabrera Guerrero *****/


#include <iostream>
#include <vector>
#include <string>
#include <cctype>   
#include <algorithm> 

using namespace std;

vector<string> split_parts(const string& s) 
{
    vector<string> parts;
    string current;
    bool in_number = false;

    for (char c : s) 
    {
        if (isdigit(c)) 
        {
            if (!in_number) 
            {
                if (!current.empty()) parts.push_back(current);
                current = "";
                in_number = true;
            }
            current += c;
        } 
        else
        {
            if (in_number) {
                if (!current.empty()) parts.push_back(current);
                current = "";
                in_number = false;
            }
            current += c;
        }
    }
    if (!current.empty()) parts.push_back(current);
    return parts;
}

bool natural_compare(const string& a, const string& b) 
{
    vector<string> partsA = split_parts(a);
    vector<string> partsB = split_parts(b);

    size_t len = min(partsA.size(), partsB.size());

    for (size_t i = 0; i < len; i++) 
    {
        const string& partA = partsA[i];
        const string& partB = partsB[i];

        bool isNumA = all_of(partA.begin(), partA.end(), ::isdigit);
        bool isNumB = all_of(partB.begin(), partB.end(), ::isdigit);

        if (isNumA && isNumB) 
        {
            int numA = stoi(partA);
            int numB = stoi(partB);
            if (numA != numB) return numA < numB;
        } 
        else 
        {
            if (partA != partB) return partA < partB;
        }
    }

    return partsA.size() < partsB.size();
}

int main() 
{
    vector<string> filenames = 
    {
        "sec3_14.txt",
        "sec10_1.txt",
        "sec3_2.txt",
        "sec10_10.txt",
        "sec3_10.txt"
    };

    sort(filenames.begin(), filenames.end(), natural_compare);

    cout << "Sorted filenames:" << endl;
    for (const string& name : filenames) 
    {
        cout << name << endl;
    }

    return 0;
}
