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
