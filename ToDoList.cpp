#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
struct Task
{
    string name_task;
    string time_task;
};

void showTasks(const vector<Task>& tasks)
{
    cout << "Список задач:" << endl;
    for (int i = 0; i < tasks.size(); ++i)
    {
        cout << i + 1 << ". " << tasks[i].name_task<<" : "<<tasks[i].time_task << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "RU");
    vector<Task> tasks;
    Task task;
    char choice;

    ifstream inputFile("tasks.txt");
    while (getline(inputFile, task.name_task))
    {
        getline(inputFile, task.time_task);
        tasks.push_back(task);
    }
    inputFile.close();

    do
    {
        cout << "A - Добавить задачу" << endl;
        cout << "V - Показать задачу" << endl;
        cout << "Q - Выход" << endl;
        cout << "Выберете: ";
        cin >> choice;

        switch (choice)
        {
        case 'A':
        case 'a':
            cout << "Введите задачу: ";
            cin.ignore(); 
            getline(cin, task.name_task);
            cout << "Введите время(часы:минуты): ";
            getline(cin, task.time_task);
            tasks.push_back(task);
            break;
        case 'V':
        case 'v':
            showTasks(tasks);
            break;
        }
    } while (choice != 'Q' && choice != 'q');

    
    ofstream outputFile("tasks.txt");
    for (const auto& t : tasks)
    {
        outputFile << t.name_task<<" "<< t.time_task << endl;
    }
    outputFile.close();



    return 0;
}