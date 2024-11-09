#include <stdio.h>
#include <string.h>

// ����ʳ��ṹ��
typedef struct {
    char name[50];       // ʳ������
    float price;         // ʳ��۸�
    int deliciousness;   // ʳ��óԶȣ�1-5��
    int healthiness;     // ʳ�｡���ȣ�1-5��
    char category[50];   // ʳ�����ͣ�����ʳ����ʳ�ȣ�
} Food;

// ����һ���������洢ʳ����Ϣ
Food foods[100];  // ���洢100��ʳ���¼
int food_count = 0;  // ��ǰ�洢��ʳ������

// ��¼ʳ����Ϣ�ĺ���
void add_food() {
    if (food_count >= 100) {
        printf("ʳ���¼�������޷������!\n");
        return;
    }

    // ����ʳ����Ϣ
    printf("������ʳ������: ");
    getchar();  // ��������������Ļ��з�
    fgets(foods[food_count].name, 50, stdin);
    foods[food_count].name[strcspn(foods[food_count].name, "\n")] = '\0';  // ȥ������ĩβ�Ļ��з�

    printf("������ʳ��۸�: ");
    scanf("%f", &foods[food_count].price);

    printf("������ʳ��ĺóԶȣ�1-5��: ");
    scanf("%d", &foods[food_count].deliciousness);

    printf("������ʳ��Ľ����ȣ�1-5��: ");
    scanf("%d", &foods[food_count].healthiness);

    printf("������ʳ������ͣ��磺��ʳ����ʳ�ȣ�: ");
    getchar();  // ���������
    fgets(foods[food_count].category, 50, stdin);
    foods[food_count].category[strcspn(foods[food_count].category, "\n")] = '\0';  // ȥ������ĩβ�Ļ��з�

    food_count++;  // ����ʳ���¼��
    printf("ʳ���¼�ѱ��棡\n");
}

// �鿴ʳ���¼�ĺ���
void view_food() {
    int choice;
    printf("ѡ��ɸѡ������\n");
    printf("1. �鿴�óԶȴ���3��ʳ��\n");
    printf("2. �鿴�����ȴ���3��ʳ��\n");
    printf("3. �鿴�óԶȺͽ����ȶ�����3��ʳ��\n");
    printf("������ѡ��1/2/3��: ");
    scanf("%d", &choice);

    int found = 0;  // ����Ƿ��ҵ�����������ʳ��

    // �����û�ѡ��ɸѡʳ��
    if (choice == 1) {
        for (int i = 0; i < food_count; i++) {
            if (foods[i].deliciousness > 3) {
                printf("ʳ������: %s, �۸�: %.2f, �óԶ�: %d, ������: %d, ����: %s\n",
                    foods[i].name, foods[i].price, foods[i].deliciousness, foods[i].healthiness, foods[i].category);
                found = 1;
            }
        }
    } else if (choice == 2) {
        for (int i = 0; i < food_count; i++) {
            if (foods[i].healthiness > 3) {
                printf("ʳ������: %s, �۸�: %.2f, �óԶ�: %d, ������: %d, ����: %s\n",
                    foods[i].name, foods[i].price, foods[i].deliciousness, foods[i].healthiness, foods[i].category);
                found = 1;
            }
        }
    } else if (choice == 3) {
        for (int i = 0; i < food_count; i++) {
            if (foods[i].deliciousness > 3 && foods[i].healthiness > 3) {
                printf("ʳ������: %s, �۸�: %.2f, �óԶ�: %d, ������: %d, ����: %s\n",
                    foods[i].name, foods[i].price, foods[i].deliciousness, foods[i].healthiness, foods[i].category);
                found = 1;
            }
        }
    } else {
        printf("��Чѡ��!\n");
        return;
    }

    if (!found) {
        printf("û�з���������ʳ���¼��\n");
    }
}

// ������
int main() {
    int choice;
    while (1) {
        printf("\n��ӭ������ʳ��¼���\n");
        printf("1. ��¼ʳ��\n");
        printf("2. �鿴ʳ���¼\n");
        printf("3. �˳�\n");
        printf("������ѡ��1/2/3��: ");
        scanf("%d", &choice);

        if (choice == 1) {
            add_food();
        } else if (choice == 2) {
            view_food();
        } else if (choice == 3) {
            printf("ллʹ�ã����������\n");
            break;
        } else {
            printf("��Чѡ������������!\n");
        }
    }

    return 0;
}

