#include<stdio.h>

struct student
{
	char name[20];
	int age;
	int id;
}stu;

int main(int argc,char *argv[])
{
	struct student  buf_stu[2];
	struct student  bufr_stu[2];
	int i;
	FILE *fp;
	fp = fopen("in.txt","w+");

	if(NULL == fp)
	{
		printf("fopen failed\n");
	}
	for(i = 0;i<2;i++)
	{
		printf("please input the name of the student\n");
		scanf("%s",buf_stu[i].name);
		printf("please input the age of the student\n");
		scanf("%d",&buf_stu[i].age);
		printf("please input the id of the student");
		scanf("%d",&buf_stu[i].id);
	}

	for(i = 0;i<2;i++)
	{
		fwrite(&buf_stu[i],sizeof(struct student),1,fp);
	}

	rewind(fp);

	for(i =0; i<2;i++)
	{
		fread(&bufr_stu[i],sizeof(struct student),1,fp);
		printf("name = %s\n",bufr_stu[i].name);
		printf("name = %d\n",bufr_stu[i].age);
		printf("name = %d\n",bufr_stu[i].id);
	}

	return 0;
}
