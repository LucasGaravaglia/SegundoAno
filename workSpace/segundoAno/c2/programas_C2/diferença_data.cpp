#include <iostream>
#include <string.h>

using namespace std;


int main(){
	char data[13];
	strcpy(data,__DATE__);
    cout << "Hoje é "<<data<< endl;
}
