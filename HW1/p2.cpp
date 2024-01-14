/*----------------------------------------------------------------
Copyleft (c) 2023 Author: Jagadeesh Vasudevamurthy
file: p2.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has p2 class definition
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
YOU CANNOT INCLUDE ANY OTHER FILES
-----------------------------------------------------------------*/
#include "p2.h"

/*----------------------------------------------------------------
WRITE CODE BELOW
-----------------------------------------------------------------*/
/*
 * author：xiaoyang chen
 * time：2023/9/12 17:53
 * edited by :clion
 */

 int p2::d1(int n, char c) {
    printf("-------------------- n = %d\n", n);
    int cnt = n * 2 - 1;
    for (int i = 0; cnt > 0; i++) {
        if (i == 10) i = 0;
        printf("%d", i);
        cnt--;
    }
    cnt=0;
    printf("\n");
    for (int i = 1; i <= n; i++)
    {
        for(int j=n-i;j>0;j--)
            printf(" ");
        for(int k=0;k<i;k++)
            printf("%c ",c);
        cnt+=i;
        printf("\n");
    }
    printf("N = %d Number of %c = %d",n,c,cnt);
    return cnt;
}

int p2::d2(int n, char c) {
    printf("-------------------- n = %d\n", n);
    int cnt = n * 2 - 1;
    for (int i = 0; cnt > 0; i++) {
        if (i == 10) i = 0;
        printf("%d", i);
        cnt--;
    }
    cnt=0;
    printf("\n");
    for (int i = n; i >0; i--)
    {
        for(int j=n-i;j>0;j--)
            printf(" ");
        for(int k=0;k<i;k++)
            printf("%c ",c);
        cnt+=i;
        printf("\n");
    }
    printf("N = %d Number of %c = %d",n,c,cnt);
    return cnt;
}

int p2::d3(int n, char c) {
    printf("-------------------- n = %d\n", n);
    int cnt = n,now=n;
    for (int i = 0; cnt > 0; i++) {
        if (i == 10) i = 0;
        printf("%d", i);
        cnt--;
    }
    printf("\n");
    cnt=0;
    n=(n-1)/2;
    for(int i=0;i<n;i++)
        printf(" ");
    printf("%c\n",c);
    cnt++;
    if(n==0){
        printf("N = %d Number of %c = %d",now,c,cnt);
        return cnt;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
            printf(" ");
        printf("%c",c);
        for(int j=0;j<2*i+1;j++)
            printf(" ");
        printf("%c\n",c);
        cnt+=2;
    }
    for(int i=n-2;i>=0;i--)
    {
        for(int j=0;j<n-i-1;j++)
            printf(" ");
        printf("%c",c);
        for(int j=0;j<2*i+1;j++)
            printf(" ");
        printf("%c\n",c);
        cnt+=2;
    }
    for(int i=0;i<n;i++)
        printf(" ");
    printf("%c\n",c);
    cnt++;
    printf("N = %d Number of %c = %d",now,c,cnt);
    return cnt;
}

int p2::d4(int n, char c) {
    printf("-------------------- n = %d\n", n);
    int cnt = n;
    for (int i = 0; cnt > 0; i++) {
        if (i == 10) i = 0;
        printf("%d", i);
        cnt--;
    }
    printf("\n");
    cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++)
            printf("%c",c);
        cnt+=i;
        printf("\n");
    }
    for(int i=n-1;i>0;i--){
        for(int j=i;j>0;j--)
            printf("%c",c);
        cnt+=i;
        printf("\n");
    }
    printf("N = %d Number of %c = %d",n,c,cnt);
    return cnt;
}

int p2::d5(int n, char c) {
    printf("-------------------- n = %d\n", n);
    int cnt = n;
    for (int i = 0; cnt > 0; i++) {
        if (i == 10) i = 0;
        printf("%d", i);
        cnt--;
    }
    printf("\n");
    cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=n-i;j>0;j--)
            printf(" ");
        for(int j=1;j<=i;j++)
            printf("%c",c);
        cnt+=i;
        printf("\n");
    }
    for(int i=n-1;i>0;i--){
        for(int j=n-i;j>0;j--)
            printf(" ");
        for(int j=i;j>0;j--)
            printf("%c",c);
        cnt+=i;
        printf("\n");
    }
    printf("N = %d Number of %c = %d",n,c,cnt);
    return cnt;
}

int p2::d6(int n, char c) {
    printf("-------------------- n = %d\n", n);
    int cnt = n * 2 - 1;
    for (int i = 0; cnt > 0; i++) {
        if (i == 10) i = 0;
        printf("%d", i);
        cnt--;
    }
    cnt=0;
    printf("\n");
    for (int i = n; i >0; i--)
    {
        for(int j=n-i;j>0;j--)
            printf(" ");
        for(int k=0;k<i;k++)
            printf("%c ",c);
        cnt+=i;
        printf("\n");
    }
    for (int i = 1; i <= n; i++)
    {
        for(int j=n-i;j>0;j--)
            printf(" ");
        for(int k=0;k<i;k++)
            printf("%c ",c);
        cnt+=i;
        printf("\n");
    }
    printf("N = %d Number of %c = %d",n,c,cnt);
    return cnt;
}


