#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;
/*
    ***************SAFE MOVE****************
    => Sort value per unit in decending order
    ***************ALGORITHM****************
    => Insert the largest values[i]/weights[i] to the
        knapsack if it is feasible else fill it as much
        as it can hold
    => Insert the next as per the above rule and continue
*/

int no_of_items = 0;
vector<int> weights;
vector<int> values;
vector<double> value_per_unit;

int get_max_index()
{
    int max_index = -1;
    for(int i = 0; i < no_of_items; i++)
    {
        if(max_index == -1 || value_per_unit[i] > value_per_unit[max_index])
            max_index = i;
    }
    //cout<<"Max Index:"<<max_index<<'\n';
    return max_index;   
}

int min(int a, int b)
{
    if(a <= b)
        return a;
    else
        return b;
}

double get_max_value(int total_weight)
{
    double final_value = 0.0;
    for(int i = 0; i < no_of_items; i++)
    {
        if(total_weight == 0)
            return final_value;

        int max_index = get_max_index();
        int a = min(weights[max_index], total_weight);
        final_value += a * value_per_unit[max_index];
        weights[max_index] -= a;
        if(weights[max_index] == 0)
            value_per_unit[max_index] = 0;
        else    
            value_per_unit[max_index] = values[max_index] / weights[max_index];
        total_weight -= a; 
    }
    return final_value;
}

main()
{
    int total_weight = 0;

    // These are temporary values to get input(value & weight) from user
    int temp_weight = 0;
    int temp_value = 0;

    //cout<<"Enter total number of items:";
    cin>>no_of_items;
    
    //cout<<"Enter total capacity of knapsack:";
    cin>>total_weight;
    
    //cout<<"Enter the values and its corresponding weight:\n";
    for(int i = 0; i < no_of_items; i++)
    {
        cin>>temp_value;
        cin>>temp_weight;
        values.push_back(temp_value);
        weights.push_back(temp_weight);
    }

    for(int i = 0; i < no_of_items; i++)
    {
        value_per_unit.push_back(((double)values[i])/ ((double)weights[i]));
        //cout<<value_per_unit[i]<<'\n';
    }

    //cout<<"Maximum value knapsack can hold is:";
    cout<<fixed<<setprecision(4);
    cout<<get_max_value(total_weight)<<'\n';
}
