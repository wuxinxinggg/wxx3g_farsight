#include <stdio.h>
/*
如下图示：
24+---------------+
  |   |   |   |   |  
20|---------------|
  |   |   |   |   |  
16+---------------|
  |   |   |   |   |  
12|---------------+
  |pig| * |fox|   |  
8 |---------------+
  |cat| * | * | * |  
4 |---------------+
  |dog| 0 | 0 | 0 |  
0 +---------------+

所以struct animals的存储空间大小为：11个字节

*/
struct animals{
	char dog;
	unsigned long cat;
	unsigned short pig;
	char fox;
};
int main(void)
{
	printf("sizeof animals=%d\n",sizeof(struct animals));	
}
