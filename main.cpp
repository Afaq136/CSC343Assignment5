
#include <iostream>
#include <vector>
#include <algorithm>

struct Process {
    int id;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
};

// Function to calculate waiting and turnaround times for FCFS
void calculateFCFS(std::vector<Process> &processes) {
    processes[0].waitingTime = 0;
    for (size_t i = 1; i < processes.size(); i++) {
        processes[i].waitingTime = processes[i - 1].waitingTime + processes[i - 1].burstTime;
    }
    for (size_t i = 0; i < processes.size(); i++) {
        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
    }
}

// Function to calculate waiting and turnaround times for SJF
void calculateSJF(std::vector<Process> &processes) {
    std::sort(processes.begin(), processes.end(), [](Process a, Process b) { return a.burstTime < b.burstTime; });
    calculateFCFS(processes); // After sorting, use FCFS logic
}

int main() {
    std::vector<Process> processes = {
        {1, 2, 0, 0}, {2, 1, 0, 0}, {3, 8, 0, 0}, {4, 4, 0, 0}, {5, 5, 0, 0}
    };

    // Calculate and display results for FCFS
    calculateFCFS(processes);
    std::cout << "----------------- FCFS -----------------\n";
    std::cout << "Process ID | Waiting Time | Turnaround Time\n";
    for (const auto &p : processes) {
        std::cout << "     " << p.id << "           |      " << p.waitingTime
                  << "                 |        " << p.turnaroundTime << "\n";
    }

    // Calculate and display results for SJF
    calculateSJF(processes);
    std::cout << "----------------- SJF -----------------\n";
    std::cout << "Process ID | Waiting Time | Turnaround Time\n";
    for (const auto &p : processes) {
        std::cout << "     " << p.id << "           |      " << p.waitingTime
                  << "                 |        " << p.turnaroundTime << "\n";
    }

    return 0;
}
