
---

````markdown
# CLI Todo App in C++

A simple command-line todo list manager built in C++ with file persistence.

This app allows you to:
- Add tasks with unique IDs
- View current tasks
- Delete tasks by ID
- Automatically save and load tasks from a local file (`tasks.txt`)

---

## 🔧 How to Compile

Ensure you have a C++ compiler installed (like `g++`), then:

```bash
g++ src/main.cpp -o bin/todo
````

---

## ▶️ How to Run

```bash
./bin/todo
```

You’ll see a prompt like this:

```
Commands: add, show, quit, delete <id>
Enter Command:
```

---

## 📂 File Structure

```
clitodo/
├── src/
│   └── main.cpp         # Application source code
├── bin/
│   └── todo             # Compiled binary (after build)
├── tasks.txt            # Auto-generated task storage (ignored by Git)
├── .gitignore
└── README.md
```

---

## 💾 Task Storage

Tasks are saved in a simple text file `tasks.txt`, using the format:

```
1|Buy milk
2|Finish C++ project
```

* The file is automatically created if it doesn't exist.
* Tasks persist across program runs.

---

## ❌ Git Ignore

The `tasks.txt` file is ignored in version control using `.gitignore`, to avoid storing personal task data.

```gitignore
tasks.txt
```

---

## ✍️ Author

Made with effort and focus by **Debopriyo Ghosh**
*First full C++ CLI project with file persistence.*

