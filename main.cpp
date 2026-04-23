#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    long long a, b, c, d, e, f;
    if (!(cin >> a >> b >> c >> d >> e >> f)) return 0;

    long long T = a * b * c;
    long long S_curr = f * a * b + e * a + d;

    long long min_s = -1;

    // A coincidence occurs when hour == minute == second = x
    // where 0 <= x < min(a, b, c)
    // The total seconds at coincidence x is:
    // S_target = x * (a * b) + x * a + x

    long long limit = min({a, b, c});
    for (long long x = 0; x < limit; ++x) {
        long long S_target = x * a * b + x * a + x;
        long long s = (S_target - S_curr) % T;
        if (s <= 0) s += T;

        if (min_s == -1 || s < min_s) {
            min_s = s;
        }
    }

    if (min_s == -1) {
        // This case should not be reached given constraints
        cout << 0 << endl;
    } else {
        cout << min_s << endl;
    }

    return 0;
}
