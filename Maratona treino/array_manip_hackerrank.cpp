#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the arrayManipulation function below.
long arrayManipulation(int n, vector<vector<long>> queries) {
    vector<vector<long>> intervals;
    long max = 0;
    for(vector<long> query : queries){
        if(intervals.empty())
            intervals.push_back(query);
        else {
            bool endQuery = false;
            while(!endQuery)
                for(int i=0; i < intervals.size(); i++){
                    if(query[1] < intervals[i][0]){
                        intervals.insert(intervals.begin()+i, query);
                        endQuery = true;
                        break;
                    }
                    if(query[1] == intervals[i][0]){
                        vector<long> equal;
                        equal.push_back(query[1]);
                        equal.push_back(query[1]);
                        equal.push_back(query[2]+intervals[i][2]);
                        intervals[i][0]++;
                        intervals.insert(intervals.begin()+i, equal);
                        intervals.insert(intervals.begin()+i, query);
                        endQuery = true;
                        break;
                    }
                    if(query[1] == intervals[i][1]){
                        if(query[0] == intervals[i][0]){
                            intervals[i][2] += query[2];
                        } else {
                            if(query[0] > intervals[i][0]){
                                query[2] += intervals[i][2];
                                intervals[i][1] = query[1]-1;
                                intervals.insert(intervals.begin()+i+1, query);
                            }
                            else {
                                vector<long> pre;
                                pre.push_back(query[0]);
                                pre.push_back(intervals[i][0]-1);
                                pre.push_back(query[2]);

                                intervals[i][2] += query[2];
                                intervals.insert(intervals.begin()+i, pre);
                            }
                        }
                        endQuery = true;
                        break;
                    }
                    if(query[1] < intervals[i][1]){
                        if(query[0] == intervals[i][0]){
                            query[2] += intervals[i][2];
                            query[1] = intervals[i][0]-1;
                            intervals.insert(intervals.begin()+i+1, query);
                        } else {
                            if(query[0] > intervals[i][0]){
                                vector<long> pre;
                                vector<long> pos;
                                pre.push_back(intervals[i][0]);
                                pre.push_back(query[0]-1);
                                pre.push_back(intervals[i][2]);
                                pos.push_back(query[1]+1);
                                pos.push_back(intervals[i][1]);
                                pos.push_back(intervals[i][2]);
                                intervals[i][0] = query[0];
                                intervals[i][1] = query[1];
                                intervals[i][2] += query[2];

                                intervals.insert(intervals.begin()+i+1, pos);
                                intervals.insert(intervals.begin()+i, pre);
                            }
                            else {
                                vector<long> pre;
                                vector<long> pos;
                                pre.push_back(query[0]);
                                pre.push_back(intervals[i][0]-1);
                                pre.push_back(query[2]);
                                pos.push_back(query[1]+1);
                                pos.push_back(intervals[i][1]);
                                pos.push_back(intervals[i][2]);
                                intervals[i][1] = query[1];
                                intervals[i][2] += query[2];

                                intervals.insert(intervals.begin()+i+1, pos);
                                intervals.insert(intervals.begin()+i, pre);
                            }
                        }
                        endQuery = true;
                        break;
                    }
                    if(query[1] > intervals[i][1]){
                        if(query[0] > intervals[i][1]) {
                            if(i+1 == intervals.size()){
                                intervals.push_back(query);
                                endQuery = true;
                                break;
                            }
                            else {
                                continue;
                            }
                        }
                        if(query[0] == intervals[i][0]){
                            query[0] = intervals[i][1]+1;
                            intervals[i][2] += query[2];
                            break;
                        }
                        if(query[0] > intervals[i][0]){
                            vector<long> pre;
                            pre.push_back(intervals[i][0]);
                            pre.push_back(query[0]-1);
                            pre.push_back(intervals[i][2]);

                            intervals[i][0] = query[0];
                            intervals[i][2] += query[2];

                            query[0] = intervals[i][1]+1;

                            intervals.insert(intervals.begin()+i, pre);
                            break;
                        }
                        vector<long> pre;
                        pre.push_back(query[0]);
                        pre.push_back(intervals[i][0]-1);
                        pre.push_back(query[2]);

                        intervals[i][2] += query[2];

                        query[0] = intervals[i][1]+1;
                        intervals.insert(intervals.begin()+i, pre);
                    }
                }
        }
    }
    for(vector<long> interval : intervals)
        if(interval[2] > max)
            max = interval[2];
    return max;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<vector<long>> queries(m);
    for (int i = 0; i < m; i++) {
        queries[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> queries[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long result = arrayManipulation(n, queries);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

