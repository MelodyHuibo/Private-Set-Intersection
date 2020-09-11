package com.marakana.jniexamples;

public class Hello {
  public native String sayHi(String who, int times); //1
//  public native void sayHi(String who, int times); //1

  static { System.loadLibrary("HelloImpl"); } //2

  public static void main (String[] args) {
    Hello hello = new Hello();
    String s = hello.sayHi(args[0], Integer.parseInt(args[1])); //3
    System.out.println("Enter a password: ");
    System.out.println(s); //3
  }
}
