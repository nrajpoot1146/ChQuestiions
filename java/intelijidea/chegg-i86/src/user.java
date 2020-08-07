public class user {
    private Name name;
    private Integer age;
    public user(){}

    /**
     * get name of user
     * @return name of user
     */
    public Name getname(){
        return name;
    }

    /**
     * set name of user
     * @param name of user
     */
    public void setname(Name name){
        this.name=name;
    }

    /**
     * get age of user
     * @return age of user
     */
    public Integer getAge(){
        return age;
    }

    /**
     * set age of user
     * @param age of user
     */
    public void setAge(Integer age){
        this.age=age;
    }

    /**
     * check whether two user equal or not
     * @param u another user object
     * @return true if both user are equal otherwise return false
     */
    public boolean equals(user u){
        if (this.name.equals(u.name) && this.age.equals(u.age)){
            return true;
        }
        return false;
    }

    /**
     * string
     * @return
     */
    @Override
    public String toString() {
        return "Name: "+name.toString()+", Age: "+this.age;
    }
}