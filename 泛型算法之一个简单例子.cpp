#include<algorithm>
#include<vector>

bool Have_Elem(const vector<int> &vec,int search_value)
{
	int max_value = max_element(vec.begin(),vec.end());
	if(max_value < search_value){
		cout <<"No enough elements"<<endl;
		return false;
	}
	vector<int> temp(vec.size());
	copy(vec.begin(),vec.end(),temp.begin());

	sort(temp.begin(),temp.end());
	return binary_search(temp.begin(),temp.end(),search_value);
}
