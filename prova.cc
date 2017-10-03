#include <bits/stdc++.h>

using namespace std;

int busca_pos_dicotomic (const vector<int>& resultats, int x, int l, int r){
	int middle = (l+r)/2;
	if (resultats[middle] <= x){
		if ((middle-1 < 0) or (resultats[middle-1] > x)) return middle;
		else return busca_pos_dicotomic(resultats, x, l, middle-1);
	}
	else {
		if (middle+1 < int(resultats.size())) return busca_pos_dicotomic(resultats, x, middle+1, r);
		else return middle+1;
	}
}

int busca_pos_dicotomic2 (const vector<int>& resultats, int x, int l, int r){
	int middle = (l+r)/2;
	if (resultats[middle] >= x){
		if ((middle-1 < 0) or (resultats[middle-1] < x)) return middle;
		else return busca_pos_dicotomic2(resultats, x, l, middle-1);
	}
	else {
		if (middle+1 < int(resultats.size())) return busca_pos_dicotomic2(resultats, x, middle+1, r);
		else return middle+1;
	}
}

int main(){
	int n;
	cin >> n;
	int cas = 1;
	while (n != 0){
		int r = 0,
			r2 = 0;
		vector<int> input (n);
		vector<int> output (n+1);
		for (int i = 0; i < n; ++i){
			cin >> input[i];
		}
		for (int i = 0; i < n; ++i){
			int x;
			cin >> x;
			output[x] = i;
		}
		vector<int> resultats (n, -1);
		vector<int> resultats2 (n, n+1);
		for (int i = 0; i < n; ++i){
			int f = output[input[i]];
			int pos = busca_pos_dicotomic(resultats, f, 0, n-1);
			int pos2 = busca_pos_dicotomic2(resultats2, f, 0, n-1);
			resultats[pos] = f;
			resultats2[pos2] = f;
			if (pos+1 > r) r = pos+1;
			if (pos2+1 > r2) r2 = pos2+1;
		}
		cout << "Case " << cas << ": " << r << ' ' << r2 << endl;
		++cas;
		cin >> n;
	}
}
		

		
