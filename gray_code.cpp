#include<iostream>
#define Number_max_columns 10
#define Number_max_rows (1<<Number_max_columns) // this is equivalent to 2^10 = 1024
using namespace std;

int n, Gray_code[Number_max_rows][Number_max_columns];
void generate_cod(int x); // the function is defined below main
int main()
{
    cin >> n;
    generate_cod(n);
    for(int i=0; i< (1<<n); i++){
        for(int j=0; j<n; j++) cout<<Gray_code[i][j]<<' ';
        cout<<endl;
    }
}

void generate_code(int x){
    if(x==1) Gray_code[1][0] = 1; /*the call of function which executes firstly, creating
    this array:     0
                    1     and for the every single call of function on the stack, the number
    of rows doubles and the number of columns increases by one
    */
   
    else{
        generate_code(x-1);
        for(int i=(1<<(x-1)); i< (1<<x); i++){
            for(int j=0; j<x-1; j++) Gray_code[i][j] = Gray_code[(1<<x) - i - 1][j];
            Gray_code[i][x-1] = 1; 
        }/* on the Xth column, the elements from index 0 to (2^x)/2-1 remains zero, but
the ones from (2^x)/2 to 2^x-1 are set, being given the value of 1
    Example: for the generate_code(3) on the third column(with index 2 because are counted starting with 0),
the first 4 elements(from 0 to 3) remains unset(zero), and the rest of 4 elements ranging from 4 to 7 become 1
    */
    }
}