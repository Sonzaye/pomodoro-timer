#include <iostream>
#include <chrono>
#include <thread>

void runTimer(int minutes, const std::string& label) {
    int seconds = minutes * 60;
    std::cout << "Starting " << label << " (" << minutes << " minutes)..." << std::endl;

    while (seconds > 0) {
        int m = seconds / 60;
        int s = seconds % 60;

        std::cout << "\r" << label << ": " << m << "m " << s << "s remaining " << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        seconds--;
    }

    std::cout << "\nDone! Time for a break." << std::endl;
}

int main() {
    int focusTime = 25;
    int breakTime = 5;

    std::cout << "Pomodoro Timer\n";
    std::cout << "Focus time: " << focusTime << " minutes\n";
    std::cout << "Break time: " << breakTime << " minutes\n";

    runTimer(focusTime, "Focus Session");
    runTimer(breakTime, "Break");

    return 0;
}
