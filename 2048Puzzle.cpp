/*
SAMPLE INPUT
2 2 2 2
4 4 0 4
2 0 0 2
8 0 8 8

after left move
4 4 0 0
8 4 0 0
4 0 0 0
16 8 0 0
*/


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int main ()
{
    int t;//number of test cases
    cin >> t;
    int id=1;
    while (t--){
        int n;//n*n size board
        cin >> n;//scanning n
        char str[10];
        cin >> str;//choice to take move
        int d;
        if (strcmp(str,"left")==0)//if choice is left
            d=1;
        else if (strcmp(str,"right")==0)//if choice is right
            d=2;
        else if (strcmp(str,"up")==0)//if choice is up
            d=3;
        else if (strcmp(str,"down")==0)//if choice is down
            d=4;
        int ** arr = (int **)malloc(n*sizeof(int *)); // the matrix
        int i,j;
        for (i=0;i<n;i++)
            arr[i]=(int *)malloc(n*sizeof(int));
        for (i=0;i<n;i++)
            for (j=0;j<n;j++)
                cin >> arr[i][j];

//when left move
        if (d==1){
            //loop to shift each row one by one
            for (i=0; i<n; i++){
                //loop to remove the interleaving zeros in each row
                for (j=n-2;j>=0;j--){
                    if (arr[i][j]==0){//if zero element found
                        int k;
                        for (k=j;k<n-1;k++){
                            arr[i][k] = arr[i][k+1];
                            arr[i][k+1] = 0;
                        }
                    }
                }
                //loop to add two adjacent values in a row
                for (j=0;j<n-2;j++){
                    if ((arr[i][j+1] == arr[i][j])){
                        arr[i][j+1]=0;
                        arr[i][j]=2*arr[i][j];
                    }
                }
                //to remove the interleaving zeros in each row
                for (j=n-2;j>=0;j--){
                    if (arr[i][j]==0){
                        int k;
                        for (k=j;k<n-1;k++){
                            arr[i][k] = arr[i][k+1];
                            arr[i][k+1] = 0;
                        }
                    }
                }
            }
        }

//right move
        else if (d==2){
            for (i=0; i<n; i++){
                for (j=0;j<n-1;j++){
                    if (arr[i][j+1]==0){
                        int k;
                        for (k=j;k>=0;k--){
                            arr[i][k+1] = arr[i][k];
                            arr[i][k]=0;
                        }
                    }
                }

                for (j=n-2;j>=0;j--){
                    if ((arr[i][j+1] == arr[i][j])){
                        arr[i][j]=0;
                        arr[i][j+1]=2*arr[i][j+1];
                    }
                }
                for (j=0;j<n-1;j++){
                    if (arr[i][j+1]==0){
                        int k;
                        for (k=j;k>=0;k--){
                            arr[i][k+1] = arr[i][k];
                            arr[i][k]=0;
                        }
                    }
                }
            }
        }

//up move
        else if (d==3){
            for (j=0; j<n; j++){
                for (i=n-2;i>=0;i--){
                    if (arr[i][j]==0){
                        int k;
                        for (k=i;k<n-1;k++){
                            arr[k][j] = arr[k+1][j];
                            arr[k+1][j]=0;
                        }
                    }
                }

                for (i=0;i<n-1;i++){
                    if ((arr[i+1][j] == arr[i][j])){
                        arr[i+1][j]=0;
                        arr[i][j]=2*arr[i][j];
                    }
                }
                for (i=n-2;i>=0;i--){
                    if (arr[i][j]==0){
                        int k;
                        for (k=i;k<n-1;k++){
                            arr[k][j] = arr[k+1][j];
                            arr[k+1][j]=0;
                        }
                    }
                }
            }
        }
//down move
        else if (d==4){
            for (j=0; j<n; j++){
                for (i=0;i<n-1;i++){
                    if (arr[i+1][j]==0){
                        int k;
                        for (k=i;k>=0;k--){
                            arr[k+1][j] = arr[k][j];
                            arr[k][j] = 0;
                        }
                    }
                }
                for (i=n-2;i>=0;i--){
                    if ((arr[i+1][j] == arr[i][j])){
                        arr[i][j]=0;
                        arr[i+1][j]=2*arr[i+1][j];
                    }
                }
                for (i=0;i<n-1;i++){
                    if (arr[i+1][j]==0){
                        int k;
                        for (k=i;k>=0;k--){
                            arr[k+1][j] = arr[k][j];
                            arr[k][j] = 0;
                        }
                    }
                }
            }
        }
        //printing output on the screen for the given test case
        cout << "Case #" << id++ << ":" << "\n";
        for (i=0;i<n;i++){
            for (j=0;j<n;j++)
                cout << arr[i][j] << " ";
            cout << "\n";
        }
    }//loop continues until number of test cases counter becomes zero
    return 0;//return from main
}
