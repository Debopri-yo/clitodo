#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

struct Task {
    int id;
    string description;
};
void loadTasks(vector<Task>& tasks, int& nextId);
void saveTasks(const vector<Task>& tasks);

int main() {
	cout << "Welcome to the todo app";

    vector<Task> tasks;
    int nextId=1;
	loadTasks(tasks,nextId);

    string input;
    while (true) {
        cout << "\nCommands: add, show, quit, delete <id>\n";
        cout << "Enter Command: ";
        getline(cin, input);

        if (input == "quit") {
            cout << "Goodbye!\n";
            break;
        }
        else if (input == "add") {
            cout << "Enter task description: ";
            string desc;
            getline(cin, desc);

            Task newTask = {nextId++, desc};
            tasks.push_back(newTask);
	    saveTasks(tasks);
            cout << "Task added!\n";
        }
        else if (input == "show") {
            if(tasks.empty()){
                cout << "list is empty ; add new tasks to be shown";
            }
            else
                cout << "Your tasks:\n";
                    for (const auto& task : tasks) {
                        cout << task.id << ": " << task.description << endl;
                    }
        }
	else if (input.substr(0,7) == "delete "){
	    bool found = false;
		string idPart = input.substr(7);
       		int idToDelete = stoi(idPart);
		for(size_t i=0;i<tasks.size();i++){
			if (tasks[i].id == idToDelete){
				tasks.erase(tasks.begin() + i);
				found = true;
                cout<<"task deleted successfully"<<endl;
			for(size_t j=i;j<tasks.size();j++){
            tasks[j].id = j + 1;
            }
		saveTasks(tasks);	
            nextId = tasks.size() + 1;
            break;
        }
		}
		if (!found)
				cout<<"task not found"<<endl;
	}
			
	else {
            cout << "Unknown Command.\n";
        }
    }

    return 0;
}
void loadTasks(vector<Task>& tasks, int& nextId){
	ifstream file("tasks.txt");
	if(!file.is_open()){
		cout<<"file does not exist"<<endl;
		return;
	}
	int maxID=0;
	string line;
	while(getline(file,line)){
		size_t sep= line.find('|');
		if(sep != string::npos){
			string idPart=line.substr(0, sep);
			string descPart=line.substr(sep+1);
			int id=stoi(idPart);
			Task task{id,descPart};
			tasks.push_back(task);
            if (id > maxID) maxID = id;   
        }
	nextId=maxID+1;
	}
	file.close();
}
void saveTasks(const vector<Task>& tasks){
	ofstream file("tasks.txt");
	if(!file.is_open()){
		cout<<"could not write to tasks"<<endl;
		return;
	}
	for(const auto& task: tasks){
		file<<task.id<<"|"<<task.description<<"\n";
	}
	file.close();
}


