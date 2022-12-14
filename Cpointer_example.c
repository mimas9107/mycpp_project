#include <stdio.h>

int main()
{
	//C語言之指標的簡單用法
	/* 定義指定: 型別 *指標名；
	例如：
	int *pi;
	char *pc;
	double *pd; */
	char n = 'A';//定義一個字元a
	char *pn=&n;//pn指標獲取變數n所在的記憶體地址（把變數a佔用的記憶體地址，儲存到指標*pn）
	//*pn = 61; //也可以直接修改指標的值，那麼
	//printf("%c",n);那麼 變數n的值也隨之修改了。
	printf("n=%c\n n's address=%d\n pn=%d\n pn's address=%d\n get pointer pn's value in memory:%c",n,&n,pn,&pn,*pn);
	//n：的值，
	//&n：表示獲取n所在記憶體的地址
	//pn：直接輸出pn的值。(因為前面*pn=&n，所以pn輸入的是n變數所在記憶體的值)
	//&pn：指標變數pn自己所在記憶體的值。
	//*pn：獲取指標pn儲存，所指向的值。
	return 0;
}