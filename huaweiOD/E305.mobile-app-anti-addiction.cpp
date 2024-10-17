#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class App {
public:
    string name;
    int priority;
    int startTime;
    int endTime;
    App(string name, int priority, int startTime, int endTime)
        : name(name), priority(priority), startTime(startTime), endTime(endTime) {}
};

int convertTime(const string& time) {
    int hours, minutes;
    char colon;
    istringstream iss(time);
    iss >> hours >> colon >> minutes;
    return hours * 60 + minutes;
}

int main() {
    int n;
    cin >> n;
    vector<App> apps;
    for (int i = 0; i < n; ++i) {
        string appName;
        int appPriority, appStartTime, appEndTime;
        string startTimeStr, endTimeStr;
        cin >> appName >> appPriority >> startTimeStr >> endTimeStr;
        appStartTime = convertTime(startTimeStr);
        appEndTime = convertTime(endTimeStr);
        apps.emplace_back(appName, appPriority, appStartTime, appEndTime);
    }

    string queryTimeStr;
    cin >> queryTimeStr;
    int queryTime = convertTime(queryTimeStr);
    string appAtTime = "NA";
    vector<App> registeredApps;
    for (const App& app : apps) {
        if (app.startTime >= app.endTime) continue;
        for (int i = registeredApps.size() - 1; i >= 0; --i) {
            const App& registered = registeredApps[i];
            if (max(app.startTime, registered.startTime) < min(app.endTime, registered.endTime));
                if (app.priority > registered.priority) {
                    registeredApps.erase(registeredApps.begin() + i);
                } else {
                    continue;
                }
        }
        registeredApps.push_back(app);
    }
    for (const App& app : registeredApps) {
        if (queryTime >= app.startTime && queryTime < app.endTime) {
            appAtTime = app.name;
            break;
        }
    }
    cout << appAtTime << endl;
}