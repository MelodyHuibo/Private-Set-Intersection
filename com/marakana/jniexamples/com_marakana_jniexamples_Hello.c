#include <stdio.h>
#include <string.h>
#include "com_marakana_jniexamples_Hello.h"

JNIEXPORT jstring JNICALL Java_com_marakana_jniexamples_Hello_sayHi(JNIEnv *env, jobject obj, jstring who, jstring times) {
  jint i, j, k = 0;
  jboolean iscopy;
  const char *name;
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
  return (*env)->NewStringUTF(env, name3);
}
