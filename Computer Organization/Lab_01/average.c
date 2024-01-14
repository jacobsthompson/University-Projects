#include <stdio.h>

int main(){
	int input;
	int totalnum = 1;
	int evennum = 0;
	double avg_even = 0;
	int oddnum = 0;
	double avg_odd = 0;

	while(input != 0){
		if(totalnum == 1){
			printf("Enter the 1st number: ");
		} else if(totalnum == 2){
			printf("Enter the 2nd number: ");
		} else if(totalnum == 3){
			printf("Enter the 3rd number: ");
		} else {
			printf("Enter the %dth number: ",totalnum);
		}
		scanf("%d",&input);
		if(input == 0){ break; }
		totalnum++;
		if(input % 2 == 0){
			evennum++;
			avg_even += input;
		} else {
			oddnum++;
			avg_odd += input;
		}

	}

	if(evennum > 0){
	avg_even = avg_even / evennum;
	}

	if(oddnum > 0){
	avg_odd = avg_odd / oddnum;
	}

	printf("Average of inputs whose digits sum up to an even number: %lf\n", avg_even);
	printf("Average of inputs whose digits sum up to an odd number: %lf\n", avg_odd);

	return 0;

}