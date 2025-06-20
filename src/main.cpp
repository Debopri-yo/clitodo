#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    int id;
    string description;
};

int main() {
    cout << "Welcome to the todo app";

    vector<Task> tasks;
    int nextId = 1;

    string input;
    while (true) {
        cout << "\nCommands: add, show, quit\n";
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
            cout << "Task added!\n";
        }
        else if (input == "show") {
            cout << "Your tasks:\n";
            for (const auto& task : tasks) {
                cout << task.id << ": " << task.description << endl;
            }
        }
        else {
            cout << "Unknown Command.\n";
        }
    }

    return 0;
}

