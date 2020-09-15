package com.marakana.jniexamples;

public class Hello {
  public native String[] sayHi(String[] who, String[] times); //1
//  public native String sayHi(String who, String times); //1
//  public native void sayHi(String who, int times); //1

  static { System.loadLibrary("HelloImpl"); } //2

  public static void main (String[] args) {
    Hello hello = new Hello();
//    String s = hello.sayHi(args[0], Integer.parseInt(args[1])); //3
    String[] A = {"Student", "woman", "man"};
    String[] B = {"Student", "women", "men", "youyou"};

    String[] arrays = hello.sayHi(A, B); //3
//    String[] arrays = hello.sayHi(args[0], args[1]); //3
    System.out.println("Intersection string is: ");
    for(int i = 0; i < arrays.length; i++) {
            System.out.println("arrays[" + i + "] = " + arrays[i]);
        }
//    System.out.println(s); //3
  }
}
