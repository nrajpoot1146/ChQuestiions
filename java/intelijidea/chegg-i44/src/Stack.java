public interface Stack {
    public void push(Element e);
    public Element pop();
    public boolean stackEmpty();
    public boolean stackFull();
    public int getTopValue();
}