#include <iostream>
#include<cstring>

void parse_args(char **args, char *flag, char *file_path);
void get_file_content(char *file_path, char *file_content);
void word_count(char *flag, char *file_content);

int main(int argc,char **argv) {
    // 处理参数传递错误
    if (argc != 3) {
        printf("wrong args\n");
        return 0;
    }

    // 参数处理
    char flag[5];
    char file_path[100];
    parse_args(argv, flag, file_path);

    // 获取文件内容
    char file_content[10000];
    get_file_content(file_path, file_content);

    // 执行统计任务
    word_count(flag, file_content);

    return 0;
}

// parse_args 从参数中获取控制参数和文件路径
void parse_args(char **args, char *flag, char *file_path) {
    strcpy(flag, args[1]);
    strcpy(file_path, args[2]);
}

// get_file_content 获取文件内容
void get_file_content(char *file_path, char *file_content) {
    FILE* file_data = fopen(file_path, "r");
    fgets(file_content, 10000, file_data);
}

// word_count 按控制参数执行对应任务
void word_count(char *flag, char *file_content) {
    size_t cnt = 0;

    if (strcmp(flag, "-c") == 0) {
        // 统计字符数
        cnt = strlen(file_content);
        printf("字符数: %lld", cnt);
    } else if (strcmp(flag, "-w") == 0) {
        bool in_word = false;
        // 统计单词数
        for (int i = 0; file_content[i] != '\0'; i++) {
            if (!in_word && (file_content[i] == ' ' || file_content[i] == ',')) {
                continue;
            } else if (!in_word) {
                cnt += 1;
                in_word = true;
            } else if (file_content[i] == ' ' || file_content[i] == ',') {
                in_word = false;
            }
        }
        printf("单词数: %lld", cnt);
    } else {
        printf("wrong args\n");
    }
}