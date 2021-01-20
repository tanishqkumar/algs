#include <iostream>
#include "helpers.hh"
#include <algorithm>

using namespace std; 

struct activity{
    int start_time; 
    int finish_time; 
};

// take as input two vectors, and output vector<int> of activities
vector<activity> greedy_activity_selector(vector<activity> input_activities){
    // assume sorted by finish times
    vector<activity> max_activities;
    int prev_act_finish_time = 0; 

    for (int i = 0; i < input_activities.size(); ++i){
        // get the first act in input_act whose start_time is > prev_act.finish_time
        if (input_activities[i].start_time > prev_act_finish_time){
            max_activities.push_back(input_activities[i]);
            prev_act_finish_time = input_activities[i].finish_time; 
            input_activities[i].start_time = -1; 
        }
    }

    return max_activities;
}

vector<activity> sort_activities_by_finish_time(vector<activity> input_activities) {
    vector<activity> sorted_activites; 
    int fastest_act_index = 0;

    for (int i = 0; i < input_activities.size(); ++i){
        input_activities[fastest_act_index].finish_time = 11;
        for (int i = 0; i < input_activities.size(); ++i){
            if (input_activities[i].finish_time < input_activities[fastest_act_index].finish_time){
                fastest_act_index = i;
            }
        }
        // here the fastest activity should really be the current fastest activity
        sorted_activites.push_back(input_activities[fastest_act_index]);
    }

    return sorted_activites;
}

int main(){
    int num_activities = 10;
    vector<activity> input_activities;
    for (int i = 0; i < num_activities; ++i){
        activity ac; 
        ac.start_time = rand_int(1, 8);
        ac.finish_time = rand_int(ac.start_time + 1, 10);
        input_activities.push_back(ac);
    }

    vector<activity> sorted_activities = sort_activities_by_finish_time(input_activities);

    cout << "before: " << endl; 
    for (auto act: sorted_activities){
        cout << "start time: " << act.start_time << " and finish time: " << act.finish_time;
        cout << endl; 
    }

    cout << "after: " << endl; 
    vector<activity> max_activities = greedy_activity_selector(sorted_activities);
    for (auto act: max_activities){
        cout << "start time: " << act.start_time << " and finish time: " << act.finish_time;
        cout << endl; 
    }

}