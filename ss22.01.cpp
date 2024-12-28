#include <stdio.h>
#include <string.h>

typedef struct {
    char ID[20];
    char name[50];
    int age;
} Student;

void loadStudent(Student student[], int *n);
void saveStudent(Student student[], int n);
void printfStudent(Student student[], int n);
void addStudent(Student student[], int *n);
void fixStudent(Student student[], int n);
void deleteStudent(Student student[], int *n);
void searchStudent(Student student[], int n);
void sortStudent(Student student[], int n);

int main() {
    Student student[100];
    int choice;
    int n = 0;

    loadStudent(student, &n);

    do {
        printf("\n********** menu **********\n");
        printf("1. in danh sach sinh vien\n");
        printf("2. them sinh vien\n");
        printf("3. sua thong tin sinh vien\n");
        printf("4. xoa sinh vien\n");
        printf("5. tim kiem sinh vien\n");
        printf("6. sap xep danh sach sinh vien\n");
        printf("7. thoat\n");
        printf("moi ban nhap lua chon: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printfStudent(student, n);
                break;
            case 2:
                addStudent(student, &n);
                saveStudent(student, n);
                break;
            case 3:
                fixStudent(student, n);
                saveStudent(student, n);
                break;
            case 4:
                deleteStudent(student, &n);
                saveStudent(student, n);
                break;
            case 5:
                searchStudent(student, n);
                break;
            case 6:
                sortStudent(student, n);
                saveStudent(student, n);
                break;
            case 7:
                break;
            default:
                printf("lua chon khong hop le\n");
        }
    } while (choice != 7);

    return 0;
}

void loadStudent(Student student[], int *n) {
    FILE *file = fopen("student01.dat", "rb");
    if (file == NULL) {
        *n = 0;
        return;
    }
    fread(n, sizeof(int), 1, file);
    fread(student, sizeof(Student), *n, file);
    fclose(file);
}

void saveStudent(Student student[], int n) {
    FILE *file = fopen("student01.dat", "wb");
    if (file == NULL) {
        return;
    }
    fwrite(&n, sizeof(int), 1, file);
    fwrite(student, sizeof(Student), n, file);
    fclose(file);
}

void printfStudent(Student student[], int n) {
    if (n == 0) {
        printf("danh sach sinh vien trong\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        printf("\nthong tin sinh vien thu %d\n", i + 1);
        printf("id: %s\n", student[i].ID);
        printf("ten: %s\n", student[i].name);
        printf("tuoi: %d\n", student[i].age);
    }
}

void addStudent(Student student[], int *n) {
    int count;
    printf("nhap so luong sinh vien: ");
    scanf("%d", &count);
    getchar();
    for (int i = 0; i < count; i++) {
        printf("nhap thong tin sinh vien thu %d\n", *n + 1);
        printf("id: ");
        fgets(student[*n].ID, sizeof(student[*n].ID), stdin);
        student[*n].ID[strcspn(student[*n].ID, "\n")] = '\0';
        printf("ten: ");
        fgets(student[*n].name, sizeof(student[*n].name), stdin);
        student[*n].name[strcspn(student[*n].name, "\n")] = '\0';
        printf("tuoi: ");
        scanf("%d", &student[*n].age);
        getchar();
        (*n)++;
    }
}

void fixStudent(Student student[], int n) {
    char id[20];
    printf("nhap id sinh vien: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';

    for (int i = 0; i < n; i++) {
        if (strcmp(student[i].ID, id) == 0) {
            printf("nhap thong tin moi:\n");
            printf("ten: ");
            fgets(student[i].name, sizeof(student[i].name), stdin);
            student[i].name[strcspn(student[i].name, "\n")] = '\0';
            printf("tuoi: ");
            scanf("%d", &student[i].age);
            getchar();
            return;
        }
    }
}

void deleteStudent(Student student[], int *n) {
    char id[20];
    printf("nhap id sinh vien: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';

    for (int i = 0; i < *n; i++) {
        if (strcmp(student[i].ID, id) == 0) {
            for (int j = i; j < *n - 1; j++) {
                student[j] = student[j + 1];
            }
            (*n)--;
            return;
        }
    }
}

void searchStudent(Student student[], int n) {
    char id[20];
    printf("nhap id sinh vien: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = '\0';

    for (int i = 0; i < n; i++) {
        if (strcmp(student[i].ID, id) == 0) {
            printf("thong tin sinh vien:\n");
            printf("id: %s\n", student[i].ID);
            printf("ten: %s\n", student[i].name);
            printf("tuoi: %d\n", student[i].age);
            return;
        }
    }
}

void sortStudent(Student student[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(student[i].ID, student[j].ID) > 0) {
                Student temp = student[i];
                student[i] = student[j];
                student[j] = temp;
            }
        }
    }
}

