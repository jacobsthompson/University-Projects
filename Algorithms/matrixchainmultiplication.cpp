#include <iostream>
#include <cstdlib>
using namespace std;

void printOptimalParents(int* s, int i, int j, int n){					//For Printing, we take in an array, the starting and ending pos, and the length of array
	if(i==j){															//Check if start = end
		cout << "A" << i-1;												//If so, Print The A# corresponding to i-1 (because array starts at 1 but syntax starts at 0)
	} else {															//If not equal, enter recursion
		cout << "(";													//Print open bracket
		printOptimalParents(s,i,*((s + i * n)+j),n);					//run print again but with j as s[i][j]
		printOptimalParents(s,*((s + i * n)+j)+1,j,n);					//run print again but with i as s[i][j] + 1
		cout << ")";													//Print close bracket
	}																	
}																		
																		
void matrixChainOrder(int p[], int n){									//For our calculations, we take in an array and the size of that array
	int m[n][n];														//We make a new 2D array for storing optimal multiplications
	int s[n][n];														//We make a new 2D array for storing positions of those optimal multiplications
																		
	for(int i = 1; i < n; i++){											//Loop through M's diagonal
		m[i][i] = 0;													//Set all of M's diagonal to zero
	}																	

	for(int l = 2; l < n; l++){											//Loop Through Length of Chain
		for(int i = 1; i < n-l+1; i++){									//Will Loop Through M to fill in the rest of M
			int j = i + l - 1;											//Set the M[][*] to 
			m[i][j] = 1000000;											//Set M[i][j] to an INT MAX
			for(int k = i; k < j; k++){								//K will loop through our positions that could be optimal solutions
				int q = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];		//Set Q to as the products of the rows and columns multiplication
				if(q < m[i][j]){										//If Q is less than INT MAX
					m[i][j] = q;										//Set m[i][j] to Q (Our optimal multiplication)
					s[i][j] = k;										//Set s[i][j] to K (Our optimal position)
				}														
			}															
		}																
	}	
	cout << m[1][n-1] << endl;											//Output the most optimal value being M[1][N-1]
	printOptimalParents((int*)s,1,n-1,n);								//Print out our parentheses
	cout << endl;														//New line
}																		
																		
int main() {															
	int matrixcount = 0;												//Set our matrix size
	cin >> matrixcount;													//Input matrix size

	int dimensions[matrixcount+1];										//Make array of our dimensions n+1 size
	for(int i = 0; i < matrixcount+1; i++){								//Input those dimensions into array
		cin >> dimensions[i]; 											//Set them
	}																	

	matrixChainOrder(dimensions,matrixcount+1);							//Run our matrix chain order with our dimensions array and our size + 1

  	return 0;
}