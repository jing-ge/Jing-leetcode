// 765. Couples Holding Hands
// N couples sit in 2N seats arranged in a row and want to hold hands. We want to know the minimum number of swaps so that every couple is sitting side by side. A swap consists of choosing any two people, then they stand up and switch seats.

// The people and seats are represented by an integer from 0 to 2N-1, the couples are numbered in order, the first couple being (0, 1), the second couple being (2, 3), and so on with the last couple being (2N-2, 2N-1).

// The couples' initial seating is given by row[i] being the value of the person who is initially sitting in the i-th seat.

// Example 1:

// Input: row = [0, 2, 1, 3]
// Output: 1
// Explanation: We only need to swap the second (row[1]) and third (row[2]) person.
// Example 2:

// Input: row = [3, 2, 0, 1]
// Output: 0
// Explanation: All couples are already seated side by side.
// Note:

// len(row) is even and in the range of [4, 60].
// row is guaranteed to be a permutation of 0...len(row)-1.
// 通过次数21,255提交次数31,957

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class UnionFind{
public:
	vector<int> parent;
	vector<int> size;
	int n;
	UnionFind(int _n){
		n = _n;
		for(int i=0;i<_n;i++){
			parent.push_back(i);
			size.push_back(1);
		}
	}
	int root(int x){
		while(parent[x]!=x){
			parent[x] = parent[parent[x]];
			x = parent[x];
		}
		return x;
	}
	bool merge(int i,int j){
		i = root(i);
		j = root(j);
		if(i==j)return false;
		if(size[i]>size[j]){
			parent[j] = i;
			size[i] += size[j];
		}else{
			parent[i] = j;
			size[j] += size[i];
		}
		n--;
		return true;
	}
};


class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
    	UnionFind uf(row.size()/2);
    	for(int i=0;i<row.size()/2;i++){
    		int x = row[2*i];
    		int y = row[2*i+1];
    		uf.merge(x/2,y/2);
    	}
    	set<int> ss;
    	int res = 0;
    	for(int i=0;i<row.size()/2;i++){
    		int t = uf.root(i);
    		if(ss.count(t))continue;
    		res +=  uf.size[t]-1;
    		ss.insert(t);
    	}
    	return res;
    }
};

int main(){
	Solution s;
	vector<int> row = {3,2,0,1};
	int res = s.minSwapsCouples(row);
	cout<<res<<endl;
	return 0;
}