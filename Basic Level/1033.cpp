#include <cstdio>
#include <cstring>
using namespace std;
 
int main() {
	bool hashTable[256];
	memset(hashTable,true,sizeof(hashTable));
	//建议初学者使用memset赋值0或-1
	//memset使用的是按字节赋值，既对每个字节赋相同的值，这样组成的int型的4个
	//字节就会被赋成相同的值，而由于0的二进制补码为全0，-1的二进制补码为全1，不容易弄错
	//如果对数组赋其他数字（如1）请用fill函数，但memset执行更快
	char str[100010];
 
	gets(str);
	int len = strlen(str);
	for(int i=0;i<len;i++){
		if(str[i]>='A'&&str[i]<='Z') str[i]+=32;
		hashTable[str[i]] = false;
	}
 
	gets(str);
	len = strlen(str);
 
	for(int i=0;i<len;i++){
		if(str[i]>='A'&&str[i]<='Z'){
			int lowcase = str[i]+32;
			if(hashTable[lowcase]==true && hashTable['+']==true)
			printf("%c",str[i]);
		}else if(hashTable[str[i]]==true)
		printf("%c",str[i]);
	}
	printf("\n");
	return 0;
}
