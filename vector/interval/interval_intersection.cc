#include <iostream>
#include <vector>

using namespace std;

class Interval{
    public:
        int start, end;
        Interval(int s, int e): start(s), end(e){}
};

vector<Interval> getIntersection(vector<Interval> v1, vector<Interval> v2) {
    vector<Interval> ans;
    //if (v1.empty() || v2.empty()) return ans;

    int i = 0, j = 0;
    int m = v1.size(), n = v2.size();
    while (i < m && j < n) {
        if (v2[j].end <= v1[i].start)  ++j;
        else if (v2[j].start >= v1[i].end) ++i;
        else {
            int ts = max(v1[i].start, v2[j].start);
            int te = min(v1[i].end, v2[j].end);
            Interval tmp(ts, te);
            ans.push_back(tmp);

            if (v2[j].end == te) ++j;
            else if (v1[i].end == te) ++i;
        }
    }
    return ans;
}

int main()
{
    Interval a1(1, 2);
    Interval a2(4, 6);
    Interval a3(8, 10);
    vector<Interval> v1;
    v1.push_back(a1);
    v1.push_back(a2);
    v1.push_back(a3);

    Interval b1(1, 3);
    Interval b2(5, 8);
    Interval b3(9, 12);
    vector<Interval> v2;
    v2.push_back(b1);
    v2.push_back(b2);
    v2.push_back(b3);

    vector<Interval> v = getIntersection(v1, v2);

    for (vector<Interval>::iterator it = v.begin(); it != v.end(); ++it) {
        cout << it->start << "\t" << it->end << endl;
    }

    return 0;

}
