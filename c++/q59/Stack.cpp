/** stack (base class)
* The basic definition of the Stack Abstract Data Type (ADT)
* and stack operations. All declared functions here are
* virtual, they must be implemented by concrete derived
* classes.
*/
template <class T>
class Stack
{
public:
  /** clear
   * Method to clear out or empty any items on stack,
   * put stack back to empty state.
   * Postcondition: Stack is empty.
   */
  virtual void clear() = 0;

  /** isEmpty
   * Function to determine whether the stack is empty. Needed
   * because it is undefined to pop from empty stack. This
   * function will not change the state of the stack (const).
   *
   * @returns bool true if stack is empty, false otherwise.
   */
  virtual bool isEmpty() const = 0;

  /** push
   * Add a new item onto top of stack. 
   *
   * @param newItem The item of template type T to push on top of
   * the current stack.
   */
  virtual void push(const T& newItem) = 0;

  /** top
   * Return the top item from the stack. Note in this ADT, peeking
   * at the top item does not remove the top item. Some ADT combine
   * top() and pop() as one operation. It is undefined to try and
   * peek at the top item of an empty stack. Derived classes should
   * throw an exception if this is attempted.
   *
   * @returns T Returns the top item from stack.
   */
  virtual T top() const = 0;

  /** pop
   * Remove the item from the top of the stack. It is undefined what
   * it means to try and pop from an empty stack. Derived classes should
   * throw an exception if pop() from empty is attempted.
   */
  virtual void pop() = 0;

  /** size
   * Accessor method to provide the current size of the stack.
   *
   * @returns int The current size (number of items) on the stack.
   */
  virtual int size() const = 0;

};
