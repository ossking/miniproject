#include <stdio.h>
#include <string.h>
#include "manager.h"

int main(){
	int count=0,menu;
	Product plist[20];
	int index;

	count=loadD(plist);
	index=count;

	while(1){
		menu=selectmenu();
		if(menu==0) break;
		if(menu==1||menu==3||menu==4||menu==6||menu==7||menu==8){
			if(count==0){
				printf("No Data\n");
				continue;
			}
		}
		if(menu==1) listP(plist,index);
		else if(menu==2){
			if(addP(&plist[index])){
				count++;
				index++;
			}
		}
		else if(menu==3){
			int no=selectDataNo(plist,index);
			if(no==0){
				printf("Canceled\n");
				continue;
			}
			updateP(&plist[no-1]);
		}
		else if(menu==4){
			int no=selectDataNo(plist,index);
			if(no==0){
				printf("Canceled\n");
				continue;
			}
			int deleteok;
			printf("Delete for real(yes:1)? ");
			scanf("%d",&deleteok);
			if(deleteok==1){
				if(deleteP(&plist[no-1])) count--;
			}
		}
		else if(menu==5){
			saveD(plist,index);
			printf("SAVED!\n");
		}
		else if(menu==6) findname(plist,index);
		else if(menu==7) findprice(plist,index);
		else if(menu==8) findhd(plist,index);
	}
	printf("ENDED!\n");
	return 0;
}




int loadD(Product *p){
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
void listP(Product *p,int count){
	printf("\nNo name des weight price delivery\n");
	printf("=================================\n");
	for(int i=0;i<count;i++){
		if(p[i].price==-1) continue;
		readP(p[i],i);
	}
	printf("\n");
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
int selectDataNo(Product *p,int count){
	int no;
	listP(p,count);
	printf("Which no(cancel:0)? ");
	scanf("%d",&no);
	return no;
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
