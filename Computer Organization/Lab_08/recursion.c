#include<stdio.h>

int recursion(int m) {
    if(m == -1) {
        printf("Returning 1\n");
        return 1;
    }
    else if(m == 0) {
        printf("Returning 3\n");
        return 3;
    }
    else
        return recursion(m - 2) + recursion(m - 1);
}

int main() {
    int x;
    printf("Please enter an integer: ");
	scanf("%d", &x);
    printf("%d\n", recursion(x));
    return 0;
}

// 5 -> 3 + 4
    // 3 -> 1 + 2
    // 4 -> 2 + 3

        // 1 -> -1 + 0
        //2 -> 0 + 1

        //2 -> 0 + 1
        //3 -> 1 + 2
            
            //-1 -> 1   X
            //0 -> 3    X

            //0 -> 3 X
            //1 -> -1 + 0
                //-1 -> 1  X
                //0 -> 3   X
            
            //0 -> 3 X
            //1 -> -1 + 0
                //-1 -> 1 X
                //0 -> 3  X

            //1 -> -1 + 0
            //2 -> 0 + 1

                //-1 -> 1 X
                //0 -> 3  X

                //0 -> 3 X
                //1 -> -1 + 0
                    //-1 -> 1 X
                    //0 -> 3  X
                