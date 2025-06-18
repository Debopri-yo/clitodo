#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
	cout<<"welcome to the todo app";
	string input;
	while(true){
		cout<<"\n Commands: add, show, quit\n";
		cout<<"Enter Command";
		getline(cin, input);
		if(input=="quit"){
			cout<<"Goodbye\n";
			break;
		}
		else if(input=="add"){
			cout<<"[Feature Pending]Add a new task here\n";
		}
		else if (input=="show"){
			cout<<"[Feature Pending]Show Tasks here";
		}
		else{
			cout<<"Unknown Command";
		}
	}

return 0;
}

		
