#include<iostream>
#include<vector>
using namespace std;

void linearSearch(vector<int> arr,int key)
{
    int left = 0;
    int length = arr.size();
    int right = length - 1;

    int pos = -1;//position where key is found

    for (left = 0;left<=right;left++)
    {
        //Now check if key at left position
        if (key == arr[left])
        {
            pos = left;
            cout << "Key found at position " << pos << " in " << left + 1 << "iteration";

            break;
        }
        //Check if key at right position 
        if(key == arr[right]){
            pos = right;
            cout << "Key found at position " << pos << " in " << right + 1 << " iteration";

            break;
        }

        left++;
        right--;
    }
}

int main(){
    int n;
    cin >> n;
    int key;
    cin >> key;

    vector<int> v;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }

    linearSearch(v, key);
}