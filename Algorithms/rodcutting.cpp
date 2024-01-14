#include <iostream>
#include <cstdlib>

using namespace std;

int rodcount;										//this will store how many rods were used in the optimal cut

int rodCutting(int p[], int rods[], int n){			//bottom up cut rod
	int r[n+1];										//results of subproblems
	int usedrods[n+1];								//keeps track of rod lengths used
	r[0] = 0;										//rod len of 0 makes no money

	for(int i = 1; i <= n; i++){					//loop through all prices except for r[0]
		int q = -1;									//set q to -1 = -infinity in this case because there are no negative prices or pieces
		int optimalrod = -1;						//set optimalrod to -1, this will keep track of optimal cuts
		for(int j = 0; j < i; j++){					//I DIDN'T USE A MAX() FUNCTION HERE BECAUSE OPTIMAL ROD SHOULD ONLY BE UPDATED IF Q IS SMALLER, SO IF STATEMENT WAS NEEDED
			if(q < p[j] + r[i-j-1]){				//finds if q is the max or not. if q is bigger, q stays as q. if not,
				q = p[j] + r[i-j-1];				//q becomes the price[j] plus the last entry
				optimalrod = j;						//we set our optimalrod to whatever j is to remember where we made the optimal cut
			}
		}
		r[i] = q;									//set our r entry as the solution to our subproblem
		usedrods[i] = optimalrod + 1;				//set our usedrods entry as the cut that reached the solution
	}

	int j = 0;										//loop through our usedrods array backwards, to trace back each optimal rod cut until we hit zero
	for(int i = n; i > 0; i -= usedrods[i]){		//we use i -= usedrods[i] to skip other values that do not match our final optimal result
		rods[j++] = usedrods[i];					//set our rods array to what usedrods is at each i, with rods indexing up by 1
	}

	rodcount = j;									//set our global variable rodcount to j, so we know how many pieces are in rods[]
	return r[n];									//return the optimal price
}

int main() {
	int n = 0;										//declare how many prices&pieces there will be
	cin >> n;										//take in n
	int p[n];										//make prices array
	for(int i = 0; i < n; i++){						//fill in prices array
		cin >> p[i];
	}
	int rods[n+1];									//create rod array, that will tell us which rods were used, with a size of n+1 so it could hold the max amount of rods

	cout << rodCutting(p,rods,n) << endl;			//do our rod cutting and print the result
	for(int i = 0; i < rodcount; i++){				//print out our rod lengths based on our rodcount variable
		cout << rods[i] << ' ';
	}
	cout << -1 << endl;								//print -1 at the end

  return 0;
}