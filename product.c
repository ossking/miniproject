#include <stdio.h>
#include <string.h>
#include "product.h"
int addP(Product *p){
	getchar();
	printf("name? ");
	fgets(p->name,100,stdin);
	p->name[strlen(p->name)-1]='\0';
	printf("description? ");
	fgets(p->des,100,stdin);
	p->des[strlen(p->des)-1]='\0';
	printf("weight? ");
	fgets(p->w,100,stdin);
	p->w[strlen(p->w)-1]='\0';
	printf("price? ");
	scanf("%d",&p->price);
	printf("delivery? ");
	scanf("%d",&p->hd);
	printf("ADDED!\n");
	return 1;
}
void readP(Product p,int no){
	printf("%d %s %s %s %d %d\n",no+1,p.name,p.des,p.w,p.price,p.hd);
}
int updateP(Product *p){
	getchar();
	printf("new name? ");
	fgets(p->name,100,stdin);
	p->name[strlen(p->name)-1]='\0';
	printf("new description? ");
	fgets(p->des,100,stdin);
	p->des[strlen(p->des)-1]='\0';
	printf("new weight? ");
	fgets(p->w,100,stdin);
	p->w[strlen(p->w)-1]='\0';
	printf("new price? ");
	scanf("%d",&p->price);
	printf("new delivery? ");
	scanf("%d",&p->hd);
	printf("UPDATED!\n");
	return 1;
}
int deleteP(Product *p){
	p->price=-1;
	printf("DELETED!\n");
	return 1;
}
int selectmenu(){
	int menu;
	printf("\n##Shop Products##\n");
	printf("1. LIST\n");
	printf("2. ADD\n");
	printf("3. UPDATE\n");
	printf("4. DELETE\n");
	printf("5. SAVE\n");
	printf("6. SEARCH NAME\n");
	printf("7. SEARCH PRICE\n");
	printf("8. SEARCH DELIVERY\n");
	printf("0. END\n\n");
	printf("=> Which Menu? ");
	scanf("%d",&menu);
	return menu;
}
