#include<sstream>
#include<iostream>
#include<stdio.h>
#include<cstring>
#include<unistd.h>

using namespace std;

int main()
{
	char *argv[100];
// argv=new char*[100];
	int argc = 0;
	string cmd;
	getline(cin, cmd);
	// making a string stream
    stringstream iss(cmd);
    for(int i=0;i<100;i++) argv[i]=new char [100];
    // Read and print each word.
    while (iss >> argv[argc]) argc++;
    argv[argc]=NULL;
    execvp(argv[0],argv);
}



