#include <stdio.h>

int main(){
	int numberoftimes;
	int numbertiltypo;

	printf("Enter the number of repetitions for the punishment phrase: ");
	scanf("%d", &numberoftimes);
	while(numberoftimes <= 0){
		printf("You entered an invalid value for the number of repetitions!\n");
		printf("Enter the number of repetitions for the punishment phrase: ");
		scanf("%d", &numberoftimes);
	}
	printf("\n");
	printf("Enter the line where you wish to introduce the typo: ");
	scanf("%d", &numbertiltypo);
	while(numbertiltypo <= 0 || numbertiltypo > numberoftimes){
		printf("You entered an invalid value for the typo placement!\n");
		printf("Enter the line where you wish to introduce the typo: ");
		scanf("%d", &numbertiltypo);
	}
	printf("\n");

	for(int i = 0; i < numberoftimes; i++){
		if(i == numbertiltypo-1){
			printf("Cading in C is fun end intreseting!\n");
		} else {
			printf("Coding in C is fun and interesting!\n");
		}
	}

	return 0;


}