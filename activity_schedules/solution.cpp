#include <iostream>
#include <vector>
using namespace std;

vector<string> possibleActivities = {"Swimming", "Running", "Football"};
int countSchedules = 0;

void generateSchedules(int days, vector<string> currentSchedule) {
    if (currentSchedule.size() == days) {
        for (string activity : currentSchedule) {
            cout << activity << " ";
        }
        cout << endl;
        countSchedules++;
        return;
    }

    for (string activity : possibleActivities) {
        if (currentSchedule.empty() || activity != currentSchedule.back()) {
            vector<string> newSchedule = currentSchedule;
            newSchedule.push_back(activity);
            generateSchedules(days, newSchedule);
        }
    }
}

int main() {
    int n;
    cin >> n;

    generateSchedules(n, {});
    cout << "COUNT: " << countSchedules << endl;

    return 0;
}
