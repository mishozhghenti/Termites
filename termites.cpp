#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void fusion(vector<long long> &v) {
	vector<long long> tmpV;

	for (int i = 0; i < v.size(); i++) {
		tmpV.push_back(v[i]);
		int x = tmpV.size() - 2;
		while (x > 0 && tmpV[x] >= tmpV[x - 1] && tmpV[x] >= tmpV[x + 1]) {
			tmpV[x - 1] += tmpV[x + 1] - tmpV[x];
			x -= 2;
			tmpV.pop_back();
			tmpV.pop_back();
		}
	}
	v = tmpV;
}

void worthlessMove(vector<long long> &v, int &power, long long &gameValue) {
	if (v.size() < 2)
		return;

	int count = 0;
	for (int i = 0; i <= v.size() - 2; i += 2) {
		if (v[i] >= v[i + 1]) {
			count += 2;
			gameValue += (-1)*power*(v[i + 1] - v[i]);
		} else
			break;
	}
	for (int i = 0; i < count; i++)
		v.erase(v.begin());
}

int main() {
	vector<vector<long long> > allSequences;
	vector<long long > preSorted;
	long long N = 0, totalSum = 0, gameValue = 0;
	int i = 0, power = 1;
	int n;

	cin >> n;

	while (i < n) {
		vector<long long> current;

		for (; i < n; i++) {
			long long l;
			cin >> l;
			totalSum += l;

			if (l != 0) {
				current.push_back(l);
				if ((n - 1) == i) {
					fusion(current);
					allSequences.push_back(current);
					N += current.size();
				}
			} else {
				if (current.size() != 0) {
					fusion(current);
					allSequences.push_back(current);
					if (i == (n - 1)) {
						vector<long long> tmp;
						allSequences.push_back(tmp);
					}
					N += current.size();
					break;
				}
				vector<long long> tmp;
				allSequences.push_back(tmp);
			}
		}
		i++;
	}

	if (N % 2 == 0)
		power = -1;

	worthlessMove(allSequences[0], power, gameValue);//first part
	reverse(allSequences[allSequences.size() - 1].begin(), allSequences[allSequences.size() - 1].end());
	worthlessMove(allSequences[allSequences.size() - 1], power, gameValue);//last part

	for (i = 0; i < allSequences.size(); i++) {
		if (allSequences[i].size() != 0) {
			for (int j = 0; j < allSequences[i].size(); j++)
				preSorted.push_back(allSequences[i][j]);
		}
	}
	sort(preSorted.begin(), preSorted.end());
	reverse(preSorted.begin(), preSorted.end());


	for (i = 0; i < preSorted.size(); i++) {
		if (i % 2 == 0)
			gameValue += preSorted[i];
		else
			gameValue -= preSorted[i];
	}

	cout << (totalSum + gameValue) / 2 << " " << (totalSum - gameValue) / 2 << endl;
	return 0;
}
