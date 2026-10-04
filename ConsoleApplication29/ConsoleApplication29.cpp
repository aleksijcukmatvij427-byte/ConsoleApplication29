#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    double profit[12];

    // Input profits for 12 months
    cout << "Enter profit for each of the 12 months:" << endl;
    for (int i = 0; i < 12; i++) {
        cout << "Month " << i + 1 << ": ";
        cin >> profit[i];
    }

    // Input the range
    int startMonth, endMonth;
    cout << "\nEnter range (start and end month, e.g., 3 6): ";
    cin >> startMonth >> endMonth;

    // Convert months to 0-based indices
    int startIdx = startMonth - 1;
    int endIdx = endMonth - 1;

    // If user entered the range in reverse order, swap them
    if (startIdx > endIdx) {
        swap(startIdx, endIdx);
    }

    // Ensure indices are within valid bounds (0 to 11)
    if (startIdx < 0) startIdx = 0;
    if (endIdx > 11) endIdx = 11;

    // Initialize max and min with the first element of the range
    double maxProfit = profit[startIdx];
    double minProfit = profit[startIdx];
    int maxMonth = startIdx + 1;
    int minMonth = startIdx + 1;

    // Loop through the selected range to find max and min
    for (int i = startIdx; i <= endIdx; i++) {
        if (profit[i] > maxProfit) {
            maxProfit = profit[i];
            maxMonth = i + 1;
        }
        if (profit[i] < minProfit) {
            minProfit = profit[i];
            minMonth = i + 1;
        }
    }

    // Output the results
    cout << "\nMonth with maximum profit: " << maxMonth << " (" << maxProfit << ")" << endl;
    cout << "Month with minimum profit: " << minMonth << " (" << minProfit << ")" << endl;

    return 0;
}