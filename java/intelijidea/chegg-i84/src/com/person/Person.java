package com.person;

/**
 * class person
 */
public class Person {
    private String name;
    private int age;
    private char gender;

    /**
     * parameterize constructor
     * @param name of person
     * @param age of person
     * @param gender of person
     */
    public Person(String name, int age, char gender){
        this.name = name;
        this.age = age;
        this.gender = gender;
    }

    /**
     * gets name of person
     * @return
     */
    public String getName() {
        return name;
    }

    /**
     * get age of person
     * @return
     */
    public int getAge() {
        return age;
    }

    /**
     * get genderr of person
     * @return
     */
    public char getGender() {
        return gender;
    }

    /**
     * set name of person
     * @param name
     */
    public void setName(String name) {
        this.name = name;
    }

    /**
     * set gender of person
     * @param gender
     */
    public void setGender(char gender) {
        this.gender = gender;
    }

    /**
     * set age of person
     * @param age
     */
    public void setAge(int age) {
        this.age = age;
    }

    @Override
    public String toString() {
        return "Person{" +
                "name='" + name + '\'' +
                ", age=" + age +
                ", gender=" + gender +
                '}';
    }
}
