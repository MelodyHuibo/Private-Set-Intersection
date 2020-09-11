Generate header file com_marakana_jniexamples_Hello.h

-- javac -h . Hello.java

After running javah, create your .c file com_marakana_jniexamples_Hello.c


Compile com_marakana_jniexamples_Hello.c in the "classes" directory (if your .h file and .c file are there) on Linux do:

-- gcc -o libHelloImpl.so -lc -shared -I${JAVA_HOME}/include -I${JAVA_HOME}/include/linux com_marakana_jniexamples_Hello.c

set the LD_LIBRARY_PATH to the current working directory:

--export LD_LIBRARY_PATH=.

Finally, run your application in the directory where your compiled classes are stored ("classes" for example):

-- java -cp ../../.. -Djava.library.path=/home/security/com/marakana/jniexamples com.marakana.jniexamples.Hello Student 5

Expected:
Hello Student
Hello Student
Hello Student
Hello Student
Hello Student
Enter a password:
Student
