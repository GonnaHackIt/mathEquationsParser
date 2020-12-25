#include <iostream>
#include <vector>
#include "yard.h"
#include "shunt_parser.h"
using namespace std;


int main()
{
    
    string expr;
    cin >> expr;

    string postfix;

    postfix = shunt_yard(expr);
    

    int result;
    result = parseShunt(postfix);
    cout << result << endl;
  

    return 0;
}
