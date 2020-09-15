#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include "com_marakana_jniexamples_Hello.h"

//JNIEXPORT jstring JNICALL Java_com_marakana_jniexamples_Hello_sayHi(JNIEnv *env, jobject obj, jstring who, jstring times) {
JNIEXPORT jobjectArray JNICALL Java_com_marakana_jniexamples_Hello_sayHi(JNIEnv *env, jobject obj, jobjectArray who, jobjectArray times) {
  jint i, j, k = 0;
  jobjectArray ret;
  jboolean iscopy;

  size_t stringCount1 = (size_t)(*env)->GetArrayLength(env, who);
  size_t stringCount2 = (size_t)(*env)->GetArrayLength(env, times);
  char **Strings1=calloc(stringCount1, sizeof(char*));
  char **Strings2=calloc(stringCount2, sizeof(char*));
  char **Strings3=calloc(stringCount1 < stringCount2 ? stringCount1:stringCount2, sizeof(char*));

  
//  ret = (jobjectArray) (*env)->NewObjectArray(env, stringCount1 < stringCount2 ? stringCount1:stringCount2, 
//(*env)->FindClass(env, "java/lang/String"), NULL);


/*  const char *name;
  const char *name2;
  name = (*env)->GetStringUTFChars(env, who, &iscopy);
  name2 = (*env)->GetStringUTFChars(env, times, &iscopy);
  int len1 = strlen(name);
  int len2 = strlen(name2);
  for (i = 0; i < len1; i++) {
    printf("Hello %s\n", name);
  }

  for (i = 0; i < len2; i++) {
    printf("Hello %s\n", name2);
  }
 
  char name3[len1 < len2 ? len1:len2]; 
  for (i = 0; i < len1; i++) {
        for (j = 0; j < len2; j++) {
            if (name[i] == name2[j]) {
                name3[k] = name[i];
                k++;
            }
        }
    }

  name3[k] = '\0';
  return (*env)->NewStringUTF(env, name3);*/

/*
  for(i = 0; i < stringCount1; i++ )
  {
        jstring jniString1 = (jstring) (*env)->GetObjectArrayElement(env, who, i);
        const char *TempString1 = (*env)->GetStringUTFChars(env, jniString1, &iscopy);
        Strings1[i] = calloc(strlen(TempString1)+1, sizeof(char));
        strcpy(Strings1[i], TempString1);
        printf("String1 %s\n", Strings1[i]);
  }
  

  for(i = 0; i < stringCount2; i++ )
  {
        jstring jniString2 = (jstring) (*env)->GetObjectArrayElement(env, times, i);
        const char *TempString2 = (*env)->GetStringUTFChars(env, jniString2, &iscopy);
        Strings2[i] = calloc(strlen(TempString2)+1, sizeof(char));
        strcpy(Strings2[i], TempString2);
        printf("String2 %s\n", Strings2[i]);
  }

  for (i = 0; i < stringCount1; i++) {
        for (j = 0; j < stringCount2; j++) {
            if (!strcmp(Strings1[i], Strings2[j])) {
                Strings3[k] = Strings1[i];
                printf("String3 %s\n", Strings3[k]);
//                (*env)->SetObjectArrayElement(env, ret, k, (*env)->NewStringUTF(env, Strings3[k]));
                k++;
            }
        }
    }
*/

for (i = 0; i < stringCount1; i++) {
        jstring jniString1 = (jstring) (*env)->GetObjectArrayElement(env, who, i);
        const char *TempString1 = (*env)->GetStringUTFChars(env, jniString1, &iscopy);
        for (j = 0; j < stringCount2; j++) {
            jstring jniString2 = (jstring) (*env)->GetObjectArrayElement(env, times, j);
            const char *TempString2 = (*env)->GetStringUTFChars(env, jniString2, &iscopy);
            if (!strcmp(TempString1, TempString2)) {
                Strings3[k] = TempString1;
                printf("String3 %s\n", Strings3[k]);
                k++;
            }
        }
    }

  ret = (jobjectArray) (*env)->NewObjectArray(env, k,
        (*env)->FindClass(env, "java/lang/String"), NULL);

  for (i =0; i < k; i++)
  {
       (*env)->SetObjectArrayElement(env, ret, i, (*env)->NewStringUTF(env, Strings3[i]));
  }

  return ret; 
  
}
