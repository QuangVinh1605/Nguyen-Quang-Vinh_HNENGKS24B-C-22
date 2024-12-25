#include<stdio.h>
typedef struct{
	char ID[20];
	char name[50];
	int age; 
}Student;
void loadStudent(Student student[],int *n);
void saveStudent(Student student[],int *n); 
void printfStudent(Student student[],int *n); 
void addStudent(Student student[],int n);
void fixStudent(Student student[],int n);
void deleteStudent(Student student[],int *n);
void searchStudent(Student student[],int n);
void sortStudent(Student student[], int n);
int main(){
	Student student[100];
	int choice;
	int n;
	loadStudent(student,&n); 
	
	do{
		printf("**********MENU**********\n");
		printf("1.In danh sach sinh vien \n");
		printf("2.them sinh vien\n");
		printf("3.sua thong tin sinh vien\n");
		printf("4.xao sinh vien\n");
		printf("5.tiem kiem sinh vien\n");
		printf("6.sap xep danh sach sinh vien\n");
		printf("7.thoat\n");
		printf("moi ban nhap vao lua chon cua minh: \n");
		switch(choice){
			case 1:{
				printfStudent(student,&n);
				
				break;
			}
			case 2:{
				addStudent(student,n); 
				saveStudent(student,&n);
				
				break;
			} 
			case 3:{
				fixStudent(student,n);
				saveStudent(student,&n);
				
				break;
			}
			case 4:{
				deleteStudent(student,&n);
				saveStudent(student,&n);
				
				break;
			}
			case 5:{
				searchStudent(student,n);
				saveStudent(student,&n);
				
				break;
			}
			case 6:{
				sortStudent(student,n);
				saveStudent(student,&n);
				
				break;
			}
			case 7:{
				printf("da thoat khoi chuong trinh.");
				
				break;
			}
			default:{
				printf("lua chon khong hop le vui long chon lai \n");
				break;
			}
		} 
		 
	} while(choice!=7);
} 
void loadStudent(Student student[],int *n){
	FILE *file=fopen("student01.dat","rb");
	if(file==NULL){
	printf("khong the mo file \n");
	*n=0;
	return; 
}
	fread(&n,sizeof(int),1,file);
    fread(student,sizeof(Student),*n,file); 
fclose(file);
printf("da lay thong tin sach tu file thanh cong\n");

}
void saveStudent(Student student[],int *n){
FILE *file=fopen("student01.dat","wb");
if(file==NULL){
	printf("khong the mo file \n");
	return; 
}
fwrite(&n,sizeof(int),1,file);
fwrite(student,sizeof(Student),n,file); 
fclose(file);
printf("da luu thong tin file thanh cong\n"); 

	
}
void printfStudent(Student student[],int *n){
	if(n=0){
		printf("danh sach sinh vien trong \n");
		return;
	}
	for(int i=0;i<n;i++){
		printf("thong tin sinh vien thu %d\n",i+1);
		printf("ma sinh vien:%s\n",student[i].ID);
		printf("ten sinh vien:%s\n",student[i].name);
		printf("tuoi sinh vien:%s\n",student[i].age);
	}
	
} 
void addStudent(Student student[],int n){
	printf("moi ban nhap so sinh vien ma ban muon them vao danh sach: ");
	scanf("%d",&n);
	getchar();
	for(int i=0;i<n;i++){
		printf("moi ban nhap thong tin sinh vien thu %d ",i+1);
		printf("id sinh vien: " );
		fgets(student[i].ID,sizeof(student[i].ID),stdin);
		student[i].ID[strcspn(student[i].ID,"\n")]='\0';
		printf("ten sinh vien: ");
		fgets(student[i].name,sizeof(student[i].name),stdin);
		student[i].name[strcspn(student[i].name,"\n")]='\0';
		printf("tuoi sinh vien: ");
		scanf("%d",&student[i].age);
		getchar();
	}
	printf("da them sinh vien thanh cong \n");
}
void fixStudent(Student student[],int n){
	char id;
	printf("moi ban nhap id sinh vien ma ban muon sua thong tin: ");
	fgets(student[id].ID,sizeof(student[id].ID),stdin);
	student[id].ID[strcspn(student[id].ID,"\n")]='\0';
	for(int i=0;i<n;i++){
		if(id==student[i].ID){
	printf("moi ban nhap lai thong tin sinh vien id:%s",student[id].ID);
	printf("ten sinh vien: ");
	fgets(student[id].name,sizeof(student[id].name),stdin);
	student[id].name[strcspn(student[id].name,"\n")]='\0';
	printf("tuoi sinh vien: ");
	scanf("%d",&student[id].age);
	getchar();
	
	
	
}
}
printf("da cap nhat thong tinh sinh vien thanh cong\n");
}
void deleteStudent(Student student[],int *n){
	char id;
	printf("moi ban nhap id sinh vien ma ban muon xoa ra khoi danh sach: ");
	fgets(student[id].ID,sizeof(student[id].ID),stdin);
	student[id].ID[strcspn(student[id].ID,"\n")]='\0';
	for(int i=0;i<n;i++){
		if(student[i].ID==id){
			for(int j=0;j<n;j++){
				student[j]=student[j+1];
			}
			(*n)--;
			printf("da xoa sinh vien ra khoi danh sach");
			return;
			
		}
	}
	printf("khong tim thay sinh vien co ID %d trong danh sach",student[id].ID);
	
}
void searchStudent(Student student[],int n){
	char id;
	printf("moi ban nhap id sinh vien ma ban muon tim kiem: ");
	fgets(student[id].ID,sizeof(student[id].ID),stdin);
	student[id].ID[strcspn(student[id].ID,"\n")]='\0';
	for(int i=0;i<n;i++){
		if(student[i].ID==id){
			printf("thong tin sinh vien co ID %c",student[i].ID);
			printf("ten sinh vien:%s\n",student[i].name);
	    	printf("tuoi sinh vien:%s\n",student[i].age);
	    	return;
			
		}
	}
	printf("khong tim thay sinh vien trong danh sach");
	
}

void sortStudent(Student student[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (student[i].ID > student[j].ID) {
                Student temp = student[i];
                student[i] = student[j];
                student[j] = temp;
            }
        }
    }

    printf("da sap xep sinh vien theo ID.\n");
}

