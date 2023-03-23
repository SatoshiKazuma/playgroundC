#include<stdio.h>
#include<math.h>
void tower( int n, char s, char t, char d){
	if(n==0){
		return;
	}
	tower(n-1, s, d, t);
	printf("\nMove disk %d from %c to %c", n, s, d);
	tower(n-1, t, s, d);
}
void main(){
	printf("disks: ");
	int n;
	scanf("%d",&n);
	tower(n, 'A', 'B', 'C');
	printf("\nnumber of moves = %d", (int)pow(2,n)-1);
}
