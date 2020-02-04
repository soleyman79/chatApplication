#include <string.h>
#include <stdio.h>

typedef char cJSON;

//Prototypes
int cJSON_GetArraySize(cJSON*);
void cJSON_AddItemToArray(cJSON*, cJSON*);
cJSON* cJSON_CreateArray(void);
char* cJSON_Print(cJSON*);
cJSON* cJSON_Parse(char*);
cJSON* cJSON_CreateObject(void);
void cJSON_AddItemToObject(cJSON*,char* ,cJSON*);
cJSON* cJSON_GetObjectItem(cJSON*, char*);



cJSON* cJSON_CreateArray(void){
    static char out[] = "[]";
    return out;
}

int cJSON_GetArraySize(cJSON* input){
    int size = 0;
    if(strlen(input) == 2){
        return size;
    }
    char* token;
    token = strtok(input, ",");
    while(token != NULL){
        size++;
        token = strtok(NULL, ",");
    }
    return size;
}

void cJSON_AddItemToArray(cJSON* array, cJSON* item){
    char* token;
    char str[100];
    if (cJSON_GetArraySize(array)){
        token = strtok(array, "]");
        sprintf(str, ",\"%s\"]", item);
    }
    else{
        token = strtok(array, "]");
        sprintf(str, "\"%s\"]", item);
    }
    strcat(token, str);
    strcpy(array, token);
}

char* cJSON_Print(cJSON* input){
    return input;
}

cJSON* cJSON_Parse(char* input){
    return input;
}

cJSON* cJSON_CreateObject(void){
    static char out[] = "{}";
    return out;
}

void cJSON_AddItemToObject(cJSON* object, char* string, cJSON* item){
    char* token;
    char str[100];
    if (cJSON_GetArraySize(object)){
        token = strtok(object, "}");
        sprintf(str, ",\"%s\":\"%s\"}", string, item);
    }
    else{
        token = strtok(object, "}");
        sprintf(str, "\"%s\":\"%s\"}", string, item);
    }
    strcat(token, str);
    strcpy(object, token);
}

cJSON* cJSON_GetObjectItem(cJSON* object, char* string){
    char str[100];
    sprintf(str, "\"%s\":", string);
    char* token = strtok(object, str);
    token = strtok(NULL, ",");
    memset(str, 0, sizeof(str));
    char trash[100];
    sscanf(token, "%[^:]:\"%[^\"]\"", trash, str);
    puts(str);

}

int main () {
    cJSON* c = cJSON_CreateObject();
    cJSON_AddItemToObject(c, "salam", "rrrrr");
    cJSON_AddItemToObject(c, "bye", "rrrrr");
    puts(c);
    cJSON_GetObjectItem(c, "salam");

    /*cJSON* a = cJSON_CreateArray();
    cJSON_AddItemToArray(a,"sendedfd");
    puts(a);
    //char str[] = "[{\"sender\":\"server\"},{\"sender\":\"server\"}]";
    char str[] = "[\"a\",\"b\",\"c\"]";
    cJSON_AddItemToArray(str, "\"d\"");
    //printf("%d", cJSON_GetArraySize(str));*/
    return(0);
}
