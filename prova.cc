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

int main(){
	int n;
	while (cin >> n){
		int r = 0;
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
		for (int i = 0; i < n; ++i){
			int f = output[input[i]];
			//cout << "f: " << f << endl;
			int pos = busca_pos_dicotomic(resultats, f, 0, n-1);
			/*for (int i = 0; i < n; ++i){
				cout << resultats[i] << ' ';
			}*/
			//cout << "pos: " << pos << endl;
			resultats[pos] = f;
			if (pos+1 > r) r = pos+1;
		}
		/*for (int i = 0; i < n; ++i){
			cout << resultats[i] << ' ';
		}
		cout << endl;*/
		cout << r << endl;
	}
}
		
