#include <stdio.h>
#include <string.h>

// 定义食物结构体
typedef struct {
    char name[50];       // 食物名称
    float price;         // 食物价格
    int deliciousness;   // 食物好吃度（1-5）
    int healthiness;     // 食物健康度（1-5）
    char category[50];   // 食物类型（如主食、零食等）
} Food;

// 定义一个数组来存储食物信息
Food foods[100];  // 最多存储100个食物记录
int food_count = 0;  // 当前存储的食物数量

// 记录食物信息的函数
void add_food() {
    if (food_count >= 100) {
        printf("食物记录已满，无法再添加!\n");
        return;
    }

    // 输入食物信息
    printf("请输入食物名称: ");
    getchar();  // 清除缓冲区残留的换行符
    fgets(foods[food_count].name, 50, stdin);
    foods[food_count].name[strcspn(foods[food_count].name, "\n")] = '\0';  // 去掉输入末尾的换行符

    printf("请输入食物价格: ");
    scanf("%f", &foods[food_count].price);

    printf("请输入食物的好吃度（1-5）: ");
    scanf("%d", &foods[food_count].deliciousness);

    printf("请输入食物的健康度（1-5）: ");
    scanf("%d", &foods[food_count].healthiness);

    printf("请输入食物的类型（如：主食、零食等）: ");
    getchar();  // 清除缓冲区
    fgets(foods[food_count].category, 50, stdin);
    foods[food_count].category[strcspn(foods[food_count].category, "\n")] = '\0';  // 去掉输入末尾的换行符

    food_count++;  // 增加食物记录数
    printf("食物记录已保存！\n");
}

// 查看食物记录的函数
void view_food() {
    int choice;
    printf("选择筛选条件：\n");
    printf("1. 查看好吃度大于3的食物\n");
    printf("2. 查看健康度大于3的食物\n");
    printf("3. 查看好吃度和健康度都大于3的食物\n");
    printf("请输入选择（1/2/3）: ");
    scanf("%d", &choice);

    int found = 0;  // 标记是否找到符合条件的食物

    // 根据用户选择筛选食物
    if (choice == 1) {
        for (int i = 0; i < food_count; i++) {
            if (foods[i].deliciousness > 3) {
                printf("食物名称: %s, 价格: %.2f, 好吃度: %d, 健康度: %d, 类型: %s\n",
                    foods[i].name, foods[i].price, foods[i].deliciousness, foods[i].healthiness, foods[i].category);
                found = 1;
            }
        }
    } else if (choice == 2) {
        for (int i = 0; i < food_count; i++) {
            if (foods[i].healthiness > 3) {
                printf("食物名称: %s, 价格: %.2f, 好吃度: %d, 健康度: %d, 类型: %s\n",
                    foods[i].name, foods[i].price, foods[i].deliciousness, foods[i].healthiness, foods[i].category);
                found = 1;
            }
        }
    } else if (choice == 3) {
        for (int i = 0; i < food_count; i++) {
            if (foods[i].deliciousness > 3 && foods[i].healthiness > 3) {
                printf("食物名称: %s, 价格: %.2f, 好吃度: %d, 健康度: %d, 类型: %s\n",
                    foods[i].name, foods[i].price, foods[i].deliciousness, foods[i].healthiness, foods[i].category);
                found = 1;
            }
        }
    } else {
        printf("无效选择!\n");
        return;
    }

    if (!found) {
        printf("没有符合条件的食物记录。\n");
    }
}

// 主程序
int main() {
    int choice;
    while (1) {
        printf("\n欢迎来到美食记录软件\n");
        printf("1. 记录食物\n");
        printf("2. 查看食物记录\n");
        printf("3. 退出\n");
        printf("请输入选择（1/2/3）: ");
        scanf("%d", &choice);

        if (choice == 1) {
            add_food();
        } else if (choice == 2) {
            view_food();
        } else if (choice == 3) {
            printf("谢谢使用，程序结束！\n");
            break;
        } else {
            printf("无效选择，请重新输入!\n");
        }
    }

    return 0;
}

