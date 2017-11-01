#include <bits/stdc++.h>
using namespace std;

void f (const vector<int>& l, vector<int>& c, vector<list<int> >& r, int M){
	int cmin, e, nmin;
	for (int n = 1; n < int(l.size()); ++n){
		for (int i = n; i > 0; --i){
			if (i == n){
				if (n < int(l.size())-1){
					e = M-l[i];
					cmin = c[i-1] + (e*e);
					nmin = i-1;
				}
				else {
					e = M-l[i];
					cmin = c[i-1];
					nmin = i-1;
				}
			}
			
			else{
				e -= 1 + l[i];
				if (e >= 0 and n < int(l.size())-1 and cmin > c[i-1] + e*e) {
					cmin = c[i-1] + e*e;
					nmin = i-1;
				}
				else if (e >= 0 and n == int(l.size())-1 and cmin > c[i-1]) {
					cmin = c[i-1];
					nmin = i-1;
				}
			}
		}
		c[n] = cmin;
		for (int i = nmin+1; i <= n; ++i){
			r[n].push_back(i);
		}
	}

}

int main(){
	string s;
	list<string> ll;
	int n = 0;
	cout << "numero de paraules: ";
	int t; cin >> t;
	cout << "text: ";
	while(t--){
		cin >> s;
		ll.push_back(s);
		++n;
	}
	cout << "numero maxim de paraules per lines: ";
	int M;
	cin >> M;
	vector<string> paraules(n+1);
	vector<int> l (n+1);
	int i = 1;
	for (auto it = ll.begin(); it != ll.end(); ++it){
		paraules[i] = *it;
		l[i] = it->size();
		++i;
	}

	vector<list<int> > r (n+1);
	vector<int> c (n+1);
	c[0] = 0;
	f (l, c, r, M);

	i = n;

	list<list<int> > res;

	while (i > 0){
		res.push_front(r[i]);
		i = *r[i].begin() -1 ;
	}

	for (auto it = res.begin(); it != res.end(); ++it) { // la suma dels dos fors == nº de paraules.
		for (auto it2 = it->begin(); it2 != it->end(); ++it2) {
			cout << paraules[*it2] << ' ';
		}
		cout << endl;
	}

	cin >> n;

}