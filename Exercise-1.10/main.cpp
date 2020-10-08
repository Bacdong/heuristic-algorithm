#include <iostream>
#define maxN 100

using namespace std;

void swap(int &firstParameter, int &secondParameter);
void arrSort(int taskTime[], int taskId[], int qtyTask);
int chooseMachine(int machine[], int qtyMachine);

int main() {
    int qtyTask;
    int qtyMachine;

    int taskId[maxN];
    int machineTime[maxN];
    int machine[maxN] = {0};

    cout << "Step 1: Enter quantity machine (m): ";
    cin >> qtyMachine;

    cout << "Step 2: Enter quantity task (n): ";
    cin >> qtyTask;

    cout << "Step 3: Enter time complete the job" << endl;
    for (int i = 1; i <= qtyTask; ++i) {
        cout << "The " << i << "th job completion time is: ";
        cin >> machineTime[i];
        taskId[i] = i;
    }

    arrSort(machineTime, taskId, qtyTask);

    int result[maxN];
    for (int i = 1; i <= qtyTask; ++i) {
        int position = chooseMachine(machine, qtyMachine);
        result[taskId[i]] = position;
        machine[position] += machineTime[i];
    }

    cout << endl << "========== ASSIGNMENT OF WORK TABLE ==========" << endl << endl;
    for (int i = 1; i <= qtyTask; ++i) {
        cout << "The " << i << "th job -----> the " << result[i] << "th machine" << endl;
    }
    cout << endl << "========== ASSIGNMENT OF WORK TABLE ==========" << endl;

    return 0;
}

void swap(int &firstParameter, int &secondParameter) {
    int temp = firstParameter;
    firstParameter = secondParameter;
    secondParameter = temp;
}

void arrSort(int taskTime[], int taskId[], int qtyTask) {
    for (int i = 1; i <= qtyTask-1; ++i) {
        for (int j = i+1; j <= qtyTask; ++j) {
            if (taskTime[i] < taskTime[j]) {
                swap(taskTime[i], taskTime[j]);
                swap(taskId[i], taskId[j]);
            }
        }
    }
}

int chooseMachine(int machine[], int qtyMachine) {
    int min = machine[1];
    int position = 1;

    for (int i = 1; i <= qtyMachine; ++i) {
        if (machine[i] < min) {
            min = machine[i];
            position = i;
        }
    }
    
    return position;
}

