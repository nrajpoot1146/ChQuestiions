#!/usr/bin/env python
# coding: utf-8

# In[20]:


def is_maxheap(l:list, start = 0):
    if (len(l) == 0 or len(l) == 1):
        return True
    
    lChild = 2 * start + 1
    RChild = 2 * start + 2
    flag = True
    
    if (lChild < len(l)):
        if l[lChild] > l[start]:
            return False
        flag = flag and is_maxheap(l, lChild)
        
    if (RChild < len(l)):
        if l[RChild] > l[start]:
            return False
        flag = flag and is_maxheap(l, RChild)
    
    return flag

print(is_maxheap([]))
print(is_maxheap([10]))
print(is_maxheap([10, 7, 8]))
print(is_maxheap([1, 2]))
print(is_maxheap([5,6,3]))


# In[19]:





# In[ ]:




