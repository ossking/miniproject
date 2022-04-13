#include <stdio.h>
#include <string.h>
#include "manager.h"

int loadD(Product *p){
#ifdef DEBUG
	printf("DEBUG--Loading textfile\n");
#endif
	int i=0;
	FILE *fp;
	fp=fopen("product.txt","rt");
	if(fp==NULL){
		printf("No File\n");
		return 0;
	}
	while(1){
		fscanf(fp,"%d %d",&p[i].hd,&p[i].price);
		fgets(p[i].name,100,fp);
		p[i].name[strlen(p[i].name)-1]='\0';
		fgets(p[i].w,100,fp);
		p[i].w[strlen(p[i].w)-1]='\0';
		fgets(p[i].des,100,fp);
		p[i].des[strlen(p[i].des)-1]='\0';
		if(feof(fp)) break;
		i++;
	}
	fclose(fp);
	printf("Load Success\n");
	return i;
}
void saveD(Product *p,int index){
#ifdef DEBUG
	printf("DEBUG--Saving changes to textfile\n");
#endif
	FILE *fp;
	fp=fopen("product.txt","wt");
	for(int i=0;i<index;i++){
		if(p[i].price==-1) continue;
		fprintf(fp,"%d %d%s\n%s\n%s\n",p[i].hd,p[i].price,p[i].name,p[i].w,p[i].des);
	}
	fclose(fp);
}
void findname(Product *p,int index){
	int q=0;
	char find[100];
	printf("name? ");
	scanf("%s",find);
	printf("\nNo name des weight price delivery\n");
	printf("=================================\n");
	for(int i=0;i<index;i++){
		if(p[i].price==-1) continue;
		if(strstr(p[i].name,find)){
			readP(p[i],i);
			q++;
		}
	}
	if(q==0) printf("no search\n\n");
}

void findprice(Product *p,int index){
	int q=0;
	int num1,num2;
	printf("lowest price? ");
	scanf("%d",&num1);
	printf("highest price? ");
	scanf("%d",&num2);
	printf("\nNo name des weight price delivery\n");
	printf("=================================\n");
	for(int i=0;i<index;i++){
		if(p[i].price==-1) continue;
		if(p[i].price>=num1&&p[i].price<=num2){
			readP(p[i],i);
			q++;
		}
	}
	if(q==0) printf("no search\n\n");
}
void findhd(Product *p,int index){
	int q=0;
	int d;
	printf("delivery? ");
	scanf("%d",&d);
	printf("\nNo name des weight price delivery\n");
	printf("=================================\n");
	for(int i=0;i<index;i++){
		if(p[i].price==-1) continue;
		if(p[i].hd==d){
			readP(p[i],i);
			q++;
		}
	}
	if(q==0) printf("no search\n\n");
}
void listP(Product *p,int count){
#ifdef DEBUG
	printf("DEBUG--Loading List\n");
#endif
	printf("\nNo name des weight price delivery\n");
	printf("=================================\n");
	for(int i=0;i<count;i++){
		if(p[i].price==-1) continue;
		readP(p[i],i);
	}
	printf("\n");
}
int selectDataNo(Product *p,int count){
	int no;
	listP(p,count);
	printf("Which no(cancel:0)? ");
	scanf("%d",&no);
	return no;
}
