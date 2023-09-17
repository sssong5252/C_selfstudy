#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { //토근 유형
    TOKEN_INT, //정수형
    TOKEN_TXT, //문자열
    TOKEN_FLT, //실수형
    TOKEN_END, //입력끝
} type_of_class;

typedef struct { //토큰 정보 담는 구조체
    type_of_class type; //토큰 유형
    int intValue;
    char* strValue;
    float fltValue;
} token_structure;

token_structure next_token(const char** input) {
    
  while (**input == ' ') (*input)++; //공백 건너뛰기

  if (**input == '\n' || **input == ';' || **input == '\0') { 
      if(**input != '\0') (*input)++;
      return (token_structure){TOKEN_END};
  }
    if (strncmp(*input, "int", 3) == 0) { //앞의 세글자 int인지 아닌지 비교 아래도 동일
      *input += 4;
      int value = atoi(*input);
      while ((**input >= '0' && **input <= '9')) (*input)++;
      return (token_structure){TOKEN_INT, .intValue=value};
  }

  if (strncmp(*input, "txt", 3) == 0) {
      *input +=4;
      char* start = * input;
      
     while(** input != ' ' && ** input != ';' && ** input != '\n') (* input)++;
      
     char* str=malloc((* input - start +1)* sizeof(char));
     strncpy(str,start,* input-start);
     
     return(token_structure){TOKEN_TXT,.strValue=str};
   }
   
   if(strncmp(* input,"flt",3)==0){
       * input +=4;
       float value=atof(* input);
       
       while((** input>='0'&& ** input<='9')|| ** input=='.') (* input)++;
       
       return(token_structure){TOKEN_FLT,.fltValue=value};
   }
   
   printf("Unexpected token error\n"); //에러 종료
   exit(1);
}