public interface Queue {
    public void enQueue(Element e);
    public Element deQueue();
    public boolean queueEmpty();
    public boolean queueFull();
    public int getHeadValue();
    public int getTailValue();
}