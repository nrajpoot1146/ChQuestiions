#ifndef SIMPLEOBJECT_H
#define SIMPLEOBJECT_H

class Simple
{
private:
    int data;

public:
    Simple(int d) { data = d; };
    int getData() { return data; };
};

#endif /* SIMPLEOBJECT_H */
